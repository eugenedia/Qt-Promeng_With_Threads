/****************************************************************************
** Meta object code from reading C++ file 'db_signal.h'
**
** Created: Wed Jul 31 17:19:24 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "db_signal.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'db_signal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_db_Signal[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      81,   61,   45,   10, 0x0a,
     156,  114,   45,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_db_Signal[] = {
    "db_Signal\0\0vSignal\0writeToDialog(vec_signal)\0"
    "QVector<Signal>\0dataTime1,dataTime2\0"
    "loadTableSignal(QString,QString)\0"
    "dataTime1,dataTime2,SelectedGuidSignal,sq\0"
    "loadArchiveTableSignal(QDateTime,QDateTime,int,QSqlDatabase)\0"
};

void db_Signal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        db_Signal *_t = static_cast<db_Signal *>(_o);
        switch (_id) {
        case 0: _t->writeToDialog((*reinterpret_cast< vec_signal(*)>(_a[1]))); break;
        case 1: { QVector<Signal> _r = _t->loadTableSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVector<Signal>*>(_a[0]) = _r; }  break;
        case 2: { QVector<Signal> _r = _t->loadArchiveTableSignal((*reinterpret_cast< QDateTime(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlDatabase(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QVector<Signal>*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData db_Signal::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject db_Signal::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_db_Signal,
      qt_meta_data_db_Signal, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &db_Signal::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *db_Signal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *db_Signal::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_db_Signal))
        return static_cast<void*>(const_cast< db_Signal*>(this));
    return QThread::qt_metacast(_clname);
}

int db_Signal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void db_Signal::writeToDialog(vec_signal _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
