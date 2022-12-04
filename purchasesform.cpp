/* purchasesform.cpp
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
#include "main.h"
#include "film.h"
#include <iostream>
#include "purchasesform.h"
#include "ui_purchasesform.h"
#include "purchaseswindow.h"
#include "ui_purchaseswindow.h"

PurchasesForm::PurchasesForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PurchasesForm) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Inventory");
    ui->purchasesHeaderText->setText("Adding New Film to Inventory");
}

PurchasesForm::~PurchasesForm(void) {
    delete ui;
}

void PurchasesForm::closeEvent(QCloseEvent *event) {
    emit closing();
    event->accept();
}

bool PurchasesForm::getEditExisting(void) {
    return editExisting;
}

void PurchasesForm::setEditExisting(bool e) {
    editExisting = e;
}

/* user clicked on the "Save Changes to Film" button on Purchases */
void PurchasesForm::on_purchasesSaveChanges_clicked(void) {

}

/* user clicked on "Discard Changes" button on Purchases */
void PurchasesForm::on_purchasesDiscardChanges_clicked(void) {
    emit closing();
    this->hide();
}

/* the text of the "Title of Film" field was changed */
void PurchasesForm::on_purchasesTitleField_textChanged(const QString &arg1) {
    film.setTitle(arg1);
    this->ui->purchasesSaveChanges->setEnabled(true);
    if (debugMode)
        std::cout << "Title changed: " << arg1.toStdString() << std::endl;
}

/* the text of the "Director of Film" field was changed */
void PurchasesForm::on_purchasesDirectorField_textChanged(const QString &arg1) {
    film.setDirector(arg1);
    this->ui->purchasesSaveChanges->setEnabled(true);
    if (debugMode)
        std::cout << "Director changed: " << arg1.toStdString() << std::endl;
}

/* the value of "Year" input field was changed */
void PurchasesForm::on_purchasesYearField_valueChanged(int arg1) {
    film.setYear(arg1);
    this->ui->purchasesSaveChanges->setEnabled(true);
    if (debugMode)
        std::cout << "Year changed: " << arg1 << std::endl;
}

/* the value of "Price" input field was changed */
void PurchasesForm::on_purchasesPriceField_valueChanged(double arg1) {
    film.setPrice(arg1);
    this->ui->purchasesSaveChanges->setEnabled(true);
    if (debugMode)
        std::cout << "Price changed: $" << arg1 << std::endl;
}

