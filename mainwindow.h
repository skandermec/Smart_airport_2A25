#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "employe.h"
#include<QDate>

QT_BEGIN_NAMESPACE
class QAbstractItemModel;
class QAbstractItemView;
class QItemSelectionModel;
QT_END_NAMESPACE
QT_BEGIN_NAMESPACE
class QTextBrowser;
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





    void on_pb_calendar_clicked();



    void on_le_stat_clicked();
    void openFile();
    void saveFile();
    void setFontSize(int size);
    void setMonth(int month);
    void setYear(QDate date);
    void on_pushButton_3_clicked();

private:




    Ui::MainWindow *ui;

    Employe E;
    Employe Etmp;


    void setupModel();
    void setupViews();
    void loadFile(const QString &path);

    QAbstractItemModel *model;
    QAbstractItemView *pieChart;
    QItemSelectionModel *selectionModel;
    void insertCalendar();

    int fontSize;
    QDate selectedDate;
    QTextBrowser *editor;
};

#endif // MAINWINDOW_H
