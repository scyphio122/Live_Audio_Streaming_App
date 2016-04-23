#include "audiosamplesplayer.h"

AudioSamplesPlayer::AudioSamplesPlayer()
{

}

AudioSamplesPlayer::AudioSamplesPlayer(QObject* parent=0)
{
    setParent(parent);
}

void AudioSamplesPlayer::init()
{
    this->audioOutputBuffer = new QBuffer(new QByteArray(new char[AUDIO_OUT_BUF_SIZE], AUDIO_OUT_BUF_SIZE));
    this->muted = true;

    this->fft = new FftCalculator();
    this->fft->setInputArraySize(AUDIO_OUT_BUF_SIZE);
}

AudioSamplesPlayer::~AudioSamplesPlayer()
{
    delete this->audioOutputBuffer;
}

void AudioSamplesPlayer::setAudioOutput(QAudioOutput *dev)
{
    this->audioOutput.reset(dev);
}

void AudioSamplesPlayer::startPlaying(bool value)
{
    if(value == true)
    {
        muted = false;
        this->audioOutput->start(this->audioOutputBuffer);
    }
    else
    {
        muted = true;
        this->audioOutput->stop();
    }
}

bool AudioSamplesPlayer::isMuted()
{
    emit isMutedSignal(this->muted);
    return this->muted;
}

FftCalculator* AudioSamplesPlayer::getFFT()
{
    return this->fft;
}

void AudioSamplesPlayer::onDataReceived(QByteArray* data)
{
    int i = 0;
    uint16_t sample = 0;
    int dataSize = data->size();
    if(!muted)
    {
        if(fft->getInputArray() == nullptr)
            fft->setInputArray(new int[8192]);
        while(dataSize != 0)
        {
            /// Put data in the audio buffer
            this->audioOutputBuffer->putChar(data->at(i));
            if(dataSize % 2 == 0)
            {
                sample = (uint8_t)data->at(i) + ((uint8_t)data->at(i+1) >> 8);
                fft->appendSample(sample);
                if(fft->getInputFillLevel() == fft->getInputArraySize()-1)
                {
                    fft->runTransform();
                }
            }
            i+=2;
            dataSize -= 2;
        }
    }
    delete data;
}
