#include "dialog_exemplaire.h"
#include "ui_dialog_exemplaire.h"


#include "exemplaire.h"
#include <QMessageBox>
Dialog_exemplaire::Dialog_exemplaire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_exemplaire)
{
    ui->setupUi(this);
    ui->tableexemplaire->setModel(tmpexemplaire.afficher());//refresh

}

Dialog_exemplaire::~Dialog_exemplaire()
{
    delete ui;
}

void Dialog_exemplaire::on_pushButton_ajouter_clicked()
{
    int Id_EXEMPLAIRE   = ui->lineEdit_id_exemplaire->text().toInt();
    QString Libelle_exemplaire  = ui->lineEdit_libelleexemplaire_2->text();

    exemplaire E(Id_EXEMPLAIRE,Libelle_exemplaire);

     bool test=E.ajouter();
     if(test)
     {
        ui->tableexemplaire->setModel(tmpexemplaire.afficher());//refresh
        /*QMessageBox::information(nullptr, QObject::tr("Ajouter un exemplaire"),
        QObject::tr("exemplaire ajouté.\n""Click Cancel to exit."), QMessageBox::Cancel);*/
        QMessageBox::information(this,"Ajout","exemplaire ajouté");

     }
     else
     {
        /*QMessageBox::critical(nullptr, QObject::tr("Ajouter un exemplaire"),
        QObject::tr("Erreur !.\n""Click Cancel to exit."), QMessageBox::Cancel);*/
         QMessageBox::warning(this,"Ajout","Erreur ! ");

     }

}

void Dialog_exemplaire::on_pushButton_supprimer_clicked()
{
    int Id_EXEMPLAIRE = ui->lineEdit_exemplairsupp->text().toInt();
    bool test=tmpexemplaire.supprimer(Id_EXEMPLAIRE);
    if(test)
    {
          ui->tableexemplaire->setModel(tmpexemplaire.afficher());//refresh
          /*QMessageBox::information(nullptr, QObject::tr("Supprimer un exemplaire"),
                    QObject::tr("exemplaire supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);*/
          QMessageBox::information(this,"Suppression","exemplaire supprimer");


    }
    else
       { /*QMessageBox::critical(nullptr, QObject::tr("Supprimer un exemplaire"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);*/
        QMessageBox::warning(this,"Suppression","auteur supprimer");

         }

}




void Dialog_exemplaire::on_pushButton_modifier_clicked()
{
    int Id_EXEMPLAIRE2   = ui->lineEdit_ide_modif->text().toInt();
    //int Id_EXEMPLAIRE   = ui->lineEdit_id_exemplaire_modif->text().toInt();
    QString Libelle_exemplaire  = ui->lineEdit_libelleexemplaire->text();
    exemplaire E(Id_EXEMPLAIRE2,Libelle_exemplaire);

    bool test=E.modifier(Id_EXEMPLAIRE2);
    if(test)
    {
       ui->tableexemplaire->setModel(tmpexemplaire.afficher());//refresh
       QMessageBox::information(this, "modification","exemplaire modifié");

    }
    else
    {

        QMessageBox::warning(this,"modification","l'identifiant est incorrect ! ");
    }

}


