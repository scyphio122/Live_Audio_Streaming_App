#include "audiosamplesgetter.h"
#include <QMessageBox>
#include <QObject>
#include <string>
#include <QAudioInput>
#include <QAudioOutput>
#include <QQueue>

#include <QTime>
#include <QDebug>

AudioSamplesGetter::AudioSamplesGetter()
{
}



AudioSamplesGetter::~AudioSamplesGetter()
{
    delete inputDataBuffer;
    delete capturingStream;
    delete audioInDevice;
}

void AudioSamplesGetter::init()
{
    this->isCurrentlySampling    = false;
    this->isMuted               = true;
    this->echoSound             = false;

    inputDataBuffer = new QByteArray(AUDIO_IN_BUFFER_SIZE, 0);
    capturingStream = new QBuffer(this->inputDataBuffer);

    capturingStream->open(QIODevice::ReadWrite);

    memset(inputDataBuffer->data(), 0, AUDIO_IN_BUFFER_SIZE);
}


void AudioSamplesGetter::setAudioSamplesSender(AudioSamplesSender* newAudioSamplesSender)
{
    audioSender = newAudioSamplesSender;
}


void AudioSamplesGetter::setInputAudioDevice(QAudioInput* newAudioInputDev)
{
    this->audioInDevice = newAudioInputDev;
    /// Connect the just set device with the buffer for samples
    connectDeviceWithBuf();
}

void AudioSamplesGetter::connectDeviceWithBuf()
{
    connect(capturingStream, SIGNAL(readyRead()), this, SLOT(onSamplesCaptured()));
}


void AudioSamplesGetter::setMuteEnabled(bool isMuted)
{
    this->isMuted = isMuted;
}


void AudioSamplesGetter::startSampling(bool value)
{
    if(!isCurrentlySampling && value == true)
    {
        inputDataBuffer->fill(0, inputDataBuffer->length());
        audioInDevice->setBufferSize(AUDIO_IN_BUFFER_SIZE);
        audioInDevice->start(capturingStream);
        isCurrentlySampling = true;
    }
    else
    {
        audioInDevice->stop();
        isCurrentlySampling = false;
    }
}


void AudioSamplesGetter::onSamplesCaptured()
{
    this->capturingStream->seek(0);
    this->audioSender->sendSamples(capturingStream);
}


void AudioSamplesGetter::isSampling()
{
    emit isSamplingSignal(isCurrentlySampling);
}

