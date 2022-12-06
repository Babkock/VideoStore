/* shoppingcart.cpp
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
#include "database.h"
#include "film.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shoppingcart.h"
#include "ui_shoppingcart.h"
#include <iostream>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QThread>

ShoppingCart::ShoppingCart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShoppingCart) {
    ui->setupUi(this);
}

ShoppingCart::ShoppingCart(void) :
    ui(new Ui::ShoppingCart),
    customerName(""), id(0), quantity(0) {
    ui->setupUi(this);
}

ShoppingCart::ShoppingCart(ShoppingCartItem_t *c):
    ui(new Ui::ShoppingCart),
    cart(c), customerName(""), id(0), quantity(0) {
    ui->setupUi(this);
}

ShoppingCart::~ShoppingCart(void) {
    delete cart;
    delete ui;
}

void ShoppingCart::closeEvent(QCloseEvent *event) {
    emit closing();
    event->accept();
}

void ShoppingCart::on_shoppingCartCancel_clicked(void) {
    emit closing();
    hide();
}

