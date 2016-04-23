/****************************************************************************
** Meta object code from reading C++ file 'audiosamplesplayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../audiosamplesplayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'audiosamplesplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AudioSamplesPlayer_t {
    QByteArrayData data[10];
    char stringdata[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AudioSamplesPlayer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AudioSamplesPlayer_t qt_meta_stringdata_AudioSamplesPlayer = {
    {
QT_MOC_LITERAL(0, 0, 18), // "AudioSamplesPlayer"
QT_MOC_LITERAL(1, 19, 13), // "isMutedSignal"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 5), // "value"
QT_MOC_LITERAL(4, 40, 4), // "init"
QT_MOC_LITERAL(5, 45, 14), // "setAudioOutput"
QT_MOC_LITERAL(6, 60, 13), // "QAudioOutput*"
QT_MOC_LITERAL(7, 74, 3), // "dev"
QT_MOC_LITERAL(8, 78, 12), // "startPlaying"
QT_MOC_LITERAL(9, 91, 7) // "isMuted"

    },
    "AudioSamplesPlayer\0isMutedSignal\0\0"
    "value\0init\0setAudioOutput\0QAudioOutput*\0"
    "dev\0startPlaying\0isMuted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AudioSamplesPlayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   42,    2, 0x0a /* Public */,
       5,    1,   43,    2, 0x0a /* Public */,
       8,    1,   46,    2, 0x0a /* Public */,
       9,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Bool,

       0        // eod
};

void AudioSamplesPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AudioSamplesPlayer *_t = static_cast<AudioSamplesPlayer *>(_o);
        switch (_id) {
        case 0: _t->isMutedSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->init(); break;
        case 2: _t->setAudioOutput((*reinterpret_cast< QAudioOutput*(*)>(_a[1]))); break;
        case 3: _t->startPlaying((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: { bool _r = _t->isMuted();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
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
            typedef void (AudioSamplesPlayer::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AudioSamplesPlayer::isMutedSignal)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject AudioSamplesPlayer::staticMetaObject = {
    { &DatagramListener::staticMetaObject, qt_meta_stringdata_AudioSamplesPlayer.data,
      qt_meta_data_AudioSamplesPlayer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AudioSamplesPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AudioSamplesPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AudioSamplesPlayer.stringdata))
        return static_cast<void*>(const_cast< AudioSamplesPlayer*>(this));
    return DatagramListener::qt_metacast(_clname);
}

int AudioSamplesPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DatagramListener::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void AudioSamplesPlayer::isMutedSignal(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
