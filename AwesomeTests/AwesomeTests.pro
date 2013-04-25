#-------------------------------------------------
#
# Project created by QtCreator 2013-04-24T19:37:34
#
#-------------------------------------------------

QT       += sql testlib

TARGET += tst_bullettest \
          tst_workwithdbtest
CONFIG   -= app_bundle
CONFIG   += console


TEMPLATE = app


SOURCES += tst_bullettest.cpp \
    tst_workwithdbtest.cpp \
    workwithdb.cpp
#DEFINES += SRCDIR=\\\"$$PWD\\\"

HEADERS += workwithdb.h
