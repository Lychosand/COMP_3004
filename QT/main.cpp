#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w; //When MainWindow is created, code is run through the mainwindow.cpp file
    w.show();

    return a.exec();
}
