#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <QAudioDeviceInfo>
#include <QString>
#include <QTimer>
#include <QPainter>
#include <QPixmap>
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
#include <cfloat>
#include <connectdialog.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    displayAudioInDevices();
    displayAudioOutDevices();

    pixmap = new QPixmap(ui->lB_visualization->width(), ui->lB_visualization->height());
    brush = new QBrush(QColor(255,255,255));
    pen = new QPen(QColor(255,127, 39));
    fftOutArray = nullptr;
}

MainWindow::~MainWindow()
{
    emit finished();

    delete ui;
    delete pixmap;
    delete fft;
    delete brush;
    delete pen;
}

void MainWindow::connectSignals()
{
    /** Thread Objects inits **/
    connect(audioGetterThread, SIGNAL(started()), audioGetter, SLOT(init()));                                                                       /// Signal for audioGetter Initialization
    connect(audioReceiverThread, SIGNAL(started()), audioPlayer, SLOT(init()));                                                                     /// Signal for audioPlayer Initialization

    /// Cleanup code
    connect(this, SIGNAL(finished()), audioGetterThread, SLOT(deleteLater()));
    connect(this, SIGNAL(finished()), audioReceiverThread, SLOT(deleteLater()));
    connect(this, SIGNAL(finished()), udpManagerThread, SLOT(deleteLater()));

    /** Audio Getter Thread **/
    connect(this, SIGNAL(setInputAudioDeviceSignal(QAudioInput*)), audioGetter, SLOT(setInputAudioDevice(QAudioInput*)));                           /// Signal for setting the Audio In device
    connect(audioSender, SIGNAL(emitSendSamplesSignal(UdpDatagram*)), udpManager, SLOT(sendData(UdpDatagram*)));  /// Signal for sending datagrams
    connect(this, SIGNAL(queryIfSamplingSignal()), audioGetter, SLOT(isSampling()));                                                                 /// Signal for querying if audioIn is playing
    connect(audioGetter, SIGNAL(isSamplingSignal(bool)), this, SLOT(audioGetterIsSampling(bool)));
    connect(this, SIGNAL(startSamplingSignal(bool)), audioGetter, SLOT(startSampling(bool)));                                                       /// Signal for sampling start
    connect(this, SIGNAL(setAudioOutputSignal(QAudioOutput*)), audioPlayer, SLOT(setAudioOutput(QAudioOutput*)));


    /** Udp Thread **/
    connect(this, SIGNAL(tryToConnect(QString,int)), cmdSender, SLOT(sendConnectionRequest(QString,int)));
    connect(cmdSender, SIGNAL(sendCommandSignal(UdpDatagram*)), udpManager, SLOT(sendCmd(UdpDatagram*)));
    connect(cmdSender, SIGNAL(connectionEstablishSignal(QString,int)), udpManager, SLOT(connectUDP(QString,int)));
    connect(cmdReceiver, SIGNAL(connectionEstablishSignal(QString,int)), udpManager, SLOT(connectUDP(QString,int)));
    /** Audio Receiver Thread **/
    connect(udpManager, SIGNAL(emitDataReceived(UdpDatagram*)), datagramProc, SLOT(processDatagram(UdpDatagram*)));
//    connect(this, SIGNAL(setAudioOutputSignal(QAudioOutput*)), audioPlayer, SLOT(setAudioOutput(QAudioOutput*)));
    connect(this, SIGNAL(queryIfPlayingSignal()), audioPlayer, SLOT(isMuted()));
//    connect(audioPlayer, SIGNAL(isMutedSignal(bool)), this, SLOT(audioPlayerIsPlaying(bool)));
    connect(this, SIGNAL(startPlayingSignal(bool)), audioPlayer, SLOT(startPlaying(bool)));
    connect(audioPlayer, SIGNAL(sendFft(FftCalculator*)), this, SLOT(setFftCalculator(FftCalculator*)));
    connect(this, SIGNAL(changeOutputVolume(int)), audioPlayer, SLOT(changeVolume(int)));
    /** Command Receiver **/
    connect(cmdReceiver, SIGNAL(connectionRequestSignal()), this, SLOT(updateConnectionStateButton()));
    connect(this, SIGNAL(connectionUpdatedSignal(bool)), cmdReceiver, SLOT(connectionUpdateGUICallback(bool)));
}

