#-------------------------------------------------
#
# Project created by QtCreator 2016-09-10T17:29:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WyattFlashcardApp
TEMPLATE = app
#QMAKE_CXXFLAGS += -std=c++0x # how to add a qt flag

SOURCES += main.cpp\
        mainwindow.cpp \
    aboutdialog.cpp \
    deckitem.cpp \
    carditem.cpp \
    editdeckwindow.cpp \
    addcarddialog.cpp \
    cardviewer.cpp \
    misc.cpp

HEADERS  += mainwindow.h \
    aboutdialog.h \
    deckitem.h \
    carditem.h \
    editdeckwindow.h \
    addcarddialog.h \
    cardviewer.h \
    misc.h

FORMS    += mainwindow.ui \
    aboutdialog.ui \
    editdeckwindow.ui \
    addcarddialog.ui \
    cardviewer.ui

OTHER_FILES += \
    Notes.txt

RESOURCES += \
    resource.qrc
