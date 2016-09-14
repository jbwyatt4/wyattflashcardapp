#-------------------------------------------------
#
# Project created by QtCreator 2016-09-10T17:29:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WyattFlashcardApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    addcarddialog.cpp \
    aboutdialog.cpp \
    decklist.cpp \
    deckitem.cpp \
    carditem.cpp \
    editdeckwindow.cpp

HEADERS  += mainwindow.h \
    addcarddialog.h \
    aboutdialog.h \
    decklist.h \
    deckitem.h \
    carditem.h \
    editdeckwindow.h

FORMS    += mainwindow.ui \
    addcarddialog.ui \
    aboutdialog.ui \
    decklist.ui \
    editdeckwindow.ui
