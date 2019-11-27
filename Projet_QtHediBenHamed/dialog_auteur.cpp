#include "dialog_auteur.h"
#include "ui_dialog_auteur.h"
#include "auteur.h"
#include <QMessageBox>
#include "connexion.h"

Dialog_auteur::Dialog_auteur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_auteur)
{
    ui->setupUi(this);
    ui->tableauteur->setModel(tmpauteur.afficher());//refresh
    ui->comboBox_auteur->setModel(tmpauteur.Detailler());//refresh
    ui->tableauteur_chercher->setModel(tmpauteur.afficher());
    ui->tableauteur->setModel(tmpauteur.trier());


}

Dialog_auteur::~Dialog_auteur()
{
    delete ui;
}

void Dialog_auteur::on_pushButton_ajouter_clicked()
{

    int Id_auteur  = ui->lineEdit_id_auteur->text().toInt();
    QString Nom_auteur = ui->lineEdit_nom->text();
    QString Prenom_auteur = ui->lineEdit_prenom->text();
    QString Nationalite= ui->lineEdit_nationalite->text();
    int Nb_livres  = ui->lineEdit_Nb_livres->text().toInt();
    int Jour  = ui->lineEdit_Jour->text().toInt();
    int Mois  = ui->lineEdit_Mois->text().toInt();
    int Annee  = ui->lineEdit_Annee->text().toInt();

    auteur A(Id_auteur, Nb_livres , Jour , Mois , Annee ,Nom_auteur,Prenom_auteur ,Nationalite);

     bool test=A.ajouter();
     if(test)
     {
        ui->tableauteur->setModel(tmpauteur.afficher());//refresh
        ui->comboBox_auteur->setModel(tmpauteur.Detailler());//refresh

        /*QMessageBox::information(nullptr, QObject::tr("Ajouter un auteur"),
        QObject::tr("auteur ajouté.\n""Click Cancel to exit."), QMessageBox::Cancel);*/
        QMessageBox::information(this,"Ajout","auteur ajouté");

     }
     else
     {
        /*QMessageBox::critical(nullptr, QObject::tr("Ajouter un auteur"),
        QObject::tr("Erreur !.\n""Click Cancel to exit."), QMessageBox::Cancel);*/
        QMessageBox::warning(this,"Ajout","Erreur");


     }
}

void Dialog_auteur::on_pushButton_supprimer_clicked()
{

  int id = ui->lineEdit_ide_4->text().toInt();
  bool test=tmpauteur.supprimer(id);
  if(test)
  {
        ui->tableauteur->setModel(tmpauteur.afficher());//refresh
        ui->comboBox_auteur->setModel(tmpauteur.Detailler());//refresh

        /*QMessageBox::information(this, QObject::tr("Supprimer un auteur"),
                  QObject::tr("auteur supprimé.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);*/
        QMessageBox::information(this,"Suppression","auteur Supprimé");


  }
  else
     { /*QMessageBox::critical(this, QObject::tr("Supprimer un auteur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);*/
      QMessageBox::warning(this,"Suppression"," Erreur");

       }
}
void Dialog_auteur::on_pushButton_modifier_clicked()
{

    int Ide_auteur  = ui->lineEdit_ide_modif->text().toInt();
    //int Id_auteur  = ui->lineEdit_id_auteur_3->text().toInt();
    QString Nom_auteur = ui->lineEdit_nom_modif->text();
    QString Prenom_auteur = ui->lineEdit_prenom_modif->text();
    QString Nationalite= ui->lineEdit_nationalite_modif->text();
    int Nb_livres  = ui->lineEdit_Nblivres_modif->text().toInt();
    int Jour  = ui->lineEdit_Jour_modif->text().toInt();
    int Mois  = ui->lineEdit_Mois_modif->text().toInt();
    int Annee  = ui->lineEdit_Annee_modif->text().toInt();
    auteur A(Ide_auteur, Nb_livres , Jour , Mois , Annee ,Nom_auteur,Prenom_auteur ,Nationalite);








     bool test=A.modifier(Ide_auteur);
     if(test)
     {
        ui->tableauteur->setModel(tmpauteur.afficher());//refresh
        QMessageBox::information(this, "modification","auteur modifié");
     }


     else
     {

        QMessageBox::warning(this,"modification","Erreur ! ");
     }

}

void Dialog_auteur::on_comboBox_auteur_currentIndexChanged(const QString &arg1)
{
    QString nom =ui->comboBox_auteur->currentText();//refresh
    connexion conn;
     QSqlQuery query;
     query.prepare("select * from  Auteur where  Nom_auteur='"+nom+"'");
     if(query.exec())
     {
        while(query.next())
                    {
                     ui->lineEdit_id_auteur_2->setText(query.value(0).toString());
                     ui->lineEdit_nom_2->setText(query.value(1).toString());
                     ui->lineEdit_prenom_2->setText(query.value(2).toString());
                     ui->lineEdit_nationalite_2->setText(query.value(3).toString());
                     ui->lineEdit_Nb_livres_2->setText(query.value(4).toString());
                     ui->lineEdit_Mois_2->setText(query.value(5).toString());
                     ui->lineEdit_Jour_2->setText(query.value(6).toString());
                     ui->lineEdit_Annee_2->setText(query.value(7).toString());





     }
        conn.fermerConnexion();
     }
     else
     {

        QMessageBox::warning(this,"chercher","Erreur");


     }

}



void Dialog_auteur::on_pushButton_chercher_clicked()
{
    int ide=ui->lineEdit_identifiant->text().toInt();
    ui->tableauteur_chercher->setModel(tmpauteur.chercher(ide));

}

void Dialog_auteur::on_pushButton_Trier_clicked()
{
    ui->tableauteur->setModel(tmpauteur.trier());

}
