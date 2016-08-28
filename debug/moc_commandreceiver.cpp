/****************************************************************************
** Meta object code from reading C++ file 'commandreceiver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../commandreceiver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'commandreceiver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CommandReceiver_t {
    QByteArrayData data[8];
    char stringdata[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CommandReceiver_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CommandReceiver_t qt_meta_stringdata_CommandReceiver = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CommandReceiver"
QT_MOC_LITERAL(1, 16, 23), // "connectionRequestSignal"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 25), // "connectionEstablishSignal"
QT_MOC_LITERAL(4, 67, 2), // "ip"
QT_MOC_LITERAL(5, 70, 4), // "port"
QT_MOC_LITERAL(6, 75, 27), // "connectionUpdateGUICallback"
QT_MOC_LITERAL(7, 103, 21) // "connectionEstablished"

    },
    "CommandReceiver\0connectionRequestSignal\0"
    "\0connectionEstablishSignal\0ip\0port\0"
    "connectionUpdateGUICallback\0"
    "connectionEstablished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommandReceiver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    2,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void CommandReceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CommandReceiver *_t = static_cast<CommandReceiver *>(_o);
        switch (_id) {
        case 0: _t->connectionRequestSignal(); break;
        case 1: _t->connectionEstablishSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->connectionUpdateGUICallback((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CommandReceiver::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandReceiver::connectionRequestSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (CommandReceiver::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandReceiver::connectionEstablishSignal)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject CommandReceiver::staticMetaObject = {
    { &DatagramListener::staticMetaObject, qt_meta_stringdata_CommandReceiver.data,
      qt_meta_data_CommandReceiver,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CommandReceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommandReceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CommandReceiver.stringdata))
        return static_cast<void*>(const_cast< CommandReceiver*>(this));
    return DatagramListener::qt_metacast(_clname);
}

int CommandReceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DatagramListener::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CommandReceiver::connectionRequestSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CommandReceiver::connectionEstablishSignal(QString _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
