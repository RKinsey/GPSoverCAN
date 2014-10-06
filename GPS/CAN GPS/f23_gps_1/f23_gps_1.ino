
#include <SoftwareSerial.h> 

 SoftwareSerial GPS(10,11); // 10 is RX, 11 is TX
 void setup()
     {
     Serial.begin(4800);
     GPS.begin(4800);  //57600 works  115200 does not work
     }
void loop()
    {
    if(GPS.available()) Serial.write(GPS.read());
    if(Serial.available()) GPS.write(Serial.read());
    }    
