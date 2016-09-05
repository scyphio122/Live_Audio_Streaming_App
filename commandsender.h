#ifndef COMMANDSSENDER_H
#define COMMANDSSENDER_H

#include <udpmanager.h>
#include <QObject>
class UdpManager;

/**
 * @brief The CommandSender class - THis is a simple wrapper for sending commands
 */
class CommandSender : public QObject
{
    Q_OBJECT
private:
    UdpManager* udpManager;

public:
    CommandSender();
    ~CommandSender();

    /**
     * @brief setUdpManager - This is the setter for udpManager
     * @param udp
     */
    void setUdpManager(UdpManager* udp);

    /**
     * @brief sendCommand - This is function called to send command datagram
     * @param datagram[in] - pointer to the command datagram
     */
    void sendCommand(UdpDatagram* datagram);

public slots:
    /**
     * @brief sendConnectionRequest - shortcut function to send request for the UDP connection to the other side
     * @param myIP - IP of this computer
     * @param receiverPort - port on which the communication will take place
     */
    void sendConnectionRequest(QString myIP, int receiverPort);

    /**
     * @brief sendDisconnectCommand - This funciton is called in order to send the disconnect request
     */
    void sendDisconnectCommand();

signals:
    ///  This signal is emmited to send datagram to be sent to the udpManager thread
    void sendCommandSignal(UdpDatagram *datagram);

    /// Signal used to establish connection in the UdpManager
    void connectionEstablishSignal(QString ip, int port);
};

#endif // COMMANDSSENDER_H
