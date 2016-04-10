#ifndef COMMANDSSENDER_H
#define COMMANDSSENDER_H

#include "udpmanager.h"

class CommandsSender
{
private:
    UdpManager* udpManager;
public:
    CommandsSender();
    void setUdpManager(UdpManager *udpManager);
};

#endif // COMMANDSSENDER_H
