
#include <SparkFun_RFD77402_Arduino_Library.h> //Use Library Manager or download here: https://github.com/sparkfun/SparkFun_RFD77402_Arduino_Library
RFD77402 myDistance; //Hook object to the library

char a='a';
char b='b';
char c='c';
char o='o';

int BUZZER = 8;     
int STATE = 0;     //Pino state do HM10 ( nivél lógico baixo caso deconectado, nível lógico alto caso concetado)
int   volt = 0;    //variável que armazena a quantidade de bateria em percentual, considerando 100% 5 volts.

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
  delay(3000);
}

void loop()
{
  STATE = digitalRead(8);   
  
  while(STATE==0){
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
    
  }
  
//------------------SEÇÃO DE MEDIÇÕES---------------------
//Quando o STATE vai para o valor 1 (alto), inicia-se o while abaixo que cuida das medições e envio bluetooth.
//Em outras palavras, só faz medições e envio de dados quando o pino STATE é deslocado para nível lógico alto.
  
 
  while(STATE==1){
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
