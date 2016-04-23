#include "audiosamplessender.h"
#include <QBuffer>
#include "udpdatagram.h"
#include <audiosamplesgetter.h>

AudioSamplesSender::AudioSamplesSender()
{
}

AudioSamplesSender::AudioSamplesSender(AudioSamplesGetter* parent = 0)
{
    this->setParent(parent);
}

void AudioSamplesSender::setUdpManager(UdpManager *udpManager)
{
    this->udpManager = udpManager;
}

void AudioSamplesSender::sendSamples(QBuffer* sampleArray)
{
    /// Create the datagram
    UdpDatagram datagram(UdpDatagram::SAMPLES, sampleArray);
    sampleArray->seek(0);
    if(datagram.getDatagram() != nullptr)
    {
        /// Send the datagram
        emit sendData(&datagram, this->ip, this->receiverPort);
    }
}
