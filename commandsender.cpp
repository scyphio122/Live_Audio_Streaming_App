#include "commandsender.h"

CommandSender::CommandSender()
{

}

CommandSender::~CommandSender()
{

}

void CommandSender::setUdpManager(UdpManager *udp)
{
    this->udpManager = udp;
}

void CommandSender::sendCommand(UdpDatagram *datagram)
{
    emit sendCommandSignal(datagram);
}

void CommandSender::sendConnectionRequest(QString myIP, int receiverPort)
{
    QByteArray* array = new QByteArray(myIP.size() + sizeof(receiverPort) + sizeof(int), 0);
    std::string ip = myIP.toStdString();

    memcpy(array->data(), &receiverPort, sizeof(receiverPort));
    memcpy(array->data() + sizeof(int), ip.data(), ip.size());

    udpManager->setSendingPortNumber(receiverPort);
    udpManager->setReceiverIpAddress(ip);
    QBuffer* buf = new QBuffer(array);
    buf->setBuffer(array);
    buf->open(QIODevice::ReadOnly);
    UdpDatagram* datagram = new UdpDatagram(UdpDatagram::CONNECT_REQ, buf);

    emit connectionEstablishSignal(myIP, receiverPort);

    /// Wait till connection is established
    while(!udpManager->getConnectionState()) {}

    emit sendCommandSignal(datagram);
//    delete array;
//    delete datagram;
}
