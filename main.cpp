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


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    AudioSamplesGetter audioSamplesGetter;
    AudioSamplesSender audioSamplesSender;
    CommandsSender commandsSender;
    UdpManager udpManager;
    ReceivedDatagramProcessor receivedDataProc;
    AudioSamplesPlayer audioSamplesPlayer;
    CommandReceiver commandsReceiver;
    GraphicsVisualizer graphVisualizer;

    audioSamplesGetter.setAudioSamplesSender(&audioSamplesSender);
    audioSamplesSender.setUdpManager(&udpManager);
    commandsSender.setUdpManager(&udpManager);
    udpManager.setDatagramProc(&receivedDataProc);
    receivedDataProc.setAudioSamplesPlayer(&audioSamplesPlayer);
    receivedDataProc.setCommandReceiver(&commandsReceiver);
//    w.runFftTest();

    return a.exec();
}
