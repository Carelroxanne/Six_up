#ifndef DIALOG_AUTEUR_H
#define DIALOG_AUTEUR_H

#include <QDialog>
#include "auteur.h"

namespace Ui {
class Dialog_auteur;
}

class Dialog_auteur : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_auteur(QWidget *parent = nullptr);
    ~Dialog_auteur();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_comboBox_auteur_currentIndexChanged(const QString &arg1);

    void on_pushButton_chercher_clicked();

    void on_pushButton_Trier_clicked();

private:
    Ui::Dialog_auteur *ui;
    auteur tmpauteur;


};

#endif // DIALOG_AUTEUR_H





