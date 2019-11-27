#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class departement
{
private:
    int CodeDepartement ,Id_CATEGORIE ;
    QString Libelle_Departement ;
public:
    departement();
    departement(int,int,QString);

    int get_CodeDepartement ();
    int get_IdCategorie ();
    QString get_LibelleDept ();

    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int);
};

#endif // DEPARTEMENT_H




