#ifndef DIALOG_VENTE_H
#define DIALOG_VENTE_H

#include <QDialog>

namespace Ui {
class Dialog_vente;
}

class Dialog_vente : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_vente(QWidget *parent = nullptr);
    ~Dialog_vente();

private:
    Ui::Dialog_vente *ui;
};

#endif // DIALOG_VENTE_H
