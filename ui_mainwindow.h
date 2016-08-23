/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *gB_inputAudioDevice;
    QComboBox *cb_inputAudioDevice;
    QPushButton *pB_startStopSampling;
    QGroupBox *gB_outputAudioDevice;
    QComboBox *cB_outputAudioDevice;
    QPushButton *pB_startStopPlaying;
    QSlider *hSlider_outputVolume;
    QLabel *label;
    QGroupBox *gB_visualization;
    QLabel *lB_visualization;
    QGroupBox *gB_networkSettings;
    QLabel *lb_peerIP;
    QLineEdit *lE_peerIP;
    QLabel *lb_peerPort;
    QSpinBox *sB_udpPort;
    QPushButton *pB_connect;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1253, 790);
        MainWindow->setMinimumSize(QSize(1253, 790));
        MainWindow->setMaximumSize(QSize(1253, 790));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QLatin1String("#MainWindow {\n"
"background-color: rgb(49, 49, 49);\n"
"}\n"
"\n"
""));
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gB_inputAudioDevice = new QGroupBox(centralWidget);
        gB_inputAudioDevice->setObjectName(QStringLiteral("gB_inputAudioDevice"));
        gB_inputAudioDevice->setGeometry(QRect(10, 20, 431, 71));
        gB_inputAudioDevice->setStyleSheet(QLatin1String("QGroupBox {\n"
"    text-align: left; /* align the text to the left */\n"
"	color:rgb(255,127,39);\n"
"    padding-left: 5px;\n"
"	border-color: rgba(85,85,85,200);\n"
"    border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius:5px;\n"
"}"));
        gB_inputAudioDevice->setFlat(false);
        cb_inputAudioDevice = new QComboBox(gB_inputAudioDevice);
        cb_inputAudioDevice->setObjectName(QStringLiteral("cb_inputAudioDevice"));
        cb_inputAudioDevice->setGeometry(QRect(20, 30, 301, 22));
        cb_inputAudioDevice->setStyleSheet(QLatin1String("QComboBox\n"
"{\n"
"    color:orange;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1,y2:1, stop: 1 rgba(55, 55, 55, 100), stop: 0 rgba(75, 75, 75, 100));\n"
"    border-color: rgba(85,85,85,200);\n"
"    border-width: 1px;\n"
"    border-style: solid;\n"
"}"));
        pB_startStopSampling = new QPushButton(gB_inputAudioDevice);
        pB_startStopSampling->setObjectName(QStringLiteral("pB_startStopSampling"));
        pB_startStopSampling->setEnabled(false);
        pB_startStopSampling->setGeometry(QRect(330, 30, 81, 21));
        pB_startStopSampling->setStyleSheet(QLatin1String("QPushButton:enabled\n"
"{\n"
"    color:orange;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1,y2:1, stop: 1 rgba(60, 60, 60, 100), stop: 0 rgba(80, 80, 80, 100));\n"
"    border-color: rgba(70,70,70,200);\n"
"    border-width: 1px;\n"
"    border-style: outset;\n"
"	border-radius:3;\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"    color:gray;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1,y2:1, stop: 1 rgba(60, 60, 60, 100), stop: 0 rgba(80, 80, 80, 100));\n"
"    border-color: rgba(70,70,70,200);\n"
"    border-width: 1px;\n"
"    border-style: inset;\n"
"	border-radius:3;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"    color:orange;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1,y2:1, stop: 1 rgba(60, 60, 60, 100), stop: 0 rgba(80, 80, 80, 100));\n"
"    border-color: rgba(70,70,70,200);\n"
"    border-width: 1px;\n"
"    border-style: inset;\n"
"	border-radius:3;\n"
"}"));
        gB_outputAudioDevice = new QGroupBox(centralWidget);
        gB_outputAudioDevice->setObjectName(QStringLiteral("gB_outputAudioDevice"));
        gB_outputAudioDevice->setGeometry(QRect(490, 20, 431, 101));
        gB_outputAudioDevice->setStyleSheet(QLatin1String("QGroupBox{\n"
"    border-color: rgba(85,85,85,200);\n"
"    border-width: 1px;\n"
"    border-style: solid;\n"
"\n"
"    text-align: left; /* align the text to the left */\n"
"	color:rgb(255,127,39);\n"
"    padding-left: 5px;\n"
"	border-radius:5px;\n"
"}"));
        gB_outputAudioDevice->setCheckable(true);
        gB_outputAudioDevice->setChecked(false);
        cB_outputAudioDevice = new QComboBox(gB_outputAudioDevice);
        cB_outputAudioDevice->setObjectName(QStringLiteral("cB_outputAudioDevice"));
        cB_outputAudioDevice->setGeometry(QRect(20, 30, 301, 22));
        cB_outputAudioDevice->setStyleSheet(QLatin1String("QComboBox:enabled\n"
"{\n"
"    color:orange;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1,y2:1, stop: 1 rgba(55, 55, 55, 100), stop: 0 rgba(75, 75, 75, 100));\n"
"    border-color: rgba(85,85,85,200);\n"
"    border-width: 1px;\n"
"    border-style: solid;\n"
"}\n"
"\n"
"QComboBox:disabled\n"
"{\n"
"    color:gray;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1,y2:1, stop: 1 rgba(60, 60, 60, 100), stop: 0 rgba(80, 80, 80, 100));\n"
"    border-color: rgba(70,70,70,200);\n"
"    border-width: 1px;\n"
"    border-style: inset;\n"
"	border-radius:3;\n"
"}"));
        pB_startStopPlaying = new QPushButton(gB_outputAudioDevice);
        pB_startStopPlaying->setObjectName(QStringLiteral("pB_startStopPlaying"));
        pB_startStopPlaying->setGeometry(QRect(330, 30, 80, 21));
        pB_startStopPlaying->setStyleSheet(QLatin1String("QPushButton:enabled\n"
"{\n"
"    color:orange;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1,y2:1, stop: 1 rgba(60, 60, 60, 100), stop: 0 rgba(80, 80, 80, 100));\n"
"    border-color: rgba(70,70,70,200);\n"
"    border-width: 1px;\n"
"    border-style: outset;\n"
"	border-radius:3;\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"    color:gray;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1,y2:1, stop: 1 rgba(60, 60, 60, 100), stop: 0 rgba(80, 80, 80, 100));\n"
"    border-color: rgba(70,70,70,200);\n"
"    border-width: 1px;\n"
"    border-style: inset;\n"
"	border-radius:3;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    color:orange;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1,y2:1, stop: 1 rgba(60, 60, 60, 100), stop: 0 rgba(80, 80, 80, 100));\n"
"    border-color: rgba(70,70,70,200);\n"
"    border-width: 1px;\n"
"    border-style: inset;\n"
"	border-radius:3;\n"
"}"));
        hSlider_outputVolume = new QSlider(gB_outputAudioDevice);
        hSlider_outputVolume->setObjectName(QStringLiteral("hSlider_outputVolume"));
        hSlider_outputVolume->setGeometry(QRect(20, 80, 391, 16));
        hSlider_outputVolume->setCursor(QCursor(Qt::PointingHandCursor));
        hSlider_outputVolume->setStyleSheet(QLatin1String("QSlider::groove:horizontal:enabled {\n"
"    border: 1px solid rgb(255,127,39);\n"
"    height: 2px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: orange;\n"
"    margin: 2px 0;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:enabled {\n"
"    background: rgb(255,127,39); \n"
"    border: 1px solid rgb(236,95,0);\n"
"    width: 18px;\n"
"    margin: -2px 0; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::groove:horizontal:hover\n"
"{\n"
"	border:1px;\n"
"	background:orange;\n"
"}\n"
"\n"
"QSlider::groove:horizontal:disabled {\n"
"    border: 1px solidrgb(60,60,60);\n"
"    height: 2px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: gray;\n"
"    margin: 2px 0;\n"
"}\n"
"\n"
"QSlider::handle:horizonta:disabled {\n"
"    background: gray; \n"
"    border: 1px soli"
                        "d rgb(60,60,60);\n"
"    width: 18px;\n"
"    margin: -2px 0; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */\n"
"    border-radius: 3px;\n"
"}"));
        hSlider_outputVolume->setMaximum(100);
        hSlider_outputVolume->setValue(100);
        hSlider_outputVolume->setOrientation(Qt::Horizontal);
        hSlider_outputVolume->setTickPosition(QSlider::TicksBelow);
        hSlider_outputVolume->setTickInterval(10);
        label = new QLabel(gB_outputAudioDevice);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 60, 101, 16));
        label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"	color:rgb(255,127,39);\n"
