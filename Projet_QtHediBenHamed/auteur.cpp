#include "auteur.h"
#include <QDebug>


auteur::auteur()
{
    Nom_auteur="";
    Prenom_auteur="";
    Nationalite="";
    Id_auteur=0;
    Nb_livres=0;
    Jour=0;
    Mois=0;
    Annee=0;

}
auteur::auteur(int Id_auteur,int Nb_livres ,int Jour ,int Mois ,int Annee ,QString Nom_auteur,QString Prenom_auteur,QString Nationalite)
{
  this->Id_auteur =Id_auteur ;
  this->Nom_auteur =Nom_auteur;
  this->Prenom_auteur=Prenom_auteur;
  this->Nationalite=Nationalite;
  this->Jour=Jour;
  this->Mois=Mois;
  this->Annee=Annee;
  this->Nb_livres=Nb_livres;
}
int auteur:: get_Jour(){return Jour;}
int auteur:: get_Mois(){return  Mois;}
int auteur:: get_Annee(){return  Annee;}
int auteur:: get_Nblivres(){return  Nb_livres;}
QString auteur::get_Nom(){return  Nom_auteur;}
QString auteur::get_Prenom(){return  Prenom_auteur;}
QString auteur::get_Nationalite(){return Nationalite;}
int auteur::get_Identifiant(){return  Id_auteur;}

bool auteur::ajouter()
{
QSqlQuery query;
QString res= QString::number(Id_auteur);
query.prepare("INSERT INTO AUTEUR (Id_auteur,Nom_auteur, Prenom_auteur,Nationalite,Jour,Mois ,Annee ,Nb_livres)"
              "VALUES (:Id_auteur,:Nom_auteur,:Prenom_auteur,:Nationalite,:Jour,:Mois ,:Annee ,:Nb_livres )");
query.bindValue(":Id_auteur",res);
query.bindValue(":Nom_auteur",Nom_auteur);
query.bindValue(":Prenom_auteur",Prenom_auteur);
query.bindValue(":Nationalite", Nationalite);
query.bindValue(":Jour",Jour);
query.bindValue(":Mois",Mois);
query.bindValue(":Annee", Annee);
query.bindValue(":Nb_livres", Nb_livres);

return   query.exec();
}

QSqlQueryModel * auteur::afficher()
{

QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from AUTEUR ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_auteur"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_auteur"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom_auteur"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nationalite"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Jour"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mois"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Annee"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nb_livres"));
return model;
}
QSqlQueryModel * auteur::Detailler()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select Nom_auteur from AUTEUR ");
model->setHeaderData(0, Qt::Vertical, QObject::tr("Nom_auteur"));

return model;
}

bool auteur::supprimer(int Id_auteur)
{
QSqlQuery query;
QString res= QString::number(Id_auteur);
query.prepare("Delete from AUTEUR where Id_auteur = :Id_auteur ");
query.bindValue(":Id_auteur", res);
return    query.exec();
}
bool auteur::modifier(int Ide_auteur)
{
    QSqlQuery query;
    QString res= QString::number(Ide_auteur);
    query.prepare("update AUTEUR set Nom_auteur = '"+Nom_auteur+"',Prenom_auteur = '"+Prenom_auteur+"',Nationalite = '"+Nationalite+"',Jour = :Jour,Mois = :Mois,Annee = :Annee,Nb_livres = :Nb_livres where Id_auteur =:Ide_auteur");
    query.bindValue(":Ide_auteur", res);
    query.bindValue(":Nom_auteur",Nom_auteur);
    query.bindValue(":Prenom_auteur",Prenom_auteur);
    query.bindValue(":Nationalite", Nationalite);
    query.bindValue(":Jour",Jour);
    query.bindValue(":Mois",Mois);
    query.bindValue(":Annee", Annee);
    query.bindValue(":Nb_livres", Nb_livres);
    return    query.exec();
}
QSqlQueryModel * auteur::chercher(int Id)
{
auteur A;
    QSqlQuery query;
    QString res=QString::number(Id);
    query.prepare("Select * from Auteur where Id_auteur=:Id");
    query.bindValue(":Id",res);
    QSqlQueryModel * model = new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_auteur"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_auteur"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom_auteur"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nationalite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Jour"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mois"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Annee"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nb_livres"));
return model;
}

QSqlQueryModel *auteur::trier()
{

    QSqlQuery query;
   query.prepare("select * from auteur order By Id_auteur");
   QSqlQueryModel * model = new QSqlQueryModel();
   query.exec();
   model->setQuery(query);
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_auteur"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_auteur"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom_auteur"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nationalite"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("Jour"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mois"));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("Annee"));
   model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nb_livres"));

   return model;

}




