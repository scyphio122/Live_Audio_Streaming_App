/****************************************************************************
** Meta object code from reading C++ file 'commandsender.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../commandsender.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'commandsender.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CommandSender_t {
    QByteArrayData data[8];
    char stringdata[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CommandSender_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CommandSender_t qt_meta_stringdata_CommandSender = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CommandSender"
QT_MOC_LITERAL(1, 14, 17), // "sendCommandSignal"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 12), // "UdpDatagram*"
QT_MOC_LITERAL(4, 46, 8), // "datagram"
QT_MOC_LITERAL(5, 55, 21), // "sendConnectionRequest"
QT_MOC_LITERAL(6, 77, 4), // "myIP"
QT_MOC_LITERAL(7, 82, 12) // "receiverPort"

    },
    "CommandSender\0sendCommandSignal\0\0"
    "UdpDatagram*\0datagram\0sendConnectionRequest\0"
    "myIP\0receiverPort"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommandSender[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    6,    7,

       0        // eod
};

void CommandSender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CommandSender *_t = static_cast<CommandSender *>(_o);
        switch (_id) {
        case 0: _t->sendCommandSignal((*reinterpret_cast< UdpDatagram*(*)>(_a[1]))); break;
        case 1: _t->sendConnectionRequest((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CommandSender::*_t)(UdpDatagram * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CommandSender::sendCommandSignal)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject CommandSender::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CommandSender.data,
      qt_meta_data_CommandSender,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CommandSender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommandSender::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CommandSender.stringdata))
        return static_cast<void*>(const_cast< CommandSender*>(this));
    return QObject::qt_metacast(_clname);
}

int CommandSender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CommandSender::sendCommandSignal(UdpDatagram * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
