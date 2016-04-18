#include "udpmanager.h"
#include <QByteArray>
#include <QUdpSocket>
#include <QtGlobal>
#include <QObject>
#include <QString>
#include "udpdatagram.h"


UdpManager::UdpManager()
{

}

UdpManager::UdpManager(QHostAddress* ip, int sendPort)
{
    setReceiverIpAddress(ip->toString().toStdString());
    this->portNumberInUse = sendPort;
}

void UdpManager::setDatagramProc(ReceivedDatagramProcessor *datagramProcessor)
{
    this->datagramProc = datagramProcessor;
}

void UdpManager::setSendingPortNumber(int portNumber)
{
    this->portNumberInUse = portNumber;
}


void UdpManager::setReceiverIpAddress(std::string address)
{
    this->receiverIpAddress.reset(new QHostAddress(QString::fromStdString(address)));
}

bool UdpManager::initSocket(int port)
{
    this->udpSocket.reset(new QUdpSocket(this));
    udpSocket->bind(port);

    /// Connect the receiver callback to call readPendingDatagrams each time readyRead event occurs
    connect(this->udpSocket.get(), SIGNAL(readyRead()), this, SLOT(readData()));

    return true;
}

int UdpManager::sendData(UdpDatagram* datagram, const QHostAddress ip = QHostAddress("localhost"), const int port = 8002)
{
    /// Write data to the socket
    qint64 retval = udpSocket->writeDatagram(*datagram->getDatagram(), ip, port);
    qint64 dataSize = datagram->getDatagram()->size();
    if(retval == (-1) || retval != dataSize)
    {
        return -1;
    }

    return 0;
}

void UdpManager::readData()
{
    UdpDatagram     datagram;
    QHostAddress    senderIpAddress;
    uint16_t        port;


    while(udpSocket->hasPendingDatagrams() != -1)
    {
        qint64 datagramSize = udpSocket->pendingDatagramSize();
        datagram.resize(datagramSize);

        udpSocket->readDatagram(datagram.getDatagram()->data(), datagramSize, &senderIpAddress, &port);
        this->datagramProc->processDatagram(&datagram, senderIpAddress, port);
    }
}


