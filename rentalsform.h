#ifndef RENTALSFORM_H
#define RENTALSFORM_H

#include "film.h"
#include "rentalswindow.h"
#include <QMainWindow>

namespace Ui {
class RentalsForm;
}

class RentalsForm : public QMainWindow {
    Q_OBJECT
public:
    explicit RentalsForm(QWidget *parent = nullptr);
    RentalsForm(Film f);
    RentalsForm(Film f, unsigned int q);
    RentalsForm(Film f, unsigned int q, unsigned int a);
    RentalsForm(Film f, const char *l);
    RentalsForm(Film f, const QString &l);
    RentalsForm(Film f, QDateTime l);
    RentalsForm(Film f, const char *l, QDateTime a);
    RentalsForm(Film f, const QString &l, QDateTime a);
    RentalsForm(Film f, unsigned int q, const char *l);
    RentalsForm(Film f, unsigned int q, const QString &l);
    RentalsForm(Film f, unsigned int q, const char *l, QDateTime a);
    RentalsForm(Film f, unsigned int q, const QString &l, QDateTime a);
    RentalsForm(Film f, unsigned int q, QDateTime a);
    //RentalsForm(Film f, unsigned int q, unsigned int a, QDateTime a);
    //RentalsForm(Film f, unsigned int q, unsigned int q, const char *l, QDateTime a);
    //RentalsForm(Film f, unsigned int q, unsigned int a, const QString &l, QDateTime a);
    RentalsForm(const QString &t);
    RentalsForm(const QString &t, const QString &d);
    RentalsForm(const QString &t, unsigned int y);
    RentalsForm(const QString &t, const QString &d, unsigned int y);
    RentalsForm(const QString &t, unsigned int y, double p);
    RentalsForm(const QString &t, const QString &d, double p);
    RentalsForm(const QString &t, const QString &d, unsigned int y, double p);
    ~RentalsForm(void);
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    /* user changed text of the "Title of Film:" field */
    void on_rentalsTitleField_textChanged(const QString &arg1);
    /* user changed text of the "Director of Film:" field */
    void on_rentalsDirectorField_textChanged(const QString &arg1);

private:
    Ui::RentalsForm *ui;
    FilmRent film;
    bool debugMode;
signals:
    void closing(void);
};

#endif // RENTALSFORM_H
