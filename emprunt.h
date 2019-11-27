# Six_up
I-library
#ifndef EMPRUNT_H
#define EMPRUNT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Emprunt
{   int id_emprunt;
    int id_livre;
    QString date;
    QString heure;
public:

    Emprunt(int  id_emprunt ,int id_livre,QString date ,QString heure);
    int getid_emprunt();
    int getid_livre();
    QString getdate();
    QString getheure();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    Emprunt();
    void setIdEmprunt(int id);
};

#endif // EMPRUNT_H
