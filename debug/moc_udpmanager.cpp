/****************************************************************************
** Meta object code from reading C++ file 'udpmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../udpmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'udpmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UdpManager_t {
    QByteArrayData data[15];
    char stringdata[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UdpManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UdpManager_t qt_meta_stringdata_UdpManager = {
    {
QT_MOC_LITERAL(0, 0, 10), // "UdpManager"
QT_MOC_LITERAL(1, 11, 16), // "emitDataReceived"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 12), // "UdpDatagram*"
QT_MOC_LITERAL(4, 42, 8), // "datagram"
QT_MOC_LITERAL(5, 51, 20), // "setReceiverIpAddress"
QT_MOC_LITERAL(6, 72, 11), // "std::string"
QT_MOC_LITERAL(7, 84, 7), // "address"
QT_MOC_LITERAL(8, 92, 20), // "setSendingPortNumber"
QT_MOC_LITERAL(9, 113, 10), // "portNumber"
QT_MOC_LITERAL(10, 124, 8), // "sendData"
QT_MOC_LITERAL(11, 133, 10), // "initSocket"
QT_MOC_LITERAL(12, 144, 2), // "ip"
QT_MOC_LITERAL(13, 147, 4), // "port"
QT_MOC_LITERAL(14, 152, 8) // "readData"

    },
    "UdpManager\0emitDataReceived\0\0UdpDatagram*\0"
    "datagram\0setReceiverIpAddress\0std::string\0"
    "address\0setSendingPortNumber\0portNumber\0"
    "sendData\0initSocket\0ip\0port\0readData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UdpManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   47,    2, 0x0a /* Public */,
       8,    1,   50,    2, 0x0a /* Public */,
      10,    1,   53,    2, 0x0a /* Public */,
      11,    2,   56,    2, 0x0a /* Public */,
      14,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   12,   13,
    QMetaType::Void,

       0        // eod
};

void UdpManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UdpManager *_t = static_cast<UdpManager *>(_o);
        switch (_id) {
        case 0: _t->emitDataReceived((*reinterpret_cast< UdpDatagram*(*)>(_a[1]))); break;
        case 1: _t->setReceiverIpAddress((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 2: _t->setSendingPortNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sendData((*reinterpret_cast< UdpDatagram*(*)>(_a[1]))); break;
        case 4: _t->initSocket((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->readData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UdpManager::*_t)(UdpDatagram * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UdpManager::emitDataReceived)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject UdpManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UdpManager.data,
      qt_meta_data_UdpManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UdpManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UdpManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UdpManager.stringdata))
        return static_cast<void*>(const_cast< UdpManager*>(this));
    return QObject::qt_metacast(_clname);
}

int UdpManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void UdpManager::emitDataReceived(UdpDatagram * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
