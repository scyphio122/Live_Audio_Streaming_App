#ifndef UDPMANAGER_H
#define UDPMANAGER_H

#include "receiveddatagramprocessor.h"
#include <boost/smart_ptr/scoped_ptr.hpp>
#include <QUdpSocket>
#include <QHostAddress>
#include <QObject>
#include <udpdatagram.h>

class UdpManager : public QObject
{
    Q_OBJECT

private:
    int                             portNumberInUse;
    boost::scoped_ptr<QHostAddress> receiverIpAddress;
    boost::scoped_ptr<QUdpSocket>   udpSocket;
    ReceivedDatagramProcessor*      datagramProc;
    bool                            isConnected = false;
public:
    UdpManager();
    UdpManager(QHostAddress* ip, int sendPort);

    void setDatagramProc(ReceivedDatagramProcessor* datagramProcessor);

public slots:
    void setReceiverIpAddress(std::string address);
    void setSendingPortNumber(int portNumber);
    void  sendData(UdpDatagram* datagram);
    void initSocket(QString ip, int port);
    void readData();
signals:
    void emitDataReceived(UdpDatagram* datagram);
};

#endif // UDPMANAGER_H
