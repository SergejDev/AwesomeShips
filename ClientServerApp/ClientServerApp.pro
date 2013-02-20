QT += network sql

TARGET = ClientServerApp
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Server.cpp \
    user.cpp

HEADERS += \
    Server.h \
    user.h
