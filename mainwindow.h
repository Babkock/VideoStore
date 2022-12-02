/* mainwindow.h
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QSqlDatabase>
#include "purchaseswindow.h"
#include "rentalswindow.h"
#include "rentalsform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow(void);
    bool getDebugMode(void);
    void setDebugMode(bool d);
protected:
    //void closeEvent(QCloseEvent *event);
private slots:
    /* user clicked "Rentals" from top menu */
    void on_buttonRentals_clicked(void);
    /* user clicked "Purchases" from top menu */
    void on_buttonPurchases_clicked(void);
    /* user clicked "Check Out Films" from top menu */
    void on_buttonCheckOut_clicked(void);
    /* user clicked "Reset Database" from top menu */
    void on_buttonReset_clicked(void);
    /* user toggled "Print Debug Messages" on top menu */
    void on_checkDebug_toggled(bool checked);
private:
    Ui::MainWindow *ui;
    RentalsWindow *rentals;
    PurchasesWindow *purchases;
    RentalsForm *form;
    QSqlDatabase db;
    bool debugMode;
signals:
    //void closing(void);
};

#endif // MAINWINDOW_H
