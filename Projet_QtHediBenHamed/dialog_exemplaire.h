#ifndef DIALOG_EXEMPLAIRE_H
#define DIALOG_EXEMPLAIRE_H

#include <QDialog>
#include "exemplaire.h"
namespace Ui {
class Dialog_exemplaire;
}

class Dialog_exemplaire : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_exemplaire(QWidget *parent = nullptr);
    ~Dialog_exemplaire();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

private:
    Ui::Dialog_exemplaire *ui;
    exemplaire tmpexemplaire;
};

#endif // DIALOG_EXEMPLAIRE_H







