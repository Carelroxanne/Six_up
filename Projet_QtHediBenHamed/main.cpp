#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connexion c;
    try {
       bool t= c.createconnect();
        qDebug()<<"connexion valide"<<t;

        w.show();

    } catch (QString s) {
        qDebug()<<s;

    }



    return a.exec();
}



