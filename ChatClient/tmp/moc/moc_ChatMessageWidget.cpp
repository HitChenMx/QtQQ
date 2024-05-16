/****************************************************************************
** Meta object code from reading C++ file 'ChatMessageWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../main/ChatMessageWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChatMessageWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChatMessageWidget_t {
    QByteArrayData data[13];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChatMessageWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChatMessageWidget_t qt_meta_stringdata_ChatMessageWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ChatMessageWidget"
QT_MOC_LITERAL(1, 18, 17), // "signal_newMessage"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 4), // "time"
QT_MOC_LITERAL(4, 42, 3), // "msg"
QT_MOC_LITERAL(5, 46, 24), // "signal_reqAsmSendChatMsg"
QT_MOC_LITERAL(6, 71, 7), // "send_id"
QT_MOC_LITERAL(7, 79, 6), // "rcv_id"
QT_MOC_LITERAL(8, 86, 8), // "chat_msg"
QT_MOC_LITERAL(9, 95, 24), // "signal_reqAsmSendChatPic"
QT_MOC_LITERAL(10, 120, 13), // "chat_pic_path"
QT_MOC_LITERAL(11, 134, 31), // "slot_btnChatMessageSend_clicked"
QT_MOC_LITERAL(12, 166, 27) // "slot_btnChatPicture_clicked"

    },
    "ChatMessageWidget\0signal_newMessage\0"
    "\0time\0msg\0signal_reqAsmSendChatMsg\0"
    "send_id\0rcv_id\0chat_msg\0"
    "signal_reqAsmSendChatPic\0chat_pic_path\0"
    "slot_btnChatMessageSend_clicked\0"
    "slot_btnChatPicture_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatMessageWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       5,    3,   44,    2, 0x06 /* Public */,
       9,    3,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   58,    2, 0x08 /* Private */,
      12,    0,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::QString,    6,    7,    8,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::QString,    6,    7,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ChatMessageWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChatMessageWidget *_t = static_cast<ChatMessageWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_newMessage((*reinterpret_cast< const QDateTime(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->signal_reqAsmSendChatMsg((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const quint32(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 2: _t->signal_reqAsmSendChatPic((*reinterpret_cast< const quint32(*)>(_a[1])),(*reinterpret_cast< const quint32(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 3: _t->slot_btnChatMessageSend_clicked(); break;
        case 4: _t->slot_btnChatPicture_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ChatMessageWidget::*_t)(const QDateTime , const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChatMessageWidget::signal_newMessage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ChatMessageWidget::*_t)(const quint32 , const quint32 , const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChatMessageWidget::signal_reqAsmSendChatMsg)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ChatMessageWidget::*_t)(const quint32 , const quint32 , const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChatMessageWidget::signal_reqAsmSendChatPic)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject ChatMessageWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ChatMessageWidget.data,
      qt_meta_data_ChatMessageWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ChatMessageWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatMessageWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChatMessageWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ChatMessageWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ChatMessageWidget::signal_newMessage(const QDateTime _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChatMessageWidget::signal_reqAsmSendChatMsg(const quint32 _t1, const quint32 _t2, const QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ChatMessageWidget::signal_reqAsmSendChatPic(const quint32 _t1, const quint32 _t2, const QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
