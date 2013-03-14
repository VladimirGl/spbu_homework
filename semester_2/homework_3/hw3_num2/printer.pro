#-------------------------------------------------
#
# Project created by QtCreator 2013-03-08T17:21:49
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = printer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    spiralprinter.cpp \
    consoleprint.cpp \
    fileprint.cpp

HEADERS += \
    spiralprinter.h \
    consoleprint.h \
    fileprint.h
