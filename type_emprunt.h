# Six_up
I-library
#ifndef TYPES_EMPRUNT_H
#define TYPES_EMPRUNT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class types_emprunts
{
   QString type;
    int nbj;
    int id_type;
public:
    types_emprunts();
    types_emprunts(QString type, int nbj, int id_type);
    QString gettype();
    int getnbj();
    int getid_type();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
};
#endif // TYPES_EMPRUNT_H
