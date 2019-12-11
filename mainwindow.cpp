#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Achat.h"
#include "vente.h"
#include <QMessageBox>
#include<QSystemTrayIcon>
#include <QString>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabachat->setModel(tmpachat.afficher());

mysystem= new QSystemTrayIcon(this);
 mysystem->setVisible(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int NUM_ACHAT= ui->lineEdit_id->text().toInt();
    QString DATE_ACHAT= ui->lineEdit_nom->text();

  ACHATS e(NUM_ACHAT,DATE_ACHAT);
  bool test=e.ajouter();
  if(test)

{mysystem->showMessage(tr("Notification"),tr("ajouter avec succes"));
      ui->tabachat->setModel(tmpachat.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un ACHATS"),
                  QObject::tr("ACHATS ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un ACHATS"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
int NUM_ACHAT = ui->lineEdit_id_2->text().toInt();
bool test=tmpachat.supprimer(NUM_ACHAT);
if(test)
{
    mysystem->showMessage(tr("Notification"),tr("supprimer avec succes"));
    ui->tabachat->setModel(tmpachat.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un ACHATS"),
                QObject::tr("ACHATS supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un ACHATS"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
void MainWindow::on_pushButton_mod_clicked()
{
    int NUM_ACHAT = ui->lineEdit_3->text().toInt();
    QString DATE_ACHAT = ui->lineEdit->text();


    bool test=tmpachat. modifier(NUM_ACHAT,DATE_ACHAT);
       if (test)
       {mysystem->showMessage(tr("Notification"),tr("modifier avec succes"));
            ui->tabachat->setModel( tmpachat.afficher());
}
}





void MainWindow::on_pb_ajouter_2_clicked()
{
    int NUM_VENTE= ui->lineEdit_id_3->text().toInt();
    QString DATE_VENTE= ui->lineEdit_nom_2->text();

  VENTE v(NUM_VENTE,DATE_VENTE);
  bool test=v.ajouter();
  if(test)
{mysystem->showMessage(tr("Notification"),tr("ajouter avec succes"));
      ui->tabvente->setModel(tmpvente.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un VENTE"),
                  QObject::tr("VENTE ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un VENTE"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_2_clicked()
{
    int NUM_VENTE = ui->lineEdit_id_4->text().toInt();
    bool test=tmpvente.supprimer(NUM_VENTE);
    if(test)
    {mysystem->showMessage(tr("Notification"),tr("supprimer avec succes"));
        ui->tabvente->setModel(tmpvente.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un VENTE"),
                    QObject::tr("VENTE supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un VENTE"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}







void MainWindow::on_pushButton_modve_clicked()
{
    int NUM_VENTE = ui->lineEdit_4->text().toInt();
    QString DATE_VENTE= ui->lineEdit_2->text();


    bool test=tmpvente. modifier(NUM_VENTE,DATE_VENTE);
       if (test)
       {mysystem->showMessage(tr("Notification"),tr("modifier avec succes"));
            ui->tabvente->setModel( tmpvente.afficher());
}
}

void MainWindow::on_pushButton_rechv_clicked()
{
    int NUM_VENTE;

        NUM_VENTE=ui->lineEdit_5->text().toInt();
    bool test= true;
    if(test==(true))
    {
      ui->tabrechv->setModel(tmprechv.Rechercher(NUM_VENTE));
    }
}

void MainWindow::on_pushButton_rechac_clicked()
{ int NUM_ACHAT;

    NUM_ACHAT=ui->lineEdit_6->text().toInt();
bool test= true;
if(test==(true))
{
  ui->tabrechac->setModel(tmprechac.Rechercher(NUM_ACHAT));
}

}

void MainWindow::on_pushButton_tri_clicked()
{
    ui->tabvente->setModel(tmpvente.afficher_tri());
}

void MainWindow::on_pushButton_tri_achat_clicked()
{
    ui->tabachat->setModel(tmpachat.afficher_tri_achat());
}
