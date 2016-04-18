#ifndef AUDIOSAMPLESRECEIVER_H
#define AUDIOSAMPLESRECEIVER_H

#include <datagramlistener.h>
#include <QtMultimedia/QAudioOutput>
#include <QBuffer>
#include "fftcalculator.h"


class AudioSamplesPlayer : public DatagramListener
{
private:
    const int   AUDIO_OUT_BUF_SIZE  =   1024;
    FftCalculator fft;
    QBuffer*     audioOutputBuffer;
    QAudioOutput audioOutput;
public:
    AudioSamplesPlayer();
    void onDataReceived(QByteArray *data);
};

#endif // AUDIOSAMPLESRECEIVER_H
