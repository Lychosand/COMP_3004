#include "mainwindow.h"
#include "ui_mainwindow.h"
using std::string;

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
    animal_db.setDatabaseName("../SQL_Database/3004.db");

    if(!animal_db.open()){
        qWarning() << "MainWindow::ConnectDatabase - ERROR: Couldn't Open Database!";
    }else{
        QueryDatabase(); //this will call the first query to the database.  Creating animal objects will happen inside this function
        AddToTable();
    }


}

//Initial function that queries the existing data in the database
void MainWindow::QueryDatabase()
{
    QSqlQuery query;
    query.prepare("SELECT name, gender, age, species, breed, hair_type, hair_colour FROM ANIMALS INNER JOIN PHYSICAL_ATTRIBUTES ON ANIMALS.animal_id = PHYSICAL_ATTRIBUTES.a_id;");

    if(!query.exec())
        qWarning() << "Query Failed!";

    QSqlRecord record = query.record(); //gets the count of columns, used for iteration

    //will delete list so there is no repeat animals
    list.deleteList();

    while(query.next()) {
        //use the data that gets fed into this string to create the animal objects
        QString name,gender,species,breed,hairType,hairColour;
        string name1,gender1,species1,breed1,hairType1,hairColour1;
        int age;

        name = query.value(0).toString();
        name1 = name.toStdString();

        gender = query.value(1).toString();
        gender1 = gender.toStdString();

        age = query.value(2).toInt();

        species = query.value(3).toString();
        species1 = species.toStdString();

        breed = query.value(4).toString();
        breed1 = breed.toStdString();

        hairType = query.value(5).toString();
        hairType1 = hairType.toStdString();

        hairColour = query.value(6).toString();
        hairColour1 = hairColour.toStdString();

        Animal *animal = new Animal(name1,gender1,species1,breed1,hairType1,hairColour1,age);
        list.addAnimal(animal);
    }
}

//Function will add the animal objects into the QTTable widget
//Commented out code is a guideline on how to insert data into the table
void MainWindow::AddToTable()
{

    QString name,gender,species,breed,hairType,hairColour,age;
    string name1,gender1,species1,breed1,hairType1,hairColour1;
    int age1;
    QSqlQuery query;

    //clears data in table if its a refresh
    ui->animalTable->clear();

    //returns number of animals in list
    int numAnimal = list.getNumAnimal();

    //Before query would return with all the sql data, change query to appropriately use a list of animal objects
    for(int i = 0; i< numAnimal; i++) {
        ui->animalTable->removeRow(i);
        ui->animalTable->insertRow(i);

        //gets info on animal object
        name1 = list.getAnimalName(i);
        name = QString::fromStdString(name1);
        ui->animalTable->setItem(i, 0, new QTableWidgetItem(name));
        ui->animalTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));

        gender1 = list.getAnimalGender(i);
        gender = QString::fromStdString(gender1);
        ui->animalTable->setItem(i, 1, new QTableWidgetItem(gender));
        ui->animalTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Gender"));

        age1 = list.getAnimalAge(i);
        age = QString::number(age1);
        ui->animalTable->setItem(i, 2, new QTableWidgetItem(age));
        ui->animalTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Age"));

        species1 = list.getAnimalSpecies(i);
        species = QString::fromStdString(species1);
        ui->animalTable->setItem(i, 3, new QTableWidgetItem(species));
        ui->animalTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Species"));

        breed1 = list.getAnimalBreed(i);
        breed = QString::fromStdString(breed1);
        ui->animalTable->setItem(i, 4, new QTableWidgetItem(breed));
        ui->animalTable->setHorizontalHeaderItem(4, new QTableWidgetItem("Breed"));

        hairType1 = list.getAnimalHairType(i);
        hairType = QString::fromStdString(hairType1);
        ui->animalTable->setItem(i, 5, new QTableWidgetItem(hairType));
        ui->animalTable->setHorizontalHeaderItem(5, new QTableWidgetItem("Hair Type"));

        hairColour1 = list.getAnimalHairColour(i);
        hairColour = QString::fromStdString(hairColour1);
        ui->animalTable->setItem(i, 6, new QTableWidgetItem(hairColour));
        ui->animalTable->setHorizontalHeaderItem(6, new QTableWidgetItem("Hair Colour"));
    }
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

void MainWindow::AddAnimal()
{
    //Following code adds the new animal into the database
    if((ui->nameInput->text().isEmpty()) ||
       (ui->genderInput->text().isEmpty()) ||
       (ui->ageInput->text().isEmpty()) ||
       (ui->speciesInput->text().isEmpty()) ||
       (ui->breedInput->text().isEmpty()) ||
       (ui->hairTypeInput->text().isEmpty()) ||
       (ui->hairColourInput->text().isEmpty()))
    {
        qWarning() << "Missing Animal Entry Data!  Please Provide Appropriate Information!";
    } else
    {
        QSqlQuery addQuery;
        QSqlQuery idQuery;
        QString animalName = ui->nameInput->text();
        QString animalGender = ui->genderInput->text();
        QString animalAge = ui->ageInput->text();
        QString animalSpecies = ui->speciesInput->text();
        QString animalBreed = ui->breedInput->text();
        QString animalHairType = ui->hairTypeInput->text();
        QString animalHairColour = ui->hairColourInput->text();

        int ageInt = animalAge.toInt();
        int animalId;
        int id_data = 0;

        idQuery.prepare("SELECT animal_id FROM ANIMALS");

        idQuery.exec();
        idQuery.first();

        QSqlRecord record = idQuery.record();

         while(idQuery.next()){
            for(int i = 0; i < record.count(); i++) {
                int temp = idQuery.value(i).toInt();
                if(temp>id_data){
                    id_data = temp;
                }
            }
        }
        qDebug() << id_data;

        animalId = id_data + 1;

        addQuery.prepare("INSERT INTO ANIMALS (animal_id, name)"
                         "VALUES (:animal_id, :name)");
        addQuery.bindValue(":animal_id", animalId);
        addQuery.bindValue(":name", animalName);
        addQuery.exec();

        addQuery.prepare("INSERT INTO PHYSICAL_ATTRIBUTES (a_id, gender, age, species, breed, hair_type, hair_colour)"
                         "VALUES (:a_id, :gender, :age, :species, :breed, :hair_type, :hair_colour)");
        addQuery.bindValue(":a_id", animalId);
        addQuery.bindValue(":gender", animalGender);
        addQuery.bindValue(":age", ageInt);
        addQuery.bindValue(":species", animalSpecies);
        addQuery.bindValue(":breed", animalBreed);
        addQuery.bindValue(":hair_type", animalHairType);
        addQuery.bindValue(":hair_colour", animalHairColour);
        addQuery.exec();

        ui->nameInput->setText("");
        ui->ageInput->setText("");
        ui->genderInput->setText("");
        ui->breedInput->setText("");
        ui->hairTypeInput->setText("");
        ui->hairColourInput->setText("");
        ui->speciesInput->setText("");

        QueryDatabase(); //this will call the first query to the database.  Creating animal objects will happen inside this function
        AddToTable(); //This function will have to add our animal objects to the viewable table
    }
}

void MainWindow::on_addButton_clicked()
{
    AddAnimal();
}

MainWindow::~MainWindow()
{
    delete ui;
}
