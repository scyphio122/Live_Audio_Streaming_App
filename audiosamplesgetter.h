#ifndef AUDIOSAMPLESGETTER_H
#define AUDIOSAMPLESGETTER_H

#include <QtMultimedia/QAudioInput>
#include <QtMultimedia/QAudioOutput>
#include <QBuffer>
#include "audiosamplessender.h"

class AudioSamplesGetter
{
private:
    QAudioInput             audioInDevice;
    QAudioOutput            audioOutDevice;
    AudioSamplesSender*     audioSender;
    QBuffer*                capturingStream;
    QByteArray*             inputDataBuffer;
    bool                    isMuted;
    bool                    echoSound;

    void playEchoedSamples(int leftSample, int rightSample);

public:
    AudioSamplesGetter();

    void setAudioSamplesSender(AudioSamplesSender* newAudioSamplesSender);
    void setInputAudioDevice(QAudioInput* newAudioInputDev);
    void setOutputAudioDevoce(QAudioOutput* newAudioOutputDev);
    void setMuteEnabled(bool isMuted);
    void setEchoEnabled(bool isOn);
    void getSamples(int& leftSample, int& rightSample);
    void audioMixerDeviceInit(std::string audioDeviceName);



};

#endif // AUDIOSAMPLESGETTER_H
