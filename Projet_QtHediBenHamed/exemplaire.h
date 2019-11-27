#ifndef EXEMPLAIRE_H
#define EXEMPLAIRE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class exemplaire
{
private:
    int Id_EXEMPLAIRE ;
    QString Libelle_exemplaire ;
public:
    exemplaire();
    exemplaire(int,QString);

    int get_Identifiant();
    QString get_libelle();
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int);


};

#endif // EXEMPLAIRE_H





