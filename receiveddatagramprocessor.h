#ifndef RECEIVEDDATAGRAMPROCESSOR_H
#define RECEIVEDDATAGRAMPROCESSOR_H

#include <QHostAddress>
#include <stdint-gcc.h>
#include "udpdatagram.h"
#include <audiosamplesplayer.h>
#include <commandreceiver.h>

class CommandReceiver;


class ReceivedDatagramProcessor : public QObject
{
    Q_OBJECT

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

public slots:
    void processDatagram(UdpDatagram *datagram);
};

#endif // RECEIVEDDATAGRAMPROCESSOR_H
