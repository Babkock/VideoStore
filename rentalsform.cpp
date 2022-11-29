#include "rentalsform.h"
#include "ui_rentalsform.h"
#include <iostream>
#include <cstdlib>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

RentalsForm::RentalsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RentalsForm) {
    film = new Film("Title", "Director", 1950, 4.99);
    ui->setupUi(this);
}

RentalsForm::~RentalsForm(void) {
    delete ui;
    delete film;
}

void RentalsForm::setDebugMode(bool d) {
    debugMode = d;
}

bool RentalsForm::getDebugMode(void) {
    return debugMode;
}

void RentalsForm::setNew(bool n) {
    newFilm = n;
}

bool RentalsForm::getNew(void) {
    return newFilm;
}

void RentalsForm::setFilm(const Film &f) {
    film->setTitle(f.getTitle());
    film->setDirector(f.getDirector());
    film->setYear(f.getYear());
    film->setPrice(f.getPrice());
    film->setAdded(f.getAdded());
}

Film *RentalsForm::getFilm(void) {
    return new Film(film->getTitle(), film->getDirector(), film->getYear(), film->getPrice());
}

void RentalsForm::setQuantity(int q) {
    quantity = q;
}

int RentalsForm::getQuantity(void) {
    return quantity;
}

void RentalsForm::setAvailable(int a) {
    available = a;
}

int RentalsForm::getAvailable(void) {
    return available;
}

QString RentalsForm::getLastRentedTo(void) {
    return lastRentedTo;
}

void RentalsForm::setLastRentedTo(const char *l) {
    lastRentedTo = QString(l);
}

/* the "Title of Film" field text has been changed */
void RentalsForm::on_rentFormTitleField_textChanged(const QString &arg1) {
    film->setTitle(arg1);
    if (debugMode)
        std::cout << "set film's title to " << arg1 << std::endl;
}

/* the "Director of Film" field text has been changed */
void RentalsForm::on_rentFormDirectorField_textChanged(const QString &arg1) {
    film->setDirector(arg1);
    if (debugMode)
        std::cout << "set film's director to " << arg1 << std::endl;
}

/* the "Year" field value has been changed */
void RentalsForm::on_rentFormYearField_valueChanged(int arg1) {
    film->setYear(arg1);
    if (debugMode)
        std::cout << "set film's year to " << arg1 << std::endl;
}

/* the "Price" field value has been changed */
void RentalsForm::on_rentFormPriceField_valueChanged(double arg1) {
    film->setPrice(arg1);
    if (debugMode)
        std::cout << "set film's price to " << arg1 << std::endl;
}

/* the "Save Changes" button has been clicked */
void RentalsForm::on_rentFormSaveChangesButton_clicked(void) {
    if (debugMode) {
        std::cout << "saving film's changes" << std::endl;
        film->print();
    }
}

/* the "Discard Changes" button has been clicked */
void RentalsForm::on_rentFormDiscardChangesButton_clicked(void) {
    emit closing();
    this->close();
}

/* user pressed Return after editing "Title of Film" field */
void RentalsForm::on_rentFormTitleField_returnPressed(void) {

}

/* user pressed Return after editing "Director of Film" field */
void RentalsForm::on_rentFormDirectorField_returnPressed(void) {

}

/* the "Date Added" date has been picked */
void RentalsForm::on_rentFormAddedField_dateTimeChanged(const QDateTime &dateTime) {
    film->setAdded(dateTime);
    if (debugMode)
        std::cout << "set film's date added" << std::endl;
}

/* the "Quantity" meter was changed */
void RentalsForm::on_rentFormQuantity_valueChanged(int arg1) {
    quantity = arg1;
    if (debugMode)
        std::cout << "set rental's quantity to " << arg1 << std::endl;
}

/* the "Available" meter was changed */
void RentalsForm::on_rentFormAvailable_valueChanged(int arg1) {
    available = arg1;
    if (debugMode)
        std::cout << "set rental's available to " << arg1 << std::endl;
}

/* the "Last Rented to" field text was changed */
void RentalsForm::on_rentFormLastRentedTo_textChanged(const QString &arg1) {
    lastRentedTo = arg1;
    if (debugMode)
        std::cout << "set rental's last rented to to " << arg1 << std::endl;
}

/* user pressed Return after editing "Last Rented to" */
void RentalsForm::on_rentFormLastRentedTo_returnPressed(void) {

}
