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
    this->muted = false;

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
        delete audioOutput;

    this->audioOutput = dev;
}

void AudioSamplesPlayer::startPlaying(bool value)
{
    if(this->audioOutputBuffer != nullptr)
        delete audioOutputBuffer;
    this->audioOutputBuffer = new QBuffer();
    this->audioOutputBuffer->open(QIODevice::WriteOnly);

    memset(audioOutputBuffer->buffer().data(), 0, audioOutputBuffer->size());

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
    int i = 0;
    uint16_t sample = 0;
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
            if((inputSize % 8192) == 0)
            {
                QMessageBox w;
                w.setIcon(QMessageBox::Icon::Warning);
                w.setText("FFT: Rozmiar wejścia nieprawidłowy: " + QString::number(inputSize));
                w.show();
                w.exec();
                return;
            }
        }

        if(audioOutputBuffer != nullptr)
        {
            delete audioOutputBuffer->buffer().data();
            audioOutputBuffer->setBuffer(data);
        }


        /// Calculate FFT
        /// Set the input array
        fft->setInputArray((int16_t*)data->data());
        fft->setInputArraySize(inputSize/sizeof(int16_t));
        fft->setOutputArraySize(inputSize/sizeof(int16_t));
        /// Run the transform
        fft->runTransform();
    }
}
