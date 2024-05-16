#-------------------------------------------------
#
# Project created by QtCreator 2024-03-12T12:55:48
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChatClient
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#独立临时目录
UI_DIR      = $$PWD/tmp/uih
MOC_DIR     = $$PWD/tmp/moc
OBJECTS_DIR = $$PWD/tmp/obj

INCLUDEPATH += $$PWD/tmp/uih \
               $$PWD/utils \
               $$PWD/main \
               $$PWD/login \
               $$PWD/littleWidgets

SOURCES += \
        main/main.cpp \
        main/mainwindow.cpp \
        utils/Config.cpp \
        login/Login.cpp \
        utils/TcpSocketManager.cpp \
        utils/LocalDatabase.cpp \
        littleWidgets/InfoButton.cpp \
        littleWidgets/FriendListWidget.cpp \
        littleWidgets/InfoLittleBox.cpp \
        littleWidgets/FriendLittleBox.cpp \
        littleWidgets/InfoListWidget.cpp \
        littleWidgets/PersonDataSet.cpp \
        littleWidgets/PersonDataShow.cpp \
        main/LeftBar.cpp \
        utils/AssembleBytes.cpp \
        main/ChatMessageWidget.cpp \
        main/FriendInfoWidget.cpp \
        littleWidgets/AddFriendRequestWidget.cpp \
        littleWidgets/SearchFriendWidget.cpp \
        littleWidgets/SearchUserLittleBox.cpp \
        main/FriendNoticeWidget.cpp \
        littleWidgets/FriendNoticeBox.cpp \
        littleWidgets/TwoClickAreaButton.cpp \
        littleWidgets/ChatBubbleBox.cpp \
        littleWidgets/ChatBubbleList.cpp \
        utils/Helper.cpp

HEADERS += \
        main/mainwindow.h \
        utils/Config.h \
        login/Login.h \
        utils/TcpSocketManager.h \
        utils/global.h \
        utils/LocalDatabase.h \
        littleWidgets/InfoButton.h \
        littleWidgets/FriendListWidget.h \
        littleWidgets/InfoLittleBox.h \
        littleWidgets/FriendLittleBox.h \
        littleWidgets/InfoListWidget.h \
        littleWidgets/PersonDataSet.h \
        littleWidgets/PersonDataShow.h \
        main/LeftBar.h \
        utils/AssembleBytes.h \
        main/ChatMessageWidget.h \
        main/FriendInfoWidget.h \
        littleWidgets/AddFriendRequestWidget.h \
        littleWidgets/SearchFriendWidget.h \
        littleWidgets/SearchUserLittleBox.h \
        main/FriendNoticeWidget.h \
        littleWidgets/FriendNoticeBox.h \
        littleWidgets/TwoClickAreaButton.h \
        littleWidgets/ChatBubbleBox.h \
        littleWidgets/ChatBubbleList.h \
        utils/Helper.h


FORMS += \
        main/mainwindow.ui \
        login/Login.ui \
        littleWidgets/InfoLittlebox.ui \
        littleWidgets/FriendLittleBox.ui \
        littleWidgets/PersonDataSet.ui \
        littleWidgets/PersonDataShow.ui \
        main/ChatMessageWidget.ui \
        main/FriendInfoWidget.ui \
        littleWidgets/AddFriendRequestWidget.ui \
        littleWidgets/SearchFriendWidget.ui \
        littleWidgets/SearchUserLittleBox.ui \
        main/FriendNoticeWidget.ui \
        littleWidgets/FriendNoticeBox.ui

RESOURCES += \
    qqicons.qrc
