QT += core gui
QT += sql
QT += core sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = TestQT
CONFIG -= console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    gui/mainwindow.cpp \
    service/scientistservice.cpp \
    model/scientist.cpp \
    service/computerservice.cpp \
    model/computer.cpp \
    data/scientistaccess.cpp \
    data/computeraccess.cpp \
    data/linkaccess.cpp \
    service/generalservice.cpp \
    gui/listgui.cpp \
    gui/editgui.cpp \
    gui/removegui.cpp \
    gui/sortgui.cpp \
    gui/searchgui.cpp \
    gui/consolegui.cpp \
    gui/gamegui.cpp \
    gui/utilitygui.cpp \
    gui/add/addsci.cpp \
    gui/add/addcomp.cpp


HEADERS += \
    gui/mainwindow.h \
    service/scientistservice.h \
    model/scientist.h \
    service/computerservice.h \
    model/computer.h \
    data/scientistaccess.h \
    data/computeraccess.h \
    data/linkaccess.h \
    service/generalservice.h \
    gui/listgui.h \
    gui/editgui.h \
    gui/removegui.h \
    gui/sortgui.h \
    gui/searchgui.h \
    gui/consolegui.h \
    gui/gamegui.h \
    gui/utilitygui.h \
    gui/add/addsci.h \
    gui/add/addcomp.h

FORMS += \
    gui/mainwindow.ui \
    gui/listgui.ui \
    gui/editgui.ui \
    gui/removegui.ui \
    gui/sortgui.ui \
    gui/searchgui.ui \
    gui/consolegui.ui \
    gui/gamegui.ui \
    gui/utilitygui.ui \
    gui/add/addsci.ui \
    gui/add/addcomp.ui


