/****************************************************************************
** Meta object code from reading C++ file 'bullets.h'
**
** Created: Wed 22. May 13:39:51 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../bullets.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bullets.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Bullets[] = {

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
       9,    8,    8,    8, 0x05,
      55,   33,    8,    8, 0x05,
      71,   33,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      88,    8,    8,    8, 0x08,
     122,   33,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Bullets[] = {
    "Bullets\0\0BulletsPositionUpdate()\0"
    "bulletIndex,shipIndex\0AimHit(int,int)\0"
    "ShipHit(int,int)\0MooveBulletsAnimationsTimerSlot()\0"
    "AimHitSlot(int,int)\0"
};

void Bullets::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Bullets *_t = static_cast<Bullets *>(_o);
        switch (_id) {
        case 0: _t->BulletsPositionUpdate(); break;
        case 1: _t->AimHit((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->ShipHit((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->MooveBulletsAnimationsTimerSlot(); break;
        case 4: _t->AimHitSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Bullets::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Bullets::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Bullets,
      qt_meta_data_Bullets, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Bullets::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Bullets::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Bullets::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Bullets))
        return static_cast<void*>(const_cast< Bullets*>(this));
    return QObject::qt_metacast(_clname);
}

int Bullets::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Bullets::BulletsPositionUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Bullets::AimHit(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Bullets::ShipHit(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE