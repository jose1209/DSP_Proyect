#-------------------------------------------------
#
# Project created by QtCreator 2017-05-10T15:52:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MediaPlayer
TEMPLATE = app

LIBS += -lfftw3f -ljack -lsndfile -lGL

INCLUDEPATH += /usr/include


SOURCES += main.cpp\
        mainwindow.cpp \
    jack.cpp \
    dspsystem.cpp \
    controlvolume.cpp \
    filtro.cpp

HEADERS  += mainwindow.h \
            jack.h \
            processor.h \
            dspsystem.h \
    controlvolume.h \
    filtro.h \
    constantes_filtros.h

FORMS    += mainwindow.ui
