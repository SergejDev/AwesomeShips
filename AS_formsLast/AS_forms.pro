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
    tabledialog.qml \
    android/AndroidManifest.xml \
    android/res/drawable/icon.png \
    android/res/drawable/logo.png \
    android/res/drawable-hdpi/icon.png \
    android/res/drawable-ldpi/icon.png \
    android/res/drawable-mdpi/icon.png \
    android/res/layout/splash.xml \
    android/res/values/libs.xml \
    android/res/values/strings.xml \
    android/res/values-de/strings.xml \
    android/res/values-el/strings.xml \
    android/res/values-es/strings.xml \
    android/res/values-et/strings.xml \
    android/res/values-fa/strings.xml \
    android/res/values-fr/strings.xml \
    android/res/values-id/strings.xml \
    android/res/values-it/strings.xml \
    android/res/values-ja/strings.xml \
    android/res/values-ms/strings.xml \
    android/res/values-nb/strings.xml \
    android/res/values-nl/strings.xml \
    android/res/values-pl/strings.xml \
    android/res/values-pt-rBR/strings.xml \
    android/res/values-ro/strings.xml \
    android/res/values-rs/strings.xml \
    android/res/values-ru/strings.xml \
    android/res/values-zh-rCN/strings.xml \
    android/res/values-zh-rTW/strings.xml \
    android/src/org/kde/necessitas/ministro/IMinistro.aidl \
    android/src/org/kde/necessitas/ministro/IMinistroCallback.aidl \
    android/src/org/kde/necessitas/origo/QtActivity.java \
    android/src/org/kde/necessitas/origo/QtApplication.java \
    android/version.xml

