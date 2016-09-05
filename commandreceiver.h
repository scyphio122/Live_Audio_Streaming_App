#ifndef COMMANDRECEIVER_H
#define COMMANDRECEIVER_H

#include <datagramlistener.h>
#include <QObject>
#include <commandsender.h>
#include "udpmanager.h"

class UdpManager;
class CommandSender;


/**
 * @brief The CommandReceiver class - This class services all of the datagrams which are command datagrams, not audio samples datagrams
 */
class CommandReceiver : public DatagramListener
{
    Q_OBJECT

private:
    CommandSender*  cmdSender;
    UdpManager*     udpManager;

    QString         connRequesterIP;
    int             connRequesterPort;
public:
    CommandReceiver();
    CommandReceiver(QObject* parent);

    /**
     * @brief onDataReceived - this function is called when command datagram is received in order to process it
     * @param data[in] - datagram to process
     * @param senderIP[in] - sender's IP
     */
    void onDataReceived(QByteArray* data, QHostAddress &senderIP);

    /**
     * @brief setCommandSender - This function sets the command sender in order to be able to respond for a command
     * @param cmdSender
     */
    void setCommandSender(CommandSender* cmdSender);

    /**
     * @brief setUdpManager - This is the setter for the udpManager
     * @param manager
     */
    void setUdpManager(UdpManager* manager);

public slots:
    /**
     * @brief connectionUpdateGUICallback - This function is called in order to service the connection status change and display it in the GUI
     * @param connectionEstablished
     */
    void connectionUpdateGUICallback(bool connectionEstablished);

signals:
    /// Signal used to display connection request window
    void connectionRequestSignal(QString hostIP);

    /// Signal used to establish connection in the UdpManager
    void connectionEstablishSignal(QString ip, int port);

    /// This signal is used to update connect button's text
    void connectionStatusUpdate(bool isConnected);

    void disconnectGUICallback();
};

#endif // COMMANDRECEIVER_H
