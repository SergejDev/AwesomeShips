/****************************************************************************
** Meta object code from reading C++ file 'gamecontroller.h'
**
** Created: Thu 23. May 23:38:20 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gamecontroller.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamecontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameController[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      43,   33,   15,   15, 0x05,
      67,   33,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      86,   15,   15,   15, 0x08,
     108,   15,   15,   15, 0x08,
     149,  127,   15,   15, 0x08,
     172,   33,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GameController[] = {
    "GameController\0\0GameAreaUpdate()\0"
    "shipIndex\0ShipOwercomeBorder(int)\0"
    "ShipDestroyed(int)\0AnimationsTimerSlot()\0"
    "AddShipTimerSlot()\0bulletIndex,shipIndex\0"
    "ShipHitedSlot(int,int)\0ShipDestroyedSlot(int)\0"
};

void GameController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GameController *_t = static_cast<GameController *>(_o);
        switch (_id) {
        case 0: _t->GameAreaUpdate(); break;
        case 1: _t->ShipOwercomeBorder((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->ShipDestroyed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->AnimationsTimerSlot(); break;
        case 4: _t->AddShipTimerSlot(); break;
        case 5: _t->ShipHitedSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->ShipDestroyedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GameController::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GameController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GameController,
      qt_meta_data_GameController, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameController))
        return static_cast<void*>(const_cast< GameController*>(this));
    return QObject::qt_metacast(_clname);
}

int GameController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void GameController::GameAreaUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void GameController::ShipOwercomeBorder(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GameController::ShipDestroyed(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
