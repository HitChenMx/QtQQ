/****************************************************************************
** Meta object code from reading C++ file 'Login.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../login/Login.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Login.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Login_t {
    QByteArrayData data[23];
    char stringdata0[416];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Login_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Login_t qt_meta_stringdata_Login = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Login"
QT_MOC_LITERAL(1, 6, 18), // "signal_sendMessage"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "message"
QT_MOC_LITERAL(4, 34, 21), // "slot_connectionFailed"
QT_MOC_LITERAL(5, 56, 21), // "slot_edtRemoveIllegal"
QT_MOC_LITERAL(6, 78, 4), // "text"
QT_MOC_LITERAL(7, 83, 28), // "slot_btnRegisterPage_clicked"
QT_MOC_LITERAL(8, 112, 22), // "slot_btnReturn_clicked"
QT_MOC_LITERAL(9, 135, 24), // "slot_btnRegister_clicked"
QT_MOC_LITERAL(10, 160, 25), // "slot_btnLogin_checkEnable"
QT_MOC_LITERAL(11, 186, 28), // "slot_btnRegister_checkEnable"
QT_MOC_LITERAL(12, 215, 21), // "slot_btnLogin_clicked"
QT_MOC_LITERAL(13, 237, 27), // "slot_btnCancelLogin_clicked"
QT_MOC_LITERAL(14, 265, 20), // "slot_registerSuccess"
QT_MOC_LITERAL(15, 286, 19), // "slot_registerFailed"
QT_MOC_LITERAL(16, 306, 6), // "reason"
QT_MOC_LITERAL(17, 313, 17), // "slot_loginSuccess"
QT_MOC_LITERAL(18, 331, 13), // "sttClientInfo"
QT_MOC_LITERAL(19, 345, 11), // "client_info"
QT_MOC_LITERAL(20, 357, 26), // "QMap<quint32,sttGroupInfo>"
QT_MOC_LITERAL(21, 384, 14), // "all_group_info"
QT_MOC_LITERAL(22, 399, 16) // "slot_loginFailed"

    },
    "Login\0signal_sendMessage\0\0message\0"
    "slot_connectionFailed\0slot_edtRemoveIllegal\0"
    "text\0slot_btnRegisterPage_clicked\0"
    "slot_btnReturn_clicked\0slot_btnRegister_clicked\0"
    "slot_btnLogin_checkEnable\0"
    "slot_btnRegister_checkEnable\0"
    "slot_btnLogin_clicked\0slot_btnCancelLogin_clicked\0"
    "slot_registerSuccess\0slot_registerFailed\0"
    "reason\0slot_loginSuccess\0sttClientInfo\0"
    "client_info\0QMap<quint32,sttGroupInfo>\0"
    "all_group_info\0slot_loginFailed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Login[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   87,    2, 0x08 /* Private */,
       5,    1,   88,    2, 0x08 /* Private */,
       7,    0,   91,    2, 0x08 /* Private */,
       8,    0,   92,    2, 0x08 /* Private */,
       9,    0,   93,    2, 0x08 /* Private */,
      10,    0,   94,    2, 0x08 /* Private */,
      11,    0,   95,    2, 0x08 /* Private */,
      12,    0,   96,    2, 0x08 /* Private */,
      13,    0,   97,    2, 0x08 /* Private */,
      14,    0,   98,    2, 0x08 /* Private */,
      15,    1,   99,    2, 0x08 /* Private */,
      17,    2,  102,    2, 0x08 /* Private */,
      22,    1,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, 0x80000000 | 18, 0x80000000 | 20,   19,   21,
    QMetaType::Void, QMetaType::QString,   16,

       0        // eod
};

void Login::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Login *_t = static_cast<Login *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_sendMessage((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->slot_connectionFailed(); break;
        case 2: _t->slot_edtRemoveIllegal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->slot_btnRegisterPage_clicked(); break;
        case 4: _t->slot_btnReturn_clicked(); break;
        case 5: _t->slot_btnRegister_clicked(); break;
        case 6: _t->slot_btnLogin_checkEnable(); break;
        case 7: _t->slot_btnRegister_checkEnable(); break;
        case 8: _t->slot_btnLogin_clicked(); break;
        case 9: _t->slot_btnCancelLogin_clicked(); break;
        case 10: _t->slot_registerSuccess(); break;
        case 11: _t->slot_registerFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->slot_loginSuccess((*reinterpret_cast< const sttClientInfo(*)>(_a[1])),(*reinterpret_cast< const QMap<quint32,sttGroupInfo>(*)>(_a[2]))); break;
        case 13: _t->slot_loginFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Login::*_t)(const QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Login::signal_sendMessage)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Login::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Login.data,
      qt_meta_data_Login,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Login::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Login::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Login.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Login::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Login::signal_sendMessage(const QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
