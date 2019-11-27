#include "departement.h"
#include <QDebug>


departement::departement()
{

    CodeDepartement=0;
    Id_CATEGORIE=0;
    Libelle_Departement="";

}

departement::departement(int CodeDepartement ,int Id_CATEGORIE,QString Libelle_Departement)
{
  this->CodeDepartement =CodeDepartement ;
  this->Id_CATEGORIE =Id_CATEGORIE;
  this->Libelle_Departement=Libelle_Departement;
}
int departement::get_CodeDepartement(){return  CodeDepartement;}
int departement::get_IdCategorie(){return  Id_CATEGORIE;}
QString departement::get_LibelleDept(){return Libelle_Departement;}


bool departement::ajouter()
{
QSqlQuery query;
QString res= QString::number(CodeDepartement);
query.prepare("INSERT INTO DEPARTEMENT (CodeDepartement,Id_CATEGORIE, Libelle_Departement)"
              "VALUES (:CodeDepartement,:Id_CATEGORIE,:Libelle_Departement)");
query.bindValue(":CodeDepartement",res);
query.bindValue(":Id_CATEGORIE",Id_CATEGORIE);
query.bindValue(":Libelle_Departement", Libelle_Departement);

return   query.exec();
}

QSqlQueryModel * departement::afficher()
{

QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from DEPARTEMENT ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CodeDepartement"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Id_CATEGORIE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Libelle_Departement"));

return model;
}

bool departement::supprimer(int CodeDepartement)
{
QSqlQuery query;
QString res= QString::number(CodeDepartement);
query.prepare("Delete from DEPARTEMENT where CodeDepartement = :CodeDepartement ");
query.bindValue(":CodeDepartement", res);
return    query.exec();
}

bool departement::modifier(int CodeDepartement2)
{
    QSqlQuery query;
    QString res= QString::number(CodeDepartement2);
    query.prepare("update DEPARTEMENT set Id_CATEGORIE =:Id_CATEGORIE,Libelle_Departement = '"+Libelle_Departement+"' where CodeDepartement =:CodeDepartement2");
    query.bindValue(":CodeDepartement2", res);
    query.bindValue(":Id_CATEGORIE",Id_CATEGORIE);
    query.bindValue(":Libelle_Departement",Libelle_Departement);
    return    query.exec();
}

