#include "audiosamplesplayer.h"
#include <QMessageBox>
AudioSamplesPlayer::AudioSamplesPlayer()
{

}

AudioSamplesPlayer::AudioSamplesPlayer(QObject* parent=0)
{
    setParent(parent);
}

void AudioSamplesPlayer::init()
{
    if(fft != nullptr)
        delete fft;

    this->fft = new FftCalculator();
    this->fft->setInputArraySize(AUDIO_OUT_BUF_SIZE);

    emit sendFft(fft);
}

AudioSamplesPlayer::~AudioSamplesPlayer()
{
    delete this->audioOutputBuffer;
}

void AudioSamplesPlayer::setAudioOutput(QAudioOutput *dev)
{
    if(audioOutput != nullptr)
    {
        delete audioOutput;
        audioOutput = nullptr;
    }

    this->audioOutput = dev;
}

void AudioSamplesPlayer::startPlaying(bool value)
{
    if(value == true)
    {
        if(this->audioOutputBuffer != nullptr)
            delete audioOutputBuffer;
        this->audioOutputBuffer = new QBuffer(new QByteArray(AUDIO_OUT_BUF_SIZE, 0));
        bool retval = this->audioOutputBuffer->open(QIODevice::ReadWrite);

        memset(audioOutputBuffer->buffer().data(), 0, audioOutputBuffer->size());
        audioOutputBuffer->seek(0);
        this->audioOutput->start(this->audioOutputBuffer);
        muted = false;
    }
    else
    {
        muted = true;
        this->audioOutput->stop();
    }
}

bool AudioSamplesPlayer::isMuted()
{
    return this->muted;
}

void AudioSamplesPlayer::changeVolume(int volumePercentage)
{
    this->audioOutput->setVolume((double)volumePercentage/100);
}

FftCalculator* AudioSamplesPlayer::getFFT()
{
    return this->fft;
}

void AudioSamplesPlayer::onDataReceived(QByteArray* data)
{
    if(!muted)
    {
        int dataSize = data->size();
        int inputSize = AUDIO_OUT_BUF_SIZE;
        if(dataSize > AUDIO_OUT_BUF_SIZE)
        {
            inputSize = (dataSize/AUDIO_OUT_BUF_SIZE)*AUDIO_OUT_BUF_SIZE + AUDIO_OUT_BUF_SIZE;
            data->resize(inputSize);
            /// Fill the rest of the array with zeros
            memset(data->data()+dataSize, 0, inputSize-dataSize);
            if((inputSize % AUDIO_OUT_BUF_SIZE) == 0)
            {
                QMessageBox w;
                w.setIcon(QMessageBox::Icon::Warning);
                w.setText("FFT: Rozmiar wejścia nieprawidłowy: " + QString::number(inputSize));
                w.show();
                w.exec();
                return;
            }
        }
        else if(dataSize < AUDIO_OUT_BUF_SIZE)
        {
            return;
        }

        if(audioOutputBuffer != nullptr)
        {
//            delete audioOutputBuffer->buffer().data();
//            audioOutputBuffer->setBuffer(data);
//            audioOutputBuffer->open(QIODevice::ReadOnly);
            audioOutputBuffer->seek(0);
            audioOutputBuffer->write(*data);
            audioOutputBuffer->seek(0);
        }
    }
    /// Calculate FFT
    /// Set the input array
    fft->setInputArray((int16_t*)data->data());
    fft->setInputArraySize(inputSize/sizeof(int16_t));
    fft->setOutputArraySize(inputSize/sizeof(int16_t));
    /// Run the transform
    fft->runTransform();
}
