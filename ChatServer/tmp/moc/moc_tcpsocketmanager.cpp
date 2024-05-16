/****************************************************************************
** Meta object code from reading C++ file 'tcpsocketmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/tcpsocketmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpsocketmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpSocketManager_t {
    QByteArrayData data[37];
    char stringdata0[643];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpSocketManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpSocketManager_t qt_meta_stringdata_TcpSocketManager = {
    {
QT_MOC_LITERAL(0, 0, 16), // "TcpSocketManager"
QT_MOC_LITERAL(1, 17, 28), // "signal_databaseConnectFailed"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 22), // "signal_socketConnected"
QT_MOC_LITERAL(4, 70, 12), // "QHostAddress"
QT_MOC_LITERAL(5, 83, 7), // "address"
QT_MOC_LITERAL(6, 91, 4), // "port"
QT_MOC_LITERAL(7, 96, 25), // "signal_socketDisconnected"
QT_MOC_LITERAL(8, 122, 7), // "user_id"
QT_MOC_LITERAL(9, 130, 16), // "QVector<quint32>"
QT_MOC_LITERAL(10, 147, 16), // "user_friend_list"
QT_MOC_LITERAL(11, 164, 19), // "signal_readFinished"
QT_MOC_LITERAL(12, 184, 7), // "message"
QT_MOC_LITERAL(13, 192, 19), // "signal_sendFinished"
QT_MOC_LITERAL(14, 212, 10), // "send_bytes"
QT_MOC_LITERAL(15, 223, 18), // "signal_socketError"
QT_MOC_LITERAL(16, 242, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(17, 271, 12), // "socket_error"
QT_MOC_LITERAL(18, 284, 19), // "signal_loginSuccess"
QT_MOC_LITERAL(19, 304, 23), // "signal_queryOnlineState"
QT_MOC_LITERAL(20, 328, 24), // "signal_requestRelayBytes"
QT_MOC_LITERAL(21, 353, 14), // "relay_to_these"
QT_MOC_LITERAL(22, 368, 5), // "bytes"
QT_MOC_LITERAL(23, 374, 20), // "slot_socketConnected"
QT_MOC_LITERAL(24, 395, 23), // "slot_socketDisconnected"
QT_MOC_LITERAL(25, 419, 23), // "slot_socketStateChanged"
QT_MOC_LITERAL(26, 443, 28), // "QAbstractSocket::SocketState"
QT_MOC_LITERAL(27, 472, 12), // "socket_state"
QT_MOC_LITERAL(28, 485, 20), // "slot_socketReadyRead"
QT_MOC_LITERAL(29, 506, 6), // "m_init"
QT_MOC_LITERAL(30, 513, 22), // "slot_socketSendMessage"
QT_MOC_LITERAL(31, 536, 28), // "slot_receiveReplyOnlineState"
QT_MOC_LITERAL(32, 565, 19), // "client_self_address"
QT_MOC_LITERAL(33, 585, 16), // "client_self_port"
QT_MOC_LITERAL(34, 602, 13), // "query_user_id"
QT_MOC_LITERAL(35, 616, 17), // "ChatType::ChatCMD"
QT_MOC_LITERAL(36, 634, 8) // "cmd_type"

    },
    "TcpSocketManager\0signal_databaseConnectFailed\0"
    "\0signal_socketConnected\0QHostAddress\0"
    "address\0port\0signal_socketDisconnected\0"
    "user_id\0QVector<quint32>\0user_friend_list\0"
    "signal_readFinished\0message\0"
    "signal_sendFinished\0send_bytes\0"
    "signal_socketError\0QAbstractSocket::SocketError\0"
    "socket_error\0signal_loginSuccess\0"
    "signal_queryOnlineState\0"
    "signal_requestRelayBytes\0relay_to_these\0"
    "bytes\0slot_socketConnected\0"
    "slot_socketDisconnected\0slot_socketStateChanged\0"
    "QAbstractSocket::SocketState\0socket_state\0"
    "slot_socketReadyRead\0m_init\0"
    "slot_socketSendMessage\0"
    "slot_receiveReplyOnlineState\0"
    "client_self_address\0client_self_port\0"
    "query_user_id\0ChatType::ChatCMD\0"
    "cmd_type"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpSocketManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    2,   95,    2, 0x06 /* Public */,
       7,    4,  100,    2, 0x06 /* Public */,
      11,    3,  109,    2, 0x06 /* Public */,
      13,    3,  116,    2, 0x06 /* Public */,
      15,    1,  123,    2, 0x06 /* Public */,
      18,    4,  126,    2, 0x06 /* Public */,
      19,    1,  135,    2, 0x06 /* Public */,
      20,    2,  138,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      23,    0,  143,    2, 0x08 /* Private */,
      24,    0,  144,    2, 0x08 /* Private */,
      25,    1,  145,    2, 0x08 /* Private */,
      28,    0,  148,    2, 0x08 /* Private */,
      29,    0,  149,    2, 0x0a /* Public */,
      30,    3,  150,    2, 0x0a /* Public */,
      31,    4,  157,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::UShort,    5,    6,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4, QMetaType::UShort, 0x80000000 | 9,    8,    5,    6,   10,
    QMetaType::Void, 0x80000000 | 4, QMetaType::UShort, QMetaType::QByteArray,    5,    6,   12,
    QMetaType::Void, 0x80000000 | 4, QMetaType::UShort, QMetaType::ULongLong,    5,    6,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4, QMetaType::UShort, 0x80000000 | 9,    8,    5,    6,   10,
    QMetaType::Void, QMetaType::UInt,    8,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QByteArray,   21,   22,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::ULongLong, 0x80000000 | 4, QMetaType::UShort, QMetaType::QByteArray,    5,    6,   12,
    QMetaType::Void, 0x80000000 | 4, QMetaType::UShort, QMetaType::UInt, 0x80000000 | 35,   32,   33,   34,   36,

       0        // eod
};

void TcpSocketManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpSocketManager *_t = static_cast<TcpSocketManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_databaseConnectFailed(); break;
        case 1: _t->signal_socketConnected((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2]))); break;
        case 2: _t->signal_socketDisconnected((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const QHostAddress(*)>(_a[2])),(*reinterpret_cast< const quint16(*)>(_a[3])),(*reinterpret_cast< const QVector<quint32>(*)>(_a[4]))); break;
        case 3: _t->signal_readFinished((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        case 4: _t->signal_sendFinished((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2])),(*reinterpret_cast< const quint64(*)>(_a[3]))); break;
        case 5: _t->signal_socketError((*reinterpret_cast< const QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 6: _t->signal_loginSuccess((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const QHostAddress(*)>(_a[2])),(*reinterpret_cast< const quint16(*)>(_a[3])),(*reinterpret_cast< const QVector<quint32>(*)>(_a[4]))); break;
        case 7: _t->signal_queryOnlineState((*reinterpret_cast< const quint32(*)>(_a[1]))); break;
        case 8: _t->signal_requestRelayBytes((*reinterpret_cast< const QVector<quint32>(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 9: _t->slot_socketConnected(); break;
        case 10: _t->slot_socketDisconnected(); break;
        case 11: _t->slot_socketStateChanged((*reinterpret_cast< const QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 12: _t->slot_socketReadyRead(); break;
        case 13: _t->m_init(); break;
        case 14: { quint64 _r = _t->slot_socketSendMessage((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< quint64*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->slot_receiveReplyOnlineState((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2])),(*reinterpret_cast< const quint32(*)>(_a[3])),(*reinterpret_cast< const ChatType::ChatCMD(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 3:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<quint32> >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 3:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<quint32> >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<quint32> >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TcpSocketManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_databaseConnectFailed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const QHostAddress , const quint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_socketConnected)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const quint32 , const QHostAddress , const quint16 , const QVector<quint32> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_socketDisconnected)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const QHostAddress , const quint16 , const QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_readFinished)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const QHostAddress , const quint16 , const quint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_sendFinished)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const QAbstractSocket::SocketError );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_socketError)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const quint32 , const QHostAddress , const quint16 , const QVector<quint32> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_loginSuccess)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_queryOnlineState)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (TcpSocketManager::*_t)(const QVector<quint32> , const QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketManager::signal_requestRelayBytes)) {
                *result = 8;
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void TcpSocketManager::signal_databaseConnectFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TcpSocketManager::signal_socketConnected(const QHostAddress _t1, const quint16 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TcpSocketManager::signal_socketDisconnected(const quint32 _t1, const QHostAddress _t2, const quint16 _t3, const QVector<quint32> _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TcpSocketManager::signal_readFinished(const QHostAddress _t1, const quint16 _t2, const QByteArray _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TcpSocketManager::signal_sendFinished(const QHostAddress _t1, const quint16 _t2, const quint64 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TcpSocketManager::signal_socketError(const QAbstractSocket::SocketError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TcpSocketManager::signal_loginSuccess(const quint32 _t1, const QHostAddress _t2, const quint16 _t3, const QVector<quint32> _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void TcpSocketManager::signal_queryOnlineState(const quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void TcpSocketManager::signal_requestRelayBytes(const QVector<quint32> _t1, const QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
