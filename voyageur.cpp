
#include "voyageur.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>
#include <QSqlRecord>
#include<QPainter>
#include<QPdfWriter>
Voyageur::Voyageur()
{
N_Passeport=0; nom=" "; e_mail="";datedenaissance=0;

}

Voyageur::Voyageur(int N_Passeport, QString nom,QString e_mail,int datedenaissance)
{this->N_Passeport=N_Passeport;this->nom=nom;this->e_mail=e_mail;this->datedenaissance=datedenaissance; }

int Voyageur::getN_Passeport(){return N_Passeport;}

QString Voyageur::getnom(){return nom;}

QString Voyageur::gete_mail(){return e_mail;}
int Voyageur::getdatedenaissance(){return datedenaissance;}


void Voyageur::setN_Passeport(int N_Passeport){this->N_Passeport=N_Passeport;}
void Voyageur::setnom(QString nom){this->nom=nom;}
void Voyageur::sete_mail(QString e_mail){this->e_mail=e_mail;}
void Voyageur::setdatedenaissance(int datedenaissance){this->datedenaissance=datedenaissance;}

bool Voyageur::ajouter()
{
    QSqlQuery query;
QString  N_Passeport_string =QString::number( N_Passeport);
QString datedenaissance_string =QString::number(datedenaissance);

          query.prepare("INSERT INTO VOYAGEUR(N_PASSEPORT, NOM,E_MAIL,DATEDENAISSANCE) "
                        "VALUES (:N_PASSEPORT, :NOM,:E_MAIL, :DATEDENAISSANCE)");
          query.bindValue(":N_PASSEPORT",N_Passeport);
          query.bindValue(":NOM", nom);
          query.bindValue(":E_MAIL", e_mail);
          query.bindValue(":DATEDENAISSANCE", datedenaissance);

      return query.exec();


}



QSqlQueryModel * Voyageur::afficher2()
       {
    QSqlQueryModel * model=new QSqlQueryModel();

  model->setQuery("SELECT* FROM voyageur ");
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("N_PASSEPORT"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("EMAIL"));
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATEDENAISSANCE"));


    return model;

       }

bool Voyageur::supprimer2(int N_Passeport)
{

    QSqlQuery query;
QString res =QString::number(N_Passeport);
          query.prepare("Delete from voyageur where N_PASSEPORT=:N_PASSEPORT");
          query.bindValue(":N_PASSEPORT",res);

      return query.exec();


}
QSqlQueryModel * Voyageur::afficher5()
{
    QSqlQueryModel * model=new QSqlQueryModel();

  model->setQuery("select * from voyageur where  N_Passeport = "+QString::number(N_Passeport) );
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("N_PASSEPORT"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("EMAIL"));
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATEDENAISSANCE"));

    return model;

       }


int Voyageur::cherche_N_Passeport(int N_Passeport)
{


            QSqlQuery q("select * from voyageur where N_PASSEPORT = "+QString::number(N_Passeport) );
                     QSqlRecord rec = q.record();

                     qDebug() << "Number of columns: " << rec.count();

                     int nameCol = rec.indexOf("N_PASSEPORT"); // index of the field "name"
                     while (q.next()){

                         qDebug() << q.value(nameCol).toString();
                         QString a= q.value(nameCol).toString();
                         if(a!=""){

                               return true;

               }
               }
                       return false;
}



QSqlQueryModel * Voyageur::tri_N_Passeport()
   {QSqlQueryModel * model= new QSqlQueryModel();

   model->setQuery("select * from voyageur order by N_Passeport");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("N_Passeport"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("e_mail"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("datedenaissance"));

       return model;
   }
void Voyageur::genererPDFact()
{
   QPdfWriter pdf("C://Users//mechiche//Desktop//projet//gestion_des_voyageurs//PDF.pdf");
    QPainter painter(&pdf);
   int i = 4000;
        painter.setPen(Qt::green);
        painter.setFont(QFont("Arial", 50));
        painter.drawText(1100,1200,"Liste Des Espaces");
        painter.setPen(Qt::red);
        painter.setFont(QFont("Arial", 15));
        painter.drawRect(100,100,7300,2600);
        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(200,3300,"N_Passeport");
        painter.drawText(1300,3300,"nom");

           painter.drawText(3500,3300,"e_mail");
              painter.drawText(4600,3300,"datedenaissance");

        QSqlQuery query;
        query.prepare("select * from VOYAGEUR");
        query.exec();
        while (query.next())
        {
            painter.drawText(200,i,query.value(0).toString());
            painter.drawText(1300,i,query.value(1).toString());
            painter.drawText(2400,i,query.value(2).toString());
            painter.drawText(3500,i,query.value(3).toString());
            painter.drawText(4600,i,query.value(4).toString());


           i = i + 500;
        }


}
