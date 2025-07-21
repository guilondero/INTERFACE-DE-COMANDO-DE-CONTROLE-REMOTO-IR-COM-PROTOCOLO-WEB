# 📡 Interface de Controle Remoto IR com Protocolo Web

Este projeto implementa um controle remoto infravermelhos para aparelhos TX9 BOX através de uma interface web, utilizando um ESP32 como controlador principal e servidor web integrado.

## 🎯 Objetivo

Desenvolver um sistema de controle remoto IR operado via interface web, permitindo o controle de aparelhos de TV/Set-top Box através de qualquer dispositivo conectado à rede local.

## 🛠️ Componentes Utilizados

### **ESP32-WROOM-32**
Microcontrolador principal responsável por:
- Processamento dos comandos da interface web
- Hosting do servidor web local
- Controle do emissor IR
- Gerenciamento da conectividade Wi-Fi

<div align="center">
  <img src="https://user-images.githubusercontent.com/97804927/155638937-3ee98226-2448-4b58-a813-cac66ce5b8a9.JPG" width="300px" alt="ESP32-WROOM-32" />
</div>

### **Jumpers**
Cabos de conexão para interligação dos componentes na protoboard.

<div align="center">
  <img src="https://user-images.githubusercontent.com/97804927/155639170-f9619ceb-6844-4d39-a5b3-b87945eca20e.JPG" width="200px" alt="Jumpers" />
</div>

### **Emissor IR (LED Infravermelho)**
Diodo emissor de luz infravermelha responsável por transmitir os comandos codificados para o aparelho receptor.

<div align="center">
  <img src="https://user-images.githubusercontent.com/97804927/155640303-55170c97-e970-4734-9678-c0acc34fa547.JPG" width="200px" alt="Emissor IR" />
</div>

### **Receptor IR**
Sensor utilizado para capturar os sinais IR do controle remoto original, permitindo a decodificação dos comandos. Possui três pinos: VCC, GND e Signal Out.

<div align="center">
  <img src="https://user-images.githubusercontent.com/97804927/155640805-0ac48278-f726-48a8-9d2d-dc3c59483800.JPG" width="300px" alt="Receptor IR" />
</div>

### **Protoboard 830 pontos**
Base para montagem e conexão dos circuitos. O projeto pode ser adaptado para protoboard de 400 pontos.

<div align="center">
  <img src="https://user-images.githubusercontent.com/97804927/155641200-5cc40758-19e5-47da-a440-3130e003b78f.JPG" width="300px" alt="Protoboard" />
</div>

### **Resistores**
- **Circuito emissor**: 2x 100Ω (paralelo) + 2x 560Ω (paralelo)
- **Circuito receptor**: 1x 1kΩ + 1x 10kΩ

<div align="center">
  <img src="https://user-images.githubusercontent.com/97804927/155641458-779cc69b-4eac-40e9-9178-1c6d8788b14f.JPG" width="300px" alt="Resistores" />
</div>

### **Transistor 2N2222A**
Componente semicondutor utilizado para amplificação dos sinais eletrônicos, garantindo potência adequada para o emissor IR.

<div align="center">
  <img src="https://user-images.githubusercontent.com/97804927/155641716-053e0fd0-ce3f-4cb4-8a86-7a21a41dbc3b.JPG" width="300px" alt="Transistor 2N2222A" />
</div>
 
## 🔧 Arquitetura do Sistema

### **Circuito Decodificador**
Responsável pela captura e decodificação dos sinais IR do controle remoto original.

<div align="center">
  <img src="https://user-images.githubusercontent.com/97804927/155764724-8301459a-3337-4b3a-bd64-342785b44517.JPG" width="500px" alt="Esquema do Circuito Decodificador" />
</div>

<div align="center">
  <img src="https://user-images.githubusercontent.com/97804927/155764869-4ab9e5bf-d3d1-435e-b084-31a0ea364521.JPG" width="400px" alt="Montagem do Circuito Decodificador" />
</div>

### **Circuito Emissor**
Configurado especificamente para o ESP32, utilizando o pino GPIO4 dedicado para transmissão IR. Este pino é otimizado para operações de timing crítico necessárias na transmissão infravermelha.

