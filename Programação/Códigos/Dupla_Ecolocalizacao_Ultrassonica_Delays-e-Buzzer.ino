// Autoria: Lucas Henrique Santos Souza & Welligtton Silva Cavedo
#include <HCSR04.h>


//conexão dos pinos para o sensor ultrasonico e buzzer
#define PIN_TRIGGER1   5
#define PIN_ECHO1      4
#define PIN_TRIGGER2   3
#define PIN_ECHO2      2

UltraSonicDistanceSensor distanceSensor(PIN_TRIGGER1, PIN_ECHO1); 
UltraSonicDistanceSensor distanceSensor2(PIN_TRIGGER2, PIN_ECHO2);
int d1, d2;
char a='a';
char b='b';
char c='c';
char o='o';

int BUZZER = 8;  
   
int STATE = 0;     //Pino state do HM10 ( nivél lógico baixo caso deconectado, nível lógico alto caso concetado)
int   volt = 0;    //variável que armazena a quantidade de bateria em percentual, considerando 100% 5 volts.
int contador = 0;
bool buz = false;

void setup() {
  pinMode(BUZZER, OUTPUT);   
  pinMode(7 , INPUT);      
  Serial.begin(9600);

  
  tone(BUZZER, 1600, 300);
  delay(100);
  tone(BUZZER, 1700, 300);
  delay(100);
  tone(BUZZER, 1800, 300);
  delay(100);
  tone(BUZZER, 1900, 300);
  delay(100);
  tone(BUZZER, 2000, 200);
  STATE = digitalRead(8); 
  delay(3000);
}

void loop() {
  
  STATE = digitalRead(8);   
  
  while(STATE==0 && buz==false){
  tone(BUZZER, 1600, 300);
  delay(100);
  tone(BUZZER, 1700, 300);
  delay(5000);
  STATE = digitalRead(7); 
    if(STATE==1){
      tone(BUZZER, 2500, 200);
      delay(300);
      tone(BUZZER, 2500, 200);
    }
    if(contador>=5){ // após 30 sem segundos sem estabeler conexão, o módulo entra em modo buzzer, onde usa o buzzer como sinal de detecção de obstáculo
    buz=true;
    }
    contador++;  
  }


//------------------SEÇÃO DE MEDIÇÕES---------------------
//Quando o STATE vai para o valor 1 (alto), inicia-se o while abaixo que cuida das medições e envio bluetooth.
//Em outras palavras, só faz medições e envio de dados quando o pino STATE é deslocado para nível lógico alto.

  while(STATE==1 && buz==false){
    d1=distanceSensor.measureDistanceCm();
    d2=distanceSensor2.measureDistanceCm();
   
    if(d1<=d2&&d1<=50&&d1>1||d2<=d1&&d2<=50&&d2>1) //distância está entre 1 e 50 cm
    Serial.println(a);
    
    if(d1<=d2&&d1<=100&&d1>50||d2<=d1&&d2<=100&&d2>50){  //distância está entre 50 e 100 cm
    Serial.println(b);
    delay(200);}
    
    if(d1<=d2&&d1<=130&&d1>100||d2<=d1&&d2<=130&&d2>100){   //distância está entre 100 e 130 cm
    Serial.println(c);
    delay(500);}
    
    if(d1>130&&d2>130||d1<1&&d2<1){      //distância está acima de 130
    Serial.println(o);
    delay(50);}


   volt = map(analogRead(A7), 0, 1023, 0, 100);   //Verifica o nível de bateria a cada nova medição
    if(volt<20){                                  //Se o nível de bateria for menor qu 20% emite um aviso sonoro diferente dos demais
      tone(BUZZER, 1500, 200);
      delay(300);
      tone(BUZZER, 1500, 200);
      delay(300);
      tone(BUZZER, 1500, 200);
    }

    
    STATE = digitalRead(7); 
    delay(100);
  }

  while(STATE==0 && buz==true){ // MODO BUZZER - usa o buzzer para detecção de obstáculos

  contador=0;
    d1=distanceSensor.measureDistanceCm();
    d2=distanceSensor2.measureDistanceCm();
    
    if(d1<=d2&&d1<=50&&d1>1||d2<=d1&&d2<=50&&d2>1) //distância está entre 1 e 50 cm
      tone(BUZZER, 2000);

    if(d1<=d2&&d1<=100&&d1>50||d2<=d1&&d2<=100&&d2>50){ //distância está entre 50 e 100 cm
      tone(BUZZER, 2000);
      delay(200);
      noTone(BUZZER);
      }

    
    if(d1<=d2&&d1<=130&&d1>100||d2<=d1&&d2<=130&&d2>100){ //distância está entre 100 e 130 cm
      tone(BUZZER, 2000);
      delay(500);
      noTone(BUZZER);}

    
    if(d1>130&&d2>130||d1<1&&d2<1)
      noTone(BUZZER); 
   
    STATE = digitalRead(3); 
    if(STATE==1){
      tone(BUZZER, 2500, 200);
      delay(300);
      tone(BUZZER, 2500, 200);
      buz=false;
      }
    delay(100);
}
  
}
