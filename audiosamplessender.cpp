#include "audiosamplessender.h"
#include <QBuffer>


AudioSamplesSender::AudioSamplesSender()
{

}

void AudioSamplesSender::setUdpManager(UdpManager *udpManager)
{
    this->udpManager = udpManager;
}

void AudioSamplesSender::sendSamples(QBuffer* sampleArray, qint64 bytesAvailable)
{

}
