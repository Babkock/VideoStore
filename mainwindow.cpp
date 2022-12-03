/* mainwindow.cpp
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
#include "mainwindow.h"
#include "purchaseswindow.h"
#include "rentalswindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <cstdlib>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

QSqlDatabase db;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    const QString DRIVER("QSQLITE");
    if (!QSqlDatabase::isDriverAvailable(DRIVER)) {
        std::cerr << "Driver is not available" << std::endl;
        delete ui;
        abort();
    }
    db = QSqlDatabase::addDatabase(DRIVER);
    db.setHostName("videostore");
    db.setDatabaseName("videostore.sql");
    db.setUserName("user");
    db.setPassword("password");
    if (!db.open()) {
        std::cerr << "Could not open database" << std::endl;
        delete ui;
        abort();
    }
    QSqlQuery create, ins1;
    if (!(create.exec((QString)"CREATE TABLE `filmrent` (`id` INTEGER PRIMARY KEY, `title` VARCHAR(110), `director` VARCHAR(80), `year` INTEGER, `price` DOUBLE, `added` DATETIME, `quantity` INT(11), `available` INT(11), `lastRentedTo` VARCHAR(80), `lastRented` DATETIME)"))) {
        if (create.lastError().number() != 1)
            std::cout << create.lastError().number() << " Error from create query: " << create.lastError().text().toStdString() << std::endl;
        else
            std::cout << "Reading filmrent table" << std::endl;
    }
    if (!(ins1.exec("INSERT INTO `filmrent` VALUES(1, 'Persona', 'Ingmar Bergman', 1966, 6.99, NULL, 2, 2, '', NULL)"))) {
        if (ins1.lastError().number() != 19)
            std::cout << ins1.lastError().number() << " Error from ins1 query: " << ins1.lastError().text().toStdString() << std::endl;
    }

    rentals = new RentalsWindow(new RentalsForm(Film("Title", "Director", 1950, 4.99)));
    purchases = new PurchasesWindow(/* new PurchasesForm(Film("Title", "Director", 1950, 4.99)) */);
    connect(rentals, SIGNAL(closing()), this, SLOT(show()));
    connect(purchases, SIGNAL(closing()), this, SLOT(show()));
}

MainWindow::~MainWindow(void) {
    delete purchases;
    delete rentals;
    db.close();
    delete ui;
}

/*
void MainWindow::closeEvent(QCloseEvent *event) {
    emit closing();
    event->accept();
} */

/* user clicked "Rentals" button from top menu */
void MainWindow::on_buttonRentals_clicked(void) {
    hide();
    rentals->show();
}

/* user clicked "Purchases" button from top menu */
void MainWindow::on_buttonPurchases_clicked(void) {
    hide();
    purchases->show();
}

/* user clicked "Check Out Films" from top menu */
void MainWindow::on_buttonCheckOut_clicked(void) {

}

/* user clicked "Reset Database" from top menu */
void MainWindow::on_buttonReset_clicked(void) {

}

/* user toggled "Print Debug Messages" on top menu */
void MainWindow::on_checkDebug_toggled(bool checked) {
    setDebugMode(checked);
}

bool MainWindow::getDebugMode(void) {
    return debugMode;
}

void MainWindow::setDebugMode(bool d) {
    debugMode = d;
}
