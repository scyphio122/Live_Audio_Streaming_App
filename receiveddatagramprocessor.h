#ifndef RECEIVEDDATAGRAMPROCESSOR_H
#define RECEIVEDDATAGRAMPROCESSOR_H

#include <QHostAddress>
#include <stdint-gcc.h>
#include "udpdatagram.h"
#include <audiosamplesplayer.h>
#include <commandreceiver.h>

class ReceivedDatagramProcessor
{
private:
    UdpDatagram* datagram;
    AudioSamplesPlayer* audioPlayer;
    CommandReceiver* cmdReceiver;

    std::string parseName(uint8_t* data);


public:
    ReceivedDatagramProcessor();
    ReceivedDatagramProcessor(AudioSamplesPlayer* player, CommandReceiver* cmdRec);

    void setAudioSamplesPlayer(AudioSamplesPlayer* player);
    void setCommandReceiver(CommandReceiver* cmdRec);
    void processDatagram(UdpDatagram *datagram, QHostAddress ip, uint16_t port);
};

#endif // RECEIVEDDATAGRAMPROCESSOR_H
