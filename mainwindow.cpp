/* mainwindow.cpp
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
#include "main.h"
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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    rentals = new RentalsWindow(new RentalsForm(Film("Title", "Director", 1950, 4.99)));
    purchases = new PurchasesWindow(/* new PurchasesForm(Film("Title", "Director", 1950, 4.99)) */);
    connect(rentals, SIGNAL(closing()), this, SLOT(show()));
    connect(purchases, SIGNAL(closing()), this, SLOT(show()));

    QSqlQuery sel1, sel2;
    int total = sel1.prepare("SELECT COUNT(*) FROM `filmrent`");
    sel1.exec();
    std::cout << "Tables in filmrent: " << total << std::endl;

    total += sel2.prepare("SELECT COUNT(*) FROM `filmsale`");
    sel2.exec();
    this->ui->totalFilmsField->setValue(total);
    this->ui->cashRegisterField->setValue(cashRegister);
    this->ui->profitsField->setValue(profits);
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
    /* Open the shopping cart editor */
}

/* user clicked "Reset Database" from top menu */
void MainWindow::on_buttonReset_clicked(void) {
    std::cout << "Resetting database" << std::endl;
    dbReset();
}

/* user toggled "Print Debug Messages" on top menu */
void MainWindow::on_checkDebug_toggled(bool checked) {
    debugMode = checked;
}
