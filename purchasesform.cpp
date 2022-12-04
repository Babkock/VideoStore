/* purchasesform.cpp
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
#include "main.h"
#include "film.h"
#include "purchasesform.h"
#include "ui_purchasesform.h"
#include "purchaseswindow.h"
#include "ui_purchaseswindow.h"

PurchasesForm::PurchasesForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PurchasesForm) {
    ui->setupUi(this);
    ui->purchasesHeaderText->setText("Adding New Film to Inventory");
}

PurchasesForm::~PurchasesForm(void) {
    delete ui;
}

void PurchasesForm::closeEvent(QCloseEvent *event) {
    emit closing();
    event->accept();
}

/* user clicked on the "Save Changes to Film" button on Purchases */
void PurchasesForm::on_purchasesSaveChanges_clicked(void) {

}

/* user clicked on "Discard Changes" button on Purchases */
void PurchasesForm::on_purchasesDiscardChanges_clicked(void) {

}

/* the text of the "Title of Film" field was changed */
void PurchasesForm::on_purchasesTitleField_textChanged(const QString &arg1) {

}

/* the text of the "Director of Film" field was changed */
void PurchasesForm::on_purchasesDirectorField_textChanged(const QString &arg1) {

}

