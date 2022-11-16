#include "mainwindow.h"
#include "rentalswindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    rentals = new RentalsWindow();
    connect(rentals, SIGNAL(closing()), this, SLOT(show()));
}

MainWindow::~MainWindow(void) {
    delete rentals;
    delete ui;
}

/* user clicked "Rentals" from top menu */
void MainWindow::on_buttonRentals_clicked(void) {
    hide();
    rentals->show();
}

/* user clicked "Purchases" from top menu */
void MainWindow::on_buttonPurchases_clicked(void) {

}

/* user clicked "Check Out Films" from top menu */
void MainWindow::on_buttonCheckOut_clicked(void) {

}

/* user clicked "Reset Database" from top menu */
void MainWindow::on_buttonReset_clicked(void) {

}

/* user toggled "Print Debug Messages" on top menu */
void MainWindow::on_checkDebug_toggled(bool checked) {
    setDebugMode(checked);
}

bool MainWindow::getDebugMode(void) {
    return debugMode;
}

void MainWindow::setDebugMode(bool d) {
    debugMode = d;
}
