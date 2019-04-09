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
#include <vector>
#include "Animal.h"
#include "Array.h"
#include "Client.h"
#include "ClientArray.h"
#include "Match.h"
#include "ACM.h"

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
    void on_view_button_clicked();

    void on_login_button_clicked();

    void on_view_animals_clicked();
    void on_view_button_2_clicked();

    void on_view_client_clicked();
    void on_view_client_2_clicked();

    void on_add_button_clicked();
    void on_add_button_2_clicked();

    void on_add_client_clicked();
    void on_add_client_2_clicked();

    //in staff_frame_2
    void on_submit_clicked();

    //in client frame
    void on_editProfile_clicked();

    //in edit profile frame
    void on_submit_2_clicked();
    void on_ClientViewAnimalProfile_clicked();

    void on_view_table_cellDoubleClicked(int row, int column);

    void on_view_button_3_clicked();

    void on_view_client_3_clicked();

    void on_add_button_3_clicked();

    void on_add_client_3_clicked();

    void on_submit_3_clicked();

    void on_runACM_clicked();
    void on_run_acm_clicked();
    void on_run_acm2_clicked();
    void on_back_button_clicked();

    //acm buttons
    void on_acmViewAnimals_clicked();
    void on_acmViewClients_clicked();
    void on_acmAddAnimal_clicked();
    void on_acmAddClient_clicked();
    //void on_back_button_clicked();

    //acm view match
    void on_acm_table_cellDoubleClicked(int row, int column);

private:
    Ui::MainWindow *ui;
    void ConnectDatabase();
    void QueryDatabase();
    void AddToTable();
    void AddToTableClient();
    void AddClientToTable();
    void PrepareForms();
    void AddAnimal();
    void AddClient();
    void show_animals();
    void show_clients();
    void setupEditClient(QString);
    void EditAnimal(int);
    void runACM();

    Array list;
    ClientArray clientList;
    vector<Match> optimalSet;
    ACM algorithm;

};

#endif // MAINWINDOW_H
