#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QString>
class Employe
{
public:
    Employe();
    Employe(int,QString,QString,QString);
        int getcin();
        QString getnom();
        QString getemail();
        QString getdatedenaissance();
        void setcin(int);
        void setnom(QString);
        void setemail(QString);
        void setdatedenaissance(QString);

        bool ajouter();
        QSqlQueryModel *afficher();
        bool supprimer(int);
    private:

        int cin;

        QString nom,email,datedenaissance;

};

#endif // EMPLOYE_H
