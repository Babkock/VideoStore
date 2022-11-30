#ifndef RENTALSEDITOR_H
#define RENTALSEDITOR_H

#include <QMainWindow>
#include <QWidget>

namespace Ui {
class RentalsEditor;
}

class RentalsEditor : public QMainWindow {
    Q_OBJECT
public:
    explicit RentalsEditor(QWidget *parent = nullptr);
    explicit RentalsEditor(QWidget *f, QWidget *parent = nullptr);
    ~RentalsEditor(void);
    QWidget *getForm(void);
    void setForm(QWidget *f);
    //QMainWindow *getExitMessage(void);
    //void setExitMessage(QMainWindow *e);
protected:
    void closeEvent(QCloseEvent *event);
    QMainWindow *exitMessage;
private:
    Ui::RentalsEditor *ui;
    QWidget *form;
    QMainWindow *parent;
signals:
    void closing(void);
private slots:
    void on_rentalEditorExit_clicked(void);
};

#endif // RENTALSEDITOR_H