> **Nota Técnica**: Diferentemente do Arduino Uno (pino 3), o ESP32 utiliza o GPIO4 como pino padrão para emissão IR. Esta configuração é determinada pelo hardware e não pode ser alterada via software.

<div align="center">
  <img src="https://user-images.githubusercontent.com/97804927/155765583-ed247947-74a3-47ae-b580-1bc493544a31.JPG" width="400px" alt="Esquema do Circuito Emissor" />
</div>

<div align="center">
  <img src="https://user-images.githubusercontent.com/97804927/155820630-0cfa3485-0491-4e08-b296-8408c54a9db0.JPG" width="500px" alt="Montagem do Circuito Emissor" />
</div>

## 📡 Protocolo de Comunicação

### **Protocolo NEC**
O sistema utiliza o protocolo NEC (Near Echo Cancellation) para comunicação infravermelha, caracterizado por:

- **Frequência portadora**: 38kHz
- **Modulação**: PCM (Pulse Code Modulation)
- **Codificação**: Pulsos representados em bits

### **Fluxo de Comunicação**
```
Interface Web → ESP32 → Emissor IR → Dispositivo TX9 BOX
```

<div align="center">
  <img src="https://user-images.githubusercontent.com/97804927/155821220-07892bd8-9a58-4613-b2df-0af5cb3d1e39.JPG" width="500px" alt="Fluxo de Comunicação" />
</div>

<div align="center">
  <img src="https://user-images.githubusercontent.com/97804927/155821010-c972766c-0c6b-4e45-bb7e-fce320f799b8.JPG" width="200px" alt="Protocolo NEC - Timing" />
</div>

<div align="center">
  <img src="https://user-images.githubusercontent.com/97804927/155821052-0b64d1af-ad55-458f-bf8a-5ed5517568f5.JPG" width="300px" alt="Protocolo NEC - Estrutura" />
</div>

## 🌐 Interface Web

### **Tecnologias Utilizadas**
- **HTML5**: Estrutura da interface
- **CSS3**: Estilização e responsividade
- **JavaScript**: Interatividade e comunicação com o ESP32

### **Características**
- Interface responsiva e intuitiva
- Controle em tempo real
- Compatível com dispositivos móveis e desktop
- Hospedada diretamente no ESP32

<div align="center">
  <img src="https://user-images.githubusercontent.com/97804927/156939574-031a8b41-3a3a-46bc-b1a4-749946c901fa.JPG" width="300px" alt="Interface Web" />
</div>

## 📁 Estrutura do Projeto

```
INTERFACE-DE-COMANDO-DE-CONTROLE-REMOTO-IR-COM-PROTOCOLO-WEB/
├── CODIGO_DECODER.ino          # Código para decodificação de sinais IR
├── Codigo_final_projeto_semestral.ino  # Código principal do projeto
├── CODIGO_SENDER.ino           # Código para envio de sinais IR
├── estruturaTvFinal.html       # Interface HTML para TV
├── indexLedFinal.html          # Interface HTML principal
├── styleLedFinal.css           # Estilos CSS para interface LED
├── styleTvFinal.css           # Estilos CSS para interface TV
├── LICENSE                     # Licença do projeto
└── README.md                   # Documentação do projeto
```

## 🚀 Como Usar

1. **Montagem do Hardware**: Monte os circuitos conforme os esquemas apresentados
2. **Upload do Código**: Carregue o código principal no ESP32 via Arduino IDE
3. **Configuração Wi-Fi**: Configure as credenciais de rede no código
4. **Acesso à Interface**: Conecte-se ao IP do ESP32 através de qualquer navegador web
5. **Operação**: Utilize a interface web para controlar o dispositivo TX9 BOX

## 📋 Pré-requisitos

- Arduino IDE com suporte ao ESP32
- Bibliotecas necessárias:
  - `WiFi.h`
  - `WebServer.h`
  - `IRremote.h`
- Conhecimentos básicos em eletrônica e programação

## 🤝 Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para:
- Reportar bugs
- Sugerir melhorias
- Submeter pull requests

## 📄 Licença

Este projeto está licenciado sob os termos especificados no arquivo `LICENSE`.

---

**Desenvolvido com ❤️ para fins acadêmicos e educacionais**