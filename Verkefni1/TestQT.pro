QT += core
QT -= gui

CONFIG += c++11

TARGET = TestQT
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    performerservice.cpp \
    performer.cpp \
    scientist.cpp \
    scientistservice.cpp

HEADERS += \
    consoleui.h \
    performerservice.h \
    scientist.h \
    scientistservice.h
