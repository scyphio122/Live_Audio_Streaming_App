#-------------------------------------------------
#
# Project created by QtCreator 2016-04-10T18:57:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Remote_Boombox
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    audiosamplesgetter.cpp \
    audiosamplessender.cpp \
    commandssender.cpp \
    udpmanager.cpp \
    receiveddatagramprocessor.cpp \
    datagramlistener.cpp \
    commandreceiver.cpp \
    graphicsvisualizer.cpp \
    abstractvisualization.cpp \
    fftbars.cpp \
    audiosamplesplayer.cpp

HEADERS  += mainwindow.h \
    audiosamplesgetter.h \
    audiosamplessender.h \
    commandssender.h \
    udpmanager.h \
    receiveddatagramprocessor.h \
    datagramlistener.h \
    commandreceiver.h \
    graphicsvisualizer.h \
    abstractvisualization.h \
    fftbars.h \
    audiosamplesplayer.h

FORMS    += mainwindow.ui
