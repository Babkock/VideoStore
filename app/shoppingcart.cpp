/*
 * shoppingcart.cpp
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
#include "shoppingcart.h"
#include "ui_shoppingcart.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QThread>

ShoppingCart::ShoppingCart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShoppingCart),
    cart(new std::vector<ShoppingCartItem>) {
    ui->setupUi(this);
    ui->shoppingCartDueField->setDateTime(QDateTime::currentDateTime());
}

ShoppingCart::ShoppingCart(void) :
    ui(new Ui::ShoppingCart),
    cart(new std::vector<ShoppingCartItem>),
    customerName(""), id(0), quantity(0), subtotal(0.0), tax(0.0), total(0.0) {
    ui->setupUi(this);
    ui->shoppingCartDueField->setDateTime(QDateTime::currentDateTime());
}

ShoppingCart::ShoppingCart(ShoppingCartItem c):
    ui(new Ui::ShoppingCart),
    cart(new std::vector<ShoppingCartItem>),
    customerName(""), id(0), quantity(0), subtotal(0.0), tax(0.0), total(0.0) {
    ui->setupUi(this);
    ui->shoppingCartDueField->setDateTime(QDateTime::currentDateTime());
    cart->push_back(c);
}

ShoppingCart::~ShoppingCart(void) {
    delete cart;
    delete ui;
}

void ShoppingCart::closeEvent(QCloseEvent *event) {
    emit closing();
    event->accept();
}

double ShoppingCart::getSubTotal(void) {
    return subtotal;
}

void ShoppingCart::setSubTotal(double s) {
    subtotal = s;
}

double ShoppingCart::getTax(void) {
    return tax;
}

void ShoppingCart::setTax(double t) {
    tax = t;
}

double ShoppingCart::getTotal(void) {
    return total;
}

void ShoppingCart::setTotal(double t) {
    total = t;
}

void ShoppingCart::push(ShoppingCartItem c) {
    cart->push_back(c);
    std::ostringstream str1, str2, str3;
    std::string id, p, q;
    str1 << ((c.rental) ? "Renting" : "Buying") << " #" << c.id;
    id = str1.str();
    str2 << "$" << c.price;
    p = str2.str();
    str3 << c.quantity;
    q = str3.str();

    int rows = ui->shoppingCartTable->rowCount();
    ui->shoppingCartTable->insertRow(rows);
    ui->shoppingCartTable->setItem(rows, 0, new QTableWidgetItem(id.c_str()));
    ui->shoppingCartTable->setItem(rows, 1, new QTableWidgetItem(c.title.toStdString().c_str()));
    ui->shoppingCartTable->setItem(rows, 2, new QTableWidgetItem(c.director.toStdString().c_str()));
    ui->shoppingCartTable->setItem(rows, 3, new QTableWidgetItem(p.c_str()));
    ui->shoppingCartTable->setItem(rows, 4, new QTableWidgetItem(q.c_str()));
}

ShoppingCartItem ShoppingCart::pop(void) {
    if (cart->size() == 0) {
        std::cerr << "Cannot remove any more items" << std::endl;
        return (ShoppingCartItem){ .rental = false, .id = 0, .quantity = 0, .price = 0.0, .title = "Error", .director = "Error" };
    } else {
        ShoppingCartItem back = cart->back();
        cart->pop_back();
        int rows = ui->shoppingCartTable->rowCount();
        ui->shoppingCartTable->setRowCount(rows-1);
        return back;
    }
}

void ShoppingCart::on_shoppingCartCancel_clicked(void) {
    emit closing();
    close();
}

/* user clicked on the "Add to Cart" button */
void ShoppingCart::on_shoppingCartAddToCart_clicked(void) {
    int qid, quant;
    qid = ui->shoppingCartIdField->text().toInt();
    quant = ui->shoppingCartQuantityField->text().toInt();

    if (qid == 0 || quant == 0)
        return;
    else {
        QSqlQuery *sel = new QSqlQuery();
        sel->prepare(((rental) ? "SELECT `title`, `director`, `price`, `available` FROM `filmrent` WHERE `id`=?" : "SELECT `title`, `director`, `price`, `quantity` FROM `filmsale` WHERE `id`=?"));
        sel->addBindValue(qid);
        if (!(sel->exec())) {
            std::cerr << "Error during select: " << sel->lastError().text().toStdString() << std::endl;
            return;
        }
        if (sel->first()) {
            if (quant > sel->value(3).toInt()) {
                std::cerr << "Not that many copies available" << std::endl;
                quant = sel->value(3).toInt();
            }
            else if (sel->value(3).toInt() == 0) {
                std::cerr << "No copies of that left" << std::endl;
            }
            else {
                this->push((ShoppingCartItem){ .rental = rental, .id = (unsigned int)qid, .quantity = quant, .price = sel->value(2).toDouble(), .title = sel->value(0).toString(), .director = sel->value(1).toString() });

                double itemPrice = sel->value(2).toDouble();
                subtotal = (getSubTotal() + (itemPrice * quant));
                tax = (getSubTotal() * 0.06);
                total = getSubTotal() + getTax();
                ui->shoppingCartSubTotalField->setValue(getSubTotal());
                ui->shoppingCartTaxField->setValue(getTax());
                ui->shoppingCartTotalField->setValue(getTotal());
                ui->shoppingCartEmptyCart->setEnabled(true);
                ui->shoppingCartRemoveLast->setEnabled(true);
                ui->shoppingCartConfirm->setEnabled(true);
            }
        } else {
            std::cerr << "No film with ID " << qid << std::endl;
        }
        delete sel;
    }
}

