#include "udpmanager.h"
#include <QByteArray>
#include <QUdpSocket>
#include <QtGlobal>
#include <QObject>
#include <QString>

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

int UdpManager::sendData(uint8_t* data, uint64_t data_size, const QHostAddress ip = QHostAddress("localhost"), const int port = 8002)
{
    QByteArray datagram = QByteArray((const char*)data, (int)data_size);
    qint64 retval = udpSocket->writeDatagram(datagram, ip, port);

    if(retval == (-1) || retval != (qint64)data_size)
    {
        return -1;
    }

    return 0;
}

void UdpManager::readData()
{
    QByteArray      datagram;
    QHostAddress    senderIpAddress;
    uint16_t        port;


    while(udpSocket->hasPendingDatagrams())
    {
        datagram.resize(udpSocket->pendingDatagramSize());

        udpSocket->readDatagram(datagram.data(), datagram.size(), &senderIpAddress, &port);
        this->datagramProc->processDatagram((uint8_t*)datagram.data(), datagram.size(), senderIpAddress, port);
    }
}


