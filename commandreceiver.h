#ifndef COMMANDRECEIVER_H
#define COMMANDRECEIVER_H

#include <datagramlistener.h>
#include "udpmanager.h"

class CommandReceiver : public DatagramListener
{
private:
    UdpManager* udpManager;
public:
    CommandReceiver();

    void setUdpManager(UdpManager *udpManager);
};

#endif // COMMANDRECEIVER_H
