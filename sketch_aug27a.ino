#include <WiFi.h>
#include <PubSubClient.h>

// =========================================================================
// CONFIGURAÇÕES DA SUA REDE E SERVIDORES
// =========================================================================
const char* ssid = "i4";                     // Nome exato da sua rede Wi-Fi
const char* password = "147258369";          // Senha da rede Wi-Fi
const char* mqtt_server = "10.10.10.104";    // IP da Raspberry Pi (wlan0)
const int mqtt_port = 1883;                  // Porta padrão do MQTT

// =========================================================================
// VARIÁVEIS GLOBAIS E PINOS
// =========================================================================
WiFiClient espClient;
PubSubClient client(espClient);

const int pinLED = 2;                        // LED embutido do ESP32
int velocidades[] = {10, 90, 150};           // Simulação de velocidades
int indice = 0;                              // Controle do índice da lista

// =========================================================================
// FUNÇÃO DE RECONEXÃO MQTT
// =========================================================================
void reconectarMQTT() {
  while (!client.connected()) {
    Serial.print("Tentando conectar ao broker MQTT na Raspberry...");
    
    // Tenta conectar usando um ID único para a placa
    if (client.connect("ESP32_Fiscalizador")) {
      Serial.println("\n[SUCESSO] Conectado ao MQTT com sucesso!");
    } else {
      Serial.print("\n[ERRO] Falha na conexao. Codigo de erro: ");
      Serial.print(client.state());
      Serial.println(" | Tentando novamente em 3 segundos...");
      delay(3000);
    }
  }
}

// =========================================================================
// CONFIGURAÇÃO INICIAL (SETUP)
// =========================================================================
void setup() {
  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, LOW);
  
  Serial.begin(115200);
  delay(1000);

  // 1. Conexão ao Wi-Fi
  Serial.println("\n----------------------------------");
  Serial.print("Iniciando conexao com Wi-Fi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  // Imprime pontos enquanto tenta conectar no Wi-Fi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n[SUCESSO] Wi-Fi Conectado!");
  Serial.print("Endereço IP do ESP32: ");
  Serial.println(WiFi.localIP());
  Serial.println("----------------------------------");

  // 2. Configuração do Servidor MQTT
  client.setServer(mqtt_server, mqtt_port);
}

// =========================================================================
// LOOP PRINCIPAL
// =========================================================================
void loop() {
  // Garante que o Wi-Fi continua conectado
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Sinal do Wi-Fi perdido. Tentando reconectar...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
  }

  // Garante que o MQTT continua conectado
  if (!client.connected()) {
    reconectarMQTT();
  }
  client.loop();

  // Seleciona e formata o valor de velocidade atual
  int velAtual = velocidades[indice];
  char msg[10];
  snprintf(msg, 10, "%d", velAtual);

  // Envia a mensagem para o tópico configurado no Node-RED
  Serial.print("Enviando velocidade para o Node-RED: ");
  Serial.print(msg);
  Serial.println(" km/h");
  
  client.publish("fiscalizacao/carro/velocidade", msg);

  // Executa o ciclo de piscar o LED (5 segundos aceso / 5 segundos apagado)
  digitalWrite(pinLED, HIGH);
  delay(5000);

  digitalWrite(pinLED, LOW);
  delay(5000);

  // Avança para a próxima velocidade (10 -> 90 -> 150 -> 10...)
  indice = (indice + 1) % 3;
}