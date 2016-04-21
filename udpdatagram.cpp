#include "udpdatagram.h"
#include <stdint-gcc.h>
#include <iostream>
#include <QBuffer>


UdpDatagram::UdpDatagram()
{
}

UdpDatagram::UdpDatagram(UdpCommandEnum command, QBuffer* data)
{
    uint32_t dataSize = data->bytesAvailable();

    this->data = data->readAll();
    if(this->data != nullptr)
    {
        this->data.push_front(dataSize>>24);
        this->data.push_front(dataSize>>16);
        this->data.push_front(dataSize>>8);
        this->data.push_front(dataSize>>0);
        this->data.push_front((char)command);
    }
}

UdpDatagram::~UdpDatagram()
{

}

QByteArray* UdpDatagram::getDatagram()
{
    return &data;
}

UdpDatagram::UdpCommandEnum UdpDatagram::getCommand()
{
    UdpCommandEnum* cmd = (UdpCommandEnum*)this->data.data()[COMMAND_INDEX];

    return *cmd;
}

uint16_t UdpDatagram::getDataSize()
{
    uint16_t* dataSize = (uint16_t*)(this->data.data() + DATA_SIZE_INDEX);

    return *dataSize;
}

QByteArray* UdpDatagram::getDataCopy()
{
    QByteArray* byteBuf = new QByteArray(getDataSize(), 0);
    /// Copy the data
    memcpy(byteBuf->data(),  this->data.data()+DATA_SIZE_INDEX+DATA_SIZE_SIZE, this->getDataSize());

    return byteBuf;
}

void UdpDatagram::setCommand(UdpCommandEnum command)
{
    this->data.data()[COMMAND_INDEX] = command;
}

void UdpDatagram::setDataSize(uint16_t dataSize)
{
    this->data.data()[DATA_SIZE_INDEX] = dataSize & 0xFF;
    this->data.data()[DATA_SIZE_INDEX + 1] = (dataSize >> 8) & 0xFF;
}

void UdpDatagram::setDatagram(QByteArray* datagram)
{
    this->data = *datagram;
}

void UdpDatagram::setData(QByteArray* data)
{
    memcpy(this->data.data() + 3, data->data(), data->size());
}

void UdpDatagram::resize(int newSize)
{
    this->data.resize(newSize);
}

void UdpDatagram::displayDatagram()
{
    uint16_t* dataSize = (uint16_t*)(this->data.data()+DATA_SIZE_INDEX);
    UdpDatagram::UdpCommandEnum* cmd =  (UdpCommandEnum*)data.data()+COMMAND_INDEX;
    std::cout<<"Command:   "<<*cmd<<std::endl;
    std::cout<<"Data size: "<<*dataSize-COMMAND_SIZE-DATA_SIZE_SIZE<<std::endl;

    for(uint64_t i=4; i<*dataSize; i++)
        std::cout<<this->data.at(i)<<" ";
    std::cout << std::endl;

}
