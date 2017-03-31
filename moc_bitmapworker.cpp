/****************************************************************************
** Meta object code from reading C++ file 'bitmapworker.h'
**
** Created: Wed Jul 31 17:19:22 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "bitmapworker.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bitmapworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BitmapWorker[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      43,   33,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BitmapWorker[] = {
    "BitmapWorker\0\0deviceProperties()\0"
    "vecSignal\0writeSignal(vec_signal)\0"
};

void BitmapWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BitmapWorker *_t = static_cast<BitmapWorker *>(_o);
        switch (_id) {
        case 0: _t->deviceProperties(); break;
        case 1: _t->writeSignal((*reinterpret_cast< vec_signal(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BitmapWorker::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BitmapWorker::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BitmapWorker,
      qt_meta_data_BitmapWorker, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BitmapWorker::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BitmapWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BitmapWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BitmapWorker))
        return static_cast<void*>(const_cast< BitmapWorker*>(this));
    return QWidget::qt_metacast(_clname);
}

int BitmapWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
