#ifndef RENTALSFORM_H
#define RENTALSFORM_H

#include "film.h"
#include <QWidget>

namespace Ui {
class RentalsForm;
}

class RentalsForm : public QWidget {
    Q_OBJECT
public:
    explicit RentalsForm(QWidget *parent = nullptr);
    ~RentalsForm(void);
    bool getDebugMode(void);
    void setDebugMode(bool d);
    bool getNew(void);
    void setNew(bool n);
    Film *getFilm(void);
    void setFilm(const Film &f);
    int getQuantity(void);
    void setQuantity(int q);
    int getAvailable(void);
    void setAvailable(int a);
    QString getLastRentedTo(void);
    void setLastRentedTo(const char *l);
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    /* the "Title of Film" field text has been changed */
    void on_rentFormTitleField_textChanged(const QString &arg1);

    /* the "Director of Film" field text has been changed */
    void on_rentFormDirectorField_textChanged(const QString &arg1);

    /* the "Year" field value has been changed */
    void on_rentFormYearField_valueChanged(int arg1);

    /* the "Price" field value has been changed */
    void on_rentFormPriceField_valueChanged(double arg1);

    /* the "Save Changes" button has been clicked */
    void on_rentFormSaveChangesButton_clicked(void);

    /* the "Discard Changes" button has been clicked */
    void on_rentFormDiscardChangesButton_clicked(void);

    /* user pressed Return after editing "Title of Film" field */
    void on_rentFormTitleField_returnPressed(void);

    /* user pressed Return after editing "Director of Film" */
    void on_rentFormDirectorField_returnPressed(void);

    /* the "Date Added" date has been picked */
    void on_rentFormAddedField_dateTimeChanged(const QDateTime &dateTime);

    /* the "Quantity" field value has been set */
    void on_rentFormQuantity_valueChanged(int arg1);

    /* the "Available" field value has been set */
    void on_rentFormAvailable_valueChanged(int arg1);

    /* the "Last Rented to" field text has been changed */
    void on_rentFormLastRentedTo_textChanged(const QString &arg1);

    /* user pressed Return after editing "Last Rented to" field */
    void on_rentFormLastRentedTo_returnPressed(void);
private:
    Ui::RentalsForm *ui;
    bool debugMode;
    bool newFilm;
    FilmRent *film;
    int quantity;
    int available;
    QString lastRentedTo;
    QDateTime lastRented;
signals:
    void closing(void);
};

#endif // RENTALSFORM_H