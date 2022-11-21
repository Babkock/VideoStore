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
    quint32 year;
    double price;
    QDateTime added;
public:
    explicit Film(QObject *parent = nullptr);
    Film(const char *t, const char *d, unsigned int y, double p);
signals:

};

#endif // FILM_H
