/****************************************************************************
** Meta object code from reading C++ file 'baza.h'
**
** Created: Wed 22. May 13:40:19 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../baza.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'baza.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Baza[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x05,
      26,    5,    5,    5, 0x05,
      39,    5,    5,    5, 0x05,
      52,    5,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
      67,    5,    5,    5, 0x08,
      91,    5,    5,    5, 0x08,
     117,    5,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Baza[] = {
    "Baza\0\0ButtonBackClicked()\0ButtonBack()\0"
    "ButtonOpen()\0ButtonImport()\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_3_clicked()\0"
};

void Baza::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Baza *_t = static_cast<Baza *>(_o);
        switch (_id) {
        case 0: _t->ButtonBackClicked(); break;
        case 1: _t->ButtonBack(); break;
        case 2: _t->ButtonOpen(); break;
        case 3: _t->ButtonImport(); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->on_pushButton_3_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Baza::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Baza::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Baza,
      qt_meta_data_Baza, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Baza::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Baza::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Baza::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Baza))
        return static_cast<void*>(const_cast< Baza*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Baza::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void Baza::ButtonBackClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Baza::ButtonBack()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Baza::ButtonOpen()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Baza::ButtonImport()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
