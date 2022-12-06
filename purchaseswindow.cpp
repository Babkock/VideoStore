/* purchaseswindow.cpp
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
#include "main.h"
#include "rentalswindow.h"
#include "purchaseswindow.h"
#include "ui_purchaseswindow.h"
#include "purchasesform.h"
#include "ui_purchasesform.h"
#include <iostream>

PurchasesWindow::PurchasesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PurchasesWindow),
    query((QString)"Title of Film Here"),
    id(0) {
    ui->setupUi(this);
}

PurchasesWindow::PurchasesWindow(QWidget *parent, QMainWindow *form) :
    QMainWindow(parent),
    ui(new Ui::PurchasesWindow),
    form(form),
    query(QString("Title of Film Here")),
    id(0) {
    ui->setupUi(this);
}

PurchasesWindow::~PurchasesWindow(void) {
    delete form;
    delete ui;
}

void PurchasesWindow::closeEvent(QCloseEvent *event) {
    emit closing();
    event->accept();
}

/* user clicked "Add Film for Purchase" from Purchases window */
void PurchasesWindow::on_purchaseAddNew_clicked(void) {
    /* bring up empty PurchasesForm */
    form = new PurchasesForm();
    form->show();
    if (debugMode)
        std::cout << "Add new Film for Purchase was clicked" << std::endl;
}

/* Whenever the text for the "Title of Film" field on Purchases is changed */
void PurchasesWindow::on_purchaseTitleField_textChanged(const QString &arg1) {
    if (debugMode)
        std::cout << "Text was changed: " << arg1.toStdString() << std::endl;
}

/* user pressed Return after editing "Title of Film" box from Purchases
 * This should do the same thing as on_purchaseEdit_clicked() */
void PurchasesWindow::on_purchaseTitleField_returnPressed(void) {
    /* do nothing if the text box is empty */

    /* else, query the database */

    /* if not found, do nothing */

    /* else, bring up the RentalsForm with the found data */
}

/* user clicked "Find Film to Edit" button from Purchases */
void PurchasesWindow::on_purchaseEdit_clicked(void) {
    /* do nothing if the text box is empty */

    /* else, query the database */

    /* if not found, do nothing */

    /* else, bring up the RentalsForm with the found data */
}

/* user clicked "Return" button from Purchases */
void PurchasesWindow::on_purchaseReturn_clicked(void) {
    emit closing();
    this->close();
}

QString PurchasesWindow::getQuery(void) {
    return query;
}

void PurchasesWindow::setQuery(QString q) {
    query = q;
}

unsigned int PurchasesWindow::getId(void) {
    return id;
}

void PurchasesWindow::setId(unsigned int i) {
    id = i;
}

/* the value of "or by ID:" field on Purchases was changed */
void PurchasesWindow::on_purchaseIdField_valueChanged(int arg1) {
    id = (unsigned int)arg1;
    if (debugMode)
        std::cout << "Value was changed: " << arg1 << std::endl;
}

/* Whenever the text in the "Title of Film" field is edited */
void PurchasesWindow::on_purchaseTitleField_textEdited(const QString &arg1) {
    query = arg1;
    if (debugMode)
        std::cout << "Text was edited: " << arg1.toStdString() << std::endl;
}

/* user is finished editing the "or by ID:" field on Purchases */
void PurchasesWindow::on_purchaseIdField_editingFinished(void) {

}

