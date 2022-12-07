#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QString>




class Employe
{
public:
    Employe();
    Employe(int,QString,QString,int,int);
        int getcin();
        QString getnom();
        QString getemail();
        int getdatedenaissance();

        int getsalaire();

        void setcin(int);
        void setnom(QString);
        void setemail(QString);
        void setdatedenaissance(int);

        void setsalaire(int);

        bool ajouter();
         QSqlQueryModel *afficher();
        bool supprimer(int);
      int cherche_cin(int );
QSqlQueryModel *afficher1();
QSqlQueryModel * tri_cin();
QSqlQueryModel *tri_nom();
QSqlQueryModel * tri_datedenaissance();
QSqlQueryModel * salaire1();




    private:

        int cin,datedenaissance,salaire;

        QString nom,email;


};

#endif // EMPLOYE_H
