#ifndef COMMANDSSENDER_H
#define COMMANDSSENDER_H

#include <udpmanager.h>
#include <QObject>
class UdpManager;

class CommandSender : public QObject
{
    Q_OBJECT
private:
    UdpManager* udpManager;

public:
    CommandSender();
    ~CommandSender();
    void setUdpManager(UdpManager* udp);
    void sendCommand(UdpDatagram* datagram);

public slots:
    void sendConnectionRequest(QString myIP, int myPort);
};

#endif // COMMANDSSENDER_H
