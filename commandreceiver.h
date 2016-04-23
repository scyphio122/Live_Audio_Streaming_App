#ifndef COMMANDRECEIVER_H
#define COMMANDRECEIVER_H

#include <datagramlistener.h>
#include <QObject>

class CommandReceiver : public DatagramListener
{
    Q_OBJECT
public:
    CommandReceiver();
    CommandReceiver(QObject* parent);
    void onDataReceived(QByteArray* data);

};

#endif // COMMANDRECEIVER_H
