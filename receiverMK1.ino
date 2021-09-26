#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile
#include <Stepper.h>
#include <Servo.h>
#include "AccelStepper.h"
#define MotorInterfaceType 8
RH_ASK driver;

int val =0;
int valTwo = 0;
uint8_t valArray[2];
uint8_t nBytesReceived = 2;
int servoValue;
int stepperValue;
int turn;
int lastStepper;

static const int STEPS_PER_REVOLUTION     = 32 * 64;
static const int PIN_IN1_BLUE             = 7;
static const int PIN_IN2_PINK             = 8;
static const int PIN_IN3_YELLOW           = 9;
static const int PIN_IN4_ORANGE           = 10;


Stepper myStepper(STEPS_PER_REVOLUTION, PIN_IN1_BLUE, PIN_IN3_YELLOW, PIN_IN2_PINK, PIN_IN4_ORANGE);
Servo myServo;
//creating accel stepper
AccelStepper stepperX(1, 2, 3);

struct yo {
  int testSend;
  int testSendTwo;
 
};

AccelStepper stepper = AccelStepper(MotorInterfaceType, PIN_IN1_BLUE, PIN_IN3_YELLOW, PIN_IN2_PINK, PIN_IN4_ORANGE);

int motorPin = 4;
int servoPin = 3;
void setup()
{
    Serial.begin(9600);  // Debugging only
    if (!driver.init()) {
         Serial.println("init failed");
    }
         stepper.setMaxSpeed(2000);
         pinMode(motorPin, OUTPUT);
         myServo.attach(3);
}

void loop()
{

//digitalWrite(motorPin, HIGH);

 //stepper.setCurrentPosition(0);
 /*  while (stepper.currentPosition() != 4096) {
    stepper.setSpeed(1000);
    stepper.runSpeed();
  }
 // delay(1000);
    stepper.setCurrentPosition(0);
      while (stepper.currentPosition() != -4096) {
    stepper.setSpeed(-1000);
    stepper.runSpeed();*/
 
    uint8_t buf[sizeof(yo)];

    uint8_t buflen = sizeof(yo);
  
    if  (driver.recv(buf, &buflen)) // Non-blocking //storing value of sent value in val
    {
      
      int i;
      // Message with a good checksum received, dump it.
      stepper.setSpeed(500);
stepper.runSpeed();
      yo test;

      memcpy(&test, &buf, sizeof(buf));
      Serial.print("Message: ");
      Serial.println(test.testSend);   
      stepperValue = test.testSend;
      //delay(500);
     Serial.println(test.testSendTwo); 
               
    servoValue = test.testSendTwo;
 
      servoValue = map(servoValue,0,1023,45,135);
      Serial.println("Writing servo:");
      Serial.println(servoValue);
      myServo.write(servoValue);

    if (stepperValue > 550)
    {
      digitalWrite(motorPin, HIGH);

      //servo motor code
     servoValue = map(servoValue,0,1023,45,135);
      Serial.println("Writing servo:");
      Serial.println(servoValue);
      myServo.write(servoValue);
      }
      
      if (stepperValue < 200)
      {
        digitalWrite(motorPin, LOW);
         //servo motor code
     servoValue = map(servoValue,0,1023,45,135);
      Serial.println("Writing servo:");
      Serial.println(servoValue);
      myServo.write(servoValue);
      }

    /*
int lastTest = stepperValue;

stepper.setSpeed((float)stepperValue);
stepper.runSpeed();

stepper.runSpeed();*/
//stepper.setCurrentPosition(0);


//Serial.println(lastTest);
//myStepper.setSpeed(7);
//myStepper.step(stepperValue);
//myStepper.setSpeed(stepperValue);
//adding values to motor
/*
if (stepperValue > 0)
{
myStepper.setSpeed(stepperValue);
//myStepper.setSpeed((int)(abs(stepperValue -512) / 30));
myStepper.step(10); 
//turning code

}

if (stepperValue < 470)
{
  myStepper.setSpeed((int)(abs(stepperValue-512)/30));
    myStepper.step(-10);
//turning code


  turn = servoValue;
turn = map(turn,0,1023,0,180);
myServo.write(turn);

  }
*/
//lastStepper = stepperValue;
      }
    }
//    delay(500);
//    if (driver.recv(buf[1], &buflen))
//    {
//      Serial.print("Message Two: ");
//      Serial.println(buf[1]);
//      }
 //myStepper.setSpeed(lastStepper);
   //myStepper.step(10);
//}
