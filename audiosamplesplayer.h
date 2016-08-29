#ifndef AUDIOSAMPLESRECEIVER_H
#define AUDIOSAMPLESRECEIVER_H

#include <datagramlistener.h>
#include <QtMultimedia/QAudioOutput>
#include <QBuffer>
#include "fftcalculator.h"
#include <boost/smart_ptr/scoped_ptr.hpp>
#include <QQueue>

class AudioSamplesPlayer : public DatagramListener
{
    Q_OBJECT

private:
    const int                           AUDIO_OUT_BUF_SIZE  =   16384;
    const int                           OUTPUT_QUEUE_SIZE   =   20;

    FftCalculator*                      fft                 =   nullptr;
    QBuffer*                            audioOutputBuffer   =   nullptr;
    QAudioOutput*                       audioOutput         =   nullptr;
    QQueue<QBuffer*>                    audioOutputQueue;
    bool                                muted               =   true;

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
    void changeVolume(int volumePercentage);
    void bufferEmptyEvent(QAudio::State state);

signals:
    void isMutedSignal(bool value);
    void sendFft(FftCalculator* fft);
};

#endif // AUDIOSAMPLESRECEIVER_H
