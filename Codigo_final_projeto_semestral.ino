/***
PROJETO SEMESTRAL DE INTEGRAÇÃO DE REDES INDUSTRIAIS

Título do projeto: INTERFACE DE CONTROLE REMOTO IR COM PROTOCOLO WEB

Código: Código de implementação final

Integrantes:Diogo Conterato Possebon, Eduardo Mello Martins, Guilherme Ramos Londero e Matheus Gaviraghi

***/

#include <Arduino.h>
#include <WiFi.h>
#include <Wire.h>
#include <IRremote.h>

const char* ssid = "RAMOS OI FIBRA";  // Mudar aqui com as credenciais
const char* password = "metralhada"; // Mudar aqui com as credenciais
IRsend irsend;

// Define a porta do servidor web como sendo a 80
WiFiServer server(80);

// Variável para armazenar a HTTP request
String header;

// Variáveis para armazenar a última função realizada
String funcTV = "Ligada";
String funcTV2 = "";

unsigned long currentTime = millis();
unsigned long previousTime = 0; 
const long timeoutTime = 10000;
int show = -1;

// Comandos utilizados para cada uma das teclas
unsigned long infraRedCode[] = {
  0x1FE8A75, //POWER 
  0x1FE649B, //CANAL -
  0x1FE14EB, //CANAL +
  0x1FE728D, //VOLUME +
  0x1FE6A95, //VOLUME -
};

