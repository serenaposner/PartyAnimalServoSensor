//this is a program that controls the servo motor, and thereby the 
//arm/leg movement of the character on the "party animal" card

#include <Servo.h> 
Servo theservo;

int value = 0;
int ledPin = 13;
int sensorval = 0;

void setup(){ 
  theservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);

} 

void loop(){
  
sensorval = analogRead(value);

if (sensorval < 100){ 
sensorval = 100;//insuring that the minimum value doesn't go below 100
}
if (sensorval > 1000){ 
sensorval = 1000;//insuring that the maximum value doesn't go over 1000
}

Serial.println(sensorval);//makes party animal dance when the card is open, and stop when it's closed
if(sensorval>700){
theservo.write(100);
delay(10);
theservo.write(20);
delay(10);
}

if(sensorval>600 && sensorval<650){//makes party animal wiggle with excitement when the card is almost open
 theservo.write(100);
delay(12);
theservo.write(30);
delay(12);
}

}
