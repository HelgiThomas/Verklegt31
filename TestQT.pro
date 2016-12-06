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
<<<<<<< Updated upstream
    model/computer.cpp
=======
<<<<<<< HEAD
    service/computerservice.cpp
=======
    model/computer.cpp
>>>>>>> e04bad6a3565e7266176c7ca3ab6ac9bb482fe54
>>>>>>> Stashed changes

HEADERS += \
    ui/consoleui.h \
    service/scientistservice.h \
    model/scientist.h \
    data/dataaccess.h \
<<<<<<< Updated upstream
    model/computer.h
=======
<<<<<<< HEAD
    service/computerservice.h
=======
    model/computer.h
>>>>>>> e04bad6a3565e7266176c7ca3ab6ac9bb482fe54
>>>>>>> Stashed changes
