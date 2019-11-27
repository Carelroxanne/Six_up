# Six_up
I-library
#include "emprunt.h"
#include <QDebug>

Emprunt::Emprunt()
{
id_emprunt=0;
id_livre=0;
date="";
heure="";
}

void Emprunt::setIdEmprunt(int id)
{
    this->id_emprunt = id;
}
Emprunt::Emprunt(int id_emprunt,int id_livre, QString date, QString heure)
{
  this->id_emprunt=id_emprunt;
  this->id_livre=id_livre;
  this->date=date;
  this->heure=heure;
}
int Emprunt::getid_emprunt(){return  id_emprunt;}
int Emprunt::getid_livre(){return id_livre;}
QString Emprunt::getdate(){return  date;}
QString Emprunt::getheure(){return  heure;}

bool Emprunt::ajouter()
{

QSqlQuery query;
 QString  res= QString ::number(id_emprunt);
query.prepare("INSERT INTO etudiant (ID_EMPRUNT,ID_LIVRE, DATE, HEURE) "
                    "VALUES (:id_emprunt,id_livre, :date, :heure)");
query.bindValue(":id_emprunt", res);
query.bindValue(":id_livre", id_livre);
query.bindValue(":date", date);
query.bindValue(":heure", heure);


return    query.exec();
}

QSqlQueryModel * Emprunt::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Emprunt");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_Emprunt"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_Livre"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Heure"));
    return model;
}

bool Emprunt::supprimer(int id_emprunt)
{

QSqlQuery query;
 QString  res= QString ::number(id_emprunt);
query.prepare("Delete from emprunt where ID = :id_emprunt ");
query.bindValue(":id_emprunt", res);
return    query.exec();
}

