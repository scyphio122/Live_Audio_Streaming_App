#include "audiosamplesgetter.h"
#include <QMessageBox>
#include <string>

AudioSamplesGetter::AudioSamplesGetter()
{
    audioMixerDeviceInit("Miks stereo (Realtek High Defin");
}

void AudioSamplesGetter::audioMixerDeviceInit(std::string audioDeviceName)
{
    bool audioMixerFound = false;
    QList<QAudioDeviceInfo> devices = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
    QAudioDeviceInfo audioDeviceInfo = QAudioDeviceInfo(;
    for(int i=0; i<devices.size(); i++)
    {
        if(devices[i].deviceName() == audioDeviceName)
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

    capturingStream->setOpenMode();
    audioInDevice.reset(new QAudioInput(audioInDevice));
    audioInDevice.start(capturingStream);

//    connect(capturingDevice, SIGNAL(readyRead()), this, SLOT(captureSample()));
    return true;
}

void AudioSamplesGetter::setAudioSamplesSender(AudioSamplesSender* newAudioSamplesSender)
{
    audioSender = newAudioSamplesSender;
}

void AudioSamplesGetter::setAudioSamplesSender(AudioSamplesSender* newAudioSamplesSender)
{
    this->audioSender = newAudioSamplesSender;
}

void AudioSamplesGetter::setInputAudioDevice(QAudioInput* newAudioInputDev)
{
    this->audioInDevice = newAudioInputDev;
}

void AudioSamplesGetter::setOutputAudioDevoce(QAudioOutput* newAudioOutputDev)
{
    this->audioOutDevice = newAudioOutputDev;
}

void AudioSamplesGetter::setMuteEnabled(bool isMuted)
{
    this->isMuted = isMuted;
}

void AudioSamplesGetter::setEchoEnabled(bool isOn)
{
    this->echoSound = isOn;
}

void AudioSamplesGetter::getSamples(int& leftSample, int& rightSample)
{

}

void AudioSamplesGetter::playEchoedSamples(int leftSample, int rightSample)
{

}
