# Six_up
I-library
#include "connexion.h"
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>



Connexion::Connexion(){
                      }
bool Connexion::ouvrirConnexion()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                           db.setDatabaseName("Projet2A");
                           db.setUserName("Soumaya");//inserer nom de l'utilisateur
                           db.setPassword("belinda");//inserer mot de passe de cet utilisateur

if (db.open())
    test=true;

else throw QString ("Erreur Paramétres"+db.lastError().text());
return  test;
}
void Connexion::fermerConnexion()
{db.close();}
