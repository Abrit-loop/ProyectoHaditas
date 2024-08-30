
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

 // Control del motor//

const int PinIN1 = 2;
const int PinIN2 = 4;
const int PinPWM = 3;

int MotorSpeed ();


void setup() {
  //Control motor//
  // inicializar la comunicación serial a 9600 bits por segundo:
Serial.begin(9600);
// configuramos los pines como salida
pinMode(PinIN1, OUTPUT);
pinMode(PinIN2, OUTPUT);
pinMode(PinPWM, OUTPUT);
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
  if (distanceR >= 10 && (distanceL >= 10)) {
    angulo=90;
    microServo.write(angulo);
    MotorHorario(255);

  }else{
  while (distanceR < 10 && (distanceL >= 10)) {
    angulo=45;
    microServo.write(angulo);
    MotorHorario(128);
   }
     while (3 < distanceL < 10 && (distanceR >= 10)) {
    angulo=135;
    microServo.write(angulo);
    MotorHorario(128);

    while (distanceR < 3 && (distanceL >= 10)) {
    angulo=25;
    microServo.write(angulo);
    MotorHorario(128);
   }
   } 
  }
}
//función para girar el motor en sentido horario
void MotorHorario(int Speed)
{
analogWrite (PinPWM, Speed);
digitalWrite (PinIN1, HIGH);
digitalWrite (PinIN2, LOW);
}
//función para girar el motor en sentido antihorario
void MotorAntihorario(int Speed)
{
analogWrite (PinPWM, Speed);
digitalWrite (PinIN1, LOW);
digitalWrite (PinIN2, HIGH);
}


//función para apagar el motor
void MotorStop()
{
digitalWrite (PinIN1, LOW);
digitalWrite (PinIN2, LOW);
}

