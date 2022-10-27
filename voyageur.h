#ifndef VOYAGEUR_H
#define VOYAGEUR_H
#include<QString>
#include <QDateTime>

class Voyageur
{
public:

    Voyageur();
    Voyageur(int,int,QString,QString,QDate,QString,QString,QString);
    int getnum_reservation();
    int getN_Passeport();
    QString getprenom();
    QString getnom();
    QDate getbirthday();
    QString getgenre();
    QString gete_mail();
    QString getnationalite();
    void setnum_reservation(int);
    void setN_Passeport(int);
    void setprenom(QString);
    void setnom(QString);
    void setbirthday(QDate);
    void setgenre(QString);
    void sete_mail(QString);
    void setnationalite(QString);
    bool ajouter();
private:
    int num_reservation,N_Passeport;
    QString  prenom,nom,genre,e_mail,nationalite;
    QDate birthday;
};

#endif // VOYAGEUR_H
