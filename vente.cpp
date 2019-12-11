#include "vente.h"
#include <QSqlQuery>
#include <QString>
#include <QTableView>
VENTE::VENTE()
{
NUM_VENTE=0;
DATE_VENTE="";
}
VENTE::VENTE(int NUM_VENTE,QString DATE_VENTE)
{
  this->NUM_VENTE=NUM_VENTE;
  this->DATE_VENTE=DATE_VENTE;

}
QString VENTE::get_DATE_VENTE(){return  DATE_VENTE;}
int VENTE::get_NUM_VENTE(){return  NUM_VENTE;}

bool VENTE::ajouter()
{
QSqlQuery query;
QString res= QString::number(NUM_VENTE);
query.prepare("INSERT INTO VENTS (NUM_VENTE, DATE_VENTE) "
                    "VALUES (:NUM_VENTE, :DATE_VENTE)");
query.bindValue(":NUM_VENTE", res);
query.bindValue(":DATE_VENTE", DATE_VENTE);


return    query.exec();
}


QSqlQueryModel * VENTE::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from VENTS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_VENTE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_VENTE "));

    return model;
}

bool VENTE::supprimer(int NUM_VENTE)
{
QSqlQuery query;
QString res= QString::number(NUM_VENTE);
query.prepare("Delete from VENTS where NUM_VENTE = :NUM_VENTE ");
query.bindValue(":NUM_VENTE", res);
return    query.exec();
}

bool VENTE::modifier(int NUM_VENTE ,QString DATE_VENTE)
{
    QSqlQuery query;
    QString res= QString::number(NUM_VENTE);
    query.prepare ("UPDATE VENTS set NUM_VENTE= :NUM_VENTE ,DATE_VENTE= :DATE_VENTE where NUM_VENTE=:NUM_VENTE");
    query.bindValue(":NUM_VENTE", res);
    query.bindValue(":DATE_VENTE", DATE_VENTE);
    return query.exec();
}
QSqlQueryModel * VENTE::Rechercher(int NUM_VENTE)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from VENTS where  NUM_VENTE =:NUM_VENTE");
    query.bindValue(":NUM_VENTE",NUM_VENTE);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_VENTE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_VENTE"));

        return model;
   }
QSqlQueryModel * VENTE::afficher_tri()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from VENTS order by NUM_VENTE asc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_VENTE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_VENTE "));

    return model;
}




