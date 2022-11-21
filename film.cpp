/* film.cpp
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
#include <QDate>
#include "film.h"

Film::Film(QObject *parent)
    : QObject{parent} {

}

Film::Film(const char *t, const char *d, unsigned int y, double p)
    : title(QString(t)), director(QString(d)), year(quint32(y)), price(p) {
    added = QDateTime::currentDateTime();
}
