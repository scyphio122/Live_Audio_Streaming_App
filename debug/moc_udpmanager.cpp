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
    QByteArrayData data[17];
    char stringdata[185];
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
QT_MOC_LITERAL(5, 51, 15), // "connectedSignal"
QT_MOC_LITERAL(6, 67, 20), // "setReceiverIpAddress"
QT_MOC_LITERAL(7, 88, 11), // "std::string"
QT_MOC_LITERAL(8, 100, 7), // "address"
QT_MOC_LITERAL(9, 108, 20), // "setSendingPortNumber"
QT_MOC_LITERAL(10, 129, 10), // "portNumber"
QT_MOC_LITERAL(11, 140, 10), // "connectUDP"
QT_MOC_LITERAL(12, 151, 2), // "ip"
QT_MOC_LITERAL(13, 154, 4), // "port"
QT_MOC_LITERAL(14, 159, 8), // "sendData"
QT_MOC_LITERAL(15, 168, 7), // "sendCmd"
QT_MOC_LITERAL(16, 176, 8) // "readData"

    },
    "UdpManager\0emitDataReceived\0\0UdpDatagram*\0"
    "datagram\0connectedSignal\0setReceiverIpAddress\0"
    "std::string\0address\0setSendingPortNumber\0"
    "portNumber\0connectUDP\0ip\0port\0sendData\0"
    "sendCmd\0readData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UdpManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   58,    2, 0x0a /* Public */,
       9,    1,   61,    2, 0x0a /* Public */,
      11,    2,   64,    2, 0x0a /* Public */,
      14,    1,   69,    2, 0x0a /* Public */,
      15,    1,   72,    2, 0x0a /* Public */,
      16,    0,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   12,   13,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void UdpManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UdpManager *_t = static_cast<UdpManager *>(_o);
        switch (_id) {
        case 0: _t->emitDataReceived((*reinterpret_cast< UdpDatagram*(*)>(_a[1]))); break;
        case 1: _t->connectedSignal(); break;
        case 2: _t->setReceiverIpAddress((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 3: _t->setSendingPortNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->connectUDP((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->sendData((*reinterpret_cast< UdpDatagram*(*)>(_a[1]))); break;
        case 6: _t->sendCmd((*reinterpret_cast< UdpDatagram*(*)>(_a[1]))); break;
        case 7: _t->readData(); break;
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
        {
            typedef void (UdpManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UdpManager::connectedSignal)) {
                *result = 1;
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void UdpManager::emitDataReceived(UdpDatagram * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UdpManager::connectedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
