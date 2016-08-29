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
    inputQueue.reserve(INPUT_QUEUE_SIZE);
}



AudioSamplesGetter::~AudioSamplesGetter()
{
    delete inputDataBuffer;
    delete capturingStream;
    delete audioInDevice;
    delete audioOutDevice;
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

void AudioSamplesGetter::setOutputAudioDevice(QAudioOutput* newAudioOutputDev)
{
    this->audioOutDevice = (newAudioOutputDev);
}

void AudioSamplesGetter::setMuteEnabled(bool isMuted)
{
    this->isMuted = isMuted;
}

void AudioSamplesGetter::setEchoEnabled(bool isOn)
{
    this->echoSound = isOn;
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
    if(inputQueue.count() == INPUT_QUEUE_SIZE)
    {
        delete this->capturingStream;
    }
    else
    {
        inputQueue.enqueue(this->capturingStream);
    }

    this->inputDataBuffer = new QByteArray(AUDIO_IN_BUFFER_SIZE, 0);
    this->capturingStream = new QBuffer(inputDataBuffer);
    this->capturingStream->open(QIODevice::ReadWrite);
    this->audioInDevice->start(this->capturingStream);

    if(inputQueue.count() > INPUT_QUEUE_WATERMARK)
    {
        while(inputQueue.count() > 0)
        this->audioSender->sendSamples(inputQueue.dequeue());
    }
}

void AudioSamplesGetter::playEchoedSamples()
{

}

void AudioSamplesGetter::isSampling()
{
    emit isSamplingSignal(isCurrentlySampling);
}

