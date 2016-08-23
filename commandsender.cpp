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

void CommandSender::sendConnectionRequest(QString myIP, int myPort)
{
    QByteArray* array = new QByteArray(myIP.size() + sizeof(myPort) + sizeof(int), 0);
    std::string ip = myIP.toStdString();
    int size = sizeof(int) + myIP.length();
    memcpy(array->data(), &size, sizeof(size));
    memcpy(array->data() + 4, &myPort, sizeof(myPort));
    memcpy(array->data() + 4 + sizeof(int), ip.data(), ip.size());

    udpManager->setSendingPortNumber(myPort);
    udpManager->setReceiverIpAddress(ip);
    QBuffer buf(array);
    buf.setBuffer(array);
    UdpDatagram* datagram = new UdpDatagram(UdpDatagram::CONNECT_REQ, &buf);
    this->sendCommand(datagram);

    delete array;
    delete datagram;
}
