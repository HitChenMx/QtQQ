/****************************************************************************
** Meta object code from reading C++ file 'SearchUserLittleBox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../littleWidgets/SearchUserLittleBox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SearchUserLittleBox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SearchUserLittleBox_t {
    QByteArrayData data[6];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SearchUserLittleBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SearchUserLittleBox_t qt_meta_stringdata_SearchUserLittleBox = {
    {
QT_MOC_LITERAL(0, 0, 19), // "SearchUserLittleBox"
QT_MOC_LITERAL(1, 20, 22), // "signal_sendMsgToFriend"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 9), // "friend_id"
QT_MOC_LITERAL(4, 54, 25), // "slot_btnAddFriend_clicked"
QT_MOC_LITERAL(5, 80, 27) // "slot_btnSendMessage_clicked"

    },
    "SearchUserLittleBox\0signal_sendMsgToFriend\0"
    "\0friend_id\0slot_btnAddFriend_clicked\0"
    "slot_btnSendMessage_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SearchUserLittleBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   32,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SearchUserLittleBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SearchUserLittleBox *_t = static_cast<SearchUserLittleBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_sendMsgToFriend((*reinterpret_cast< const quint32(*)>(_a[1]))); break;
        case 1: _t->slot_btnAddFriend_clicked(); break;
        case 2: _t->slot_btnSendMessage_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SearchUserLittleBox::*_t)(const quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SearchUserLittleBox::signal_sendMsgToFriend)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SearchUserLittleBox::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SearchUserLittleBox.data,
      qt_meta_data_SearchUserLittleBox,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SearchUserLittleBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SearchUserLittleBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SearchUserLittleBox.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SearchUserLittleBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SearchUserLittleBox::signal_sendMsgToFriend(const quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
