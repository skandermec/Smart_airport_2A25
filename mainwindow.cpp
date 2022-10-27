#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 ui->le_cin->setValidator(new QIntValidator(100, 99999999, this));
ui->tab_employe->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_pb_ajouter_clicked()
{
    int cin=ui->le_cin->text().toInt();
    QString nom=ui->le_nom->text();
    QString email=ui->le_email->text();
    QString date=ui->le_date->text();

    Employe E(cin,nom,email,date);

bool test=E.ajouter();
QMessageBox msgBox;
if(test)
    msgBox.setText("Ajout avec succes.");
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
    }


void MainWindow::on_pb_supprimer_clicked()
{
int cin =ui->le_cin_supp->text().toInt();
bool test=Etmp.supprimer(cin);
if(test)
{
   QMessageBox::information(nullptr,QObject::tr("ok"),
                            QObject::tr("suppression effectuee \n"
                                        "click Cancel to exit."), QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                           QObject::tr("suppression non effectuee.\n"
                                  "click Cancel to exit."),QMessageBox::Cancel);
}


