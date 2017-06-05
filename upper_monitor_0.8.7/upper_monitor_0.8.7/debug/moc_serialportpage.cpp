/****************************************************************************
** Meta object code from reading C++ file 'serialportpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../serialportpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialportpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SerialportPage_t {
    QByteArrayData data[9];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialportPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialportPage_t qt_meta_stringdata_SerialportPage = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SerialportPage"
QT_MOC_LITERAL(1, 15, 21), // "on_openButton_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 19), // "on_sendData_clicked"
QT_MOC_LITERAL(4, 58, 23), // "on_clearRecData_clicked"
QT_MOC_LITERAL(5, 82, 24), // "on_clearSendData_clicked"
QT_MOC_LITERAL(6, 107, 21), // "on_refreshCom_clicked"
QT_MOC_LITERAL(7, 129, 7), // "recData"
QT_MOC_LITERAL(8, 137, 7) // "my_task"

    },
    "SerialportPage\0on_openButton_clicked\0"
    "\0on_sendData_clicked\0on_clearRecData_clicked\0"
    "on_clearSendData_clicked\0on_refreshCom_clicked\0"
    "recData\0my_task"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialportPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SerialportPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialportPage *_t = static_cast<SerialportPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_openButton_clicked(); break;
        case 1: _t->on_sendData_clicked(); break;
        case 2: _t->on_clearRecData_clicked(); break;
        case 3: _t->on_clearSendData_clicked(); break;
        case 4: _t->on_refreshCom_clicked(); break;
        case 5: _t->recData(); break;
        case 6: _t->my_task(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SerialportPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SerialportPage.data,
      qt_meta_data_SerialportPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SerialportPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialportPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SerialportPage.stringdata0))
        return static_cast<void*>(const_cast< SerialportPage*>(this));
    return QWidget::qt_metacast(_clname);
}

int SerialportPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
