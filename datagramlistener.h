#ifndef DATAGRAMLISTENER_H
#define DATAGRAMLISTENER_H

#include <QByteArray>
#include <QObject>
#include <QHostAddress>

/**
 * @brief The DatagramListener class - This is an interface for receiving datagrams
 */
class DatagramListener: public QObject
{
public:
    DatagramListener();

    /**
     * @brief onDataReceived - Overwrite of this method should be called when the datagram is received. It is introduced to make difference between command datagrams and samples datagrams
     * @param data[in] - received datagram
     * @param senderIP[in] - the IP of the transmitter device
     */
    virtual void onDataReceived(QByteArray* data, QHostAddress& senderIP) = 0;
};

#endif // DATAGRAMLISTENER_H
