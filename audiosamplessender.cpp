#include "audiosamplessender.h"
#include <QBuffer>
#include "udpdatagram.h"
#include <audiosamplesgetter.h>

AudioSamplesSender::AudioSamplesSender()
{
}

AudioSamplesSender::AudioSamplesSender(AudioSamplesGetter* parent)
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
    UdpDatagram* datagram = new UdpDatagram(UdpDatagram::SAMPLES, sampleArray);
    sampleArray->seek(0);
    if(datagram->getDatagram() != nullptr)
    {
        /// Send the datagram to the thread with UdpManager
        emit emitSendSamplesSignal(datagram);
    }
    /// If QBuffer has grown too much then shrink it
    if(sampleArray->size() > AudioSamplesGetter::AUDIO_IN_BUFFER_SIZE)
        sampleArray->buffer().resize(AudioSamplesGetter::AUDIO_IN_BUFFER_SIZE);
}
