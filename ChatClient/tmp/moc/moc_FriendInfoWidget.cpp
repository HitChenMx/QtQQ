/****************************************************************************
** Meta object code from reading C++ file 'FriendInfoWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../main/FriendInfoWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FriendInfoWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FriendInfoWidget_t {
    QByteArrayData data[10];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FriendInfoWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FriendInfoWidget_t qt_meta_stringdata_FriendInfoWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "FriendInfoWidget"
QT_MOC_LITERAL(1, 17, 28), // "signal_reqOpenChatWithFriend"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 9), // "friend_id"
QT_MOC_LITERAL(4, 57, 27), // "signal_reqMoveFriendToGroup"
QT_MOC_LITERAL(5, 85, 7), // "user_id"
QT_MOC_LITERAL(6, 93, 8), // "group_id"
QT_MOC_LITERAL(7, 102, 21), // "slot_updateGroupNames"
QT_MOC_LITERAL(8, 124, 39), // "slot_cmbFriendGroup_currentIn..."
QT_MOC_LITERAL(9, 164, 5) // "index"

    },
    "FriendInfoWidget\0signal_reqOpenChatWithFriend\0"
    "\0friend_id\0signal_reqMoveFriendToGroup\0"
    "user_id\0group_id\0slot_updateGroupNames\0"
    "slot_cmbFriendGroup_currentIndexChanged\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FriendInfoWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    3,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   44,    2, 0x0a /* Public */,
       8,    1,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    5,    3,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void FriendInfoWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FriendInfoWidget *_t = static_cast<FriendInfoWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_reqOpenChatWithFriend((*reinterpret_cast< const quint32(*)>(_a[1]))); break;
        case 1: _t->signal_reqMoveFriendToGroup((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const quint32(*)>(_a[2])),(*reinterpret_cast< const quint32(*)>(_a[3]))); break;
        case 2: _t->slot_updateGroupNames(); break;
        case 3: _t->slot_cmbFriendGroup_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FriendInfoWidget::*_t)(const quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FriendInfoWidget::signal_reqOpenChatWithFriend)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FriendInfoWidget::*_t)(const quint32 , const quint32 , const quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FriendInfoWidget::signal_reqMoveFriendToGroup)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject FriendInfoWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FriendInfoWidget.data,
      qt_meta_data_FriendInfoWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FriendInfoWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FriendInfoWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FriendInfoWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FriendInfoWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void FriendInfoWidget::signal_reqOpenChatWithFriend(const quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FriendInfoWidget::signal_reqMoveFriendToGroup(const quint32 _t1, const quint32 _t2, const quint32 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
