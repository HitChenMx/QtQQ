/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../main/mainwindow.h"
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
    QByteArrayData data[27];
    char stringdata0[444];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 24), // "signal_closeSocketThread"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 23), // "signal_updateGroupNames"
QT_MOC_LITERAL(4, 61, 27), // "slot_launchAddFriendRequest"
QT_MOC_LITERAL(5, 89, 7), // "send_id"
QT_MOC_LITERAL(6, 97, 13), // "sttClientInfo"
QT_MOC_LITERAL(7, 111, 15), // "rcv_client_info"
QT_MOC_LITERAL(8, 127, 10), // "verify_msg"
QT_MOC_LITERAL(9, 138, 14), // "which_group_id"
QT_MOC_LITERAL(10, 153, 23), // "slot_receiveChatMessage"
QT_MOC_LITERAL(11, 177, 6), // "rcv_id"
QT_MOC_LITERAL(12, 184, 8), // "chat_msg"
QT_MOC_LITERAL(13, 193, 21), // "slot_updateFriendInfo"
QT_MOC_LITERAL(14, 215, 9), // "friend_id"
QT_MOC_LITERAL(15, 225, 13), // "sttFriendInfo"
QT_MOC_LITERAL(16, 239, 18), // "friend_update_info"
QT_MOC_LITERAL(17, 258, 25), // "slot_btnAddFriend_clicked"
QT_MOC_LITERAL(18, 284, 27), // "slot_btnFriendsInfo_clicked"
QT_MOC_LITERAL(19, 312, 28), // "slot_receiveAddFriendRequest"
QT_MOC_LITERAL(20, 341, 14), // "send_user_info"
QT_MOC_LITERAL(21, 356, 8), // "group_id"
QT_MOC_LITERAL(22, 365, 23), // "slot_receiveUserHeadPic"
QT_MOC_LITERAL(23, 389, 7), // "user_id"
QT_MOC_LITERAL(24, 397, 8), // "pic_path"
QT_MOC_LITERAL(25, 406, 23), // "slot_receiveChatPicture"
QT_MOC_LITERAL(26, 430, 13) // "chat_pic_path"

    },
    "MainWindow\0signal_closeSocketThread\0"
    "\0signal_updateGroupNames\0"
    "slot_launchAddFriendRequest\0send_id\0"
    "sttClientInfo\0rcv_client_info\0verify_msg\0"
    "which_group_id\0slot_receiveChatMessage\0"
    "rcv_id\0chat_msg\0slot_updateFriendInfo\0"
    "friend_id\0sttFriendInfo\0friend_update_info\0"
    "slot_btnAddFriend_clicked\0"
    "slot_btnFriendsInfo_clicked\0"
    "slot_receiveAddFriendRequest\0"
    "send_user_info\0group_id\0slot_receiveUserHeadPic\0"
    "user_id\0pic_path\0slot_receiveChatPicture\0"
    "chat_pic_path"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    4,   66,    2, 0x0a /* Public */,
      10,    3,   75,    2, 0x08 /* Private */,
      13,    2,   82,    2, 0x08 /* Private */,
      17,    0,   87,    2, 0x08 /* Private */,
      18,    0,   88,    2, 0x08 /* Private */,
      19,    4,   89,    2, 0x08 /* Private */,
      22,    2,   98,    2, 0x08 /* Private */,
      25,    3,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 6, QMetaType::QString, QMetaType::UInt,    5,    7,    8,    9,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::QString,    5,   11,   12,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 15,   14,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 6, QMetaType::QString, QMetaType::UInt,   11,   20,    8,   21,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString,   23,   24,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::QString,    5,   11,   26,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_closeSocketThread(); break;
        case 1: _t->signal_updateGroupNames(); break;
        case 2: _t->slot_launchAddFriendRequest((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const sttClientInfo(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const quint32(*)>(_a[4]))); break;
        case 3: _t->slot_receiveChatMessage((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const quint32(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 4: _t->slot_updateFriendInfo((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const sttFriendInfo(*)>(_a[2]))); break;
        case 5: _t->slot_btnAddFriend_clicked(); break;
        case 6: _t->slot_btnFriendsInfo_clicked(); break;
        case 7: _t->slot_receiveAddFriendRequest((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const sttClientInfo(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const quint32(*)>(_a[4]))); break;
        case 8: _t->slot_receiveUserHeadPic((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 9: _t->slot_receiveChatPicture((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const quint32(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::signal_closeSocketThread)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::signal_updateGroupNames)) {
                *result = 1;
                return;
            }
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signal_closeSocketThread()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::signal_updateGroupNames()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
