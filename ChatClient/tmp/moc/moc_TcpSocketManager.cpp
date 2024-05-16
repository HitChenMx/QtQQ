/****************************************************************************
** Meta object code from reading C++ file 'TcpSocketManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../utils/TcpSocketManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TcpSocketManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpSocketManager_t {
    QByteArrayData data[54];
    char stringdata0[989];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpSocketManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpSocketManager_t qt_meta_stringdata_TcpSocketManager = {
    {
QT_MOC_LITERAL(0, 0, 16), // "TcpSocketManager"
QT_MOC_LITERAL(1, 17, 22), // "signal_socketConnected"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 25), // "signal_socketDisconnected"
QT_MOC_LITERAL(4, 67, 26), // "signal_socketConnectFailed"
QT_MOC_LITERAL(5, 94, 25), // "signal_socketReadFinished"
QT_MOC_LITERAL(6, 120, 7), // "message"
QT_MOC_LITERAL(7, 128, 22), // "signal_registerSuccess"
QT_MOC_LITERAL(8, 151, 21), // "signal_registerFailed"
QT_MOC_LITERAL(9, 173, 6), // "reason"
QT_MOC_LITERAL(10, 180, 19), // "signal_loginSuccess"
QT_MOC_LITERAL(11, 200, 13), // "sttClientInfo"
QT_MOC_LITERAL(12, 214, 11), // "client_info"
QT_MOC_LITERAL(13, 226, 26), // "QMap<quint32,sttGroupInfo>"
QT_MOC_LITERAL(14, 253, 14), // "all_group_info"
QT_MOC_LITERAL(15, 268, 18), // "signal_loginFailed"
QT_MOC_LITERAL(16, 287, 28), // "signal_modifyUserInfoSuccess"
QT_MOC_LITERAL(17, 316, 27), // "signal_modifyUserInfoFailed"
QT_MOC_LITERAL(18, 344, 22), // "signal_addGroupSuccess"
QT_MOC_LITERAL(19, 367, 12), // "new_group_id"
QT_MOC_LITERAL(20, 380, 10), // "group_name"
QT_MOC_LITERAL(21, 391, 21), // "signal_addGroupFailed"
QT_MOC_LITERAL(22, 413, 17), // "signal_userOnline"
QT_MOC_LITERAL(23, 431, 7), // "user_id"
QT_MOC_LITERAL(24, 439, 18), // "signal_userOffline"
QT_MOC_LITERAL(25, 458, 21), // "signal_receiveChatMsg"
QT_MOC_LITERAL(26, 480, 7), // "send_id"
QT_MOC_LITERAL(27, 488, 6), // "rcv_id"
QT_MOC_LITERAL(28, 495, 8), // "chat_msg"
QT_MOC_LITERAL(29, 504, 31), // "signal_receiveSearchUserRecords"
QT_MOC_LITERAL(30, 536, 11), // "search_text"
QT_MOC_LITERAL(31, 548, 22), // "QVector<sttFriendInfo>"
QT_MOC_LITERAL(32, 571, 19), // "search_user_records"
QT_MOC_LITERAL(33, 591, 30), // "signal_receiveAddFriendRequest"
QT_MOC_LITERAL(34, 622, 14), // "send_user_info"
QT_MOC_LITERAL(35, 637, 10), // "verify_msg"
QT_MOC_LITERAL(36, 648, 8), // "group_id"
QT_MOC_LITERAL(37, 657, 36), // "signal_receiveRejectAddFriend..."
QT_MOC_LITERAL(38, 694, 12), // "rcv_group_id"
QT_MOC_LITERAL(39, 707, 35), // "signal_receiveAgreeAddFriendR..."
QT_MOC_LITERAL(40, 743, 19), // "rcv_select_group_id"
QT_MOC_LITERAL(41, 763, 13), // "sttFriendInfo"
QT_MOC_LITERAL(42, 777, 15), // "new_friend_info"
QT_MOC_LITERAL(43, 793, 30), // "signal_receiveUpdateFriendInfo"
QT_MOC_LITERAL(44, 824, 9), // "friend_id"
QT_MOC_LITERAL(45, 834, 18), // "friend_update_info"
QT_MOC_LITERAL(46, 853, 25), // "signal_receiveUserHeadPic"
QT_MOC_LITERAL(47, 879, 8), // "pic_path"
QT_MOC_LITERAL(48, 888, 21), // "signal_receiveChatPic"
QT_MOC_LITERAL(49, 910, 13), // "chat_pic_path"
QT_MOC_LITERAL(50, 924, 9), // "slot_init"
QT_MOC_LITERAL(51, 934, 16), // "slot_closeSocket"
QT_MOC_LITERAL(52, 951, 16), // "slot_socketWrite"
QT_MOC_LITERAL(53, 968, 20) // "slot_socketReadyRead"

    },
    "TcpSocketManager\0signal_socketConnected\0"
    "\0signal_socketDisconnected\0"
    "signal_socketConnectFailed\0"
    "signal_socketReadFinished\0message\0"
    "signal_registerSuccess\0signal_registerFailed\0"
    "reason\0signal_loginSuccess\0sttClientInfo\0"
    "client_info\0QMap<quint32,sttGroupInfo>\0"
    "all_group_info\0signal_loginFailed\0"
    "signal_modifyUserInfoSuccess\0"
    "signal_modifyUserInfoFailed\0"
    "signal_addGroupSuccess\0new_group_id\0"
    "group_name\0signal_addGroupFailed\0"
    "signal_userOnline\0user_id\0signal_userOffline\0"
    "signal_receiveChatMsg\0send_id\0rcv_id\0"
    "chat_msg\0signal_receiveSearchUserRecords\0"
    "search_text\0QVector<sttFriendInfo>\0"
    "search_user_records\0signal_receiveAddFriendRequest\0"
    "send_user_info\0verify_msg\0group_id\0"
    "signal_receiveRejectAddFriendRequest\0"
    "rcv_group_id\0signal_receiveAgreeAddFriendRequest\0"
    "rcv_select_group_id\0sttFriendInfo\0"
    "new_friend_info\0signal_receiveUpdateFriendInfo\0"
    "friend_id\0friend_update_info\0"
    "signal_receiveUserHeadPic\0pic_path\0"
    "signal_receiveChatPic\0chat_pic_path\0"
    "slot_init\0slot_closeSocket\0slot_socketWrite\0"
    "slot_socketReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpSocketManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      22,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  144,    2, 0x06 /* Public */,
       3,    0,  145,    2, 0x06 /* Public */,
       4,    0,  146,    2, 0x06 /* Public */,
       5,    1,  147,    2, 0x06 /* Public */,
       7,    0,  150,    2, 0x06 /* Public */,
       8,    1,  151,    2, 0x06 /* Public */,
      10,    2,  154,    2, 0x06 /* Public */,
      15,    1,  159,    2, 0x06 /* Public */,
      16,    1,  162,    2, 0x06 /* Public */,
      17,    0,  165,    2, 0x06 /* Public */,
      18,    2,  166,    2, 0x06 /* Public */,
      21,    0,  171,    2, 0x06 /* Public */,
      22,    1,  172,    2, 0x06 /* Public */,
      24,    1,  175,    2, 0x06 /* Public */,
      25,    3,  178,    2, 0x06 /* Public */,
      29,    2,  185,    2, 0x06 /* Public */,
      33,    4,  190,    2, 0x06 /* Public */,
      37,    3,  199,    2, 0x06 /* Public */,
      39,    3,  206,    2, 0x06 /* Public */,
      43,    2,  213,    2, 0x06 /* Public */,
      46,    2,  218,    2, 0x06 /* Public */,
      48,    3,  223,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      50,    0,  230,    2, 0x0a /* Public */,
      51,    0,  231,    2, 0x0a /* Public */,
      52,    1,  232,    2, 0x0a /* Public */,
      53,    0,  235,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 13,   12,   14,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString,   19,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,   23,
    QMetaType::Void, QMetaType::UInt,   23,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::QString,   26,   27,   28,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 31,   30,   32,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 11, QMetaType::QString, QMetaType::UInt,   27,   34,   35,   36,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,   27,   26,   38,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, 0x80000000 | 41,   27,   40,   42,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 41,   44,   45,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString,   23,   47,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::QString,   26,   27,   49,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void,

       0        // eod
};

void TcpSocketManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpSocketManager *_t = static_cast<TcpSocketManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_socketConnected(); break;
        case 1: _t->signal_socketDisconnected(); break;
        case 2: _t->signal_socketConnectFailed(); break;
        case 3: _t->signal_socketReadFinished((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 4: _t->signal_registerSuccess(); break;
        case 5: _t->signal_registerFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->signal_loginSuccess((*reinterpret_cast< const sttClientInfo(*)>(_a[1])),(*reinterpret_cast< const QMap<quint32,sttGroupInfo>(*)>(_a[2]))); break;
        case 7: _t->signal_loginFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->signal_modifyUserInfoSuccess((*reinterpret_cast< const sttClientInfo(*)>(_a[1]))); break;
        case 9: _t->signal_modifyUserInfoFailed(); break;
        case 10: _t->signal_addGroupSuccess((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 11: _t->signal_addGroupFailed(); break;
        case 12: _t->signal_userOnline((*reinterpret_cast< const quint32(*)>(_a[1]))); break;
        case 13: _t->signal_userOffline((*reinterpret_cast< const quint32(*)>(_a[1]))); break;
        case 14: _t->signal_receiveChatMsg((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const quint32(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 15: _t->signal_receiveSearchUserRecords((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVector<sttFriendInfo>(*)>(_a[2]))); break;
        case 16: _t->signal_receiveAddFriendRequest((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const sttClientInfo(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const quint32(*)>(_a[4]))); break;
        case 17: _t->signal_receiveRejectAddFriendRequest((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const quint32(*)>(_a[2])),(*reinterpret_cast< const quint32(*)>(_a[3]))); break;
        case 18: _t->signal_receiveAgreeAddFriendRequest((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const quint32(*)>(_a[2])),(*reinterpret_cast< const sttFriendInfo(*)>(_a[3]))); break;
        case 19: _t->signal_receiveUpdateFriendInfo((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const sttFriendInfo(*)>(_a[2]))); break;
        case 20: _t->signal_receiveUserHeadPic((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 21: _t->signal_receiveChatPic((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const quint32(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 22: _t->slot_init(); break;
        case 23: _t->slot_closeSocket(); break;
        case 24: _t->slot_socketWrite((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 25: _t->slot_socketReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TcpSocketManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_socketConnected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_socketDisconnected)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_socketConnectFailed)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_socketReadFinished)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_registerSuccess)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_registerFailed)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const sttClientInfo , const QMap<quint32,sttGroupInfo> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_loginSuccess)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_loginFailed)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const sttClientInfo );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_modifyUserInfoSuccess)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_modifyUserInfoFailed)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const quint32 , const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_addGroupSuccess)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_addGroupFailed)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_userOnline)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_userOffline)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const quint32 , const quint32 , const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_receiveChatMsg)) {
                *result = 14;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const QString , const QVector<sttFriendInfo> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_receiveSearchUserRecords)) {
                *result = 15;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const quint32 , const sttClientInfo , const QString , const quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_receiveAddFriendRequest)) {
                *result = 16;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const quint32 , const quint32 , const quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_receiveRejectAddFriendRequest)) {
                *result = 17;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const quint32 , const quint32 , const sttFriendInfo );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_receiveAgreeAddFriendRequest)) {
                *result = 18;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const quint32 , const sttFriendInfo );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_receiveUpdateFriendInfo)) {
                *result = 19;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const quint32 , const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_receiveUserHeadPic)) {
                *result = 20;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const quint32 , const quint32 , const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_receiveChatPic)) {
                *result = 21;
                return;
            }
        }
    }
}

