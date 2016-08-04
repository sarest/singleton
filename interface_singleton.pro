#-------------------------------------------------
#
# Project created by QtCreator 2016-08-03T08:45:54
#
#-------------------------------------------------

QT       += core gui xml sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = interface_singleton
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mediator.cpp \
    files.cpp \
    functions.cpp \
    views/windowtarget.cpp \
    items/target.cpp \
    items/segment.cpp \
    views/myqgraphicsview.cpp

HEADERS  += mainwindow.h \
    mediator.h \
    files.h \
    functions.h \
    views/windowtarget.h \
    items/target.h \
    items/segment.h \
    views/myqgraphicsview.h

FORMS    += mainwindow.ui \
    views/windowtarget.ui
