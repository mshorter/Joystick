//Writen by Michelle Shorter 4/10/15 under beef licence (like beer licence, but I prefer a steak)

#include <RedBot.h>


RedBotMotors motors;
int motorPower=255;
int pause = 10;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available()>0)
  {
    char data = Serial.read();
    Serial.println(data);
    if (data == 'W')  forward(motorPower);
    else if (data == 'D')  right(motorPower/2);
    else if (data == 'S')  backward(motorPower);
    else if (data == 'A')  left(motorPower/2);
    else if (data == 'Z')  motors.brake();
    //else motors.brake();
    
  }//while
  //motors.brake(); //at this point we are not getting data, so stop moving

}//loop

int forward(int myspeed)
{
  Serial.println("Forward");
  motors.drive(200);
  motors.rightMotor(myspeed);
  motors.leftMotor(-myspeed);
  delay(pause);
}//forwared

int backward(int myspeed)
{
  motors.rightMotor(-myspeed);
  motors.leftMotor(myspeed);
  delay(pause);
}//backward

int right(int myspeed)
{
  motors.rightMotor(-myspeed);
  motors.leftMotor(-myspeed);
  delay(pause);
}//forwared

int left(int myspeed)
{
  motors.rightMotor(myspeed);
  motors.leftMotor(myspeed);
  delay(pause);
}//forwared

