/****************************************************************************
** Meta object code from reading C++ file 'windowscontroller.h'
**
** Created: Fri 26. Apr 12:50:32 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../windowscontroller.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'windowscontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WindowsController[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      38,   19,   18,   18, 0x0a,
      59,   18,   18,   18, 0x2a,
      76,   19,   18,   18, 0x0a,
      95,   18,   18,   18, 0x2a,
     110,   18,   18,   18, 0x08,
     125,   18,   18,   18, 0x08,
     144,   18,   18,   18, 0x08,
     159,   18,   18,   18, 0x08,
     179,   18,   18,   18, 0x08,
     195,   18,   18,   18, 0x08,
     210,   18,   18,   18, 0x08,
     225,   18,   18,   18, 0x08,
     244,   18,   18,   18, 0x08,
     256,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_WindowsController[] = {
    "WindowsController\0\0isGameWindowActive\0"
    "ShowMenuWindow(bool)\0ShowMenuWindow()\0"
    "ShowGameMenu(bool)\0ShowGameMenu()\0"
    "ReturnToGame()\0GoToMainMenuSlot()\0"
    "RegisterSlot()\0RegisterStartRead()\0"
    "StartGameSlot()\0SettingsSlot()\0"
    "QuitGameSlot()\0ReturnToMenuSlot()\0"
    "StartRead()\0ConnectionTimeout()\0"
};

void WindowsController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        WindowsController *_t = static_cast<WindowsController *>(_o);
        switch (_id) {
        case 0: _t->ShowMenuWindow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->ShowMenuWindow(); break;
        case 2: _t->ShowGameMenu((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->ShowGameMenu(); break;
        case 4: _t->ReturnToGame(); break;
        case 5: _t->GoToMainMenuSlot(); break;
        case 6: _t->RegisterSlot(); break;
        case 7: _t->RegisterStartRead(); break;
        case 8: _t->StartGameSlot(); break;
        case 9: _t->SettingsSlot(); break;
        case 10: _t->QuitGameSlot(); break;
        case 11: _t->ReturnToMenuSlot(); break;
        case 12: _t->StartRead(); break;
        case 13: _t->ConnectionTimeout(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData WindowsController::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject WindowsController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WindowsController,
      qt_meta_data_WindowsController, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WindowsController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WindowsController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WindowsController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WindowsController))
        return static_cast<void*>(const_cast< WindowsController*>(this));
    return QObject::qt_metacast(_clname);
}

int WindowsController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
