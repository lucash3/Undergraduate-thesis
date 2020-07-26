// Autoria: Lucas Henrique Santos Souza & Welligtton Silva Cavedo

#include <SparkFun_RFD77402_Arduino_Library.h> //Use Library Manager or download here: https://github.com/sparkfun/SparkFun_RFD77402_Arduino_Library
RFD77402 myDistance; //Hook object to the library

char a='a';
char b='b';
char c='c';
char o='o';

int BUZZER = 10;     
int STATE = 0;     //Pino state do HM10 ( nivél lógico baixo caso deconectado, nível lógico alto caso concetado)
int   volt = 0;    //variável que armazena a quantidade de bateria em percentual, considerando 100% 5 volts.
int contador = 0;
bool buz = false;

void setup()
{
  pinMode(BUZZER, OUTPUT);   
  pinMode(7 , INPUT); 
  Serial.begin(9600);
  while (!Serial);


  if (myDistance.begin() == false) //caso o sensor TOF falhe
  {
    while (1); //Freeze!
  }

  tone(BUZZER, 1600, 300);
  delay(100);
  tone(BUZZER, 1700, 300);
  delay(100);
  tone(BUZZER, 1800, 300);
  delay(100);
  tone(BUZZER, 1900, 300);
  delay(100);
  tone(BUZZER, 2000, 200);
  STATE = digitalRead(3);  
  delay(3000);
  
}

void loop()
{
  STATE = digitalRead(3);   
  
  while(STATE==0 && buz==false){
  tone(BUZZER, 1600, 300);
  delay(100);
  tone(BUZZER, 1700, 300);
  delay(5000);
  STATE = digitalRead(3); 
    if(STATE==1){
      tone(BUZZER, 2500, 200);
      delay(300);
      tone(BUZZER, 2500, 200);
    }
  if(contador>=5){
    buz=true;
    }
    contador++;
  }
  
//------------------SEÇÃO DE MEDIÇÕES---------------------
//Quando o STATE vai para o valor 1 (alto), inicia-se o while abaixo que cuida das medições e envio bluetooth.
//Em outras palavras, só faz medições e envio de dados quando o pino STATE é deslocado para nível lógico alto.
  
 
  while(STATE==1 && buz==false){
 
  myDistance.takeMeasurement(); //Tell sensor to take measurement

  unsigned int distance = myDistance.getDistance(); //Retrieve the distance value
  unsigned int d = distance/10;

    if(d<50&&d>1) //distância está entre 1 e 50 cm
    Serial.println(a);
    
    if(d<100&&d>50){ //distância está entre 50 e 100 cm
    Serial.println(b);
    delay(200);}
    
    if(d<150&&d>100){ //distância está entre 100 e 150 cm
    Serial.println(c);
    delay(500);}
    
    if(d>150)
    Serial.println(o);
    delay(50);
   
    STATE = digitalRead(3); 
    delay(100);
}
  while(STATE==0 && buz==true){

  contador=0;
  myDistance.takeMeasurement(); //Tell sensor to take measurement

  unsigned int distance = myDistance.getDistance(); //Retrieve the distance value
  unsigned int d = distance/10;

    if(d<50&&d>1) //distância está entre 1 e 50 cm
      tone(BUZZER, 2000);

    if(d<100&&d>50){ //distância está entre 50 e 100 cm
      tone(BUZZER, 2000);
      delay(200);
      noTone(BUZZER);
      }

    
    if(d<150&&d>100){ //distância está entre 100 e 150 cm
      tone(BUZZER, 2000);
      delay(500);
      noTone(BUZZER);}

    
    if(d>150)
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
