#ifndef UDPDATAGRAM_H
#define UDPDATAGRAM_H

#include <stdint-gcc.h>
#include <QByteArray>
#include <QBuffer>

/**
 * @brief The UdpDatagram class - This class is a simple wrapper for a byte array and represents the UdpDatagram
 */
class UdpDatagram
{
private:
    const int               COMMAND_INDEX = 0;
    const int               COMMAND_SIZE  = 1;
    const int               DATA_SIZE_INDEX = 1;
    const int               DATA_SIZE_SIZE  = 4;

    QByteArray             data;

public:

    enum UdpCommandEnum : char
    {
        SAMPLES = 0,

        CONNECT_REQ,
        DISCONNECT,
        CONNECT_ACK,
        CONNECT_NACK,

    };

    /**
     * @brief UdpDatagram - Simple constructor. Deprecated.
     */
    UdpDatagram();
    /**
     * @brief UdpDatagram - Constructor which creates entire datagram in one step
     * @param command[in] - byte which specifies the type of datagram
     * @param data[in] - pointer to the data which are to be sent. They are deep-copied
     */
    UdpDatagram(UdpCommandEnum command, QBuffer *data);
    ~UdpDatagram();


    /**
     * @brief getDatagram - getter for data from datagram.
     * @return reference to the data. It is valid until the datagram is in scope.
     */
    QByteArray&         getDatagram();

    /**
     * @brief getCommand - getter for command
     * @return command value
     */
    UdpCommandEnum      getCommand();

    /**
     * @brief getDataSize - getterfor data size
     * @return data size
     */
    uint16_t            getDataSize();

    /**
     * @brief getDataCopy - returns a pointer to the deep copied data. They lie on a heap.
     * @return pointer to the data
     */
    QByteArray*         getDataCopy();

    /**
     * @brief setDatagram - setter for entire datagram. It includes command and data size already
     * @param datagram[in]
     */
    void                setDatagram(QByteArray* datagram);

    /**
     * @brief setCommand - setter for command
     * @param command[in]
     */
    void                setCommand(UdpCommandEnum command);

    /**
     * @brief setDataSize - setter for data size.
     * @param dataSize[in]
     */
    void                setDataSize(uint16_t dataSize);

    /**
     * @brief setData - setter for data. Not inclucing data size and command
     * @param data[in]
     */
    void                setData(QByteArray* data);

    /**
     * @brief displayDatagram - debug function used to show the datagram on the console
     */
    void                displayDatagram();

    /**
     * @brief resize - function to resize the datagram size
     * @param newSize[in] - requested size of the datagram's internal buffer - QByteArray
     */
    void                resize(int newSize);


};

#endif // UDPDATAGRAM_H
