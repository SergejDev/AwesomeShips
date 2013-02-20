#-------------------------------------------------
#
# Project created by QtCreator 2012-10-18T19:14:11
#
#-------------------------------------------------

QT       += core gui\
 sql
QT += network

TARGET = AS_forms
TEMPLATE = app


SOURCES += main.cpp\
        gamewindow.cpp \
    usernamedialog.cpp \
    tabledialog.cpp \
    ship.cpp \
    ships.cpp \
    bullet.cpp \
    bullets.cpp \
    gamecontroller.cpp \
    gun.cpp \
    windowscontroller.cpp \
    menuwindow.cpp \
    workwithdb.cpp \
    WINDOW.cpp \
    user.cpp

HEADERS  += gamewindow.h \
    usernamedialog.h \
    tabledialog.h \
    ship.h \
    ships.h \
    bullet.h \
    bullets.h \
    gamecontroller.h \
    gun.h \
    windowscontroller.h \
    menuwindow.h \
    workwithdb.h \
    WINDOW.h \
    user.h

FORMS    += \
    usernamedialog.ui \
    tabledialog.ui \
    menuwindow.ui

RESOURCES += \
    resourses.qrc
