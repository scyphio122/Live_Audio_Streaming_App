#ifndef AUDIOSAMPLESSENDER_H
#define AUDIOSAMPLESSENDER_H

#include "udpmanager.h"
#include <QBuffer>


class AudioSamplesSender
{
private:
    UdpManager* udpManager;
public:
    AudioSamplesSender();
    void setUdpManager(UdpManager* udpManager);
    void sendSamples(QBuffer *sampleArray, qint64 bytesAvailable);
};

#endif // AUDIOSAMPLESSENDER_H
