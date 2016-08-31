#ifndef DATAGRAMLISTENER_H
#define DATAGRAMLISTENER_H

#include <QByteArray>
#include <QObject>
#include <QHostAddress>

class DatagramListener: public QObject
{
public:
    DatagramListener();

    virtual void onDataReceived(QByteArray* data, QHostAddress& senderIP) = 0;
};

#endif // DATAGRAMLISTENER_H
