#include "dialog_home.h"
#include "ui_dialog_home.h"

Dialog_home::Dialog_home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_home)
{
    ui->setupUi(this);
}

Dialog_home::~Dialog_home()
{
    delete ui;
}


void Dialog_home::on_pushButton_Livre_clicked()
{

       acces_livre= new Dialog_livre(this);
       acces_livre->show();

}

void Dialog_home::on_pushButton_Auteur_clicked()
{
    acces_auteur= new Dialog_auteur(this);
    acces_auteur->show();


}

void Dialog_home::on_pushButton_Personnel_clicked()
{
    acces_perso= new Dialog_personnel(this);
    acces_perso->show();

}

void Dialog_home::on_pushButton_Exemplaire_clicked()
{
    acces_exemplaire= new Dialog_exemplaire(this);
    acces_exemplaire->show();
}

void Dialog_home::on_pushButton_Departement_clicked()
{
    acces_departement = new Dialog_departement(this);
    acces_departement->show();

}
