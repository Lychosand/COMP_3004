#include "MainWindow.h"
#include "ui_MainWindow.h"
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
        QueryDatabase(); //this will call the first query to the database.  Creating animal objects + clients will happen inside this function
    }
}

//Initial function that populates both client and animal list into memory
void MainWindow::QueryDatabase()
{
    QSqlQuery query;
    query.prepare("SELECT name, gender, age, species, breed, hair_type, hair_colour FROM ANIMALS INNER JOIN PHYSICAL_ATTRIBUTES ON ANIMALS.animal_id = PHYSICAL_ATTRIBUTES.a_id;");

    if(!query.exec())
        qWarning() << "Query Failed!";

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

    query.prepare("SELECT name, username, password, phone_number, address, postal_code, province FROM USERS INNER JOIN CLIENTS ON CLIENTS.u_id = USERS.user_id");

    if(!query.exec())
        qWarning() << "Client Query Failed!";

    //will delete list so there is no repeat clients
    clientList.deleteList();

    while(query.next())
    {
        //use the data that gets fed into this string to create the animal objects
        QString name,username,password,address,postal_code,province;
        string name1,username1,password1,address1,postal_code1,province1;
        int phone_number;

        name = query.value(0).toString();
        name1 = name.toStdString();

        username = query.value(1).toString();
        username1 = username.toStdString();

        password = query.value(2).toString();
        password1 = password.toStdString();

        phone_number = query.value(3).toInt();

        address = query.value(4).toString();
        address1 = address.toStdString();

        postal_code = query.value(5).toString();
        postal_code1 = postal_code.toStdString();

        province = query.value(6).toString();
        province1 = province.toStdString();

        Client *client = new Client(name1,username1,password1,phone_number,address1,postal_code1,province1);
        clientList.addClient(client);
    }
}

//Function will add the animal objects into the QTTable widget
//Commented out code is a guideline on how to insert data into the table
void MainWindow::AddToTable()
{
    for(int i=ui->view_table->rowCount()-1; i>=0; i--)
    {
        ui->view_table->removeRow(i);
    }

    if(ui->staff_combo->currentText() == "Animals")
    {
        QString name,gender,species,breed,hairType,hairColour,age;
        string name1,gender1,species1,breed1,hairType1,hairColour1;
        int age1;

        //returns number of animals in list
        int numAnimal = list.getNumAnimal();

        //Before query would return with all the sql data, change query to appropriately use a list of animal objects
        for(int i = 0; i< numAnimal; i++) {
            ui->view_table->insertRow(i);

            //gets info on animal object
            name1 = list.getAnimalName(i);
            name = QString::fromStdString(name1);
            ui->view_table->setItem(i, 0, new QTableWidgetItem(name));

            gender1 = list.getAnimalGender(i);
            gender = QString::fromStdString(gender1);
            ui->view_table->setItem(i, 1, new QTableWidgetItem(gender));

            age1 = list.getAnimalAge(i);
            age = QString::number(age1);
            ui->view_table->setItem(i, 2, new QTableWidgetItem(age));

            species1 = list.getAnimalSpecies(i);
            species = QString::fromStdString(species1);
            ui->view_table->setItem(i, 3, new QTableWidgetItem(species));

            breed1 = list.getAnimalBreed(i);
            breed = QString::fromStdString(breed1);
            ui->view_table->setItem(i, 4, new QTableWidgetItem(breed));

            hairType1 = list.getAnimalHairType(i);
            hairType = QString::fromStdString(hairType1);
            ui->view_table->setItem(i, 5, new QTableWidgetItem(hairType));

            hairColour1 = list.getAnimalHairColour(i);
            hairColour = QString::fromStdString(hairColour1);
            ui->view_table->setItem(i, 6, new QTableWidgetItem(hairColour));
        }
    } else if(ui->staff_combo->currentText() == "Clients")
    {

        for(int i=0; i < clientList.getNumClients(); i++)
        {
            ui->view_table->insertRow(i);

            ui->view_table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(clientList.getClientName(i))));
            ui->view_table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(clientList.getClientUsername(i))));
            ui->view_table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(clientList.getClientPassword(i))));
            ui->view_table->setItem(i, 3, new QTableWidgetItem(QString::number(clientList.getClientPhoneNumber(i))));
            ui->view_table->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(clientList.getClientAddress(i))));
            ui->view_table->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(clientList.getClientPostalCode(i))));
            ui->view_table->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(clientList.getClientProvince(i))));
        }
    }

}

//Function is called when the view animals button is clicked
void MainWindow::on_view_button_clicked()
{
    AddToTable(); //This function will have to add our animal objects to the viewable table
}

