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
    this->udpManager->sendData(datagram);
}

void CommandSender::sendConnectionRequest(QString myIP, int receiverPort)
{
    QByteArray* array = new QByteArray(myIP.size() + sizeof(receiverPort) + sizeof(int), 0);
    std::string ip = myIP.toStdString();
    int size = sizeof(int) + myIP.length();
    memcpy(array->data(), &size, sizeof(size));
    memcpy(array->data() + 4, &receiverPort, sizeof(receiverPort));
    memcpy(array->data() + 4 + sizeof(int), ip.data(), ip.size());

    udpManager->setSendingPortNumber(receiverPort);
    udpManager->setReceiverIpAddress(ip);
    QBuffer* buf = new QBuffer(array);
    buf->setBuffer(array);
    buf->open(QIODevice::ReadOnly);
    UdpDatagram* datagram = new UdpDatagram(UdpDatagram::CONNECT_REQ, buf);

    udpManager->connectUDP(myIP, receiverPort);
//    this->sendCommand(datagram);
    emit sendCommandSignal(datagram);
//    delete array;
//    delete datagram;
}
