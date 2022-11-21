/* rentalswindow.h
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
#ifndef RENTALSWINDOW_H
#define RENTALSWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>

namespace Ui {
class RentalsWindow;
}

class RentalsWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit RentalsWindow(QWidget *parent = nullptr);
    ~RentalsWindow(void);
    bool getDebugMode(void);
    void setDebugMode(bool d);
    QString getQuery(void);
    void setQuery(QString q);
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    /* user clicked "Add Film for Rent" button from Rentals window */
    void on_rentalAddNew_clicked(void);
    /* Whenever the text for the "Title of Film" text box is changed */
    void on_rentalFilmTitle_textChanged(const QString &arg1);
    /* User pressed Return after editing "Title of Film" box from Rentals window */
    void on_rentalFilmTitle_returnPressed(void);
    /* user clicked "Edit Film" button from Rentals window */
    void on_rentalEdit_clicked(void);
    /* user clicked "Return" button from Rentals window */
    void on_rentalReturn_clicked(void);
private:
    Ui::RentalsWindow *ui;
    QString query;
    bool debugMode;
signals:
    void closing(void);
};

#endif // RENTALSWINDOW_H
