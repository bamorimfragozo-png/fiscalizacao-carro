Grupo: Beatriz Amorim, Beatriz Chiara, Glória, Heloisa e Agatha 

# Relatório de Formatação do Raspberry Pi 106

Para preparar o nó rpi-106, utilizamos um adaptador de cartão SD em formato de pen drive conectado ao computador da bancada para instalar o sistema operacional no cartão micro SD com o software Raspberry Pi Imager. No programa, selecionamos a opção do dispositivo Raspberry Pi 3B+ e a versão do sistema Raspberry Pi OS Lite (64-bit)—Legacy, por ser a versão recomendada para o equipamento e por não possuir interface gráfica.

Em seguida, selecionamos o cartão SD conectado ao computador e abrimos as opções avançadas de personalização. Nessa etapa, configuramos o nome do dispositivo (hostname) como rpi-106 e ativamos a autenticação por SSH para acesso remoto. Foram definidos também o usuário pi com a senha 147, a conexão com a rede sem fio do laboratório na rede i4 (senha 147258369), o fuso horário de São Paulo e o teclado no padrão brasileiro. Após verificar todos os parâmetros, iniciamos a gravação do sistema no cartão e aguardamos a finalização do processo de verificação.

Com a gravação concluída, a etapa prática consistiu na montagem do hardware. O cartão micro SD foi inserido no Raspberry Pi 106. Para colocar a placa em funcionamento, desconectamos o cabo de vídeo HDMI, o teclado e a fonte de alimentação do computador da bancada e conectamos esses cabos diretamente ao minicomputador para ligá-lo e permitir a visualização da tela de inicialização. 

Por fim, após o equipamento inicializar, retornamos ao computador principal para validar as configurações de rede. Executamos o teste de conectividade no terminal por meio do comando "ping rpi-106" para confirmar se o dispositivo estava acessível na rede local, seguido do teste de acesso remoto através do comando "ssh pi@rpi-106", finalizando assim a preparação e a verificação do nó. Após a conclusão dos testes, o minicomputador foi desligado e desconectado, retornando os cabos de monitor, teclado e energia às conexões originais do computador da bancada.
