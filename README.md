# INTERFACE DE COMANDO DE CONTROLE REMOTO IR COM PROTOCOLO WEB
O objetivo deste projeto é criar um controle remoto para um aparelho TX9 BOX capaz de ser operado via
interface web. O projeto compriu 

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
  <img src="https://user-images.githubusercontent.com/97804927/155640303-55170c97-e970-4734-9678-c0acc34fa547.JPG" width="200px" />
  </div>
  
  - **Receptor IR:**
  O receptor IR foi utilizado para captar os sinais infravermelhos enviados a partir do controle remoto original, estes que foram utilizados pelo emissor posteriormente. Diferente do emissor, o receptor é composto por um pino VCC, um pino GND e um de Signal Out
  <div align ="center">
  <img src="https://user-images.githubusercontent.com/97804927/155640805-0ac48278-f726-48a8-9d2d-dc3c59483800.JPG" width="300px" />
  </div>
  
  - **Protoboard 830 pontos:**
  utilizada para realizar a ligação dos circuitos. O projeto também pode ser realizado em uma protoboard de 400 pontos
  <div align ="center">
  <img src="https://user-images.githubusercontent.com/97804927/155641200-5cc40758-19e5-47da-a440-3130e003b78f.JPG" width="300px" />
  </div>
 
 - **Resistores:**
 Para o circuito do emissor foram utilizados 2 resistores de 100Ohm em parelo e 2 resistores de 560Ohm em parelelo. Para o circuito do receptor foram utilizados 1 resistor de 1kOhm e 1 resistor de 10kOhm
 <div align ="center">
 <img src="https://user-images.githubusercontent.com/97804927/155641458-779cc69b-4eac-40e9-9178-1c6d8788b14f.JPG" width="300px" />
 </div>
 
 - **Transitor 2N222A:**
 Transistor é um dispositivo semicondutor usado para amplificar ou trocar sinais eletrônicos e potência elétrica, no caso do projeto foi para amplificar os sinais.
 <div align ="center">
 <img src="https://user-images.githubusercontent.com/97804927/155641716-053e0fd0-ce3f-4cb4-8a86-7a21a41dbc3b.JPG" width="300px" />
 </div>
 
 ## Circuitos implementados
 - **Decodificador**
 <div align ="center">
 <img src="https://user-images.githubusercontent.com/97804927/155764724-8301459a-3337-4b3a-bd64-342785b44517.JPG" width="500px" />
 </div>
 <div align ="center">
 <img src="https://user-images.githubusercontent.com/97804927/155764869-4ab9e5bf-d3d1-435e-b084-31a0ea364521.JPG" width="400px" />
 </div>
 
 - **Emissor:**
 Cabe salientar que cada plataforma, como Arduino, ESP32, entre outros, apresenta um de seus pinos especificamente para trabalhar com o envio de dados a partir de um emissor infravermelho. Para o Arduino Uno, por exemplo, o pino a ser utilizado seria o 03. Já para o projeto, visto que estamos utilizando um ESP32, o pino a ser utilizado é o GPI04, informação esta que foi obtida a partir da análise do datasheet e com as pesquisas realizadas. A utilização de um emissor infravermelho precisa ser feita utilizando esta pinagem, visto que não há como definir no código o pino ao qual o emissor estará sendo utilizado
 <div align ="center">
 <img src="https://user-images.githubusercontent.com/97804927/155765583-ed247947-74a3-47ae-b580-1bc493544a31.JPG" width="400px" />
 </div>
 <div align ="center">
 <img src="https://user-images.githubusercontent.com/97804927/155820630-0cfa3485-0491-4e08-b296-8408c54a9db0.JPG" width="500px" />
 </div>

## Comunicação e protocolo
Um dos protocolos utilizado para comandos IR é o protocolo NEC, que utiliza a modulação PCM com faixas de frequência portadora de 38kHz para transmitir pulsos que são representados em bits, com suas informações. O caminho da comunicação é: **Executar um comando na interface WEB > ESP32 executar o mesmo comando no emissor IR > Emissor IR enviar o comando para a TV.** 
<div align ="center">
<img src="https://user-images.githubusercontent.com/97804927/155821220-07892bd8-9a58-4613-b2df-0af5cb3d1e39.JPG" width="500px" />
</div>
<hr style ="color:black">
<div align ="center">
<img src="https://user-images.githubusercontent.com/97804927/155821010-c972766c-0c6b-4e45-bb7e-fce320f799b8.JPG" width="200px" />
</div>
<hr style ="color:black">
<div align ="center">
<img src="https://user-images.githubusercontent.com/97804927/155821052-0b64d1af-ad55-458f-bf8a-5ed5517568f5.JPG" width="300px" />
</div>

## Aplicação WEB
Para a aplicação web, foram utilizado as linguaguens de programação HTLML e o CSS para estilos, esses codigos foram inseridos dentro mesmo do ESP, atraves da IDE do Arduino.
Os codigos separadamente também se encontram disponivel no repositorio
<div align ="center">
<img src="https://user-images.githubusercontent.com/97804927/156939574-031a8b41-3a3a-46bc-b1a4-749946c901fa.JPG" width="300px" />
</div>







 
 
 
 
 
