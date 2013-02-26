#include "baza.h"
#include "ui_baza.h"

Baza::Baza(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Baza)
{
    ui->setupUi(this);
}

Baza::~Baza()
{
    delete ui;
}
