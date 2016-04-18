#ifndef AUDIOSAMPLESSENDER_H
#define AUDIOSAMPLESSENDER_H

#include "udpmanager.h"
#include <QBuffer>


class AudioSamplesSender
{
private:
    const QHostAddress ip   = QHostAddress::LocalHost;
    const int receiverPort  = 8002;
    UdpManager* udpManager;

public:
    AudioSamplesSender();
    void setUdpManager(UdpManager* udpManager);
    void sendSamples(QBuffer *sampleArray);
};

#endif // AUDIOSAMPLESSENDER_H
