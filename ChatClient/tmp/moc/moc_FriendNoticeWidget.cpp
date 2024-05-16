/****************************************************************************
** Meta object code from reading C++ file 'FriendNoticeWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../main/FriendNoticeWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FriendNoticeWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FriendNoticeWidget_t {
    QByteArrayData data[14];
    char stringdata0[251];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FriendNoticeWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FriendNoticeWidget_t qt_meta_stringdata_FriendNoticeWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "FriendNoticeWidget"
QT_MOC_LITERAL(1, 19, 22), // "signal_newUnreadNotice"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 16), // "signal_newFriend"
QT_MOC_LITERAL(4, 60, 9), // "friend_id"
QT_MOC_LITERAL(5, 70, 34), // "slot_receiveRejectAddFriendRe..."
QT_MOC_LITERAL(6, 105, 6), // "rcv_id"
QT_MOC_LITERAL(7, 112, 7), // "send_id"
QT_MOC_LITERAL(8, 120, 12), // "rcv_group_id"
QT_MOC_LITERAL(9, 133, 33), // "slot_receiveAgreeAddFriendReq..."
QT_MOC_LITERAL(10, 167, 19), // "rcv_select_group_id"
QT_MOC_LITERAL(11, 187, 13), // "sttFriendInfo"
QT_MOC_LITERAL(12, 201, 15), // "new_friend_info"
QT_MOC_LITERAL(13, 217, 33) // "slot_btnClearFriendNotice_cli..."

    },
    "FriendNoticeWidget\0signal_newUnreadNotice\0"
    "\0signal_newFriend\0friend_id\0"
    "slot_receiveRejectAddFriendRequest\0"
    "rcv_id\0send_id\0rcv_group_id\0"
    "slot_receiveAgreeAddFriendRequest\0"
    "rcv_select_group_id\0sttFriendInfo\0"
    "new_friend_info\0slot_btnClearFriendNotice_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FriendNoticeWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    3,   43,    2, 0x0a /* Public */,
       9,    3,   50,    2, 0x0a /* Public */,
      13,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    6,    7,    8,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, 0x80000000 | 11,    6,   10,   12,
    QMetaType::Void,

       0        // eod
};

void FriendNoticeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FriendNoticeWidget *_t = static_cast<FriendNoticeWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_newUnreadNotice(); break;
        case 1: _t->signal_newFriend((*reinterpret_cast< const quint32(*)>(_a[1]))); break;
        case 2: _t->slot_receiveRejectAddFriendRequest((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const quint32(*)>(_a[2])),(*reinterpret_cast< const quint32(*)>(_a[3]))); break;
        case 3: _t->slot_receiveAgreeAddFriendRequest((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const quint32(*)>(_a[2])),(*reinterpret_cast< const sttFriendInfo(*)>(_a[3]))); break;
        case 4: _t->slot_btnClearFriendNotice_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FriendNoticeWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FriendNoticeWidget::signal_newUnreadNotice)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FriendNoticeWidget::*_t)(const quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FriendNoticeWidget::signal_newFriend)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject FriendNoticeWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FriendNoticeWidget.data,
      qt_meta_data_FriendNoticeWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FriendNoticeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FriendNoticeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FriendNoticeWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FriendNoticeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void FriendNoticeWidget::signal_newUnreadNotice()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FriendNoticeWidget::signal_newFriend(const quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
