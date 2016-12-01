QT += core
QT -= gui

CONFIG += c++11

TARGET = TestQT
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ui/consoleui.cpp \
    service/scientistservice.cpp \
    model/scientist.cpp \
    data/dataaccess.cpp

HEADERS += \
    ui/consoleui.h \
    service/scientistservice.h \
    model/scientist.h \
    data/dataaccess.h
