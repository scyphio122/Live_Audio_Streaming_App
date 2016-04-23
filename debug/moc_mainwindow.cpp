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
    QByteArrayData data[32];
    char stringdata[516];
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
QT_MOC_LITERAL(13, 195, 19), // "initializeUdpSocket"
QT_MOC_LITERAL(14, 215, 2), // "ip"
QT_MOC_LITERAL(15, 218, 4), // "port"
QT_MOC_LITERAL(16, 223, 31), // "on_pB_startStopSampling_clicked"
QT_MOC_LITERAL(17, 255, 32), // "on_cb_inputAudioDevice_activated"
QT_MOC_LITERAL(18, 288, 4), // "arg1"
QT_MOC_LITERAL(19, 293, 33), // "on_cB_outputAudioDevice_activ..."
QT_MOC_LITERAL(20, 327, 30), // "on_pB_startStopPlaying_clicked"
QT_MOC_LITERAL(21, 358, 21), // "on_pB_connect_clicked"
QT_MOC_LITERAL(22, 380, 21), // "audioGetterIsSampling"
QT_MOC_LITERAL(23, 402, 16), // "signalFromThread"
QT_MOC_LITERAL(24, 419, 20), // "audioPlayerIsPlaying"
QT_MOC_LITERAL(25, 440, 14), // "setFftOutArray"
QT_MOC_LITERAL(26, 455, 8), // "Complex*"
QT_MOC_LITERAL(27, 464, 5), // "array"
QT_MOC_LITERAL(28, 470, 9), // "arraySize"
QT_MOC_LITERAL(29, 480, 16), // "setFftCalculator"
QT_MOC_LITERAL(30, 497, 14), // "FftCalculator*"
QT_MOC_LITERAL(31, 512, 3) // "fft"

    },
    "MainWindow\0setInputAudioDeviceSignal\0"
    "\0QAudioInput*\0newAudioInputDev\0"
    "setAudioOutputSignal\0QAudioOutput*\0"
    "dev\0queryIfSamplingSignal\0"
    "queryIfPlayingSignal\0startSamplingSignal\0"
    "value\0startPlayingSignal\0initializeUdpSocket\0"
    "ip\0port\0on_pB_startStopSampling_clicked\0"
    "on_cb_inputAudioDevice_activated\0arg1\0"
    "on_cB_outputAudioDevice_activated\0"
    "on_pB_startStopPlaying_clicked\0"
    "on_pB_connect_clicked\0audioGetterIsSampling\0"
    "signalFromThread\0audioPlayerIsPlaying\0"
    "setFftOutArray\0Complex*\0array\0arraySize\0"
    "setFftCalculator\0FftCalculator*\0fft"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       5,    1,   97,    2, 0x06 /* Public */,
       8,    0,  100,    2, 0x06 /* Public */,
       9,    0,  101,    2, 0x06 /* Public */,
      10,    1,  102,    2, 0x06 /* Public */,
      12,    1,  105,    2, 0x06 /* Public */,
      13,    2,  108,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    0,  113,    2, 0x08 /* Private */,
      17,    1,  114,    2, 0x08 /* Private */,
      19,    1,  117,    2, 0x08 /* Private */,
      20,    0,  120,    2, 0x08 /* Private */,
      21,    0,  121,    2, 0x08 /* Private */,
      22,    1,  122,    2, 0x0a /* Public */,
      24,    1,  125,    2, 0x0a /* Public */,
      25,    2,  128,    2, 0x0a /* Public */,
      29,    1,  133,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   14,   15,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, 0x80000000 | 26, QMetaType::Int,   27,   28,
    QMetaType::Void, 0x80000000 | 30,   31,

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
        case 6: _t->initializeUdpSocket((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->on_pB_startStopSampling_clicked(); break;
        case 8: _t->on_cb_inputAudioDevice_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_cB_outputAudioDevice_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_pB_startStopPlaying_clicked(); break;
        case 11: _t->on_pB_connect_clicked(); break;
        case 12: _t->audioGetterIsSampling((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->audioPlayerIsPlaying((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->setFftOutArray((*reinterpret_cast< Complex*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: _t->setFftCalculator((*reinterpret_cast< FftCalculator*(*)>(_a[1]))); break;
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
        case 15:
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
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::initializeUdpSocket)) {
                *result = 6;
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
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
void MainWindow::initializeUdpSocket(QString _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
