/****************************************************************************
** Meta object code from reading C++ file 'fftcalculator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fftcalculator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fftcalculator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FftCalculator_t {
    QByteArrayData data[8];
    char stringdata[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FftCalculator_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FftCalculator_t qt_meta_stringdata_FftCalculator = {
    {
QT_MOC_LITERAL(0, 0, 13), // "FftCalculator"
QT_MOC_LITERAL(1, 14, 12), // "fftCompleted"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 16), // "Complex<double>*"
QT_MOC_LITERAL(4, 45, 11), // "outputArray"
QT_MOC_LITERAL(5, 57, 15), // "outputArraySize"
QT_MOC_LITERAL(6, 73, 9), // "fftEnable"
QT_MOC_LITERAL(7, 83, 5) // "value"

    },
    "FftCalculator\0fftCompleted\0\0"
    "Complex<double>*\0outputArray\0"
    "outputArraySize\0fftEnable\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FftCalculator[] = {

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
       1,    2,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   29,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void FftCalculator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FftCalculator *_t = static_cast<FftCalculator *>(_o);
        switch (_id) {
        case 0: _t->fftCompleted((*reinterpret_cast< Complex<double>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->fftEnable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FftCalculator::*_t)(Complex<double> * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FftCalculator::fftCompleted)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject FftCalculator::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FftCalculator.data,
      qt_meta_data_FftCalculator,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FftCalculator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FftCalculator::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FftCalculator.stringdata))
        return static_cast<void*>(const_cast< FftCalculator*>(this));
    return QObject::qt_metacast(_clname);
}

int FftCalculator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void FftCalculator::fftCompleted(Complex<double> * _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
