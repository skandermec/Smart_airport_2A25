#ifndef CALENDARDIALOG_H
#define CALENDARDIALOG_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QString>
#include<QDialog>
#include <QMainWindow>

namespace Ui {
class calendarDialog ;
}

class Calendar : public QDialog {

Q_OBJECT
public:

explicit Calendar(QWidget *parent = 0);
private:
Ui::calendarDialog *ui;
private:

QDate getdate();
QDate currentDate() const;
void setCurrentDate(const QDate &d);
void on_calendar_clicked(const QDate &date);
private slots:

void on_MonthFrontButton_clicked();

void on_MonthBackButton_clicked();
void on_yearBackButton_clicked();

void on_yearFrontButton_clicked();
void on_OkButton_clicked(); };

#endif // CALENDARDIALOG_H

