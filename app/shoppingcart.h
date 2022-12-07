/* shoppingcart.h
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
#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "database.h"
#include "film.h"
#include <QMainWindow>
#include <QCloseEvent>
#include <vector>

namespace Ui {
class ShoppingCart;
}

class ShoppingCart : public QMainWindow {
    Q_OBJECT
public:
    explicit ShoppingCart(QWidget *parent = nullptr);
    ShoppingCart(void);
    ShoppingCart(ShoppingCartItem c);
    ShoppingCart(ShoppingCartItem_t c, const char *n);
    ShoppingCart(ShoppingCartItem_t c, const QString &n);
    ~ShoppingCart(void);
    QString getCustomerName(void);
    void setCustomerName(const char *n);
    void setCustomerName(const QString &n);
    bool getRental(void);
    void setRental(bool r);
    unsigned int getId(void);
    void setId(unsigned int i);
    unsigned int getQuantity(void);
    void setQuantity(unsigned int q);
    void push(ShoppingCartItem c);
protected:
    void closeEvent(QCloseEvent *event);
private:
    Ui::ShoppingCart *ui;
    std::vector<ShoppingCartItem> cart;
    QString customerName;
    bool rental;
    unsigned int id;
    unsigned int quantity;
    QDateTime due;
signals:
    void closing(void);
private slots:
    /* user clicked the "Cancel" button */
    void on_shoppingCartCancel_clicked(void);
    /* user clicked the "Add to Cart" button */
    void on_shoppingCartAddToCart_clicked(void);
    /* the value of the "ID:" field was changed */
    void on_shoppingCartIdField_valueChanged(int arg1);
    /* the value of the "Quantity:" field was changed */
    void on_shoppingCartQuantityField_valueChanged(int arg1);
    /* user clicked the "Remove Last Item from Cart" button */
    void on_shoppingCartRemoveLast_clicked(void);
    /* user clicked the "Empty Cart" button */
    void on_shoppingCartEmptyCart_clicked(void);
    /* the text of the "Customer Name" field was changed */
    void on_shoppingCartCustomerNameField_textChanged(const QString &arg1);
    /* user selected a date time in the "Due" field */
    void on_shoppingCartDueField_dateTimeChanged(const QDateTime &dateTime);
    /* user clicked the "Confirm Order" button */
    void on_shoppingCartConfirm_clicked(void);
};

#endif // SHOPPINGCART_H
