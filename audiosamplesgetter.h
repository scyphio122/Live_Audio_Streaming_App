#ifndef AUDIOSAMPLESGETTER_H
#define AUDIOSAMPLESGETTER_H

#include <QtMultimedia/QAudioInput>
#include <QtMultimedia/QAudioOutput>
#include <QBuffer>
#include "audiosamplessender.h"

class AudioSamplesGetter : public QObject
{
    Q_OBJECT

private:
    const int                                   AUDIO_IN_BUFFER_SIZE = 1024;
    AudioSamplesSender*                         audioSender;
    QAudioInput*              audioInDevice;
    QAudioOutput*             audioOutDevice;
    QBuffer*                  capturingStream;
    QByteArray*               inputDataBuffer;
    bool                                        isMuted;
    bool                                        echoSound;
    bool                                        isCurrentlyPlaying;
    void playEchoedSamples(int leftSample, int rightSample);

public slots:
    void onSamplesCaptured();

public:
    AudioSamplesGetter();
    ~AudioSamplesGetter();

    void setAudioSamplesSender(AudioSamplesSender* newAudioSamplesSender);
    void setInputAudioDevice(QAudioInput* newAudioInputDev);
    void connectDeviceWithBuf();
    void setOutputAudioDevice(QAudioOutput* newAudioOutputDev);
    void setMuteEnabled(bool isMuted);
    void setEchoEnabled(bool isOn);
//    bool audioMixerDeviceInit(std::string audioDeviceName);
    void startSampling();
    void stopSampling();
    bool isPlaying();

};

#endif // AUDIOSAMPLESGETTER_H
