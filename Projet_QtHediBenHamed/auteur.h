#ifndef AUTEUR_H
#define AUTEUR_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class auteur
{
private:
    QString Nom_auteur,Prenom_auteur,Nationalite;
    int Id_auteur, Nb_livres , Jour , Mois , Annee;
public:
    auteur();
    auteur(int,int,int,int,int,QString,QString,QString);

    int get_Identifiant();
    int get_Jour();
    int get_Mois();
    int get_Annee();
    int get_Nblivres();
    QString get_Nom();
    QString get_Prenom();
    QString get_Nationalite();
    bool ajouter();
    QSqlQueryModel *afficher();
    QSqlQueryModel *Detailler();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * trier();
    QSqlQueryModel * chercher(int);
};

#endif // AUTEUR_H

