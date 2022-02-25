/***
PROJETO SEMESTRAL DE INTEGRAÇÃO DE REDES INDUSTRIAIS

Título do projeto: INTERFACE DE CONTROLE REMOTO IR COM PROTOCOLO WEB

Código: Código do emissor IR

Integrantes:Diogo Conterato Possebon, Eduardo Mello Martins, Guilherme Ramos Londero e Matheus Gaviraghi

***/

#include <IRremote.h>

IRsend irsend;

unsigned long infraRedCode[] = {
  0x1FE8A75, //POWER 
  0x1FE14EB, //CANAL +
  0x1FE649B, //CANAL -
  0x1FE728D, //VOLUME +
  0x1FE6A95, //VOLUME -
};
void setup() {
  Serial.begin(9600);
}

void loop() {
   
  for (int i = 0; i < 10; i++) {
    irsend.sendNEC(infraRedCode[3], 32);
    Serial.println("VOLUME +");
    delay(1000);
  }
  delay(2000);
  
  for (int i = 0; i < 10; i++) {
    irsend.sendNEC(infraRedCode[4], 32);
    Serial.println("VOLUME -");
    delay(1000);
  }
  delay(2000);

  for (int i = 0; i < 3; i++) {
    irsend.sendNEC(infraRedCode[2], 32); 
    Serial.println("CANAL-");
    delay(2000);
  }
  for (int i = 0; i < 3; i++) {
    irsend.sendNEC(infraRedCode[1], 32);
    Serial.println("CANAL+");
    delay(2000);
  }
}
