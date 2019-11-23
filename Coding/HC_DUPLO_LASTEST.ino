#include <HCSR04.h>


//conexão dos pinos para o sensor ultrasonico e buzzer
#define PIN_TRIGGER1   5
#define PIN_ECHO1      4
#define PIN_TRIGGER2   3
#define PIN_ECHO2      2
#define PIN_BUZZER     10


UltraSonicDistanceSensor distanceSensor(PIN_TRIGGER1, PIN_ECHO1);  // Initialize sensor that uses digital pins 13 and 12.
UltraSonicDistanceSensor distanceSensor2(PIN_TRIGGER2, PIN_ECHO2);
int d1, d2;
char a='a';
char b='b';
char c='c';
char o='o';

void setup () {
    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
    pinMode(PIN_BUZZER,     OUTPUT); 
}

void loop () {
    
    digitalWrite(PIN_BUZZER, LOW);
  
    d1=distanceSensor.measureDistanceCm();
    d2=distanceSensor2.measureDistanceCm();
   
    if(d1<=d2&&d1<=50&&d1>1||d2<=d1&&d2<=50&&d2>1)
    Serial.println(a);
    if(d1<=d2&&d1<=100&&d1>50||d2<=d1&&d2<=100&&d2>50){
    Serial.println(b);
    delay(200);}
    if(d1<=d2&&d1<=150&&d1>100||d2<=d1&&d2<=150&&d2>100){
    Serial.println(c);
    delay(500);}
    if(d1>150&&d2>150||d1<1&&d2<1)
    Serial.println(o);
    delay(50);
    
    
    if(d1<10 && d1!=-1)
    digitalWrite(PIN_BUZZER, HIGH);
    
}
