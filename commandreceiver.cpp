#include "commandreceiver.h"
#include "udpmanager.h"
#include <QObject>
#include <QDialog>
#include <connectdialog.h>


CommandReceiver::CommandReceiver()
{

}

CommandReceiver::CommandReceiver(QObject* parent=0)
{
    setParent(parent);
}

void CommandReceiver::onDataReceived(QByteArray *data, QHostAddress& senderIP)
{
    uint8_t cmd;
    cmd = data->at(0);

    switch(cmd)
    {
        case UdpDatagram::CONNECT_REQ:
        {
            connRequesterIP.clear();

            memcpy(&connRequesterPort, &data->data()[5], sizeof(int));

            int ipSize = 0;
            memcpy(&ipSize, data->data()+1, sizeof(int));
            ipSize -= sizeof(connRequesterPort);  /// Decrease by size of connRequesterPort
            for(int i = 9; i < ipSize + 9; i++)
            {
                connRequesterIP.append(data->at(i));
            }

            connRequesterIP.append('\0');
            emit connectionRequestSignal(senderIP.toString());
        }break;

        case UdpDatagram::CONNECT_ACK:
        {
            udpManager->setConnectionState(true);
        }break;

        case UdpDatagram::CONNECT_NACK:
        {
            udpManager->setConnectionState(false);
        }break;

//        case DEVICE_NAME:
//        {
//            std::string name = parseName(raw_data);
//            const UdpDevice dev = UdpDevice(name, ip, port);

//            if(!devicesFound.contains(dev))
//            {
//               devicesFound.append(dev);
//            }

//            sendACK(ip, port);
//        }break;

//        case VOLUME_VALUE:
//        {

//        }break;
    }
}

void CommandReceiver::setCommandSender(CommandSender* cmdSender)
{
    this->cmdSender = cmdSender;
}

void CommandReceiver::setUdpManager(UdpManager *manager)
{
    this->udpManager = manager;
}

void CommandReceiver::connectionUpdateGUICallback(bool connectionEstablished)
{
    QBuffer* buf = new QBuffer(new QByteArray(1, '\0'));
    buf->open(QIODevice::ReadWrite);

    /// Connect either way in order to be able to send response
//    udpManager->connectUDP(connRequesterIP, connRequesterPort);
    emit connectionEstablishSignal(connRequesterIP, connRequesterPort);
    /// Wait till connection established
    while(!udpManager->getConnectionState())
    {}

    /// If user agreed to connection
    if(connectionEstablished)
    {
        UdpDatagram* datagram = new UdpDatagram(UdpDatagram::CONNECT_ACK, buf);

        cmdSender->sendCommand(datagram);
//        udpManager->setConnectionState(true);
    }
    else    /// Otherwise send back response about non-agreement
    {
        UdpDatagram* datagram = new UdpDatagram(UdpDatagram::CONNECT_NACK, buf);
        cmdSender->sendCommand(datagram);
        udpManager->setConnectionState(false);
    }
}
