#include "udpdatagram.h"
#include <stdint-gcc.h>
#include <iostream>

UdpDatagram::UdpDatagram()
{

}

UdpDatagram::UdpDatagram(UdpCommandEnum command, QByteArray* data)
{
    int dataSize = data->size();
    this->intBuffer = new char[dataSize + sizeof(UdpCommandEnum) + DATA_SIZE_SIZE];
    this->data  = new QByteArray(intBuffer, dataSize + 4);
    this->data->data()[0] = (char)command;
    memcpy(&this->data->data()[DATA_SIZE_INDEX], &dataSize, 2);
    memcpy(&this->data->data()[DATA_SIZE_INDEX + DATA_SIZE_SIZE], data->data(), dataSize);
}

UdpDatagram::~UdpDatagram()
{
    delete data;
    delete intBuffer;
}

QByteArray* UdpDatagram::getDatagram()
{
    return data;
}

UdpDatagram::UdpCommandEnum UdpDatagram::getCommand()
{
    UdpCommandEnum* cmd = (UdpCommandEnum*)this->data->data()[COMMAND_INDEX];

    return *cmd;
}

uint16_t UdpDatagram::getDataSize()
{
    uint16_t* dataSize = (uint16_t*)(this->data->data() + DATA_SIZE_INDEX);

    return *dataSize;
}

void UdpDatagram::setCommand(UdpCommandEnum command)
{
    this->data->data()[COMMAND_INDEX] = command;
}

void UdpDatagram::setDataSize(uint16_t dataSize)
{
    this->data->data()[DATA_SIZE_INDEX] = dataSize & 0xFF;
    this->data->data()[DATA_SIZE_INDEX + 1] = (dataSize >> 8) & 0xFF;
}

void UdpDatagram::setDatagram(QByteArray* datagram)
{
    this->data = datagram;
}

void UdpDatagram::setData(QByteArray* data)
{
    memcpy(this->data->data() + 3, data->data(), data->size());
}

void UdpDatagram::resize(int newSize)
{
    this->data->resize(newSize);
}

void UdpDatagram::displayDatagram()
{
    uint16_t* dataSize = (uint16_t*)(this->data->data()+DATA_SIZE_INDEX);
    UdpDatagram::UdpCommandEnum* cmd =  (UdpCommandEnum*)data->data()+COMMAND_INDEX;
    std::cout<<"Command:   "<<*cmd<<std::endl;
    std::cout<<"Data size: "<<*dataSize-COMMAND_SIZE-DATA_SIZE_SIZE<<std::endl;

    for(uint64_t i=4; i<*dataSize; i++)
        std::cout<<this->data->at(i)<<" ";
    std::cout << std::endl;

}
