#include "receiveddatagramprocessor.h"

ReceivedDatagramProcessor::ReceivedDatagramProcessor()
{

}

void ReceivedDatagramProcessor::processDatagram(uint8_t* raw_data, uint64_t data_size, QHostAddress ip, uint16_t port)
{
    uint8_t command = raw_data[0];
    for(uint64_t i=0; i<data_size; i++)
        qDebug()<<raw_data[i]<<" ";
    qDebug() << endl;
    switch(command)
    {
        case ACK:
        {

        }break;
        case DEVICE_NAME:
        {
            std::string name = parseName(raw_data);
//            const UdpDevice dev = UdpDevice(name, ip, port);

//            if(!devicesFound.contains(dev))
//            {
//                devicesFound.append(dev);
//            }

//            sendACK(ip, port);
            break;
        }
        case VOLUME_VALUE:
        {

            break;
        }
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
