# INTERFACE DE COMANDO DE CONTROLE REMOTO IR COM PROTOCOLO WEB
O objetivo deste projeto é criar um controle remoto para um aparelho TX9 BOX capaz de ser operado via
interface web.

## Materiais Utilizados
 - **ESP-WROOM-32:**
  Foi utilizado o ESP-32 como o controlador do projeto, além de realizar as funções de controle do projeto, o ESP-32 também será responsável por realizar o host do servidor criado para a execução da interface web.
  <div align ="center">
  <img src="https://user-images.githubusercontent.com/97804927/155638937-3ee98226-2448-4b58-a813-cac66ce5b8a9.JPG" width="300px" />
  </div>
  
  - **Jumpers:**
  Utilizados para realizar as conexões dos circuitos montados.
  <div align ="center">
  <img src="https://user-images.githubusercontent.com/97804927/155639170-f9619ceb-6844-4d39-a5b3-b87945eca20e.JPG" width="200px" />
  </div>
  
  - **Emissor IR:**
  Emissor IR simples, composto por um catodo e anodo
  <div align ="center">
  <img src="("https://user-images.githubusercontent.com/97804927/155640303-55170c97-e970-4734-9678-c0acc34fa547.JPG" width="200px" />
  </div>
  
  - **Receptor IR:**
  O receptor IR foi utilizado para captar os sinais infravermelhos enviados a partir do controle remoto original, estes que foram utilizados pelo emissor posteriormente. Diferente do emissor, o receptor é composto por um pino VCC, um pino GND e um de Signal Out
  <div align ="center">
  <img src="("https://user-images.githubusercontent.com/97804927/155640805-0ac48278-f726-48a8-9d2d-dc3c59483800.JPG" width="200px" />
  </div>
 
 
