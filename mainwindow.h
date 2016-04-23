#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "audiosamplesgetter.h"
#include "audiosamplessender.h"
#include "commandssender.h"
#include "udpmanager.h"
#include "receiveddatagramprocessor.h"
#include "audiosamplesplayer.h"
#include "commandreceiver.h"
#include "graphicsvisualizer.h"
#include "fftcalculator.h"
#include "audiosamplesgetter.h"
#include "audiosamplessender.h"
#include "commandssender.h"
#include "udpmanager.h"
#include "receiveddatagramprocessor.h"
#include "audiosamplesplayer.h"
#include "commandreceiver.h"
#include "graphicsvisualizer.h"
#include "fftcalculator.h"
#include "complex.h"
#include "audiodevicelister.h"
#include <QThread>


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
    CommandsSender*             cmdSender;
    UdpManager*                 udpManager;
    ReceivedDatagramProcessor*  datagramProc;
    AudioSamplesPlayer*         audioPlayer;
    CommandReceiver*            cmdReceived;
    GraphicsVisualizer*         graphicVisualizer;

    QThread*                    audioGetterThread;
    QThread*                    udpManagerThread;
    QThread*                    audioReceiverThread;

    FftCalculator*  fft;
    QPixmap*        pixmap;
    QPainter*       painter;
    QBrush*         brush;
    QPen*           pen;
    double          inputFreq;
    volatile bool   redrawFlag = false;

    bool                        audioInSampling = false;

    void paintEvent(QPaintEvent *);
    void visualizeFFT();
    void drawingDelay(uint32_t time_ms);
    void setFftCalculator(FftCalculator* fft);
    void generateTestSin(double freq, int *dataOut, double xStart, double xEnd, uint32_t dataOutNumber);
    void displayAudioInDevices();
    void displayAudioOutDevices();
    bool audioGetterIsPlaying(bool* signalFromThread);
private slots:

    void fftTest();

    void on_pB_startStopSampling_clicked();

    void on_cb_inputAudioDevice_activated(const QString &arg1);

    void on_cB_outputAudioDevice_activated(const QString &arg1);

    void on_pB_startStopPlaying_clicked();

public:
    explicit MainWindow(QWidget *parent = 0);

    void setAudioSamplesGetter(AudioSamplesGetter* o);
    void setAudioSamplesSender(AudioSamplesSender* o);
    void setCommandSender(CommandsSender* o);
    void setUdpManager(UdpManager* o);
    void setReceivedDatagramProcessor(ReceivedDatagramProcessor* o);
    void setAudioSamplesPlayer(AudioSamplesPlayer* o);
    void setCommandReceiver(CommandReceiver* o);
    void setGraphicVisualizer(GraphicsVisualizer* o);
    void setAudioSenderThread(QThread* o);
    void setUdpThread(QThread* o);
    void setAudioReceiverThread(QThread* o);
    void connectSignals();
    void runFftTest();
    ~MainWindow();

signals:
    void setInputAudioDeviceSignal(QAudioInput* newAudioInputDev);
    void queryIfPlayingSignal();
    void startPlayingSignal(bool value);

};



#endif // MAINWINDOW_H
