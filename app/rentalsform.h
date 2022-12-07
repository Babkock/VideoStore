/* rentalsform.h
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
#ifndef RENTALSFORM_H
#define RENTALSFORM_H

#include "film.h"
#include "rentalswindow.h"
#include <QMainWindow>
#include <QCloseEvent>

namespace Ui {
class RentalsForm;
}

class RentalsForm : public QMainWindow {
    Q_OBJECT
public:
    explicit RentalsForm(QWidget *parent = nullptr);
    RentalsForm(void);
    RentalsForm(Film f);
    RentalsForm(Film f, unsigned int q);
    RentalsForm(Film f, unsigned int q, unsigned int a);
    RentalsForm(Film f, const char *l);
    RentalsForm(Film f, const QString &l);
    RentalsForm(Film f, QDateTime l);
    RentalsForm(const QString &t);
    RentalsForm(const QString &t, const QString &d);
    RentalsForm(const QString &t, unsigned int y);
    RentalsForm(const QString &t, const QString &d, unsigned int y);
    RentalsForm(const QString &t, unsigned int y, double p);
    RentalsForm(const QString &t, const QString &d, double p);
    RentalsForm(const QString &t, const QString &d, unsigned int y, double p);
    RentalsForm(unsigned int id, const QString &t);
    RentalsForm(unsigned int id, const char *t);
    RentalsForm(unsigned int id, const QString &t, const QString &d);
    RentalsForm(unsigned int id, const char *t, const char *d);
    RentalsForm(unsigned int id, const QString &t, const QString &d, unsigned int y);
    RentalsForm(unsigned int id, const QString &t, const QString &d, unsigned int y, double p);
    RentalsForm(unsigned int id, const char *t, const char *d, unsigned int y);
    RentalsForm(unsigned int id, const char *t, const char *d, unsigned int y, double p);
    ~RentalsForm(void);
    bool getEditExisting(void);
    void setEditExisting(bool e);
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    /* user changed text of the "Title of Film:" field */
    void on_rentalsTitleField_textChanged(const QString &arg1);
    /* user changed text of the "Director of Film:" field */
    void on_rentalsDirectorField_textChanged(const QString &arg1);
    /* user changed value of "Price in $:" field */
    void on_rentalsPriceField_valueChanged(double arg1);
    /* the value of "Price" input field was changed */
    void on_rentalsYearField_valueChanged(int arg1);
    /* the value of "Quantity" input field was changed */
    void on_rentalsQuantityField_valueChanged(int arg1);
    /* the value of "Available" field was changed */
    void on_rentalsAvailableField_valueChanged(int arg1);
    /* user selected a date time for the "Last Rented" field */
    void on_rentalsLastRentedField_dateTimeChanged(const QDateTime &dateTime);
    /* user changed text of "Last Rented to" field */
    void on_rentalsLastRentedTo_textChanged(const QString &arg1);
    /* user clicked on "Save Changes to Film" button */
    void on_rentalsSaveChanges_clicked(void);
    /* user clicked on "Discard Changes" button */
    void on_rentalsDiscardChanges_clicked(void);
    /* user pressed Return after editing "Title of Film" field */
    void on_rentalsTitleField_returnPressed(void);
    /* user pressed Return after editing "Director of Film" field */
    void on_rentalsDirectorField_returnPressed(void);
    /* user pressed Return after editing "Last Rented to" field */
    void on_rentalsLastRentedTo_returnPressed(void);

private:
    Ui::RentalsForm *ui;
    FilmRent film;
    bool editExisting;
signals:
    void closing(void);
};

#endif // RENTALSFORM_H
