/* shoppingcart.cpp
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
#include "main.h"
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

ShoppingCart::~ShoppingCart(void) {
    delete ui;
}
