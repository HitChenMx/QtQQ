/****************************************************************************
** Meta object code from reading C++ file 'LeftBar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../main/LeftBar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LeftBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LeftBar_t {
    QByteArrayData data[11];
    char stringdata0[204];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LeftBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LeftBar_t qt_meta_stringdata_LeftBar = {
    {
QT_MOC_LITERAL(0, 0, 7), // "LeftBar"
QT_MOC_LITERAL(1, 8, 25), // "signal_openInfomationPage"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 22), // "signal_openFriendsPage"
QT_MOC_LITERAL(4, 58, 23), // "signal_queryUserHeadPic"
QT_MOC_LITERAL(5, 82, 7), // "user_id"
QT_MOC_LITERAL(6, 90, 27), // "slot_btnInformation_clicked"
QT_MOC_LITERAL(7, 118, 23), // "slot_btnFriends_clicked"
QT_MOC_LITERAL(8, 142, 23), // "slot_lblHeadPic_clicked"
QT_MOC_LITERAL(9, 166, 19), // "slot_buildTabwidget"
QT_MOC_LITERAL(10, 186, 17) // "slot_editUserInfo"

    },
    "LeftBar\0signal_openInfomationPage\0\0"
    "signal_openFriendsPage\0signal_queryUserHeadPic\0"
    "user_id\0slot_btnInformation_clicked\0"
    "slot_btnFriends_clicked\0slot_lblHeadPic_clicked\0"
    "slot_buildTabwidget\0slot_editUserInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LeftBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    1,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LeftBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LeftBar *_t = static_cast<LeftBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_openInfomationPage(); break;
        case 1: _t->signal_openFriendsPage(); break;
        case 2: _t->signal_queryUserHeadPic((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 3: _t->slot_btnInformation_clicked(); break;
        case 4: _t->slot_btnFriends_clicked(); break;
        case 5: _t->slot_lblHeadPic_clicked(); break;
        case 6: _t->slot_buildTabwidget(); break;
        case 7: _t->slot_editUserInfo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LeftBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LeftBar::signal_openInfomationPage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LeftBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LeftBar::signal_openFriendsPage)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (LeftBar::*_t)(quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LeftBar::signal_queryUserHeadPic)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject LeftBar::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_LeftBar.data,
      qt_meta_data_LeftBar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LeftBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LeftBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LeftBar.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int LeftBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void LeftBar::signal_openInfomationPage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LeftBar::signal_openFriendsPage()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void LeftBar::signal_queryUserHeadPic(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
