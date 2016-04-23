/****************************************************************************
** Meta object code from reading C++ file 'receiveddatagramprocessor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../receiveddatagramprocessor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'receiveddatagramprocessor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ReceivedDatagramProcessor_t {
    QByteArrayData data[9];
    char stringdata[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ReceivedDatagramProcessor_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ReceivedDatagramProcessor_t qt_meta_stringdata_ReceivedDatagramProcessor = {
    {
QT_MOC_LITERAL(0, 0, 25), // "ReceivedDatagramProcessor"
QT_MOC_LITERAL(1, 26, 15), // "processDatagram"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 12), // "UdpDatagram*"
QT_MOC_LITERAL(4, 56, 8), // "datagram"
QT_MOC_LITERAL(5, 65, 12), // "QHostAddress"
QT_MOC_LITERAL(6, 78, 2), // "ip"
QT_MOC_LITERAL(7, 81, 8), // "uint16_t"
QT_MOC_LITERAL(8, 90, 4) // "port"

    },
    "ReceivedDatagramProcessor\0processDatagram\0"
    "\0UdpDatagram*\0datagram\0QHostAddress\0"
    "ip\0uint16_t\0port"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReceivedDatagramProcessor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7,    4,    6,    8,

       0        // eod
};

void ReceivedDatagramProcessor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ReceivedDatagramProcessor *_t = static_cast<ReceivedDatagramProcessor *>(_o);
        switch (_id) {
        case 0: _t->processDatagram((*reinterpret_cast< UdpDatagram*(*)>(_a[1])),(*reinterpret_cast< QHostAddress(*)>(_a[2])),(*reinterpret_cast< uint16_t(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject ReceivedDatagramProcessor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ReceivedDatagramProcessor.data,
      qt_meta_data_ReceivedDatagramProcessor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ReceivedDatagramProcessor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReceivedDatagramProcessor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ReceivedDatagramProcessor.stringdata))
        return static_cast<void*>(const_cast< ReceivedDatagramProcessor*>(this));
    return QObject::qt_metacast(_clname);
}

int ReceivedDatagramProcessor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
