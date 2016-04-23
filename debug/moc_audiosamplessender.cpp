/****************************************************************************
** Meta object code from reading C++ file 'audiosamplessender.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../audiosamplessender.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'audiosamplessender.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AudioSamplesSender_t {
    QByteArrayData data[8];
    char stringdata[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AudioSamplesSender_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AudioSamplesSender_t qt_meta_stringdata_AudioSamplesSender = {
    {
QT_MOC_LITERAL(0, 0, 18), // "AudioSamplesSender"
QT_MOC_LITERAL(1, 19, 21), // "emitSendSamplesSignal"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 12), // "UdpDatagram*"
QT_MOC_LITERAL(4, 55, 8), // "datagram"
QT_MOC_LITERAL(5, 64, 12), // "QHostAddress"
QT_MOC_LITERAL(6, 77, 2), // "ip"
QT_MOC_LITERAL(7, 80, 4) // "port"

    },
    "AudioSamplesSender\0emitSendSamplesSignal\0"
    "\0UdpDatagram*\0datagram\0QHostAddress\0"
    "ip\0port"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AudioSamplesSender[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::Int,    4,    6,    7,

       0        // eod
};

void AudioSamplesSender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AudioSamplesSender *_t = static_cast<AudioSamplesSender *>(_o);
        switch (_id) {
        case 0: _t->emitSendSamplesSignal((*reinterpret_cast< UdpDatagram*(*)>(_a[1])),(*reinterpret_cast< const QHostAddress(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AudioSamplesSender::*_t)(UdpDatagram * , const QHostAddress , const int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AudioSamplesSender::emitSendSamplesSignal)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject AudioSamplesSender::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AudioSamplesSender.data,
      qt_meta_data_AudioSamplesSender,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AudioSamplesSender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AudioSamplesSender::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AudioSamplesSender.stringdata))
        return static_cast<void*>(const_cast< AudioSamplesSender*>(this));
    return QObject::qt_metacast(_clname);
}

int AudioSamplesSender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void AudioSamplesSender::emitSendSamplesSignal(UdpDatagram * _t1, const QHostAddress _t2, const int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
