//Configurar módulo BLE com comandos AT
//Alimenta dados do BLE para a serial do Arduino e vice versa
#include <SoftwareSerial.h>

  #define PIN_STATE      10
 int x=500;
SoftwareSerial BLE_serial = SoftwareSerial(8,9); //rxPin = 3 , txPin = 4
void setup()
{
  
 Serial.begin(9600); // Monitor Serial Arduino
 BLE_serial.begin(9600); // Terminal BLE
 Serial.println("Configurar módulo BLE1010 Soft com comandos AT");
 Serial.println("Digite AT e observe a resposta OK\n");

  pinMode(PIN_STATE,     INPUT);  
 
}
void loop()
{
 // Serial.println(digitalRead(PIN_STATE));
 // Alimenta dados do BLE para o Monitor Serial do Arduino
 if (BLE_serial.available()>0)
 {
 Serial.write(BLE_serial.read());
 }
 // Alimenta dados do Monitor Serial do Arduino para o BLE
 if (Serial.available()>0)
 {
  BLE_serial.write(Serial.read());
  
 // BLE_serial.write(x);
 x--;
 }

}
