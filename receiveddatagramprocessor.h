#ifndef RECEIVEDDATAGRAMPROCESSOR_H
#define RECEIVEDDATAGRAMPROCESSOR_H

#include <QHostAddress>
#include <stdint-gcc.h>
#include "udpdatagram.h"
class ReceivedDatagramProcessor
{
private:
    UdpDatagram* datagram;
    std::string parseName(uint8_t* data);


public:
    ReceivedDatagramProcessor();

    void processDatagram(UdpDatagram *datagram, QHostAddress ip, uint16_t port);
};

#endif // RECEIVEDDATAGRAMPROCESSOR_H
