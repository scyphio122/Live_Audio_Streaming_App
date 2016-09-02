#ifndef AUDIOSAMPLESRECEIVER_H
#define AUDIOSAMPLESRECEIVER_H

#include <datagramlistener.h>
#include <QtMultimedia/QAudioOutput>
#include <QBuffer>
#include "fftcalculator.h"
#include <boost/smart_ptr/scoped_ptr.hpp>
#include <QQueue>
#include <QTimer>
#include <abstractvisualization.h>

class AudioSamplesPlayer : public DatagramListener
{
    Q_OBJECT

private:
    const int                           AUDIO_OUT_BUF_SIZE  =   8192*8-100;
    const int                           OUTPUT_QUEUE_SIZE   =   100;

    FftCalculator*                      fft                 =   nullptr;
    QBuffer*                            audioOutputBuffer   =   nullptr;
    QAudioOutput*                       audioOutput         =   nullptr;
    bool                                muted               =   true;
    bool                                isConnected         =   false;
    AbstractVisualization::InputType    inputType           =   AbstractVisualization::INPUT_FFT;

    void m_AudioOutWatchdog();
public:
    AudioSamplesPlayer();
    AudioSamplesPlayer(QObject* parent);
    ~AudioSamplesPlayer();

    FftCalculator* getFFT();
    void onDataReceived(QByteArray *data, QHostAddress& senderIP);
    int getInputArraySize() {return AUDIO_OUT_BUF_SIZE;}

public slots:
    void init();
    void setAudioOutput(QAudioOutput* dev);
    void startPlaying(bool value);
    bool isMuted();
    void changeVolume(int volumePercentage);
//    void bufferEmptyEvent(QAudio::State state);
    void changeConnectionState(bool state);
    void on_VisualizationChange(int inputType);
signals:
    void isMutedSignal(bool value);
    void sendFft(FftCalculator* fft);
    void sendSamplesSignal(int16_t* samplesArray);
};

#endif // AUDIOSAMPLESRECEIVER_H
