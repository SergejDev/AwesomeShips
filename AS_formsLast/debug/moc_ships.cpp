/****************************************************************************
** Meta object code from reading C++ file 'ships.h'
**
** Created: Fri 26. Apr 12:50:25 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ships.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ships.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Ships[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,
      39,   29,    6,    6, 0x05,
      70,   63,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      89,    6,    6,    6, 0x08,
     121,   29,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Ships[] = {
    "Ships\0\0ShipsPositionUpdate()\0shipIndex\0"
    "ShipOwercomeBorder(int)\0points\0"
    "ShipDestroyed(int)\0MooveShipsAnimationsTimerSlot()\0"
    "OvercomeBorderSlot(int)\0"
};

void Ships::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Ships *_t = static_cast<Ships *>(_o);
        switch (_id) {
        case 0: _t->ShipsPositionUpdate(); break;
        case 1: _t->ShipOwercomeBorder((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->ShipDestroyed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->MooveShipsAnimationsTimerSlot(); break;
        case 4: _t->OvercomeBorderSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Ships::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Ships::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Ships,
      qt_meta_data_Ships, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Ships::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Ships::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Ships::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ships))
        return static_cast<void*>(const_cast< Ships*>(this));
    return QObject::qt_metacast(_clname);
}

int Ships::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Ships::ShipsPositionUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Ships::ShipOwercomeBorder(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Ships::ShipDestroyed(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
