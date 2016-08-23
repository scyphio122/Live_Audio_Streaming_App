#ifndef COMMANDRECEIVER_H
#define COMMANDRECEIVER_H

#include <datagramlistener.h>
#include <QObject>
#include <commandsender.h>
#include "udpmanager.h"

class UdpManager;
class CommandSender;


class CommandReceiver : public DatagramListener
{
    Q_OBJECT

private:
    CommandSender*  cmdSender;
    UdpManager*     udpManager;
public:
    CommandReceiver();
    CommandReceiver(QObject* parent);

    void onDataReceived(QByteArray* data);

    void setCommandSender(CommandSender* cmdSender);

    void setUdpManager(UdpManager* manager);

signals:
    void connectionUpdateSignal(bool status);
};

#endif // COMMANDRECEIVER_H
