#-------------------------------------------------
#
# Project created by QtCreator 2015-01-30T15:04:17
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AssetInfo
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    Database.cpp

HEADERS  += widget.h \
    Database.h

FORMS    += widget.ui
