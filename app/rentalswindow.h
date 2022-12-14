/*
 * rentalswindow.h
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
#ifndef RENTALSWINDOW_H
#define RENTALSWINDOW_H

#include "film.h"
#include <QMainWindow>
#include <QCloseEvent>

namespace Ui {
class RentalsWindow;
}

class RentalsWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit RentalsWindow(QWidget *parent = nullptr);
    RentalsWindow(QWidget *parent, QMainWindow *form);
    ~RentalsWindow(void);
    QString getQuery(void);
    void setQuery(QString q);
    unsigned int getId(void);
    void setId(unsigned int i);
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    /* user clicked "Add Film for Rent" button from Rentals window */
    void on_rentalAddNew_clicked(void);
    /* Whenever the text for the "Title of Film" text box is changed */
    void on_rentalTitleField_textChanged(const QString &arg1);
    /* User pressed Return after editing "Title of Film" box from Rentals window */
    void on_rentalTitleField_returnPressed(void);
    /* user clicked "Find Film to Edit" button from Rentals window */
    void on_rentalEdit_clicked(void);
    /* user clicked "Return" button from Rentals window */
    void on_rentalReturn_clicked(void);
    /* the value of "or by ID:" box was changed */
    void on_rentalIdField_valueChanged(int arg1);
    /* Whenever the text in the "Title of Film" field is edited */
    void on_rentalTitleField_textEdited(const QString &arg1);
    /* user has finished editing the "or by ID:" field on Rentals */
    void on_rentalIdField_editingFinished(void);
private:
    Ui::RentalsWindow *ui;
    QMainWindow *form;
    QString query;
    unsigned int id;
signals:
    void closing(void);
};

#endif // RENTALSWINDOW_H
