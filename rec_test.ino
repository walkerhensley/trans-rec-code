#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile
#include <Stepper.h>
#include <PWMServo.h>


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
static const int PIN_BUTTON               = 4;

Stepper myStepper(STEPS_PER_REVOLUTION, PIN_IN1_BLUE, PIN_IN3_YELLOW, PIN_IN2_PINK, PIN_IN4_ORANGE);
PWMServo myServo;


struct yo {
  int testSend;
  int testSendTwo;
 
};
void setup()
{
    Serial.begin(9600);  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
 
    uint8_t buf[sizeof(yo)];

    uint8_t buflen = sizeof(yo);
  
    if  (driver.recv(buf, &buflen)) // Non-blocking //storing value of sent value in val
    {
      int i;
      // Message with a good checksum received, dump it.

      yo test;

      memcpy(&test, &buf, sizeof(buf));
      Serial.print("Message: ");
      Serial.println(test.testSend);   
      stepperValue = test.testSend;
      delay(500);
     Serial.println(test.testSendTwo);           
    servoValue = test.testSendTwo;
//int lastTest = stepperValue;
myStepper.step(10);
myStepper.setSpeed(stepperValue);
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
//    delay(500);
//    if (driver.recv(buf[1], &buflen))
//    {
//      Serial.print("Message Two: ");
//      Serial.println(buf[1]);
//      }
 //myStepper.setSpeed(lastStepper);
   //myStepper.step(10);
}

