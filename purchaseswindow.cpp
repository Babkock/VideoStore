/* purchaseswindow.cpp
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
#include "main.h"
#include "rentalswindow.h"
#include "purchaseswindow.h"
#include "ui_purchaseswindow.h"
#include "purchasesform.h"
#include "ui_purchasesform.h"
#include <iostream>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

PurchasesWindow::PurchasesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PurchasesWindow),
    query((QString)"Title of Film Here"),
    id(0) {
    ui->setupUi(this);
}

PurchasesWindow::PurchasesWindow(QWidget *parent, QMainWindow *form) :
    QMainWindow(parent),
    ui(new Ui::PurchasesWindow),
    form(form),
    query(QString("Title of Film Here")),
    id(0) {
    ui->setupUi(this);
}

PurchasesWindow::~PurchasesWindow(void) {
    delete form;
    delete ui;
}

void PurchasesWindow::closeEvent(QCloseEvent *event) {
    emit closing();
    event->accept();
}

/* user clicked "Add Film for Purchase" from Purchases window */
void PurchasesWindow::on_purchaseAddNew_clicked(void) {
    /* bring up empty PurchasesForm */
    form = new PurchasesForm(this);
    form->show();
    if (debugMode)
        std::cout << "Add new Film for Purchase was clicked" << std::endl;
}

/* Whenever the text for the "Title of Film" field on Purchases is changed */
void PurchasesWindow::on_purchaseTitleField_textChanged(const QString &arg1) {
    if (debugMode)
        std::cout << "Text was changed: " << arg1.toStdString() << std::endl;
}

/* user pressed Return after editing "Title of Film" box from Purchases
 * This should do the same thing as on_purchaseEdit_clicked() */
void PurchasesWindow::on_purchaseTitleField_returnPressed(void) {
    QString qtitle = ui->purchaseTitleField->text();
    int qid = ui->purchaseIdField->text().toInt();
    QSqlQuery i, t;

    if ((qtitle.length() == 0) && (qid == 0))
        return;
    else if (qid != 0) {

    }
    else if (qtitle.length() != 0) {

    }
}

/* user clicked "Find Film to Edit" button from Purchases
 * This should do the same thing as on_rentalFilmTitle_returnPressed() */
void PurchasesWindow::on_purchaseEdit_clicked(void) {
    QString qtitle = ui->purchaseTitleField->text();
    int qid = ui->purchaseIdField->text().toInt();
    QSqlQuery i, t;

    if ((qtitle.length() == 0) && (qid == 0))
        return;
    else if (qid != 0) {
        i.prepare("SELECT * FROM `filmsale` WHERE `id`=?");
        i.addBindValue(qid);
        if (!(i.exec())) {
            std::cerr << i.lastError().nativeErrorCode().toStdString() << " Error during ID select: " << i.lastError().text().toStdString() << std::endl;
            return;
        }
        if (i.first()) {
            form = new PurchasesForm((unsigned int)i.value(0).toInt(), i.value(1).toString(), i.value(2).toString(), (unsigned int)i.value(3).toInt(), i.value(4).toDouble());
            form->show();
        } else {
            std::cerr << "Film with ID " << qid << " not found" << std::endl;
        }
    }
    else if (qtitle.length() != 0) {
        t.prepare("SELECT * FROM `filmsale` WHERE `title` LIKE ?");
        t.addBindValue("%" + qtitle + "%");
        if (!(t.exec())) {
            std::cerr << t.lastError().nativeErrorCode().toStdString() << " Error during Title select: " << t.lastError().text().toStdString() << std::endl;
            return;
        }
        if (t.first()) {
            form = new PurchasesForm((unsigned int)i.value(0).toInt(), i.value(1).toString(), i.value(2).toString(), (unsigned int)i.value(3).toInt(), i.value(4).toDouble());
            form->show();
        } else {
            std::cerr << "Film with Title '" << qtitle.toStdString() << "' not found" << std::endl;
        }
    }
}

/* user clicked "Return" button from Purchases */
void PurchasesWindow::on_purchaseReturn_clicked(void) {
    emit closing();
    close();
}

QString PurchasesWindow::getQuery(void) {
    return query;
}

void PurchasesWindow::setQuery(QString q) {
    query = q;
}

unsigned int PurchasesWindow::getId(void) {
    return id;
}

void PurchasesWindow::setId(unsigned int i) {
    id = i;
}

/* the value of "or by ID:" field on Purchases was changed */
void PurchasesWindow::on_purchaseIdField_valueChanged(int arg1) {
    id = (unsigned int)arg1;
    if (debugMode)
        std::cout << "Value was changed: " << arg1 << std::endl;
}

/* Whenever the text in the "Title of Film" field is edited */
void PurchasesWindow::on_purchaseTitleField_textEdited(const QString &arg1) {
    query = arg1;
    if (debugMode)
        std::cout << "Text was edited: " << arg1.toStdString() << std::endl;
}

/* user is finished editing the "or by ID:" field on Purchases */
void PurchasesWindow::on_purchaseIdField_editingFinished(void) {

}

