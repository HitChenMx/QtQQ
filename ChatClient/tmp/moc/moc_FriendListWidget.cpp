/****************************************************************************
** Meta object code from reading C++ file 'FriendListWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../littleWidgets/FriendListWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FriendListWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FriendListWidget_t {
    QByteArrayData data[22];
    char stringdata0[337];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FriendListWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FriendListWidget_t qt_meta_stringdata_FriendListWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "FriendListWidget"
QT_MOC_LITERAL(1, 17, 24), // "signal_friendBox_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 9), // "friend_id"
QT_MOC_LITERAL(4, 53, 21), // "signal_addGroup_query"
QT_MOC_LITERAL(5, 75, 7), // "user_id"
QT_MOC_LITERAL(6, 83, 10), // "group_name"
QT_MOC_LITERAL(7, 94, 24), // "signal_renameGroup_query"
QT_MOC_LITERAL(8, 119, 8), // "group_id"
QT_MOC_LITERAL(9, 128, 8), // "new_name"
QT_MOC_LITERAL(10, 137, 23), // "signal_queryOnlineState"
QT_MOC_LITERAL(11, 161, 19), // "signal_queryHeadPic"
QT_MOC_LITERAL(12, 181, 19), // "slot_addGroup_query"
QT_MOC_LITERAL(13, 201, 21), // "slot_addGroup_success"
QT_MOC_LITERAL(14, 223, 12), // "new_group_id"
QT_MOC_LITERAL(15, 236, 20), // "slot_addGroup_failed"
QT_MOC_LITERAL(16, 257, 16), // "slot_renameGroup"
QT_MOC_LITERAL(17, 274, 16), // "slot_deleteGroup"
QT_MOC_LITERAL(18, 291, 16), // "slot_itemClicked"
QT_MOC_LITERAL(19, 308, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(20, 325, 4), // "item"
QT_MOC_LITERAL(21, 330, 6) // "column"

    },
    "FriendListWidget\0signal_friendBox_clicked\0"
    "\0friend_id\0signal_addGroup_query\0"
    "user_id\0group_name\0signal_renameGroup_query\0"
    "group_id\0new_name\0signal_queryOnlineState\0"
    "signal_queryHeadPic\0slot_addGroup_query\0"
    "slot_addGroup_success\0new_group_id\0"
    "slot_addGroup_failed\0slot_renameGroup\0"
    "slot_deleteGroup\0slot_itemClicked\0"
    "QTreeWidgetItem*\0item\0column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FriendListWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    2,   72,    2, 0x06 /* Public */,
       7,    3,   77,    2, 0x06 /* Public */,
      10,    1,   84,    2, 0x06 /* Public */,
      11,    1,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   90,    2, 0x0a /* Public */,
      13,    2,   91,    2, 0x0a /* Public */,
      15,    0,   96,    2, 0x0a /* Public */,
      16,    0,   97,    2, 0x0a /* Public */,
      17,    0,   98,    2, 0x0a /* Public */,
      18,    2,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString,    5,    6,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::QString,    5,    8,    9,
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, QMetaType::UInt,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString,   14,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19, QMetaType::Int,   20,   21,

       0        // eod
};

void FriendListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FriendListWidget *_t = static_cast<FriendListWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_friendBox_clicked((*reinterpret_cast< const quint32(*)>(_a[1]))); break;
        case 1: _t->signal_addGroup_query((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->signal_renameGroup_query((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const quint32(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 3: _t->signal_queryOnlineState((*reinterpret_cast< const quint32(*)>(_a[1]))); break;
        case 4: _t->signal_queryHeadPic((*reinterpret_cast< const quint32(*)>(_a[1]))); break;
        case 5: _t->slot_addGroup_query(); break;
        case 6: _t->slot_addGroup_success((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->slot_addGroup_failed(); break;
        case 8: _t->slot_renameGroup(); break;
        case 9: _t->slot_deleteGroup(); break;
        case 10: _t->slot_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FriendListWidget::*_t)(const quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FriendListWidget::signal_friendBox_clicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FriendListWidget::*_t)(const quint32 , const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FriendListWidget::signal_addGroup_query)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (FriendListWidget::*_t)(const quint32 , const quint32 , const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FriendListWidget::signal_renameGroup_query)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (FriendListWidget::*_t)(const quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FriendListWidget::signal_queryOnlineState)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (FriendListWidget::*_t)(const quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FriendListWidget::signal_queryHeadPic)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject FriendListWidget::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_FriendListWidget.data,
      qt_meta_data_FriendListWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FriendListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FriendListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FriendListWidget.stringdata0))
        return static_cast<void*>(this);
    return QTreeWidget::qt_metacast(_clname);
}

int FriendListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void FriendListWidget::signal_friendBox_clicked(const quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FriendListWidget::signal_addGroup_query(const quint32 _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FriendListWidget::signal_renameGroup_query(const quint32 _t1, const quint32 _t2, const QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FriendListWidget::signal_queryOnlineState(const quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FriendListWidget::signal_queryHeadPic(const quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
struct qt_meta_stringdata_ExpandButton_t {
    QByteArrayData data[1];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ExpandButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ExpandButton_t qt_meta_stringdata_ExpandButton = {
    {
QT_MOC_LITERAL(0, 0, 12) // "ExpandButton"

    },
    "ExpandButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExpandButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ExpandButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject ExpandButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_ExpandButton.data,
      qt_meta_data_ExpandButton,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ExpandButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExpandButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ExpandButton.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int ExpandButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
