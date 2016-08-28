#ifndef UDPMANAGER_H
#define UDPMANAGER_H

#include "receiveddatagramprocessor.h"
#include <boost/smart_ptr/scoped_ptr.hpp>
#include <QUdpSocket>
#include <QHostAddress>
#include <QObject>
#include <udpdatagram.h>

class ReceivedDatagramProcessor;


class UdpManager : public QObject
{
    Q_OBJECT

private:
    int                             portNumberInUse;
    QHostAddress*                   receiverIpAddress = nullptr;
    QUdpSocket*                     udpSocket = nullptr;
    ReceivedDatagramProcessor*      datagramProc = nullptr;
    bool                            isConnected = false;
    QMutex                          mutex;

    void m_setReceiverIpAddress(std::string address);
public:
    UdpManager();
    UdpManager(QHostAddress* ip, int sendPort);
    ~UdpManager();

    void setDatagramProc(ReceivedDatagramProcessor* datagramProcessor);
    void setConnectionState(bool state);
    bool getConnectionState();

public slots:
    void setReceiverIpAddress(std::string address);
    void setSendingPortNumber(int portNumber);

    void connectUDP(QString ip, int port);
    void sendData(UdpDatagram* datagram);
    void sendCmd(UdpDatagram* datagram);
    void readData();
signals:
    void emitDataReceived(UdpDatagram* datagram);

    void connectedSignal();
};

#endif // UDPMANAGER_H
