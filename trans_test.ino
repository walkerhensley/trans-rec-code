#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;
int testSend = 512;
int testSendTwo = 10;
int testArray[] = {512,10};
void setup()
{
    Serial.begin(9600);    // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    const char *msg = "777";
    
    //int x = 12345;
    //driver.send((uint8_t *)&x, 2);
    driver.send((uint8_t *) &testSendTwo,(uint8_t)2);
    driver.send((uint8_t *)&testSend, (uint8_t)2); //sending testSend value over
    driver.send((uint8_t *)&testArray[0], (uint8_t)2);
    driver.send((uint8_t *)&testArray[1], (uint8_t)2);
    driver.waitPacketSent();
    delay(1000);
}
