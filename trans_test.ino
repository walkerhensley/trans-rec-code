#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile
#include <Stepper.h>
#include <PWMServo.h>

RH_ASK driver;
int testSend = 512;
int testSendTwo = 10;
int yoarray[] = {512,12};

static const int STEPS_PER_REVOLUTION     = 32 * 64;
static const int PIN_IN1_BLUE             = 7;
static const int PIN_IN2_PINK             = 8;
static const int PIN_IN3_YELLOW           = 9;
static const int PIN_IN4_ORANGE           = 10;
static const int PIN_BUTTON               = 4;
//E brake button declaration
int buttonState = 0;
//joystick declaration
const int joystickSwitch = 5;
const int joystickX = A1;
const int joystickY = A2;

//stepper
Stepper myStepper(STEPS_PER_REVOLUTION, PIN_IN1_BLUE, PIN_IN3_YELLOW, PIN_IN2_PINK, PIN_IN4_ORANGE);
PWMServo myServo;


struct yo {
  int testSend;
  int testSendTwo;
  
};
uint8_t testArrayStore[sizeof(yo)];
void setup()
{
    Serial.begin(9600);    // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    yo asdf;
    asdf.testSend = 7;
    asdf.testSendTwo = 10;
    const char *msg = "777";
    memcpy(testArrayStore, &asdf, sizeof(asdf));
    //int x = 12345;
    //driver.send((uint8_t *)&x, 2);
//    driver.send((uint8_t *) &testSendTwo,(uint8_t)2);
//    driver.send((uint8_t *)&testSend, (uint8_t)2); //sending testSend value over
//    driver.waitPacketSent();
//    driver.send((uint8_t *)&testArray, (uint8_t)2);
//    driver.waitPacketSent();
    driver.send((uint8_t *)&testArrayStore, sizeof(asdf));
    driver.waitPacketSent();
    
}
