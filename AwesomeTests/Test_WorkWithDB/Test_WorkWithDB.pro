#-------------------------------------------------
#
# Project created by QtCreator 2013-04-25T21:06:18
#
#-------------------------------------------------

QT       += sql testlib

QT       -= gui

TARGET = tst_workwithdbtest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_workwithdbtest.cpp \
            workwithdb.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS +=\
 menuwindow.h \
workwithdb.h

