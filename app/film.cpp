/* film.cpp
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

FilmRent::FilmRent(void) {
    setTitle("Title");
    setDirector("Director");
    setYear(1950);
    setPrice(4.99);
    setAdded(QDateTime::currentDateTime());
}

FilmSale::FilmSale(void) {
    setTitle("Title");
    setDirector("Director");
    setYear(1950);
    setPrice(4.99);
    setAdded(QDateTime::currentDateTime());
}

FilmRent::FilmRent(Film f) {
    setId(f.getId());
    setTitle(f.getTitle());
    setDirector(f.getDirector());
    setYear(f.getYear());
    setPrice(f.getPrice());
    setAdded(QDateTime::currentDateTime());
}

FilmSale::FilmSale(Film f) {
    setId(f.getId());
    setTitle(f.getTitle());
    setDirector(f.getDirector());
    setYear(f.getYear());
    setPrice(f.getPrice());
    setAdded(QDateTime::currentDateTime());
}

FilmRent::FilmRent(Film f, unsigned int q):
    quantity(q) {
    setId(f.getId());
    setTitle(f.getTitle());
    setDirector(f.getDirector());
    setYear(f.getYear());
    setPrice(f.getPrice());
    setAdded(QDateTime::currentDateTime());
}

FilmSale::FilmSale(Film f, unsigned int q):
    quantity(q) {
    setId(f.getId());
    setTitle(f.getTitle());
    setDirector(f.getDirector());
    setYear(f.getYear());
    setPrice(f.getPrice());
    setAdded(QDateTime::currentDateTime());
}

FilmRent::FilmRent(Film f, unsigned int q, unsigned int a):
    quantity(q), available(a) {
    setId(f.getId());
    setTitle(f.getTitle());
    setDirector(f.getDirector());
    setYear(f.getYear());
    setPrice(f.getPrice());
    setAdded(QDateTime::currentDateTime());
}

FilmRent::FilmRent(Film f, const char *l):
    lastRentedTo((QString)l) {
    setId(f.getId());
    setTitle(f.getTitle());
    setDirector(f.getDirector());
    setYear(f.getYear());
    setPrice(f.getPrice());
    setAdded(QDateTime::currentDateTime());
}

FilmSale::FilmSale(Film f, const char *l):
    lastSoldTo((QString)l) {
    setId(f.getId());
    setTitle(f.getTitle());
    setDirector(f.getDirector());
    setYear(f.getYear());
    setPrice(f.getPrice());
    setAdded(QDateTime::currentDateTime());
}

FilmRent::FilmRent(Film f, const QString &l):
    lastRentedTo(l) {
    setId(f.getId());
    setTitle(f.getTitle());
    setDirector(f.getDirector());
    setYear(f.getYear());
    setPrice(f.getPrice());
    setAdded(QDateTime::currentDateTime());
}

FilmSale::FilmSale(Film f, const QString &l):
    lastSoldTo(l) {
    setId(f.getId());
    setTitle(f.getTitle());
    setDirector(f.getDirector());
    setYear(f.getYear());
    setPrice(f.getPrice());
    setAdded(QDateTime::currentDateTime());
}

FilmRent::FilmRent(Film f, QDateTime l):
    lastRented(l) {
    setId(f.getId());
    setTitle(f.getTitle());
    setDirector(f.getDirector());
    setYear(f.getYear());
    setPrice(f.getPrice());
    setAdded(QDateTime::currentDateTime());
}

FilmSale::FilmSale(Film f, QDateTime l):
    lastSold(l) {
    setId(f.getId());
    setTitle(f.getTitle());
    setDirector(f.getDirector());
    setYear(f.getYear());
    setPrice(f.getPrice());
    setAdded(QDateTime::currentDateTime());
}

FilmSale::FilmSale(Film f, const char *l, QDateTime a):
    lastSold(a),
    lastSoldTo(QString(l)) {
    setId(f.getId());
    setTitle(f.getTitle());
    setDirector(f.getDirector());
    setYear(f.getYear());
    setPrice(f.getPrice());
    setAdded(QDateTime::currentDateTime());
}

FilmSale::FilmSale(Film f, const QString &l, QDateTime a):
    lastSold(a),
    lastSoldTo(l) {
    setId(f.getId());
    setTitle(f.getTitle());
    setDirector(f.getDirector());
    setYear(f.getYear());
    setPrice(f.getPrice());
    setAdded(QDateTime::currentDateTime());
}

FilmSale::FilmSale(Film f, unsigned int q, const char *l):
    quantity(q),
    lastSoldTo(QString(l)) {
    setId(f.getId());
    setTitle(f.getTitle());
    setDirector(f.getDirector());
    setYear(f.getYear());
    setPrice(f.getPrice());
    setAdded(QDateTime::currentDateTime());
}

FilmSale::FilmSale(Film f, unsigned int q, const QString &l):
    quantity(q),
    lastSoldTo(l) {
    setId(f.getId());
    setTitle(f.getTitle());
    setDirector(f.getDirector());
    setYear(f.getYear());
    setPrice(f.getPrice());
    setAdded(QDateTime::currentDateTime());
}

FilmSale::FilmSale(Film f, unsigned int q, const char *l, QDateTime a):
    quantity(q),
    lastSold(a),
    lastSoldTo(QString(l)) {
    setId(f.getId());
    setTitle(f.getTitle());
    setDirector(f.getDirector());
    setYear(f.getYear());
    setPrice(f.getPrice());
    setAdded(QDateTime::currentDateTime());
}

FilmSale::FilmSale(Film f, unsigned int q, const QString &l, QDateTime a):
    quantity(q),
    lastSold(a),
    lastSoldTo(l) {
    setId(f.getId());
    setTitle(f.getTitle());
    setDirector(f.getDirector());
    setYear(f.getYear());
    setPrice(f.getPrice());
    setAdded(QDateTime::currentDateTime());
}

FilmSale::FilmSale(Film f, unsigned int q, QDateTime a):
    quantity(q),
    lastSold(a) {
    setId(f.getId());
    setTitle(f.getTitle());
    setDirector(f.getDirector());
    setYear(f.getYear());
    setPrice(f.getPrice());
    setAdded(QDateTime::currentDateTime());
}

Film::Film(const char *t, const char *d, unsigned int y, double p)
    : id(0), title(QString(t)), director(QString(d)), year(y), price(p) {
    added = QDateTime::currentDateTime();
}

Film::Film(const QString &t, const QString &d)
    : id(0), title(t), director(d), year(0), price(0.0) {
    added = QDateTime::currentDateTime();
}

Film::Film(const char *t, const char *d)
    : id(0), title(QString(t)), director(QString(d)), year(0), price(0.0) {
    added = QDateTime::currentDateTime();
}

Film::Film(const QString &t, const QString &d, unsigned int y)
    : id(0), title(t), director(d), year(y), price(0.0) {
    added = QDateTime::currentDateTime();
}

Film::Film(const char *t, const char *d, unsigned int y)
    : id(0), title(QString(t)), director(QString(d)), year(y), price(0.0) {
    added = QDateTime::currentDateTime();
}

Film::Film(const QString &t, const QString &d, unsigned int y, double p)
    : id(0), title(t), director(d), year(y), price(p) {
    added = QDateTime::currentDateTime();
}

Film::Film(unsigned int i, const QString &t, const QString &d)
    : id(i), title(t), director(d), year(0), price(0.0) {
    added = QDateTime::currentDateTime();
}

Film::Film(unsigned int i, const char *t, const char *d)
    : id(i), title(QString(t)), director(QString(d)), year(0), price(0.0) {
    added = QDateTime::currentDateTime();
}

Film::Film(unsigned int i, const QString &t, const QString &d, unsigned int y)
    : id(i), title(t), director(d), year(y), price(0.0) {
    added = QDateTime::currentDateTime();
}

Film::Film(unsigned int i, const char *t, const char *d, unsigned int y)
    : id(i), title(QString(t)), director(QString(d)), year(y), price(0.0) {
    added = QDateTime::currentDateTime();
}

Film::Film(unsigned int i, const QString &t, const QString &d, unsigned int y, double p)
    : id(i), title(t), director(d), year(y), price(p) {
    added = QDateTime::currentDateTime();
}

Film::Film(unsigned int i, const char *t, const char *d, unsigned int y, double p)
    : id(i), title(QString(t)), director(QString(d)), year(y), price(p) {
    added = QDateTime::currentDateTime();
}

void Film::print(void) {

}

void Film::setId(int i) {
    id = (unsigned int)i;
}

unsigned int Film::getId(void) {
    return id;
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

void FilmRent::setQuantity(int q) {
    quantity = (unsigned int)q;
}

int FilmRent::getQuantity(void) {
    return (int)quantity;
}

void FilmSale::setQuantity(int q) {
    quantity = (unsigned int)q;
}

int FilmSale::getQuantity(void) {
    return (int)quantity;
}

void FilmRent::setAvailable(int a) {
    available = (unsigned int)a;
}

int FilmRent::getAvailable(void) {
    return (int)available;
}

void FilmRent::setLastRented(QDateTime l) {
    lastRented = l;
}

QDateTime FilmRent::getLastRented(void) {
    return lastRented;
}

void FilmSale::setLastSold(QDateTime l) {
    lastSold = l;
}

QDateTime FilmSale::getLastSold(void) {
    return lastSold;
}

void FilmRent::setLastRentedTo(const char *l) {
    lastRentedTo = (QString)l;
}

void FilmRent::setLastRentedTo(const QString &l) {
    lastRentedTo = l;
}

QString FilmRent::getLastRentedTo(void) {
    return lastRentedTo;
}

void FilmSale::setLastSoldTo(const char *l) {
    lastSoldTo = (QString)l;
}

void FilmSale::setLastSoldTo(const QString &l) {
    lastSoldTo = l;
}

QString FilmSale::getLastSoldTo(void) {
    return lastSoldTo;
}

void FilmRent::print(void) {
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "Title: " << getTitle().toStdString() << std::endl;
    std::cout << "Director: " << getDirector().toStdString() << std::endl;
    std::cout << "Year: " << getYear() << std::endl;
    std::cout << "Price: $" << getPrice() << std::endl;
    std::cout << "Quantity: " << quantity << std::endl;
    std::cout << "Available: " << available << std::endl;
    std::cout << "Last Rented to: " << lastRentedTo.toStdString() << std::endl;
}

void FilmSale::print(void) {
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "Title: " << getTitle().toStdString() << std::endl;
    std::cout << "Director: " << getDirector().toStdString() << std::endl;
    std::cout << "Year: " << getYear() << std::endl;
    std::cout << "Price: $" << getPrice() << std::endl;
    std::cout << "Quantity: " << quantity << std::endl;
    std::cout << "Last Sold to: " << lastSoldTo.toStdString() << std::endl;
}