"}"));
        gB_visualization = new QGroupBox(centralWidget);
        gB_visualization->setObjectName(QStringLiteral("gB_visualization"));
        gB_visualization->setGeometry(QRect(10, 140, 1221, 591));
        gB_visualization->setStyleSheet(QLatin1String("QGroupBox\n"
"{\n"
"    text-align: left; /* align the text to the left */\n"
"	color:rgb(255,127,39);\n"
"    padding-left: 5px;\n"
"	border-color: rgba(85,85,85,200);\n"
"    border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius:5px;\n"
"}"));
        lB_visualization = new QLabel(gB_visualization);
        lB_visualization->setObjectName(QStringLiteral("lB_visualization"));
        lB_visualization->setGeometry(QRect(20, 20, 1181, 561));
        lB_visualization->setAutoFillBackground(false);
        lB_visualization->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1,y2:1, stop: 1 rgba(55, 55, 55, 100), stop: 0 rgba(65, 65, 65, 100));\n"
"	border-color: rgba(85,85,85,200);\n"
"    border-width: 1px;\n"
"    border-style: solid;\n"
"}"));
        lB_visualization->setFrameShape(QFrame::Box);
        lB_visualization->setFrameShadow(QFrame::Sunken);
        lB_visualization->setScaledContents(false);
        gB_networkSettings = new QGroupBox(centralWidget);
        gB_networkSettings->setObjectName(QStringLiteral("gB_networkSettings"));
        gB_networkSettings->setGeometry(QRect(960, 20, 271, 101));
        gB_networkSettings->setStyleSheet(QLatin1String("QGroupBox{\n"
"    text-align: left; /* align the text to the left */\n"
"	color:rgb(255,127,39);\n"
"    padding-left: 5px;\n"
"    border-color: rgba(85,85,85,200);\n"
"    border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius:5px;\n"
"}"));
        lb_peerIP = new QLabel(gB_networkSettings);
        lb_peerIP->setObjectName(QStringLiteral("lb_peerIP"));
        lb_peerIP->setGeometry(QRect(10, 20, 47, 13));
        lb_peerIP->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"	color:rgb(255,127,39);\n"
