
// Recommend only use IRLibRecvPCI or IRLibRecvLoop for best results
#include <IRLibRecvPCI.h> 

IRrecvPCI myReceiver(2);//pin number for the receiver


void setup() {
  Serial.begin(115200);
  delay(2000); while (!Serial); //delay for Leonardo
  myReceiver.enableIRIn(); // Start the receiver
}

void loop() {
  
  //Continue looping until you get a complete signal received
  if (myReceiver.getResults()) { 
    for(bufIndex_t i=1;i<recvGlobal.recvLength;i++) {
      Serial.println(recvGlobal.recvBuffer[i]);
      //Serial.print(", ");
      //if( (i % 8)==0) Serial.print(F("\n\t"));
    }
    myReceiver.enableIRIn();      //Restart receiver
  }
}
