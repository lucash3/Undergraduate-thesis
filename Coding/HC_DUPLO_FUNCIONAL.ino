#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(7, 6);  // Initialize sensor that uses digital pins 13 and 12.
UltraSonicDistanceSensor distanceSensor2(3, 2);
float d1, d2;
void setup () {
    Serial.begin(115200);  // We initialize serial connection so that we could print values from sensor.
}

void loop () {
    d1=distanceSensor.measureDistanceCm();
    delay(50);
    d2=distanceSensor2.measureDistanceCm();
    if(d1<=200){
    // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
    Serial.print("Sensor 1:  ");
    Serial.print(d1);
    Serial.print(" - Sensor 2:  ");
    Serial.println(d2);}
    delay(100);
}
