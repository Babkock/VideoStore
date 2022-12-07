/*
 * main.cpp
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
/**********************************
 * OS: Void GNU/Linux
 * IDE: QtCreator
 * Copyright : This is my own original work based
 * on specifications issued by our instructor.
 * Academic Honesty: I attest that this is my original
 * work. I have not used unauthorized source code,
 * either modified or unmodified. I have not given
 * other fellow student(s) access to my program.
***********************************/
#include "database.h"
#include "mainwindow.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QSqlDatabase>
#include <QSqlQuery>

bool debugMode;
QSqlDatabase db;
double cashRegister;
double profits;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    dbConnect("videostore.sql");
    if (dbReload()) {
        std::cout << "Reloading existing database" << std::endl;
    } else {
        std::cout << "Writing new database" << std::endl;
    }
    cashRegister = 50.0;
    profits = 0.0;

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "VideoStore_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    a.exec();
    return 0;
}
