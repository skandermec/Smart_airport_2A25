#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"
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

private:
    Ui::MainWindow *ui;
    Employe E;
    Employe Etmp;
};

#endif // MAINWINDOW_H
