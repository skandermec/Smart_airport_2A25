#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <strstream>
#include <QSystemTrayIcon>
#include <QRegExpValidator>
#include <QDesktopServices>
#include <QUrl>
#include <QPdfWriter>
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QSqlQuery>
#include <QValidator>
#include"pieview.h"
#include<QStandardItemModel>
#include<QSplitter>
#include <QtWidgets>

#include <QtWidgets>



#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QtCharts>


#include <QCalendarWidget>
#include <QCheckBox>
#include <QComboBox>
#include <QDateEdit>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLocale>
#include <QTextCharFormat>
#include <QWidget>


#include "voyageur.h"
//bagages

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"bagages.h"
#include<QMessageBox>
#include<QIntValidator>
#include <QPdfWriter>
#include <QPrinter>
#include <QPainter>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <strstream>
#include <QSystemTrayIcon>
#include <QRegExpValidator>
#include <QDesktopServices>
#include <QUrl>
#include <QPdfWriter>
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QSqlQuery>
#include <QComboBox>
#include <QString>
#include <QSystemTrayIcon>
#include"bagages.h"

//bagages
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"bagages.h"
#include<QMessageBox>
#include<QIntValidator>
#include <QPdfWriter>
#include <QPrinter>
#include <QPainter>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <strstream>
#include <QSystemTrayIcon>
#include <QRegExpValidator>
#include <QDesktopServices>
#include <QUrl>
#include <QPdfWriter>
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QSqlQuery>
#include <QComboBox>
#include <QString>
#include <QSystemTrayIcon>
#include"bagages.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{








    ui->setupUi(this);
   // QRegularExpression QRegExp( "[a-zA-Z]+");
     //   QRegularExpressionValidator *validator = new QRegularExpressionValidator(QRegExp,this);
     //   ui->le_nom->setValidator(validator);
//ui->le_nom2->setValidator(validator);

 ui->le_cin->setValidator(new QIntValidator(0, 99999999, this));
 ui->le_cin_supp->setValidator(new QIntValidator(100, 99999999, this));
 ui->le_cin_mod->setValidator(new QIntValidator(100, 99999999, this));
 ui->le_cin2->setValidator(new QIntValidator(100, 99999999, this));

ui->tab_employe->setModel(E.afficher());

ui->tab_voyageur_tri_2->setModel(V.afficher2());
Bagages b;




}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_pb_ajouter_clicked()
{
    int cin=ui->le_cin->text().toInt();
    QString nom=ui->le_nom->text();
    QString email=ui->le_email->text();
    int datedenaissance=ui->le_date->text().toInt();
int salaire=ui->le_salaire->text().toInt();
    Employe E(cin,nom,email,datedenaissance,salaire);

bool test=E.ajouter();
QMessageBox msgBox;
if(test)
{


    msgBox.setText("Ajout avec succes.");
    ui->tab_employe->setModel(E.afficher());
}
    else
        msgBox.setText("Echec d'ajout");

    msgBox.exec();

    }


