#include "livre.h"
#include <QDebug>
livre::livre()
{
 Titre="";
 Format="";
 Theme="";
 Nb_pages=0;
 Isbn=0;
 Id_auteur =0;
 Id_EXEMPLAIRE =0;
 Jour=0;
 Mois=0;
 Annee=0;
}
livre::livre(int Isbn ,int Nb_pages,int Id_auteur ,int Id_EXEMPLAIRE ,int Jour ,int Mois ,int Annee ,QString Titre,QString Format,QString Theme)
{
  this->Isbn=Isbn;
  this->Titre=Titre;
  this->Format=Format;
  this->Theme=Theme;
  this->Nb_pages=Nb_pages;
  this->Id_auteur=Id_auteur;
  this->Id_EXEMPLAIRE=Id_EXEMPLAIRE;
  this->Jour=Jour;
  this->Mois=Mois;
  this->Annee=Annee;
}
QString livre::get_FOrmat(){return  Format;}
QString livre::get_Theme(){return  Theme;}
QString livre::get_Titre(){return Titre;}
int livre:: get_Jour(){return Jour;}
int livre:: get_Mois(){return  Mois;}
int livre:: get_Annee(){return  Annee;}
int livre::get_Isbn(){return  Isbn;}
int livre::get_Nbpage(){return  Nb_pages;}
int livre::get_idauteur(){return  Id_auteur;}
int livre::get_idexemplaire(){return  Id_EXEMPLAIRE;}

bool livre::ajouter()
{
QSqlQuery query;

QString res= QString::number(Isbn);
query.prepare("INSERT INTO LIVRE (Isbn,Titre,Nb_pages,Theme,Format,Id_auteur,Id_EXEMPLAIRE,Jour,Mois ,Annee)"
                         "VALUES (:Isbn,:Titre,:Nb_pages,:Theme,:Format,:Id_auteur,:Id_EXEMPLAIRE,:Jour,:Mois ,:Annee)");
query.bindValue(":Isbn", res);
query.bindValue(":Titre", Titre);
query.bindValue(":Nb_pages",Nb_pages);
query.bindValue(":Theme", Theme);
query.bindValue(":Format", Format);
query.bindValue(":Id_auteur", Id_auteur);
query.bindValue(":Id_EXEMPLAIRE", Id_EXEMPLAIRE);
query.bindValue(":Jour",Jour);
query.bindValue(":Mois",Mois);
query.bindValue(":Annee",Annee);

return  query.exec();
}
QSqlQueryModel * livre::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from LIVRE");
model->setHeaderData(0, Qt::Vertical, QObject::tr("Isbn  "));
model->setHeaderData(1, Qt::Vertical, QObject::tr("Titre"));
model->setHeaderData(2, Qt::Vertical, QObject::tr("Nb_pages"));
model->setHeaderData(3, Qt::Vertical, QObject::tr("Theme"));
model->setHeaderData(4, Qt::Vertical, QObject::tr("Format"));
model->setHeaderData(5, Qt::Vertical, QObject::tr("Id_auteur"));
model->setHeaderData(6, Qt::Vertical, QObject::tr("Id_EXEMPLAIRE"));
model->setHeaderData(7, Qt::Vertical, QObject::tr("Jour"));
model->setHeaderData(8, Qt::Vertical, QObject::tr("Mois"));
model->setHeaderData(9, Qt::Vertical, QObject::tr("Annee"));
return model;
}
bool livre::supprimer(int Isbn)
{
QSqlQuery query;
QString res= QString::number(Isbn);
query.prepare("Delete from LIVRE where Isbn = :Isbn ");
query.bindValue(":Isbn",res);
return    query.exec();
}
bool livre::modifier(int Isbn2)
{
    QSqlQuery query;
    QString res= QString::number(Isbn2);
    query.prepare("update LIVRE set Nb_pages=:Nb_pages,Titre = '"+Titre+"',Format = '"+Format+"',Theme = '"+Theme+"',Id_auteur =:Id_auteur,Id_EXEMPLAIRE =:Id_EXEMPLAIRE,Jour = :Jour,Mois = :Mois,Annee = :Annee where Isbn =:Isbn2");
    query.bindValue(":Isbn2", res);
    query.bindValue(":Titre", Titre);
    query.bindValue(":Nb_pages",Nb_pages);
    query.bindValue(":Theme", Theme);
    query.bindValue(":Format", Format);
    query.bindValue(":Id_auteur", Id_auteur);
    query.bindValue(":Id_EXEMPLAIRE", Id_EXEMPLAIRE);
    query.bindValue(":Jour",Jour);
    query.bindValue(":Mois",Mois);
    query.bindValue(":Annee",Annee);
return query.exec();
}
QSqlQueryModel * livre::Detailler()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select Titre from LIVRE ");
model->setHeaderData(0, Qt::Vertical, QObject::tr("Titre"));
return model;
}
QSqlQueryModel * livre::chercher(int Id)
{
    QSqlQuery query;
    QString res=QString::number(Id);
    query.prepare("Select * from LIVRE where Isbn=:Id");
    query.bindValue(":Id",res);
    QSqlQueryModel * model = new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Vertical, QObject::tr("Isbn  "));
    model->setHeaderData(1, Qt::Vertical, QObject::tr("Titre"));
    model->setHeaderData(2, Qt::Vertical, QObject::tr("Nb_pages"));
    model->setHeaderData(3, Qt::Vertical, QObject::tr("Theme"));
    model->setHeaderData(4, Qt::Vertical, QObject::tr("Format"));
    model->setHeaderData(5, Qt::Vertical, QObject::tr("Id_auteur"));
    model->setHeaderData(6, Qt::Vertical, QObject::tr("Id_EXEMPLAIRE"));
    model->setHeaderData(7, Qt::Vertical, QObject::tr("Jour"));
    model->setHeaderData(8, Qt::Vertical, QObject::tr("Mois"));
    model->setHeaderData(9, Qt::Vertical, QObject::tr("Annee"));
return model;
}
QSqlQueryModel *livre::trier()
{
   QSqlQuery query;
   query.prepare("select * from LIVRE order By Isbn");
   QSqlQueryModel * model = new QSqlQueryModel();
   query.exec();
   model->setQuery(query);
   model->setHeaderData(0, Qt::Vertical, QObject::tr("Isbn  "));
   model->setHeaderData(1, Qt::Vertical, QObject::tr("Titre"));
   model->setHeaderData(2, Qt::Vertical, QObject::tr("Nb_pages"));
   model->setHeaderData(3, Qt::Vertical, QObject::tr("Theme"));
   model->setHeaderData(4, Qt::Vertical, QObject::tr("Format"));
   model->setHeaderData(5, Qt::Vertical, QObject::tr("Id_auteur"));
   model->setHeaderData(6, Qt::Vertical, QObject::tr("Id_EXEMPLAIRE"));
   model->setHeaderData(7, Qt::Vertical, QObject::tr("Jour"));
   model->setHeaderData(8, Qt::Vertical, QObject::tr("Mois"));
   model->setHeaderData(9, Qt::Vertical, QObject::tr("Annee"));
   return model;
}
