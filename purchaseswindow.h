/* purchaseswindow.h
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
#ifndef PURCHASESWINDOW_H
#define PURCHASESWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>

namespace Ui {
class PurchasesWindow;
}

class PurchasesWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit PurchasesWindow(QWidget *parent = nullptr);
    ~PurchasesWindow(void);
    bool getDebugMode(void);
    void setDebugMode(bool d);
    QString getQuery(void);
    void setQuery(QString q);
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    /* user clicked "Add Film for Purchase" button from Purchases */
    void on_purchaseAddNew_clicked(void);
    /* Whenever the text for the "Title of Film" box is changed */
    void on_purchaseFilmTitle_textChanged(const QString &arg1);
    /* user pressed Return after editing "Title of Film" box from Purchases */
    void on_purchaseFilmTitle_returnPressed(void);
    /* user clicked "Edit Film" button from Purchases */
    void on_purchaseEdit_clicked(void);
    /* user clicked "Return" button from Purchases */
    void on_purchaseReturn_clicked(void);
private:
    Ui::PurchasesWindow *ui;
    bool debugMode;
    QString query;
signals:
    void closing(void);
};

#endif // PURCHASESWINDOW_H
