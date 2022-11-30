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
    unsigned int getId(void);
    void setId(unsigned int i);
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    /* user clicked "Add Film for Purchase" button from Purchases */
    void on_purchaseAddNew_clicked(void);
    /* Whenever the text for the "Title of Film" field is changed */
    void on_purchaseTitleField_textChanged(const QString &arg1);
    /* user pressed Return after editing "Title of Film" box from Purchases */
    void on_purchaseTitleField_returnPressed(void);
    /* user clicked "Edit Film" button from Purchases */
    void on_purchaseEdit_clicked(void);
    /* user clicked "Return" button from Purchases */
    void on_purchaseReturn_clicked(void);
    /* the value of "or by ID:" field on Purchases was changed */
    void on_purchaseIdField_valueChanged(int arg1);
    /* Whenever the text in the "Title of Film" field is edited */
    void on_purchaseTitleField_textEdited(const QString &arg1);
    /* user is finished editing the "or by ID:" field on Purchases */
    void on_purchaseIdField_editingFinished(void);
private:
    Ui::PurchasesWindow *ui;
    /* PurchasesEditor *purchaseEditor; */
    bool debugMode;
    QString query;
    unsigned int id;
signals:
    void closing(void);
};

#endif // PURCHASESWINDOW_H
