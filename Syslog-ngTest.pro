#-------------------------------------------------
#
# Project created by QtCreator 2015-03-15T08:00:42
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Syslog-ngTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    yamlparser.cpp \
    yamlfilehandler.cpp

HEADERS  += mainwindow.h \
    yamlparser.h \
    yamlfilehandler.h

FORMS    += mainwindow.ui
