# Six_up
I-library
#include "types_emprunt.h"
#include <QString>

types_emprunts::types_emprunts()
{
    type="";
    nbj=0;
    id_type=0;
}

types_emprunts::types_emprunts(QString type,int nbj,int id_type)
{
    this->type=type;
    this->nbj=nbj;
    this->id_type=id_type;
}
QString types_emprunts::gettype(){return  type;}
int types_emprunts::getnbj(){return nbj;}
int types_emprunts::getid_type(){return  id_type;}

bool types_emprunts::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_type);
query.prepare("INSERT INTO types_emprunts (type, nbj, id_type) "
                    "VALUES (:type, :nbj, :id_type)");
query.bindValue(":id_type", res);
query.bindValue(":nbj", nbj);
query.bindValue(":type", type);

return    query.exec();
}
QSqlQueryModel * types_emprunts::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from types_emprunts");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("type"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbj "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_type"));
    return model;
}

bool types_emprunts::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from etudiant where ID = :id_type ");
query.bindValue(":id_type", res);
return    query.exec();
}

