/****************************************************************************
** Meta object code from reading C++ file 'SearchFriendWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../littleWidgets/SearchFriendWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SearchFriendWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SearchFriendWidget_t {
    QByteArrayData data[10];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SearchFriendWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SearchFriendWidget_t qt_meta_stringdata_SearchFriendWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "SearchFriendWidget"
QT_MOC_LITERAL(1, 19, 24), // "signal_searchTextChanged"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 7), // "user_id"
QT_MOC_LITERAL(4, 53, 11), // "search_text"
QT_MOC_LITERAL(5, 65, 22), // "signal_sendMsgToFriend"
QT_MOC_LITERAL(6, 88, 9), // "friend_id"
QT_MOC_LITERAL(7, 98, 24), // "slot_updateSearchRecords"
QT_MOC_LITERAL(8, 123, 22), // "QVector<sttFriendInfo>"
QT_MOC_LITERAL(9, 146, 14) // "update_records"

    },
    "SearchFriendWidget\0signal_searchTextChanged\0"
    "\0user_id\0search_text\0signal_sendMsgToFriend\0"
    "friend_id\0slot_updateSearchRecords\0"
    "QVector<sttFriendInfo>\0update_records"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SearchFriendWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       5,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::UInt,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 8,    4,    9,

       0        // eod
};

void SearchFriendWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SearchFriendWidget *_t = static_cast<SearchFriendWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_searchTextChanged((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->signal_sendMsgToFriend((*reinterpret_cast< const quint32(*)>(_a[1]))); break;
        case 2: _t->slot_updateSearchRecords((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QVector<sttFriendInfo>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SearchFriendWidget::*_t)(const quint32 , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SearchFriendWidget::signal_searchTextChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SearchFriendWidget::*_t)(const quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SearchFriendWidget::signal_sendMsgToFriend)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject SearchFriendWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SearchFriendWidget.data,
      qt_meta_data_SearchFriendWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SearchFriendWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SearchFriendWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SearchFriendWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SearchFriendWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void SearchFriendWidget::signal_searchTextChanged(const quint32 _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SearchFriendWidget::signal_sendMsgToFriend(const quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
