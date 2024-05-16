/****************************************************************************
** Meta object code from reading C++ file 'tcpservermanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/tcpservermanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpservermanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpServerManager_t {
    QByteArrayData data[36];
    char stringdata0[657];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpServerManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpServerManager_t qt_meta_stringdata_TcpServerManager = {
    {
QT_MOC_LITERAL(0, 0, 16), // "TcpServerManager"
QT_MOC_LITERAL(1, 17, 28), // "signal_databaseConnectFailed"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 7), // "qintptr"
QT_MOC_LITERAL(4, 55, 16), // "socketDescriptor"
QT_MOC_LITERAL(5, 72, 22), // "signal_clientConnected"
QT_MOC_LITERAL(6, 95, 12), // "QHostAddress"
QT_MOC_LITERAL(7, 108, 7), // "address"
QT_MOC_LITERAL(8, 116, 4), // "port"
QT_MOC_LITERAL(9, 121, 25), // "signal_clientDisconnected"
QT_MOC_LITERAL(10, 147, 27), // "signal_receiveClientMessage"
QT_MOC_LITERAL(11, 175, 7), // "message"
QT_MOC_LITERAL(12, 183, 24), // "signal_sendClientMessage"
QT_MOC_LITERAL(13, 208, 32), // "signal_sendClientMessageFinished"
QT_MOC_LITERAL(14, 241, 10), // "send_bytes"
QT_MOC_LITERAL(15, 252, 24), // "signal_clientSocketError"
QT_MOC_LITERAL(16, 277, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(17, 306, 12), // "socket_error"
QT_MOC_LITERAL(18, 319, 28), // "signal_replyQueryOnlineState"
QT_MOC_LITERAL(19, 348, 19), // "client_self_address"
QT_MOC_LITERAL(20, 368, 16), // "client_self_port"
QT_MOC_LITERAL(21, 385, 13), // "query_user_id"
QT_MOC_LITERAL(22, 399, 17), // "ChatType::ChatCMD"
QT_MOC_LITERAL(23, 417, 8), // "cmd_type"
QT_MOC_LITERAL(24, 426, 20), // "slot_clientConnected"
QT_MOC_LITERAL(25, 447, 23), // "slot_clientDisconnected"
QT_MOC_LITERAL(26, 471, 7), // "user_id"
QT_MOC_LITERAL(27, 479, 16), // "QVector<quint32>"
QT_MOC_LITERAL(28, 496, 16), // "user_friend_list"
QT_MOC_LITERAL(29, 513, 25), // "slot_receiveClientMessage"
QT_MOC_LITERAL(30, 539, 23), // "slot_clientLoginSuccess"
QT_MOC_LITERAL(31, 563, 27), // "slot_clientQueryOnlineState"
QT_MOC_LITERAL(32, 591, 24), // "slot_relayBytesToClients"
QT_MOC_LITERAL(33, 616, 14), // "relay_to_these"
QT_MOC_LITERAL(34, 631, 5), // "bytes"
QT_MOC_LITERAL(35, 637, 19) // "slot_threadFinished"

    },
    "TcpServerManager\0signal_databaseConnectFailed\0"
    "\0qintptr\0socketDescriptor\0"
    "signal_clientConnected\0QHostAddress\0"
    "address\0port\0signal_clientDisconnected\0"
    "signal_receiveClientMessage\0message\0"
    "signal_sendClientMessage\0"
    "signal_sendClientMessageFinished\0"
    "send_bytes\0signal_clientSocketError\0"
    "QAbstractSocket::SocketError\0socket_error\0"
    "signal_replyQueryOnlineState\0"
    "client_self_address\0client_self_port\0"
    "query_user_id\0ChatType::ChatCMD\0"
    "cmd_type\0slot_clientConnected\0"
    "slot_clientDisconnected\0user_id\0"
    "QVector<quint32>\0user_friend_list\0"
    "slot_receiveClientMessage\0"
    "slot_clientLoginSuccess\0"
    "slot_clientQueryOnlineState\0"
    "slot_relayBytesToClients\0relay_to_these\0"
    "bytes\0slot_threadFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpServerManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       5,    2,   92,    2, 0x06 /* Public */,
       9,    2,   97,    2, 0x06 /* Public */,
      10,    3,  102,    2, 0x06 /* Public */,
      12,    3,  109,    2, 0x06 /* Public */,
      13,    3,  116,    2, 0x06 /* Public */,
      15,    1,  123,    2, 0x06 /* Public */,
      18,    4,  126,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      24,    2,  135,    2, 0x08 /* Private */,
      25,    4,  140,    2, 0x08 /* Private */,
      29,    3,  149,    2, 0x08 /* Private */,
      30,    4,  156,    2, 0x08 /* Private */,
      31,    1,  165,    2, 0x08 /* Private */,
      32,    2,  168,    2, 0x08 /* Private */,
      35,    0,  173,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, QMetaType::UShort,    7,    8,
    QMetaType::Void, 0x80000000 | 6, QMetaType::UShort,    7,    8,
    QMetaType::Void, 0x80000000 | 6, QMetaType::UShort, QMetaType::QByteArray,    7,    8,   11,
    QMetaType::Void, 0x80000000 | 6, QMetaType::UShort, QMetaType::QByteArray,    7,    8,   11,
    QMetaType::Void, 0x80000000 | 6, QMetaType::UShort, QMetaType::ULongLong,    7,    8,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 6, QMetaType::UShort, QMetaType::UInt, 0x80000000 | 22,   19,   20,   21,   23,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, QMetaType::UShort,    7,    8,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 6, QMetaType::UShort, 0x80000000 | 27,   26,    7,    8,   28,
    QMetaType::Void, 0x80000000 | 6, QMetaType::UShort, QMetaType::QByteArray,    7,    8,   11,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 6, QMetaType::UShort, 0x80000000 | 27,   26,    7,    8,   28,
    QMetaType::Void, QMetaType::UInt,   26,
    QMetaType::Void, 0x80000000 | 27, QMetaType::QByteArray,   33,   34,
    QMetaType::Void,

       0        // eod
};

void TcpServerManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpServerManager *_t = static_cast<TcpServerManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_databaseConnectFailed((*reinterpret_cast< qintptr(*)>(_a[1]))); break;
        case 1: _t->signal_clientConnected((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2]))); break;
        case 2: _t->signal_clientDisconnected((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2]))); break;
        case 3: _t->signal_receiveClientMessage((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        case 4: _t->signal_sendClientMessage((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        case 5: _t->signal_sendClientMessageFinished((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2])),(*reinterpret_cast< const quint64(*)>(_a[3]))); break;
        case 6: _t->signal_clientSocketError((*reinterpret_cast< const QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 7: _t->signal_replyQueryOnlineState((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2])),(*reinterpret_cast< const quint32(*)>(_a[3])),(*reinterpret_cast< const ChatType::ChatCMD(*)>(_a[4]))); break;
        case 8: _t->slot_clientConnected((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2]))); break;
        case 9: _t->slot_clientDisconnected((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const QHostAddress(*)>(_a[2])),(*reinterpret_cast< const quint16(*)>(_a[3])),(*reinterpret_cast< const QVector<quint32>(*)>(_a[4]))); break;
        case 10: _t->slot_receiveClientMessage((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        case 11: _t->slot_clientLoginSuccess((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const QHostAddress(*)>(_a[2])),(*reinterpret_cast< const quint16(*)>(_a[3])),(*reinterpret_cast< const QVector<quint32>(*)>(_a[4]))); break;
        case 12: _t->slot_clientQueryOnlineState((*reinterpret_cast< const quint32(*)>(_a[1]))); break;
        case 13: _t->slot_relayBytesToClients((*reinterpret_cast< const QVector<quint32>(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 14: _t->slot_threadFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 3:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<quint32> >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 3:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<quint32> >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<quint32> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TcpServerManager::*_t)(qintptr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpServerManager::signal_databaseConnectFailed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TcpServerManager::*_t)(const QHostAddress , const quint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpServerManager::signal_clientConnected)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TcpServerManager::*_t)(const QHostAddress , const quint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpServerManager::signal_clientDisconnected)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (TcpServerManager::*_t)(const QHostAddress , const quint16 , const QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpServerManager::signal_receiveClientMessage)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (TcpServerManager::*_t)(const QHostAddress , const quint16 , const QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpServerManager::signal_sendClientMessage)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (TcpServerManager::*_t)(const QHostAddress , const quint16 , const quint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpServerManager::signal_sendClientMessageFinished)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (TcpServerManager::*_t)(const QAbstractSocket::SocketError );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpServerManager::signal_clientSocketError)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (TcpServerManager::*_t)(const QHostAddress , const quint16 , const quint32 , const ChatType::ChatCMD );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpServerManager::signal_replyQueryOnlineState)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject TcpServerManager::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_TcpServerManager.data,
      qt_meta_data_TcpServerManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TcpServerManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpServerManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpServerManager.stringdata0))
        return static_cast<void*>(this);
    return QTcpServer::qt_metacast(_clname);
}

int TcpServerManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void TcpServerManager::signal_databaseConnectFailed(qintptr _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpServerManager::signal_clientConnected(const QHostAddress _t1, const quint16 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TcpServerManager::signal_clientDisconnected(const QHostAddress _t1, const quint16 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TcpServerManager::signal_receiveClientMessage(const QHostAddress _t1, const quint16 _t2, const QByteArray _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TcpServerManager::signal_sendClientMessage(const QHostAddress _t1, const quint16 _t2, const QByteArray _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TcpServerManager::signal_sendClientMessageFinished(const QHostAddress _t1, const quint16 _t2, const quint64 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TcpServerManager::signal_clientSocketError(const QAbstractSocket::SocketError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void TcpServerManager::signal_replyQueryOnlineState(const QHostAddress _t1, const quint16 _t2, const quint32 _t3, const ChatType::ChatCMD _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
