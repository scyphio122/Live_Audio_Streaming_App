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
    void sendConnectionRequest(QString myIP, int receiverPort);
    void sendDisconnectCommand();
signals:
    void sendCommandSignal(UdpDatagram *datagram);

    /// Signal used to establish connection in the UdpManager
    void connectionEstablishSignal(QString ip, int port);
};

#endif // COMMANDSSENDER_H
