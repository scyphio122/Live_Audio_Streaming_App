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
public:
    UdpManager();
    UdpManager(QHostAddress* ip, int sendPort);

    void setDatagramProc(ReceivedDatagramProcessor* datagramProcessor);
    bool initSocket(std::string ip, int port);
    void readData();
public slots:
    void setReceiverIpAddress(std::string address);
    void setSendingPortNumber(int portNumber);
    int  sendData(UdpDatagram* datagram, const QHostAddress ip, const int port);

signals:
    void emitDataReceived(UdpDatagram* datagram);
};

#endif // UDPMANAGER_H
