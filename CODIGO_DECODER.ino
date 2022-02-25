/***
PROJETO SEMESTRAL DE INTEGRAÇÃO DE REDES INDUSTRIAIS

Título do projeto: INTERFACE DE CONTROLE REMOTO IR COM PROTOCOLO WEB

Código: circuito decodificador

Integrantes:Diogo Conterato Possebon, Eduardo Mello Martins, Guilherme Ramos Londero e Matheus Gaviraghi

***/

#include <Arduino.h>
#include <IRremote.h>

int recvPin = 34;
IRrecv irrecv(recvPin);

void  setup ( )
{
  Serial.begin(115200);   
  irrecv.enableIRIn();  
}

void  encoding (decode_results *results)
{
  switch (results->decode_type) {
    default:
    case UNKNOWN:      Serial.print("UNKNOWN");       break ;
    case NEC:          Serial.print("NEC");           break ;
  }
}

void  dumpInfo (decode_results *results)
{
  // Conferindo se o resultado não tem overflow
  if (results->overflow) {
    Serial.println("IR code too long. Edit IRremoteInt.h and increase RAWBUF");
    return;
  }

  // Print do Enconding
  Serial.print("Encoding  : ");
  encoding(results);
  Serial.println("");

  // Print do codigo e do tamanho
  Serial.print("Code      : F7C03F ");
  ircode(results);
  Serial.print(" (");
  Serial.print(results->bits, DEC);
  Serial.println(" bits)");
}

void  dumpRaw (decode_results *results)
{
  for (int i = 1;  i < results->rawlen;  i++) {
    unsigned long  x = results->rawbuf[i] * USECPERTICK;
    if (!(i & 1)) {  // par
       (x < 1000);  
      if (x < 100);   
    
    } else {  // impar
      if (x < 1000);  
      if (x < 100);   
      if (i < results->rawlen-1); 
    }
    if (!(i % 8));  
  }
}

void  dumpCode (decode_results *results)
{
  pinMode(21, LOW);
  for (int i = 1;  i < results->rawlen;  i++) {
    if ( i < results->rawlen-1 ); 
    if (!(i & 1));  
  }

  encoding(results);
  ircode(results);

  // Print de codigos registrados
  if (results->decode_type != UNKNOWN) {

    // Print da data
    Serial.println("");
    Serial.print("unsigned int  data = 0x");
    Serial.print(results->value, HEX);
    Serial.println(";");
  }
}

void  loop ( )
{
  decode_results  results;        

  if (irrecv.decode(&results)) {  // Capturando resultado
    dumpInfo(&results);           
    dumpRaw(&results);            
    dumpCode(&results);           
    Serial.println("");           // Quebra de linha
    irrecv.resume();              // Prepara para novo recebimento
  }
}
