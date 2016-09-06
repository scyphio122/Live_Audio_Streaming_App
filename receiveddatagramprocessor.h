#ifndef RECEIVEDDATAGRAMPROCESSOR_H
#define RECEIVEDDATAGRAMPROCESSOR_H

#include <QHostAddress>
#include <stdint-gcc.h>
#include "udpdatagram.h"
#include <audiosamplesplayer.h>
#include <commandreceiver.h>

class CommandReceiver;

/**
 * @brief The ReceivedDatagramProcessor class - This class is used to determine whiether the received datagram is samples datagram or command datagram. It dispatches then the datagram to the proper object
 */
class ReceivedDatagramProcessor : public QObject
{
    Q_OBJECT

private:
    UdpDatagram* datagram;
    AudioSamplesPlayer* audioPlayer;
    CommandReceiver* cmdReceiver;



public:
    ReceivedDatagramProcessor();
    /**
     * @brief ReceivedDatagramProcessor
     * @param player[in]
     * @param cmdRec[in]
     */
    ReceivedDatagramProcessor(AudioSamplesPlayer* player, CommandReceiver* cmdRec);

    /**
     * @brief setAudioSamplesPlayer - setter for the audio samples player
     * @param player
     */
    void setAudioSamplesPlayer(AudioSamplesPlayer* player);

    /**
     * @brief setCommandReceiver - setter for the command receiver
     * @param cmdRec
     */
    void setCommandReceiver(CommandReceiver* cmdRec);

public slots:
    /**
     * @brief processDatagram - This function is called in order to process the received datagram and determine where it should be processed
     * @param datagram[in] - received datagram
     * @param senderIP[in] - IP of the sender
     */
    void processDatagram(UdpDatagram *datagram, QString senderIP);
};

#endif // RECEIVEDDATAGRAMPROCESSOR_H
