/* purchasesform.cpp
 * Tanner Babcock
 * CIS 152 - Data Structures
 * Final Project: Video Store
 * November - December 2022
 * https://github.com/Babkock/VideoStore
*/
#include "main.h"
#include "film.h"
#include <iostream>
#include "purchasesform.h"
#include "ui_purchasesform.h"
#include "purchaseswindow.h"
#include "ui_purchaseswindow.h"

PurchasesForm::PurchasesForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PurchasesForm),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Purchases");
    ui->purchasesHeaderText->setText("Adding New Film to Purchases");
}

PurchasesForm::PurchasesForm(void) :
    ui(new Ui::PurchasesForm),
    film(FilmSale(Film("Title", "Director"))),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Purchases");
    ui->purchasesHeaderText->setText("Adding New Film to Purchases");
    ui->purchasesSaveChanges->setEnabled(false);
}

PurchasesForm::PurchasesForm(Film f):
    ui(new Ui::PurchasesForm),
    film(FilmSale(Film(f.getId(), f.getTitle(), f.getDirector(), f.getYear(), f.getPrice()))),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Purchases");
    ui->purchasesHeaderText->setText("Adding New Film to Purchases");
    ui->purchasesTitleField->setText(f.getTitle());
    ui->purchasesDirectorField->setText(f.getDirector());
    ui->purchasesYearField->setValue((int)f.getYear());
    ui->purchasesPriceField->setValue(f.getPrice());
    ui->purchasesSaveChanges->setEnabled(false);
}

PurchasesForm::PurchasesForm(Film f, unsigned int q):
    ui(new Ui::PurchasesForm),
    film(FilmSale(Film(f.getId(), f.getTitle(), f.getDirector(), f.getYear(), f.getPrice()), q)),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Purchases");
    ui->purchasesHeaderText->setText("Adding New Film to Purchases");
    ui->purchasesTitleField->setText(f.getTitle());
    ui->purchasesDirectorField->setText(f.getDirector());
    ui->purchasesYearField->setValue((int)f.getYear());
    ui->purchasesPriceField->setValue(f.getPrice());
    ui->purchasesQuantityField->setValue((int)q);
    ui->purchasesSaveChanges->setEnabled(false);
}

PurchasesForm::PurchasesForm(Film f, const char *l):
    ui(new Ui::PurchasesForm),
    film(FilmSale(Film(f.getId(), f.getTitle(), f.getDirector(), f.getYear(), f.getPrice()), l)),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Purchases");
    ui->purchasesHeaderText->setText("Adding New Film to Purchases");
    ui->purchasesTitleField->setText(f.getTitle());
    ui->purchasesDirectorField->setText(f.getDirector());
    ui->purchasesYearField->setValue((int)f.getYear());
    ui->purchasesPriceField->setValue(f.getPrice());
    ui->purchasesLastSoldTo->setText((QString)l);
    ui->purchasesSaveChanges->setEnabled(false);
}

PurchasesForm::PurchasesForm(Film f, const QString &l):
    ui(new Ui::PurchasesForm),
    film(FilmSale(Film(f.getId(), f.getTitle(), f.getDirector(), f.getYear(), f.getPrice()), l)),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Purchases");
    ui->purchasesHeaderText->setText("Adding New Film to Purchases");
    ui->purchasesTitleField->setText(f.getTitle());
    ui->purchasesDirectorField->setText(f.getDirector());
    ui->purchasesYearField->setValue((int)f.getYear());
    ui->purchasesPriceField->setValue(f.getPrice());
    ui->purchasesLastSoldTo->setText(l);
    ui->purchasesSaveChanges->setEnabled(false);
}

PurchasesForm::PurchasesForm(Film f, QDateTime l):
    ui(new Ui::PurchasesForm),
    film(FilmSale(Film(f.getId(), f.getTitle(), f.getDirector(), f.getYear(), f.getPrice()), l)),
    editExisting(true) {
    ui->setupUi(this);
    char head[32];
    sprintf(head, "Editing Film Purchase #%d", f.getId());
    this->setWindowTitle(head);
    ui->purchasesHeaderText->setText(head);
    ui->purchasesTitleField->setText(f.getTitle());
    ui->purchasesDirectorField->setText(f.getDirector());
    ui->purchasesYearField->setValue((int)f.getYear());
    ui->purchasesPriceField->setValue(f.getPrice());
    ui->purchasesLastSoldField->setDateTime(l);
    ui->purchasesSaveChanges->setEnabled(false);
}

