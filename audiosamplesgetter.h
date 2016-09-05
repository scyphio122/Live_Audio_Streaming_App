#ifndef AUDIOSAMPLESGETTER_H
#define AUDIOSAMPLESGETTER_H

#include <QtMultimedia/QAudioInput>
#include <QtMultimedia/QAudioOutput>
#include <QBuffer>
#include "audiosamplessender.h"
#include <QQueue>


class AudioSamplesSender;

/**
 * @brief The AudioSamplesGetter class - This class is used to gather audio samples from audio input device and send them via audioSender and UDP socket to the client
 */
class AudioSamplesGetter : public QObject
{
    Q_OBJECT

private:
    const int                                   INPUT_QUEUE_SIZE        = 20;
    const int                                   INPUT_QUEUE_WATERMARK   = 10;
    AudioSamplesSender*                         audioSender             = nullptr;
    QAudioInput*                                audioInDevice           = nullptr;
    QBuffer*                                    capturingStream         = nullptr;
    QByteArray*                                 inputDataBuffer         = nullptr;
    bool                                        isMuted;
    bool                                        echoSound;
    bool                                        isCurrentlySampling;


public slots:
    /**
     * @brief init - This function initializes the buffers where the samples are to be stored
     */
    void init();

    /**
     * @brief setInputAudioDevice - This function sets the QAudioInputDevice
     * @param newAudioInputDev[in] - pointer to the QAudioInput object which will gather samples from the audio input
     */
    void setInputAudioDevice(QAudioInput* newAudioInputDev);

    /**
     * @brief onSamplesCaptured - This is event function, which is called when audioInput object fills entire buffer if audio samples
     */
    void onSamplesCaptured();

    /**
     * @brief setMuteEnabled- this function mutes/unmutes the audio input
     * @param isMuted[in] - value of mute to be set
     */
    void setMuteEnabled(bool isMuted);


    /**
     * @brief startSampling  This function is called in order to start/pause sampling of audio samples
     * @param value[in] - The bool value of sampling
     */
    void startSampling(bool value);

    /**
     * @brief isSampling - This function checks whether the audio samples are currently gathered. The output is sent via signal to other threads
     */
    void isSampling();

    /**
     * @brief connectDeviceWithBuf - this function sonnects th ebuffer readyRead signal with the onSamplesCaptured function
     */
    void connectDeviceWithBuf();
public:
    const static int                            AUDIO_IN_BUFFER_SIZE = 2*8192;//8192*8 - 100;

    AudioSamplesGetter();
    ~AudioSamplesGetter();

    /**
     * @brief setAudioSamplesSender - This function sets the audioSender device which is used as a middleman between audio samples gathering and sending them via UDP
     * @param newAudioSamplesSender[in] - pointer to the audioSender device
     */
    void setAudioSamplesSender(AudioSamplesSender* newAudioSamplesSender);



signals:
    void isSamplingSignal(bool isSampling); /*< Signal used to inform other threads whether audio sampling is on or off **/

};

#endif // AUDIOSAMPLESGETTER_H
