#include "udpmanager.h"

UdpManager::UdpManager()
{

}

void UdpManager::setDatagramProc(ReceivedDatagramProcessor *datagramProcessor)
{
    this->datagramProc = datagramProcessor;
}
