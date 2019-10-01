/*
 * ----------------------------------
 * $Author: PFG2 - IoT Tecnologia Assistiva $
 * $Date: 2019-09-27 $
 * $Revision: 2 $
 * ----------------------------------
 */

#include <Ultrasonic.h>

unsigned int distancia = 0;

int TRIGGER_PIN = 4;
int ECHO_PIN  =   5;

Ultrasonic ultrasonic1(TRIGGER_PIN, ECHO_PIN);
Ultrasonic ultrasonic2(18, 19);

void setup()
  {
  Serial.begin(9600);
  }

void loop()
  {
    
    distancia = getDistance();

    int distanciaCM;
    long microsec = ultrasonic2.timing();
    distanciaCM = ultrasonic2.convert(microsec, Ultrasonic::CM);
    
    Serial.print("*** Sent Value: ");
    Serial.print(distancia);
    Serial.print(" ");
    Serial.print(distanciaCM);
    Serial.println(" ***");
    
 /* if ((TRIGGER_PIN = 4) && (ECHO_PIN = 5)){
    TRIGGER_PIN = 18;
    ECHO_PIN = 19;
  }
  if ((TRIGGER_PIN = 18) && (ECHO_PIN = 19)){
    TRIGGER_PIN = 4;
    ECHO_PIN = 5;
  }*/
  
  delay(500);
  }

int getDistance()
{
    //faz a leitura das informacoes do sensor (em cm)
    int distanciaCM;
    long microsec = ultrasonic1.timing();
    distanciaCM = ultrasonic1.convert(microsec, Ultrasonic::CM);

    return distanciaCM;

}
