#ifndef RENTALSFORM_H
#define RENTALSFORM_H

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

private:
    Ui::RentalsForm *ui;
    bool debugMode;
signals:
    void closing(void);
};

#endif // RENTALSFORM_H
