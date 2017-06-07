/****************************************************************************
** Meta object code from reading C++ file 'returnvlc.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Ground_Station/returnvlc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'returnvlc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Returnvlc_t {
    QByteArrayData data[7];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Returnvlc_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Returnvlc_t qt_meta_stringdata_Returnvlc = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Returnvlc"
QT_MOC_LITERAL(1, 10, 11), // "returnValue"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 7), // "openVLC"
QT_MOC_LITERAL(4, 31, 5), // "info1"
QT_MOC_LITERAL(5, 37, 5), // "info2"
QT_MOC_LITERAL(6, 43, 5) // "info3"

    },
    "Returnvlc\0returnValue\0\0openVLC\0info1\0"
    "info2\0info3"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Returnvlc[] = {

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
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    3,   25,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    5,    6,

       0        // eod
};

void Returnvlc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Returnvlc *_t = static_cast<Returnvlc *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returnValue(); break;
        case 1: _t->openVLC((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Returnvlc::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Returnvlc::returnValue)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Returnvlc::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Returnvlc.data,
      qt_meta_data_Returnvlc,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Returnvlc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Returnvlc::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Returnvlc.stringdata0))
        return static_cast<void*>(const_cast< Returnvlc*>(this));
    return QObject::qt_metacast(_clname);
}

int Returnvlc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Returnvlc::returnValue()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