void MainWindow::setMutex(QMutex* mutex)
{
    this->mutex = mutex;
}

void MainWindow::updateConnectionStateButton()
{
    ConnectDialog connectDialog;

    int retval = connectDialog.exec();
    if(retval == QDialog::Accepted)
    {
        ui->pB_connect->setText("Disconnect");

        emit connectionUpdatedSignal(true);
    }
    else
    if(retval == QDialog::Rejected)
    {
        ui->pB_connect->setText("Connect");
        emit connectionUpdatedSignal(false);
    }

}


void MainWindow::paintEvent(QPaintEvent *)
{
    /// Draw the pixmap
    if(fft != nullptr)
    {
        if(fftOutArray != nullptr && fft->getFftEnable() == false)
        {
            QPainter painter;
            painter.begin(pixmap);
            painter.setPen(*pen);

            int windowWidth = ui->lB_visualization->width();
            int windowHeight = ui->lB_visualization->height();

            painter.setBrush(QBrush(QColor(0,0,0)));
            painter.drawRect(0,0, windowWidth, windowHeight);

            /// Draw the frame
            graphicVisualizer->draw(fftOutArray, fftOutArraySize, painter, windowHeight, windowWidth);


            ui->lB_visualization->setPixmap(*pixmap);
            /// Enable the fft calculator
            emit fftEnable(true);

            delete[] fftOutArray;
            fftOutArray = nullptr;

        }
    }
}

void MainWindow::setFftCalculator(FftCalculator* fft)
{
    this->fft = fft;
    connect(fft, SIGNAL(fftCompleted(Complex*,int)), this, SLOT(setFftOutArray(Complex*,int)));
    connect(fft, SIGNAL(repaintGUI()), this, SLOT(repaint()));
    connect(this, SIGNAL(fftEnable(bool)), fft, SLOT(fftEnable(bool)));

}


void MainWindow::visualizeFFT()
{
    update();
}



void MainWindow::generateTestSin(double freq, int* dataOut, double xStart, double xEnd, uint32_t sampleNumber)
{
    double omega = 2*M_PI*freq;
    double x = xStart;
    double interpolator = (xEnd - xStart)/(double)sampleNumber;
    for(uint32_t i=0; i<sampleNumber; i++)
    {
        dataOut[i] = (sin(omega*x));//+0.2*sin(10*omega*x))*0.2*sin(15*omega*x);
        x += interpolator;
    }
}


void MainWindow::displayAudioInDevices()
{
    QList<QAudioDeviceInfo> audioInDev = AudioDeviceLister::listAvailableDevicesIn();
    int listSize = audioInDev.size();

    ui->cb_inputAudioDevice->clear();
    for(int i=0; i < listSize; i++)
    {
        QString devName = audioInDev[i].deviceName();
        ui->cb_inputAudioDevice->addItem(devName);
    }
}

void MainWindow::displayAudioOutDevices()
{
    QList<QAudioDeviceInfo> audioOutDev = AudioDeviceLister::listAvailableDevicesOut();
    int listSize = audioOutDev.size();

    ui->cB_outputAudioDevice->clear();
    for(int i=0; i < listSize; i++)
    {
        QString devName = audioOutDev[i].deviceName();
        ui->cB_outputAudioDevice->addItem(devName);
    }
}


void MainWindow::audioGetterIsSampling(bool signalFromThread)
{
    audioInSampling = signalFromThread;
    if(signalFromThread)
    {
        ui->pB_startStopSampling->setText("Stop Sampling");
    }
    else
    {
        ui->pB_startStopSampling->setText("Start Sampling");
    }

}

