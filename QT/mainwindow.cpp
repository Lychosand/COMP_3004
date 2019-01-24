#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "animal.h"

Animal* animal_array[10];

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("cuACS");
    this->setWindowIcon(QIcon("/home/student/Desktop/COMP_3004/QT/Images/icon.gif"));

    ConnectDatabase();
}

void MainWindow::ConnectDatabase() {
    QSqlDatabase animal_db=QSqlDatabase::addDatabase("QSQLITE");
    animal_db.setDatabaseName("/home/student/Desktop/COMP_3004/SQL_Database/3004.db");

    if(!animal_db.open())
        qWarning() << "MainWindow::ConnectDatabase - ERROR: Couldn't Open!";

}

void MainWindow::QueryDatabase() {
    QSqlQuery query;

    query.prepare("SELECT name, gender, age, species, breed, hair_type, hair_colour FROM ANIMALS INNER JOIN PHYSICAL_ATTRIBUTES ON ANIMALS.animal_id = PHYSICAL_ATTRIBUTES.a_id;");

    QString name, gender, species, breed, hair_type, hair_colour;
    int age;

    QString temp_table_string;

    int iterator = 0;

    if(!query.exec())
        qWarning() << "Query Failed Dumbass!";
    else
        while(query.next()) {
            name = query.value(0).toString();
            gender = query.value(1).toString();
            age = query.value(2).toInt();
            species = query.value(3).toString();
            breed = query.value(4).toString();
            hair_type = query.value(5).toString();
            hair_colour = query.value(6).toString();

            ui->animalTable->insertRow(iterator);

            for(int j=0; j<7; j++) {
                temp_table_string = query.value(j).toString();
                ui->animalTable->setItem(iterator, j, new QTableWidgetItem(temp_table_string));
            }

            animal_array[iterator++] = new Animal(name, gender, age, species, breed, hair_type, hair_colour);
        }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_animalViewer_clicked()
{
    QueryDatabase();
}

