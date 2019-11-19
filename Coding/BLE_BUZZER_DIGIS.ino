//Configurar módulo BLE com comandos AT
//Alimenta dados do BLE para a serial do Arduino e vice versa
#include <SoftSerial.h>
#include <TinyPinChange.h>
 
#define SOFT_RX 3
#define SOFT_TX 2
#define PIN_VIBRA     1


SoftSerial BLE_serial(2, 3); //rxPin = 3 , txPin = 4
void setup()
{
 pinMode(PIN_VIBRA,     OUTPUT); 
 BLE_serial.begin(9600); // Terminal BLE 
}
void loop()
{
 
 while (BLE_serial.available() > 0) {
    char inByte = BLE_serial.read();
    Serial.print(inByte);

  if(inByte=='b'){
  digitalWrite(PIN_VIBRA, HIGH);
  delay(50);
  digitalWrite(PIN_VIBRA, LOW);
  delay(50);
  }
  
  }

}
