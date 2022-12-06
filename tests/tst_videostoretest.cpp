#include "film.h"
#include "database.h"
#include "mainwindow.h"
#include "shoppingcart.h"
#include <iostream>
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
    void test_case1(void);

};

videoStoreTest::videoStoreTest(void) {

}

videoStoreTest::~videoStoreTest(void) {

}

void videoStoreTest::initTestCase(void) {
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
}

void videoStoreTest::cleanupTestCase(void) {
    QCOMPARE(5, 6);
}

void videoStoreTest::test_case1(void) {

}

QTEST_MAIN(videoStoreTest)

#include "tst_videostoretest.moc"
