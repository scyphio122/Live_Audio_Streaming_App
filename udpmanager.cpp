#include "udpmanager.h"
#include <QByteArray>
#include <QUdpSocket>
#include <QtGlobal>
#include <QObject>
#include <QString>
#include "udpdatagram.h"
#include <QDebug>
#include <QAbstractSocket>

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

void UdpManager::initSocket(QString ip, int port)
{
    isConnected = true;
    this->setReceiverIpAddress(ip.toStdString());
    this->portNumberInUse = port;

    this->udpSocket.reset(new QUdpSocket(this));
    udpSocket->bind(port);

    /// Connect the receiver callback to call readPendingDatagrams each time readyRead event occurs
    connect(this->udpSocket.get(), SIGNAL(readyRead()), this, SLOT(readData()));

}

void UdpManager::sendData(UdpDatagram* datagram)
{
    qint64 retval = 0;
    if(isConnected)
    {
        QHostAddress ip("localhost");//*this->receiverIpAddress.get()
        /// Write data to the socket
        retval = udpSocket->writeDatagram(*datagram->getDatagram(), ip, this->portNumberInUse);
        qDebug()<<"Ilość wysłanych danych:"<<retval;
        if(retval == -1)
        {
            QAbstractSocket::SocketError err =udpSocket->error();
            qDebug()<<"Błąd wysyłki:"<<err;
        }
    }
}

void UdpManager::readData()
{
    QHostAddress    senderIpAddress;
    uint16_t        port;

    while(udpSocket->hasPendingDatagrams() && isConnected)
    {
        qint64 datagramSize = udpSocket->pendingDatagramSize();
        UdpDatagram*     datagram = new UdpDatagram();
        datagram->resize(datagramSize);
        udpSocket->readDatagram(datagram->getDatagram()->data(), datagramSize, &senderIpAddress, &port);

        /// Emit event that the datragram has been received
        emit emitDataReceived(datagram);
//        this->datagramProc->processDatagram(&datagram, senderIpAddress, port);
    }
}


