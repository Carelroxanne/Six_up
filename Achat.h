#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class ACHATS
{public:
    ACHATS();
    ACHATS(int,QString);
    QString get_DATE_ACHAT();

    int get_NUM_ACHAT();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString);
     QSqlQueryModel * Rechercher(int );
     QSqlQueryModel * afficher_tri_achat();

private:
    QString DATE_ACHAT;
    int NUM_ACHAT;
};


#endif // ETUDIANT_H
