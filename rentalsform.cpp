/* rentalsform.cpp
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
#include "film.h"
#include "rentalsform.h"
#include "ui_rentalsform.h"
#include "rentalswindow.h"
#include "ui_rentalswindow.h"
#include <iostream>

RentalsForm::RentalsForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RentalsForm) {
    ui->setupUi(this);
    ui->rentalsHeaderText->setText("This Has Been Changed");
}

RentalsForm::RentalsForm(Film f) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(f.getTitle(), f.getDirector(), f.getYear(), f.getPrice()))) {
    ui->setupUi(this);
    ui->rentalsHeaderText->setText("This Has Been Changed");
}

RentalsForm::RentalsForm(Film f, unsigned int q) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(f.getTitle(), f.getDirector(), f.getYear(), f.getPrice()), q)) {
    ui->setupUi(this);
}

RentalsForm::RentalsForm(Film f, unsigned int q, unsigned int a) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(f.getTitle(), f.getDirector(), f.getYear(), f.getPrice()), q, a)) {
    ui->setupUi(this);
}

RentalsForm::RentalsForm(Film f, const char *l) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(f.getTitle(), f.getDirector(), f.getYear(), f.getPrice()), l)) {
    ui->setupUi(this);
}

RentalsForm::RentalsForm(Film f, const QString &l) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(f.getTitle(), f.getDirector(), f.getYear(), f.getPrice()), l)) {
    ui->setupUi(this);
}

RentalsForm::RentalsForm(Film f, QDateTime l) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(f.getTitle(), f.getDirector(), f.getYear(), f.getPrice()), l)) {
    ui->setupUi(this);
}

RentalsForm::RentalsForm(const QString &t) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(t, "Director"))) {
    ui->setupUi(this);
}

RentalsForm::RentalsForm(const QString &t, const QString &d) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(t, d))) {
    ui->setupUi(this);
}

RentalsForm::RentalsForm(const QString &t, unsigned int y) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(t, "Director", y))) {
    ui->setupUi(this);
}

RentalsForm::RentalsForm(const QString &t, const QString &d, unsigned int y) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(t, d, y))) {
    ui->setupUi(this);
}

RentalsForm::RentalsForm(const QString &t, unsigned int y, double p) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(t, "Director", y, p))) {
    ui->setupUi(this);
}

RentalsForm::~RentalsForm(void) {
    delete ui;
}

void RentalsForm::closeEvent(QCloseEvent *event) {
    emit closing();
    event->accept();
    close();
    QMainWindow *p = (QMainWindow *)this->parent();
    p->close();
}

/* user changed text of "Title of Film" field */
void RentalsForm::on_rentalsTitleField_textChanged(const QString &arg1) {
    film.setTitle(arg1);
    std::cout << "Title changed: " << arg1.toStdString() << std::endl;
}

/* user changed text of "Director of Film" field */
void RentalsForm::on_rentalsDirectorField_textChanged(const QString &arg1) {
    film.setDirector(arg1);
    std::cout << "Director changed: " << arg1.toStdString() << std::endl;
}

/* user changed value of "Price in $:" field */
void RentalsForm::on_rentalsPriceField_valueChanged(double arg1) {
    film.setPrice(arg1);
    std::cout << "Price changed: " << arg1 << std::endl;
}

/* user changed value of "Year" field */
void RentalsForm::on_rentalsYearField_valueChanged(int arg1) {
    film.setYear((unsigned int)arg1);
    std::cout << "Year changed: " << arg1 << std::endl;
}

/* user changed value of "Quantity" field */
void RentalsForm::on_rentalsQuantityField_valueChanged(int arg1) {
    film.setQuantity((unsigned int)arg1);
    std::cout << "Quantity changed: " << arg1 << std::endl;
}

/* user changed value of "Available" field */
void RentalsForm::on_rentalsAvailableField_valueChanged(int arg1) {
    film.setAvailable((unsigned int)arg1);
    std::cout << "Available changed: " << arg1 << std::endl;
}

/* user selected a date for "Last Rented" field */
void RentalsForm::on_rentalsLastRentedField_dateTimeChanged(const QDateTime &dateTime) {
    film.setLastRented(dateTime);
    std::cout << "Set last rented" << std::endl;
}

/* user changed text of "Last Rented to" field */
void RentalsForm::on_rentalsLastRentedTo_textChanged(const QString &arg1) {
    film.setLastRentedTo(arg1);
    std::cout << "Last Rented to changed: " << arg1.toStdString() << std::endl;
}

/* user clicked on "Save Changes to Film" button */
void RentalsForm::on_rentalsSaveChanges_clicked(void) {
    std::cout << "Changes saved" << std::endl;
}

/* user clicked on "Discard Changes" button */
void RentalsForm::on_rentalsDiscardChanges_clicked(void) {
    emit closing();
    this->hide();
}

/* user pressed Return after editing "Title of Film" field */
void RentalsForm::on_rentalsTitleField_returnPressed(void) {
    std::cout << "Pressed Return on Title" << std::endl;
}

/* user pressed Return after editing "Director of Film" field */
void RentalsForm::on_rentalsDirectorField_returnPressed(void) {
    std::cout << "Pressed Return on Director" << std::endl;
}

