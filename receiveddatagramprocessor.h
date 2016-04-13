#ifndef RECEIVEDDATAGRAMPROCESSOR_H
#define RECEIVEDDATAGRAMPROCESSOR_H

#include <QHostAddress>
#include <stdint-gcc.h>

class ReceivedDatagramProcessor
{
private:
    std::string parseName(uint8_t* data);

    enum ControlCommands
    {
        ACK,
        DEVICE_NAME,
        VOLUME_VALUE
    };

public:
    ReceivedDatagramProcessor();

    void processDatagram(uint8_t* raw_data, uint64_t data_size, QHostAddress ip, uint16_t port);
};

#endif // RECEIVEDDATAGRAMPROCESSOR_H
