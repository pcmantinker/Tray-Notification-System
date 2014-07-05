#-------------------------------------------------
#
# Project created by QtCreator 2012-02-24T18:42:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tray-Notification-System
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    traynotificationwidget.cpp \
    traynotificationmanager.cpp

HEADERS  += mainwindow.h \
    traynotificationwidget.h \
    traynotificationmanager.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
