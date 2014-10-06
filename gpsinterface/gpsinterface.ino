// demo: CAN-BUS Shield, send data.
//GPS shows up on serial port, not SkyTraq
/*for NMEA0183, must upload GPS alone (f23_gps_1_) first, open SkyTraq
then switch to "NMEA0183". Then upload this program.
*/
#include <mcp_can.h>
#include <SPI.h>
#include <SoftwareSerial.h> 

SoftwareSerial GPS(9,11);
MCP_CAN CAN(10);                                      // Set CS to pin 10
// i;

void setup()
{
    Serial.begin(57600); //115200 does not work
    GPS.begin(57600);
   // i=0;
   
START_INIT:

   if(CAN_OK == CAN.begin(CAN_500KBPS))                   // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS Shield init ok!");
    }
    else
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println("Init CAN BUS Shield again");
        delay(1000);
        goto START_INIT;
    }
    /*
        char a[66];
    //CAN.sendMsgBuf(0x00, 0, 8, stmp);
    if(GPS.available()) GPS.readBytes(a,66);
    if(Serial.available()) GPS.write(Serial.read());
    // send data per 100ms or 10Hz
    for(int i=0; i<66;i++){
    Serial.print(a[i]);
    }*/
  //  delay(20);
}

//unsigned char stmp[8] = {0, 1, 2, 3, 4, 5, 6, 7};
void loop()
{
  //if(GPS.available()) Serial.write(GPS.read());
  
 // delay(100); //20 ms delay
    // send data:  id = 0x00, standrad flame, data len = 8, stmp: data buf. This is a comment, not code.
    //CAN.readMsgBuf(&8, stmp);
    char data[66];
//     CAN.sendMsgBuf(0x00, 0, 8, stmp);
    if(GPS.available()) GPS.readBytes(data,66);
    if(Serial.available()) GPS.write(Serial.read());
    /*
    for(int i=0; i<66; i++) {
      Serial.print(data[i]);
    }
    Serial.println();*/
    char pos[8]; //change back to char?
    for(int i=10; i<=18; i++){
      pos[i-10]=data[i];
    }
   /* for(int i=0; i<4;i++){
      Serial.print(longi[i]);
    }
    Serial.println();*/
    for(int i=0; i<8; i++){
      Serial.print(pos[i]);
      byte b = pos[i];
      CAN.sendMsgBuf(0x00, 0, 8, &b);
    }
    Serial.println();
}

