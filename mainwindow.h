#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Achat.h"
#include <QMainWindow>
#include<QSystemTrayIcon>
#include"vente.h"

namespace Ui {
class MainWindow;
}
class QSystemTrayIcon;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();


    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pushButton_modve_clicked();
    void on_pushButton_mod_clicked();



    void on_pushButton_rechv_clicked();

    void on_pushButton_rechac_clicked();

    void on_pushButton_tri_clicked();

    void on_pushButton_tri_achat_clicked();

private:
    Ui::MainWindow *ui;
    ACHATS tmpachat;
      QSystemTrayIcon * mysystem;
      VENTE tmpvente;
      VENTE tmprechv;
      ACHATS tmprechac;
};

#endif // MAINWINDOW_H
