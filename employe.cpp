#include "employe.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Employe::Employe()
{
cin=0; nom=" "; email=" " ; datedenaissance=" ";
}

Employe::Employe(int cin,QString nom,QString email,QString datedenaissance)
{this->cin=cin;this->nom=nom;this->email=email;this->datedenaissance=datedenaissance; }



bool Employe::ajouter()
{
    QSqlQuery query;
    QString res =QString::number(cin);
          query.prepare("INSERT INTO employe(cin, nom, email,datedenaissance) "
                        "VALUES (:CIN, :NOM, :EMAIL,:DATEDENAISSANCE)");
          query.bindValue(0,res);
          query.bindValue(1, nom);
          query.bindValue(2, email);
          query.bindValue(3, datedenaissance);
      return query.exec();
}

bool Employe::supprimer(int cin)
{

    QSqlQuery query;
QString res =QString::number(cin);
          query.prepare("Delete from employe where cin=:cin");
          query.bindValue(":cin",res);

      return query.exec();


}



QSqlQueryModel * Employe::afficher()
       {
    QSqlQueryModel * model=new QSqlQueryModel();

  model->setQuery("SELECT* FROM employe");
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("EMAIL"));
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATEDENAISSANCE"));


    return model;

       }





