//servo//
#include <Servo.h>
Servo servoMotor;
// Motor//
const int ENA = 3;
const int IN1 = 2;
const int IN2 = 4;
int MotorSpeed = 255;

 //sensorR//
const int trigPinR = 10;  
const int echoPinR = 9;
long durationR;
int distanceR;  
 //sensorL//
const int trigPinL = 6;  
const int echoPinL = 5;
long durationL;
int distanceL;  


void setup() {
  //motor//
  pinMode (ENA, OUTPUT);
 pinMode (IN1, OUTPUT);
 pinMode (IN2, OUTPUT);
  //servo//
servoMotor.attach(11);
servoMotor.write(90);
 //sensores//
	pinMode(trigPinR, OUTPUT);  
	pinMode(echoPinR, INPUT);  
  pinMode(trigPinL, OUTPUT);  
	pinMode(echoPinL, INPUT);  
	Serial.begin(9600);  
}  
  


void loop() {
  
  //SENSOR R
digitalWrite(trigPinR, LOW);  
delayMicroseconds(2);  
digitalWrite(trigPinR, HIGH);  
delayMicroseconds(10);  
digitalWrite(trigPinR, LOW);  
  durationR = pulseIn(echoPinR, HIGH);
  distanceR = (durationR*0.0343)/2;
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
while (distanceR > 10) {
    void Adelante();
    }// aqui es de que si la distancia detectada del lado derecho es mayor a 10cm entonces puede ir hacia adelante, no se  cuales serian los valores reales es para probar y hay que icluir el sensor izquierdo
      while (distanceR < 5) {
        void Giro();
      }// aqui es que cuando la distancia del lado derecho es menor a 5cm entonces el carro tiene que disminuir la velocidad y girar, no esta definitvo, hay que probar
  }// hasta ahi llega por ahora
    
void Adelante()
{   digitalWrite (IN1, HIGH);
    digitalWrite (IN2, LOW);
    analogWrite (ENA, 155); 

}

void Giro()
{ 
  void Posicion50();
    digitalWrite (IN1, HIGH);
    digitalWrite (IN2, LOW);
    analogWrite (ENA, 53); 

}
void Posicion50 ()
  {
  // Desplazamos a la posición 50
  servoMotor.write(50);
  // Esperamos 1 segundo
  delay(1000);
  }
  void Posicion0 ()
  {
  // Desplazamos a la posición 90º
  servoMotor.write(0);
  // Esperamos 1 segundo
  delay(1000);
  }
    void Posicion180 ()
  {
  // Desplazamos a la posición 90º
  servoMotor.write(180);
  // Esperamos 1 segundo
  delay(1000);
  }

  