void setup() {

  int error;

  Serial.begin(9600);
  
  // Conecta na rede Wi-Fi usando as credenciais
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Printa o endereço IP local e inicia o servidor web
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Fica aguardando novos clientes

  if (client) {                             // Se um novo cliente se conectar,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // Printa a mensagem na serial avisando que um novo cliente se conectou
    String currentLine = "";                // Variável para armazenar dados vindos do cliente
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // realiza o loop while enquanto o cliente estiver conectado
      currentTime = millis();
      if (client.available()) {             // Se tiver bytes a serem lidos do cliente
        char c = client.read();             // lê o byte, então
        Serial.write(c);                    // printa na serial
        header += c;
        if (c == '\n') {                    // se o byte for um caractere de nova linha
            if (currentLine.length() == 0) {
            // Cabeçalhos HTTP sempre começam com o código de resposta (ex: HTTP/1.1 200 OK)
            // e o tipo de conteúdo e depois uma linha em branco:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            if (header.indexOf("GET /power/on") >= 0) {
              Serial.println("Ligou a TV");
              funcTV = "Ligada";
              irsend.sendNEC(infraRedCode[0], 32); // COMANDO PARA LIGAR A TV
              Serial.println("CÓDIGO PARA LIGAR: 0x1FE8A75");
              
            } else if (header.indexOf("GET /power/off") >= 0) {
              Serial.println("Desligou a TV");
              funcTV = "Desligada";
              irsend.sendNEC(infraRedCode[0], 32); // COMANDO PARA DESLIGAR A TV
              Serial.println("CÓDIGO PARA DESLIGAR: 0x1FE8A75"); 
              
            } else if (header.indexOf("GET /volume/mais") >= 0) {
              Serial.println("Aumentou o volume da TV");
              funcTV2 = "VolumeMais";
              irsend.sendNEC(infraRedCode[3], 32); // COMANDO PARA AUMENTAR O VOLUME DA TV
              Serial.println("CÓDIGO PARA AUMENTAR VOLUME: 0x1FE728D");

            } else if (header.indexOf("GET /volume/menos") >= 0) {
              Serial.println("Diminuiu o volume da TV");
              funcTV2 = "VolumeMenos";
              irsend.sendNEC(infraRedCode[4], 32); // COMANDO PARA DIMINUIR O VOLUME DA TV     
              Serial.println("CÓDIGO PARA DIMINUIR VOLUME: 0x1FE6A95");
            
            } else if (header.indexOf("GET /channel/mais") >= 0) {
              Serial.println("Trocou o canal da TV (+)");
              funcTV2 = "CanalMais";
              irsend.sendNEC(infraRedCode[2], 32); // COMANDO PARA TROCAR (+) O CANAL DA TV  
              Serial.println("CÓDIGO PARA TROCAR O CANAL (+): 0x1FE14EB");
            
            } else if (header.indexOf("GET /channel/menos") >= 0) {
              Serial.println("Trocou o canal da TV (-)");
              funcTV2 = "CanalMenos";
              irsend.sendNEC(infraRedCode[1], 32); // COMANDO PARA TROCAR (+) O CANAL DA TV  
              Serial.println("CÓDIGO PARA TROCAR O CANAL (-): 0x1FE649B");}
            
            // Inicio da implementação da página web usando HTML + CSS
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<style>html {font-family: Helvetica;display: inline-block;margin: 0px auto;text-align: center;}");
            client.println(".buttonPower {background-color: #ff0000;border-color: white;border-radius: 50%;color: white;padding: 16px 40px;text-decoration: none;font-size: 30px;margin: 2px;cursor: pointer;}");
            client.println("#buttonOff {background-color: #1b680b;}");
            client.println(".button {background-color: #ff6b08;border: 1.5px solid white;color: white;padding: 20px 20px;text-decoration: none;font-size: 30px;cursor: pointer;}");
            client.println(".button2 {background-color: blue;}");
            client.println(".gridControle{background-color: black;width: 350px;height: 470px;padding: 10px;margin: auto;border: 10px solid gray;border-radius: 50px;}");
            client.println(".gridContainerComandos{display: grid;grid-template-columns: auto auto auto;padding: 10px;}");
            client.println(".footer{text-align:center;color:#ffffff;font-size:0.8rem;padding:10px;}");
            client.println(".footerInfos{border: medium solid purple;border-radius: 50px;margin: 40px auto;width: 350px;height: 200px;}</style></head>");
            
            // Corpo da Página Web
            client.println("<body><h1>INTERFACE DE COMANDO DE CONTROLE REMOTO IR COM PROTOCOLO WEB</h1>");
            client.println("<p>Trabalho da disciplina de Integração de Redes Industriais</p>");
            // Mostra a última função realizada  
            client.println("<p>Televisão: " + funcTV + "</p>");

            client.print("<div class=\"gridControle\">");  
            if (funcTV=="Desligada") {
              client.println("<p><a href=\"/power/on\"><button class=\"buttonPower\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/power/off\"><button class=\"buttonPower\" id=\"buttonOff\">OFF</button></a></p>");
            }
            client.print("<p style=\"color:white\">Último Comando: " + funcTV2 + "</p>");
            client.print("<div class=\"gridContainerComandos\">");
            client.print("<div><p><a href=\"/volume/mais\"><button class=\"button\">↑</button></a></p></div>");
            client.print("<div></div>");
            client.print("<div><p><a href=\"/channel/mais\"><button class=\"button button2\">↑</button></a></p></div>");
            client.print("<div><p style=\"color:white\">VOLUME</p></div>");
            client.print("<div></div>");
            client.print("<div><p style=\"color:white\">CANAL</p></div>");
            client.print("<div><p><a href=\"/volume/menos\"><button class=\"button\">↓</button></a></p></div>");
            client.print("<div></div>");
            client.print("<div><p><a href=\"/channel/menos\"><button class=\"button button2\">↓</button></a></p></div>");
            client.print("</div>");
            client.print("<div class=\"footer\"><b>----- DEGM -----</b></div>");
            client.print("</div>");

            // Rodapé da página Web
            client.print("<div class=\"footerInfos\">");
            client.print("<h2>Integrantes do Grupo</h2>");
            client.print("<p>Diogo Conterato Possebon</p>");
            client.print("<p>Eduardo Mello Martins</p>");
            client.print("<p>Guilherme Ramos Londero</p>");
            client.print("<p>Matheus Gaviraghi</p></div>");
            client.print("</body></html>");
            
            // A resposta do HTTP termina com uma outra linha em branco
            client.println();
            
            break;
          } else { 
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c;      
        }
      }
    }
    // Limpa o que foi armazenado no header
    header = "";
    // Finaliza a conexão
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
    
  }
}
