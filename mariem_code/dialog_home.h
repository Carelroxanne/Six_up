#ifndef DIALOG_HOME_H
#define DIALOG_HOME_H

#include <dialog_livre.h>
#include <dialog_auteur.h>
#include <dialog_personnel.h>
#include <dialog_exemplaire.h>
#include <dialog_departement.h>
#include <QDialog>



namespace Ui {
class Dialog_home;
}

class Dialog_home : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_home(QWidget *parent = nullptr);
    ~Dialog_home();

private slots:
    void on_pushButton_Livre_clicked();

    void on_pushButton_Auteur_clicked();

    void on_pushButton_Personnel_clicked();

    void on_pushButton_Exemplaire_clicked();

    void on_pushButton_Departement_clicked();

private:
    Ui::Dialog_home *ui;

     Dialog_livre *acces_livre;
     Dialog_auteur * acces_auteur;
     Dialog_personnel *acces_perso;
     Dialog_exemplaire *acces_exemplaire;
     Dialog_departement *acces_departement;
};

#endif // DIALOG_HOME_H

