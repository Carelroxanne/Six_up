#include "connexion.h"

connexion::connexion()
{

}


bool connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("My_DataBase");
db.setUserName("UserMariem");//inserer nom de l'utilisateur
db.setPassword("esprit20");//inserer mot de passe de cet utilisateur

if (db.open())
{test=true;}

else
{throw QString ("Erreur "+ test);}
return  test;
}
void connexion::fermerConnexion()
{db.close();}

