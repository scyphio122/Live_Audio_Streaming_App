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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    AudioSamplesGetter audioSamplesGetter;
    AudioSamplesSender audioSamplesSender;
    CommandsSender commandsSender;
    UdpManager udpManager;
    ReceivedDatagramProcessor receivedDataProc;
    AudioSamplesPlayer audioSamplesPlayer;
    CommandReceiver commandsReceiver;
    GraphicsVisualizer graphVisualizer;

    FftCalculator*  fft;
    QPixmap*        pixmap;
    QPainter*       painter;
    QBrush*         brush;
    QPen*           pen;
    double          inputFreq;
    volatile bool   redrawFlag = false;


    void paintEvent(QPaintEvent *);
    void visualizeFFT();
    void drawingDelay(uint32_t time_ms);
    void setFftCalculator(FftCalculator* fft);
    void generateTestSin(double freq, double* dataOut, double xStart, double xEnd, uint32_t dataOutNumber);
    void displayAudioInDevices();
    void displayAudioOutDevices();

private slots:

    void fftTest();

    void on_pB_startStopSampling_clicked();

    void on_cb_inputAudioDevice_activated(const QString &arg1);

    void on_cB_outputAudioDevice_activated(const QString &arg1);

    void on_pB_startStopPlaying_clicked();

public:
    explicit MainWindow(QWidget *parent = 0);
    void runFftTest();
    ~MainWindow();


};



#endif // MAINWINDOW_H
