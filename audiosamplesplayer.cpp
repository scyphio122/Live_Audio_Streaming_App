#include "audiosamplesplayer.h"

AudioSamplesPlayer::AudioSamplesPlayer()
{
    this->audioOutputBuffer = new QBuffer(new QByteArray(new char[AUDIO_OUT_BUF_SIZE], AUDIO_OUT_BUF_SIZE));
    this->muted = true;
}

AudioSamplesPlayer::~AudioSamplesPlayer()
{
    delete this->audioOutputBuffer;
}

void AudioSamplesPlayer::setAudioOutput(QAudioOutput *dev)
{
    this->audioOutput.reset(dev);
}

void AudioSamplesPlayer::startPlaying()
{
    muted = false;
    this->audioOutput->start(this->audioOutputBuffer);
}

void AudioSamplesPlayer::pausePlaying()
{
    muted = true;
    this->audioOutput->stop();
}

bool AudioSamplesPlayer::isMuted()
{
    return this->muted;
}

FftCalculator* AudioSamplesPlayer::getFFT()
{
    return &this->fft;
}

void AudioSamplesPlayer::onDataReceived(QByteArray* data)
{
    int i = 0;
    uint16_t sample = 0;
    if(!muted)
    {
        while(data->size() != 0)
        {
            /// Put data in the audio buffer
            this->audioOutputBuffer->putChar(data->at(i));
            if(data->size() % 2 == 0)
            {
                sample = (uint8_t)data->at(i) + ((uint8_t)data->at(i+1) >> 8);
                fft.appendSample(sample);
                if(fft.getInputFillLevel() == fft.getInputArraySize()-1)
                {
                    fft.runTransform();
                }
            }
            i++;
        }
    }
    delete data;
}
