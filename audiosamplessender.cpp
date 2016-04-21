#include "audiosamplessender.h"
#include <QBuffer>
#include "udpdatagram.h"

AudioSamplesSender::AudioSamplesSender()
{

}

void AudioSamplesSender::setUdpManager(UdpManager *udpManager)
{
    this->udpManager = udpManager;
}

void AudioSamplesSender::sendSamples(QBuffer* sampleArray)
{
    int bytesAvailable = sampleArray->bytesAvailable();
    /// Create the datagram
    UdpDatagram datagram(UdpDatagram::SAMPLES, sampleArray);
    /// SAend the datagram
    this->udpManager->sendData(&datagram, this->ip, this->receiverPort);
}
