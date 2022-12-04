/* purchasesform.h
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
#ifndef PURCHASESFORM_H
#define PURCHASESFORM_H

#include "film.h"
#include "purchaseswindow.h"
#include <QMainWindow>

namespace Ui {
class PurchasesForm;
}

class PurchasesForm : public QMainWindow {
    Q_OBJECT
public:
    explicit PurchasesForm(QWidget *parent = nullptr);
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

private:
    Ui::PurchasesForm *ui;
    FilmSale film;
    bool editExisting;
signals:
    void closing(void);
};

#endif // PURCHASESFORM_H
