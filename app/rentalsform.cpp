/* rentalsform.cpp
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
#include "film.h"
#include "rentalsform.h"
#include "ui_rentalsform.h"
#include "rentalswindow.h"
#include "ui_rentalswindow.h"
#include <iostream>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>

RentalsForm::RentalsForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RentalsForm),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Rentals");
    ui->rentalsHeaderText->setText("Adding New Film to Rentals");
}

RentalsForm::RentalsForm(void) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film("Title", "Director"))),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Rentals");
    ui->rentalsHeaderText->setText("Adding New Film to Rentals");
    ui->rentalsSaveChanges->setEnabled(false);
}

RentalsForm::RentalsForm(Film f) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(f.getId(), f.getTitle(), f.getDirector(), f.getYear(), f.getPrice()))),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Rentals");
    ui->rentalsHeaderText->setText("Adding New Film to Rentals");
    ui->rentalsTitleField->setText(f.getTitle());
    ui->rentalsDirectorField->setText(f.getDirector());
    ui->rentalsYearField->setValue((int)f.getYear());
    ui->rentalsPriceField->setValue(f.getPrice());
    ui->rentalsSaveChanges->setEnabled(false);
}

RentalsForm::RentalsForm(Film f, unsigned int q) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(f.getId(), f.getTitle(), f.getDirector(), f.getYear(), f.getPrice()), q)),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Rentals");
    ui->rentalsHeaderText->setText("Adding New Film to Rentals");
    ui->rentalsTitleField->setText(f.getTitle());
    ui->rentalsDirectorField->setText(f.getDirector());
    ui->rentalsYearField->setValue((int)f.getYear());
    ui->rentalsPriceField->setValue(f.getPrice());
    ui->rentalsQuantityField->setValue((int)q);
}

RentalsForm::RentalsForm(Film f, unsigned int q, unsigned int a) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(f.getId(), f.getTitle(), f.getDirector(), f.getYear(), f.getPrice()), q, a)),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Rentals");
    ui->rentalsHeaderText->setText("Adding New Film to Rentals");
    ui->rentalsIdField->setValue(f.getId());
    ui->rentalsTitleField->setText(f.getTitle());
    ui->rentalsDirectorField->setText(f.getDirector());
    ui->rentalsYearField->setValue((int)f.getYear());
    ui->rentalsPriceField->setValue(f.getPrice());
    ui->rentalsQuantityField->setValue((int)q);
    ui->rentalsAvailableField->setValue((int)a);
}

RentalsForm::RentalsForm(Film f, const char *l) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(f.getId(), f.getTitle(), f.getDirector(), f.getYear(), f.getPrice()), l)) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Rentals");
    ui->rentalsHeaderText->setText("Adding New Film to Rentals");
    ui->rentalsIdField->setValue(f.getId());
    ui->rentalsTitleField->setText(f.getTitle());
    ui->rentalsDirectorField->setText(f.getDirector());
    ui->rentalsYearField->setValue((int)f.getYear());
    ui->rentalsPriceField->setValue(f.getPrice());
    ui->rentalsLastRentedTo->setText((QString)l);
}

RentalsForm::RentalsForm(Film f, const QString &l) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(f.getId(), f.getTitle(), f.getDirector(), f.getYear(), f.getPrice()), l)) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Rentals");
    ui->rentalsHeaderText->setText("Adding New Film to Rentals");
    ui->rentalsTitleField->setText(f.getTitle());
    ui->rentalsDirectorField->setText(f.getDirector());
    ui->rentalsYearField->setValue((int)f.getYear());
    ui->rentalsPriceField->setValue(f.getPrice());
    ui->rentalsLastRentedTo->setText(l);
}

RentalsForm::RentalsForm(Film f, QDateTime l) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(f.getId(), f.getTitle(), f.getDirector(), f.getYear(), f.getPrice()), l)),
    editExisting(true) {
    ui->setupUi(this);
    char head[32];
    sprintf(head, "Editing Film Rental #%d", f.getId());
    this->setWindowTitle(head);
    ui->rentalsHeaderText->setText(head);
    ui->rentalsIdField->setValue(f.getId());
    ui->rentalsTitleField->setText(f.getTitle());
    ui->rentalsDirectorField->setText(f.getDirector());
    ui->rentalsYearField->setValue(int(f.getYear()));
    ui->rentalsPriceField->setValue(f.getPrice());
    ui->rentalsLastRentedField->setDateTime(l);
}

RentalsForm::RentalsForm(const QString &t) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(t, "Director"))),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Rentals");
    ui->rentalsHeaderText->setText("Adding New Film to Rentals");
    ui->rentalsTitleField->setText(t);
    ui->rentalsSaveChanges->setEnabled(false);
}

RentalsForm::RentalsForm(const QString &t, const QString &d) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(t, d))),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Inventory");
    ui->rentalsHeaderText->setText("Adding New Film to Inventory");
    ui->rentalsTitleField->setText(t);
    ui->rentalsDirectorField->setText(d);
    ui->rentalsSaveChanges->setEnabled(false);
}

RentalsForm::RentalsForm(const QString &t, unsigned int y) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(t, "Director", y))),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Inventory");
    ui->rentalsHeaderText->setText("Adding New Film to Inventory");
    ui->rentalsTitleField->setText(t);
    ui->rentalsYearField->setValue((int)y);
    ui->rentalsSaveChanges->setEnabled(false);
}

RentalsForm::RentalsForm(const QString &t, const QString &d, unsigned int y) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(t, d, y))),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Inventory");
    ui->rentalsHeaderText->setText("Adding New Film to Inventory");
    ui->rentalsTitleField->setText(t);
    ui->rentalsDirectorField->setText(d);
    ui->rentalsYearField->setValue((int)y);
    ui->rentalsSaveChanges->setEnabled(false);
}

RentalsForm::RentalsForm(const QString &t, unsigned int y, double p) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(t, "Director", y, p))),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Inventory");
    ui->rentalsHeaderText->setText("Adding New Film to Inventory");
    ui->rentalsTitleField->setText(t);
    ui->rentalsYearField->setValue((int)y);
    ui->rentalsPriceField->setValue(p);
    ui->rentalsSaveChanges->setEnabled(false);
}

RentalsForm::RentalsForm(unsigned int id, const QString &t) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(id, t, "Director"))),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Inventory");
    ui->rentalsHeaderText->setText("Adding New Film to Inventory");
    ui->rentalsTitleField->setText(t);
    ui->rentalsSaveChanges->setEnabled(false);
}

RentalsForm::RentalsForm(unsigned int id, const char *t) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(id, t, "Director"))),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Inventory");
    ui->rentalsHeaderText->setText("Adding New Film to Inventory");
    ui->rentalsIdField->setValue(id);
    ui->rentalsTitleField->setText(QString(t));
    ui->rentalsSaveChanges->setEnabled(false);
}

RentalsForm::RentalsForm(unsigned int id, const QString &t, const QString &d) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(id, t, d))),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Inventory");
    ui->rentalsHeaderText->setText("Adding New Film to Inventory");
    ui->rentalsIdField->setValue(id);
    ui->rentalsTitleField->setText(t);
    ui->rentalsDirectorField->setText(d);
    ui->rentalsSaveChanges->setEnabled(false);
}

RentalsForm::RentalsForm(unsigned int id, const char *t, const char *d) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(id, t, d))),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Inventory");
    ui->rentalsHeaderText->setText("Adding New Film to Inventory");
    ui->rentalsIdField->setValue(id);
    ui->rentalsTitleField->setText(QString(t));
    ui->rentalsDirectorField->setText(QString(d));
    ui->rentalsSaveChanges->setEnabled(false);
}

RentalsForm::RentalsForm(unsigned int id, const QString &t, const QString &d, unsigned int y) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(id, t, d, y))),
    editExisting(true) {
    ui->setupUi(this);
    char head[32];
    sprintf(head, "Editing Film Rental #%d", id);
    this->setWindowTitle(head);
    ui->rentalsHeaderText->setText(head);
    ui->rentalsIdField->setValue(id);
    ui->rentalsTitleField->setText(t);
    ui->rentalsDirectorField->setText(d);
    ui->rentalsYearField->setValue(int(y));
    ui->rentalsSaveChanges->setEnabled(false);
}

RentalsForm::RentalsForm(unsigned int id, const char *t, const char *d, unsigned int y) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(id, t, d, y))),
    editExisting(true) {
    ui->setupUi(this);
    char head[32];
    sprintf(head, "Editing Film Rental #%d", id);
    this->setWindowTitle(head);
    ui->rentalsHeaderText->setText(head);
    ui->rentalsIdField->setValue(id);
    ui->rentalsTitleField->setText(QString(t));
    ui->rentalsDirectorField->setText(QString(d));
    ui->rentalsYearField->setValue(int(y));
    ui->rentalsSaveChanges->setEnabled(false);
}

RentalsForm::RentalsForm(unsigned int id, const QString &t, const QString &d, unsigned int y, double p) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(id, t, d, y, p))),
    editExisting(true) {
    ui->setupUi(this);
    char head[32];
    sprintf(head, "Editing Film Rental #%d", id);
    this->setWindowTitle(head);
    ui->rentalsHeaderText->setText(head);
    ui->rentalsIdField->setValue(id);
    ui->rentalsTitleField->setText(t);
    ui->rentalsDirectorField->setText(d);
    ui->rentalsYearField->setValue(int(y));
    ui->rentalsPriceField->setValue(p);
    ui->rentalsSaveChanges->setEnabled(false);
}

RentalsForm::RentalsForm(unsigned int id, const char *t, const char *d, unsigned int y, double p) :
    ui(new Ui::RentalsForm),
    film(FilmRent(Film(id, t, d, y, p))),
    editExisting(true) {
    ui->setupUi(this);
    char head[32];
    sprintf(head, "Editing Film Rental #%d", id);
    this->setWindowTitle(head);
    ui->rentalsHeaderText->setText(head);
    ui->rentalsIdField->setValue(id);
    ui->rentalsTitleField->setText(QString(t));
    ui->rentalsDirectorField->setText(QString(d));
    ui->rentalsYearField->setValue(int(y));
    ui->rentalsPriceField->setValue(p);
    ui->rentalsSaveChanges->setEnabled(false);
}

RentalsForm::~RentalsForm(void) {
    delete ui;
}

void RentalsForm::closeEvent(QCloseEvent *event) {
    emit closing();
    event->accept();
    close();
}

/* user changed text of "Title of Film" field */
void RentalsForm::on_rentalsTitleField_textChanged(const QString &arg1) {
    film.setTitle(arg1);
    ui->rentalsSaveChanges->setEnabled(true);
    if (debugMode)
        std::cout << "Title changed: " << arg1.toStdString() << std::endl;
}

