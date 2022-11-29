/* rentalswindow.cpp
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
#include "rentalswindow.h"
#include "ui_rentalswindow.h"
#include "rentalseditor.h"
#include "ui_rentalseditor.h"
#include "rentalsform.h"
#include "ui_rentalsform.h"
#include <iostream>

RentalsWindow::RentalsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RentalsWindow) {
    rentalEditor = new RentalsEditor(new RentalsForm(this), this);
    ui->setupUi(this);
    connect(rentalEditor, SIGNAL(closing()), this, SLOT(show()));
}

RentalsWindow::~RentalsWindow(void) {
    delete ui;
    delete rentalEditor;
}

void RentalsWindow::closeEvent(QCloseEvent *event) {
    emit closing();
    event->accept();
}

/* user clicked "Add Film for Rent" from Rentals window */
void RentalsWindow::on_rentalAddNew_clicked(void) {
    /* bring up empty RentalsForm */
    //this->hide();
    rentalEditor->show();
}

/* Whenever the text for the "Title of Film" box is changed */
void RentalsWindow::on_rentalFilmTitle_textChanged(const QString &arg1) {
    query = arg1;
}

/* User pressed Return after editing "Title of Film" box from Rentals window
 * This should do the same thing as on_rentalEdit_clicked() */
void RentalsWindow::on_rentalFilmTitle_returnPressed(void) {
    /* do nothing if the text box is empty */

    /* else, query the database */

    /* if not found, do nothing */

    /* else, bring up the RentalsForm with the found data */
}

/* user clicked "Edit Film" button from Rentals window
 * This should do the same thing as on_rentalFilmTitle_returnPressed() */
void RentalsWindow::on_rentalEdit_clicked(void) {
    /* do nothing if the text box is empty */

    /* else, query the database */

    /* if not found, do nothing */

    /* else, bring up the RentalsForm with the found data */
}

/* user clicked "Return" button from Rentals window */
void RentalsWindow::on_rentalReturn_clicked(void) {
    emit closing();
    this->close();
}

bool RentalsWindow::getDebugMode(void) {
    return debugMode;
}

void RentalsWindow::setDebugMode(bool d) {
    debugMode = d;
}

QString RentalsWindow::getQuery(void) {
    return query;
}

void RentalsWindow::setQuery(QString q) {
    query = q;
}
