#ifndef VOYAGEUR_H
#define VOYAGEUR_H
#include<QString>
#include <QDateTime>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>
#include<QSqlQueryModel>
class Voyageur
{
public:

    Voyageur();
    Voyageur(int,QString,QString,int);
    int getN_Passeport();

    QString getnom();

    QString gete_mail();
 int getdatedenaissance();

    void setN_Passeport(int);

    void setnom(QString);

    void sete_mail(QString);
void setdatedenaissance(int);
    bool ajouter();

   QSqlQueryModel *afficher2();
    bool supprimer2(int);
    QSqlQueryModel *afficher5();
    int cherche_N_Passeport (int);
    QSqlQueryModel *tri_N_Passeport();
     void genererPDFact();

private:
    int N_Passeport,datedenaissance;
    QString  nom,e_mail;

};

#endif // VOYAGEUR_H
