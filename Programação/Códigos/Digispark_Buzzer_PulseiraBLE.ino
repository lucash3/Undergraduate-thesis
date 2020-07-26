//Configurar módulo BLE com comandos AT
//Alimenta dados do BLE para a serial do Arduino e vice versa
//Autoria: Lucas Henrique Santos Souza & Welligtton Silva Cavedo

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
 delay(1000);
 /*BLE_serial.write("AT+IMME1");
 delay(500);
 BLE_serial.write("AT+ROLE1");
 delay(500);
 BLE_serial.write("AT+RESET");
 */
 BLE_serial.write("AT+DISC?");
 delay(5000);
 BLE_serial.write("AT+CON0013AA0004F0");
 
 delay(100);

 
}
void loop()
{
 
 while (BLE_serial.available() > 0) {
    char inByte = BLE_serial.read();
    Serial.print(inByte);

  while(inByte=='a'){
  digitalWrite(PIN_VIBRA, HIGH);
  inByte = BLE_serial.read();
  }

  while(inByte=='b'){
  digitalWrite(PIN_VIBRA, HIGH);
  delay(200);
  digitalWrite(PIN_VIBRA, LOW);
  //delay(50);
  inByte = BLE_serial.read();
  }

  while(inByte=='c'){
  digitalWrite(PIN_VIBRA, HIGH);
  delay(500);
  digitalWrite(PIN_VIBRA, LOW);
  //delay(50);
  inByte = BLE_serial.read();
  }

  while(inByte=='o'){
  digitalWrite(PIN_VIBRA, LOW);
  inByte = BLE_serial.read();
  }
  
  }

}
