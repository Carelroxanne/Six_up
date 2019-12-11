#ifndef VENTE_H
#define VENTE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class VENTE
{public:
    VENTE();
    VENTE(int,QString);
    QString get_DATE_VENTE();

    int get_NUM_VENTE();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString);
     QSqlQueryModel * Rechercher(int );
     QSqlQueryModel * afficher_tri();

private:
    QString DATE_VENTE;
    int NUM_VENTE;
};
#endif // VENTE_H
