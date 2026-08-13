Nome:Beatriz Costa
Nome:Beatriz Amorim
Nome:Glória    
Nome:Heloisa    
Nome:Agatha 

# Relatório de Formatação do Raspberry Pi 106

Para preparar o Raspberry Pi 106, utilizamos o Raspberry Pi Imager para instalar o sistema operacional no cartão SD. 
Primeiro, selecionamos o modelo Raspberry Pi 3B+, que é o modelo utilizado na infraestrutura do laboratório. 
Depois, escolhemos o Raspberry Pi OS Lite (64-bit) – Legacy, por ser uma versão mais adequada ao equipamento e não possuir interface gráfica, que não é necessária para o uso que será feito.
Em seguida, selecionamos o cartão SD disponível no computador e abrimos as opções avançadas do programa. Nessa parte, configuramos o nome do dispositivo como rpi-106 e ativamos o acesso por SSH, que permite acessar o Raspberry Pi remotamente pelo computador. 
Também configuramos o usuário pi, a conexão com a rede Wi-Fi do laboratório, utilizando a rede i4, além do fuso horário de São Paulo e do teclado no padrão brasileiro.
Depois de conferir todas as configurações, iniciamos a gravação do sistema no cartão SD e aguardamos a conclusão da verificação. 
Com o cartão pronto, ele foi colocado no Raspberry Pi 106 e o equipamento foi ligado.
Por fim, realizamos um teste de conexão pelo computador usando o comando ping rpi-106. 
A ideia desse teste foi verificar se o Raspberry Pi estava conectado corretamente à rede. Também seria possível testar o acesso remoto por meio do comando ssh pi@rpi-106.
Dessa forma, o Raspberry Pi 106 ficou preparado com o sistema operacional e as configurações necessárias para ser utilizado nas atividades da infraestrutura do laboratório.

