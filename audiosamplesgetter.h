#ifndef AUDIOSAMPLESGETTER_H
#define AUDIOSAMPLESGETTER_H

#include <QtMultimedia/QAudioInput>
#include <QtMultimedia/QAudioOutput>
#include <QBuffer>
#include "audiosamplessender.h"

class AudioSamplesGetter : public QObject
{
private:
    const int                                   AUDIO_IN_BUFFER_SIZE = 1024;
    AudioSamplesSender*                         audioSender;
    boost::scoped_ptr<QAudioInput>              audioInDevice;
    boost::scoped_ptr<QAudioOutput>             audioOutDevice;
    boost::scoped_ptr<QBuffer>                  capturingStream;
    boost::scoped_ptr<QByteArray>               inputDataBuffer;
    bool                                        isMuted;
    bool                                        echoSound;
    bool                                        isCurrentlyPlaying;

    void playEchoedSamples(int leftSample, int rightSample);

public:
    AudioSamplesGetter();

    void setAudioSamplesSender(AudioSamplesSender* newAudioSamplesSender);
    void setInputAudioDevice(QAudioInput* newAudioInputDev);
    void setOutputAudioDevice(QAudioOutput* newAudioOutputDev);
    void setMuteEnabled(bool isMuted);
    void setEchoEnabled(bool isOn);
    void captureSamples(int& leftSample, int& rightSample);
    bool audioMixerDeviceInit(std::string audioDeviceName);
    void startSampling();
    void stopSampling();
    QList<QAudioDeviceInfo> listAvailableDevicesIn();
    QList<QAudioDeviceInfo> listAvailableDevicesOut();
    bool isPlaying();



};

#endif // AUDIOSAMPLESGETTER_H
