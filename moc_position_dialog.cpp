/****************************************************************************
** Meta object code from reading C++ file 'position_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "views/position_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'position_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_position_dialog_t {
    QByteArrayData data[10];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_position_dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_position_dialog_t qt_meta_stringdata_position_dialog = {
    {
QT_MOC_LITERAL(0, 0, 15), // "position_dialog"
QT_MOC_LITERAL(1, 16, 17), // "on_bClose_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 17), // "on_bApply_clicked"
QT_MOC_LITERAL(4, 53, 31), // "on_listWidget_itemDoubleClicked"
QT_MOC_LITERAL(5, 85, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(6, 102, 4), // "item"
QT_MOC_LITERAL(7, 107, 18), // "on_bSelect_clicked"
QT_MOC_LITERAL(8, 126, 18), // "on_bDelete_clicked"
QT_MOC_LITERAL(9, 145, 15) // "on_bNew_clicked"

    },
    "position_dialog\0on_bClose_clicked\0\0"
    "on_bApply_clicked\0on_listWidget_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0on_bSelect_clicked\0"
    "on_bDelete_clicked\0on_bNew_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_position_dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    1,   46,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,
       8,    0,   50,    2, 0x08 /* Private */,
       9,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void position_dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        position_dialog *_t = static_cast<position_dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_bClose_clicked(); break;
        case 1: _t->on_bApply_clicked(); break;
        case 2: _t->on_listWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->on_bSelect_clicked(); break;
        case 4: _t->on_bDelete_clicked(); break;
        case 5: _t->on_bNew_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject position_dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_position_dialog.data,
      qt_meta_data_position_dialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *position_dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *position_dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_position_dialog.stringdata0))
        return static_cast<void*>(const_cast< position_dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int position_dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
