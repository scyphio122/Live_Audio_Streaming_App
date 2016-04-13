#ifndef AUDIOSAMPLESRECEIVER_H
#define AUDIOSAMPLESRECEIVER_H

#include <datagramlistener.h>

class AudioSamplesPlayer : public DatagramListener
{
public:
    AudioSamplesPlayer();
    void onDataReceived(QByteArray& data);
};

#endif // AUDIOSAMPLESRECEIVER_H
