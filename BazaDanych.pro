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
                toolstime.cpp           \
                SqLiteMaper.cpp         \
                StringTools.cpp         \
                Log.cpp

HEADERS     += mainwindow.h 		\
                ConfigManager.h 	\
                toolstime.h             \
                SqLiteMaper.h           \
                StringTools.h           \
                Log.h

FORMS       += mainwindow.ui

OTHER_FILES += ZapytaniaSql.sql 	\
                doxyEnterys.txt 	\
                Dokumentacja.txt        \
                config.conf             \
                Plan.txt

RESOURCES   += icons.qrc

INCLUDEPATH += $$quote(c:/Boost/include/boost-1_46_1)
LIBS        += $$quote(c:/Boost/lib/libboost_date_time-mgw44-mt-s-1_46_1.a)
