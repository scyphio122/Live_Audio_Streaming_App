#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "audiosamplesgetter.h"
#include "audiosamplessender.h"
#include "commandsender.h"
#include "udpmanager.h"
#include "receiveddatagramprocessor.h"
#include "audiosamplesplayer.h"
#include "commandreceiver.h"
#include "graphicsvisualizer.h"
#include "fftcalculator.h"
#include "audiosamplesgetter.h"
#include "audiosamplessender.h"
#include "commandsender.h"
#include "udpmanager.h"
#include "receiveddatagramprocessor.h"
#include "audiosamplesplayer.h"
#include "commandreceiver.h"
#include "graphicsvisualizer.h"
#include "fftcalculator.h"
#include "complex.h"
#include "audiodevicelister.h"
#include <QThread>
#include <QMutex>


namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class - This is the main GUI class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;

    AudioSamplesGetter*         audioGetter;
    AudioSamplesSender*         audioSender;
    AudioSamplesPlayer*         audioPlayer;
    CommandSender*              cmdSender;
    UdpManager*                 udpManager;
    ReceivedDatagramProcessor*  datagramProc;
    CommandReceiver*            cmdReceiver;
    GraphicsVisualizer*         graphicVisualizer;

    QThread*                    audioGetterThread;
    QThread*                    udpManagerThread;
    QThread*                    audioReceiverThread;
    QMutex                      mutex;

    FftCalculator*  fft = nullptr;
    Complex*        fftOutArray = nullptr;
    int16_t*        inputSamplesArray = nullptr;
    int             fftOutArraySize;
    QPixmap*        pixmap;
    QBrush*         brush;
    QPen*           pen;
    bool                        audioInSampling = false;
    bool            repaintFlag = true;


    /**
     * @brief paintEvent - function which is called every time GUI needs to be redrawen.
     */
    void paintEvent(QPaintEvent *);


    /**
     * @brief displayAudioInDevices - This function lists all of the available audio input devices on the cb_inputAudioDevice
     */
    void displayAudioInDevices();

    /**
     * @brief displayAudioOutDevices - This function lists all of the available audio output devices on the cb_outputAudioDevice
     */
    void displayAudioOutDevices();

private slots:

    /**
     * @brief on_pB_startStopSampling_clicked - handler of the press event for pB_startStopSampling
     */
    void on_pB_startStopSampling_clicked();

    /**
     * @brief on_cb_inputAudioDevice_activated - handler for the activation of cb_inputAudioDevice
     * @param arg1
     */
    void on_cb_inputAudioDevice_activated(const QString &arg1);

    /**
     * @brief on_cB_outputAudioDevice_activated - handler for the activation of cb_outputAudioDevice
     * @param arg1
     */
    void on_cB_outputAudioDevice_activated(const QString &arg1);

    /**
     * @brief on_pB_startStopPlaying_clicked - handler for pressing pB_startStopPlaying
     */
    void on_pB_startStopPlaying_clicked();

    /**
     * @brief on_pB_connect_clicked - handler for pressing pB_connectButton
     */
    void on_pB_connect_clicked();

    /**
     * @brief on_hSlider_outputVolume_valueChanged - handler for changing the position of the volume slider
     * @param value
     */
    void on_hSlider_outputVolume_valueChanged(int value);

    /**
     * @brief on_cB_Visualization_currentIndexChanged - handler for the activation of the visualization combo box
     * @param index
     */
    void on_cB_Visualization_currentIndexChanged(int index);

    /**
     * @brief updateGUI - function which forces GUI redrawing
     */
    void updateGUI();

public:
    explicit MainWindow(QWidget *parent = 0);

    /**
     * @brief setAudioSamplesGetter
     * @param o
     */
    void setAudioSamplesGetter(AudioSamplesGetter* o);

    /**
     * @brief setAudioSamplesSender
     * @param o
     */
    void setAudioSamplesSender(AudioSamplesSender* o);

    /**
     * @brief setCommandSender
     * @param o
     */
    void setCommandSender(CommandSender* o);

    /**
     * @brief setUdpManager
     * @param o
     */
    void setUdpManager(UdpManager* o);

    /**
     * @brief setReceivedDatagramProcessor
     * @param o
     */
    void setReceivedDatagramProcessor(ReceivedDatagramProcessor* o);

    /**
     * @brief setAudioSamplesPlayer
     * @param o
     */
    void setAudioSamplesPlayer(AudioSamplesPlayer* o);

    /**
     * @brief setCommandReceiver
     * @param o
     */
    void setCommandReceiver(CommandReceiver* o);

    /**
     * @brief setGraphicVisualizer
     * @param o
     */
    void setGraphicVisualizer(GraphicsVisualizer* o);

    /**
     * @brief setAudioSenderThread
     * @param o
     */
    void setAudioSenderThread(QThread* o);

    /**
     * @brief setUdpThread
     * @param o
     */
    void setUdpThread(QThread* o);

    /**
     * @brief setAudioReceiverThread
     * @param o
     */
    void setAudioReceiverThread(QThread* o);

    /**
     * @brief setMutex
     * @param mutex
     */
    void setMutex(QMutex* mutex);

    /**
     * @brief connectSignals - This function connects signals between all of the threads
     */
    void connectSignals();


    ~MainWindow();

public slots:
    /**
     * @brief audioGetterIsSampling - This method changes the text on connect button and sets the internal variable
     * @param signalFromThread[in] - true is is sampling
     */
    void audioGetterIsSampling(bool signalFromThread);

    /**
     * @brief setFftOutArray - This is setter for FFT array
     * @param array[in] - pointer to FFT out array
     * @param arraySize[in] - FFT out array size
     */
    void setFftOutArray(Complex* array, int arraySize);

    /**
     * @brief setFftCalculator - setter for FFT calculator
     * @param fft[in]
     */
    void setFftCalculator(FftCalculator* fft);

    /**
     * @brief ManageConnectionRequest - This method shows the connection dialog when the remote connection request occured
     * @param senderIP[in] - IP of the connection requester
     */
    void ManageConnectionRequest(QString senderIP);

    /**
     * @brief updateConnectButton - This function changes the text on connection button depending on the connection state
     * @param isConnected[in] - true if is connected
     */
    void updateConnectButton(bool isConnected);

    /**
     * @brief onDisconnect - This is disconnect event handler
     */
    void onDisconnect();

    /**
     * @brief setAudioSamplesArray - This is setter for input sampler array
     * @param array[in]
     */
    void setAudioSamplesArray(int16_t* array);

signals:
    void setInputAudioDeviceSignal(QAudioInput* newAudioInputDev);
    void setAudioOutputSignal(QAudioOutput *dev);
    void queryIfSamplingSignal();
    void queryIfPlayingSignal();
    void startSamplingSignal(bool value);
    void startPlayingSignal(bool value);
    void tryToConnect(QString ip, int port);
    void fftEnable(bool value);
    void finished();
    void changeOutputVolume(int);
    void udpConnectionEstablished(bool);
    void connectionUpdatedSignal(bool);
    void disconnectSignal();
};



#endif // MAINWINDOW_H
