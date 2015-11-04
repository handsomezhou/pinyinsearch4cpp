#-------------------------------------------------
#
# Project created by QtCreator 2015-08-09T12:22:30
#
#-------------------------------------------------

QT       -= gui

TARGET = pinyinsearch
TEMPLATE = lib

DEFINES += PINYINSEARCH_LIBRARY

SOURCES += \
    T9Util.cpp \
    QwertyUtil.cpp \
    PinyinUtil.cpp \
    PinyinBaseUnit.cpp \
    PinyinUnit.cpp \
    PinyinSearchUnit.cpp

HEADERS +=\
        pinyinsearch_global.h \
    T9Util.h \
    QwertyUtil.h \
    PinyinUtil.h \
    PinyinBaseUnit.h \
    PinyinUnit.h \
    PinyinSearchUnit.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
