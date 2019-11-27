#include "exemplaire.h"
#include <QDebug>

exemplaire::exemplaire()
{

    Libelle_exemplaire ="";
    Id_EXEMPLAIRE =0;

}
#include "auteur.h"



exemplaire::exemplaire(int Id_EXEMPLAIRE ,QString Libelle_exemplaire)
{
  this->Id_EXEMPLAIRE =Id_EXEMPLAIRE ;
  this->Libelle_exemplaire =Libelle_exemplaire;
}
int exemplaire::get_Identifiant(){return Id_EXEMPLAIRE ;}
QString exemplaire::get_libelle(){return  Libelle_exemplaire;}


bool exemplaire::ajouter()
{
QSqlQuery query;
QString res= QString::number(Id_EXEMPLAIRE);
query.prepare("INSERT INTO EXEMPLAIRE (Id_EXEMPLAIRE,Libelle_exemplaire)"
              "VALUES (:Id_EXEMPLAIRE,:Libelle_exemplaire)");
query.bindValue(":Id_EXEMPLAIRE",res);
query.bindValue(":Libelle_exemplaire",Libelle_exemplaire);

return   query.exec();
}

QSqlQueryModel * exemplaire::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from EXEMPLAIRE ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_EXEMPLAIRE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Libelle_exemplaire"));
return model;
}

bool exemplaire::supprimer(int Id_EXEMPLAIRE)
{
QSqlQuery query;
QString res= QString::number(Id_EXEMPLAIRE);
query.prepare("Delete from EXEMPLAIRE where Id_EXEMPLAIRE = :Id_EXEMPLAIRE ");
query.bindValue(":Id_EXEMPLAIRE", res);
return    query.exec();
}

bool exemplaire::modifier(int Id_EXEMPLAIRE2)
{
    QSqlQuery query;
    QString res= QString::number(Id_EXEMPLAIRE2);
    query.prepare("update EXEMPLAIRE set Libelle_exemplaire='"+Libelle_exemplaire+"' where Id_EXEMPLAIRE = :Id_EXEMPLAIRE2");
    query.bindValue(":Id_EXEMPLAIRE2",res);
    query.bindValue(":Libelle_exemplaire",Libelle_exemplaire);
    return    query.exec();
}



