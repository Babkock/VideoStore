#include "film.h"
#include "database.h"
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
};

videoStoreTest::videoStoreTest(void) {

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

    QSqlQuery create1, create2;
    if (!(create1.exec((QString)"CREATE TABLE `filmrent` (`id` INTEGER PRIMARY KEY AUTOINCREMENT, `title` VARCHAR(110), `director` VARCHAR(80), `year` INTEGER, `price` DOUBLE, `added` DATETIME, `quantity` INT(11), `available` INT(11), `lastRentedTo` VARCHAR(80), `lastRented` DATETIME)"))) {
        if (create1.lastError().number() != 1)
            std::cerr << create1.lastError().nativeErrorCode().toStdString() << " Error from first create: " << create1.lastError().text().toStdString() << std::endl;
    } else {
        std::cout << "Successfully created filmrent table" << std::endl;
    }
    if (!(create2.exec((QString)"CREATE TABLE `filmsale` (`id` INTEGER PRIMARY KEY AUTOINCREMENT, `title` VARCHAR(110), `director` VARCHAR(80), `year` INTEGER, `price` DOUBLE, `added` DATETIME, `quantity` INT(11), `lastSoldTo` VARCHAR(80), `lastSold` DATETIME)"))) {
        if (create2.lastError().number() != 1)
            std::cerr << create2.lastError().nativeErrorCode().toStdString() << " Error from second create: " << create2.lastError().text().toStdString() << std::endl;
    } else {
        std::cout << "Successfully created filmsale table" << std::endl;
    }
    db.commit();
}

void videoStoreTest::cleanupTestCase(void) {
    db.close();
    unlink("test.sql");
}

void videoStoreTest::test_filmrent(void) {
    FilmRent f = FilmRent(Film("Kings of the Road", "Wim Wenders", 1976, 5.99), 10);
    QCOMPARE(f.getTitle().toStdString(), "Kings of the Road");
    QCOMPARE(f.getDirector().toStdString(), "Wim Wenders");
    QCOMPARE(f.getYear(), (unsigned int)1976);
    QCOMPARE(f.getPrice(), 5.99);
    QCOMPARE(f.getQuantity(), 10);

    QSqlQuery ins;
    ins.prepare("INSERT INTO `filmrent` (`id`, `title`, `director`, `year`, `price`, `added`, `quantity`, `available`, `lastRentedTo`, `lastRented`) VALUES (1, ?, ?, ?, ?, ?, ?, ?, ?, NULL)");
    ins.addBindValue(f.getTitle());
    ins.addBindValue(f.getDirector());
    ins.addBindValue(f.getYear());
    ins.addBindValue(f.getPrice());
    ins.addBindValue(f.getAdded().toString("yyyy-MM-dd hh:mm:ss"));
    ins.addBindValue(f.getQuantity());
    ins.addBindValue(f.getAvailable());
    ins.addBindValue(f.getLastRentedTo());
    QCOMPARE(ins.exec(), true);
    db.commit();
    std::cout << "Inserted row into filmrent table" << std::endl;
}

void videoStoreTest::test_filmsale(void) {
    FilmSale f = FilmSale(Film("Manhattan", "Woody Allen", 1979, 7.99), 12);
    QCOMPARE(f.getTitle().toStdString(), "Manhattan");
    QCOMPARE(f.getDirector().toStdString(), "Woody Allen");
    QCOMPARE(f.getYear(), (unsigned int)1979);
    QCOMPARE(f.getPrice(), 7.99);
    QCOMPARE(f.getQuantity(), 12);

    QSqlQuery ins;
    ins.prepare("INSERT INTO `filmsale` (`id`, `title`, `director`, `year`, `price`, `added`, `quantity`, `lastSoldTo`, `lastSold`) VALUES (1, ?, ?, ?, ?, ?, ?, ?, NULL)");
    ins.addBindValue(f.getTitle());
    ins.addBindValue(f.getDirector());
    ins.addBindValue(f.getYear());
    ins.addBindValue(f.getPrice());
    ins.addBindValue(f.getAdded().toString("yyyy-MM-dd hh:mm:ss"));
    ins.addBindValue(f.getQuantity());
    ins.addBindValue(f.getLastSoldTo());
    QCOMPARE(ins.exec(), true);
    db.commit();
    std::cout << "Inserted row into filmsale table" << std::endl;
}

void videoStoreTest::test_selectrent(void) {
    QSqlQuery sel;
    sel.prepare("SELECT * FROM `filmrent` WHERE `id`=? LIMIT 1");
    sel.addBindValue(1);
    QCOMPARE(sel.exec(), true);
    QCOMPARE(sel.next(), true);
    QCOMPARE(sel.value(0).toInt(), 1);
    QCOMPARE(sel.value(1).toString().toStdString().c_str(), "Kings of the Road");
    QCOMPARE(sel.value(2).toString().toStdString().c_str(), "Wim Wenders");
    QCOMPARE(sel.value(3).toInt(), 1976);
    QCOMPARE(sel.value(4).toDouble(), 5.99);
    QCOMPARE(sel.value(6).toInt(), 10);
    std::cout << "Selected film from filmrent" << std::endl;
}

void videoStoreTest::test_selectsale(void) {
    QSqlQuery sel;
    sel.prepare("SELECT * FROM `filmsale` WHERE `id`=? LIMIT 1");
    sel.addBindValue(1);
    QCOMPARE(sel.exec(), true);
    QCOMPARE(sel.next(), true);
    QCOMPARE(sel.value(0).toInt(), 1);
    QCOMPARE(sel.value(1).toString().toStdString().c_str(), "Manhattan");
    QCOMPARE(sel.value(2).toString().toStdString().c_str(), "Woody Allen");
    QCOMPARE(sel.value(3).toInt(), 1979);
    QCOMPARE(sel.value(4).toDouble(), 7.99);
    QCOMPARE(sel.value(6).toInt(), 12);
    std::cout << "Selected film from filmsale" << std::endl;
}

QTEST_MAIN(videoStoreTest)

#include "tst_videostoretest.moc"
