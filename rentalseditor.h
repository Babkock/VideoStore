#ifndef RENTALSEDITOR_H
#define RENTALSEDITOR_H

#include <QMainWindow>

namespace Ui {
class RentalsEditor;
}

class RentalsEditor : public QMainWindow {
    Q_OBJECT
public:
    explicit RentalsEditor(QWidget *parent = nullptr);
    explicit RentalsEditor(QWidget *f, QWidget *parent = nullptr);
    ~RentalsEditor(void);
protected:
    void closeEvent(QCloseEvent *event);
private:
    Ui::RentalsEditor *ui;
    QWidget *form;
    QMainWindow *parent;
signals:
    void closing(void);
};

#endif // RENTALSEDITOR_H
