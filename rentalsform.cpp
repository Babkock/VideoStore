#include "rentalsform.h"
#include "ui_rentalsform.h"

RentalsForm::RentalsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RentalsForm) {
    ui->setupUi(this);
}

RentalsForm::~RentalsForm(void) {
    delete ui;
}

/* the "Title of Film" field text has been changed */
void RentalsForm::on_rentFormTitleField_textChanged(const QString &arg1) {

}

/* the "Director of Film" field text has been changed */
void RentalsForm::on_rentFormDirectorField_textChanged(const QString &arg1) {

}

/* the "Year" field value has been changed */
void RentalsForm::on_rentFormYearField_valueChanged(int arg1) {

}

/* the "Price" field value has been changed */
void RentalsForm::on_rentFormPriceField_valueChanged(double arg1) {

}

/* the "Save Changes" button has been clicked */
void RentalsForm::on_rentFormSaveChangesButton_clicked(void) {

}

/* the "Discard Changes" button has been clicked */
void RentalsForm::on_rentFormDiscardChangesButton_clicked(void) {

}

