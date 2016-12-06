QT += core
QT += sql
QT += core sql
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
    data/dataaccess.cpp \
    service/computerservice.cpp \
    model/computer.cpp \
    data/scientistaccess.cpp \
    data/computeraccess.cpp \
    data/linkaccess.cpp \
    service/generalservice.cpp
    model/computer.cpp
    service/computerservice.cpp
    model/computer.cpp

HEADERS += \
    ui/consoleui.h \
    service/scientistservice.h \
    model/scientist.h \
    data/dataaccess.h \
    service/computerservice.h \
    model/computer.h \
    data/scientistaccess.h \
    data/computeraccess.h \
    data/linkaccess.h \
    service/generalservice.h
    model/computer.h
    service/computerservice.h
    model/computer.h