void MainWindow::on_add_button_clicked()
{
    if((ui->input_01->text().isEmpty()) ||
       (ui->input_02->text().isEmpty()) ||
       (ui->input_03->text().isEmpty()) ||
       (ui->input_04->text().isEmpty()) ||
       (ui->input_05->text().isEmpty()) ||
       (ui->input_06->text().isEmpty()) ||
       (ui->input_07->text().isEmpty()))
    {
        qWarning() << "Missing Entry Data!  Please Provide Appropriate Information!";
    } else
    {
        if(ui->staff_combo->currentText() == "Animals")
        {
            AddAnimal();
        }else if(ui->staff_combo->currentText() == "Clients")
        {
            AddClient();
        }
    }
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
    QSqlQuery addQuery;
    QSqlQuery idQuery;
    QString animalName = ui->input_01->text();
    QString animalGender = ui->input_02->text();
    QString animalAge = ui->input_03->text();
    QString animalSpecies = ui->input_04->text();
    QString animalBreed = ui->input_05->text();
    QString animalHairType = ui->input_06->text();
    QString animalHairColour = ui->input_07->text();

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

    //adds animal to list
    Animal *animal = new Animal(animalName.toStdString(), animalGender.toStdString(), animalSpecies.toStdString(),
                                animalBreed.toStdString(), animalHairType.toStdString(), animalHairColour.toStdString(), ageInt);
    list.addAnimal(animal);

    animalId = id_data + 1;

    //adds animal to database
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

    ui->input_01->setText("");
    ui->input_03->setText("");
    ui->input_02->setText("");
    ui->input_05->setText("");
    ui->input_06->setText("");
    ui->input_07->setText("");
    ui->input_04->setText("");

    //QueryDatabase(); //this will call the first query to the database.  Creating animal objects will happen inside this function
    //AddToTable(); //This function will have to add our animal objects to the viewable table
}

void MainWindow::AddClient()
{
    //Following code adds the new client into the database
    QSqlQuery addQuery;
    QSqlQuery idQuery;
    QString clientName = ui->input_01->text();
    QString clientUsername = ui->input_02->text();
    QString clientPassword = ui->input_03->text();
    QString clientPhoneNumber = ui->input_04->text();
    QString clientAddress = ui->input_05->text();
    QString clientPostalCode = ui->input_06->text();
    QString clientProvince = ui->input_07->text();

    int phoneNumber = clientPhoneNumber.toInt();
    qDebug() << phoneNumber;

    int clientId;
    int id_data = 0;

    idQuery.prepare("SELECT user_id FROM USERS");

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

    //adding client to client list
    Client *client = new Client(clientName.toStdString(), clientUsername.toStdString(), clientPassword.toStdString(), phoneNumber,
                                clientAddress.toStdString(), clientPostalCode.toStdString(), clientProvince.toStdString());
    clientList.addClient(client);

    clientId = id_data + 1;

    addQuery.prepare("INSERT INTO USERS (user_id, name, phone_number, address, postal_code, province)"
                         "VALUES (:user_id, :name, :phone_number, :address, :postal_code, :province)");
    addQuery.bindValue(":user_id", clientId);
    addQuery.bindValue(":name", clientName);
    addQuery.bindValue(":phone_number", phoneNumber);
    addQuery.bindValue(":address", clientAddress);
    addQuery.bindValue(":postal_code", clientPostalCode);
    addQuery.bindValue(":province", clientProvince);
    addQuery.exec();

    addQuery.prepare("INSERT INTO CLIENTS (u_id, username, password)"
                         "VALUES (:u_id, :username, :password)");
    addQuery.bindValue(":u_id", clientId);
    addQuery.bindValue(":username", clientUsername);
    addQuery.bindValue(":password", clientPassword);
    addQuery.exec();

    ui->input_01->setText("");
    ui->input_03->setText("");
    ui->input_02->setText("");
    ui->input_05->setText("");
    ui->input_06->setText("");
    ui->input_07->setText("");
    ui->input_04->setText("");
}

void MainWindow::show_clients()
{
    ui->input_label_02->setText("Username:");
    ui->input_label_03->setText("Password:");
    ui->input_label_04->setText("Phone Number:");
    ui->input_label_05->setText("Address:");
    ui->input_label_06->setText("Postal Code:");
    ui->input_label_07->setText("Province:");
    ui->view_button->setText("View Clients");
    ui->add_button->setText("Add Client");

    ui->view_table->setHorizontalHeaderItem(1, new QTableWidgetItem("Username"));
    ui->view_table->setHorizontalHeaderItem(2, new QTableWidgetItem("Password"));
    ui->view_table->setHorizontalHeaderItem(3, new QTableWidgetItem("Phone Number"));
    ui->view_table->setHorizontalHeaderItem(4, new QTableWidgetItem("Address"));
    ui->view_table->setHorizontalHeaderItem(5, new QTableWidgetItem("Postal Code"));
    ui->view_table->setHorizontalHeaderItem(6, new QTableWidgetItem("Province"));
}

void MainWindow::show_animals()
{
    ui->input_label_02->setText("Gender:");
    ui->input_label_03->setText("Age:");
    ui->input_label_04->setText("Species:");
    ui->input_label_05->setText("Breed:");
    ui->input_label_06->setText("Hair Type:");
    ui->input_label_07->setText("Hair Colour:");
    ui->view_button->setText("View Animals");
    ui->add_button->setText("Add Animal");

    ui->view_table->setHorizontalHeaderItem(1, new QTableWidgetItem("Gender"));
    ui->view_table->setHorizontalHeaderItem(2, new QTableWidgetItem("Age"));
    ui->view_table->setHorizontalHeaderItem(3, new QTableWidgetItem("Species"));
    ui->view_table->setHorizontalHeaderItem(4, new QTableWidgetItem("Breed"));
    ui->view_table->setHorizontalHeaderItem(5, new QTableWidgetItem("Hair Type"));
    ui->view_table->setHorizontalHeaderItem(6, new QTableWidgetItem("Hair Colour"));
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_staff_combo_activated(const QString &arg1)
{
    //Clears the table to get it ready for either clients or animals
    for(int i=ui->view_table->rowCount()-1; i>=0; i--)
    {
        ui->view_table->removeRow(i);
    }

    if(arg1 == "Animals"){
        qDebug() << "Now looking at animal menu";
        show_animals();
    }else if(arg1 == "Clients") {
        qDebug() << "Now looking at client menu";
        show_clients();
    }
}