PurchasesForm::PurchasesForm(unsigned int id, const QString &t):
    ui(new Ui::PurchasesForm),
    film(FilmSale(Film(id, t, "Director"))),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Purchases");
    ui->purchasesIdField->setValue((int)id);
    ui->purchasesHeaderText->setText("Adding New Film to Purchases");
    ui->purchasesTitleField->setText(t);
    ui->purchasesSaveChanges->setEnabled(false);
}

PurchasesForm::PurchasesForm(unsigned int id, const char *t):
    ui(new Ui::PurchasesForm),
    film(FilmSale(Film(id, t, "Director"))),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Purchases");
    ui->purchasesIdField->setValue((int)id);
    ui->purchasesHeaderText->setText("Adding New Film to Purchases");
    ui->purchasesTitleField->setText(t);
    ui->purchasesSaveChanges->setEnabled(false);
}

PurchasesForm::PurchasesForm(unsigned int id, const QString &t, const QString &d):
    ui(new Ui::PurchasesForm),
    film(FilmSale(Film(id, t, d))),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Purchases");
    ui->purchasesHeaderText->setText("Adding New Film to Purchases");
    ui->purchasesIdField->setValue((int)id);
    ui->purchasesTitleField->setText(t);
    ui->purchasesDirectorField->setText(d);
    ui->purchasesSaveChanges->setEnabled(false);
}

PurchasesForm::PurchasesForm(unsigned int id, const char *t, const char *d):
    ui(new Ui::PurchasesForm),
    film(FilmSale(Film(id, t, d))),
    editExisting(false) {
    ui->setupUi(this);
    this->setWindowTitle("Adding New Film to Purchases");
    ui->purchasesHeaderText->setText("Adding New Film to Purchases");
    ui->purchasesIdField->setValue((int)id);
    ui->purchasesTitleField->setText((QString)t);
    ui->purchasesDirectorField->setText((QString)d);
    ui->purchasesSaveChanges->setEnabled(false);
}

PurchasesForm::PurchasesForm(unsigned int id, const QString &t, const QString &d, unsigned int y):
    ui(new Ui::PurchasesForm),
    film(FilmSale(Film(id, t, d, y))),
    editExisting(true) {
    ui->setupUi(this);
    char head[32];
    sprintf(head, "Editing Film Purchase #%d", id);
    this->setWindowTitle(head);
    ui->purchasesHeaderText->setText(head);
    ui->purchasesIdField->setValue((int)id);
    ui->purchasesTitleField->setText(t);
    ui->purchasesDirectorField->setText(d);
    ui->purchasesYearField->setValue((int)y);
    ui->purchasesSaveChanges->setEnabled(false);
}

PurchasesForm::PurchasesForm(unsigned int id, const char *t, const char *d, unsigned int y):
    ui(new Ui::PurchasesForm),
    film(FilmSale(Film(id, t, d, y))),
    editExisting(true) {
    ui->setupUi(this);
    char head[32];
    sprintf(head, "Editing Film Purchase #%d", id);
    this->setWindowTitle(head);
    ui->purchasesHeaderText->setText(head);
    ui->purchasesIdField->setValue((int)id);
    ui->purchasesTitleField->setText((QString)t);
    ui->purchasesDirectorField->setText((QString)d);
    ui->purchasesYearField->setValue((int)y);
    ui->purchasesSaveChanges->setEnabled(false);
}

PurchasesForm::PurchasesForm(unsigned int id, const QString &t, const QString &d, unsigned int y, double p):
    ui(new Ui::PurchasesForm),
    film(FilmSale(Film(id, t, d, y, p))),
    editExisting(true) {
    ui->setupUi(this);
    char head[32];
    sprintf(head, "Editing Film Purchase #%d", id);
    this->setWindowTitle(head);
    ui->purchasesHeaderText->setText(head);
    ui->purchasesIdField->setValue((int)id);
    ui->purchasesTitleField->setText((QString)t);
    ui->purchasesDirectorField->setText((QString)d);
    ui->purchasesYearField->setValue((int)y);
    ui->purchasesPriceField->setValue(p);
    ui->purchasesSaveChanges->setEnabled(false);
}

