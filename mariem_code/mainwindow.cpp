#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "connexion.h"
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer =new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();

    //LOGO


    QPixmap pic("D:/esprit/2eme/projet/book1.png");
    int w=ui->label_picture->width();
    int h=ui->label_picture->height();
    ui->label_picture->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));

    //USER
    QPixmap pic1("D:/esprit/2eme/projet/user2.png");
    int w1=ui->label_Pseudo->width();
    int h1=ui->label_Pseudo->height();
    ui->label_Pseudo->setPixmap(pic1.scaled(w1,h1,Qt::KeepAspectRatio));

    //Blocus
    QPixmap pic2("D:/esprit/2eme/projet/bloqus.png");
    int w2=ui->label_Mdp->width();
    int h2=ui->label_Mdp->height();
    ui->label_Mdp->setPixmap(pic2.scaled(w2,h2,Qt::KeepAspectRatio));

}
void MainWindow::showTime()
{


    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    ui->Digital_Clock->setText(time_text);

}


MainWindow::~MainWindow()
{
    delete ui;
}









void MainWindow::on_pushButton_connex_clicked()
{


    QSqlQuery query;
         QString Pseudo ,Mot_de_passe ;
         Pseudo=ui->lineEdit_Pseudo->text();
         Mot_de_passe=ui->lineEdit_Mdp->text();
         if(query.exec(("select * from Personnel where Pseudo ='"+Pseudo+"'and  Mot_de_passe = '"+Mot_de_passe+"'")))
         {
             int count=0;
             while (query.next())
             {
                 count++;
             }
             if(count==1)
             {
                 hide();
               connexion= new Dialog_home(this);
               connexion->show();

             }
               else
             {QMessageBox::warning(this,"Login","Username Or Password is not correct");}

         }
}

void MainWindow::on_pushButton_inscr_clicked()
{
       inscrire= new Dialog_inscription(this);
       inscrire->show();
}
