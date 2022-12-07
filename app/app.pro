# VideoStore app.pro
# Tanner Babcock
# CIS 152 - Data Structures
# Final Project: Video Store
# November - December 2022
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VideoStore

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    database.cpp \
	mainwindow.cpp \
    film.cpp \
    purchasesform.cpp \
    purchaseswindow.cpp \
    rentalsform.cpp \
    rentalswindow.cpp \
    shoppingcart.cpp

HEADERS += database.h \
    mainwindow.h \
    film.h \
    purchasesform.h \
    purchaseswindow.h \
    rentalsform.h \
    rentalswindow.h \
    shoppingcart.h

FORMS += mainwindow.ui \
    purchasesform.ui \
    purchaseswindow.ui \
    rentalsform.ui \
    rentalswindow.ui \
    shoppingcart.ui

TRANSLATIONS += VideoStore_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
