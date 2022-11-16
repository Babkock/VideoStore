#include "rentalswindow.h"
#include "ui_rentalswindow.h"

RentalsWindow::RentalsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RentalsWindow) {
    ui->setupUi(this);
}

RentalsWindow::~RentalsWindow(void) {
    delete ui;
}

void RentalsWindow::closeEvent(QCloseEvent *event) {
    emit closing();
    event->accept();
}

/* user clicked "Add Film for Rent" from Rentals window */
void RentalsWindow::on_rentalAddNew_clicked(void) {
    /* bring up empty RentalsForm */
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

}

bool RentalsWindow::getDebugMode(void) {
    return debugMode;
}

void RentalsWindow::setDebugMode(bool d) {
    debugMode = d;
}
