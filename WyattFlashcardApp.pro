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
    aboutdialog.cpp \
    decklist.cpp \
    deckitem.cpp \
    carditem.cpp \
    editdeckwindow.cpp \
    addcarddialog.cpp

HEADERS  += mainwindow.h \
    aboutdialog.h \
    decklist.h \
    deckitem.h \
    carditem.h \
    editdeckwindow.h \
    addcarddialog.h \
    defs.h

FORMS    += mainwindow.ui \
    aboutdialog.ui \
    decklist.ui \
    editdeckwindow.ui \
    addcarddialog.ui

OTHER_FILES += \
    Notes.txt
