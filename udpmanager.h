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
private:
    int                             portNumberInUse;
    boost::scoped_ptr<QHostAddress> receiverIpAddress;
    boost::scoped_ptr<QUdpSocket>   udpSocket;
    ReceivedDatagramProcessor*      datagramProc;
public:
    UdpManager();
    UdpManager(QHostAddress* ip, int sendPort);

    void setDatagramProc(ReceivedDatagramProcessor* datagramProcessor);
    void setReceiverIpAddress(std::string address);
    void setSendingPortNumber(int portNumber);


    bool initSocket(int port);
    int  sendData(UdpDatagram* datagram, const QHostAddress ip, const int port);
    void readData();
};

#endif // UDPMANAGER_H
