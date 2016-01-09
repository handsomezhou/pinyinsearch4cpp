#-------------------------------------------------
#
# Project created by QtCreator 2015-08-09T12:19:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pinyinsearchdemo
TEMPLATE = app


SOURCES += main.cpp\
        pinyinsearchdemo.cpp \
    BaseContacts.cpp \
    Contacts.cpp \
    ContactsHelper.cpp

HEADERS  += pinyinsearchdemo.h \
    BaseContacts.h \
    Contacts.h \
    ContactsHelper.h

RESOURCES += \
    res.qrc




INCLUDEPATH += $$PWD/../build-pinyinsearch-Desktop_Qt_5_2_1_MinGW_32bit-Debug/debug
DEPENDPATH += $$PWD/../build-pinyinsearch-Desktop_Qt_5_2_1_MinGW_32bit-Debug/debug

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-pinyinsearch-MinGW_Custom-Debug/release/ -lpinyinsearch
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-pinyinsearch-MinGW_Custom-Debug/debug/ -lpinyinsearch
else:unix: LIBS += -L$$PWD/../build-pinyinsearch-MinGW_Custom-Debug/ -lpinyinsearch

INCLUDEPATH += $$PWD/../build-pinyinsearch-MinGW_Custom-Debug/debug
DEPENDPATH += $$PWD/../build-pinyinsearch-MinGW_Custom-Debug/debug

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../pinyin4cpp/build-pinyin4cpp-MinGW_Custom-Debug/release/ -lpinyin4cpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../pinyin4cpp/build-pinyin4cpp-MinGW_Custom-Debug/debug/ -lpinyin4cpp
else:unix: LIBS += -L$$PWD/../../pinyin4cpp/build-pinyin4cpp-MinGW_Custom-Debug/ -lpinyin4cpp

INCLUDEPATH += $$PWD/../../pinyin4cpp/build-pinyin4cpp-MinGW_Custom-Debug/debug
DEPENDPATH += $$PWD/../../pinyin4cpp/build-pinyin4cpp-MinGW_Custom-Debug/debug
