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
#include "commandssender.h"
#include "udpmanager.h"
#include "receiveddatagramprocessor.h"
#include "audiosamplesplayer.h"
#include "commandreceiver.h"
#include "graphicsvisualizer.h"
#include "fftcalculator.h"
#include "complex.h"
#include "audiodevicelister.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    displayAudioInDevices();
    displayAudioOutDevices();

    pixmap = new QPixmap(ui->lB_visualization->width(), ui->lB_visualization->height());
    painter = new QPainter(pixmap);
    brush = new QBrush(QColor(255,255,255));
    pen = new QPen(QColor(255, 0, 255));
    painter->setBrush(*brush);
    painter->setPen(*pen);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete pixmap;
    delete fft;
    delete painter;
    delete brush;
    delete pen;
}

void MainWindow::paintEvent(QPaintEvent *)
{
//    if(redrawFlag == true)
//    {

//        double step = 1;//(double)(ui->lB_visualization->width() - 30)/(audioSamplesPlayer.getFFT()->getOutputArraySize()/2);
//        ui->lB_visualization->clear();
//        double maxVal = 0;
//        painter->setBrush(QBrush(QColor(255,255,255)));
//        painter->drawRect(0,0, ui->lB_visualization->width(), ui->lB_visualization->height());
//        painter->setBrush(*brush);
//        double coord = 15;
//        if(audioSamplesPlayer.getFFT()->getOutputArray() != nullptr)
//        {
//            for(uint32_t i=0; i<fft->getOutputArraySize()/2; i++)
//            {

//                Complex fftElement = audioSamplesPlayer.getFFT()->getOutputElement(i);
//                double  fftValue = fftElement.getMagnitude();
//                if(fftElement.getMagnitude() > maxVal)
//                    maxVal = fftValue;
//                coord += 1;
//                painter->drawRect(i, 0, step, 0.01*fftValue);
//            }
//        }
//        coord = (double)(ui->lB_visualization->width() - 30)/2;
//        int size = 1024;
//        if(audioSamplesPlayer.getFFT()->getInputArray() != nullptr)
//        {
//            for(uint32_t i=0; i<size/2; i++)
//            {
//                double  inputSample = audioSamplesPlayer.getFFT()->getInputArray()[i];

//                coord = coord + 1;
//                painter->drawRect(coord, 300, 1, 0.1*inputSample);
//            }
//        }

//        ui->lB_visualization->setPixmap(*pixmap);

//        redrawFlag = false;

//        delete[] fft->getOutputArray();
//        delete[] fft->getInputArray();
//        fft->setInputArray(nullptr);
//        fft->setOutputArray(nullptr);
//    }

}

void MainWindow::setAudioSamplesGetter(AudioSamplesGetter* o)
{
    this->audioGetter = o;
}

void MainWindow::setAudioSamplesSender(AudioSamplesSender* o)
{
    this->audioSender = o;
}

void MainWindow::setCommandSender(CommandsSender* o)
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
    this->cmdReceived = o;
}

void MainWindow::setGraphicVisualizer(GraphicsVisualizer* o)
{
    this->graphicVisualizer = o;
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

void MainWindow::connectSignals()
{
    /** Thread Objects inits **/
    connect(audioGetterThread, SIGNAL(started()), audioGetter, SLOT(init()));                                                                       /// Signal for audioGetter Initialization
    connect(audioReceiverThread, SIGNAL(started()), audioPlayer, SLOT(init()));                                                                     /// Signal for audioPlayer Initialization

    /** Audio Getter Thread **/
    connect(this, SIGNAL(setInputAudioDeviceSignal(QAudioInput*)), audioGetter, SLOT(setInputAudioDevice(QAudioInput*)));                           /// Signal for setting the Audio In device
    connect(audioSender, SIGNAL(emitSendSamplesSignal(UdpDatagram*)), udpManager, SLOT(sendData(UdpDatagram*)));  /// Signal for sending datagrams
    connect(this, SIGNAL(queryIfSamplingSignal()), audioGetter, SLOT(isSampling()));                                                                 /// Signal for querying if audioIn is playing
    connect(audioGetter, SIGNAL(isSamplingSignal(bool)), this, SLOT(audioGetterIsSampling(bool)));
    connect(this, SIGNAL(startSamplingSignal(bool)), audioGetter, SLOT(startSampling(bool)));                                                       /// Signal for sampling start
    connect(this, SIGNAL(setAudioOutputSignal(QAudioOutput*)), audioPlayer, SLOT(setAudioOutput(QAudioOutput*)));                                   /// Signal for setting audioOut for audioPlayer
    /** Udp Manager Thread **/
    connect(this, SIGNAL(initializeUdpSocket(QString,int)), udpManager, SLOT(initSocket(QString,int)));

    /** Audio Receiver Thread **/
    connect(udpManager, SIGNAL(emitDataReceived(UdpDatagram*)), datagramProc, SLOT(processDatagram(UdpDatagram*)));
    connect(this, SIGNAL(setAudioOutputSignal(QAudioOutput*)), audioPlayer, SLOT(setAudioOutput(QAudioOutput*)));
    connect(this, SIGNAL(queryIfPlayingSignal()), audioPlayer, SLOT(isMuted()));
    connect(audioPlayer, SIGNAL(isMutedSignal(bool)), this, SLOT(audioPlayerIsPlaying(bool)));
    connect(this, SIGNAL(startPlayingSignal(bool)), audioPlayer, SLOT(startPlaying(bool)));
}

void MainWindow::setFftCalculator(FftCalculator* fft)
{
    this->fft = fft;
}


void MainWindow::fftTest()
{
    static int cnt = 1;
    const int   size = 1024;
    int*     sampleArray = new int[size];
    fft->setInputArray(sampleArray);
    fft->setInputArraySize(size);
    fft->setOutputArraySize(fft->getInputArraySize());

    inputFreq = 10*cnt;
    generateTestSin(inputFreq, sampleArray, 0, 1, size);
    fft->runTransform();

    visualizeFFT();
    redrawFlag = true;
    drawingDelay(1000);
    if(cnt++ == 5)
        cnt = 1;
}

void MainWindow::visualizeFFT()
{
    update();
}



void MainWindow::drawingDelay(uint32_t time_ms)
{
    QTimer::singleShot((int)time_ms, this, SLOT(fftTest()));
}

void MainWindow::runFftTest()
{
    fftTest();
}

void MainWindow::generateTestSin(double freq, int* dataOut, double xStart, double xEnd, uint32_t sampleNumber)
{
    double omega = 2*M_PI*freq;
    double x = xStart;
    double interpolator = (xEnd - xStart)/sampleNumber;
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

void MainWindow::audioPlayerIsPlaying(bool signalFromThread)
{
    audioOutMuted = signalFromThread;
    if(signalFromThread)
    {
        ui->pB_startStopPlaying->setText("Stop Playing");
    }
    else
    {
        ui->pB_startStopPlaying->setText("Start Playing");
    }
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
    if(audioOutMuted)
    {
        emit startPlayingSignal(true);
        ui->pB_startStopPlaying->setText("Stop Playing");
    }
    else
    {
         emit startPlayingSignal(false);
         ui->pB_startStopPlaying->setText("Start Playing");
    }

    emit queryIfPlayingSignal();
}


void MainWindow::on_pB_connect_clicked()
{
    int port = ui->sB_udpPort->value();
    QString ip = ui->lE_peerIP->text();
    if(ip == "localhost")
        ip = "127.0.0.1";
    emit initializeUdpSocket(ip, port);
}
