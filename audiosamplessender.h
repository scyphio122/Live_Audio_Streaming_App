#ifndef AUDIOSAMPLESSENDER_H
#define AUDIOSAMPLESSENDER_H

#include "udpmanager.h"
#include <QBuffer>
#include "audiosamplesgetter.h"



class AudioSamplesGetter;

/**
 * @brief The AudioSamplesSender class - This class is used to send gathered samples to the udpManager. It forms the datagram from samples
 */
class AudioSamplesSender : public QObject
{
    Q_OBJECT
private:
    const QHostAddress  ip       = QHostAddress::LocalHost;
    QString             ipText;
    const int           receiverPort      = 8002;
    UdpManager*         udpManager;


public:
    AudioSamplesSender();
    AudioSamplesSender(AudioSamplesGetter* parent = 0);

    /**
     * @brief setUdpManager - setter for the UdpManager
     * @param udpManager - pointer to set
     */
    void setUdpManager(UdpManager* udpManager);

    /**
     * @brief sendSamples - This creates datagram from the given sampleArray and passes it to udpManager
     * @param sampleArray[in] - array containing gathered audio samples
     */
    void sendSamples(QBuffer *sampleArray);


signals:
    void emitSendSamplesSignal(UdpDatagram* datagram);  /*< This signal sends the datagram to be sent to the udpManager */

};

#endif // AUDIOSAMPLESSENDER_H
