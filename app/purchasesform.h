/*
 * purchasesform.h
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
#ifndef PURCHASESFORM_H
#define PURCHASESFORM_H

#include "film.h"
#include "purchaseswindow.h"
#include <QMainWindow>
#include <QCloseEvent>

namespace Ui {
class PurchasesForm;
}

class PurchasesForm : public QMainWindow {
    Q_OBJECT
public:
    explicit PurchasesForm(QWidget *parent = nullptr);
    PurchasesForm(void);
    PurchasesForm(Film f);
    PurchasesForm(Film f, unsigned int q);
    PurchasesForm(Film f, const char *l);
    PurchasesForm(Film f, const QString &l);
    PurchasesForm(Film f, QDateTime l);
    PurchasesForm(Film f, const char *l, QDateTime a);
    PurchasesForm(Film f, const QString &l, QDateTime a);
    PurchasesForm(Film f, unsigned int q, const char *l);
    PurchasesForm(Film f, unsigned int q, const QString &l);
    PurchasesForm(Film f, unsigned int q, const char *l, QDateTime a);
    PurchasesForm(Film f, unsigned int q, const QString &l, QDateTime a);
    PurchasesForm(Film f, unsigned int q, QDateTime a);
    PurchasesForm(unsigned int id, const QString &t);
    PurchasesForm(unsigned int id, const char *t);
    PurchasesForm(unsigned int id, const QString &t, const QString &d);
    PurchasesForm(unsigned int id, const char *t, const char *d);
    PurchasesForm(unsigned int id, const QString &t, const QString &d, unsigned int y);
    PurchasesForm(unsigned int id, const char *t, const char *d, unsigned int y);
    PurchasesForm(unsigned int id, const QString &t, const QString &d, unsigned int y, double p);
    PurchasesForm(unsigned int id, const char *t, const char *d, unsigned int y, double p);
    ~PurchasesForm(void);
    bool getEditExisting(void);
    void setEditExisting(bool e);
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    /* user clicked on the "Save Changes to Film" button on Purchases */
    void on_purchasesSaveChanges_clicked(void);
    /* user clicked on "Discard Changes" button on Purchases */
    void on_purchasesDiscardChanges_clicked(void);
    /* the text of the "Title of Film" field was changed */
    void on_purchasesTitleField_textChanged(const QString &arg1);
    /* the text of the "Director of Film" field was changed */
    void on_purchasesDirectorField_textChanged(const QString &arg1);
    /* the value of "Year" input field was changed */
    void on_purchasesYearField_valueChanged(int arg1);
    /* the value of "Price" field was changed */
    void on_purchasesPriceField_valueChanged(double arg1);
    /* the value of the "Quantity" field was changed */
    void on_purchasesQuantityField_valueChanged(int arg1);
    /* user selected a new date time on the "Last Sold:" field */
    void on_purchasesLastSoldField_dateTimeChanged(const QDateTime &dateTime);
    /* the text of the "Last Sold to:" field was changed */
    void on_purchasesLastSoldTo_textChanged(const QString &arg1);
    /* user pressed Return after editing "Title of Film" field */
    void on_purchasesTitleField_returnPressed(void);
    /* user pressed Return after editing "Director of Film" field */
    void on_purchasesDirectorField_returnPressed(void);
    /* user pressed Return after editing "Last Sold to:" field */
    void on_purchasesLastSoldTo_returnPressed(void);
private:
    Ui::PurchasesForm *ui;
    FilmSale film;
    bool editExisting;
signals:
    void closing(void);
};

#endif // PURCHASESFORM_H
