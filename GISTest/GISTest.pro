#-------------------------------------------------
#
# Project created by QtCreator 2018-01-27T10:44:28
#
#-------------------------------------------------

#QT       += core gui

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#TARGET = GISTest
#TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


#SOURCES += main.cpp\
#        mainwindow.cpp

#HEADERS  += mainwindow.h

#FORMS    += mainwindow.ui

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GISTest
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp

## QGIS
QGIS_DIR = "D:/OSGeo4W/apps/qgis"
INCLUDEPATH +=  "D:/OSGeo4W/include"
INCLUDEPATH +=  $$QGIS_DIR/include $$QGIS_DIR/plugins

#LIBS += -L"D:/OSGeo4W/apps/qgis/lib" -lqgis_core -lqgis_gui

LIBS += $$QGIS_DIR/lib/qgis_core.lib
LIBS += $$QGIS_DIR/lib/qgis_gui.lib
LIBS += $$QGIS_DIR/lib/qgis_app.lib


DLLDESTDIR += $$QGIS_DIR/bin

DEFINES+=CORE_EXPORT=
DEFINES+=GUI_EXPORT=
## QGIS
