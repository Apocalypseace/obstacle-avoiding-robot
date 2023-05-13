#include <Servo.h> 
int servoPin = 12; 
int in1=11;
int in2=2;
int in3=3;
int in4=4;

int i1=5;
int i2=6;
int i3=7;
int i4=8;
float duration;
float distance;
const int trigpin=10;
const int echopin=9;
Servo Servo1; 
void setup() {
     Servo1.attach(servoPin); 
     Servo1.write(90);
  pinMode(in1,OUTPUT);
    pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  
  pinMode(i1,OUTPUT);
  pinMode(i2,OUTPUT);
  pinMode(i3,OUTPUT);
  pinMode(i4,OUTPUT);
   pinMode(trigpin, OUTPUT); 
  pinMode(echopin, INPUT); 
    Serial.begin(9600);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);

  digitalWrite(i1,LOW);
  digitalWrite(i3,LOW);
  digitalWrite(i3,LOW);
  digitalWrite(i4,LOW);


}

void loop() {
  snsr();
  if(distance<=20)
  {
  stp();
  servo1();
  if(distance<=20)
  {
    servo2();
    servo();
    if (distance<=20)
    {
      back();
    }
  }
}
forward();
} 
void snsr()
{
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echopin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);


}
void servo1()
{
  Servo1.write(0); 
   delay(1000); 

   digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echopin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
   // Make servo go to 90 degrees



   Servo1.write(90);
   delay(1000);

   if (distance>= 20)
    {
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in4,HIGH);
digitalWrite(in3,LOW);

digitalWrite(i1,LOW);
digitalWrite(i2,HIGH);
digitalWrite(i3,LOW);
digitalWrite(i4,HIGH);
      delay(300);

  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);

  digitalWrite(i1,LOW);
  digitalWrite(i3,LOW);
  digitalWrite(i3,LOW);
  digitalWrite(i4,LOW);
    }
}
void servo2()
{
  Servo1.write(180); 
   delay(1000); 

   digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echopin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

   

    if (distance>=20)
    {
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
digitalWrite(in4,LOW);
digitalWrite(in3,HIGH);

digitalWrite(i1,HIGH);
digitalWrite(i2,LOW);
digitalWrite(i3,HIGH);
digitalWrite(i4,LOW);
      delay(300);

  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);

  digitalWrite(i1,LOW);
  digitalWrite(i3,LOW);
  digitalWrite(i3,LOW);
  digitalWrite(i4,LOW);
    }
}

void servo()
{
  Servo1.write(90);
  delay(1000);
}

void stp()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);

  digitalWrite(i1,LOW);
  digitalWrite(i3,LOW);
  digitalWrite(i3,LOW);
  digitalWrite(i4,LOW);
}
void forward()
{
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in4,HIGH);
digitalWrite(in3,LOW);

digitalWrite(i1,HIGH);
digitalWrite(i2,LOW);
digitalWrite(i3,HIGH);
digitalWrite(i4,LOW);
}
void back()
{
  digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
digitalWrite(in4,LOW);
digitalWrite(in3,HIGH);

digitalWrite(i1,HIGH);
digitalWrite(i2,LOW);
digitalWrite(i3,HIGH);
digitalWrite(i4,LOW);
      delay(570);
}
