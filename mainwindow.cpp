#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "audiosamplesgetter.h"
#include "audiosamplessender.h"
#include "commandssender.h"
#include "udpmanager.h"
#include "receiveddatagramprocessor.h"
#include "audiosamplesplayer.h"
#include "commandreceiver.h"
#include "graphicsvisualizer.h"
#include <QList>
#include <QAudioDeviceInfo>
#include <QString>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    audioSamplesGetter.setAudioSamplesSender(&audioSamplesSender);
    audioSamplesSender.setUdpManager(&udpManager);
    commandsSender.setUdpManager(&udpManager);
    udpManager.setDatagramProc(&receivedDataProc);

    displayAudioInDevices();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAudioInDevices()
{
    QList<QAudioDeviceInfo> audioInDev = this->audioSamplesGetter.listAvailableDevicesIn();
    int listSize = audioInDev.size();

    ui->cb_inputAudioDevice->clear();
    for(int i=0; i < listSize; i++)
    {
        QString devName = audioInDev[i].deviceName();
        ui->cb_inputAudioDevice->addItem(devName);
    }
}

void MainWindow::on_pB_startStopSampling_clicked()
{
    if(!audioSamplesGetter.isPlaying())
    {
        audioSamplesGetter.startSampling();
        ui->pB_startStopSampling->setText("Stop Playing");
    }
    else
    {
         audioSamplesGetter.stopSampling();
         ui->pB_startStopSampling->setText("Start Playing");
    }
}

void MainWindow::on_cb_inputAudioDevice_activated(const QString &arg1)
{
    audioSamplesGetter.audioMixerDeviceInit(arg1.toStdString());
    ui->pB_startStopSampling->setEnabled(true);
}
