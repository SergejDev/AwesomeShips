/****************************************************************************
** Meta object code from reading C++ file 'gamemenu.h'
**
** Created: Wed 22. May 13:40:25 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gamemenu.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamemenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_gamemenu[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      37,    9,    9,    9, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_gamemenu[] = {
    "gamemenu\0\0ResumeGameButton_Pressed()\0"
    "BackToMenuButton_Pressed()\0"
};

void gamemenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        gamemenu *_t = static_cast<gamemenu *>(_o);
        switch (_id) {
        case 0: _t->ResumeGameButton_Pressed(); break;
        case 1: _t->BackToMenuButton_Pressed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData gamemenu::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject gamemenu::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_gamemenu,
      qt_meta_data_gamemenu, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &gamemenu::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *gamemenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *gamemenu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_gamemenu))
        return static_cast<void*>(const_cast< gamemenu*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int gamemenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void gamemenu::ResumeGameButton_Pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void gamemenu::BackToMenuButton_Pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