/* user changed text of "Director of Film" field */
void RentalsForm::on_rentalsDirectorField_textChanged(const QString &arg1) {
    film.setDirector(arg1);
    ui->rentalsSaveChanges->setEnabled(true);
    if (debugMode)
        std::cout << "Director changed: " << arg1.toStdString() << std::endl;
}

/* the value of the "Price" input field was changed */
void RentalsForm::on_rentalsPriceField_valueChanged(double arg1) {
    film.setPrice(arg1);
    ui->rentalsSaveChanges->setEnabled(true);
    if (debugMode)
        std::cout << "Price changed: " << arg1 << std::endl;
}

/* the value of the "Year" input field was changed */
void RentalsForm::on_rentalsYearField_valueChanged(int arg1) {
    film.setYear((unsigned int)arg1);
    ui->rentalsSaveChanges->setEnabled(true);
    if (debugMode)
        std::cout << "Year changed: " << arg1 << std::endl;
}

/* user changed value of "Quantity" field */
void RentalsForm::on_rentalsQuantityField_valueChanged(int arg1) {
    film.setQuantity((unsigned int)arg1);
    ui->rentalsSaveChanges->setEnabled(true);
    if (debugMode)
        std::cout << "Quantity changed: " << arg1 << std::endl;
}

/* user changed value of "Available" field */
void RentalsForm::on_rentalsAvailableField_valueChanged(int arg1) {
    film.setAvailable((unsigned int)arg1);
    ui->rentalsSaveChanges->setEnabled(true);
    if (debugMode)
        std::cout << "Available changed: " << arg1 << std::endl;
}

