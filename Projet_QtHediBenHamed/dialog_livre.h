#ifndef DIALOG_LIVRE_H
#define DIALOG_LIVRE_H

#include <QDialog>
#include "livre.h"


namespace Ui {
class Dialog_livre;
}

class Dialog_livre : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_livre(QWidget *parent = nullptr);
    ~Dialog_livre();

private slots:
    void on_pushButton_ajouter_2_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_clicked();

    void on_comboBox_livre_currentIndexChanged(const QString &arg1);

    void on_pushButton_chercher_clicked();

    void on_pushButton_ajouter_4_clicked();

private:
    Ui::Dialog_livre *ui;
    livre tmplivre;
};

#endif // DIALOG_LIVRE_H




