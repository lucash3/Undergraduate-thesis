#include <HCSR04.h>

#define INTERVALO_LEITURA 200 //(ms)

//conexão dos pinos para o sensor ultrasonico e buzzer
#define PIN_TRIGGER1   5
#define PIN_ECHO1      4
#define PIN_TRIGGER   3
#define PIN_ECHO      2
#define PIN_BUZZER      7
#define PIN_BUZZER1     7

UltraSonicDistanceSensor distanceSensor(5, 4);  // Initialize sensor that uses digital pins 13 and 12.
UltraSonicDistanceSensor distanceSensor2(3, 2);
int d1, d2;
void setup () {
    Serial.begin(115200);  // We initialize serial connection so that we could print values from sensor.
    pinMode(PIN_BUZZER,     OUTPUT); 
}

void loop () {

    digitalWrite(PIN_BUZZER, LOW);
  
    d1=distanceSensor.measureDistanceCm();
    delay(50);
    d2=distanceSensor2.measureDistanceCm();
    if(d1<=200){
    // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
    //Serial.print("Sensor 1:  ");
    Serial.println(d1);
    if(d1<10 && d1!=-1)
    digitalWrite(PIN_BUZZER, HIGH);
    
  //  Serial.print(" - Sensor 2:  ");
    Serial.println(d2);}
    delay(100);
}
