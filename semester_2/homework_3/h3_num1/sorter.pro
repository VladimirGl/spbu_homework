#-------------------------------------------------
#
# Project created by QtCreator 2013-03-08T14:13:57
#
#-------------------------------------------------

QT       += core \
    testlib

QT       -= gui

TARGET = sorter
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    sorter.cpp \
    qsort.cpp \
    hsort.cpp \
    bsort.cpp

HEADERS += \
    sorter.h \
    qsort.h \
    hsort.h \
    bsort.h \
    testSorter.h
