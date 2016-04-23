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
    QByteArrayData data[18];
    char stringdata[225];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AudioSamplesGetter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AudioSamplesGetter_t qt_meta_stringdata_AudioSamplesGetter = {
    {
QT_MOC_LITERAL(0, 0, 18), // "AudioSamplesGetter"
QT_MOC_LITERAL(1, 19, 9), // "isPlaying"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "bool*"
QT_MOC_LITERAL(4, 36, 4), // "init"
QT_MOC_LITERAL(5, 41, 19), // "setInputAudioDevice"
QT_MOC_LITERAL(6, 61, 12), // "QAudioInput*"
QT_MOC_LITERAL(7, 74, 16), // "newAudioInputDev"
QT_MOC_LITERAL(8, 91, 20), // "setOutputAudioDevice"
QT_MOC_LITERAL(9, 112, 13), // "QAudioOutput*"
QT_MOC_LITERAL(10, 126, 17), // "newAudioOutputDev"
QT_MOC_LITERAL(11, 144, 17), // "onSamplesCaptured"
QT_MOC_LITERAL(12, 162, 14), // "setMuteEnabled"
QT_MOC_LITERAL(13, 177, 7), // "isMuted"
QT_MOC_LITERAL(14, 185, 14), // "setEchoEnabled"
QT_MOC_LITERAL(15, 200, 4), // "isOn"
QT_MOC_LITERAL(16, 205, 13), // "startSampling"
QT_MOC_LITERAL(17, 219, 5) // "value"

    },
    "AudioSamplesGetter\0isPlaying\0\0bool*\0"
    "init\0setInputAudioDevice\0QAudioInput*\0"
    "newAudioInputDev\0setOutputAudioDevice\0"
    "QAudioOutput*\0newAudioOutputDev\0"
    "onSamplesCaptured\0setMuteEnabled\0"
    "isMuted\0setEchoEnabled\0isOn\0startSampling\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AudioSamplesGetter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   62,    2, 0x0a /* Public */,
       5,    1,   63,    2, 0x0a /* Public */,
       8,    1,   66,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x0a /* Public */,
      12,    1,   70,    2, 0x0a /* Public */,
      14,    1,   73,    2, 0x0a /* Public */,
      16,    1,   76,    2, 0x0a /* Public */,
       1,    0,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    1,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void,

       0        // eod
};

void AudioSamplesGetter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AudioSamplesGetter *_t = static_cast<AudioSamplesGetter *>(_o);
        switch (_id) {
        case 0: _t->isPlaying((*reinterpret_cast< bool*(*)>(_a[1]))); break;
        case 1: _t->init(); break;
        case 2: _t->setInputAudioDevice((*reinterpret_cast< QAudioInput*(*)>(_a[1]))); break;
        case 3: _t->setOutputAudioDevice((*reinterpret_cast< QAudioOutput*(*)>(_a[1]))); break;
        case 4: _t->onSamplesCaptured(); break;
        case 5: _t->setMuteEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->setEchoEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->startSampling((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->isPlaying(); break;
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
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAudioOutput* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AudioSamplesGetter::*_t)(bool * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AudioSamplesGetter::isPlaying)) {
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void AudioSamplesGetter::isPlaying(bool * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
