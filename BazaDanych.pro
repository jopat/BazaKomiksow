#-------------------------------------------------
#
# Project created by QtCreator 2010-12-07T11:42:25
#
#-------------------------------------------------

QT          += core gui
QT          += sql

TARGET      = BazaDanych
TEMPLATE    = app


SOURCES     += main.cpp                 \
                mainwindow.cpp 		\
                ConfigManager.cpp 	\
                toolstime.cpp \
                SqLiteMaper.cpp \
    StringTools.cpp

HEADERS     += mainwindow.h 		\
                ConfigManager.h 	\
                toolstime.h \
                SqLiteMaper.h \
    StringTools.h

FORMS       += mainwindow.ui 		\
                createdatabase.ui

OTHER_FILES += ZapytaniaSql.sql 	\
                doxyEnterys.txt 	\
                Dokumentacja.txt        \
                config.conf

RESOURCES   += icons.qrc
