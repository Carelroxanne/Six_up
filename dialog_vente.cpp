#include "dialog_vente.h"
#include "ui_dialog_vente.h"

Dialog_vente::Dialog_vente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_vente)
{
    ui->setupUi(this);
}

Dialog_vente::~Dialog_vente()
{
    delete ui;
}
