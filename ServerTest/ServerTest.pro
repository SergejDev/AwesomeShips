#-------------------------------------------------
#
# Project created by QtCreator 2013-05-05T21:50:50
#
#-------------------------------------------------

QT       += network sql testlib

QT       -= gui

TARGET = tst_servertest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += E:\\AwesomeShips\\ClientServerApp
HEADERS += E:\\AwesomeShips\\ClientServerApp\\Server.h
SOURCES += E:\\AwesomeShips\\ClientServerApp\\Server.cpp

SOURCES += tst_servertest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
