/****************************************************************************
** Meta object code from reading C++ file 'audiosamplesgetter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../audiosamplesgetter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'audiosamplesgetter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AudioSamplesGetter_t {
    QByteArrayData data[14];
    char stringdata[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AudioSamplesGetter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AudioSamplesGetter_t qt_meta_stringdata_AudioSamplesGetter = {
    {
QT_MOC_LITERAL(0, 0, 18), // "AudioSamplesGetter"
QT_MOC_LITERAL(1, 19, 16), // "isSamplingSignal"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 10), // "isSampling"
QT_MOC_LITERAL(4, 48, 4), // "init"
QT_MOC_LITERAL(5, 53, 19), // "setInputAudioDevice"
QT_MOC_LITERAL(6, 73, 12), // "QAudioInput*"
QT_MOC_LITERAL(7, 86, 16), // "newAudioInputDev"
QT_MOC_LITERAL(8, 103, 17), // "onSamplesCaptured"
QT_MOC_LITERAL(9, 121, 14), // "setMuteEnabled"
QT_MOC_LITERAL(10, 136, 7), // "isMuted"
QT_MOC_LITERAL(11, 144, 13), // "startSampling"
QT_MOC_LITERAL(12, 158, 5), // "value"
QT_MOC_LITERAL(13, 164, 20) // "connectDeviceWithBuf"

    },
    "AudioSamplesGetter\0isSamplingSignal\0"
    "\0isSampling\0init\0setInputAudioDevice\0"
    "QAudioInput*\0newAudioInputDev\0"
    "onSamplesCaptured\0setMuteEnabled\0"
    "isMuted\0startSampling\0value\0"
    "connectDeviceWithBuf"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AudioSamplesGetter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   57,    2, 0x0a /* Public */,
       5,    1,   58,    2, 0x0a /* Public */,
       8,    0,   61,    2, 0x0a /* Public */,
       9,    1,   62,    2, 0x0a /* Public */,
      11,    1,   65,    2, 0x0a /* Public */,
       3,    0,   68,    2, 0x0a /* Public */,
      13,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AudioSamplesGetter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AudioSamplesGetter *_t = static_cast<AudioSamplesGetter *>(_o);
        switch (_id) {
        case 0: _t->isSamplingSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->init(); break;
        case 2: _t->setInputAudioDevice((*reinterpret_cast< QAudioInput*(*)>(_a[1]))); break;
        case 3: _t->onSamplesCaptured(); break;
        case 4: _t->setMuteEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->startSampling((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->isSampling(); break;
        case 7: _t->connectDeviceWithBuf(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAudioInput* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AudioSamplesGetter::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AudioSamplesGetter::isSamplingSignal)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject AudioSamplesGetter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AudioSamplesGetter.data,
      qt_meta_data_AudioSamplesGetter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AudioSamplesGetter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AudioSamplesGetter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AudioSamplesGetter.stringdata))
        return static_cast<void*>(const_cast< AudioSamplesGetter*>(this));
    return QObject::qt_metacast(_clname);
}

int AudioSamplesGetter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void AudioSamplesGetter::isSamplingSignal(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
