#ifndef BAGAGES_H
#define BAGAGES_H
#include<QString>
#include<QSqlQueryModel>


class Bagages
{
public:
    Bagages();
    Bagages(QString,int,QString);
    int getpoids();
    QString getnom_proprietaire();
    QString gettype();
    void setnom_proprietaire(QString);
    void setpoids(int);
    void settype(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier(QString nom_proprietaire,int poids,QString type);
    QSqlQueryModel * tribagages();
    QSqlQueryModel *  recherche(QString data);

private:
QString nom_proprietaire;
int poids;
QString type;
};

#endif // BAGAGES_H
