/*
 * mainwindow.cpp
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
#include "film.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "purchaseswindow.h"
#include "rentalswindow.h"
#include "shoppingcart.h"
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

    rentals = new RentalsWindow(/* new RentalsForm(Film("Title", "Director", 1950, 4.99)) */);
    purchases = new PurchasesWindow(/* new PurchasesForm(Film("Title", "Director", 1950, 4.99)) */);
    sc = new ShoppingCart((ShoppingCartItem){ .rental = true, .id = 0, .quantity = 0, .price = 0.99, .title = "Test", .director = "Director" });
    connect(rentals, SIGNAL(closing()), this, SLOT(show()));
    connect(purchases, SIGNAL(closing()), this, SLOT(show()));
    connect(sc, SIGNAL(closing()), this, SLOT(show()));

    QSqlQuery sel1, sel2, sel3, sel4;
    sel1.prepare("SELECT COUNT(*) FROM `filmrent`");
    if (!(sel1.exec()))
        std::cerr << "Error while counting filmrent: " << sel1.lastError().text().toStdString() << std::endl;
    else {
        sel1.next();
        std::cout << "Rows in filmrent: " << sel1.value(0).toInt() << std::endl;
    }

    sel2.prepare("SELECT COUNT(*) FROM `filmsale`");
    if (!(sel2.exec()))
        std::cerr << "Error while counting filmsale: " << sel2.lastError().text().toStdString() << std::endl;
    else {
        sel2.next();
        std::cout << "Rows in filmsale: " << sel2.value(0).toInt() << std::endl;
        ui->totalFilmsField->setValue(sel1.value(0).toInt() + sel2.value(0).toInt());
    }

    sel3.prepare("SELECT COUNT(*) FROM `transactions`");
    if (!(sel3.exec())) {
        std::cerr << "Could not count transactions" << std::endl;
    } else {
        sel3.next();
        int trans = sel3.value(0).toInt();
        sel4.prepare("SELECT `cashRegister`, `profits` FROM `transactions` WHERE `id`=?");
        sel4.addBindValue(trans);
        if (!(sel4.exec())) {
            std::cerr << "Could not select transaction #" << trans << std::endl;
            cashRegister = 50.0;
            profits = 0.0;
        } else {
            sel4.next();
            cashRegister = sel4.value(0).toDouble();
            profits = sel4.value(1).toDouble();
        }
        ui->cashRegisterField->setValue(cashRegister);
        ui->profitsField->setValue(profits);
    }
}

MainWindow::~MainWindow(void) {
    delete ui;
}

/* user clicked "Rentals" button from top menu */
void MainWindow::on_buttonRentals_clicked(void) {
    if (debugMode)
        std::cout << "Rentals" << std::endl;
    hide();
    rentals->show();
}

/* user clicked "Purchases" button from top menu */
void MainWindow::on_buttonPurchases_clicked(void) {
    if (debugMode)
        std::cout << "Purchases" << std::endl;
    hide();
    purchases->show();
}

/* user clicked "Check Out Films" from top menu */
void MainWindow::on_buttonCheckOut_clicked(void) {
    if (debugMode)
        std::cout << "Shopping Cart" << std::endl;
    hide();
    sc->show();
}

/* user clicked "Reset Database" from top menu */
void MainWindow::on_buttonReset_clicked(void) {
    std::cout << "Resetting database" << std::endl;
    dbReset();
}

/* user toggled "Print Debug Messages" on top menu */
void MainWindow::on_checkDebug_toggled(bool checked) {
    std::cout << "Debug messages " << ((checked) ? "enabled" : "disabled") << std::endl;
    debugMode = checked;
}
