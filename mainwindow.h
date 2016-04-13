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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    AudioSamplesGetter audioSamplesGetter;
    AudioSamplesSender audioSamplesSender;
    CommandsSender commandsSender;
    UdpManager udpManager;
    ReceivedDatagramProcessor receivedDataProc;
    AudioSamplesPlayer audioSamplesPlayer;
    CommandReceiver commandsReceiver;
    GraphicsVisualizer graphVisualizer;


    void displayAudioInDevices();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pB_startStopSampling_clicked();

    void on_cb_inputAudioDevice_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
