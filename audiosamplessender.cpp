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
    sampleArray->seek(0);
    /// Create the datagram
    UdpDatagram datagram(UdpDatagram::SAMPLES, sampleArray);
    sampleArray->seek(0);
    if(datagram.getDatagram() != nullptr)
    {
        /// Send the datagram
        this->udpManager->sendData(&datagram, this->ip, this->receiverPort);
    }
}
