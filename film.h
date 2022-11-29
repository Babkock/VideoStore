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
    double actualPrice;      // Price of film with ID * quantity
    QString title;           // Title of film
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
    Film(const QString &t, const QString &d);
    Film(const char *t, const char *d);
    Film(const QString &t, const QString &d, unsigned int y);
    Film(const char *t, const char *d, unsigned int y);
    Film(const QString &t, const QString &d, unsigned int y, double p);
    Film(const char *t, const char *d, unsigned int y, double p);
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
signals:

};

class FilmRent : public Film {
    Q_OBJECT
private:
    int quantity;
    int available;
    QString lastRentedTo;
    QDateTime lastRented;
public:
    /*
    explicit FilmRent(QObject *parent = nullptr);
    explicit FilmRent(Film f, QObject *parent = nullptr);
    explicit FilmRent(const QString &t, const QString &d, unsigned int y = 0, double p = 0.0, QObject *parent = nullptr);
    explicit FilmRent(const char *t, const char *d, unsigned int y = 0, double p = 0.0, QObject *parent = nullptr);
    */
    FilmRent(Film f);
    FilmRent(Film f, int q);
    FilmRent(Film f, int q, int a);
    FilmRent(Film f, const char *l);
    FilmRent(Film f, QDateTime l);
    FilmRent(Film f, const char *l, QDateTime a);
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
    int quantity;
    QDateTime lastSold;
public:
    /*
    explicit FilmSale(QObject *parent = nullptr);
    explicit FilmSale(Film f, QObject *parent = nullptr);
    explicit FilmSale(const QString &t, const QString &d, unsigned int y = 0, double p = 0.0, QObject *parent = nullptr);
    explicit FilmSale(const char *t, const char *d, unsigned int y = 0, double p = 0.0, QObject *parent = nullptr);
    */
    FilmSale(Film f);
    FilmSale(Film f, int q);
    FilmSale(Film f, QDateTime l);
    FilmSale(Film f, int q, QDateTime l);
    int getQuantity(void);
    void setQuantity(int q);
    QDateTime getLastSold(void);
    void setLastSold(QDateTime l);
signals:

};

#endif // FILM_H
