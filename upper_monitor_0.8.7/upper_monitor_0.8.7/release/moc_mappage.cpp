/****************************************************************************
** Meta object code from reading C++ file 'mappage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mappage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mappage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MapPage_t {
    QByteArrayData data[21];
    char stringdata0[384];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MapPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MapPage_t qt_meta_stringdata_MapPage = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MapPage"
QT_MOC_LITERAL(1, 8, 13), // "addJavaScript"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 15), // "setGoalPosition"
QT_MOC_LITERAL(4, 39, 12), // "sendData2Web"
QT_MOC_LITERAL(5, 52, 1), // "x"
QT_MOC_LITERAL(6, 54, 1), // "y"
QT_MOC_LITERAL(7, 56, 3), // "num"
QT_MOC_LITERAL(8, 60, 20), // "drawPointTimerUpdate"
QT_MOC_LITERAL(9, 81, 24), // "on_takeoffButton_clicked"
QT_MOC_LITERAL(10, 106, 21), // "on_landButton_clicked"
QT_MOC_LITERAL(11, 128, 28), // "on_urgencyStopButton_clicked"
QT_MOC_LITERAL(12, 157, 31), // "on_setCenterPointButton_clicked"
QT_MOC_LITERAL(13, 189, 26), // "on_clearAllMarkers_clicked"
QT_MOC_LITERAL(14, 216, 26), // "on_clearGoalButton_clicked"
QT_MOC_LITERAL(15, 243, 27), // "on_selectGoalButton_clicked"
QT_MOC_LITERAL(16, 271, 29), // "on_startMissionButton_clicked"
QT_MOC_LITERAL(17, 301, 35), // "on_checkCommunicationButton_c..."
QT_MOC_LITERAL(18, 337, 18), // "receiveDataFromWeb"
QT_MOC_LITERAL(19, 356, 16), // "updateFocusValue"
QT_MOC_LITERAL(20, 373, 10) // "enableForm"

    },
    "MapPage\0addJavaScript\0\0setGoalPosition\0"
    "sendData2Web\0x\0y\0num\0drawPointTimerUpdate\0"
    "on_takeoffButton_clicked\0on_landButton_clicked\0"
    "on_urgencyStopButton_clicked\0"
    "on_setCenterPointButton_clicked\0"
    "on_clearAllMarkers_clicked\0"
    "on_clearGoalButton_clicked\0"
    "on_selectGoalButton_clicked\0"
    "on_startMissionButton_clicked\0"
    "on_checkCommunicationButton_clicked\0"
    "receiveDataFromWeb\0updateFocusValue\0"
    "enableForm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MapPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    3,   96,    2, 0x08 /* Private */,
       8,    0,  103,    2, 0x08 /* Private */,
       9,    0,  104,    2, 0x08 /* Private */,
      10,    0,  105,    2, 0x08 /* Private */,
      11,    0,  106,    2, 0x08 /* Private */,
      12,    0,  107,    2, 0x08 /* Private */,
      13,    0,  108,    2, 0x08 /* Private */,
      14,    0,  109,    2, 0x08 /* Private */,
      15,    0,  110,    2, 0x08 /* Private */,
      16,    0,  111,    2, 0x08 /* Private */,
      17,    0,  112,    2, 0x08 /* Private */,
      18,    0,  113,    2, 0x08 /* Private */,
      19,    0,  114,    2, 0x08 /* Private */,
      20,    0,  115,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    5,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MapPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MapPage *_t = static_cast<MapPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addJavaScript(); break;
        case 1: _t->setGoalPosition(); break;
        case 2: _t->sendData2Web((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->drawPointTimerUpdate(); break;
        case 4: _t->on_takeoffButton_clicked(); break;
        case 5: _t->on_landButton_clicked(); break;
        case 6: _t->on_urgencyStopButton_clicked(); break;
        case 7: _t->on_setCenterPointButton_clicked(); break;
        case 8: _t->on_clearAllMarkers_clicked(); break;
        case 9: _t->on_clearGoalButton_clicked(); break;
        case 10: _t->on_selectGoalButton_clicked(); break;
        case 11: _t->on_startMissionButton_clicked(); break;
        case 12: _t->on_checkCommunicationButton_clicked(); break;
        case 13: _t->receiveDataFromWeb(); break;
        case 14: _t->updateFocusValue(); break;
        case 15: _t->enableForm(); break;
        default: ;
        }
    }
}

const QMetaObject MapPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MapPage.data,
      qt_meta_data_MapPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MapPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MapPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MapPage.stringdata0))
        return static_cast<void*>(const_cast< MapPage*>(this));
    return QWidget::qt_metacast(_clname);
}

int MapPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
