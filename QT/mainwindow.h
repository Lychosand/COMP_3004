#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QtCore>
#include <QtGui>
#include "Animal.h"
#include "Array.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_animalViewer_clicked();

    void on_login_button_clicked();

    void on_addButton_clicked();

    void on_staff_combo_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    void ConnectDatabase();
    void QueryDatabase();
    void AddToTable();
    void PrepareForms();
    void AddAnimal();
    void show_animals();
    void show_clients();
    Array list;

};

#endif // MAINWINDOW_H
