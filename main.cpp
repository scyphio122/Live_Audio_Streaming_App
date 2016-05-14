#include "mainwindow.h"
#include <QApplication>
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
#include <QObject>
#include <QMutex>


int main(int argc, char *argv[])
{
//    QMutex  guiMutex;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /// Create objects
    AudioSamplesGetter audioSamplesGetter;
    AudioSamplesSender audioSamplesSender(&audioSamplesGetter);

    UdpManager udpManager;

    ReceivedDatagramProcessor receivedDataProc;
    AudioSamplesPlayer audioSamplesPlayer(&receivedDataProc);
    CommandReceiver commandsReceiver(&receivedDataProc);;

    CommandsSender commandsSender;
    GraphicsVisualizer graphVisualizer;

    /// Set inter-object dependencies
    audioSamplesGetter.setAudioSamplesSender(&audioSamplesSender);
    audioSamplesSender.setUdpManager(&udpManager);
    commandsSender.setUdpManager(&udpManager);
    udpManager.setDatagramProc(&receivedDataProc);
    receivedDataProc.setAudioSamplesPlayer(&audioSamplesPlayer);
    receivedDataProc.setCommandReceiver(&commandsReceiver);

//    w.setMutex(&guiMutex);
//    audioSamplesPlayer.getFFT()->setMutex(&guiMutex);

    /// Set the pointers in the mainwindow, to connect signals
    w.setAudioSamplesGetter(&audioSamplesGetter);
    w.setAudioSamplesSender(&audioSamplesSender);
    w.setCommandSender(&commandsSender);
    w.setUdpManager(&udpManager);
    w.setReceivedDatagramProcessor(&receivedDataProc);
    w.setAudioSamplesPlayer(&audioSamplesPlayer);
    w.setCommandReceiver(&commandsReceiver);
    w.setGraphicVisualizer(&graphVisualizer);

    /// Create threads
    QThread samplesGetterThread;
    QThread udpMangerThread;
    QThread samplesReceivedThread;

    /// Push objects into the threads
    audioSamplesGetter.moveToThread(&samplesGetterThread);
    udpManager.moveToThread(&udpMangerThread);
    receivedDataProc.moveToThread(&samplesReceivedThread);

    /// Set pointer to the threads
    w.setAudioSenderThread(&samplesGetterThread);
    w.setUdpThread(&udpMangerThread);
    w.setAudioReceiverThread(&samplesReceivedThread);

    /// Connect signals between threads
    w.connectSignals();

    /// Start threads
    samplesGetterThread.start();
    udpMangerThread.start();
    samplesReceivedThread.start();


    /// Start threds
    return a.exec();
}
