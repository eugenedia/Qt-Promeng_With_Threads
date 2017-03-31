/****************************************************************************
** Meta object code from reading C++ file 'TableEditDialog.h'
**
** Created: Wed Jul 31 17:19:31 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TableEditDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TableEditDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TableEditDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      28,   16,   16,   16, 0x0a,
      40,   16,   16,   16, 0x0a,
      55,   16,   16,   16, 0x0a,
      76,   16,   16,   16, 0x0a,
      90,   16,   16,   16, 0x0a,
     111,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TableEditDialog[] = {
    "TableEditDialog\0\0saveData()\0addRecord()\0"
    "removeRecord()\0onCancelBtnClicked()\0"
    "onOkClicked()\0onInsertBtnClicked()\0"
    "onDeleteBtnClicked()\0"
};

void TableEditDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TableEditDialog *_t = static_cast<TableEditDialog *>(_o);
        switch (_id) {
        case 0: _t->saveData(); break;
        case 1: _t->addRecord(); break;
        case 2: _t->removeRecord(); break;
        case 3: _t->onCancelBtnClicked(); break;
        case 4: _t->onOkClicked(); break;
        case 5: _t->onInsertBtnClicked(); break;
        case 6: _t->onDeleteBtnClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData TableEditDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TableEditDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TableEditDialog,
      qt_meta_data_TableEditDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TableEditDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TableEditDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TableEditDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TableEditDialog))
        return static_cast<void*>(const_cast< TableEditDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int TableEditDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
