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
    gui/sortgui.cpp \
    gui/searchgui.cpp \
    gui/consolegui.cpp \
    gui/gamegui.cpp \
    gui/utilitygui.cpp \
    gui/add/addcomp.cpp \
    gui/add/addsci.cpp \
<<<<<<< HEAD
    gui/add/addcomp.cpp \
    gui/add/addrel.cpp
=======
    gui/removescigui.cpp \
    gui/removecomp.cpp
>>>>>>> be4dfcd33d1f3bd2d6fd42038d6200038ee9dd6b


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
    gui/sortgui.h \
    gui/searchgui.h \
    gui/consolegui.h \
    gui/gamegui.h \
    gui/utilitygui.h \
    gui/add/addcomp.h \
    gui/add/addsci.h \
<<<<<<< HEAD
    gui/add/addcomp.h \
    gui/add/addrel.h
=======
    gui/removescigui.h \
    gui/removecomp.h
>>>>>>> be4dfcd33d1f3bd2d6fd42038d6200038ee9dd6b

FORMS += \
    gui/mainwindow.ui \
    gui/listgui.ui \
    gui/editgui.ui \
    gui/sortgui.ui \
    gui/searchgui.ui \
    gui/consolegui.ui \
    gui/gamegui.ui \
    gui/utilitygui.ui \
    gui/add/addcomp.ui \
    gui/add/addsci.ui \
<<<<<<< HEAD
    gui/add/addcomp.ui \
    gui/add/addrel.ui
=======
    gui/removescigui.ui \
    gui/removecomp.ui
>>>>>>> be4dfcd33d1f3bd2d6fd42038d6200038ee9dd6b


