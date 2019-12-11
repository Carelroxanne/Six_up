#include "Achat.h"
#include <QSqlQuery>
#include <QString>
#include <QTableView>
ACHATS::ACHATS()
{
NUM_ACHAT=0;
DATE_ACHAT="";
}
ACHATS::ACHATS(int NUM_ACHAT,QString DATE_ACHAT)
{
  this->NUM_ACHAT=NUM_ACHAT;
  this->DATE_ACHAT=DATE_ACHAT;

}
QString ACHATS::get_DATE_ACHAT(){return  DATE_ACHAT;}
int ACHATS::get_NUM_ACHAT(){return  NUM_ACHAT;}

bool ACHATS::ajouter()
{
QSqlQuery query;
QString res= QString::number(NUM_ACHAT);
query.prepare("INSERT INTO ACHATS (NUM_ACHAT, DATE_ACHAT) "
                    "VALUES (:NUM_ACHAT, :DATE_ACHAT)");
query.bindValue(":NUM_ACHAT", res);
query.bindValue(":DATE_ACHAT", DATE_ACHAT);


return    query.exec();
}

QSqlQueryModel * ACHATS::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from ACHATS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_ACHAT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_ACHAT"));

    return model;
}

bool ACHATS::supprimer(int NUM_ACHAT)
{
QSqlQuery query;
QString res= QString::number(NUM_ACHAT);
query.prepare("Delete from ACHATS where NUM_ACHAT = :NUM_ACHAT ");
query.bindValue(":NUM_ACHAT", res);
return    query.exec();
}


bool ACHATS::modifier(int NUM_ACHAT ,QString DATE_ACHAT)
{
    QSqlQuery query;
    QString res= QString::number(NUM_ACHAT);
    query.prepare ("UPDATE ACHATS set NUM_ACHAT= :NUM_ACHAT ,DATE_ACHAT= :DATE_ACHAT where NUM_ACHAT= :NUM_ACHAT");
    query.bindValue(":NUM_ACHAT",  res);
    query.bindValue(":DATE_ACHAT", DATE_ACHAT);
    return query.exec();
}
QSqlQueryModel * ACHATS::Rechercher(int NUM_ACHAT)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from ACHATS where  NUM_ACHAT =:NUM_ACHAT");
    query.bindValue(":NUM_ACHAT",NUM_ACHAT);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_ACHAT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_ACHAT"));

        return model;
   }
QSqlQueryModel * ACHATS::afficher_tri_achat()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from ACHATS order by NUM_ACHAT asc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_ACHAT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_ACHAT"));

    return model;
}


