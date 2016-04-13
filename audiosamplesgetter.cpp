#include "audiosamplesgetter.h"
#include <QMessageBox>
#include <QObject>
#include <string>
#include <QAudioInput>
#include <QAudioOutput>

AudioSamplesGetter::AudioSamplesGetter()
{
    this->isCurrentlyPlaying    = false;
    this->isMuted               = true;
    this->echoSound             = false;

    inputDataBuffer.reset(new QByteArray(new char[AUDIO_IN_BUFFER_SIZE], AUDIO_IN_BUFFER_SIZE));
    capturingStream.reset(new QBuffer(this->inputDataBuffer.get()));
    capturingStream->open(QIODevice::ReadWrite);
}

QList<QAudioDeviceInfo> AudioSamplesGetter::listAvailableDevicesIn()
{
    return QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
}

QList<QAudioDeviceInfo> AudioSamplesGetter::listAvailableDevicesOut()
{
    return QAudioDeviceInfo::availableDevices(QAudio::AudioOutput);
}


bool AudioSamplesGetter::audioMixerDeviceInit(std::string audioDeviceName)
{
    bool audioMixerFound = false;
    QList<QAudioDeviceInfo> devices = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
    QAudioDeviceInfo audioDeviceInfo;
    for(int i=0; i<devices.size(); i++)
    {
        if(devices[i].deviceName().toStdString() == audioDeviceName)
        {
            audioDeviceInfo = devices[i];
            audioMixerFound = true;
            break;
        }
    }

    if(!audioMixerFound)
    {
        QMessageBox errorWindow;
        errorWindow.setText("Audio mixer device not found. Remote audio transmission not available.");
        errorWindow.setIcon(QMessageBox::Warning);
        errorWindow.exec();
        return false;
    }


    QAudioFormat desiredFormat;
    desiredFormat.setChannelCount(2);
    desiredFormat.setCodec("audio/pcm");
    desiredFormat.setSampleType(QAudioFormat::SignedInt);
    desiredFormat.setSampleRate(48000);
    desiredFormat.setSampleSize(16);
    desiredFormat = audioDeviceInfo.nearestFormat(desiredFormat);

    setInputAudioDevice(new QAudioInput(audioDeviceInfo, desiredFormat));
//    connect(audioInDevice, SIGNAL(readyRead()), this, SLOT(captureSamples()));
    return true;
}

void AudioSamplesGetter::setAudioSamplesSender(AudioSamplesSender* newAudioSamplesSender)
{
    audioSender = newAudioSamplesSender;
}


void AudioSamplesGetter::setInputAudioDevice(QAudioInput* newAudioInputDev)
{
    this->audioInDevice.reset(newAudioInputDev);
}

void AudioSamplesGetter::setOutputAudioDevice(QAudioOutput* newAudioOutputDev)
{
    this->audioOutDevice .reset(newAudioOutputDev);
}

void AudioSamplesGetter::setMuteEnabled(bool isMuted)
{
    this->isMuted = isMuted;
}

void AudioSamplesGetter::setEchoEnabled(bool isOn)
{
    this->echoSound = isOn;
}

void AudioSamplesGetter::startSampling()
{
    if(!isCurrentlyPlaying)
    {
        audioInDevice->start(capturingStream.get());
        isCurrentlyPlaying = true;
    }
}

void AudioSamplesGetter::stopSampling()
{
    if(isCurrentlyPlaying)
    {
        audioInDevice->stop();
        isCurrentlyPlaying = false;
    }
}


void AudioSamplesGetter::captureSamples(int& leftSample, int& rightSample)
{

}

void AudioSamplesGetter::playEchoedSamples(int leftSample, int rightSample)
{

}

bool AudioSamplesGetter::isPlaying()
{
    return this->isCurrentlyPlaying;
}

