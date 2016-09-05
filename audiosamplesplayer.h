#ifndef AUDIOSAMPLESRECEIVER_H
#define AUDIOSAMPLESRECEIVER_H

#include <datagramlistener.h>
#include <QtMultimedia/QAudioOutput>
#include <QBuffer>
#include "fftcalculator.h"
#include <boost/smart_ptr/scoped_ptr.hpp>
#include <QQueue>
#include <QTimer>
#include <abstractvisualization.h>

/**
 * @brief The AudioSamplesPlayer class - This class is used in order to play the samples which were received via UDP socket and set the input data for visualization (and optionally calculate FFT)
 */
class AudioSamplesPlayer : public DatagramListener
{
    Q_OBJECT

private:
    const int                           AUDIO_OUT_BUF_SIZE  =   2*8192;//8192*8-100;
    const int                           OUTPUT_QUEUE_SIZE   =   100;

    FftCalculator*                      fft                 =   nullptr;
    QBuffer*                            audioOutputBuffer   =   nullptr;
    QAudioOutput*                       audioOutput         =   nullptr;
    bool                                muted               =   true;
    bool                                isConnected         =   false;
    AbstractVisualization::InputType    inputType           =   AbstractVisualization::INPUT_FFT;

public:
    AudioSamplesPlayer();
    AudioSamplesPlayer(QObject* parent);
    ~AudioSamplesPlayer();

    /**
     * @brief getFFT - returns the pointer to the fftCalculator object
     * @return pointer to the fftCalculator object
     */
    FftCalculator* getFFT();

    /**
     * @brief onDataReceived - this function is called every time when packet with audio samples is received. It plays the sound and calculates its FFT
     * @param data[in] - data(audio samples) sent by udp packet
     * @param senderIP[in] - IP of the device which sent the packet
     */
    void onDataReceived(QByteArray *data, QHostAddress& senderIP);

    /**
     * @brief getInputArraySize - This function returns the size of the audio samples array
     * @return size of audio samples array size
     */
    int getInputArraySize() {return AUDIO_OUT_BUF_SIZE;}

public slots:
    /**
     * @brief init - This function initializes the module. It creates the fftCakculator object and an buffer for its output
     */
    void init();

    /**
     * @brief setAudioOutput - this function sets the audioOutput which will service playing of the incomingsound
     * @param dev - pointer to the QAudioOutput device
     */
    void setAudioOutput(QAudioOutput* dev);

    /**
     * @brief startPlaying - This method is called in order to start playing the sound
     * @param value[in] true if start, false if stop
     */
    void startPlaying(bool value);

    /**
     * @brief isMuted - this function returns the state of the mute
     * @return  true if muted, false if not
     */
    bool isMuted();

    /**
     * @brief changeVolume - This function changes the volume value
     * @param volumePercentage - value of volume
     */
    void changeVolume(int volumePercentage);

    /**
     * @brief changeConnectionState - This functions changes the internal state of UDP connection for this module
     * @param state - true if connected
     */
    void changeConnectionState(bool state);

    /**
     * @brief on_VisualizationChange - This function services the visualization change event from the point of delivering the input array for visualizations
     * @param inputType[in] -  INPUT_FFT or INPUT_SAMPLES
     */
    void on_VisualizationChange(int inputType);
signals:
    void isMutedSignal(bool value);                 /*< This signal is emitted to inform whether audio output is muted */
    void sendFft(FftCalculator* fft);               /*< This signal is emitted to set FFT output array as input for visualization */
    void sendSamplesSignal(int16_t* samplesArray);  /*< This signal is emitted to set audio samples array as input for visualization */
    void redrawGUI();                               /*< This signal is emitted in order to force GUI redrawing */
};

#endif // AUDIOSAMPLESRECEIVER_H
