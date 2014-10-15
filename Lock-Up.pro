#-------------------------------------------------
#
# Project created by QtCreator 2014-08-07T10:20:27
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lock-Up
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    newaccount.cpp \
    myaccounts.cpp \
    addentry.cpp \
    tinyaes.cpp

HEADERS  += dialog.h \
    newaccount.h \
    myaccounts.h \
    addentry.h \
    tinyaes.h

FORMS    += dialog.ui \
    newaccount.ui \
    myaccounts.ui \
    addentry.ui

RESOURCES += \
    Resources.qrc \
    Resources.qrc

OTHER_FILES += \
    Db/pwmanager.db \
    Db/passwordmanager.sqlite \
