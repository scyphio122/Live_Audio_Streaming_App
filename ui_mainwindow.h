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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
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
    QGroupBox *gB_visualization;
    QLabel *lB_visualization;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1263, 797);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gB_inputAudioDevice = new QGroupBox(centralWidget);
        gB_inputAudioDevice->setObjectName(QStringLiteral("gB_inputAudioDevice"));
        gB_inputAudioDevice->setGeometry(QRect(20, 20, 421, 61));
        gB_inputAudioDevice->setFlat(false);
        cb_inputAudioDevice = new QComboBox(gB_inputAudioDevice);
        cb_inputAudioDevice->setObjectName(QStringLiteral("cb_inputAudioDevice"));
        cb_inputAudioDevice->setGeometry(QRect(20, 30, 301, 22));
        pB_startStopSampling = new QPushButton(gB_inputAudioDevice);
        pB_startStopSampling->setObjectName(QStringLiteral("pB_startStopSampling"));
        pB_startStopSampling->setEnabled(false);
        pB_startStopSampling->setGeometry(QRect(330, 30, 81, 21));
        gB_outputAudioDevice = new QGroupBox(centralWidget);
        gB_outputAudioDevice->setObjectName(QStringLiteral("gB_outputAudioDevice"));
        gB_outputAudioDevice->setGeometry(QRect(470, 20, 471, 61));
        gB_outputAudioDevice->setCheckable(true);
        gB_outputAudioDevice->setChecked(false);
        cB_outputAudioDevice = new QComboBox(gB_outputAudioDevice);
        cB_outputAudioDevice->setObjectName(QStringLiteral("cB_outputAudioDevice"));
        cB_outputAudioDevice->setGeometry(QRect(20, 30, 301, 22));
        pB_startStopPlaying = new QPushButton(gB_outputAudioDevice);
        pB_startStopPlaying->setObjectName(QStringLiteral("pB_startStopPlaying"));
        pB_startStopPlaying->setGeometry(QRect(340, 30, 80, 21));
        gB_visualization = new QGroupBox(centralWidget);
        gB_visualization->setObjectName(QStringLiteral("gB_visualization"));
        gB_visualization->setGeometry(QRect(20, 110, 1221, 631));
        lB_visualization = new QLabel(gB_visualization);
        lB_visualization->setObjectName(QStringLiteral("lB_visualization"));
        lB_visualization->setGeometry(QRect(20, 40, 1181, 561));
        lB_visualization->setAutoFillBackground(true);
        lB_visualization->setFrameShape(QFrame::Box);
        lB_visualization->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1263, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
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
        gB_visualization->setTitle(QApplication::translate("MainWindow", "Visualziation", 0));
        lB_visualization->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
