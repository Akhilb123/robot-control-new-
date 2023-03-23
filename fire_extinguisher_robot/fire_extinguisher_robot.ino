#include <Servo.h>
Servo myservo;
int pos = 0;
boolean fire = false;

int LeftSidesensor= 9;      // sensor at left side
int RightSidesensor = 10;      // sensor at right side
int Frontsidesensor = 8; //forward sensor

int LM1 = 2;       // left side motor
int LM2 = 3;       // left side motor
int RM1 = 4;       // right side motor
int RM2 = 5;       // right side motor
int pump = 6;        //pump
void setup()
{
  pinMode(LeftSidesensor, INPUT);
  pinMode(RightSidesensor, INPUT);
  pinMode(Frontsidesensor, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(pump, OUTPUT);
  myservo.attach(11);
  myservo.write(90);
}
void put_off_fire()
{
    delay (600);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
   digitalWrite(pump, HIGH); delay(600);
    for (pos = 50; pos <= 130; pos += 1) {
    myservo.write(pos);
    delay(20);
  }
  for (pos = 130; pos >= 50; pos -= 1) {
    myservo.write(pos);
    delay(20);
  }
  digitalWrite(pump,LOW);
  myservo.write(90);
  fire=false;
}
void loop()
{
   myservo.write(90); //Sweep_Servo();
    if (digitalRead(LeftSidesensor) ==1 && digitalRead(RightSidesensor)==1 && digitalRead(Frontsidesensor) ==1) //If Fire not detected all sensors are zero
    {
    //Do not move the robot
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
    }
    else if (digitalRead(Frontsidesensor) ==0) //If Fire is straight ahead
    {
    //Move the robot forward
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    fire = true;
    }
    else if (digitalRead(LeftSidesensor) ==0) //If Fire is to the left side
    {
    //Move the robot left
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
    }
    else if (digitalRead(RightSidesensor) ==0) //If Fire is to the right side
    {
    //Move the robot right
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    }
delay(400); //to reduce speed of robot
     while (fire == true)
     {
      put_off_fire();
     }
}
