#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"bagages.h"
#include<QMessageBox>
#include<QIntValidator>
#include <QPdfWriter>
#include <QPrinter>
#include <QPainter>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <strstream>
#include <QSystemTrayIcon>
#include <QRegExpValidator>
#include <QDesktopServices>
#include <QUrl>
#include <QPdfWriter>
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QSqlQuery>
#include <QComboBox>
#include <QString>
#include "smtp.h"
#include <QSystemTrayIcon>
#include"his.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    Bagages B;
    ui->le_poids->setValidator(new QIntValidator(0,999999999,this));
    ui->tab_bagages->setModel(B.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QString nom_proprietaire=ui->le_np->text();
    int poids=ui->le_poids->text().toInt();
    QString type=ui->le_type->text();
    Bagages B(nom_proprietaire,poids,type);

    if(B.ajouter())
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("ajout effectué\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);


 ui->tab_bagages->setModel(B.afficher());

    }
    else QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                               QObject::tr("Ajout non effectué.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);}





void MainWindow::on_pushButton_2_clicked()
{
    Bagages B1; B1.setnom_proprietaire(ui->lineEdit_4->text());
    bool test=B1.supprimer(B1.getnom_proprietaire());
    QMessageBox msgBox;
    if(test)
    {
        msgBox.setText(("Suppression avec succes "));
      ui->tab_bagages->setModel(B.afficher());


    }
       else
        msgBox.setText(("Eches de suppression"));
                msgBox.exec();
}



void MainWindow::on_pushButton_3_clicked()
{
    Bagages B;

       QString nom_proprietaire=ui->lineEdit_5->text();
        B.setpoids(ui->lineEdit_6->text().toInt());
        QString type=ui->lineEdit_7->text();

       bool test=B.modifier(B.getnom_proprietaire(),B.getpoids(),B.gettype());

       QMessageBox msgBox;


       if(test)
       {msgBox.setText("Modification avec succés.");
       ui->tab_bagages->setModel(B.afficher());

       }
       else msgBox.setText("Echec de modification");
       msgBox.exec();
}




void MainWindow::on_pushButton_4_clicked()
{
        Bagages B;
        ui->tableView->setModel(B.tribagages());

}





void MainWindow::on_pushButton_pdf_clicked()
{
    QPdfWriter pdf("C:/Atelier_Connexion/bagages.pdf");

              QPainter painter(&pdf);
              int i = 4000;
                     painter.setPen(Qt::darkCyan);
                     painter.setFont(QFont("Time New Roman", 25));
                     painter.drawText(3000,1400,"Listes des bagages");
                     painter.setPen(Qt::black);
                     painter.setFont(QFont("Time New Roman", 15));
                     painter.drawRect(100,100,9400,2500);
                     painter.drawRect(100,3000,9400,500);
                     painter.setFont(QFont("Time New Roman", 9));
                     painter.drawText(400,3300,"nom_proprietaire");
                     painter.drawText(1350,3300,"poids");
                     painter.drawText(2200,3300,"type");
                     painter.drawRect(100,3000,9400,9000);

                     QSqlQuery query;
                     query.prepare("select * from Bagages");
                     query.exec();
                     while (query.next())
                     {
                         painter.drawText(400,i,query.value(0).toString());
                         painter.drawText(1350,i,query.value(1).toString());
                         painter.drawText(2300,i,query.value(2).toString());
                         painter.drawText(3400,i,query.value(3).toString());
                         painter.drawText(4400,i,query.value(4).toString());
                         painter.drawText(6200,i,query.value(5).toString());




                        i = i + 350;
                     }
                     QMessageBox::information(this, QObject::tr("PDF Saved Successfuly!"),
                     QObject::tr("PDF Saved Successfuly!.\n" "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_5_clicked()
{
    Bagages b;
          QString s1;
             QSqlQueryModel *model=b.recherche( ui->lineEdit_ch->text());
              ui->tab_bagages->setModel(model);
}

//void MainWindow::on_pb_envoyer_clicked()
//{
   // Smtp* smtp = new Smtp("zitouni.badr1103@gmail.com", "vanguards", "smtp.gmail.com", 465);

   // smtp->sendMail("zitouni.badr1103@gmail.com", ui->a1->text() , ui->a2->text() ,ui->a3->toPlainText());
//}

/*void MainWindow::on_pushButton_6_clicked()
{
    his=new his(this);
                           his->show();
                           his m;
                         m.readfile();
}*/
