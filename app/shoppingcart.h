/* shoppingcart.h
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
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
    void on_shoppingCartIdField_valueChanged(int arg1);
    void on_shoppingCartQuantityField_valueChanged(int arg1);
};

#endif // SHOPPINGCART_H
