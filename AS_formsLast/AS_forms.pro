#-------------------------------------------------
#
# Project created by QtCreator 2012-10-18T19:14:11
#
#-------------------------------------------------

QT       += core gui declarative\
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
    user.cpp \
    baza.cpp \
    gamemenu.cpp \
    shipExt.cpp

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
    user.h \
    baza.h \
    gamemenu.h \
    shipExt.h

FORMS    += \
    usernamedialog.ui \
    tabledialog.ui \
    baza.ui \
    gamemenu.ui

RESOURCES += \
    resourses.qrc

OTHER_FILES += \
    qml_WINDOW.qml \
    main.qml \
    gameWindow.qml \
    AButton.qml \
    ALabel.qml \
    NewAComboBox.qml \
    usernamedialog.qml \
    tabledialog.qml
