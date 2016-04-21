#include "udpdatagram.h"
#include <stdint-gcc.h>
#include <iostream>
#include <QBuffer>


UdpDatagram::UdpDatagram()
{
    this->data.reserve(QBYTEARRAY_SIZE);
}

UdpDatagram::UdpDatagram(UdpCommandEnum command, QBuffer* data)
{
    char dataSize = data->data().size();
    char tmp = 0;
    this->data.reserve(QBYTEARRAY_SIZE);
    this->data.push_back((char)command);
    this->data.push_back(dataSize);

    while(dataSize>0)
    {
        data->getChar(&tmp);
        this->data.push_back(tmp);
        dataSize--;
    }
}

UdpDatagram::~UdpDatagram()
{

}

QByteArray UdpDatagram::getDatagram()
{
    return data;
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
    char* buf = new char[getDataSize()];

    QByteArray* byteBuf = new QByteArray(buf, getDataSize());
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
