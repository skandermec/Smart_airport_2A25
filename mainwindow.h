#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "employe.h"
#include<QDate>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QtCharts>
#include <QTextBrowser>
#include "voyageur.h"
#include "notification.h"
#include"bagages.h"

QT_BEGIN_NAMESPACE
class QTextBrowser;
QT_END_NAMESPACE
QT_BEGIN_NAMESPACE
class QAbstractItemModel;
class QAbstractItemView;
QT_END_NAMESPACE






namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:




    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_chercher_clicked();

    void on_pb_modifier_clicked();

    void on_pb_tri_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pb_pdf_clicked();



    void on_pb_calcul_clicked();




void on_pushButton_3_clicked();



void on_pb_LESTAT_clicked();


void on_cal_clicked();

void setFontSize(int size);
    void setMonth(int month);
    void setYear(QDate date);

    void on_ajouter_voyageur_clicked();

    void on_modifier_voyageur_clicked();

    void on_pb_supprimer_voyageur_clicked();

    void on_pb_chercher_2_clicked();

    void on_pb_tri_2_clicked();

    void on_pb_pdfvoyageur_clicked();

    void on_pb_statvoyageur_2_clicked();
    //bagages

    void on_bagages_ajouter_clicked();

    void on_bagages_supprimer_clicked();

    void on_bagages_modifier_clicked();

    void on_bagages_pdf_clicked();

    void on_bagages_recherche_clicked();

    void on_bagages_tri_clicked();


private:
void insertCalendar(); int fontSize; QDate selectedDate;
QTextBrowser *editor;



    Ui::MainWindow *ui;

    Employe E;
    Employe Etmp;
    Voyageur V;
 notification n;
 Bagages B;





};

#endif // MAINWINDOW_H