"}"));
        lE_peerIP = new QLineEdit(gB_networkSettings);
        lE_peerIP->setObjectName(QStringLiteral("lE_peerIP"));
        lE_peerIP->setGeometry(QRect(20, 40, 113, 21));
        lE_peerIP->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	background:rgb(75,75,75);\n"
"	color:orange;\n"
"    border-color: rgba(85,85,85,200);\n"
"    border-width: 1px;\n"
"    border-style: solid;\n"
"}"));
        lb_peerPort = new QLabel(gB_networkSettings);
        lb_peerPort->setObjectName(QStringLiteral("lb_peerPort"));
        lb_peerPort->setGeometry(QRect(150, 20, 47, 13));
        lb_peerPort->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"	color:rgb(255,127,39);\n"
"}"));
        sB_udpPort = new QSpinBox(gB_networkSettings);
        sB_udpPort->setObjectName(QStringLiteral("sB_udpPort"));
        sB_udpPort->setGeometry(QRect(170, 40, 71, 22));
        sB_udpPort->setStyleSheet(QLatin1String("QSpinBox\n"
"{\n"
"	color:orange;\n"
"	background:rgb(65,65,65);\n"
"    border-color: rgba(85,85,85,200);\n"
"    border-width: 1px;\n"
"    border-style: solid;\n"
"}"));
        sB_udpPort->setMaximum(65535);
        sB_udpPort->setValue(8002);
        pB_connect = new QPushButton(gB_networkSettings);
        pB_connect->setObjectName(QStringLiteral("pB_connect"));
        pB_connect->setGeometry(QRect(20, 70, 221, 21));
        pB_connect->setStyleSheet(QLatin1String("QPushButton:enabled\n"
"{\n"
"    color:orange;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1,y2:1, stop: 1 rgba(60, 60, 60, 100), stop: 0 rgba(80, 80, 80, 100));\n"
"    border-color: rgba(70,70,70,200);\n"
"    border-width: 1px;\n"
"    border-style: outset;\n"
"	border-radius:3;\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"    color:gray;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1,y2:1, stop: 1 rgba(60, 60, 60, 100), stop: 0 rgba(80, 80, 80, 100));\n"
"    border-color: rgba(70,70,70,200);\n"
"    border-width: 1px;\n"
"    border-style: inset;\n"
"	border-radius:3;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"    color:orange;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1,y2:1, stop: 1 rgba(60, 60, 60, 100), stop: 0 rgba(80, 80, 80, 100));\n"
"    border-color: rgba(70,70,70,200);\n"
"    border-width: 1px;\n"
"    border-style: inset;\n"
"	border-radius:3;\n"
"}"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1253, 20));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Remote Boombox", 0));
        gB_inputAudioDevice->setTitle(QApplication::translate("MainWindow", "Input Audio Device", 0));
        pB_startStopSampling->setText(QApplication::translate("MainWindow", "Start Sampling", 0));
        gB_outputAudioDevice->setTitle(QApplication::translate("MainWindow", "Output Audio Device", 0));
        pB_startStopPlaying->setText(QApplication::translate("MainWindow", "Start Playing", 0));
        label->setText(QApplication::translate("MainWindow", "Change Volume:", 0));
        gB_visualization->setTitle(QApplication::translate("MainWindow", "Visualziation", 0));
        lB_visualization->setText(QString());
        gB_networkSettings->setTitle(QApplication::translate("MainWindow", "Network Settings", 0));
        lb_peerIP->setText(QApplication::translate("MainWindow", "Peer Ip:", 0));
        lE_peerIP->setText(QApplication::translate("MainWindow", "localhost", 0));
        lb_peerPort->setText(QApplication::translate("MainWindow", "Peer port:", 0));
        pB_connect->setText(QApplication::translate("MainWindow", "Connect", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