const QMetaObject TcpSocketManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TcpSocketManager.data,
      qt_meta_data_TcpSocketManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TcpSocketManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpSocketManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpSocketManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TcpSocketManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void TcpSocketManager::signal_socketConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TcpSocketManager::signal_socketDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TcpSocketManager::signal_socketConnectFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TcpSocketManager::signal_socketReadFinished(const QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TcpSocketManager::signal_registerSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void TcpSocketManager::signal_registerFailed(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TcpSocketManager::signal_loginSuccess(const sttClientInfo _t1, const QMap<quint32,sttGroupInfo> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void TcpSocketManager::signal_loginFailed(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void TcpSocketManager::signal_modifyUserInfoSuccess(const sttClientInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void TcpSocketManager::signal_modifyUserInfoFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void TcpSocketManager::signal_addGroupSuccess(const quint32 _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void TcpSocketManager::signal_addGroupFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void TcpSocketManager::signal_userOnline(const quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void TcpSocketManager::signal_userOffline(const quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void TcpSocketManager::signal_receiveChatMsg(const quint32 _t1, const quint32 _t2, const QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void TcpSocketManager::signal_receiveSearchUserRecords(const QString _t1, const QVector<sttFriendInfo> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void TcpSocketManager::signal_receiveAddFriendRequest(const quint32 _t1, const sttClientInfo _t2, const QString _t3, const quint32 _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void TcpSocketManager::signal_receiveRejectAddFriendRequest(const quint32 _t1, const quint32 _t2, const quint32 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void TcpSocketManager::signal_receiveAgreeAddFriendRequest(const quint32 _t1, const quint32 _t2, const sttFriendInfo _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void TcpSocketManager::signal_receiveUpdateFriendInfo(const quint32 _t1, const sttFriendInfo _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void TcpSocketManager::signal_receiveUserHeadPic(const quint32 _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void TcpSocketManager::signal_receiveChatPic(const quint32 _t1, const quint32 _t2, const QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
