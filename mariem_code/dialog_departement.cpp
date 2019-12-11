#include "dialog_departement.h"
#include "ui_dialog_departement.h"
#include "departement.h"
#include <QMessageBox>

Dialog_departement::Dialog_departement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_departement)
{
    ui->setupUi(this);
    ui->tabledepartement->setModel(tmpdepartement.afficher());//refresh
    //ui->comboBox_departement->setModel(tmpdepartement.Detailler());//refresh
    ui->tabledepartement_chercher->setModel(tmpdepartement.afficher());
    ui->tabledepartement->setModel(tmpdepartement.trier());

}

Dialog_departement::~Dialog_departement()
{
    delete ui;
}

void Dialog_departement::on_pushButton_ajouter_clicked()
{

     int CodeDepartement = ui->lineEdit_Cd->text().toInt();
     int Id_CATEGORIE =ui->lineEdit_Ide ->text().toInt();
     QString Libelle_Departement = ui->lineEdit_L->text();

    departement D(CodeDepartement,Id_CATEGORIE,Libelle_Departement);
    bool test=D.ajouter();
    if(test)

            {
                 ui->tabledepartement->setModel(tmpdepartement.afficher());//refresh
                  /*QMessageBox::information(nullptr, QObject::tr("Ajouter un Departement"),
                  QObject::tr("Departement ajouté.\n""Click Cancel to exit."), QMessageBox::Cancel);*/
                 QMessageBox::information(this,"Ajout","departement ajouté");


            }
  else
            {
                  /*QMessageBox::critical(nullptr, QObject::tr("Ajouter un Departement"),
                  QObject::tr("Erreur !.\n""Click Cancel to exit."), QMessageBox::Cancel);*/
        QMessageBox::warning(this,"Ajout","departement ajouté");

            }
}

void Dialog_departement::on_pushButton_modifier_clicked()
{
    int CodeDepartement2 = ui->lineEdit_ide_modif->text().toInt();
    //int CodeDepartement = ui->lineEdit_Code_modifier->text().toInt();
    int Id_CATEGORIE =ui->lineEdit_Ide_3 ->text().toInt();
    QString Libelle_Departement = ui->lineEdit_L_3->text();
    departement D(CodeDepartement2,Id_CATEGORIE,Libelle_Departement);

     bool test=D.modifier(CodeDepartement2);
     if(test)
     {
        ui->tabledepartement->setModel(tmpdepartement.afficher());//refresh

        QMessageBox::information(this, "modification","departement modifié");

     }
     else
     {

         QMessageBox::warning(this,"modification","Erreur ! ");

     }

}
/* supppression */

void Dialog_departement::on_pushButton_supprimer_clicked()
{
    int id = ui->lineEdit_ide_4->text().toInt();
    bool test=tmpdepartement.supprimer(id);
    if(test)
    {
          ui->tabledepartement->setModel(tmpdepartement.afficher());//refresh


          QMessageBox::information(this,"Suppression","departement Supprimé");


    }
    else
       {
        QMessageBox::warning(this,"Suppression"," Erreur");

         }
}

void Dialog_departement::on_pushButton_chercher_clicked()
{
    int code_departement=ui->lineEdit_identifiant->text().toInt();
    ui->tabledepartement_chercher->setModel(tmpdepartement.chercher(code_departement));

}

void Dialog_departement::on_pushButton_Trier_clicked()
{
    ui->tabledepartement->setModel(tmpdepartement.trier());

}
