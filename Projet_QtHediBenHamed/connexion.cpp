#include "connexion.h"

connexion::connexion()
{

}


bool connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-bd");
db.setUserName("ideh25");//inserer nom de l'utilisateur
db.setPassword("25101999");//inserer mot de passe de cet utilisateur

if (db.open())
{test=true;}

else
{throw QString ("Erreur Paramétres"+ test);}
return  test;
}
void connexion::fermerConnexion()
{db.close();}

