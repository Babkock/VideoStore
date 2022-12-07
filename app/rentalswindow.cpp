/* rentalswindow.cpp
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
#include "database.h"
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
    form = new RentalsForm(this);
    form->show();
    if (debugMode)
        std::cout << "Add new Film for Rent was clicked" << std::endl;
}

/* Whenever the text for the "Title of Film" box is changed */
void RentalsWindow::on_rentalTitleField_textChanged(const QString &arg1) {
    setQuery(arg1);
    if (debugMode)
        std::cout << "Text was changed: " << arg1.toStdString() << std::endl;
}

/* User pressed Return after editing "Title of Film" box from Rentals window
 * This should do the same thing as on_rentalEdit_clicked() */
void RentalsWindow::on_rentalTitleField_returnPressed(void) {
    /* do nothing if the text box is empty */
    QString qtitle = ui->rentalTitleField->text();
    int qid = ui->rentalIdField->text().toInt();
    QSqlQuery i, t;

    if ((qtitle.length() == 0) && (qid == 0))
        return;
    /* else, query the database */
    else if (qid != 0) {
        i.prepare("SELECT * FROM `filmrent` WHERE `id`=?");
        i.addBindValue(qid);
        if (!(i.exec())) {
            std::cerr << i.lastError().number() << " Error during ID select: " << i.lastError().text().toStdString() << std::endl;
            return;
        }
        if (i.first()) {
            form = new RentalsForm((unsigned int)i.value(0).toInt(), i.value(1).toString(), i.value(2).toString(), (unsigned int)i.value(3).toInt(), i.value(4).toDouble());
            form->show();
        } else {
            std::cerr << "Film with ID " << qid << " not found" << std::endl;
            return;
        }
    }
    else if (qtitle.length() != 0) {
        t.prepare("SELECT * FROM `filmrent` WHERE `title` LIKE ? LIMIT 1");
        t.addBindValue("%" + qtitle + "%");
        if (!(t.exec())) {
            std::cerr << t.lastError().number() << " Error during Title select: " << t.lastError().text().toStdString() << std::endl;
            return;
        }
        if (t.first()) {
            form = new RentalsForm((unsigned int)i.value(0).toInt(), i.value(1).toString(), i.value(2).toString(), (unsigned int)i.value(3).toInt(), i.value(4).toDouble());
            form->show();
        } else {
            std::cerr << "Film with title '" << qtitle.toStdString() << "' not found" << std::endl;
            return;
        }
    }
}

/* user clicked "Find Film to Edit" button from Rentals window
 * This should do the same thing as on_rentalFilmTitle_returnPressed() */
void RentalsWindow::on_rentalEdit_clicked(void) {
    QString qtitle = ui->rentalTitleField->text();
    int qid = ui->rentalIdField->text().toInt();
    QSqlQuery i, t;

    if ((qtitle.length() == 0) && (qid == 0))
        return;
    else if (qid != 0) {
        i.prepare("SELECT * FROM `filmrent` WHERE `id`=?");
        i.addBindValue(qid);
        if (!(i.exec())) {
            std::cerr << i.lastError().number() << " Error during ID select: " << i.lastError().text().toStdString() << std::endl;
            return;
        }
        if (i.first()) {
            form = new RentalsForm((unsigned int)i.value(0).toInt(), i.value(1).toString(), i.value(2).toString(), (unsigned int)i.value(3).toInt(), i.value(4).toDouble());
            form->show();
        } else {
            std::cerr << "Film with ID " << qid << " not found" << std::endl;
        }
    }
    else if (qtitle.length() != 0) {
        t.prepare("SELECT * FROM `filmrent` WHERE `title` LIKE ?");
        t.addBindValue("%" + qtitle + "%");
        if (!(t.exec())) {
            std::cerr << t.lastError().number() << " Error during Title select: " << t.lastError().text().toStdString() << std::endl;
            return;
        }
        if (t.first()) {
            form = new RentalsForm((unsigned int)i.value(0).toInt(), i.value(1).toString(), i.value(2).toString(), (unsigned int)i.value(3).toInt(), i.value(4).toDouble());
            form->show();
        } else {
            std::cerr << "Film with title '" << qtitle.toStdString() << "' not found" << std::endl;
        }
    }
}

/* user clicked "Return" button from Rentals window */
void RentalsWindow::on_rentalReturn_clicked(void) {
    emit closing();
    hide();
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
    if (debugMode)
        std::cout << "Value was changed: " << arg1 << std::endl;
}

/* Whenever the text in the "Title of Film" box on Rentals is edited */
void RentalsWindow::on_rentalTitleField_textEdited(const QString &arg1) {
    query = arg1;
    if (debugMode)
        std::cout << "Text was edited: " << arg1.toStdString() << std::endl;
}

/* user has finished editing the "or by ID:" field on Rentals */
void RentalsWindow::on_rentalIdField_editingFinished(void) {

}
