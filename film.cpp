/* film.cpp
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
#include <iostream>
#include <QDate>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include "film.h"

Film::Film(QObject *parent)
    : QObject{parent}, title(""), director(""), year(0), price(0.0) {
    added = QDateTime::currentDateTime();
}

FilmRent::FilmRent(Film f) {
    setTitle(f.getTitle());
    setDirector(f.getDirector());
    setYear(f.getYear());
    setPrice(f.getPrice());
    setAdded(QDateTime::currentDateTime());
}

Film::Film(const char *t, const char *d, unsigned int y, double p)
    : title(QString(t)), director(QString(d)), year(y), price(p) {
    added = QDateTime::currentDateTime();
}

Film::Film(const QString &t, const QString &d)
    : title(t), director(d), year(0), price(0.0) {
    added = QDateTime::currentDateTime();
}

Film::Film(const char *t, const char *d)
    : title(QString(t)), director(QString(d)), year(0), price(0.0) {
    added = QDateTime::currentDateTime();
}

Film::Film(const QString &t, const QString &d, unsigned int y)
    : title(t), director(d), year(y), price(0.0) {
    added = QDateTime::currentDateTime();
}

Film::Film(const char *t, const char *d, unsigned int y)
    : title(QString(t)), director(QString(d)), year(y), price(0.0) {
    added = QDateTime::currentDateTime();
}

Film::Film(const QString &t, const QString &d, unsigned int y, double p)
    : title(t), director(d), year(y), price(p) {
    added = QDateTime::currentDateTime();
}

QString Film::getTitle(void) {
    return title;
}

void Film::setTitle(const QString &t) {
    title = t;
}

void Film::setTitle(const char *t) {
    title = QString(t);
}

QString Film::getDirector(void) {
    return director;
}

void Film::setDirector(const QString &d) {
    director = d;
}

void Film::setDirector(const char *d) {
    director = QString(d);
}

unsigned int Film::getYear(void) {
    return year;
}

void Film::setYear(unsigned int y) {
    year = y;
}

double Film::getPrice(void) {
    return price;
}

void Film::setPrice(double p) {
    price = p;
}

QDateTime Film::getAdded(void) {
    return added;
}

void Film::setAdded(QDateTime a) {
    added = a;
}

void FilmRent::print(void) {
    std::cout << "Title: " << getTitle().toStdString() << std::endl;
    std::cout << "Director: " << getDirector().toStdString() << std::endl;
    std::cout << "Year: " << getYear() << std::endl;
    std::cout << "Price: $" << getPrice() << std::endl;
    std::cout << "Quantity: " << quantity << std::endl;
    std::cout << "Available: " << available << std::endl;
    std::cout << "Last Rented to: " << lastRentedTo.toStdString() << std::endl;
}
