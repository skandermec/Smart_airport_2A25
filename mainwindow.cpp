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













MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{







    ui->setupUi(this);
    QRegularExpression QRegExp( "[a-zA-Z]+");
        QRegularExpressionValidator *validator = new QRegularExpressionValidator(QRegExp,this);
        ui->le_nom->setValidator(validator);
ui->le_nom2->setValidator(validator);

 ui->le_cin->setValidator(new QIntValidator(0, 99999999, this));
 ui->le_cin_supp->setValidator(new QIntValidator(100, 99999999, this));
 ui->le_cin_mod->setValidator(new QIntValidator(100, 99999999, this));
 ui->le_cin2->setValidator(new QIntValidator(100, 99999999, this));

ui->tab_employe->setModel(E.afficher());






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

















void MainWindow::on_le_stat_clicked()
{

        QMenu *fileMenu = new QMenu(tr("&File"), this);
        QAction *openAction = fileMenu->addAction(tr("&Open..."));
        openAction->setShortcuts(QKeySequence::Open);
        QAction *saveAction = fileMenu->addAction(tr("&Save As..."));
        saveAction->setShortcuts(QKeySequence::SaveAs);
        QAction *quitAction = fileMenu->addAction(tr("E&xit"));
        quitAction->setShortcuts(QKeySequence::Quit);

        setupModel();
        setupViews();

        connect(openAction, &QAction::triggered, this, &MainWindow::openFile);
        connect(saveAction, &QAction::triggered, this, &MainWindow::saveFile);
        connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);

        menuBar()->addMenu(fileMenu);
        statusBar();

        loadFile(":/Charts/qtdata.cht");

        setWindowTitle(tr("Chart"));
        resize(870, 550);
    }

    void MainWindow::setupModel()
    {
        model = new QStandardItemModel(8, 2, this);
        model->setHeaderData(0, Qt::Horizontal, tr("Label"));
        model->setHeaderData(1, Qt::Horizontal, tr("Quantity"));
    }

    void MainWindow::setupViews()
    {
        QSplitter *splitter = new QSplitter;
        QTableView *table = new QTableView;
        pieChart = new PieView;
        splitter->addWidget(table);
        splitter->addWidget(pieChart);
        splitter->setStretchFactor(0, 0);
        splitter->setStretchFactor(1, 1);

        table->setModel(model);
        pieChart->setModel(model);

        QItemSelectionModel *selectionModel = new QItemSelectionModel(model);
        table->setSelectionModel(selectionModel);
        pieChart->setSelectionModel(selectionModel);

        QHeaderView *headerView = table->horizontalHeader();
        headerView->setStretchLastSection(true);

        setCentralWidget(splitter);
    }

    void MainWindow::openFile()
    {
        const QString fileName =
            QFileDialog::getOpenFileName(this, tr("Choose a data file"), "", "*.cht");
        if (!fileName.isEmpty())
            loadFile(fileName);
    }

    void MainWindow::loadFile(const QString &fileName)
    {
        QFile file(fileName);
        if (!file.open(QFile::ReadOnly | QFile::Text))
            return;

        QTextStream stream(&file);
        QString line;

        model->removeRows(0, model->rowCount(QModelIndex()), QModelIndex());

        int row = 0;
        do {
            line = stream.readLine();
            if (!line.isEmpty()) {
                model->insertRows(row, 1, QModelIndex());

                QStringList pieces = line.split(',', QString::SkipEmptyParts);
                model->setData(model->index(row, 0, QModelIndex()),
                               pieces.value(0));
                model->setData(model->index(row, 1, QModelIndex()),
                               pieces.value(1));
                model->setData(model->index(row, 0, QModelIndex()),
                               QColor(pieces.value(2)), Qt::DecorationRole);
                row++;
            }
        } while (!line.isEmpty());

        file.close();
        statusBar()->showMessage(tr("Loaded %1").arg(fileName), 2000);
    }

    void MainWindow::saveFile()
    {
        QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save file as"), "", "*.cht");

        if (fileName.isEmpty())
            return;

        QFile file(fileName);
        if (!file.open(QFile::WriteOnly | QFile::Text))
            return;

        QTextStream stream(&file);
        for (int row = 0; row < model->rowCount(QModelIndex()); ++row) {

            QStringList pieces;

            pieces.append(model->data(model->index(row, 0, QModelIndex()),
                                      Qt::DisplayRole).toString());
            pieces.append(model->data(model->index(row, 1, QModelIndex()),
                                      Qt::DisplayRole).toString());
            pieces.append(model->data(model->index(row, 0, QModelIndex()),
                                      Qt::DecorationRole).toString());

            stream << pieces.join(',') << "\n";
        }

        file.close();
        statusBar()->showMessage(tr("Saved %1").arg(fileName), 2000);
    }




void MainWindow::on_pushButton_3_clicked()
{
    //! [0]

        selectedDate = QDate::currentDate();
        fontSize = 10;

        QWidget *centralWidget = new QWidget;
    //! [0]

    //! [1]
        QLabel *dateLabel = new QLabel(tr("Date:"));
        QComboBox *monthCombo = new QComboBox;

        for (int month = 1; month <= 12; ++month)
            monthCombo->addItem(QDate::longMonthName(month));

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
        connect(monthCombo, SIGNAL(activated(int)), this, SLOT(setMonth(int)));
        connect(yearEdit, SIGNAL(dateChanged(QDate)), this, SLOT(setYear(QDate)));
        connect(fontSizeSpinBox, SIGNAL(valueChanged(int)),
                this, SLOT(setFontSize(int)));
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
    //! [4]
    }

//! [5]
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
        cellCursor.insertText(QString("%1").arg(QDate::longDayName(weekDay)), boldFormat);
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
        ).arg(QDate::longMonthName(selectedDate.month())
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

