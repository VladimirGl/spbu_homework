#-------------------------------------------------
#
# Project created by QtCreator 2013-03-18T19:27:04
#
#-------------------------------------------------

QT       += core \
    testlib

QT       -= gui

TARGET = hash
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    hasher.cpp \
    hashFunction.cpp

HEADERS += \
    hasher.h \
    hasherTest.h \
    hashFunction.h \
    hashFunctionTest.h \
    userInterface.h