PurchasesForm::PurchasesForm(unsigned int id, const char *t, const char *d, unsigned int y, double p):
    ui(new Ui::PurchasesForm),
    film(FilmSale(Film(id, t, d, y, p))),
    editExisting(true) {
    ui->setupUi(this);
    char head[32];
    sprintf(head, "Editing Film Purchase #%d", id);
    this->setWindowTitle(head);
    ui->purchasesHeaderText->setText(head);
    ui->purchasesIdField->setValue((int)id);
    ui->purchasesTitleField->setText((QString)t);
    ui->purchasesDirectorField->setText((QString)d);
    ui->purchasesYearField->setValue((int)y);
    ui->purchasesPriceField->setValue(p);
    ui->purchasesSaveChanges->setEnabled(false);
}

PurchasesForm::~PurchasesForm(void) {
    delete ui;
}

void PurchasesForm::closeEvent(QCloseEvent *event) {
    emit closing();
    event->accept();
    hide();
}

bool PurchasesForm::getEditExisting(void) {
    return editExisting;
}

void PurchasesForm::setEditExisting(bool e) {
    editExisting = e;
}

/* user clicked on the "Save Changes to Film" button on Purchases */
void PurchasesForm::on_purchasesSaveChanges_clicked(void) {

}

/* user clicked on "Discard Changes" button on Purchases */
void PurchasesForm::on_purchasesDiscardChanges_clicked(void) {
    emit closing();
    hide();
}

/* the text of the "Title of Film" field was changed */
void PurchasesForm::on_purchasesTitleField_textChanged(const QString &arg1) {
    film.setTitle(arg1);
    ui->purchasesSaveChanges->setEnabled(true);
    if (debugMode)
        std::cout << "Title changed: " << arg1.toStdString() << std::endl;
}

/* the text of the "Director of Film" field was changed */
void PurchasesForm::on_purchasesDirectorField_textChanged(const QString &arg1) {
    film.setDirector(arg1);
    ui->purchasesSaveChanges->setEnabled(true);
    if (debugMode)
        std::cout << "Director changed: " << arg1.toStdString() << std::endl;
}

/* the value of "Year" input field was changed */
void PurchasesForm::on_purchasesYearField_valueChanged(int arg1) {
    film.setYear(arg1);
    ui->purchasesSaveChanges->setEnabled(true);
    if (debugMode)
        std::cout << "Year changed: " << arg1 << std::endl;
}

/* the value of "Price" input field was changed */
void PurchasesForm::on_purchasesPriceField_valueChanged(double arg1) {
    film.setPrice(arg1);
    ui->purchasesSaveChanges->setEnabled(true);
    if (debugMode)
        std::cout << "Price changed: $" << arg1 << std::endl;
}

/* the value of "Quantity" input field was changed */
void PurchasesForm::on_purchasesQuantityField_valueChanged(int arg1) {
    film.setQuantity((int)arg1);
    ui->purchasesSaveChanges->setEnabled(true);
    if (debugMode)
        std::cout << "Quantity changed: " << arg1 << std::endl;
}

/* user selected a new date time on the "Last Sold" field */
void PurchasesForm::on_purchasesLastSoldField_dateTimeChanged(const QDateTime &dateTime) {
    film.setLastSold(dateTime);
    ui->purchasesSaveChanges->setEnabled(true);
    if (debugMode)
        std::cout << "Date time changed" << std::endl;
}

/* the text of the "Last Sold to:" field was changed */
void PurchasesForm::on_purchasesLastSoldTo_textChanged(const QString &arg1) {
    film.setLastSoldTo(arg1);
    ui->purchasesSaveChanges->setEnabled(true);
    if (debugMode)
        std::cout << "Last sold to changed: " << arg1.toStdString() << std::endl;
}
