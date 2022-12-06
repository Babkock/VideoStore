/* main.cpp
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
#include "main.h"
#include "mainwindow.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

bool debugMode;
QSqlDatabase db;
double cashRegister;
double profits;

void dbConnect(const char *out) {
    const QString DRIVER("QSQLITE");
    QString dbName;
    if (!QSqlDatabase::isDriverAvailable(DRIVER)) {
        std::cerr << "Driver is not available" << std::endl;
        abort();
    }
    if (strlen(out) == 0) {
        dbName = (QString)"videostore.sql";
    } else if (strcmp(out, "-") == 0) {
        dbName = (QString)":memory:";
    } else {
        dbName = (QString)out;
    }
    db = QSqlDatabase::addDatabase(DRIVER);
    db.setHostName("videostore");
    db.setDatabaseName(out);
    db.setUserName("user");
    db.setPassword("password");
    if (!db.open()) {
        std::cerr << "Could not open database" << std::endl;
        abort();
    }
}

bool dbReload(void) {
    cashRegister = 50.0;
    profits = 0.0;
    bool exists = false;
    QSqlQuery create1, create2;
    if (!(create1.exec((QString)"CREATE TABLE `filmrent` (`id` INTEGER PRIMARY KEY AUTOINCREMENT, `title` VARCHAR(110), `director` VARCHAR(80), `year` INTEGER, `price` DOUBLE, `added` DATETIME, `quantity` INT(11), `available` INT(11), `lastRentedTo` VARCHAR(80), `lastRented` DATETIME)"))) {
        if (create1.lastError().number() != 1)
            std::cerr << create1.lastError().nativeErrorCode().toStdString() << " Error from first create: " << create1.lastError().text().toStdString() << std::endl;
        else {
            std::cout << "Reading filmrent table" << std::endl;
            exists = true;
        }
    }
    if (!(create2.exec((QString)"CREATE TABLE `filmsale` (`id` INTEGER PRIMARY KEY AUTOINCREMENT, `title` VARCHAR(110), `director` VARCHAR(80), `year` INTEGER, `price` DOUBLE, `added` DATETIME, `quantity` INT(11), `lastSoldTo` VARCHAR(80), `lastSold` DATETIME)"))) {
        if (create2.lastError().number() != 1)
            std::cerr << create2.lastError().nativeErrorCode().toStdString() << " Error from second create: " << create2.lastError().text().toStdString() << std::endl;
        else {
            std::cout << "Reading filmsale table" << std::endl;
            exists = true;
        }
    }
    if (!exists) {
        dbRepopulate();
    }
    return exists;
}

void dbRepopulate(void) {
    QSqlQuery ins1, ins2, ins3, ins4;
    if (!(ins1.exec((QString)"INSERT INTO `filmrent` VALUES(1, 'Persona', 'Ingmar Bergman', 1966, 6.99, NULL, 2, 2, '', NULL)"))) {
        if (ins1.lastError().number() != 19)
            std::cerr << ins1.lastError().nativeErrorCode().toStdString() << " Error from first insert: " << ins1.lastError().text().toStdString() << std::endl;
    }
    if (!(ins2.exec((QString)"INSERT INTO `filmrent` VALUES(2, 'Faces', 'John Cassavetes', 1968, 7.99, NULL, 3, 2, '', NULL)"))) {
        if (ins2.lastError().number() != 19)
            std::cerr << ins2.lastError().nativeErrorCode().toStdString() << " Error from second insert: " << ins2.lastError().text().toStdString() << std::endl;
    }
    if (!(ins3.exec((QString)"INSERT INTO `filmsale` VALUES(1, 'The Seventh Seal', 'Ingmar Bergman', 1957, 9.99, NULL, 1, '', NULL)"))) {
        if (ins3.lastError().number() != 19)
            std::cerr << ins3.lastError().nativeErrorCode().toStdString() << " Error from third insert: " << ins3.lastError().text().toStdString() << std::endl;
    }
    if (!(ins4.exec((QString)"INSERT INTO `filmsale` VALUES(2, 'Opening Night', 'John Cassavetes', 1977, 8.99, NULL, 2, '', NULL)"))) {
        if (ins4.lastError().number() != 19)
            std::cerr << ins4.lastError().nativeErrorCode().toStdString() << " Error from fourth insert: " << ins4.lastError().text().toStdString() << std::endl;
    }
    db.commit();
}

void dbReset(void) {
    cashRegister = 50.0;
    profits = 0.0;
    QSqlQuery drop, drop2;
    if (!(drop.exec((QString)"DROP TABLE `filmrent`"))) {
        std::cerr << drop.lastError().nativeErrorCode().toStdString() << " Error from first drop: " << drop.lastError().text().toStdString() << std::endl;
    } else if (!(drop2.exec((QString)"DROP TABLE `filmsale`"))) {
        std::cerr << drop2.lastError().nativeErrorCode().toStdString() << " Error from second drop: " << drop.lastError().text().toStdString() << std::endl;
    } else {
        dbReload();
    }
}

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
