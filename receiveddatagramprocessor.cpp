#include "receiveddatagramprocessor.h"
#include "udpdatagram.h"

ReceivedDatagramProcessor::ReceivedDatagramProcessor()
{

}

ReceivedDatagramProcessor::ReceivedDatagramProcessor(AudioSamplesPlayer* player, CommandReceiver* cmdRec)
{
    this->audioPlayer = player;
    this->cmdReceiver = cmdRec;
}

void ReceivedDatagramProcessor::setAudioSamplesPlayer(AudioSamplesPlayer* player)
{
    this->audioPlayer = player;
}

void ReceivedDatagramProcessor::setCommandReceiver(CommandReceiver* cmdRec)
{
    this->cmdReceiver = cmdRec;
}


void ReceivedDatagramProcessor::processDatagram(UdpDatagram* datagram)
{
    UdpDatagram::UdpCommandEnum command = (UdpDatagram::UdpCommandEnum)datagram->getDatagram()->at(0);
    switch(command)
    {
        case UdpDatagram::SAMPLES:
        {
            QByteArray* data = datagram->getDataCopy();
            this->audioPlayer->onDataReceived(data);
            break;
        }
//        case ACK:
//        {

//        }break;
//        case DEVICE_NAME:
//        {
//            std::string name = parseName(raw_data);
////            const UdpDevice dev = UdpDevice(name, ip, port);

////            if(!devicesFound.contains(dev))
////            {
////                devicesFound.append(dev);
////            }

////            sendACK(ip, port);
//            break;
//        }
//        case VOLUME_VALUE:
//        {

//            break;
//        }
        default:
            break;
    }
}

std::string ReceivedDatagramProcessor::parseName(uint8_t* data)
{
    uint64_t i=1;
    std::string name = "";

    while(data[i] != '\0')
    {
        name.push_back(data[i]);
    }

    return name;
}
