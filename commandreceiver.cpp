#include "commandreceiver.h"
#include "udpmanager.h"
#include <QObject>

CommandReceiver::CommandReceiver()
{

}

CommandReceiver::CommandReceiver(QObject* parent=0)
{
    setParent(parent);
}

void CommandReceiver::onDataReceived(QByteArray *data)
{

}
