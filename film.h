/* film.h
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
#ifndef FILM_H
#define FILM_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QDateTime>

typedef struct ShoppingCartItem_t {
    bool rental : 1;         // rental = true, sale = false
    unsigned int id : 8;     // ID from the Database
    int quantity : 6;        // Selected by shopper/employee
    double price;            // Price of film
    QString title;           // Title of film
    struct ShoppingCartItem_t *next;
} ShoppingCartItem;

class Film : public QObject {
    Q_OBJECT
private:
    unsigned int id;
    QString title;
    QString director;
    unsigned int year;
    double price;
    QDateTime added;
public:
    explicit Film(QObject *parent = nullptr);
    Film(const Film &f);
    Film(const QString &t, const QString &d);
    Film(const char *t, const char *d);
    Film(const QString &t, const QString &d, unsigned int y);
    Film(const char *t, const char *d, unsigned int y);
    Film(const QString &t, const QString &d, unsigned int y, double p);
    Film(const char *t, const char *d, unsigned int y, double p);
    Film(unsigned int i, const QString &t, const QString &d);
    Film(unsigned int i, const char *t, const char *d);
    Film(unsigned int i, const QString &t, const QString &d, unsigned int y);
    Film(unsigned int i, const char *t, const char *d, unsigned int y);
    Film(unsigned int i, const QString &t, const QString &d, unsigned int y, double p);
    Film(unsigned int i, const char *t, const char *d, unsigned int y, double p);
    void setId(int i);
    unsigned int getId(void);
    QString getTitle(void);
    void setTitle(const QString &t);
    void setTitle(const char *t);
    QString getDirector(void);
    void setDirector(const QString &d);
    void setDirector(const char *t);
    unsigned int getYear(void);
    void setYear(unsigned int y);
    double getPrice(void);
    void setPrice(double p);
    QDateTime getAdded(void);
    void setAdded(QDateTime a);
    virtual void print(void);
signals:

};

class FilmRent : public Film {
    Q_OBJECT
private:
    unsigned int quantity;
    unsigned int available;
    QString lastRentedTo;
    QDateTime lastRented;
public:
    FilmRent(void);
    FilmRent(Film f);
    FilmRent(Film f, unsigned int q);
    FilmRent(Film f, unsigned int q, unsigned int a);
    FilmRent(Film f, const char *l);
    FilmRent(Film f, const QString &l);
    FilmRent(Film f, QDateTime l);
    FilmRent(Film f, const char *l, QDateTime a);
    FilmRent(Film f, const QString &l, QDateTime a);
    FilmRent(Film f, unsigned int q, const char *l);
    FilmRent(Film f, unsigned int q, const QString &l);
    FilmRent(Film f, unsigned int q, const char *l, QDateTime a);
    FilmRent(Film f, unsigned int q, const QString &l, QDateTime a);
    FilmRent(Film f, unsigned int q, QDateTime a);
    int getQuantity(void);
    void setQuantity(int q);
    int getAvailable(void);
    void setAvailable(int a);
    QString getLastRentedTo(void);
    void setLastRentedTo(const QString &l);
    void setLastRentedTo(const char *l);
    QDateTime getLastRented(void);
    void setLastRented(QDateTime l);
    void print(void);
signals:

};

class FilmSale : public Film {
    Q_OBJECT
private:
    unsigned int quantity;
    QDateTime lastSold;
    QString lastSoldTo;
public:
    FilmSale(void);
    FilmSale(Film f);
    FilmSale(Film f, unsigned int q);
    FilmSale(Film f, const char *l);
    FilmSale(Film f, const QString &l);
    FilmSale(Film f, QDateTime l);
    FilmSale(Film f, const char *l, QDateTime a);
    FilmSale(Film f, const QString &l, QDateTime a);
    FilmSale(Film f, unsigned int q, const char *l);
    FilmSale(Film f, unsigned int q, const QString &l);
    FilmSale(Film f, unsigned int q, const char *l, QDateTime a);
    FilmSale(Film f, unsigned int q, const QString &l, QDateTime a);
    FilmSale(Film f, unsigned int q, QDateTime a);
    int getQuantity(void);
    void setQuantity(int q);
    QDateTime getLastSold(void);
    void setLastSold(QDateTime l);
    QString getLastSoldTo(void);
    void setLastSoldTo(const char *l);
    void setLastSoldTo(const QString &l);
    void print(void);
signals:

};

#endif // FILM_H
