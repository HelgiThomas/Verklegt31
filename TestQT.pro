QT += core
QT -= gui

CONFIG += c++11

TARGET = TestQT
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    scientistservice.cpp \
    scientist.cpp \
    dataaccess.cpp

HEADERS += \
    consoleui.h \
    scientistservice.h \
    scientist.h \
    dataaccess.h
