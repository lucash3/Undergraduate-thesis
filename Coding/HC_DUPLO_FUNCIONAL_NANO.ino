// Código de configuração da Bengala inteligente
 
#include <HCSR04.h>

//conexão dos pinos para os sensores ultrassônicos e buzzer
#define PIN_TRIGGER1   5
#define PIN_ECHO1      4
#define PIN_TRIGGER2   3
#define PIN_ECHO2      2
#define PIN_BUZZER      10

UltraSonicDistanceSensor distanceSensor(PIN_TRIGGER1, PIN_ECHO1);  // Inicializa o sensor ultrassônico 1 nos pinos 4 e 5
UltraSonicDistanceSensor distanceSensor2(PIN_TRIGGER2, PIN_ECHO2); // Inicializa o sensor ultrassônico 2 nos pinos 2 e 3
int d1, d2;     //Distâncias dos senssores 1 e 2 respectivamente
char t='b';

void setup () {
    Serial.begin(9600);  //Serial iniciado em 9600 baud
    pinMode(PIN_BUZZER,     OUTPUT);    //pino digital 10 configurado como saída
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
