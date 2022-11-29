#include "rentalseditor.h"
#include "ui_rentalseditor.h"
#include "rentalsform.h"
#include "ui_rentalsform.h"
#include <QCloseEvent>

RentalsEditor::RentalsEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RentalsEditor),
    parent((QMainWindow*)(parent)) {
    ui->setupUi(this);
}

RentalsEditor::RentalsEditor(QWidget *f, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::RentalsEditor),
    parent((QMainWindow*)(parent)) {
    form = f;
    ui->setupUi(this);
    this->setCentralWidget(f);
}

RentalsEditor::~RentalsEditor(void) {
    delete form;
    delete ui;
}

void RentalsEditor::closeEvent(QCloseEvent *event) {
    emit closing();
    event->accept();
}
