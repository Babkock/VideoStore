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

class Film : public QObject {
    Q_OBJECT
private:
    QString title;
    QString director;
    int year;
    double price;
    QDateTime added;
public:
    explicit Film(QObject *parent = nullptr);
    Film(const char *t, const char *d, unsigned int y, double p);
    QString getTitle(void);
    void setTitle(QString t);
    QString getDirector(void);
    void setDirector(QString d);
    int getYear(void);
    void setYear(int y);
    double getPrice(void);
    void setPrice(double p);
    QDateTime getAdded(void);
    void setAdded(QDateTime a);
    void print(void);
signals:

};

#endif // FILM_H
