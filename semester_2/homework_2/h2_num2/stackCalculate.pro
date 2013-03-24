#-------------------------------------------------
#
# Project created by QtCreator 2013-03-24T21:47:07
#
#-------------------------------------------------

QT       += core \
    testlib

QT       -= gui

TARGET = stackCalculate
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    arrayStack.cpp \
    pointerStack.cpp \
    stackCalculate.cpp \
    stringParser.cpp \
    translateIntoPolish.cpp


HEADERS += arrayStack.h \
    pointerStack.h \
    stack.h \
    stackCalculate.h \
    stringParser.h \
    translateIntoPolish.h \
    testStack.h \
    testCalculate.h

