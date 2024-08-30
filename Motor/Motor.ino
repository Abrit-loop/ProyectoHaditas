//Programa para control del motor

const int PinIN1 = 2;
const int PinIN2 = 4;
const int PinPWM = 3;

int MotorSpeed = 255;

void setup() {
// inicializar la comunicación serial a 9600 bits por segundo:
Serial.begin(9600);
// configuramos los pines como salida
pinMode(PinIN1, OUTPUT);
pinMode(PinIN2, OUTPUT);
pinMode(PinPWM, OUTPUT);
}

void loop() {
MotorHorario(MotorSpeed);
Serial.println("Giro del Motor en sentido horario");
delay(5000);
MotorAntihorario(MotorSpeed);
Serial.println("Giro del Motor en sentido antihorario");
delay(5000);
MotorStop();
Serial.println("Motor Detenido");
delay(3000);
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


__________________________________