//void MainWindow::audioPlayerIsPlaying(bool signalFromThread)
//{
//    audioOutMuted = signalFromThread;
//    if(signalFromThread)
//    {
//        ui->pB_startStopPlaying->setText("Stop Playing");
//    }
//    else
//    {
//        ui->pB_startStopPlaying->setText("Start Playing");
//    }
//}

void MainWindow::setFftOutArray(Complex *array, int arraySize)
{
    this->fftOutArray = array;
    this->fftOutArraySize = arraySize;
    repaint();
}

void MainWindow::on_cb_inputAudioDevice_activated(const QString &arg1)
{
    QAudioDeviceInfo dev = AudioDeviceLister::listAudioDevices(arg1.toStdString(), QAudio::AudioInput);
    /// Send signal to the Audio Getter Thread
    emit setInputAudioDeviceSignal(new QAudioInput(dev, AudioDeviceLister::getFormat(dev, "audio/pcm")));
    ui->pB_startStopSampling->setEnabled(true);
}


void MainWindow::on_pB_startStopSampling_clicked()
{
    if(!audioInSampling)
    {
        emit startSamplingSignal(true);
        ui->pB_startStopSampling->setText("Stop Sampling");
    }
    else
    {
         emit startSamplingSignal(false);
         ui->pB_startStopSampling->setText("Start Sampling");
    }

    /// Query the audioGetter To update the current state of audioPlayer
    emit queryIfSamplingSignal();
}

void MainWindow::on_cB_outputAudioDevice_activated(const QString &arg1)
{
    QAudioDeviceInfo dev = AudioDeviceLister::listAudioDevices(arg1.toStdString(), QAudio::AudioOutput);
    emit setAudioOutputSignal(new QAudioOutput(dev, AudioDeviceLister::getFormat(dev, "audio/pcm")));
    ui->pB_startStopPlaying->setEnabled(true);
}

void MainWindow::on_pB_startStopPlaying_clicked()
{
    if(audioPlayer->isMuted())
    {
        ui->pB_startStopPlaying->setText("Stop Playing");
        emit startPlayingSignal(true);

    }
    else
    {
        ui->pB_startStopPlaying->setText("Start Playing");
        emit startPlayingSignal(false);
    }

    emit queryIfPlayingSignal();
}


void MainWindow::on_pB_connect_clicked()
{
    int port = ui->sB_udpPort->value();
    QString ip = ui->lE_peerIP->text();
    if(ip == "localhost")
        ip = "127.0.0.1";

    emit tryToConnect(ip, port);
}

void MainWindow::on_hSlider_outputVolume_valueChanged(int value)
{
    emit changeOutputVolume(value);
}

void MainWindow::setAudioSamplesGetter(AudioSamplesGetter* o)
{
    this->audioGetter = o;
}

void MainWindow::setAudioSamplesSender(AudioSamplesSender* o)
{
    this->audioSender = o;
}

void MainWindow::setCommandSender(CommandSender *o)
{
    this->cmdSender = o;
}

void MainWindow::setUdpManager(UdpManager* o)
{
    this->udpManager = o;
}

void MainWindow::setReceivedDatagramProcessor(ReceivedDatagramProcessor* o)
{
    this->datagramProc = o;
}

void MainWindow::setAudioSamplesPlayer(AudioSamplesPlayer* o)
{
    this->audioPlayer = o;
}

void MainWindow::setCommandReceiver(CommandReceiver* o)
{
    this->cmdReceiver = o;
}

void MainWindow::setGraphicVisualizer(GraphicsVisualizer* o)
{
    this->graphicVisualizer = o;
    graphicVisualizer->fftBars.setWindowHeight(ui->lB_visualization->height());
    graphicVisualizer->fftBars.setWindowWidth(ui->lB_visualization->width());
    graphicVisualizer->fftBars.calcOffset();
}

void MainWindow::setAudioSenderThread(QThread* o)
{
 this->audioGetterThread = o;
}

void MainWindow::setUdpThread(QThread* o)
{
    this->udpManagerThread = o;
}

void MainWindow::setAudioReceiverThread(QThread* o)
{
    this->audioReceiverThread = o;
}
