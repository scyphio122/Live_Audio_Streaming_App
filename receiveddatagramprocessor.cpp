#include "receiveddatagramprocessor.h"
#include "udpdatagram.h"

ReceivedDatagramProcessor::ReceivedDatagramProcessor()
{

}

void ReceivedDatagramProcessor::processDatagram(UdpDatagram* datagram, QHostAddress ip, uint16_t port)
{
    UdpDatagram::UdpCommandEnum command = (UdpDatagram::UdpCommandEnum)datagram->getDatagram()->at(0);
    switch(command)
    {
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
