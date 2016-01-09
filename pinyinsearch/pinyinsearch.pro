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




INCLUDEPATH += $$PWD/../../pinyin4cpp/build-pinyin4cpp-Desktop_Qt_5_2_1_MinGW_32bit-Debug/debug
DEPENDPATH += $$PWD/../../pinyin4cpp/build-pinyin4cpp-Desktop_Qt_5_2_1_MinGW_32bit-Debug/debug

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../pinyin4cpp/build-pinyin4cpp-MinGW_Custom-Debug/release/ -lpinyin4cpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../pinyin4cpp/build-pinyin4cpp-MinGW_Custom-Debug/debug/ -lpinyin4cpp
else:unix: LIBS += -L$$PWD/../../pinyin4cpp/build-pinyin4cpp-MinGW_Custom-Debug/ -lpinyin4cpp

INCLUDEPATH += $$PWD/../../pinyin4cpp/build-pinyin4cpp-MinGW_Custom-Debug/debug
DEPENDPATH += $$PWD/../../pinyin4cpp/build-pinyin4cpp-MinGW_Custom-Debug/debug
