/****************************************************************************
** Meta object code from reading C++ file 'multiplayergui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CPS111BrickBreaker/multiplayergui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'multiplayergui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MultiplayerGUI_t {
    QByteArrayData data[11];
    char stringdata[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MultiplayerGUI_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MultiplayerGUI_t qt_meta_stringdata_MultiplayerGUI = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 15),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 18),
QT_MOC_LITERAL(4, 51, 12),
QT_MOC_LITERAL(5, 64, 25),
QT_MOC_LITERAL(6, 90, 21),
QT_MOC_LITERAL(7, 112, 18),
QT_MOC_LITERAL(8, 131, 18),
QT_MOC_LITERAL(9, 150, 15),
QT_MOC_LITERAL(10, 166, 21)
    },
    "MultiplayerGUI\0clientConnected\0\0"
    "clientDisconnected\0dataRecieved\0"
    "on_btnStartServer_clicked\0"
    "on_btnConnect_clicked\0clientDataRecieved\0"
    "serverDisconnected\0processFinished\0"
    "serverProcessFinished\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MultiplayerGUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08,
       3,    0,   60,    2, 0x08,
       4,    0,   61,    2, 0x08,
       5,    0,   62,    2, 0x08,
       6,    0,   63,    2, 0x08,
       7,    0,   64,    2, 0x08,
       8,    0,   65,    2, 0x08,
       9,    0,   66,    2, 0x08,
      10,    0,   67,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MultiplayerGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MultiplayerGUI *_t = static_cast<MultiplayerGUI *>(_o);
        switch (_id) {
        case 0: _t->clientConnected(); break;
        case 1: _t->clientDisconnected(); break;
        case 2: _t->dataRecieved(); break;
        case 3: _t->on_btnStartServer_clicked(); break;
        case 4: _t->on_btnConnect_clicked(); break;
        case 5: _t->clientDataRecieved(); break;
        case 6: _t->serverDisconnected(); break;
        case 7: _t->processFinished(); break;
        case 8: _t->serverProcessFinished(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MultiplayerGUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MultiplayerGUI.data,
      qt_meta_data_MultiplayerGUI,  qt_static_metacall, 0, 0}
};


const QMetaObject *MultiplayerGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MultiplayerGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MultiplayerGUI.stringdata))
        return static_cast<void*>(const_cast< MultiplayerGUI*>(this));
    return QWidget::qt_metacast(_clname);
}

int MultiplayerGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
