#ifndef COMMANDRECEIVER_H
#define COMMANDRECEIVER_H

#include <datagramlistener.h>


class CommandReceiver : public DatagramListener
{

public:
    CommandReceiver();
    void onDataReceived(QByteArray& data);

};

#endif // COMMANDRECEIVER_H
