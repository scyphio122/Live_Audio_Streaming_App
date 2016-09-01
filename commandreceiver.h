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

    QString         connRequesterIP;
    int             connRequesterPort;
public:
    CommandReceiver();
    CommandReceiver(QObject* parent);

    void onDataReceived(QByteArray* data, QHostAddress &senderIP);

    void setCommandSender(CommandSender* cmdSender);

    void setUdpManager(UdpManager* manager);

public slots:
    void connectionUpdateGUICallback(bool connectionEstablished);

signals:
    /// Signal used to display connection request window
    void connectionRequestSignal(QString hostIP);

    /// Signal used to establish connection in the UdpManager
    void connectionEstablishSignal(QString ip, int port);

    /// This signal is used to update connect button's text
    void connectionStatusUpdate(bool isConnected);

    void disconnectGUICallback();
};

#endif // COMMANDRECEIVER_H
