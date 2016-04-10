#ifndef DATAGRAMLISTENER_H
#define DATAGRAMLISTENER_H

#include <QByteArray>

class DatagramListener
{
public:
    DatagramListener();

    virtual void onDataReceived(QByteArray& data) = 0;
};

#endif // DATAGRAMLISTENER_H
