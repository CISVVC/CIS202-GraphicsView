#-------------------------------------------------
#
# Project created by QtCreator 2016-05-24T16:10:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = graphicsView
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    circleanim.cpp \
    sinewave.cpp \
    coswave.cpp

HEADERS  += mainwindow.h \
    circleanim.h \
    sinewave.h \
    coswave.h

FORMS    += mainwindow.ui
