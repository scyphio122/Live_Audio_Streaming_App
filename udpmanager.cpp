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
    if(udpSocket != nullptr)
    {
        delete udpSocket;
        udpSocket = nullptr;
    }

    this->udpSocket = new QUdpSocket(this);
    this->udpSocket->bind(8002);
    /// Connect the receiver callback to call readPendingDatagrams each time readyRead event occurs
    connect(this->udpSocket, SIGNAL(readyRead()), this, SLOT(readData()));
}

UdpManager::UdpManager(QHostAddress* ip, int sendPort)
{
    setReceiverIpAddress(ip->toString().toStdString());
    this->portNumberInUse = sendPort;

    if(udpSocket != nullptr)
    {
        delete udpSocket;
        udpSocket = nullptr;
    }

    this->udpSocket = new QUdpSocket(this);
    /// Connect the receiver callback to call readPendingDatagrams each time readyRead event occurs
    connect(this->udpSocket, SIGNAL(readyRead()), this, SLOT(readData()));
}

UdpManager::~UdpManager()
{
    udpSocket->close();

    if(udpSocket != nullptr)
        delete udpSocket;

    if(receiverIpAddress != nullptr)
        delete receiverIpAddress;
}

void UdpManager::setDatagramProc(ReceivedDatagramProcessor *datagramProcessor)
{
    this->datagramProc = datagramProcessor;
}

void UdpManager::setSendingPortNumber(int portNumber)
{
    mutex.lock();
    this->portNumberInUse = portNumber;
    mutex.unlock();
}

void UdpManager::setReceiverIpAddress(std::string address)
{
    mutex.lock();
    m_setReceiverIpAddress(address);
    mutex.unlock();
}

void UdpManager::m_setReceiverIpAddress(std::string address)
{
    if(receiverIpAddress != nullptr)
    {
        delete receiverIpAddress;
        receiverIpAddress = nullptr;
    }

    this->receiverIpAddress = new QHostAddress(QString::fromStdString(address));
}

void UdpManager::connectUDP(QString ip, int port)
{
    mutex.lock();
    this->m_setReceiverIpAddress(ip.toStdString());
    this->portNumberInUse = port;

    udpSocket->bind(*receiverIpAddress, port);

    isConnected = true;
    mutex.unlock();
}

void UdpManager::sendData(UdpDatagram* datagram)
{
    qint64 retval = 0;

    mutex.lock();
    /// Write data to the socket
    retval = udpSocket->writeDatagram(datagram->getDatagram(), *receiverIpAddress, this->portNumberInUse);
//    qDebug()<<"Ilość wysłanych danych:"<<retval;
    if(retval == -1)
    {
        QAbstractSocket::SocketError err =udpSocket->error();
        qDebug()<<"Błąd wysyłki:"<<err;
    }
    delete datagram;
    mutex.unlock();
}

void UdpManager::sendCmd(UdpDatagram* datagram)
{
    sendData(datagram);
}
void UdpManager::readData()
{
    QHostAddress    senderIpAddress;
    uint16_t        port;

    while(udpSocket->hasPendingDatagrams())
    {
        mutex.lock();

        qint64 datagramSize = udpSocket->pendingDatagramSize();
        UdpDatagram*     datagram = new UdpDatagram();
        datagram->resize(datagramSize);
        udpSocket->readDatagram(datagram->getDatagram().data(), datagramSize, &senderIpAddress, &port);

        mutex.unlock();
        /// Emit event that the datragram has been received
        emit emitDataReceived(datagram, senderIpAddress.toString());
    }
}

void UdpManager::setConnectionState(bool state)
{
    mutex.lock();
    isConnected = state;
    emit onConnectionStateChangedSignal(state);
    mutex.unlock();
}

bool UdpManager::getConnectionState()
{
    return isConnected;
}
