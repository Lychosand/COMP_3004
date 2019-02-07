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
    void on_addAnimal_clicked();

    void on_login_button_clicked();

private:
    Ui::MainWindow *ui;
    void ConnectDatabase();
    void QueryDatabase();
    void AddToTable();
    void PrepareForms();
};

#endif // MAINWINDOW_H
