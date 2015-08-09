#-------------------------------------------------
#
# Project created by QtCreator 2015-08-09T12:22:30
#
#-------------------------------------------------

QT       -= gui

TARGET = pinyinsearch
TEMPLATE = lib

DEFINES += PINYINSEARCH_LIBRARY

SOURCES += pinyinsearch.cpp

HEADERS += pinyinsearch.h\
        pinyinsearch_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
