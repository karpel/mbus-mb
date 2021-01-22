#include "MBus.h"

#define mBusIn 0 //input port
#define mBusOut 1 //output port

MBus mBus(mBusIn, mBusOut); //make an object of MBus to work with 

void setup(){}

uint64_t  receivedMessage=0;
uint64_t  nextTime=0;

void loop()
{
  if(nextTime<millis())
  {
    mBus.sendChangedCD(1,1);
    mBus.sendCDStatus(1);
    mBus.sendPlayingTrack(1,0);
    nextTime=millis()+500;

  }
  if(mBus.receive(&receivedMessage))
  {
    if(receivedMessage == Ping)
    {
      mBus.send(PingOK);
    }
  }
}
