/* shoppingcart.cpp
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
#include <vector>
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

ShoppingCart::ShoppingCart(ShoppingCartItem c):
    ui(new Ui::ShoppingCart),
    customerName(""), id(0), quantity(0) {
    ui->setupUi(this);
    cart.push_back(c);
}

ShoppingCart::~ShoppingCart(void) {
    //delete cart;
    delete ui;
}

void ShoppingCart::closeEvent(QCloseEvent *event) {
    emit closing();
    event->accept();
}

void ShoppingCart::push(ShoppingCartItem c) {
    cart.push_back(c);
    int rows = ui->shoppingCartTable->rowCount();
    char col[10], title[150], p[7];
    sprintf(col, "%s #%d", ((c.rental) ? "Rental" : "Purchase"), c.id);
    sprintf(title, "%s", c.title.toStdString().c_str());
    sprintf(p, "$%.2f", c.price);
    ui->shoppingCartTable->setItem(rows-1, 0, new QTableWidgetItem(col));
    ui->shoppingCartTable->setItem(rows-1, 1, new QTableWidgetItem(title));
    ui->shoppingCartTable->setItem(rows-1, 2, new QTableWidgetItem(p));
    ui->shoppingCartTable->setItem(rows-1, 3, new QTableWidgetItem("" + c.quantity));
    ui->shoppingCartTable->setRowCount(rows++);
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
    if (ui->shoppingCartRentalRadio->isDown())
        rental = true;
    else if (ui->shoppingCartPurchaseRadio->isDown())
        rental = false;

    if (qid == 0 || quant == 0)
        return;
    else {
        QSqlQuery sel;
        sel.prepare(((rental) ? "SELECT `title`, `director`, `price`, `quantity` FROM `filmrent` WHERE `id`=?" : "SELECT `title`, `director`, `price`, `available` FROM `filmsale` WHERE `id`=?"));
        sel.addBindValue(qid);
        if (!(sel.exec())) {
            std::cerr << sel.lastError().nativeErrorCode().toStdString() << " Error during select: " << sel.lastError().text().toStdString() << std::endl;
            return;
        }
        if (sel.first()) {
            if (quant > sel.value(3).toInt()) {
                std::cerr << "Not that many copies available" << std::endl;
                quant = sel.value(3).toInt();
            }
            else if (sel.value(3).toInt() == 0) {
                std::cerr << "No copies of that left" << std::endl;
            }
            else {
                cart.push_back((ShoppingCartItem){ .rental = rental, .id = (unsigned int)qid, .quantity = quant, .price = sel.value(2).toDouble(), .title = sel.value(0).toString() });
                int rows = ui->shoppingCartTable->rowCount();
                char col[10], title[150], p[7];
                sprintf(col, "%s #%d", ((rental) ? "Rental" : "Purchase"), qid);
                sprintf(title, "%s by %s", sel.value(0).toString().toStdString().c_str(), sel.value(1).toString().toStdString().c_str());
                sprintf(p, "$%.2f", sel.value(2).toDouble());
                ui->shoppingCartTable->setItem(rows-1, 0, new QTableWidgetItem(col));
                ui->shoppingCartTable->setItem(rows-1, 1, new QTableWidgetItem(title));
                ui->shoppingCartTable->setItem(rows-1, 2, new QTableWidgetItem(p));
                ui->shoppingCartTable->setItem(rows-1, 3, new QTableWidgetItem("" + quant));
                ui->shoppingCartSubTotalField->setValue(ui->shoppingCartSubTotalField->text().toDouble() + sel.value(2).toDouble());
                ui->shoppingCartTotalField->setValue(ui->shoppingCartSubTotalField->text().toDouble());
                ui->shoppingCartTable->setRowCount(rows++);
                ui->shoppingCartEmptyCart->setEnabled(true);
                ui->shoppingCartRemoveLast->setEnabled(true);
                ui->shoppingCartConfirm->setEnabled(true);
            }
        } else {
            std::cerr << "No film with ID " << qid << std::endl;
        }
    }
}

/* the value of the "ID:" field was changed */
void ShoppingCart::on_shoppingCartIdField_valueChanged(int arg1) {
    id = (unsigned int)arg1;
    ui->shoppingCartAddToCart->setEnabled(true);
}

/* the value of the "Quantity" field was changed */
void ShoppingCart::on_shoppingCartQuantityField_valueChanged(int arg1) {
    quantity = (unsigned int)arg1;
    ui->shoppingCartAddToCart->setEnabled(true);
}

/* user clicked the "Remove Last Item from Cart" button */
void ShoppingCart::on_shoppingCartRemoveLast_clicked(void) {

}

/* user clicked the "Empty the Cart" button */
void ShoppingCart::on_shoppingCartEmptyCart_clicked(void) {

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

}