/* the value of the "ID:" field was changed */
void ShoppingCart::on_shoppingCartIdField_valueChanged(int arg1) {
    id = (unsigned int)arg1;
    ui->shoppingCartAddToCart->setEnabled(true);
    if (debugMode)
        std::cout << "ID field changed: " << arg1 << std::endl;
}

/* the value of the "Quantity" field was changed */
void ShoppingCart::on_shoppingCartQuantityField_valueChanged(int arg1) {
    quantity = (unsigned int)arg1;
    ui->shoppingCartAddToCart->setEnabled(true);
    if (debugMode)
        std::cout << "Quantity field changed: " << arg1 << std::endl;
}

/* user clicked the "Remove Last Item from Cart" button */
void ShoppingCart::on_shoppingCartRemoveLast_clicked(void) {
    ShoppingCartItem del = this->pop();
    if (debugMode)
        std::cout << "Removed shopping cart item: " << del.id << ", " << del.title.toStdString() << ", " << del.quantity << ", $" << del.price << std::endl;
    subtotal = (getSubTotal() - (del.quantity * del.price));
    tax = (getSubTotal() * 0.06);
    total = getSubTotal() + getTax();
    ui->shoppingCartSubTotalField->setValue(getSubTotal());
    ui->shoppingCartTaxField->setValue(getTax());
    ui->shoppingCartTotalField->setValue(getTotal());
}

/* user clicked the "Empty the Cart" button */
void ShoppingCart::on_shoppingCartEmptyCart_clicked(void) {
    ui->shoppingCartTable->setRowCount(0);
    cart->clear();
    ui->shoppingCartConfirm->setEnabled(false);
    subtotal = 0.0;
    tax = 0.0;
    total = 0.0;
    ui->shoppingCartSubTotalField->setValue(0.0);
    ui->shoppingCartTaxField->setValue(0.0);
    ui->shoppingCartTotalField->setValue(0.0);
    if (debugMode)
        std::cout << "Cart emptied" << std::endl;
}

/* the text of the "Customer Name" field was changed */
void ShoppingCart::on_shoppingCartCustomerNameField_textChanged(const QString &arg1) {
    customerName = arg1;
    if (debugMode)
        std::cout << "Customer name was set to '" << arg1.toStdString() << "'" << std::endl;
    ui->shoppingCartConfirm->setEnabled(true);
}

/* user selected a date time in the "Due" field */
void ShoppingCart::on_shoppingCartDueField_dateTimeChanged(const QDateTime &dateTime) {
    due = dateTime;
    if (debugMode)
        std::cout << "Customer due date was set to '" << dateTime.toString("yyyy-MM-dd hh:mm:ss").toStdString() << std::endl;
    if (ui->shoppingCartCustomerNameField->text().length() != 0)
        ui->shoppingCartConfirm->setEnabled(true);
}

/* user clicked the "Confirm Order" button */
void ShoppingCart::on_shoppingCartConfirm_clicked(void) {
    if (debugMode)
        std::cout << "Order is being confirmed..." << std::endl;

    double tot = getTotal();
    std::cout << "Total: $" << tot << std::endl;
    cashRegister += tot;
    profits += tot;

    QSqlQuery *ins = new QSqlQuery();
    ins->prepare("INSERT INTO `transactions` VALUES (NULL, ?, ?, ?)");
    ins->addBindValue(cashRegister);
    ins->addBindValue(profits);
    ins->addBindValue(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    if (!(ins->exec()))
        std::cerr << "Error during transaction insert: " << ins->lastError().text().toStdString() << std::endl;

    for (auto item : *cart) {
        bool r = item.rental;
        std::cout << ((r) ? "Renting" : "Buying");
        std::cout << " Cart ID: " << (int)item.id << ": " << item.title.toStdString() << ", $" << item.price << std::endl;

        QSqlQuery update;
        update.prepare(((r) ? "UPDATE `filmrent` SET `lastRented`=?, `lastRentedTo`=?, `available`=available - ? WHERE `id`=?" : "UPDATE `filmsale` SET `lastSold`=?, `lastSoldTo`=?, `quantity`=quantity - ? WHERE `id`=?"));
        update.addBindValue(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        update.addBindValue(customerName);
        update.addBindValue(item.quantity);
        update.addBindValue(item.id);
        if (!(update.exec())) {
            std::cerr << "Updating film " << ((r) ? "rent" : "purchase") << " #" << item.id << " failed: " << update.lastError().text().toStdString() << std::endl;
            break;
        }
    }

    delete ins;
    emit closing();
    close();
}

/* user clicked the "Rental" radio button */
void ShoppingCart::on_shoppingCartRentalRadio_clicked(void) {
    rental = true;
}

/* user clicked the "Purchase" radio button */
void ShoppingCart::on_shoppingCartPurchaseRadio_clicked(void) {
    rental = false;
}
