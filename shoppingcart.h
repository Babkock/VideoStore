/* shoppingcart.h
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QMainWindow>
#include <QCloseEvent>

namespace Ui {
class ShoppingCart;
}

class ShoppingCart : public QMainWindow {
    Q_OBJECT
public:
    explicit ShoppingCart(QWidget *parent = nullptr);
    ~ShoppingCart(void);

private:
    Ui::ShoppingCart *ui;
};

#endif // SHOPPINGCART_H
