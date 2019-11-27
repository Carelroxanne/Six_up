# Six_up
I-library
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <emprunt.h>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_10_clicked()
{
    int id_emprunt = ui->lineEdit->text().toInt();
    int id_livre = ui->lineEdit_2->text().toInt();
    QString date = ui->lineEdit_3->text();\
    QString heure = ui->lineEdit_4->text();
    Emprunt e(id_emprunt,id_livre,date,heure);
    if(e.ajouter())
    {
        QMessageBox::information(this,"succes","qjoute avec succes");
    }else{
        QMessageBox::warning(this,"erreur","error");
    }


}

void MainWindow::on_pushButton_5_clicked() //fonction afficher
{
    ui->stackedWidget_2->setCurrentIndex(1);
    Emprunt e;
    ui->tableView->setModel(e.afficher());
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pushButton_8_clicked()
{
    int id_emprunt = ui->lineEdit_5->text().toInt();
    Emprunt e;
    int reponse = QMessageBox::question(this,"onssss","voulez vous supp",QMessageBox::Yes | QMessageBox::No);
    if(reponse == QMessageBox::Yes)
    {
        if(e.supprimer(id_emprunt))
        {
            QMessageBox::information(this,"succes","supprime avec succes");
        }else{
            QMessageBox::warning(this,"erreur","error");
        }
    }
    else
    {
        QMessageBox::information(this,"succes","suppression annulee");
    }
    /**/
}

void MainWindow::on_pushButton_20_clicked()
{
    
}
