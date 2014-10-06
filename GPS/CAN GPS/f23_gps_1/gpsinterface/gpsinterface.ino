// demo: CAN-BUS Shield, send data
#include <mcp_can.h>
#include <SPI.h>
#include <SoftwareSerial.h>

SoftwareSerial GPS(10,11);
MCP_CAN CAN(10);                                      // Set CS to pin 10

void setup()
{
    Serial.begin(4800);
    GPS.begin(4800);

}
//unsigned char stmp[8] = {0, 1, 2, 3, 4, 5, 6, 7};
void loop()
{
    // send data:  id = 0x00, standrad flame, data len = 8, stmp: data buf
    if(GPS.available()) Serial.write(GPS.read());
    if(Serial.available()) GPS.write(Serial.read());
    //CAN.sendMsgBuf(0x00, 0, 8, stmp);
   // delay(100);                       // send data per 100ms
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
