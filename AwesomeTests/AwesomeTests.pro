#-------------------------------------------------
#
# Project created by QtCreator 2013-04-24T19:37:34
#
#-------------------------------------------------

QT       += sql testlib

TARGET += tst_bullettest

CONFIG   -= app_bundle
CONFIG   += console


TEMPLATE = app


SOURCES += \
    tst_workwithdbtest.cpp \
    workwithdb.cpp \
    tst_bullettest.cpp \
    main.cpp
DEFINES += SRCDIR=\\\"$$PWD\\\"

HEADERS += workwithdb.h \
    tst_workwithdbtest.h
