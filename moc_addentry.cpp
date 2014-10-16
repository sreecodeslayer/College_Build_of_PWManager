/****************************************************************************
** Meta object code from reading C++ file 'addentry.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "addentry.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addentry.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AddEntry_t {
    QByteArrayData data[8];
    char stringdata[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_AddEntry_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_AddEntry_t qt_meta_stringdata_AddEntry = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 20),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 32),
QT_MOC_LITERAL(4, 64, 16),
QT_MOC_LITERAL(5, 81, 4),
QT_MOC_LITERAL(6, 86, 24),
QT_MOC_LITERAL(7, 111, 16)
    },
    "AddEntry\0on_Ok_Button_clicked\0\0"
    "on_account_type_list_itemClicked\0"
    "QListWidgetItem*\0item\0on_Cancel_Button_clicked\0"
    "createConnection\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddEntry[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08,
       3,    1,   35,    2, 0x08,
       6,    0,   38,    2, 0x08,
       7,    0,   39,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void AddEntry::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddEntry *_t = static_cast<AddEntry *>(_o);
        switch (_id) {
        case 0: _t->on_Ok_Button_clicked(); break;
        case 1: _t->on_account_type_list_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->on_Cancel_Button_clicked(); break;
        case 3: { bool _r = _t->createConnection();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject AddEntry::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddEntry.data,
      qt_meta_data_AddEntry,  qt_static_metacall, 0, 0}
};


const QMetaObject *AddEntry::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddEntry::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddEntry.stringdata))
        return static_cast<void*>(const_cast< AddEntry*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddEntry::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
