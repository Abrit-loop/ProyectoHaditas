
//definiciones//
#define OUTPUT 0x1
#define INPUT 0x0
#define LOW 0x0
#define HIGH 0x1
//servo//
#include <Servo.h> //incluimos la libreria del servo
Servo microServo; //llamamos al objeto servo
int angulo;

 //sensorR//
const int trigPinR = 10;  
const int echoPinR = 9;
float durationR;
float distanceR;  
 //sensorL//
const int trigPinL = 6;  
const int echoPinL = 5;
float durationL;
float distanceL;  

void setup() {
  //sensores//
	pinMode(trigPinR, OUTPUT);  
	pinMode(echoPinR, INPUT);  
  pinMode(trigPinL, OUTPUT);  
	pinMode(echoPinL, INPUT);  
	Serial.begin(9600);
    //servo//
  microServo.attach(11); //el pin del servo es el 11
  Serial.begin (9600);
  microServo.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
  //SENSOR R
digitalWrite(trigPinR, LOW);  
delayMicroseconds(2);  
digitalWrite(trigPinR, HIGH);  
delayMicroseconds(10);  
digitalWrite(trigPinR, LOW);  

  float durationR = pulseIn(echoPinR, HIGH);
  float distanceR = (durationR*0.0343)/2;
  Serial.println(distanceR);

  
    //SENSOR L
digitalWrite(trigPinL, LOW);  
delayMicroseconds(2);  
digitalWrite(trigPinL, HIGH);  
delayMicroseconds(10);  
digitalWrite(trigPinL, LOW);  
  durationL = pulseIn(echoPinL, HIGH);
  distanceL = (durationL*0.0343)/2;
   Serial.println(distanceL);
   //algoritmo
  if (distanceR >= 5 && (distanceL >= 5)) {
    angulo=90;
    microServo.write(angulo);
  }else{
  while (distanceR < 5 && (distanceL >= 5)) {
    angulo=45;
    microServo.write(angulo);
   }
     while (distanceL < 5 && (distanceR >= 5)) {
    angulo=135;
    microServo.write(angulo);

    while (distanceR < 3 && (distanceL >= 5)) {
    angulo=25;
    microServo.write(angulo);
   }
   } 
  }
}


