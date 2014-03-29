#-------------------------------------------------
#
# Project created by QtCreator 2014-02-22T20:39:09
#
#-------------------------------------------------

QT       += core gui widgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CPS111BrickBreaker
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        gameworld.cpp \
        gameobject.cpp \
        savemanager.cpp\
    gamewindow.cpp \
    inputdialog.cpp \
    highscorewindow.cpp \
    highscore.cpp \
    multiplayergui.cpp


HEADERS  += mainwindow.h \
        gameworld.h \
        gameobject.h \
        savemanager.h\
    gamewindow.h \
    inputdialog.h \
    highscorewindow.h \
    highscore.h \
    multiplayergui.h

FORMS    += mainwindow.ui \
    inputdialog.ui \
    gamewindow.ui \
    highscorewindow.ui \
    multiplayergui.ui

QMAKE_CXXFLAGS += -std=c++0x

RESOURCES += \
    resources.qrc
