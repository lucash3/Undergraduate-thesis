
#include <SparkFun_RFD77402_Arduino_Library.h> //Use Library Manager or download here: https://github.com/sparkfun/SparkFun_RFD77402_Arduino_Library
RFD77402 myDistance; //Hook object to the library

char a='a';
char b='b';
char c='c';
char o='o';

void setup()
{
  Serial.begin(9600);
  while (!Serial);


  if (myDistance.begin() == false)
  {
    //Serial.println("Sensor failed to initialize. Check wiring.");
    while (1); //Freeze!
  }
 // Serial.println("Sensor online!");
  
}

void loop()
{
  myDistance.takeMeasurement(); //Tell sensor to take measurement

  unsigned int distance = myDistance.getDistance(); //Retrieve the distance value
  unsigned int d = distance/10;

    if(d<50&&d>1)
    Serial.println(a);
    if(d<100&&d>50){
    Serial.println(b);
    delay(200);}
    if(d<150&&d>100){
    Serial.println(c);
    delay(500);}
    if(d>150)
    Serial.println(o);
    delay(50);
}
