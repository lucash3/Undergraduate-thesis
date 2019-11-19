#include <HCSR04.h>

#define INTERVALO_LEITURA 200 //(ms)

//conexão dos pinos para o sensor ultrasonico e buzzer
#define PIN_TRIGGER1   5
#define PIN_ECHO1      4
#define PIN_TRIGGER   3
#define PIN_ECHO      2
#define PIN_BUZZER      10
#define PIN_BUZZER1     7

UltraSonicDistanceSensor distanceSensor(5, 4);  // Initialize sensor that uses digital pins 13 and 12.
UltraSonicDistanceSensor distanceSensor2(3, 2);
int d1, d2;
char t='b';
char r='a';
void setup () {
    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
    pinMode(PIN_BUZZER,     OUTPUT); 
}

void loop () {
    
    digitalWrite(PIN_BUZZER, LOW);
  
    d1=distanceSensor.measureDistanceCm();
    delay(50);
    d2=distanceSensor2.measureDistanceCm();
    if(d1<=15)
    Serial.println(t);
    delay(100);
    if(d1<10 && d1!=-1)
    digitalWrite(PIN_BUZZER, HIGH);
    
    if(d2<=15)
    Serial.println(t);
    delay(100);
    
}
