#ifndef DATAGRAMLISTENER_H
#define DATAGRAMLISTENER_H

#include <QByteArray>
#include <QObject>

class DatagramListener: public QObject
{
public:
    DatagramListener();

    virtual void onDataReceived(QByteArray* data) = 0;
};

#endif // DATAGRAMLISTENER_H
