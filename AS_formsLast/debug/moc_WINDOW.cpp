/****************************************************************************
** Meta object code from reading C++ file 'WINDOW.h'
**
** Created: Mon 4. Mar 22:24:41 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WINDOW.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WINDOW.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ToolsWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      33,   12,   12,   12, 0x05,
      53,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      73,   12,   12,   12, 0x08,
      98,   12,   12,   12, 0x08,
     122,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ToolsWindow[] = {
    "ToolsWindow\0\0ButtonSaveClicked()\0"
    "ButtonBackClicked()\0ButtonBazaClicked()\0"
    "on_button_Save_clicked()\0"
    "ButtonBackClickedSlot()\0button_baza_clicked()\0"
};

void ToolsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ToolsWindow *_t = static_cast<ToolsWindow *>(_o);
        switch (_id) {
        case 0: _t->ButtonSaveClicked(); break;
        case 1: _t->ButtonBackClicked(); break;
        case 2: _t->ButtonBazaClicked(); break;
        case 3: _t->on_button_Save_clicked(); break;
        case 4: _t->ButtonBackClickedSlot(); break;
        case 5: _t->button_baza_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ToolsWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ToolsWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ToolsWindow,
      qt_meta_data_ToolsWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ToolsWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ToolsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ToolsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ToolsWindow))
        return static_cast<void*>(const_cast< ToolsWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int ToolsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ToolsWindow::ButtonSaveClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ToolsWindow::ButtonBackClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ToolsWindow::ButtonBazaClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
