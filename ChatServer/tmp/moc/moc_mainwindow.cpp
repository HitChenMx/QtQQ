/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[406];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 33), // "slot_action_startListen_trigg..."
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 32), // "slot_action_stopListen_triggered"
QT_MOC_LITERAL(4, 79, 33), // "slot_action_clearOutput_trigg..."
QT_MOC_LITERAL(5, 113, 26), // "slot_action_exit_triggered"
QT_MOC_LITERAL(6, 140, 27), // "slot_btnSendMessage_clicked"
QT_MOC_LITERAL(7, 168, 26), // "slot_lstClientView_clicked"
QT_MOC_LITERAL(8, 195, 5), // "index"
QT_MOC_LITERAL(9, 201, 32), // "slot_clientDatabaseConnectFailed"
QT_MOC_LITERAL(10, 234, 7), // "qintptr"
QT_MOC_LITERAL(11, 242, 16), // "socketDescriptor"
QT_MOC_LITERAL(12, 259, 20), // "slot_clientConnected"
QT_MOC_LITERAL(13, 280, 12), // "QHostAddress"
QT_MOC_LITERAL(14, 293, 7), // "address"
QT_MOC_LITERAL(15, 301, 4), // "port"
QT_MOC_LITERAL(16, 306, 23), // "slot_clientDisconnected"
QT_MOC_LITERAL(17, 330, 25), // "slot_receiveClientMessage"
QT_MOC_LITERAL(18, 356, 7), // "message"
QT_MOC_LITERAL(19, 364, 30), // "slot_sendClientMessageFinished"
QT_MOC_LITERAL(20, 395, 10) // "send_bytes"

    },
    "MainWindow\0slot_action_startListen_triggered\0"
    "\0slot_action_stopListen_triggered\0"
    "slot_action_clearOutput_triggered\0"
    "slot_action_exit_triggered\0"
    "slot_btnSendMessage_clicked\0"
    "slot_lstClientView_clicked\0index\0"
    "slot_clientDatabaseConnectFailed\0"
    "qintptr\0socketDescriptor\0slot_clientConnected\0"
    "QHostAddress\0address\0port\0"
    "slot_clientDisconnected\0"
    "slot_receiveClientMessage\0message\0"
    "slot_sendClientMessageFinished\0"
    "send_bytes"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    1,   74,    2, 0x08 /* Private */,
       9,    1,   77,    2, 0x08 /* Private */,
      12,    2,   80,    2, 0x08 /* Private */,
      16,    2,   85,    2, 0x08 /* Private */,
      17,    3,   90,    2, 0x08 /* Private */,
      19,    3,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13, QMetaType::UShort,   14,   15,
    QMetaType::Void, 0x80000000 | 13, QMetaType::UShort,   14,   15,
    QMetaType::Void, 0x80000000 | 13, QMetaType::UShort, QMetaType::QByteArray,   14,   15,   18,
    QMetaType::Void, 0x80000000 | 13, QMetaType::UShort, QMetaType::ULongLong,   14,   15,   20,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_action_startListen_triggered(); break;
        case 1: _t->slot_action_stopListen_triggered(); break;
        case 2: _t->slot_action_clearOutput_triggered(); break;
        case 3: _t->slot_action_exit_triggered(); break;
        case 4: _t->slot_btnSendMessage_clicked(); break;
        case 5: _t->slot_lstClientView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->slot_clientDatabaseConnectFailed((*reinterpret_cast< qintptr(*)>(_a[1]))); break;
        case 7: _t->slot_clientConnected((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2]))); break;
        case 8: _t->slot_clientDisconnected((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2]))); break;
        case 9: _t->slot_receiveClientMessage((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        case 10: _t->slot_sendClientMessageFinished((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2])),(*reinterpret_cast< const quint64(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
