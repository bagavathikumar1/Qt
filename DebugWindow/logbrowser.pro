QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
 
TARGET = DebugWindow
TEMPLATE = app
 
SOURCES += main.cpp logbrowserdialog.cpp logbrowser.cpp
HEADERS  += logbrowserdialog.h logbrowser.h
