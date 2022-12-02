/* rentalsform.h
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
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
    bool getDebugMode(void);
    void setDebugMode(bool d);
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
    /* user changed value of "Year" field */
    void on_rentalsYearField_valueChanged(int arg1);
    /* user changed value of "Quantity" field */
    void on_rentalsQuantityField_valueChanged(int arg1);
    /* user changed value of "Available" field */
    void on_rentalsAvailableField_valueChanged(int arg1);
    /* user selected a date for the "Last Rented" field */
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

private:
    Ui::RentalsForm *ui;     // The interface for our Rentals Form window
    FilmRent film;           // A FilmRent object that can read from/write to database
    bool editExisting;       // true = existing film is being edited, false = new film
    bool debugMode;          // Should we print debug messages?
signals:
    void closing(void);
};

#endif // RENTALSFORM_H
