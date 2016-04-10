#include "commandreceiver.h"
#include "udpmanager.h"


CommandReceiver::CommandReceiver()
{

}

void CommandReceiver::setUdpManager(UdpManager *udpManager)
{
    this->udpManager = udpManager;
}
