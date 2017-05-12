#include "rc522.h"
#include "protocol.h"
#include <SoftwareSerial.h>

SoftwareSerial RCNodeCom(6,7);
RFID rfid;
void setup()
{
//    Serial.begin(9600);
    RCNodeCom.begin(19200);
//    RCNodeCom.listen();
}
 
void loop()
{
 
    uchar status;
    uchar str[MAX_LEN];
 
    // Search card, return card types
    status = rfid.MFRC522_Request(PICC_REQIDL, str);
    if (status != MI_OK)
    {
        return;
    }
 
    // Show card type
//    rfid.ShowCardType(str);
 
    //Prevent conflict, return the 4 bytes Serial number of the card
    status = rfid.MFRC522_Anticoll(str);
 
    // str[0..3]: serial number of the card
    // str[4]: XOR checksum of the SN.
    if (status == MI_OK)
    {
//        Serial.print("The card's number is: ");
        memcpy(rfid.serNum, str, 5);
//        rfid.ShowCardID(rfid.serNum);
 
        // Check people associated with card ID
        uchar* id = rfid.serNum;
        int IDlen=5;
        Frame frame(BOOKTAG,id);
//        Serial.write((uchar *)&frame,sizeof(Frame));
        RCNodeCom.write((uchar *)&frame,sizeof(Frame));
        
//    for(int i=0; i<IDlen; i++){
//       Serial.print(0x0F & (id[i]>>4), HEX);
//        Serial.print(id[i],HEX);
//    }
//        Serial.print(id[0]);
//        Serial.print(id[1]);
//        Serial.print(id[2]);
//        Serial.print(id[3]);
//        Serial.print(id[4]);
//        Serial.print('\n');
    }
 
    rfid.MFRC522_Halt(); //command the card into sleep mode
 
    delay(200);
}
 
