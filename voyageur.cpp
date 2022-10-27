#include "voyageur.h"
#include<QString>
#include<QDateTime>

Voyageur::Voyageur()
{
num_reservation=0;N_Passeport=0;nom=" ";prenom=" ";birthday=QDate();genre=" ";
e_mail="";nationalite=" ";
}
Voyageur::Voyageur(int num_reservation,int N_Passeport,QString prenom,QString nom,QDate birthday,QString genre,QString e_mail,QString nationalite)
{
this->num_reservation=num_reservation;this->N_Passeport=N_Passeport;
   this->prenom=prenom;this->nom=nom;this->birthday=birthday;this->genre=genre;this->e_mail=e_mail;this->nationalite=nationalite;
}
int Voyageur:: getnum_reservation() {return num_reservation;}
int Voyageur::getN_Passeport(){return N_Passeport;}
QString Voyageur::getprenom(){return prenom;}
QString Voyageur::getnom(){return nom;}
QDate Voyageur::getbirthday(){return birthday;}
QString Voyageur::getgenre(){return genre;}
QString Voyageur::gete_mail(){return e_mail;}
QString Voyageur::getnationalite(){return nationalite;}
void Voyageur::setnum_reservation(int num_reservation){this->num_reservation=num_reservation;}
void Voyageur::setN_Passeport(int N_Passeport){this->N_Passeport=N_Passeport;}
void Voyageur::setprenom(QString prenom){this->prenom=prenom;}
void Voyageur::setnom(QString nom){this->nom=nom;}
void Voyageur::setbirthday(QDate birthday){this->birthday=birthday;}
void Voyageur::setgenre(QString genre){this->genre=genre;}
void Voyageur::sete_mail(QString e_mail){this->e_mail=e_mail;}
void Voyageur::setnationalite(QString nationalite){this->nationalite=nationalite;}
bool Voyageur::ajouter()
{
    bool test=false;




    return test;
}
