#include "audiosamplessender.h"

AudioSamplesSender::AudioSamplesSender()
{

}

void AudioSamplesSender::setUdpManager(UdpManager *udpManager)
{
    this->udpManager = udpManager;
}
