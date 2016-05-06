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
    pen = new QPen(QColor(255, 0, 0));
    painter->setBrush(*brush);
    painter->setPen(*pen);

    fftOutArray = nullptr;

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
    if(fft != nullptr)
    {
        ui->lB_visualization->clear();
        double maxVal = 0;
        painter->setBrush(QBrush(QColor(0,0,0)));
        int windowWidth = ui->lB_visualization->width();
        int windowHeight = ui->lB_visualization->height();
        painter->drawRect(0,0, windowWidth, windowHeight);
        painter->setBrush(*brush);
        int coord = 1;

        /// Draw the pixmap
        if(fftOutArray != nullptr)
        {
            for(uint32_t i=0; i<fftOutArraySize; i++)
            {
                if(i >= windowWidth)
                    break;
                Complex fftElement = fftOutArray[i];
                double  fftValue = fftElement.getMagnitude();
                if(fftElement.getMagnitude() > maxVal)
                    maxVal = fftValue;
                painter->drawLine(i+coord, 0, i+coord, 0.01*fftValue);
            }
            /// Enable the fft calculator
            emit fftEnable(true);
        }
//            uint32_t inputArraySize = fft->getInputArraySize();
//            int offset = windowHeight/2;
//            int16_t* ptr = fft->getInputArray();
//            if(ptr != nullptr)
//                for(uint32_t i=0; i<inputArraySize; i++)
//                {
//                    painter->drawLine(i+coord, offset, i+coord, offset + 0.05*ptr[i]);
//                }


            ui->lB_visualization->setPixmap(*pixmap);
    }
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
    connect(audioPlayer, SIGNAL(sendFft(FftCalculator*)), this, SLOT(setFftCalculator(FftCalculator*)));

}

void MainWindow::setFftCalculator(FftCalculator* fft)
{
    this->fft = fft;
    connect(fft, SIGNAL(fftCompleted(Complex*,int)), this, SLOT(setFftOutArray(Complex*,int)));
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

void MainWindow::setFftOutArray(Complex *array, int arraySize)
{
    this->fftOutArray = array;
    this->fftOutArraySize = arraySize;
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
        guiRefreshTimer = new QTimer();
        connect(guiRefreshTimer, SIGNAL(timeout()), this, SLOT(repaint()));
        guiRefreshTimer->start(10);
    }
    else
    {
         emit startSamplingSignal(false);
         ui->pB_startStopSampling->setText("Start Sampling");
         if(guiRefreshTimer != nullptr)
         {
             guiRefreshTimer->stop();
             delete guiRefreshTimer;
             guiRefreshTimer = nullptr;
         }
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
