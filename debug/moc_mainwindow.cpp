/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[38];
    char stringdata[619];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 25), // "setInputAudioDeviceSignal"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 12), // "QAudioInput*"
QT_MOC_LITERAL(4, 51, 16), // "newAudioInputDev"
QT_MOC_LITERAL(5, 68, 20), // "setAudioOutputSignal"
QT_MOC_LITERAL(6, 89, 13), // "QAudioOutput*"
QT_MOC_LITERAL(7, 103, 3), // "dev"
QT_MOC_LITERAL(8, 107, 21), // "queryIfSamplingSignal"
QT_MOC_LITERAL(9, 129, 20), // "queryIfPlayingSignal"
QT_MOC_LITERAL(10, 150, 19), // "startSamplingSignal"
QT_MOC_LITERAL(11, 170, 5), // "value"
QT_MOC_LITERAL(12, 176, 18), // "startPlayingSignal"
QT_MOC_LITERAL(13, 195, 12), // "tryToConnect"
QT_MOC_LITERAL(14, 208, 2), // "ip"
QT_MOC_LITERAL(15, 211, 4), // "port"
QT_MOC_LITERAL(16, 216, 9), // "fftEnable"
QT_MOC_LITERAL(17, 226, 8), // "finished"
QT_MOC_LITERAL(18, 235, 18), // "changeOutputVolume"
QT_MOC_LITERAL(19, 254, 31), // "on_pB_startStopSampling_clicked"
QT_MOC_LITERAL(20, 286, 32), // "on_cb_inputAudioDevice_activated"
QT_MOC_LITERAL(21, 319, 4), // "arg1"
QT_MOC_LITERAL(22, 324, 33), // "on_cB_outputAudioDevice_activ..."
QT_MOC_LITERAL(23, 358, 30), // "on_pB_startStopPlaying_clicked"
QT_MOC_LITERAL(24, 389, 21), // "on_pB_connect_clicked"
QT_MOC_LITERAL(25, 411, 36), // "on_hSlider_outputVolume_value..."
QT_MOC_LITERAL(26, 448, 21), // "audioGetterIsSampling"
QT_MOC_LITERAL(27, 470, 16), // "signalFromThread"
QT_MOC_LITERAL(28, 487, 20), // "audioPlayerIsPlaying"
QT_MOC_LITERAL(29, 508, 14), // "setFftOutArray"
QT_MOC_LITERAL(30, 523, 8), // "Complex*"
QT_MOC_LITERAL(31, 532, 5), // "array"
QT_MOC_LITERAL(32, 538, 9), // "arraySize"
QT_MOC_LITERAL(33, 548, 16), // "setFftCalculator"
QT_MOC_LITERAL(34, 565, 14), // "FftCalculator*"
QT_MOC_LITERAL(35, 580, 3), // "fft"
QT_MOC_LITERAL(36, 584, 27), // "updateConnectionStateButton"
QT_MOC_LITERAL(37, 612, 6) // "status"

    },
    "MainWindow\0setInputAudioDeviceSignal\0"
    "\0QAudioInput*\0newAudioInputDev\0"
    "setAudioOutputSignal\0QAudioOutput*\0"
    "dev\0queryIfSamplingSignal\0"
    "queryIfPlayingSignal\0startSamplingSignal\0"
    "value\0startPlayingSignal\0tryToConnect\0"
    "ip\0port\0fftEnable\0finished\0"
    "changeOutputVolume\0on_pB_startStopSampling_clicked\0"
    "on_cb_inputAudioDevice_activated\0arg1\0"
    "on_cB_outputAudioDevice_activated\0"
    "on_pB_startStopPlaying_clicked\0"
    "on_pB_connect_clicked\0"
    "on_hSlider_outputVolume_valueChanged\0"
    "audioGetterIsSampling\0signalFromThread\0"
    "audioPlayerIsPlaying\0setFftOutArray\0"
    "Complex*\0array\0arraySize\0setFftCalculator\0"
    "FftCalculator*\0fft\0updateConnectionStateButton\0"
    "status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x06 /* Public */,
       5,    1,  122,    2, 0x06 /* Public */,
       8,    0,  125,    2, 0x06 /* Public */,
       9,    0,  126,    2, 0x06 /* Public */,
      10,    1,  127,    2, 0x06 /* Public */,
      12,    1,  130,    2, 0x06 /* Public */,
      13,    2,  133,    2, 0x06 /* Public */,
      16,    1,  138,    2, 0x06 /* Public */,
      17,    0,  141,    2, 0x06 /* Public */,
      18,    1,  142,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    0,  145,    2, 0x08 /* Private */,
      20,    1,  146,    2, 0x08 /* Private */,
      22,    1,  149,    2, 0x08 /* Private */,
      23,    0,  152,    2, 0x08 /* Private */,
      24,    0,  153,    2, 0x08 /* Private */,
      25,    1,  154,    2, 0x08 /* Private */,
      26,    1,  157,    2, 0x0a /* Public */,
      28,    1,  160,    2, 0x0a /* Public */,
      29,    2,  163,    2, 0x0a /* Public */,
      33,    1,  168,    2, 0x0a /* Public */,
      36,    1,  171,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   14,   15,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void, 0x80000000 | 30, QMetaType::Int,   31,   32,
    QMetaType::Void, 0x80000000 | 34,   35,
    QMetaType::Void, QMetaType::Bool,   37,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->setInputAudioDeviceSignal((*reinterpret_cast< QAudioInput*(*)>(_a[1]))); break;
        case 1: _t->setAudioOutputSignal((*reinterpret_cast< QAudioOutput*(*)>(_a[1]))); break;
        case 2: _t->queryIfSamplingSignal(); break;
        case 3: _t->queryIfPlayingSignal(); break;
        case 4: _t->startSamplingSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->startPlayingSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->tryToConnect((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->fftEnable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->finished(); break;
        case 9: _t->changeOutputVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_pB_startStopSampling_clicked(); break;
        case 11: _t->on_cb_inputAudioDevice_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->on_cB_outputAudioDevice_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->on_pB_startStopPlaying_clicked(); break;
        case 14: _t->on_pB_connect_clicked(); break;
        case 15: _t->on_hSlider_outputVolume_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->audioGetterIsSampling((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->audioPlayerIsPlaying((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->setFftOutArray((*reinterpret_cast< Complex*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 19: _t->setFftCalculator((*reinterpret_cast< FftCalculator*(*)>(_a[1]))); break;
        case 20: _t->updateConnectionStateButton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAudioInput* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAudioOutput* >(); break;
            }
            break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FftCalculator* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(QAudioInput * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::setInputAudioDeviceSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (MainWindow::*_t)(QAudioOutput * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::setAudioOutputSignal)) {
                *result = 1;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::queryIfSamplingSignal)) {
                *result = 2;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::queryIfPlayingSignal)) {
                *result = 3;
            }
        }
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::startSamplingSignal)) {
                *result = 4;
            }
        }
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::startPlayingSignal)) {
                *result = 5;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::tryToConnect)) {
                *result = 6;
            }
        }
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::fftEnable)) {
                *result = 7;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::finished)) {
                *result = 8;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::changeOutputVolume)) {
                *result = 9;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::setInputAudioDeviceSignal(QAudioInput * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::setAudioOutputSignal(QAudioOutput * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::queryIfSamplingSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MainWindow::queryIfPlayingSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MainWindow::startSamplingSignal(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::startPlayingSignal(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::tryToConnect(QString _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::fftEnable(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void MainWindow::changeOutputVolume(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
