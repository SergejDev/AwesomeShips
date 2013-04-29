/****************************************************************************
** Meta object code from reading C++ file 'gamewindow.h'
**
** Created: Fri 26. Apr 12:50:31 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gamewindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      31,   12,   11,   11, 0x05,
      55,   11,   11,   11, 0x25,
      75,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      89,   11,   11,   11, 0x0a,
     101,   11,   11,   11, 0x0a,
     114,   11,   11,   11, 0x08,
     126,   11,   11,   11, 0x08,
     141,  136,   11,   11, 0x08,
     182,  172,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GameWindow[] = {
    "GameWindow\0\0isGameWindowActive\0"
    "MenuButtonPressed(bool)\0MenuButtonPressed()\0"
    "EndGameFlag()\0PauseGame()\0ResumeGame()\0"
    "StartRead()\0EndGame()\0word\0"
    "InputFieldTextChanged(QString)\0shipIndex\0"
    "ShipDestroyedSlot(int)\0"
};

void GameWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GameWindow *_t = static_cast<GameWindow *>(_o);
        switch (_id) {
        case 0: _t->MenuButtonPressed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->MenuButtonPressed(); break;
        case 2: _t->EndGameFlag(); break;
        case 3: _t->PauseGame(); break;
        case 4: _t->ResumeGame(); break;
        case 5: _t->StartRead(); break;
        case 6: _t->EndGame(); break;
        case 7: _t->InputFieldTextChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->ShipDestroyedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GameWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GameWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GameWindow,
      qt_meta_data_GameWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameWindow))
        return static_cast<void*>(const_cast< GameWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int GameWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void GameWindow::MenuButtonPressed(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void GameWindow::EndGameFlag()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
