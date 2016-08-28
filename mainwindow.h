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

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;

    AudioSamplesGetter*         audioGetter;
    AudioSamplesSender*         audioSender;
    CommandSender*              cmdSender;
    UdpManager*                 udpManager;
    ReceivedDatagramProcessor*  datagramProc;
    AudioSamplesPlayer*         audioPlayer;
    CommandReceiver*            cmdReceiver;
    GraphicsVisualizer*         graphicVisualizer;

    QThread*                    audioGetterThread;
    QThread*                    udpManagerThread;
    QThread*                    audioReceiverThread;
    QMutex*                     mutex;

    FftCalculator*  fft = nullptr;
    Complex*        fftOutArray;
    int             fftOutArraySize;
    QPixmap*        pixmap;
    QBrush*         brush;
    QPen*           pen;
    bool                        audioInSampling = false;
//    bool                        audioOutMuted   = true;

    void paintEvent(QPaintEvent *);
    void visualizeFFT();
    void drawingDelay(uint32_t time_ms);
    void drawScale(QPainter& painter, int windowWidth, int windowHeight, int sampleIndexMult);

    void generateTestSin(double freq, int *dataOut, double xStart, double xEnd, uint32_t dataOutNumber);
    void displayAudioInDevices();
    void displayAudioOutDevices();

private slots:

//    void fftTest();

    void on_pB_startStopSampling_clicked();

    void on_cb_inputAudioDevice_activated(const QString &arg1);

    void on_cB_outputAudioDevice_activated(const QString &arg1);

    void on_pB_startStopPlaying_clicked();

    void on_pB_connect_clicked();

    void on_hSlider_outputVolume_valueChanged(int value);

public:
    explicit MainWindow(QWidget *parent = 0);

    void setAudioSamplesGetter(AudioSamplesGetter* o);
    void setAudioSamplesSender(AudioSamplesSender* o);
    void setCommandSender(CommandSender* o);
    void setUdpManager(UdpManager* o);
    void setReceivedDatagramProcessor(ReceivedDatagramProcessor* o);
    void setAudioSamplesPlayer(AudioSamplesPlayer* o);
    void setCommandReceiver(CommandReceiver* o);
    void setGraphicVisualizer(GraphicsVisualizer* o);
    void setAudioSenderThread(QThread* o);
    void setUdpThread(QThread* o);
    void setAudioReceiverThread(QThread* o);
    void setMutex(QMutex* mutex);

    void connectSignals();
    void runFftTest();
    ~MainWindow();

public slots:
    void audioGetterIsSampling(bool signalFromThread);
//    void audioPlayerIsPlaying(bool signalFromThread);
    void setFftOutArray(Complex* array, int arraySize);
    void setFftCalculator(FftCalculator* fft);
    void updateConnectionStateButton();

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

};



#endif // MAINWINDOW_H
