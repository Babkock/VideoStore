/* rentalswindow.cpp
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
#include "rentalswindow.h"
#include "ui_rentalswindow.h"
#include "rentalsform.h"
#include "ui_rentalsform.h"
#include <iostream>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

RentalsWindow::RentalsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RentalsWindow),
    query(QString("Title of Film Here")),
    id(0) {
    ui->setupUi(this);
}

RentalsWindow::RentalsWindow(QWidget *parent, QMainWindow *form):
    QMainWindow(parent),
    ui(new Ui::RentalsWindow),
    form(form),
    query(QString("Title of Film Here")),
    id(0) {
    ui->setupUi(this);
    connect(form, SIGNAL(closing()), this, SLOT(show()));
}

RentalsWindow::~RentalsWindow(void) {
    delete form;
    delete ui;
}

void RentalsWindow::closeEvent(QCloseEvent *event) {
    emit closing();
    event->accept();
}

/* user clicked "Add Film for Rent" from Rentals window */
void RentalsWindow::on_rentalAddNew_clicked(void) {
    /* bring up empty RentalsForm */
    form = new RentalsForm(0, "Title", "Director", 1950, 5.00);
    form->show();
    std::cout << "Add new Film for Rent was clicked" << std::endl;
}

/* Whenever the text for the "Title of Film" box is changed */
void RentalsWindow::on_rentalTitleField_textChanged(const QString &arg1) {
    setQuery(arg1);
    std::cout << "Text was changed: " << arg1.toStdString() << std::endl;
}

/* User pressed Return after editing "Title of Film" box from Rentals window
 * This should do the same thing as on_rentalEdit_clicked() */
void RentalsWindow::on_rentalTitleField_returnPressed(void) {
    /* do nothing if the text box is empty */
    QString qtitle = this->ui->rentalTitleField->text();
    int qid = this->ui->rentalIdField->text().toInt();
    QSqlQuery i, t;

    if ((qtitle.length() == 0) && (qid == 0))
        return;
    /* else, query the database */
    else if (qid != 0) {
        i.prepare("SELECT * FROM `filmrent` WHERE `id`=?");
        i.addBindValue(qid);
        i.exec();
        if (i.first()) {
            form = new RentalsForm((unsigned int)i.value(0).toInt(), i.value(1).toString(), i.value(2).toString(), (unsigned int)i.value(3).toInt(), i.value(4).toDouble());
            form->show();
        } else {
            std::cout << "Film with ID " << qid << " not found" << std::endl;
            return;
        }
    }
    else if (qtitle.length() != 0) {
        t.prepare("SELECT * FROM `filmrent` WHERE `title`=?");
        t.addBindValue(qtitle);
        t.exec();
        if (t.first()) {
            form = new RentalsForm((unsigned int)i.value(0).toInt(), i.value(1).toString(), i.value(2).toString(), (unsigned int)i.value(3).toInt(), i.value(4).toDouble());
            form->show();
        } else {
            std::cout << "Film with title '" << qtitle.toStdString() << "' not found" << std::endl;
            return;
        }
    }
}

/* user clicked "Find Film to Edit" button from Rentals window
 * This should do the same thing as on_rentalFilmTitle_returnPressed() */
void RentalsWindow::on_rentalEdit_clicked(void) {
    QString qtitle = this->ui->rentalTitleField->text();
    int qid = this->ui->rentalIdField->text().toInt();
    QSqlQuery i, t;

    if ((qtitle.length() == 0) && (qid == 0))
        return;
    else if (qid != 0) {
        i.prepare("SELECT * FROM `filmrent` WHERE `id`=?");
        i.addBindValue(qid);
        i.exec();
        if (i.first()) {
            form = new RentalsForm((unsigned int)i.value(0).toInt(), i.value(1).toString(), i.value(2).toString(), (unsigned int)i.value(3).toInt(), i.value(4).toDouble());
            form->show();
        } else {
            std::cout << "Film with ID " << qid << " not found" << std::endl;
            return;
        }
    }
    else if (qtitle.length() != 0) {
        t.prepare("SELECT * FROM `filmrent` WHERE `title`=?");
        t.addBindValue(qtitle);
        t.exec();
        if (t.first()) {
            form = new RentalsForm((unsigned int)i.value(0).toInt(), i.value(1).toString(), i.value(2).toString(), (unsigned int)i.value(3).toInt(), i.value(4).toDouble());
            form->show();
        } else {
            std::cout << "Film with title '" << qtitle.toStdString() << "' not found" << std::endl;
            return;
        }
    }
}

/* user clicked "Return" button from Rentals window */
void RentalsWindow::on_rentalReturn_clicked(void) {
    emit closing();
    hide();
}

bool RentalsWindow::getDebugMode(void) {
    return debugMode;
}

void RentalsWindow::setDebugMode(bool d) {
    debugMode = d;
}

QString RentalsWindow::getQuery(void) {
    return query;
}

void RentalsWindow::setQuery(QString q) {
    query = q;
}

/* the value of "or by ID:" box has changed */
void RentalsWindow::on_rentalIdField_valueChanged(int arg1) {
    id = (unsigned int)arg1;
    std::cout << "Value was changed: " << arg1 << std::endl;
}

/* Whenever the text in the "Title of Film" box on Rentals is edited */
void RentalsWindow::on_rentalTitleField_textEdited(const QString &arg1) {
    query = arg1;
    std::cout << "Text was edited: " << arg1.toStdString() << std::endl;
}

/* user has finished editing the "or by ID:" field on Rentals */
void RentalsWindow::on_rentalIdField_editingFinished(void) {

}
