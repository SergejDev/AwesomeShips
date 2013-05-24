/****************************************************************************
** Meta object code from reading C++ file 'menuwindow.h'
**
** Created: Thu 23. May 23:41:41 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../menuwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menuwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MenuWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      33,   11,   11,   11, 0x05,
      57,   11,   11,   11, 0x05,
      81,   11,   11,   11, 0x05,

 // methods: signature, parameters, type, tag, flags
     101,   11,   11,   11, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_MenuWindow[] = {
    "MenuWindow\0\0StartButtonPressed()\0"
    "RegisterButtonPressed()\0SettingsButtonPressed()\0"
    "QuitButtonPressed()\0GetUserData()\0"
};

void MenuWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MenuWindow *_t = static_cast<MenuWindow *>(_o);
        switch (_id) {
        case 0: _t->StartButtonPressed(); break;
        case 1: _t->RegisterButtonPressed(); break;
        case 2: _t->SettingsButtonPressed(); break;
        case 3: _t->QuitButtonPressed(); break;
        case 4: _t->GetUserData(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MenuWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MenuWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MenuWindow,
      qt_meta_data_MenuWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MenuWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MenuWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MenuWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MenuWindow))
        return static_cast<void*>(const_cast< MenuWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MenuWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void MenuWindow::StartButtonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MenuWindow::RegisterButtonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MenuWindow::SettingsButtonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MenuWindow::QuitButtonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
