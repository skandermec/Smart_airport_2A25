#include "employe.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>
#include <QSqlRecord>
Employe::Employe()
{
cin=0; nom=" "; email=" " ;datedenaissance=0;salaire=0;

}

Employe::Employe(int cin, QString nom, QString email, int datedenaissance, int salaire)
{this->cin=cin;this->nom=nom;this->email=email;this->datedenaissance=datedenaissance;this->salaire=salaire; }
int Employe::getcin(){return cin;}
QString Employe::getnom(){return nom;}
QString Employe::getemail(){return email;}
int Employe::getdatedenaissance(){return datedenaissance;}
int Employe::getsalaire(){return salaire;}
void Employe::setcin(int cin){this->cin=cin;}
void Employe::setnom(QString nom){this->nom=nom;}
void Employe::setemail(QString email){this->email=email;}
void Employe::setdatedenaissance(int datedenaissance){this->datedenaissance=datedenaissance;}
void Employe::setsalaire(int salaire){this->salaire=salaire;}

bool Employe::ajouter()
{
    QSqlQuery query;
QString cin_string =QString::number(cin);
QString datedenaissance_string =QString::number(datedenaissance);
QString salaire_string =QString::number(salaire);
          query.prepare("INSERT INTO employe(CIN, NOM, EMAIL,DATEDENAISSANCE,SALAIRE) "
                        "VALUES (:CIN, :NOM, :EMAIL,:DATEDENAISSANCE,:SALAIRE)");
          query.bindValue(":CIN",cin_string);
          query.bindValue(":NOM", nom);
          query.bindValue(":EMAIL", email);
          query.bindValue(":DATEDENAISSANCE", datedenaissance_string);
query.bindValue(":SALAIRE", salaire_string);
      return query.exec();


}

bool Employe::supprimer(int cin)
{

    QSqlQuery query;
QString res =QString::number(cin);
          query.prepare("Delete from employe where CIN=:CIN");
          query.bindValue(":CIN",res);

      return query.exec();


}



QSqlQueryModel * Employe::afficher()
       {
    QSqlQueryModel * model=new QSqlQueryModel();

  model->setQuery("SELECT* FROM employe ");
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("EMAIL"));
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATEDENAISSANCE"));
  model->setHeaderData(4,Qt::Horizontal,QObject::tr("SALAIRE"));

    return model;

       }
QSqlQueryModel * Employe::afficher1()
{
    QSqlQueryModel * model=new QSqlQueryModel();

  model->setQuery("select * from employe where  CIN = "+QString::number(cin) );
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("EMAIL"));
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATEDENAISSANCE"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("SALAIRE"));

    return model;

       }


int Employe::cherche_cin(int cin)
{


            QSqlQuery q("select * from employe where  CIN = "+QString::number(cin) );
                     QSqlRecord rec = q.record();

                     qDebug() << "Number of columns: " << rec.count();

                     int nameCol = rec.indexOf("CIN"); // index of the field "name"
                     while (q.next()){

                         qDebug() << q.value(nameCol).toString();
                         QString a= q.value(nameCol).toString();
                         if(a!=""){

                               return true;

               }
               }
                       return false;
}



QSqlQueryModel * Employe::tri_cin()
   {QSqlQueryModel * model= new QSqlQueryModel();

   model->setQuery("select * from employe order by cin");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("email"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("datedenaissance"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("SALAIRE"));
       return model;
   }


QSqlQueryModel * Employe::tri_nom()
   {QSqlQueryModel * model= new QSqlQueryModel();

   model->setQuery("select * from employe order by nom");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("email"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("datedenaissance"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("SALAIRE"));
       return model;
   }
QSqlQueryModel * Employe::tri_datedenaissance()
   {QSqlQueryModel * model= new QSqlQueryModel();

   model->setQuery("select * from employe order by datedenaissance");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("email"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("datedenaissance"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("SALAIRE"));
       return model;
   }





QSqlQueryModel * Employe::salaire1()
   {QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
int sum = 0;
   model->setQuery("SELECT SUM(salaire) AS SALAIRE_total FROM employe");

   query.bindValue(":salaire", sum);


 model->setHeaderData(0,Qt::Horizontal,QObject::tr("SALAIRE TOTALE"));

       return model;
   }













