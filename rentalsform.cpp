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
}

RentalsForm::RentalsForm(Film f) :
//    QMainWindow(parent),
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(f.getTitle(), f.getDirector(), f.getYear(), f.getPrice()))) {
    ui->setupUi(this);
}

RentalsForm::RentalsForm(Film f, unsigned int q) :
//    QMainWindow(parent),
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(f.getTitle(), f.getDirector(), f.getYear(), f.getPrice()), q)) {
    ui->setupUi(this);
}

RentalsForm::RentalsForm(Film f, unsigned int q, unsigned int a) :
//    QMainWindow(parent),
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(f.getTitle(), f.getDirector(), f.getYear(), f.getPrice()), q, a)) {
    ui->setupUi(this);
}

RentalsForm::RentalsForm(Film f, const char *l) :
//    QMainWindow(parent),
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(f.getTitle(), f.getDirector(), f.getYear(), f.getPrice()), l)) {
    ui->setupUi(this);
}

RentalsForm::RentalsForm(Film f, const QString &l) :
//    QMainWindow(parent),
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(f.getTitle(), f.getDirector(), f.getYear(), f.getPrice()), l)) {
    ui->setupUi(this);
}

RentalsForm::RentalsForm(Film f, QDateTime l) :
//    QMainWindow(parent),
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(f.getTitle(), f.getDirector(), f.getYear(), f.getPrice()), l)) {
    ui->setupUi(this);
}

RentalsForm::RentalsForm(const QString &t) :
//    QMainWindow(parent),
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(t, "Director"))) {
    ui->setupUi(this);
}

RentalsForm::RentalsForm(const QString &t, const QString &d) :
//    QMainWindow(parent),
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(t, d))) {
    ui->setupUi(this);
}

RentalsForm::RentalsForm(const QString &t, unsigned int y) :
//    QMainWindow(parent),
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(t, "Director", y))) {
    ui->setupUi(this);
}

RentalsForm::RentalsForm(const QString &t, const QString &d, unsigned int y) :
//    QMainWindow(parent),
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(t, d, y))) {
    ui->setupUi(this);
}

RentalsForm::RentalsForm(const QString &t, unsigned int y, double p) :
//    QMainWindow(parent),
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
