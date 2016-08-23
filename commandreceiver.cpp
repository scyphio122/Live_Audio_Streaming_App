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

void CommandReceiver::onDataReceived(QByteArray *data)
{
    uint8_t cmd;
    cmd = data->at(0);

    switch(cmd)
    {
        case UdpDatagram::CONNECT_REQ:
        {
            ConnectDialog connectDialog;
            QString ip;

            for(int i = 2; i < data->data()[1] - sizeof(int); i++)
            {
                ip.append(data->at(i));
            }

            ip.append('\0');

            int port = 0;
            memcpy(&port, data+1+data->data()[1]-sizeof(int), sizeof(int));

            int retval = connectDialog.exec();
            if(retval == QDialog::Accepted)
            {
                UdpDatagram datagram(UdpDatagram::CONNECT_ACK, nullptr);
                cmdSender->sendCommand(&datagram);
                udpManager->connectUDP(ip, port);
                udpManager->setConnectionState(true);
                emit connectionUpdateSignal(true);
            }
            else
            if(retval == QDialog::Rejected)
            {
                UdpDatagram datagram(UdpDatagram::CONNECT_NACK, nullptr);
                cmdSender->sendCommand(&datagram);
                udpManager->setConnectionState(false);
                emit connectionUpdateSignal(false);
            }

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
