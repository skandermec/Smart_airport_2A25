#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"bagages.h"
#include"smtp.h"
#include"his.h"

#include <QMainWindow>
#include<QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void on_pb_ajouter_clicked();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    //void on_pushButton_5_clicked();



    void on_pushButton_pdf_clicked();

    void on_pushButton_5_clicked();

    void on_pb_envoyer_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    Bagages B;
    Smtp* smtp;
    //his* His;
};

#endif // MAINWINDOW_H
