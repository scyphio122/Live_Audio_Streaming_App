#ifndef AUDIOSAMPLESSENDER_H
#define AUDIOSAMPLESSENDER_H

#include "udpmanager.h"

class AudioSamplesSender
{
private:
    UdpManager* udpManager;
public:
    AudioSamplesSender();
    void setUdpManager(UdpManager* udpManager);
};

#endif // AUDIOSAMPLESSENDER_H