void MainWindow::on_pb_supprimer_clicked()
{
int cin =ui->le_cin_supp->text().toInt();
bool test=Etmp.supprimer(cin);
if(test)
{

   QMessageBox::information(nullptr,QObject::tr("ok"),
                            QObject::tr("suppression effectuee \n"
                                        "click Cancel to exit."), QMessageBox::Cancel);
   ui->tab_employe->setModel(E.afficher());
}
else
    QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                           QObject::tr("suppression non effectuee.\n"
                                  "click Cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::on_pb_chercher_clicked()

{
    Employe E1;
        E1.setcin(ui->le_cin_cher->text().toInt());
        bool test1=E1.cherche_cin(E1.getcin());
     ui->tab_employe_cher->setModel(E1.afficher1());
        if(test1){


            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("numero found.\n"
                                    "rechercher effectuer."), QMessageBox::Cancel);


        }
        else
               QMessageBox::critical(nullptr, QObject::tr("nope"),
                           QObject::tr("numero not found .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);




}






void MainWindow::on_pb_modifier_clicked()
{
    {
       Employe E1;
            E1.setcin(ui->le_cin_mod->text().toInt());
            bool test=E1.supprimer(E1.getcin());
            if(!test){
                QMessageBox::critical(nullptr, QObject::tr("nope"),
                            QObject::tr("update failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);



            }
            else
            {   Employe e;
                int cin=ui->le_cin2->text().toInt();
                QString nom=ui->le_nom2->text();
                QString email=ui->le_email2->text();
                int datedenaissance=ui->le_dat2->text().toInt();
               int salaire=ui->le_salaire_2->text().toInt();
                Employe E(cin,nom,email,datedenaissance,salaire);
                bool test=E.ajouter();

          if(test)
{

              QMessageBox::information(nullptr, QObject::tr("ok"),
                          QObject::tr("update successful.\n"
                                      "update effectuer."), QMessageBox::Cancel);
          ui->tab_employe->setModel(E1.afficher());
          }


          else

              QMessageBox::critical(nullptr, QObject::tr("nope"),
                          QObject::tr("update failed.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);}}


}

void MainWindow::on_pb_tri_clicked()
{


        QMessageBox::information(nullptr, QObject::tr("Ok"),
                 QObject::tr("tri effectué.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
                ui->tab_employe_tri->setModel(E.tri_cin());


}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
             QObject::tr("tri effectué.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_employe_tri->setModel(E.tri_nom());
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
             QObject::tr("tri effectué.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_employe_tri->setModel(E.tri_datedenaissance());
}

void MainWindow::on_pb_pdf_clicked()
{

        QPdfWriter pdf("C:/Users/Irn0x/Desktop/Atelier_Connexion/PDF/employe.pdf");

           QPainter painter(&pdf);
           int i = 4000;
                  painter.setPen(Qt::darkCyan);
                  painter.setFont(QFont("Time New Roman", 25));
                  painter.drawText(3000,1400,"LA LISTE DES EMPLOYES");
                  painter.setPen(Qt::black);
                  painter.setFont(QFont("Time New Roman", 15));
                  painter.drawRect(100,100,9400,2500);
                  painter.drawRect(100,3000,9400,500);
                  painter.setFont(QFont("Time New Roman", 9));
                  painter.drawText(400,3300,"CIN");
                  painter.drawText(1350,3300,"NOM");
                  painter.drawText(2200,3300,"EMAIL");
                  painter.drawText(3400,3300,"DATE DE NAISSANCE");
                  painter.drawText(4800,3300,"SALAIRE");

                  painter.drawRect(100,3000,9400,9000);

                  QSqlQuery query;
                  query.prepare("select * from employe");
                  query.exec();
                  while (query.next())
                  {
                      painter.drawText(400,i,query.value(0).toString());
                      painter.drawText(1350,i,query.value(1).toString());
                      painter.drawText(2300,i,query.value(2).toString());
                      painter.drawText(3400,i,query.value(3).toString());
                      painter.drawText(4400,i,query.value(4).toString());
                      painter.drawText(6200,i,query.value(5).toString());




                     i = i + 350;
                  }
                  QMessageBox::information(this, QObject::tr("PDF Saved Successfuly!"),
                  QObject::tr("PDF Saved Successfuly!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }




void MainWindow::on_pb_calcul_clicked()
{
    Employe E1;


     ui->tab_employe_sal->setModel(E1.salaire1());


    QMessageBox::information(nullptr, QObject::tr("Ok"),
             QObject::tr("calcul effectué.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);

}










void MainWindow::on_pb_LESTAT_clicked()
{ QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from EMPLOYE where cin < 100 ");
    float code=model->rowCount();
    model->setQuery("select * from EMPLOYE where cin  between 100 and 1000 ");
    float codee=model->rowCount();
    model->setQuery("select * from EMPLOYE where cin >1000 ");
    float codeee=model->rowCount();
    float total=code+codee+codeee;
    QString a=QString("moins de 100 \t"+QString::number((code*100)/total,'f',2)+"%" );
    QString b=QString("entre 100 et 1000 \t"+QString::number((codee*100)/total,'f',2)+"%" );
    QString c=QString("+1000 \t"+QString::number((codeee*100)/total,'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(a,code);
    series->append(b,codee);
    series->append(c,codeee);
if (code!=0)
{QPieSlice *slice = series->slices().at(0);
slice->setLabelVisible();
slice->setPen(QPen());}
if ( codee!=0)
{
     // Add label, explode and define brush for 2nd slice
     QPieSlice *slice1 = series->slices().at(1);
     //slice1->setExploded();
     slice1->setLabelVisible();
}
if(codeee!=0)
{
     // Add labels to rest of slices
     QPieSlice *slice2 = series->slices().at(2);
     //slice1->setExploded();
     slice2->setLabelVisible();
}
    // Create the chart widget
    QChart *chart = new QChart();
    // Add data to chart with title and hide legend
    chart->addSeries(series);
    chart->setTitle("Pourcentage Par CIN :Nombre Des employe "+ QString::number(total));
    chart->legend()->hide();
    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1000,500);
    chartView->show();

}


void MainWindow::on_cal_clicked()

{

    selectedDate = QDate::currentDate();
        fontSize = 10;

        QWidget *centralWidget = new QWidget;
    //! [0]

    //! [1]
        QLabel *dateLabel = new QLabel(tr("Date:"));
        QComboBox *monthCombo = new QComboBox;

        for (int month = 1; month <= 12; ++month)
            monthCombo->addItem(QLocale::system().monthName(month));

        QDateTimeEdit *yearEdit = new QDateTimeEdit;
        yearEdit->setDisplayFormat("yyyy");
        yearEdit->setDateRange(QDate(1753, 1, 1), QDate(8000, 1, 1));
    //! [1]

        monthCombo->setCurrentIndex(selectedDate.month() - 1);
        yearEdit->setDate(selectedDate);

    //! [2]
        QLabel *fontSizeLabel = new QLabel(tr("Font size:"));
        QSpinBox *fontSizeSpinBox = new QSpinBox;
        fontSizeSpinBox->setRange(1, 64);

        editor = new QTextBrowser;
        insertCalendar();
    //! [2]

    //! [3]
        connect(monthCombo, QOverload<int>::of(&QComboBox::activated),
                this, &MainWindow::setMonth);
        connect(yearEdit, &QDateTimeEdit::dateChanged,
                this, &MainWindow::setYear);
        connect(fontSizeSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
                this, &MainWindow::setFontSize);
    //! [3]

        fontSizeSpinBox->setValue(10);

    //! [4]
        QHBoxLayout *controlsLayout = new QHBoxLayout;
        controlsLayout->addWidget(dateLabel);
        controlsLayout->addWidget(monthCombo);
        controlsLayout->addWidget(yearEdit);
        controlsLayout->addSpacing(24);
        controlsLayout->addWidget(fontSizeLabel);
        controlsLayout->addWidget(fontSizeSpinBox);
        controlsLayout->addStretch(1);

        QVBoxLayout *centralLayout = new QVBoxLayout;
        centralLayout->addLayout(controlsLayout);
        centralLayout->addWidget(editor, 1);
        centralWidget->setLayout(centralLayout);

        setCentralWidget(centralWidget);



}

void MainWindow::insertCalendar()
{
    editor->clear();
    QTextCursor cursor = editor->textCursor();
    cursor.beginEditBlock();

    QDate date(selectedDate.year(), selectedDate.month(), 1);
//! [5]

//! [6]
    QTextTableFormat tableFormat;
    tableFormat.setAlignment(Qt::AlignHCenter);
    tableFormat.setBackground(QColor("#e0e0e0"));
    tableFormat.setCellPadding(2);
    tableFormat.setCellSpacing(4);
//! [6] //! [7]
    QVector<QTextLength> constraints;
    constraints << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14);
    tableFormat.setColumnWidthConstraints(constraints);
//! [7]

//! [8]
    QTextTable *table = cursor.insertTable(1, 7, tableFormat);
//! [8]

//! [9]
    QTextFrame *frame = cursor.currentFrame();
    QTextFrameFormat frameFormat = frame->frameFormat();
    frameFormat.setBorder(1);
    frame->setFrameFormat(frameFormat);
//! [9]

//! [10]
    QTextCharFormat format = cursor.charFormat();
    format.setFontPointSize(fontSize);

    QTextCharFormat boldFormat = format;
    boldFormat.setFontWeight(QFont::Bold);

    QTextCharFormat highlightedFormat = boldFormat;
    highlightedFormat.setBackground(Qt::yellow);
//! [10]

//! [11]
    for (int weekDay = 1; weekDay <= 7; ++weekDay) {
        QTextTableCell cell = table->cellAt(0, weekDay-1);
//! [11] //! [12]
        QTextCursor cellCursor = cell.firstCursorPosition();
        cellCursor.insertText(QLocale::system().dayName(weekDay), boldFormat);
    }
//! [12]

//! [13]
    table->insertRows(table->rows(), 1);
//! [13]

    while (date.month() == selectedDate.month()) {
        int weekDay = date.dayOfWeek();
        QTextTableCell cell = table->cellAt(table->rows()-1, weekDay-1);
        QTextCursor cellCursor = cell.firstCursorPosition();

        if (date == QDate::currentDate())
            cellCursor.insertText(QString("%1").arg(date.day()), highlightedFormat);
        else
            cellCursor.insertText(QString("%1").arg(date.day()), format);

        date = date.addDays(1);
        if (weekDay == 7 && date.month() == selectedDate.month())
            table->insertRows(table->rows(), 1);
    }

    cursor.endEditBlock();
//! [14]
    setWindowTitle(tr("Calendar for %1 %2"
        ).arg(QLocale::system().monthName(selectedDate.month())
        ).arg(selectedDate.year()));
}
//! [14]

//! [15]
void MainWindow::setFontSize(int size)
{
    fontSize = size;
    insertCalendar();
}
//! [15]

//! [16]
void MainWindow::setMonth(int month)
{
    selectedDate = QDate(selectedDate.year(), month + 1, selectedDate.day());
    insertCalendar();
}
//! [16]

//! [17]
void MainWindow::setYear(QDate date)
{
    selectedDate = QDate(date.year(), selectedDate.month(), selectedDate.day());
    insertCalendar();
}
//! [17]



void MainWindow::on_ajouter_voyageur_clicked()
{

    {
        int N_Passeport=ui->passeportv_2->text().toInt();
        QString nom=ui->nomv_2->text();
        QString e_mail=ui->emailv_2->text();
        int datedenaissance=ui->datev_2->text().toInt();

        Voyageur E(N_Passeport,nom,e_mail,datedenaissance);

    bool test=E.ajouter();
    QMessageBox msgBox;
    if(test)
    {

n.notification_ajout();
        msgBox.setText("Ajout avec succes.");
    ui->tab_voyageur_3->setModel(V.afficher2());
    }
        else
            msgBox.setText("Echec d'ajout");

        msgBox.exec();

        }
}

void MainWindow::on_modifier_voyageur_clicked()
{
    Voyageur E1;
                 E1.setN_Passeport(ui->passeport_mod_2->text().toInt());
                 bool test=E1.cherche_N_Passeport(E1.getN_Passeport());
                 if(!test){
                    // n.notification_modifier();
                     QMessageBox::critical(nullptr, QObject::tr("nope"),
                                 QObject::tr("update failed.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);



                 }
                 else
                 {   Voyageur e;
                     int N_Passeport=ui->passeport_mod2_2->text().toInt();
                     QString nom=ui->nom_mod_2->text();
                     QString e_mail=ui->email_mod_2->text();
                     int datedenaissance=ui->date_mod_2->text().toInt();

                     Voyageur E(N_Passeport,nom,e_mail,datedenaissance);
                     bool test=E.ajouter();

               if(test)
     {

                   QMessageBox::information(nullptr, QObject::tr("ok"),
                               QObject::tr("update successful.\n"
                                           "update effectuer."), QMessageBox::Cancel);
                ui->tab_voyageur_3->setModel(V.afficher2());
               }


               else

                   QMessageBox::critical(nullptr, QObject::tr("nope"),
                               QObject::tr("update failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);}}








void MainWindow::on_pb_supprimer_voyageur_clicked()
{
    int N_Passeport =ui->passeportsupp_2->text().toInt();
       bool test=V.supprimer2(N_Passeport);
       if(test)
       {
           n.notification_supprimer();

          QMessageBox::information(nullptr,QObject::tr("ok"),
                                   QObject::tr("suppression effectuee \n"
                                               "click Cancel to exit."), QMessageBox::Cancel);
      ui->tab_voyageur_3->setModel(V.afficher2());
       }
       else
           QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                                  QObject::tr("suppression non effectuee.\n"
                                         "click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pb_chercher_2_clicked()
{
    {

        {
            Voyageur E1;
                E1.setN_Passeport(ui->le_passeport_cher_3->text().toInt());
                bool test1=E1.cherche_N_Passeport(E1.getN_Passeport());
             ui->tab_employe_cher_4->setModel(E1.afficher5());
                if(test1){


                    QMessageBox::information(nullptr, QObject::tr("ok"),
                                QObject::tr("numero found.\n"
                                            "rechercher effectuer."), QMessageBox::Cancel);


                }
                else
                       QMessageBox::critical(nullptr, QObject::tr("nope"),
                                   QObject::tr("numero not found .\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);




        }
}
}

void MainWindow::on_pb_tri_2_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
                       QObject::tr("tri effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
                      ui->tab_voyageur_tri_2->setModel(V.afficher2());
}

void MainWindow::on_pb_pdfvoyageur_clicked()
{ QPdfWriter pdf("C:/Users/Irn0x/Desktop/Atelier_Connexion222/PDF DES VOYAGEURS/PDF DES VOYAGEURS.pdf");

    QPainter painter(&pdf);
    int i = 4000;
           painter.setPen(Qt::red);
           painter.setFont(QFont("Time New Roman", 25));
           painter.drawText(3000,1400,"Liste Des voyageurs");
           painter.setPen(Qt::black);
           painter.setFont(QFont("Time New Roman", 15));
           painter.drawRect(100,3000,9400,500);
           painter.setFont(QFont("Time New Roman", 9));
           painter.drawText(1000,3300,"N_Passeport");
           painter.drawText(2500,3300,"nom");
           painter.drawText(4000,3300,"e_mail");
           painter.drawText(5500,3300,"datedenaissance");

           painter.drawRect(100,3000,9400,9000);

           QSqlQuery query;
           query.prepare("select * from VOYAGEUR");
           query.exec();
           while (query.next())
           {
               painter.drawText(1000,i,query.value(0).toString());
               painter.drawText(2500,i,query.value(1).toString());
               painter.drawText(4000,i,query.value(2).toString());
               painter.drawText(5500,i,query.value(3).toString());
               painter.drawText(7000,i,query.value(4).toString());


              i = i + 350;
           }
           QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
           QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_statvoyageur_2_clicked()
{ QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from VOYAGEUR where N_Passeport < 26000000 ");
    float code=model->rowCount();
    model->setQuery("select * from VOYAGEUR where N_Passeport  between 26000000 and 46000000 ");
    float codee=model->rowCount();
    model->setQuery("select * from VOYAGEUR where N_Passeport >46000000");
    float codeee=model->rowCount();
    float total=code+codee+codeee;
    QString a=QString("moins de26000000  \t"+QString::number((code*100)/total,'f',2)+"%" );
    QString b=QString("entre 26000000 et 46000000  \t"+QString::number((codee*100)/total,'f',2)+"%" );
    QString c=QString("+46000000  \t"+QString::number((codeee*100)/total,'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(a,code);
    series->append(b,codee);
    series->append(c,codeee);
if (code!=0)
{QPieSlice *slice = series->slices().at(0);
slice->setLabelVisible();
slice->setPen(QPen());}
if ( codee!=0)
{
     // Add label, explode and define brush for 2nd slice
     QPieSlice *slice1 = series->slices().at(1);
     //slice1->setExploded();
     slice1->setLabelVisible();
}
if(codeee!=0)
{
     // Add labels to rest of slice
     QPieSlice *slice2 = series->slices().at(2);
     //slice1->setExploded();
     slice2->setLabelVisible();
}
    // Create the chart widget
    QChart *chart = new QChart();
    // Add data to chart with title and hide legend
    chart->addSeries(series);
    chart->setTitle("Pourcentage Par N_Passeport :Nombre Des voyageur "+ QString::number(total));
    chart->legend()->hide();
    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1000,500);
    chartView->show();

}


//bagages

void MainWindow::on_bagages_ajouter_clicked()
{
    QString nom_proprietaire=ui->a1->text();
    int poids=ui->a2->text().toInt();
    QString type=ui->texte_type->text();
    Bagages B(nom_proprietaire,poids,type);

    if(B.ajouter())
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("ajout effectué\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);


 ui->tab_bagages->setModel(B.afficher());

    }
    else QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                               QObject::tr("Ajout non effectué.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);}



void MainWindow::on_bagages_supprimer_clicked()
{
    Bagages B1; B1.setnom_proprietaire(ui->t_supp->text());
    bool test=B1.supprimer(B1.getnom_proprietaire());
    QMessageBox msgBox;
    if(test)
    {
        msgBox.setText(("Suppression avec succes "));
      ui->tab_bagages->setModel(B1.afficher());


    }
       else
        msgBox.setText(("Eches de suppression"));
                msgBox.exec();
}

void MainWindow::on_bagages_modifier_clicked()
{
    Bagages B;

       QString nom_proprietaire=ui->lineEdit_5->text();
        B.setpoids(ui->lineEdit_6->text().toInt());
        QString type=ui->lineEdit_7->text();

       bool test=B.modifier(B.getnom_proprietaire(),B.getpoids(),B.gettype());

       QMessageBox msgBox;


       if(test)
       {msgBox.setText("Modification avec succés.");
       ui->tab_bagages->setModel(B.afficher());

       }
       else msgBox.setText("Echec de modification");
       msgBox.exec();
}

void MainWindow::on_bagages_pdf_clicked()
{
    QPdfWriter pdf("C:/Atelier_Connexion/bagages.pdf");

              QPainter painter(&pdf);
              int i = 4000;
                     painter.setPen(Qt::darkCyan);
                     painter.setFont(QFont("Time New Roman", 25));
                     painter.drawText(3000,1400,"Listes des bagages");
                     painter.setPen(Qt::black);
                     painter.setFont(QFont("Time New Roman", 15));
                     painter.drawRect(100,100,9400,2500);
                     painter.drawRect(100,3000,9400,500);
                     painter.setFont(QFont("Time New Roman", 9));
                     painter.drawText(400,3300,"nom_proprietaire");
                     painter.drawText(1350,3300,"poids");
                     painter.drawText(2200,3300,"type");
                     painter.drawRect(100,3000,9400,9000);

                     QSqlQuery query;
                     query.prepare("select * from Bagages");
                     query.exec();
                     while (query.next())
                     {
                         painter.drawText(400,i,query.value(0).toString());
                         painter.drawText(1350,i,query.value(1).toString());
                         painter.drawText(2300,i,query.value(2).toString());
                         painter.drawText(3400,i,query.value(3).toString());
                         painter.drawText(4400,i,query.value(4).toString());
                         painter.drawText(6200,i,query.value(5).toString());




                        i = i + 350;
                     }
                     QMessageBox::information(this, QObject::tr("PDF Saved Successfuly!"),
                     QObject::tr("PDF Saved Successfuly!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_bagages_recherche_clicked()
{
    Bagages b;
          QString s1;
             QSqlQueryModel *model=b.recherche( ui->recherche_->text());
              ui->tab_bagages->setModel(model);
}


void MainWindow::on_bagages_tri_clicked()
{
    Bagages B;
    ui->tableView->setModel(B.tribagages());
}

