# VideoStore tests.pro
# Tanner Babcock
# CIS 152 - Data Structures
# Final Project: Video Store
# November-December 2022
QT += core testlib sql gui widgets
TARGET = tests

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app
INCLUDEPATH = ../app
VPATH = "../app"

FORMS += \
    mainwindow.ui \
	rentalswindow.ui \
	purchaseswindow.ui \
	rentalsform.ui \
	purchasesform.ui \
	shoppingcart.ui

SOURCES += \
    tst_videostoretest.cpp \
	database.cpp \
	film.cpp \
	mainwindow.cpp \
	rentalswindow.cpp \
	purchaseswindow.cpp \
	rentalsform.cpp \
	purchasesform.cpp \
	shoppingcart.cpp

HEADERS += \
    database.h \
	film.h \
	mainwindow.h \
	rentalswindow.h \
	purchaseswindow.h \
	rentalsform.h \
	purchasesform.h \
	shoppingcart.h
