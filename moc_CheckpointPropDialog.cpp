/****************************************************************************
** Meta object code from reading C++ file 'CheckpointPropDialog.h'
**
** Created: Wed Jul 31 17:19:38 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CheckpointPropDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CheckpointPropDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CheckpointPropDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x0a,
      49,   41,   21,   21, 0x0a,
      70,   41,   21,   21, 0x0a,
      88,   41,   21,   21, 0x0a,
     106,   41,   21,   21, 0x0a,
     125,   41,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CheckpointPropDialog[] = {
    "CheckpointPropDialog\0\0manualUpdateData()\0"
    "checked\0r30Min_toogled(bool)\0"
    "r1h_toogled(bool)\0r8h_toogled(bool)\0"
    "r24h_toogled(bool)\0rManual_toogled(bool)\0"
};

void CheckpointPropDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CheckpointPropDialog *_t = static_cast<CheckpointPropDialog *>(_o);
        switch (_id) {
        case 0: _t->manualUpdateData(); break;
        case 1: _t->r30Min_toogled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->r1h_toogled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->r8h_toogled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->r24h_toogled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->rManual_toogled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CheckpointPropDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CheckpointPropDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CheckpointPropDialog,
      qt_meta_data_CheckpointPropDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CheckpointPropDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CheckpointPropDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CheckpointPropDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CheckpointPropDialog))
        return static_cast<void*>(const_cast< CheckpointPropDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CheckpointPropDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
