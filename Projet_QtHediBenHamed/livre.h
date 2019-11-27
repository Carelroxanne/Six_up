#ifndef LIVRE_H
#define LIVRE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class livre
{
private:
    QString Titre,Format,Theme;
    int Isbn,Nb_pages,Id_auteur,Id_EXEMPLAIRE,Jour , Mois , Annee;
public:
    livre();
    livre(int,int,int,int,int,int,int,QString,QString,QString);

    int get_Isbn();
    int get_Nbpage();
    int get_Jour();
    int get_Mois();
    int get_Annee();
    int get_idauteur();
    int get_idexemplaire();
    QString get_Titre();
    QString get_Theme();
    QString get_FOrmat();
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int);

    QSqlQueryModel *Detailler();

    QSqlQueryModel * trier();
    QSqlQueryModel * chercher(int);
};
#endif // LIVRE_H
