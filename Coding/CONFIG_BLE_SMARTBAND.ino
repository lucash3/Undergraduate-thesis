//Configurar módulo BLE com comandos AT
//Alimenta dados do  serial do Arduino para o BLE (HM10)
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
 BLE_serial.write("AT+ALLO1");            //permite conexão apenas de dispositivos previamente salvos
 delay(500);
 BLE_serial.write("AT+AD10013AA0004F0");  //adiciona o endereço do módulo HC a whitelist da pulseira
 delay(500);
 BLE_serial.write("AT+AD20013AA0021BA");  //adiciona o endereço do módulo TOF a whitelist da pulseira
 delay(500);
 BLE_serial.write("AT+IMME1");            //modo de conexão manual
 delay(500);
 BLE_serial.write("AT+ROLE1");            //ativa o modo mestre
 delay(500);
 BLE_serial.write("AT+RESET");        
 }

}
