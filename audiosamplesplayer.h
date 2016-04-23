#ifndef AUDIOSAMPLESRECEIVER_H
#define AUDIOSAMPLESRECEIVER_H

#include <datagramlistener.h>
#include <QtMultimedia/QAudioOutput>
#include <QBuffer>
#include "fftcalculator.h"
#include <boost/smart_ptr/scoped_ptr.hpp>

class AudioSamplesPlayer : public DatagramListener
{
    Q_OBJECT

private:
    const int                           AUDIO_OUT_BUF_SIZE  =   8192;
    FftCalculator*                      fft;
    QBuffer*                            audioOutputBuffer;
    boost::scoped_ptr<QAudioOutput>     audioOutput;
    bool                                muted;
public:
    AudioSamplesPlayer();
    AudioSamplesPlayer(QObject* parent);
    ~AudioSamplesPlayer();

    FftCalculator* getFFT();
    void onDataReceived(QByteArray *data);

public slots:
    void init();
    void setAudioOutput(QAudioOutput* dev);
    void startPlaying(bool value);
    bool isMuted();
signals:
    void isMutedSignal(bool value);
};

#endif // AUDIOSAMPLESRECEIVER_H
