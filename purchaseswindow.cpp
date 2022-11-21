/* purchaseswindow.cpp
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
#include "purchaseswindow.h"
#include "rentalswindow.h"
#include "ui_purchaseswindow.h"

PurchasesWindow::PurchasesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PurchasesWindow) {
    ui->setupUi(this);
}

PurchasesWindow::~PurchasesWindow(void) {
    delete ui;
}

void PurchasesWindow::closeEvent(QCloseEvent *event) {
    emit closing();
    event->accept();
}

/* user clicked "Add Film for Purchase" from Purchases window */
void PurchasesWindow::on_purchaseAddNew_clicked(void) {
    /* bring up empty PurchasesForm */
}

/* Whenever the text for the "Title of Film" box is changed */
void PurchasesWindow::on_purchaseFilmTitle_textChanged(const QString &arg1) {
    query = arg1;
}

/* user pressed Return after editing "Title of Film" box from Purchases
 * This should do the same thing as on_purchaseEdit_clicked() */
void PurchasesWindow::on_purchaseFilmTitle_returnPressed(void) {
    /* do nothing if the text box is empty */

    /* else, query the database */

    /* if not found, do nothing */

    /* else, bring up the RentalsForm with the found data */
}

/* user clicked "Edit Film" button from Purchases */
void PurchasesWindow::on_purchaseEdit_clicked(void) {
    /* do nothing if the text box is empty */

    /* else, query the database */

    /* if not found, do nothing */

    /* else, bring up the RentalsForm with the found data */
}

/* user clicked "Return" button from Purchases */
void PurchasesWindow::on_purchaseReturn_clicked(void) {

}

bool PurchasesWindow::getDebugMode(void) {
    return debugMode;
}

void PurchasesWindow::setDebugMode(bool d) {
    debugMode = d;
}

QString PurchasesWindow::getQuery(void) {
    return query;
}

void PurchasesWindow::setQuery(QString q) {
    query = q;
}
