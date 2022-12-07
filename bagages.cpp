#include "bagages.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include <QPdfWriter>
#include <QPainter>
#include <iostream>
using namespace  std;

Bagages::Bagages()
{
    nom_proprietaire="";
    poids=0;
    type="";
}
Bagages::Bagages(QString nom_proprietaire,int poids,QString type)
{
    this->nom_proprietaire=nom_proprietaire;
    this->poids=poids;
    this->type=type;
}
QString Bagages::getnom_proprietaire(){return nom_proprietaire;}
int Bagages::getpoids( ){return poids;}

QString Bagages::gettype(){return type;}
void Bagages::setnom_proprietaire(QString nom_proprietaire){this->nom_proprietaire=nom_proprietaire;}
void Bagages::setpoids(int poids){this->poids=poids;}
void Bagages::settype(QString type){this->type=type;}



bool Bagages::ajouter()
{
    QSqlQuery query;

         query.prepare("INSERT INTO Bagages(nom_proprietaire, poids, type) "
                       "VALUES (:nom_proprietaire, :poids, :type)");
         query.bindValue(":nom_proprietaire",nom_proprietaire);
         query.bindValue(":poids", poids);
         query.bindValue(":type", type);

           return query.exec();
}




bool Bagages::supprimer(QString nom_proprietaire)
{
    QSqlQuery query;
    query.prepare("Delete from Bagages where nom_proprietaire=:nom_proprietaire");
    query.bindValue(0,nom_proprietaire);
    return query.exec(); }


    QSqlQueryModel* Bagages::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();


           model->setQuery("SELECT* FROM BAGAGES");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom_proprietaire"));//ajouter le nom de tableau
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("poids"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
        return model;

    }

bool Bagages::modifier(QString nom_proprietaire,int poids,  QString type)
{
    QSqlQuery query;
    QString id_string=QString::number(poids);
    query.prepare("update Bagages set nom_proprietaire=:nom_proprietaire, poids=:poids,type=type");
    query.bindValue(":nom_proprietaire", nom_proprietaire);
    query.bindValue(":poids", poids);
    query.bindValue(":type", type);

    return    query.exec();

}

QSqlQueryModel *Bagages::tribagages()
{
    QSqlQueryModel * model=new QSqlQueryModel();
 model->setQuery("select * from Bagages order by poids" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom_proprietaire"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("poids"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));

    return model;
}
QSqlQueryModel * Bagages::recherche(QString data)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM BAGAGES  where  nom_proprietaire='"+data+"' OR poids='"+data+"' OR type='"+data+"'  ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom_proprietaire"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("poids"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));



    return model;
}

