#-------------------------------------------------
#
# Project created by QtCreator 2024-02-10T13:30:52
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChatServer
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
               $$PWD/include

SOURCES += \
        source/main.cpp \
        source/mainwindow.cpp \
        source/tcpservermanager.cpp \
        source/tcpsocketmanager.cpp \
        source/databasemanager.cpp \
        source/log.cpp \
        source/global.cpp \
        source/Helper.cpp


HEADERS += \
        include/mainwindow.h \
        include/tcpservermanager.h \
        include/global.h \
        include/tcpsocketmanager.h \
        include/databasemanager.h \
        include/log.h \
        include/Helper.h


FORMS += \
        form/mainwindow.ui

RESOURCES += \
    icons.qrc
