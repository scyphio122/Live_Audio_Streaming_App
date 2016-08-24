#include "receiveddatagramprocessor.h"
#include "udpdatagram.h"
#include "connectdialog.h"


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
    UdpDatagram::UdpCommandEnum command = (UdpDatagram::UdpCommandEnum)datagram->getDatagram().at(0);

    switch(command)
    {
        case UdpDatagram::SAMPLES:
        {
            QByteArray* data = datagram->getDataCopy();
            this->audioPlayer->onDataReceived(data);
            delete data;
        }break;

        default:
        {
            this->cmdReceiver->onDataReceived(&datagram->getDatagram());
        }break;
    }


    delete datagram;

    return;
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
