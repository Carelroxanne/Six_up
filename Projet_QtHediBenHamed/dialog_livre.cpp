#include "dialog_livre.h"
#include "ui_dialog_livre.h"
#include "livre.h"
#include <QMessageBox>
#include "connexion.h"

Dialog_livre::Dialog_livre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_livre)
{
    ui->setupUi(this);
    ui->tablelivre->setModel(tmplivre.afficher());//refresh
    ui->comboBox_livre->setModel(tmplivre.Detailler());//refresh
    ui->tablelivre_chercher->setModel(tmplivre.afficher());
    ui->tablelivre->setModel(tmplivre.trier());
}
Dialog_livre::~Dialog_livre()
{
    delete ui;
}
void Dialog_livre::on_pushButton_ajouter_2_clicked()
{
    int Isbn = ui->lineEdit_Isbn_2->text().toInt();
    int Nb_page = ui->lineEdit_Nbp_2->text().toInt();
    QString Titre= ui->lineEdit_Titre_2->text();
    QString Format = ui->lineEdit_Format_2->text();
    QString Theme= ui->lineEdit_Theme_2->text();
    int Id_auteur = ui->lineEdit_ideauteur->text().toInt();
    int Id_EXEMPLAIRE= ui->lineEdit_ideexemplaire->text().toInt();
    int Jour = ui->lineEdit_Jour_2->text().toInt();
    int Mois= ui->lineEdit_Mois_2->text().toInt();
    int Annee = ui->lineEdit_annee_2->text().toInt();
    livre l(Isbn,Nb_page,Id_auteur,Id_EXEMPLAIRE, Jour , Mois , Annee ,Titre,Format,Theme);
    bool test=l.ajouter();
    if(test)
        {
            ui->tablelivre->setModel(tmplivre.afficher());//refresh
            ui->comboBox_livre->setModel(tmplivre.Detailler());//refresh
            QMessageBox::information(this,"Ajout","livre ajouté");
        }
    else
        {
            QMessageBox::warning(this,"Ajout","Erreur ");
        }
}
void Dialog_livre::on_pushButton_supprimer_clicked()
{
    int id = ui->lineEdit_2->text().toInt();
    bool test=tmplivre.supprimer(id);
    if(test)
    {
        ui->tablelivre->setModel(tmplivre.afficher());//refresh
        ui->comboBox_livre->setModel(tmplivre.Detailler());//refresh
        QMessageBox::information(this, "suppression","livre supprimer");

    }
    else
    {
        QMessageBox::warning(this,"Suppression","Erreur ! ");
    }
}
void Dialog_livre::on_pushButton_clicked()
{
    int Isbn2 = ui->lineEdit_idlivre_modif->text().toInt();
    int Id_auteur = ui->lineEdit_IdeAuteur_modif->text().toInt();
    int Id_EXEMPLAIRE= ui->lineEdit_ideexemplaire_modif->text().toInt();
    int Jour = ui->lineEdit_Jour_modif->text().toInt();
    int Mois= ui->lineEdit_Mois_modif->text().toInt();
    int Annee = ui->lineEdit_annee_modif->text().toInt();
    int Nb_page = ui->lineEdit_Nbp_modif->text().toInt();
    QString Titre= ui->lineEdit_Titre_modif->text();
    QString Format = ui->lineEdit_Format_modif->text();
    QString Theme= ui->lineEdit_Theme_modif->text();
    livre l(Isbn2,Nb_page,Id_auteur,Id_EXEMPLAIRE, Jour , Mois , Annee ,Titre,Format,Theme);
    bool test=l.modifier(Isbn2);

    if(test)
         {
             ui->tablelivre->setModel(tmplivre.afficher());//refresh
             QString nom =ui->comboBox_livre->currentText();//refresh
             QMessageBox::information(this, "modification","livre modifié");
         }
     else
         {
            QMessageBox::warning(this,"modification","Erreur ! ");
         }
}
void Dialog_livre::on_comboBox_livre_currentIndexChanged(const QString &arg1)
{
      QString nom =ui->comboBox_livre->currentText();//refresh
      connexion conn;
      QSqlQuery query;
      query.prepare("select * from  Livre where  Titre='"+nom+"'");
      if(query.exec())
      {
         while(query.next())
                     {
             ui->lineEdit_Isbn_3->setText(query.value(0).toString());
             ui->lineEdit_Titre_3->setText(query.value(1).toString());
             ui->lineEdit_Theme_3->setText(query.value(2).toString());
             ui->lineEdit_Format_3->setText(query.value(3).toString());
             ui->lineEdit_Nbp_3->setText(query.value(4).toString());
             ui->lineEdit_Jour_3->setText(query.value(5).toString());
             ui->lineEdit_Mois_3->setText(query.value(6).toString());
             ui->lineEdit_annee_3->setText(query.value(7).toString());
             ui->lineEdit_ideexemplaire_3->setText(query.value(8).toString());
             ui->lineEdit_ideauteur_3->setText(query.value(9).toString());

                      }
         conn.fermerConnexion();
      }
      else
      {
         QMessageBox::warning(this,"Trier","Erreur");
      }
}
void Dialog_livre::on_pushButton_chercher_clicked()
{
    int ide=ui->lineEdit_identifiant->text().toInt();
    ui->tablelivre_chercher->setModel(tmplivre.chercher(ide));
}
void Dialog_livre::on_pushButton_ajouter_4_clicked()
{
    ui->tablelivre->setModel(tmplivre.trier());
}

