#ifndef DIALOG_DEPARTEMENT_H
#define DIALOG_DEPARTEMENT_H

#include "departement.h"
#include <QDialog>

namespace Ui {
class Dialog_departement;
}

class Dialog_departement : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_departement(QWidget *parent = nullptr);
    ~Dialog_departement();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_supprimer_clicked();
    void on_pushButton_chercher_clicked();

    void on_pushButton_Trier_clicked();

private:
    Ui::Dialog_departement *ui;
    departement tmpdepartement;
};

#endif // DIALOG_DEPARTEMENT_H




