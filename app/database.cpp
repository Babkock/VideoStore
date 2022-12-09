/*
 * database.cpp
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
#include <iostream>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>

extern bool debugMode;
extern QSqlDatabase db;
extern double cashRegister;
extern double profits;

/* This function connects to the database with the given
 * string as the file name. If none is given, it uses the name
 * "videostore.sql". It prints an error if it cannot connect */
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

/* This function checks if the initial tables filmrent, filmsale, and
 * transactions are there. If they are not, it creates them. It returns
 * whether it found the tables or not. */
bool dbReload(void) {
    cashRegister = 50.0;
    profits = 0.0;
    bool exists = false;
    QSqlQuery create1, create2, create3;
    if (!(create1.exec((QString)"CREATE TABLE `filmrent` (`id` INTEGER PRIMARY KEY AUTOINCREMENT, `title` VARCHAR(110), `director` VARCHAR(80), `year` INTEGER, `price` DOUBLE, `added` DATETIME, `quantity` INT(11), `available` INT(11), `lastRentedTo` VARCHAR(80), `lastRented` DATETIME)"))) {
        if (create1.lastError().nativeErrorCode().toInt() != 1)
            std::cerr << create1.lastError().nativeErrorCode().toStdString() << " Error from filmrent create: " << create1.lastError().text().toStdString() << std::endl;
        else {
            std::cout << "Reading filmrent table" << std::endl;
            exists = true;
        }
    }
    if (!(create2.exec((QString)"CREATE TABLE `filmsale` (`id` INTEGER PRIMARY KEY AUTOINCREMENT, `title` VARCHAR(110), `director` VARCHAR(80), `year` INTEGER, `price` DOUBLE, `added` DATETIME, `quantity` INT(11), `lastSoldTo` VARCHAR(80), `lastSold` DATETIME)"))) {
        if (create2.lastError().nativeErrorCode().toInt() != 1)
            std::cerr << create2.lastError().nativeErrorCode().toStdString() << " Error from filmsale create: " << create2.lastError().text().toStdString() << std::endl;
        else {
            std::cout << "Reading filmsale table" << std::endl;
            exists = true;
        }
    }
    if (!(create3.exec((QString)"CREATE TABLE `transactions` (`id` INTEGER PRIMARY KEY, `cashRegister` DOUBLE, `profits` DOUBLE, `receipt` DATETIME)"))) {
        if (create3.lastError().nativeErrorCode().toInt() != 1)
           std::cerr << create3.lastError().nativeErrorCode().toStdString() << "Error from transactions create: " << create3.lastError().text().toStdString() << std::endl;
        else {
            std::cout << "Reading transactions table" << std::endl;
            exists = true;
        }
    }
    if (!exists)
        dbRepopulate();
    else
        db.commit();
    return exists;
}

/* This function seeds the database with sample data. It
 * inserts two rows each into filmrent and filmsale,
 * and one row into transactions */
void dbRepopulate(void) {
    QSqlQuery ins1, ins2, ins3, ins4, ins5;
    /* it is possible to use NULL for the ID fields here, but that
     * might overpopulate the DB */
    if (!(ins1.exec((QString)"INSERT INTO `filmrent` VALUES(1, 'Persona', 'Ingmar Bergman', 1966, 6.99, NULL, 2, 2, '', NULL)"))) {
        if (ins1.lastError().nativeErrorCode().toInt() != 19)
            std::cerr << ins1.lastError().nativeErrorCode().toStdString() << " Error from first insert: " << ins1.lastError().text().toStdString() << std::endl;
    }
    if (!(ins2.exec((QString)"INSERT INTO `filmrent` VALUES(2, 'Faces', 'John Cassavetes', 1968, 7.99, NULL, 3, 2, '', NULL)"))) {
        if (ins2.lastError().nativeErrorCode().toInt() != 19)
            std::cerr << ins2.lastError().nativeErrorCode().toStdString() << " Error from second insert: " << ins2.lastError().text().toStdString() << std::endl;
    }
    if (!(ins3.exec((QString)"INSERT INTO `filmsale` VALUES(1, 'The Seventh Seal', 'Ingmar Bergman', 1957, 9.99, NULL, 1, '', NULL)"))) {
        if (ins3.lastError().nativeErrorCode().toInt() != 19)
            std::cerr << ins3.lastError().nativeErrorCode().toStdString() << " Error from third insert: " << ins3.lastError().text().toStdString() << std::endl;
    }
    if (!(ins4.exec((QString)"INSERT INTO `filmsale` VALUES(2, 'Opening Night', 'John Cassavetes', 1977, 8.99, NULL, 2, '', NULL)"))) {
        if (ins4.lastError().nativeErrorCode().toInt() != 19)
            std::cerr << ins4.lastError().nativeErrorCode().toStdString() << " Error from fourth insert: " << ins4.lastError().text().toStdString() << std::endl;
    }
    if (!(ins5.exec((QString)"INSERT INTO `transactions` VALUES(1, 50.0, 0.0, NULL)"))) {
        if (ins5.lastError().nativeErrorCode().toInt() != 19)
            std::cerr << ins5.lastError().nativeErrorCode().toStdString() << " Error from fifth insert: " << ins5.lastError().text().toStdString() << std::endl;
    }
    db.commit();
}

/* This function drops the tables from the database, then
 * re-creates them and re-seeds them */
void dbReset(void) {
    cashRegister = 50.0;
    profits = 0.0;
    QSqlQuery drop, drop2, drop3;
    if (!(drop.exec((QString)"DROP TABLE `filmrent`"))) {
        std::cerr << drop.lastError().nativeErrorCode().toStdString() << " Error from first drop: " << drop.lastError().text().toStdString() << std::endl;
    } else if (!(drop2.exec((QString)"DROP TABLE `filmsale`"))) {
        std::cerr << drop2.lastError().nativeErrorCode().toStdString() << " Error from second drop: " << drop2.lastError().text().toStdString() << std::endl;
    } else if (!(drop3.exec((QString)"DROP TABLE `transactions`"))) {
        std::cerr << drop3.lastError().nativeErrorCode().toStdString() << " Error from third drop: " << drop3.lastError().text().toStdString() << std::endl;
    } else {
        db.commit();
        dbReload();
    }
}
