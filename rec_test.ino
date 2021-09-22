#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;

int val =0; 
int valTwo = 0;
uint8_t valArray[2];
uint8_t nBytesReceived = 2;
void setup()
{
    Serial.begin(9600);  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    uint8_t buf[2];

    uint8_t buflen = sizeof(buf);
    if  (driver.recv((uint8_t *) (&valArray[0]), 2)) // Non-blocking //storing value of sent value in val
    {
      int i;
      // Message with a good checksum received, dump it.
      Serial.print("Message: ");
      Serial.println(valArray[0]);         
    }
    delay(500);
    if (driver.recv((uint8_t *) (&valArray[1]), 2))
    {
      Serial.print("Message Two: ");
      Serial.println(valArray[1]);
      }
}

