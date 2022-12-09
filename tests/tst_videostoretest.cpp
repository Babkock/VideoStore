/*
 * tst_videostoretest.cpp
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November-December 2022
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
#include "film.h"
#include "mainwindow.h"
#include "shoppingcart.h"
#include <iostream>
#include <unistd.h>
#include <QtTest>
#include <QCoreApplication>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>

bool debugMode;
QSqlDatabase db;
double cashRegister;
double profits;

class videoStoreTest : public QObject {
    Q_OBJECT
public:
    videoStoreTest(void);
    ~videoStoreTest(void);
private slots:
    void initTestCase(void);
    void cleanupTestCase(void);
    void test_filmrent(void);
    void test_filmsale(void);
    void test_selectrent(void);
    void test_selectsale(void);
    void test_updaterent(void);
    void test_updatesale(void);
    void test_shoppingcart(void);
    void test_transaction(void);
};

videoStoreTest::videoStoreTest(void) {
    std::cout << "Tests initialized" << std::endl;
}

videoStoreTest::~videoStoreTest(void) {

}

void videoStoreTest::initTestCase(void) {
    unlink("test.sql");
    const QString DRIVER("QSQLITE");
    QString dbName = "test.sql";

    if (!QSqlDatabase::isDriverAvailable(DRIVER)) {
        std::cerr << "Driver is not available" << std::endl;
        abort();
    }

    db = QSqlDatabase::addDatabase(DRIVER);
    db.setHostName("videostore");
    db.setDatabaseName(dbName);
    db.setUserName("user");
    db.setPassword("password");
    std::cout << "Opening Database" << std::endl;
    QCOMPARE(db.open(), true);

    QSqlQuery *create1 = new QSqlQuery(), *create2 = new QSqlQuery(), *create3 = new QSqlQuery();
    if (!(create1->exec((QString)"CREATE TABLE `filmrent` (`id` INTEGER PRIMARY KEY AUTOINCREMENT, `title` VARCHAR(110), `director` VARCHAR(80), `year` INTEGER, `price` DOUBLE, `added` DATETIME, `quantity` INT(11), `available` INT(11), `lastRentedTo` VARCHAR(80), `lastRented` DATETIME)"))) {
        if (create1->lastError().number() != 1)
            std::cerr << "Error from first create: " << create1->lastError().text().toStdString() << std::endl;
    } else {
        std::cout << "Successfully created filmrent table" << std::endl;
    }

    if (!(create2->exec((QString)"CREATE TABLE `filmsale` (`id` INTEGER PRIMARY KEY AUTOINCREMENT, `title` VARCHAR(110), `director` VARCHAR(80), `year` INTEGER, `price` DOUBLE, `added` DATETIME, `quantity` INT(11), `lastSoldTo` VARCHAR(80), `lastSold` DATETIME)"))) {
        if (create2->lastError().number() != 1)
            std::cerr << "Error from second create: " << create2->lastError().text().toStdString() << std::endl;
    } else {
        std::cout << "Successfully created filmsale table" << std::endl;
    }

    if (!(create3->exec((QString)"CREATE TABLE `transactions` (`id` INTEGER PRIMARY KEY AUTOINCREMENT, `cashRegister` DOUBLE, `profits` DOUBLE, `receipt` DATETIME)"))) {
        if (create3->lastError().number() != 1)
            std::cerr << "Error from third create: " << create3->lastError().text().toStdString() << std::endl;
    } else {
        std::cout << "Successfully created transactions table" << std::endl;
    }

    delete create1;
    delete create2;
    delete create3;
    db.commit();
}

void videoStoreTest::cleanupTestCase(void) {
    QSqlQuery drop1("DROP TABLE `filmrent`");
    QSqlQuery drop2("DROP TABLE `filmsale`");
    db.close();
    unlink("test.sql");
}

void videoStoreTest::test_filmrent(void) {
    FilmRent *f = new FilmRent(Film("Kings of the Road", "Wim Wenders", 1976, 5.99), 10);
    QCOMPARE(f->getTitle().toStdString(), "Kings of the Road");
    QCOMPARE(f->getDirector().toStdString(), "Wim Wenders");
    QCOMPARE(f->getYear(), (unsigned int)1976);
    QCOMPARE(f->getPrice(), 5.99);
    QCOMPARE(f->getQuantity(), 10);

    QSqlQuery *ins = new QSqlQuery();
    ins->prepare("INSERT INTO `filmrent` (`id`, `title`, `director`, `year`, `price`, `added`, `quantity`, `available`, `lastRentedTo`, `lastRented`) VALUES (1, ?, ?, ?, ?, ?, ?, ?, ?, NULL)");
    ins->addBindValue(f->getTitle());
    ins->addBindValue(f->getDirector());
    ins->addBindValue(f->getYear());
    ins->addBindValue(f->getPrice());
    ins->addBindValue(f->getAdded().toString("yyyy-MM-dd hh:mm:ss"));
    ins->addBindValue(f->getQuantity());
    ins->addBindValue(f->getAvailable());
    ins->addBindValue(f->getLastRentedTo());
    QCOMPARE(ins->exec(), true);
    delete ins;
    delete f;

    db.commit();
    std::cout << "Inserted row into filmrent table" << std::endl;
}

void videoStoreTest::test_filmsale(void) {
    FilmSale *f = new FilmSale(Film("Manhattan", "Woody Allen", 1979, 7.99), 12);
    QCOMPARE(f->getTitle().toStdString(), "Manhattan");
    QCOMPARE(f->getDirector().toStdString(), "Woody Allen");
    QCOMPARE(f->getYear(), (unsigned int)1979);
    QCOMPARE(f->getPrice(), 7.99);
    QCOMPARE(f->getQuantity(), 12);

    QSqlQuery *ins = new QSqlQuery();
    ins->prepare("INSERT INTO `filmsale` (`id`, `title`, `director`, `year`, `price`, `added`, `quantity`, `lastSoldTo`, `lastSold`) VALUES (1, ?, ?, ?, ?, ?, ?, ?, NULL)");
    ins->addBindValue(f->getTitle());
    ins->addBindValue(f->getDirector());
    ins->addBindValue(f->getYear());
    ins->addBindValue(f->getPrice());
    ins->addBindValue(f->getAdded().toString("yyyy-MM-dd hh:mm:ss"));
    ins->addBindValue(f->getQuantity());
    ins->addBindValue(f->getLastSoldTo());
    QCOMPARE(ins->exec(), true);
    delete ins;
    delete f;

    db.commit();
    std::cout << "Inserted row into filmsale table" << std::endl;
}

void videoStoreTest::test_selectrent(void) {
    QSqlQuery *sel = new QSqlQuery();
    sel->prepare("SELECT * FROM `filmrent` WHERE `id`=? LIMIT 1");
    sel->addBindValue(1);
    QCOMPARE(sel->exec(), true);
    QCOMPARE(sel->next(), true);
    QCOMPARE(sel->value(0).toInt(), 1);
    QCOMPARE(sel->value(1).toString().toStdString().c_str(), "Kings of the Road");
    QCOMPARE(sel->value(2).toString().toStdString().c_str(), "Wim Wenders");
    QCOMPARE(sel->value(3).toInt(), 1976);
    QCOMPARE(sel->value(4).toDouble(), 5.99);
    QCOMPARE(sel->value(6).toInt(), 10);

    delete sel;
    std::cout << "Selected film from filmrent" << std::endl;
}

void videoStoreTest::test_selectsale(void) {
    QSqlQuery *sel = new QSqlQuery();
    sel->prepare("SELECT * FROM `filmsale` WHERE `id`=? LIMIT 1");
    sel->addBindValue(1);
    QCOMPARE(sel->exec(), true);
    QCOMPARE(sel->next(), true);
    QCOMPARE(sel->value(0).toInt(), 1);
    QCOMPARE(sel->value(1).toString().toStdString().c_str(), "Manhattan");
    QCOMPARE(sel->value(2).toString().toStdString().c_str(), "Woody Allen");
    QCOMPARE(sel->value(3).toInt(), 1979);
    QCOMPARE(sel->value(4).toDouble(), 7.99);
    QCOMPARE(sel->value(6).toInt(), 12);

    delete sel;
    std::cout << "Selected film from filmsale" << std::endl;
}

void videoStoreTest::test_shoppingcart(void) {
    std::vector<ShoppingCartItem> *cart = new std::vector<ShoppingCartItem>();
    cart->push_back((ShoppingCartItem){ .rental = true, .id = 2, .quantity = 2, .price = 5.99, .title = "Title", .director = "Director" });
    cart->push_back((ShoppingCartItem){ .rental = false, .id = 3, .quantity = 1, .price = 6.99, .title = "Another Movie", .director = "Another Guy" });

    QCOMPARE(cart->size(), (unsigned int)2);
    int x = 0;
    for (auto it : *cart) {
        if (x == 0) {
            QCOMPARE(it.id, (unsigned int)2);
            QCOMPARE(it.quantity, 2);
            QCOMPARE(it.price, 5.99);
            QCOMPARE(it.title, "Title");
        } else if (x == 1) {
            QCOMPARE(it.id, (unsigned int)3);
            QCOMPARE(it.quantity, 1);
            QCOMPARE(it.price, 6.99);
            QCOMPARE(it.title, "Another Movie");
        }
        x++;
    }
    delete cart;
}

void videoStoreTest::test_transaction(void) {
    QSqlQuery *ins1 = new QSqlQuery(), *ins2 = new QSqlQuery();
    ins1->prepare("INSERT INTO `transactions` (`id`, `cashRegister`, `profits`, `receipt`) VALUES (?, ?, ?, NULL)");
    ins1->addBindValue(1);
    ins1->addBindValue(32.32);
    ins1->addBindValue(2.32);
    QCOMPARE(ins1->exec(), true);

    ins2->prepare("INSERT INTO `transactions` (`id`, `cashRegister`, `profits`, `receipt`) VALUES (?, ?, ?, NULL)");
    ins2->addBindValue(2);
    ins2->addBindValue(69.69);
    ins2->addBindValue(39.60);
    QCOMPARE(ins2->exec(), true);

    delete ins1;
    delete ins2;
    db.commit();
}

void videoStoreTest::test_updaterent(void) {
    FilmRent *f = new FilmRent(Film(1, "Stalker", "Andrei Tarkovsky", 1979, 9.99), 1);
    QCOMPARE(f->getTitle(), "Stalker");
    QCOMPARE(f->getDirector(), "Andrei Tarkovsky");
    QCOMPARE(f->getYear(), (unsigned int)1979);

    QSqlQuery *update = new QSqlQuery();
    update->prepare("UPDATE `filmrent` SET `title`=?, `director`=?, `year`=?, `price`=?, `added`=?, `quantity`=?, `available`=?, `lastRented`=?, `lastRentedTo`=? WHERE `id`=?");
    update->addBindValue(f->getTitle());
    update->addBindValue(f->getDirector());
    update->addBindValue(f->getYear());
    update->addBindValue(f->getPrice());
    update->addBindValue(f->getAdded().toString("yyyy-MM-dd hh:mm:ss"));
    update->addBindValue(f->getQuantity());
    update->addBindValue(f->getAvailable());
    update->addBindValue(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    update->addBindValue(f->getLastRentedTo());
    update->addBindValue(f->getId());
    QCOMPARE(update->exec(), true);
    delete update;
    delete f;

    db.commit();
    std::cout << "Updated film in filmrent" << std::endl;
}

void videoStoreTest::test_updatesale(void) {
    FilmSale *f = new FilmSale(Film(1, "Funny Games", "Michael Haneke", 1997, 6.99), 2);
    QCOMPARE(f->getTitle(), "Funny Games");
    QCOMPARE(f->getDirector(), "Michael Haneke");
    QCOMPARE(f->getPrice(), 6.99);

    QSqlQuery *update = new QSqlQuery();
    update->prepare("UPDATE `filmsale` SET `title`=?, `director`=?, `year`=?, `price`=?, `added`=?, `quantity`=?, `lastSoldTo`=?, `lastSold`=? WHERE `id`=?");
    update->addBindValue(f->getTitle());
    update->addBindValue(f->getDirector());
    update->addBindValue(f->getYear());
    update->addBindValue(f->getPrice());
    update->addBindValue(f->getAdded().toString("yyyy-MM-dd hh:mm:ss"));
    update->addBindValue(f->getQuantity());
    update->addBindValue(f->getLastSoldTo());
    update->addBindValue(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    update->addBindValue(f->getId());
    QCOMPARE(update->exec(), true);
    delete update;
    delete f;

    db.commit();
    std::cout << "Updated film in filmsale" << std::endl;
}

QTEST_MAIN(videoStoreTest)

#include "tst_videostoretest.moc"
