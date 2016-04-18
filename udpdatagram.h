#ifndef UDPDATAGRAM_H
#define UDPDATAGRAM_H

#include <stdint-gcc.h>
#include <QByteArray>

class UdpDatagram
{
private:
    const int               COMMAND_INDEX = 0;
    const int               COMMAND_SIZE  = 1;
    const int               DATA_SIZE_INDEX = 1;
    const int               DATA_SIZE_SIZE  = 2;
    char*                   intBuffer;
    QByteArray*             data;

public:

    enum UdpCommandEnum : char
    {
        SAMPLES = 0
    };

    UdpDatagram();
    UdpDatagram(UdpCommandEnum command, QByteArray* data);
    ~UdpDatagram();


    QByteArray*         getDatagram();
    UdpCommandEnum      getCommand();
    uint16_t            getDataSize();
    QByteArray*         getDataCopy();

    void                setDatagram(QByteArray* datagram);
    void                setCommand(UdpCommandEnum command);
    void                setDataSize(uint16_t dataSize);
    void                setData(QByteArray* data);

    void                displayDatagram();
    void                resize(int newSize);

};

#endif // UDPDATAGRAM_H
