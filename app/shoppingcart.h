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

namespace Ui {
class ShoppingCart;
}

class ShoppingCart : public QMainWindow {
    Q_OBJECT
public:
    explicit ShoppingCart(QWidget *parent = nullptr);
    ShoppingCart(void);
    ShoppingCart(ShoppingCartItem_t *c);
    ShoppingCart(ShoppingCartItem_t c, const char *n);
    ShoppingCart(ShoppingCartItem_t c, const QString &n);
    ~ShoppingCart(void);
    QString getCustomerName(void);
    void setCustomerName(const char *n);
    void setCustomerName(const QString &n);
    unsigned int getId(void);
    void setId(unsigned int i);
    unsigned int getQuantity(void);
    void setQuantity(unsigned int q);
protected:
    void closeEvent(QCloseEvent *event);
private:
    Ui::ShoppingCart *ui;
    ShoppingCartItem *cart;
    QString customerName;
    unsigned int id;
    unsigned int quantity;
    QDateTime due;
signals:
    void closing(void);
private slots:
    /* user clicked the "Cancel" button */
    void on_shoppingCartCancel_clicked(void);
};

#endif // SHOPPINGCART_H
