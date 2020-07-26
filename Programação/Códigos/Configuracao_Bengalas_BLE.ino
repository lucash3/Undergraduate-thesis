//Configurar módulo BLE com comandos AT
//Alimenta dados do  serial do Arduino para o BLE (HM10)
//Autoria: Lucas Henrique Santos Souza & Welligtton Silva Cavedo

#include <SoftwareSerial.h>


SoftwareSerial BLE_serial = SoftwareSerial(4,5); //rxPin = 5 , txPin = 4
void setup()
{

 Serial.begin(9600); // Monitor Serial Arduino
 BLE_serial.begin(9600); // Terminal BLE 
}

void loop()
{

 if (Serial.available()>0)
 {
 BLE_serial.write("AT+ADTY1");            //permite conexão apenas o último dispositivo salvo
 delay(500);
 BLE_serial.write("AT+ROLE0");            //ativa o modo escravo
 delay(500);
 BLE_serial.write("AT+RESET");        
 }

}
