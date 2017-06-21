#-------------------------------------------------
#
# Project created by QtCreator 2017-06-21T03:09:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Filtro
TEMPLATE = app

LIBS += -lfftw3f -ljack -lsndfile -lGL

INCLUDEPATH += /usr/include ##,"C:/fftwMinGW"



SOURCES += main.cpp\
        mainwindow.cpp \
    jack.cpp \
    filtro.cpp \
    dspsystem.cpp \
    controlvolume.cpp

HEADERS  += mainwindow.h \
    processor.h \
    jack.h \
    filtro.h \
    dspsystem.h \
    controlvolume.h

FORMS    += mainwindow.ui
