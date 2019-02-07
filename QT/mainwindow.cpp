#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); //UI is the object that houses all of the current window information.  Take a look at the mainwindow.ui in forms to understand what is encapsulated in ui
    this->setWindowTitle("cuACS"); //sets the window title
    this->setWindowIcon(QIcon("/home/student/Desktop/COMP_3004/QT/Images/icon.gif")); //gives our program a little icon

    PrepareForms();
    ConnectDatabase(); //connects to the 3004.db
}

//Hides and sets coordinates for the current QWidgets found on the main window
void MainWindow::PrepareForms()
{
    ui->login_frame->move(80, 170); //x_pos = (mainwindow.width-login_frame.width)/2 height, y_pos = (mainwindow.height-login_frame.height)/2
    ui->staff_frame->move(80, 170);
    ui->staff_frame->hide();
    ui->password_input->setEchoMode(QLineEdit::Password);
}

//Initial function connecting us to the database
void MainWindow::ConnectDatabase()
{
    QSqlDatabase animal_db=QSqlDatabase::addDatabase("QSQLITE");
    animal_db.setDatabaseName("/home/student/Desktop/COMP_3004/SQL_Database/3004.db");

    if(!animal_db.open())
        qWarning() << "MainWindow::ConnectDatabase - ERROR: Couldn't Open Database!";

}

//Initial function that queries the existing data in the database
void MainWindow::QueryDatabase()
{
    QSqlQuery query;

    query.prepare("SELECT name, gender, age, species, breed, hair_type, hair_colour FROM ANIMALS INNER JOIN PHYSICAL_ATTRIBUTES ON ANIMALS.animal_id = PHYSICAL_ATTRIBUTES.a_id;");

    if(!query.exec())
        qWarning() << "Query Failed!";

    QSqlRecord record = query.record(); //gets the count of columns, used for iteration

    while(query.next()) {
        QString animal_data; //use the data that gets fed into this string to create the animal objects

        for(int i = 0; i < record.count(); i++) {
            animal_data += query.value(i).toString() + " ";
        }

        qDebug() << animal_data;
    }
}

//Function will add the animal objects into the QTTable widget
//Commented out code is a guideline on how to insert data into the table
void MainWindow::AddToTable()
{
    /*
    QString temp_table_string;

    int iterator = 0;

    //Before query would return with all the sql data, change query to appropriately use a list of animal objects
    while(query.next()) {
        ui->animalTable->insertRow(iterator);

        for(int j=0; j<7; j++) {
            temp_table_string = query.value(j).toString();
            ui->animalTable->setItem(iterator, j, new QTableWidgetItem(temp_table_string));
        }

        iterator++;
    }
    */
}
MainWindow::~MainWindow()
{
    delete ui;
}

//Function is called when the view animals button is clicked
void MainWindow::on_animalViewer_clicked()
{
    QueryDatabase(); //this will call the first query to the database.  Creating animal objects will happen inside this function
    AddToTable(); //This function will have to add our animal objects to the viewable table
}

//Function is called when the login button on the login form is pressed
void MainWindow::on_login_button_clicked()
{
    QSqlQuery query;

    query.prepare("SELECT password FROM STAFF WHERE USERNAME = :staff_username");
    query.bindValue(":staff_username", ui->username_input->text());

    query.exec();

    if(!query.next()) {
        qWarning() << "User not Found!";
    }else {
        qDebug() << "Found the user! ";

        if(query.value(0).toString() == ui->password_input->text()) {
            qDebug() << "Welcome!";
            ui->login_frame->hide();
            ui->staff_frame->show();
        }else {
            qWarning() << "Incorrect Password!";
        }
    }
}

