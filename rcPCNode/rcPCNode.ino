#include "rc522.h"
#include "protocol.h"
#include <SoftwareSerial.h>
RFID rfid;

SoftwareSerial BTNodeCom(8,7);
SoftwareSerial RPNodeCom(4,6);
void setup()
{
    Serial.begin(9600);
    
    BTNodeCom.begin(19200);
    RPNodeCom.begin(9600);
   
//    RPNodeCom.listen();
}
 
void loop()
{
  BTNodeCom.listen();
    uchar status;
    uchar str[MAX_LEN];
  if(BTNodeCom.available()>0){
      uchar buff[8];
      BTNodeCom.readBytes(buff,8);
      RPNodeCom.write(buff,8);
      for(int i = 0;i<8;i++){
          Serial.print(buff[i],HEX);
        }
        Serial.println("");
    }
status = rfid.MFRC522_Request(PICC_REQIDL, str);
    status = rfid.MFRC522_Anticoll(str);
 
    // str[0..3]: serial number of the card
    // str[4]: XOR checksum of the SN.

    
    if (status == MI_OK)
    {
      memcpy(rfid.serNum, str, 5);
        uchar* id = rfid.serNum;
        Frame frame(READCARD,id);
        uchar buff[8];
        frame.getBuff(buff);
        for(int i = 0;i<8;i++){
          Serial.print(buff[i],HEX);
        }
        Serial.println("");
        RPNodeCom.write(buff,8);

    }
    rfid.MFRC522_Halt(); //command the card into sleep mode
    delay(200);
}
 
