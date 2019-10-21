#include <SoftwareSerial.h>
SoftwareSerial mySerial(8,9); //(TX/RX)

void setup()
{
  mySerial.begin(9600);   
  Serial.begin(9600);   
  delay(100);
}
void loop()
{

if (Serial.available()>0)   //do monitor pra o smartphone
mySerial.write(Serial.read());
if (mySerial.available()>0) //do smartphone para o monitor
Serial.write(mySerial.read());

}
