#ifndef UDPMANAGER_H
#define UDPMANAGER_H

#include "receiveddatagramprocessor.h"
#include <boost/smart_ptr/scoped_ptr.hpp>
#include <QUdpSocket>
#include <QHostAddress>
#include <QObject>
#include <udpdatagram.h>

class ReceivedDatagramProcessor;

/**
 * @brief The UdpManager class - This class manages the entire UDP network functionality. It sends and reads datagrams no matter of their kind.
 */
class UdpManager : public QObject
{
    Q_OBJECT

private:
    int                             portNumberInUse;
    QHostAddress*                   receiverIpAddress = nullptr;
    QUdpSocket*                     udpSocket = nullptr;
    ReceivedDatagramProcessor*      datagramProc = nullptr;
    bool                            isConnected = false;
    QMutex                          mutex;

    /**
     * @brief m_setReceiverIpAddress - Private function for setting the IP address of the computer which is to receive the datagrams
     * @param address[in]
     */
    void m_setReceiverIpAddress(std::string address);
public:
    /**
     * @brief UdpManager - simple constructor.
     */
    UdpManager();

    /**
     * @brief UdpManager - Constructor to create the object in one step.
     * @param ip[in] - the IP address of the computer which will receive the datas
     * @param sendPort[in] - the port on which the communication will take place
     */
    UdpManager(QHostAddress* ip, int sendPort);
    ~UdpManager();

    /**
     * @brief setDatagramProc - setter for the datagram processor. All datagrams are delivered to it. It manages the further usage of the datagrams depending on the command field
     * @param datagramProcessor[in]
     */
    void setDatagramProc(ReceivedDatagramProcessor* datagramProcessor);

    /**
     * @brief setConnectionState - setter for the connection state
     * @param state[in] - true if connected
     */
    void setConnectionState(bool state);

    /**
     * @brief getConnectionState - getter for the connection state
     * @return true if connected
     */
    bool getConnectionState();

public slots:
    /**
     * @brief setReceiverIpAddress - does basically the same as @function m_setReceiverIpAddress, but thread safe - it uses mutex
     * @param address[in]
     */
    void setReceiverIpAddress(std::string address);

    /**
     * @brief setSendingPortNumber - Setter for the port. It is thread safe.
     * @param portNumber[in]
     */
    void setSendingPortNumber(int portNumber);

    /**
     * @brief connectUDP - Function which establishes connection. It configures the UDP socket
     * @param ip[in] - IP of the other computer with which the connection is being established
     * @param port[in] - the port on which the communication will take place
     */
    void connectUDP(QString ip, int port);

    /**
     * @brief sendData - This function is responsible for sending a datagram to the other computer
     * @param datagram[in] - pointer to the datagram to be sent
     */
    void sendData(UdpDatagram* datagram);

    /**
     * @brief sendCmd - simple wrapper for @function sendData, basically to indicate that command datagram is being sent
     * @param datagram[in] - pointer ot the datagram to be sent
     */
    void sendCmd(UdpDatagram* datagram);

    /**
     * @brief readData - This function reads the pending datagram(s) and delivers it to the receivedDatagramProc to  further processing.
     */
    void readData();

signals:
    void emitDataReceived(UdpDatagram* datagram, QString senderIP); /*< Signal emitted when the datagram has been received */

    void onConnectionStateChangedSignal(bool state); /*< Signal emitted when connection status has changed */
};

#endif // UDPMANAGER_H
