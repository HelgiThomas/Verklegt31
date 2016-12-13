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
    gui/sortgui.cpp \
    gui/searchgui.cpp \
    gui/consolegui.cpp \
    gui/gamegui.cpp \
    gui/utilitygui.cpp \
    gui/add/addsci.cpp \
<<<<<<< HEAD
    gui/removescigui.cpp \
    gui/removecomp.cpp \
    gui/edit/editcomp.cpp \
    gui/edit/editrelation.cpp \
    gui/edit/editsci.cpp
=======
    gui/add/addcomp.cpp \
    gui/add/addrel.cpp \
    gui/removecomp.cpp \
    gui/removescigui.cpp
>>>>>>> f99de35a28c932a3448fc4b973aeb449b08b2af9


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
    gui/sortgui.h \
    gui/searchgui.h \
    gui/consolegui.h \
    gui/gamegui.h \
    gui/utilitygui.h \
    gui/add/addcomp.h \
    gui/add/addsci.h \
<<<<<<< HEAD
    gui/removescigui.h \
    gui/removecomp.h \
    gui/edit/editcomp.h \
    gui/edit/editrelation.h \
    gui/edit/editsci.h
=======
    gui/add/addrel.h \
    gui/removecomp.h \
    gui/removescigui.h
>>>>>>> f99de35a28c932a3448fc4b973aeb449b08b2af9

FORMS += \
    gui/mainwindow.ui \
    gui/listgui.ui \
    gui/sortgui.ui \
    gui/searchgui.ui \
    gui/consolegui.ui \
    gui/gamegui.ui \
    gui/utilitygui.ui \
    gui/add/addsci.ui \
    gui/add/addcomp.ui \
    gui/add/addrel.ui \
    gui/removescigui.ui \
    gui/removecomp.ui \
    gui/edit/editcomp.ui \
    gui/edit/editrelation.ui \
    gui/edit/editsci.ui


