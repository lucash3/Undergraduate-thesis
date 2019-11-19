/*Código da Pulseira BLE usando uma Digispark
Ambas bibliotecas foram adicionadas do repositório oficial da Digispark no GitHub.
Na raiz Arduino/libraries --> git clone https://github.com/digistump/DigistumpArduino.git
*/

#include <SoftSerial.h>
#include <TinyPinChange.h>
 
#define SOFT_RX 3       
#define SOFT_TX 2
#define PIN_VIBRA     1

SoftSerial BLE_serial(2, 3); //rxPin = 2 , txPin = 3

void setup()
{
 pinMode(PIN_VIBRA,     OUTPUT);  //Define o pino digital como saída.
 BLE_serial.begin(9600); // Terminal BLE configurado em 9600 baud
}
void loop()
{
  while (BLE_serial.available() > 0) {   //Laço que mantém a transmissão pelo BLE 1010 ativa 
    char inByte = BLE_serial.read();     //Coloca a informação recebida por bluetooth em uma variável tipo char

  if(inByte=='b'){                       //Define as condições de vibração. No caso, quando recebe o char 'b' vibra por 50 ms e depois desliga.
  digitalWrite(PIN_VIBRA, HIGH);
  delay(50);
  digitalWrite(PIN_VIBRA, LOW);
  delay(50);
                 }
  }

}
