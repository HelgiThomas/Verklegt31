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
    service/scientistservice.cpp \
    model/scientist.cpp \
    service/computerservice.cpp \
    model/computer.cpp \
    data/scientistaccess.cpp \
    data/computeraccess.cpp \
    data/linkaccess.cpp \
    service/generalservice.cpp \
    gui/list/listgui.cpp \
    gui/consolegui.cpp \
    gui/game/gamegui.cpp \
    gui/add/addsci.cpp \
    gui/add/addcomp.cpp \
    gui/add/addrel.cpp \
    gui/remove/removecomp.cpp \
    gui/remove/removescigui.cpp \
    gui/edit/editcomp.cpp \
    gui/edit/editsci.cpp \
    gui/remove/removerelation.cpp \
    gui/list/infosci.cpp \
    gui/list/infocomp.cpp \
    gui/game/citationgame.cpp \
    gui/game/relationgame.cpp


HEADERS += \
    service/scientistservice.h \
    model/scientist.h \
    service/computerservice.h \
    model/computer.h \
    data/scientistaccess.h \
    data/computeraccess.h \
    data/linkaccess.h \
    service/generalservice.h \
    gui/list/listgui.h \
    gui/consolegui.h \
    gui/game/gamegui.h \
    gui/add/addcomp.h \
    gui/add/addsci.h \
    gui/add/addrel.h \
    gui/remove/removecomp.h \
    gui/remove/removescigui.h \
    gui/edit/editcomp.h \
    gui/edit/editsci.h \
    gui/remove/removerelation.h \
    gui/list/infosci.h \
    gui/list/infocomp.h \
    gui/game/citationgame.h \
    gui/game/relationgame.h

FORMS += \
    gui/list/listgui.ui \
    gui/consolegui.ui \
    gui/game/gamegui.ui \
    gui/add/addsci.ui \
    gui/add/addcomp.ui \
    gui/add/addrel.ui \
    gui/remove/removescigui.ui \
    gui/remove/removecomp.ui \
    gui/edit/editcomp.ui \
    gui/edit/editsci.ui \
    gui/remove/removerelation.ui \
    gui/list/infosci.ui \
    gui/list/infocomp.ui \
    gui/game/citationgame.ui \
    gui/game/relationgame.ui

RESOURCES += \
    gui/list/resource.qrc