/* user selected a date for "Last Rented" field */
void RentalsForm::on_rentalsLastRentedField_dateTimeChanged(const QDateTime &dateTime) {
    film.setLastRented(dateTime);
    ui->rentalsSaveChanges->setEnabled(true);
    if (debugMode)
        std::cout << "Set last rented: " << dateTime.toString("yyyy-MM-dd hh:mm:ss").toStdString() << std::endl;
}

/* user changed text of "Last Rented to" field */
void RentalsForm::on_rentalsLastRentedTo_textChanged(const QString &arg1) {
    film.setLastRentedTo(arg1);
    ui->rentalsSaveChanges->setEnabled(true);
    if (debugMode)
        std::cout << "Last Rented to changed: " << arg1.toStdString() << std::endl;
}

/* user clicked on "Save Changes to Film" button */
void RentalsForm::on_rentalsSaveChanges_clicked(void) {
    if (editExisting) {
        QSqlQuery update;
        update.prepare("UPDATE `filmrent` SET `title`=?, `director`=?, `year`=?, `added`=?, `price`=?, `quantity`=?, `available`=?, `lastRentedTo`=? WHERE `id`=? LIMIT 1");
        update.addBindValue(film.getTitle());
        update.addBindValue(film.getDirector());
        update.addBindValue(film.getYear());
        update.addBindValue(film.getAdded().toString("yyyy-MM-dd hh:mm:ss"));
        update.addBindValue(film.getPrice());
        update.addBindValue(film.getQuantity());
        update.addBindValue(film.getAvailable());
        update.addBindValue(film.getLastRentedTo());
        update.addBindValue(film.getId());
        if (!(update.exec())) {
            std::cerr << update.lastError().nativeErrorCode().toStdString() << " Error during update: " << update.lastError().text().toStdString() << std::endl;
        }
        else {
            if (debugMode)
                std::cout << "Successfully updated filmrent #" << film.getId() << std::endl;
            else
                std::cout << "Successfully updated film rental '" << film.getTitle().toStdString() << "'" << std::endl;
        }
        db.commit();
        emit closing();
        hide();
    } else {
        QSqlQuery c;
        int newid = c.prepare("SELECT COUNT(*) FROM `filmrent`");
        c.exec();
        newid++;
        film.setId(newid);

        QSqlQuery ins;
        ins.prepare("INSERT INTO `filmrent` (`id`, `title`, `director`, `year`, `price`, `added`, `quantity`, `available`, `lastRentedTo`, `lastRented`) VALUES (NULL, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
        ins.addBindValue(film.getTitle());
        ins.addBindValue(film.getDirector());
        ins.addBindValue(film.getYear());
        ins.addBindValue(film.getPrice());
        ins.addBindValue(film.getAdded().toString("yyyy-MM-dd hh:mm:ss"));
        ins.addBindValue(film.getQuantity());
        ins.addBindValue(film.getAvailable());
        ins.addBindValue(film.getLastRentedTo());
        ins.addBindValue(film.getLastRented());
        if (!(ins.exec())) {
            std::cerr << ins.lastError().nativeErrorCode().toStdString() << " Error during insert: " << ins.lastError().text().toStdString() << std::endl;
        }
        else {
            if (debugMode)
                std::cout << "Successfully inserted filmrent #" << film.getId() << std::endl;
            else
                std::cout << "Successfully added film rental '" << film.getTitle().toStdString() << "'" << std::endl;
        }
        db.commit();
        emit closing();
        hide();
    }
}

/* user clicked on "Discard Changes" button */
void RentalsForm::on_rentalsDiscardChanges_clicked(void) {
    emit closing();
    hide();
}

/* user pressed Return after editing "Title of Film" field */
void RentalsForm::on_rentalsTitleField_returnPressed(void) {
    if (debugMode)
        std::cout << "Pressed Return on Title" << std::endl;
}

/* user pressed Return after editing "Director of Film" field */
void RentalsForm::on_rentalsDirectorField_returnPressed(void) {
    if (debugMode)
        std::cout << "Pressed Return on Director" << std::endl;
}

/* user pressed Return after editing "Last Rented to" field */
void RentalsForm::on_rentalsLastRentedTo_returnPressed(void) {
    if (debugMode)
        std::cout << "Pressed Return on Last Rented to" << std::endl;
}

