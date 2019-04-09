#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QPixmap>
#include <QMessageBox>
using std::string;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); //UI is the object that houses all of the current window information.  Take a look at the mainwindow.ui in forms to understand what is encapsulated in ui
    this->setWindowTitle("cuACS"); //sets the window title
<<<<<<< HEAD
    this->setWindowIcon(QIcon("../Images/icon.gif")); //gives our program a little icon

    //Sets Up our project logo
    QPixmap pix("../Images/duck.jpg");
    ui->Logo->setPixmap(pix);
    ui->Logo_2->setPixmap(pix);


=======
    this->setWindowIcon(QIcon("/Images/icon.gif")); //gives our program a little icon

    //Sets Up our project logo
    QPixmap pix("/Images/duck.jpg");
    ui->Logo->setPixmap(pix);
    ui->Logo_2->setPixmap(pix);
>>>>>>> master

    PrepareForms();
    ConnectDatabase(); //connects to the 3004.db
}

//Hides and sets coordinates for the current QWidgets found on the main window
void MainWindow::PrepareForms()
{
    //Sets up the frames
    //View animals is the default when staff logs in
    ui->stackedWidget->setCurrentIndex(0);
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
    query.prepare("SELECT NAME, gender, age, species, breed, hair_type, hair_colour, aggressiveness, hyperactivity, sleep, noise, appetite, maintainance, outside, space_required, child_friendly, animal_friendly, equipment, excitibility, animal_id FROM ANIMALS INNER JOIN PHYSICAL_ATTRIBUTES ON ANIMALS.animal_id = PHYSICAL_ATTRIBUTES.a_id;");

    if(!query.exec())
        qWarning() << "Query Failed!";

    //will delete list so there is no repeat animals
    list.deleteList();

    while(query.next()) {

        //use the data that gets fed into this string to create the animal objects
        QString name,gender,species,breed,hairType,hairColour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space,child,animalFriendly,equipment,excitement;
        string name1,gender1,species1,breed1,hairType1,hairColour1,aggressiveness1,hyperactivity1,sleep1,noise1,appetite1,maintainance1,outside1,space1,child1,animalFriendly1,equipment1,excitement1;
        int age, id;

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

        aggressiveness = query.value(7).toString();
        aggressiveness1 = aggressiveness.toStdString();

        hyperactivity = query.value(8).toString();
        hyperactivity1 = hyperactivity.toStdString();

        sleep = query.value(9).toString();
        sleep1 = sleep.toStdString();

        noise = query.value(10).toString();
        noise1 = noise.toStdString();

        appetite = query.value(11).toString();
        appetite1 = appetite.toStdString();

        maintainance = query.value(12).toString();
        maintainance1 = maintainance.toStdString();

        outside = query.value(13).toString();
        outside1 = outside.toStdString();

        space = query.value(14).toString();
        space1 = space.toStdString();

        child = query.value(15).toString();
        child1 = child.toStdString();

        animalFriendly = query.value(16).toString();
        animalFriendly1 = animalFriendly.toStdString();

        equipment = query.value(17).toString();
        equipment1 = equipment.toStdString();

        excitement = query.value(18).toString();
        excitement1 = excitement.toStdString();

        id = query.value(19).toInt();

        Animal *animal = new Animal(name1,gender1,species1,breed1,hairType1,hairColour1,aggressiveness1,hyperactivity1,sleep1,noise1,appetite1,maintainance1,outside1,space1,child1,animalFriendly1,equipment1,excitement1,age, id);
        list.addAnimal(animal);
    }

    query.prepare("SELECT name, username, password, phone_number, address, postal_code, province, animal_wanted,agression,hyperactivity,sleep,animal_loudness,food_budget,time_avail,house_type,child_friendly, equip_budget, have_animals,ex_stimuli,pref_age,pref_gender FROM USERS INNER JOIN CLIENTS ON CLIENTS.u_id = USERS.user_id");
    int database_id = 11;
    if(!query.exec())
        qWarning() << "Client Query Failed!";

    //will delete list so there is no repeat clients
    clientList.deleteList();

    while(query.next())
    {

        //use the data that gets fed into this string to create the animal objects
        QString name,username,password,address,postal_code,province,phone_number;
        string name1,username1,password1,address1,postal_code1,province1,phone_number1;
        int client_id;
        int pref[14];

        //add int query values to array
        pref[0] = query.value(7).toInt();
        pref[1] = query.value(8).toInt();
        pref[2] = query.value(9).toInt();
        pref[3] = query.value(10).toInt();
        pref[4] = query.value(11).toInt();
        pref[5] = query.value(12).toInt();
        pref[6] = query.value(13).toInt();
        pref[7] = query.value(14).toInt();
        pref[8] = query.value(15).toInt();
        pref[9] = query.value(16).toInt();
        pref[10] = query.value(17).toInt();
        pref[11] = query.value(18).toInt();
        pref[12] = query.value(19).toInt();
        pref[13] = query.value(20).toInt();

        name = query.value(0).toString();
        name1 = name.toStdString();

        username = query.value(1).toString();
        username1 = username.toStdString();

        password = query.value(2).toString();
        password1 = password.toStdString();

        phone_number = query.value(3).toString();
        phone_number1 = phone_number.toStdString();


        address = query.value(4).toString();
        address1 = address.toStdString();

        postal_code = query.value(5).toString();
        postal_code1 = postal_code.toStdString();

        province = query.value(6).toString();
        province1 = province.toStdString();

        client_id = database_id;

        Client *client = new Client(name1,username1,password1,phone_number1,address1,postal_code1,province1,client_id,pref);
        clientList.addClient(client);
        database_id++;
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

        QString name,gender,species,breed,hairType,hairColour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space,child,animalFriendly,equipment,excitement,age;
        string name1,gender1,species1,breed1,hairType1,hairColour1,aggressiveness1,hyperactivity1,sleep1,noise1,appetite1,maintainance1,outside1,space1,child1,animalFriendly1,equipment1,excitement1;
        int age1;

        //returns number of animals in list
        int numAnimal = list.getNumAnimal();

        //Before query would return with all the sql data, change query to appropriately use a list of animal objects
        for(int i = 0; i< numAnimal; i++) {
            ui->view_table->insertRow(i);
            ui->view_table->setRowHeight(i,50);

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

            aggressiveness1 = list.getAnimalAggressiveness(i);
            aggressiveness = QString::fromStdString(aggressiveness1);
            ui->view_table->setItem(i, 7, new QTableWidgetItem(aggressiveness));

            hyperactivity1 = list.getAnimalHyperactivity(i);
            hyperactivity = QString::fromStdString(hyperactivity1);
            ui->view_table->setItem(i, 8, new QTableWidgetItem(hyperactivity));

            sleep1 = list.getAnimalSleep(i);
            sleep = QString::fromStdString(sleep1);
            ui->view_table->setItem(i, 9, new QTableWidgetItem(sleep));

            noise1 = list.getAnimalNoise(i);
            noise = QString::fromStdString(noise1);
            ui->view_table->setItem(i, 10, new QTableWidgetItem(noise));

            appetite1 = list.getAnimalAppetite(i);
            appetite = QString::fromStdString(appetite1);
            ui->view_table->setItem(i, 11, new QTableWidgetItem(appetite));

            maintainance1 = list.getAnimalMaintainance(i);
            maintainance = QString::fromStdString(maintainance1);
            ui->view_table->setItem(i, 12, new QTableWidgetItem(maintainance));

            outside1 = list.getAnimalOutside(i);
            outside = QString::fromStdString(outside1);
            ui->view_table->setItem(i, 13, new QTableWidgetItem(outside));

            space1 = list.getAnimalSpace(i);
            space = QString::fromStdString(space1);
            ui->view_table->setItem(i, 14, new QTableWidgetItem(space));

            child1 = list.getAnimalChild(i);
            child = QString::fromStdString(child1);
            ui->view_table->setItem(i, 16, new QTableWidgetItem(child));
<<<<<<< HEAD

            animalFriendly1 = list.getAnimalAnimalFriendly(i);
            animalFriendly = QString::fromStdString(animalFriendly1);
            ui->view_table->setItem(i, 17, new QTableWidgetItem(animalFriendly));

=======

            animalFriendly1 = list.getAnimalAnimalFriendly(i);
            animalFriendly = QString::fromStdString(animalFriendly1);
            ui->view_table->setItem(i, 17, new QTableWidgetItem(animalFriendly));

>>>>>>> master
            equipment1 = list.getAnimalEquipment(i);
            equipment = QString::fromStdString(equipment1);
            ui->view_table->setItem(i, 15, new QTableWidgetItem(equipment));

            excitement1 = list.getAnimalExcitability(i);
            excitement = QString::fromStdString(excitement1);
            ui->view_table->setItem(i, 18, new QTableWidgetItem(excitement));
        }


}

void MainWindow::AddClientToTable(){

    for(int i=ui->view_table_3->rowCount(); i>=0; i--)
    {
        ui->view_table_3->removeRow(i);
    }

    for(int i=0; i < clientList.getNumClients(); i++)
    {
        ui->view_table_3->insertRow(i);

        ui->view_table_3->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(clientList.getClientName(i))));
        ui->view_table_3->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(clientList.getClientUsername(i))));
        ui->view_table_3->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(clientList.getClientPassword(i))));
        ui->view_table_3->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(clientList.getClientPhoneNumber(i))));
        ui->view_table_3->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(clientList.getClientAddress(i))));
        ui->view_table_3->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(clientList.getClientPostalCode(i))));
        ui->view_table_3->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(clientList.getClientProvince(i))));
    }
}

//Function will add the animal objects into the QTTable widget
//Commented out code is a guideline on how to insert data into the table
void MainWindow::AddToTableClient()
{
    for(int i=ui->view_table_2->rowCount()-1; i>=0; i--)
    {
        ui->view_table_2->removeRow(i);
    }

        QString name,gender,species,breed,hairType,hairColour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space,child,animalFriendly,equipment,excitement,age;
        string name1,gender1,species1,breed1,hairType1,hairColour1,aggressiveness1,hyperactivity1,sleep1,noise1,appetite1,maintainance1,outside1,space1,child1,animalFriendly1,equipment1,excitement1;
        int age1;

        //returns number of animals in list
        int numAnimal = list.getNumAnimal();

        //Before query would return with all the sql data, change query to appropriately use a list of animal objects
        for(int i = 0; i< numAnimal; i++) {
            ui->view_table_2->insertRow(i);
            ui->view_table_2->setRowHeight(i,50);

            //gets info on animal object
            name1 = list.getAnimalName(i);
            name = QString::fromStdString(name1);
            ui->view_table_2->setItem(i, 0, new QTableWidgetItem(name));

            gender1 = list.getAnimalGender(i);
            gender = QString::fromStdString(gender1);
            ui->view_table_2->setItem(i, 1, new QTableWidgetItem(gender));

            age1 = list.getAnimalAge(i);
            age = QString::number(age1);
            ui->view_table_2->setItem(i, 2, new QTableWidgetItem(age));

            species1 = list.getAnimalSpecies(i);
            species = QString::fromStdString(species1);
            ui->view_table_2->setItem(i, 3, new QTableWidgetItem(species));

            breed1 = list.getAnimalBreed(i);
            breed = QString::fromStdString(breed1);
            ui->view_table_2->setItem(i, 4, new QTableWidgetItem(breed));

            hairType1 = list.getAnimalHairType(i);
            hairType = QString::fromStdString(hairType1);
            ui->view_table_2->setItem(i, 5, new QTableWidgetItem(hairType));

            hairColour1 = list.getAnimalHairColour(i);
            hairColour = QString::fromStdString(hairColour1);
            ui->view_table_2->setItem(i, 6, new QTableWidgetItem(hairColour));

            aggressiveness1 = list.getAnimalAggressiveness(i);
            aggressiveness = QString::fromStdString(aggressiveness1);
            ui->view_table_2->setItem(i, 7, new QTableWidgetItem(aggressiveness));

            hyperactivity1 = list.getAnimalHyperactivity(i);
            hyperactivity = QString::fromStdString(hyperactivity1);
            ui->view_table_2->setItem(i, 8, new QTableWidgetItem(hyperactivity));

            sleep1 = list.getAnimalSleep(i);
            sleep = QString::fromStdString(sleep1);
            ui->view_table_2->setItem(i, 9, new QTableWidgetItem(sleep));

            noise1 = list.getAnimalNoise(i);
            noise = QString::fromStdString(noise1);
            ui->view_table_2->setItem(i, 10, new QTableWidgetItem(noise));

            appetite1 = list.getAnimalAppetite(i);
            appetite = QString::fromStdString(appetite1);
            ui->view_table_2->setItem(i, 11, new QTableWidgetItem(appetite));

            maintainance1 = list.getAnimalMaintainance(i);
            maintainance = QString::fromStdString(maintainance1);
            ui->view_table_2->setItem(i, 12, new QTableWidgetItem(maintainance));

            outside1 = list.getAnimalOutside(i);
            outside = QString::fromStdString(outside1);
            ui->view_table_2->setItem(i, 13, new QTableWidgetItem(outside));

            space1 = list.getAnimalSpace(i);
            space = QString::fromStdString(space1);
            ui->view_table_2->setItem(i, 14, new QTableWidgetItem(space));

            equipment1 = list.getAnimalEquipment(i);
            equipment = QString::fromStdString(equipment1);
            ui->view_table_2->setItem(i, 15, new QTableWidgetItem(equipment));

            child1 = list.getAnimalChild(i);
            child = QString::fromStdString(child1);
            ui->view_table_2->setItem(i, 16, new QTableWidgetItem(child));

            animalFriendly1 = list.getAnimalAnimalFriendly(i);
            animalFriendly = QString::fromStdString(animalFriendly1);
            ui->view_table_2->setItem(i, 17, new QTableWidgetItem(animalFriendly));

            excitement1 = list.getAnimalExcitability(i);
            excitement = QString::fromStdString(excitement1);
            ui->view_table_2->setItem(i, 18, new QTableWidgetItem(excitement));
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
        //qWarning() << "User not Found!";
        QSqlQuery query1;
        query1.prepare("SELECT password FROM CLIENTS WHERE USERNAME = :clients_username");
        query1.bindValue(":clients_username", ui->username_input->text());

        query1.exec();

        if(!query1.next()){
            qWarning() << "User not Found!";
        }else{

            if(query1.value(0).toString() == ui->password_input->text()) {
                qDebug() << "Welcome!";
<<<<<<< HEAD
                ui->stackedWidget->setCurrentIndex(6);
=======
                ui->stackedWidget->setCurrentIndex(4);
>>>>>>> master
                AddToTableClient();


            }else {
                qWarning() << "Incorrect Password!";
            }
        }



    }else {
        qDebug() << "Found the user! ";

        if(query.value(0).toString() == ui->password_input->text()) {
            qDebug() << "Welcome!";
            ui->stackedWidget->setCurrentIndex(1);
            ui->view_table_2->hide();
            ui->table_frame->show();
            on_view_button_clicked();
            AddToTable();

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
    QString animalAggressiveness = ui->aggressivenessCombo->currentText();
    QString animalHyperactivity = ui->hyperactivity_combo->currentText();
    QString animalSleep = ui->sleep_combo->currentText();
    QString animalNoise = ui->noise_combo->currentText();
    QString animalAppetite = ui->appetite_combo->currentText();
    QString animalMaintainance = ui->maintainance_combo->currentText();
    QString animalOutside = ui->outside_combo->currentText();
    QString animalSpace = ui->space_combo->currentText();
    QString animalChild = ui->child_combo->currentText();
    QString animalAnimal = ui->animal_combo->currentText();
    QString animalEquipment = ui->equipment_combo->currentText();
    QString animalExcitment = ui->excitibility_combo->currentText();



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
    animalId = id_data + 1;

    //adds animal to list
    Animal *animal = new Animal(animalName.toStdString(), animalGender.toStdString(), animalSpecies.toStdString(),
                                animalBreed.toStdString(), animalHairType.toStdString(), animalHairColour.toStdString(),animalAggressiveness.toStdString(),animalHyperactivity.toStdString(),animalSleep.toStdString(),
                                animalNoise.toStdString(),animalAppetite.toStdString(),animalMaintainance.toStdString(),animalOutside.toStdString(),animalSpace.toStdString(),animalChild.toStdString()
                                ,animalAnimal.toStdString(),animalEquipment.toStdString(),animalExcitment.toStdString(),ageInt, animalId);
    list.addAnimal(animal);



    //adds animal to database
    addQuery.prepare("INSERT INTO ANIMALS (animal_id, name)"
                         "VALUES (:animal_id, :name)");
    addQuery.bindValue(":animal_id", animalId);
    addQuery.bindValue(":name", animalName);
    addQuery.exec();

    addQuery.prepare("INSERT INTO PHYSICAL_ATTRIBUTES (a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)"
                         "VALUES (:a_id, :gender, :age, :species, :breed, :hair_type, :hair_colour,:aggressiveness,:hyperactivity,:sleep,:noise,:appetite,:maintainance,:outside,:space_required,:child_friendly,:animal_friendly,:equipment,:excitibility)");
    addQuery.bindValue(":a_id", animalId);
    addQuery.bindValue(":gender", animalGender);
    addQuery.bindValue(":age", ageInt);
    addQuery.bindValue(":species", animalSpecies);
    addQuery.bindValue(":breed", animalBreed);
    addQuery.bindValue(":hair_type", animalHairType);
    addQuery.bindValue(":hair_colour", animalHairColour);
    addQuery.bindValue(":aggressiveness", animalAggressiveness);
    addQuery.bindValue(":hyperactivity", animalAggressiveness);
    addQuery.bindValue(":sleep", animalAggressiveness);
    addQuery.bindValue(":noise", animalAggressiveness);
    addQuery.bindValue(":appetite", animalAggressiveness);
    addQuery.bindValue(":maintainance", animalAggressiveness);
    addQuery.bindValue(":outside", animalAggressiveness);
    addQuery.bindValue(":space_required", animalAggressiveness);
    addQuery.bindValue(":child_friendly", animalAggressiveness);
    addQuery.bindValue(":animal_friendly", animalAggressiveness);
    addQuery.bindValue(":equipment", animalAggressiveness);
    addQuery.bindValue(":excitibility", animalAggressiveness);
    addQuery.exec();

    ui->input_01->setText("");
    ui->input_03->setText("");
    ui->input_02->setText("");
    ui->input_05->setText("");
    ui->input_06->setText("");
    ui->input_07->setText("");
    ui->input_04->setText("");
    ui->aggressivenessCombo->setCurrentIndex(0);
    ui->hyperactivity_combo->setCurrentIndex(0);
    ui->sleep_combo->setCurrentIndex(0);
    ui->noise_combo->setCurrentIndex(0);
    ui->appetite_combo->setCurrentIndex(0);
    ui->maintainance_combo->setCurrentIndex(0);
    ui->outside_combo->setCurrentIndex(0);
    ui->space_combo->setCurrentIndex(0);
    ui->child_combo->setCurrentIndex(0);
    ui->animal_combo->setCurrentIndex(0);
    ui->equipment_combo->setCurrentIndex(0);
    ui->excitibility_combo->setCurrentIndex(0);

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

    int pref[14];

    //add int query values to array
    pref[0] = ui->ClientAnimalWanted_2->currentIndex();
    pref[1] = ui->ClientDealwithAgression_2->currentIndex();
    pref[2] = ui->ClientHyperactivity_2->currentIndex();
    pref[3] = ui->ClientPreferredSleep_2->currentIndex();
    pref[4] = ui->ClientAnimalLoudness_2->currentIndex();
    pref[5] = ui->ClientFoodBudget_2->currentIndex();
    pref[6] = ui->ClientTimeAvail_2->currentIndex();
    pref[7] = ui->ClientHouseType_2->currentIndex();
    pref[8] = ui->ClientChildren_2->currentIndex();
    pref[9] = ui->ClientEquipmentNeededBudget_2->currentIndex();
    pref[10] = ui->ClientOtherAnimal_2->currentIndex();
    pref[11] = ui->ClientExternalStimuli_2->currentIndex();
    pref[12] = ui->ClientAge_2->currentIndex();
    pref[13] = ui->ClientPreferredGender_2->currentIndex();

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


    clientId = id_data + 1;


    //adding client to client list
    Client *client = new Client(clientName.toStdString(), clientUsername.toStdString(), clientPassword.toStdString(), clientPhoneNumber.toStdString(),
                              clientAddress.toStdString(), clientPostalCode.toStdString(), clientProvince.toStdString(),clientId,pref);
   clientList.addClient(client);



    addQuery.prepare("INSERT INTO USERS (user_id, name, phone_number, address, postal_code, province)"
                         "VALUES (:user_id, :name, :phone_number, :address, :postal_code, :province)");
    addQuery.bindValue(":user_id", clientId);
    addQuery.bindValue(":name", clientName);
    addQuery.bindValue(":phone_number", clientPhoneNumber);
    addQuery.bindValue(":address", clientAddress);
    addQuery.bindValue(":postal_code", clientPostalCode);
    addQuery.bindValue(":province", clientProvince);
    addQuery.exec();

    addQuery.prepare("INSERT INTO CLIENTS (u_id, username, password,animal_wanted,agression,hyperactivity,sleep,animal_loudness,food_budget,time_avail,house_type,child_friendly, equip_budget, have_animals,ex_stimuli,pref_age,pref_gender)"
                         "VALUES (:u_id, :username, :password,:animal_wanted,:agression,:hyperactivity,:sleep,:animal_loudness,:food_budget,:time_avail,:house_type,:child_friendly,:equip_budget,:have_animals,:ex_stimuli,:pref_age,:pref_gender)");
    addQuery.bindValue(":u_id", clientId);
    addQuery.bindValue(":username", clientUsername);
    addQuery.bindValue(":password", clientPassword);
    addQuery.bindValue(":animal_wanted", ui->ClientAnimalWanted_2->currentIndex());
    addQuery.bindValue(":agression", ui->ClientDealwithAgression_2->currentIndex());
    addQuery.bindValue(":hyperactivity", ui->ClientHyperactivity_2->currentIndex());
    addQuery.bindValue(":sleep", ui->ClientPreferredSleep_2->currentIndex());
    addQuery.bindValue(":animal_loudness", ui->ClientAnimalLoudness_2->currentIndex());
    addQuery.bindValue(":food_budget", ui->ClientFoodBudget_2->currentIndex());
    addQuery.bindValue(":time_avail", ui->ClientTimeAvail_2->currentIndex());
    addQuery.bindValue(":house_type", ui->ClientHouseType_2->currentIndex());
    addQuery.bindValue(":child_friendly", ui->ClientChildren_2->currentIndex());
    addQuery.bindValue(":equip_budget", ui->ClientEquipmentNeededBudget_2->currentIndex());
    addQuery.bindValue(":have_animals", ui->ClientOtherAnimal_2->currentIndex());
    addQuery.bindValue(":ex_stimuli", ui->ClientExternalStimuli_2->currentIndex());
    addQuery.bindValue(":pref_age", ui->ClientAge_2->currentIndex());
    addQuery.bindValue(":pref_gender", ui->ClientPreferredGender_2->currentIndex());
    addQuery.exec();

    ui->input_01->setText("");
    ui->input_03->setText("");
    ui->input_02->setText("");
    ui->input_05->setText("");
    ui->input_06->setText("");
    ui->input_07->setText("");
    ui->input_04->setText("");

    ui->ClientAnimalWanted_2->setCurrentIndex(0);
    ui->ClientDealwithAgression_2->setCurrentIndex(0);
    ui->ClientHyperactivity_2->setCurrentIndex(0);
    ui->ClientPreferredSleep_2->setCurrentIndex(0);
    ui->ClientAnimalLoudness_2->setCurrentIndex(0);
    ui->ClientFoodBudget_2->setCurrentIndex(0);
    ui->ClientTimeAvail_2->setCurrentIndex(0);
    ui->ClientHouseType_2->setCurrentIndex(0);
    ui->ClientChildren_2->setCurrentIndex(0);
    ui->ClientEquipmentNeededBudget_2->setCurrentIndex(0);
    ui->ClientOtherAnimal_2->setCurrentIndex(0);
    ui->ClientExternalStimuli_2->setCurrentIndex(0);
    ui->ClientAge_2->setCurrentIndex(0);
    ui->ClientPreferredGender_2->setCurrentIndex(0);
}

void MainWindow::show_clients()
{
    ui->input_label_02->setText("Username:");
    ui->input_label_03->setText("Password:");
    ui->input_label_04->setText("Phone Number:");
    ui->input_label_05->setText("Address:");
    ui->input_label_06->setText("Postal Code:");
    ui->input_label_07->setText("Province:");
    ui->addAnimalFrame->hide();


}

void MainWindow::show_animals()
{
    ui->input_label_02->setText("Gender:");
    ui->input_label_03->setText("Age:");
    ui->input_label_04->setText("Species:");
    ui->input_label_05->setText("Breed:");
    ui->input_label_06->setText("Hair Type:");
    ui->input_label_07->setText("Hair Colour:");
    ui->addAnimalFrame->show();
<<<<<<< HEAD

}



void MainWindow::on_view_client_clicked()
{

    qDebug() << "Now looking at client menu";
    ui->table_frame->hide();
    ui->table_frame_2->show();
    ui->table_frame_2->move(140,70);
    show_clients();
    AddClientToTable();


}
//When a staff member is in add form already and wants to view client
//it hides the form and shows table
void MainWindow::on_view_client_2_clicked(){
    ui->stackedWidget->setCurrentIndex(1);
    ui->table_frame->hide();
    ui->table_frame_2->show();
    ui->table_frame_2->move(140,70);
    show_clients();
    AddClientToTable();
}


void MainWindow::on_view_client_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->table_frame->hide();
    ui->table_frame_2->show();
    ui->table_frame_2->move(140,70);
    show_clients();
    AddClientToTable();
}

//When a staff member selects add client it'll hide the current frame
//and show the add form
void MainWindow::on_add_client_clicked(){
    ui->stackedWidget->setCurrentIndex(2);
    ui->stack_add->setCurrentIndex(1);
    show_clients();

}

void MainWindow::on_add_client_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->stack_add->setCurrentIndex(1);
    show_clients();
}

void MainWindow::on_add_client_2_clicked(){
    show_clients();
    ui->stack_add->setCurrentIndex(1);

}

//Function is called when the view animals button is clicked
void MainWindow::on_view_button_clicked()
{
    ui->table_frame->show();
    ui->table_frame_2->hide();
    ui->table_frame->move(140,70);
    show_animals();
    AddToTable(); //This function will have to add our animal objects to the viewable table
}

void MainWindow::on_view_button_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->table_frame->show();
    ui->table_frame_2->hide();
    ui->table_frame->move(140,70);
    show_animals();
    AddToTable();
}

//adds animals to the table when a client is logged in
void MainWindow::on_view_animals_clicked()
{
    AddToTableClient();
}

void MainWindow::on_view_button_2_clicked(){
    ui->stackedWidget->setCurrentIndex(1);
    ui->table_frame->show();
    ui->table_frame_2->hide();
    ui->table_frame->move(140,70);
    show_animals();
    AddToTable();
}

void MainWindow::on_add_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->stack_add->setCurrentIndex(0);

    show_animals();


}

void MainWindow::on_add_button_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->stack_add->setCurrentIndex(0);

    show_animals();
}

void MainWindow::on_add_button_2_clicked()
{
    show_animals();
    ui->stack_add->setCurrentIndex(0);
}

//This is the submit button when staff adds
void MainWindow::on_submit_clicked(){

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
        if(ui->input_label_05->text() == "Breed:"){
            AddAnimal();
        }else{
            AddClient();
        }

    }

}

void MainWindow::on_editProfile_clicked(){
    ui->stackedWidget->setCurrentIndex(7);
    setupEditClient(ui->username_input->text());

}


void MainWindow::setupEditClient(QString name){

    int numClients = clientList.getNumClients();
    for(int i = 0; i < numClients; i++){
        string clientName = clientList.getClientUsername(i);
        QString gender = QString::fromStdString(clientName);
        if(gender == name ){

            int *p;
            p = clientList.getClientPreferences(i);
            //once we find a match of username we fill in the edit profile input fields
            ui->editClientName->setText(QString::fromStdString(clientList.getClientName(i)));
            ui->editClientUsername->setText(QString::fromStdString(clientList.getClientUsername(i)));
            ui->editClientPN->setText(QString::fromStdString(clientList.getClientPhoneNumber(i)));
            ui->editClientAddress->setText(QString::fromStdString(clientList.getClientAddress(i)));
            ui->EditClientPassword->setText(QString::fromStdString(clientList.getClientPassword(i)));
            ui->EditClientPostalCode->setText(QString::fromStdString(clientList.getClientPostalCode(i)));
            ui->editClientProvince->setText(QString::fromStdString(clientList.getClientProvince(i)));
            ui->client_id_label->setText(QString::number(clientList.getClientDatabase_id(i)));

            ui->ClientAnimalWanted->setCurrentIndex(p[0]);
            ui->ClientDealwithAgression->setCurrentIndex(p[1]);
            ui->ClientHyperactivity->setCurrentIndex(p[2]);
            ui->ClientPreferredSleep->setCurrentIndex(p[3]);
            ui->ClientAnimalLoudness->setCurrentIndex(p[4]);
            ui->ClientFoodBudget->setCurrentIndex(p[5]);
            ui->ClientTimeAvail->setCurrentIndex(p[6]);
            ui->ClientHouseType->setCurrentIndex(p[7]);
            ui->ClientChildren->setCurrentIndex(p[8]);
            ui->ClientEquipmentNeededBudget->setCurrentIndex(p[9]);
            ui->ClientOtherAnimal->setCurrentIndex(p[10]);
            ui->ClientExternalStimuli->setCurrentIndex(p[11]);
            ui->ClientAge->setCurrentIndex(p[12]);
            ui->ClientPreferredGender->setCurrentIndex(p[13]);



        }
    }


}

void MainWindow::on_submit_2_clicked(){

    //Following code updates the client into the database
    QSqlQuery addQuery;
    QSqlQuery idQuery;
    QString clientName = ui->editClientName->text();
    QString clientUsername = ui->editClientUsername->text();
    QString clientPassword = ui->EditClientPassword->text();
    QString clientPhoneNumber = ui->editClientPN->text();
    QString clientAddress = ui->editClientAddress->text();
    QString clientPostalCode = ui->EditClientPostalCode->text();
    QString clientProvince = ui->editClientProvince->text();


    int clientId = ui->client_id_label->text().toInt();
    idQuery.exec();

    addQuery.prepare("UPDATE USERS SET name=:name, phone_number=:phone_number, address=:address, postal_code=:postal_code, province=:province WHERE user_id=:user_id");

    addQuery.bindValue(":name", clientName);
    addQuery.bindValue(":phone_number", clientPhoneNumber);
    addQuery.bindValue(":address", clientAddress);
    addQuery.bindValue(":postal_code", clientPostalCode);
    addQuery.bindValue(":province", clientProvince);
    addQuery.bindValue(":user_id", clientId);
    addQuery.exec();

    addQuery.prepare("UPDATE CLIENTS SET username=:username, password=:password,animal_wanted=:animal_wanted,agression=:agression,hyperactivity=:hyperactivity,sleep=:sleep,animal_loudness=:animal_loudness,food_budget=:food_budget,time_avail=:time_avail,house_type=:house_type,child_friendly=:child_friendly, equip_budget=:equip_budget, have_animals=:have_animals,ex_stimuli=:ex_stimuli,pref_age=:pref_age,pref_gender=:pref_gender WHERE u_id=:u_id");
    addQuery.bindValue(":u_id", clientId);
    addQuery.bindValue(":username", clientUsername);
    addQuery.bindValue(":password", clientPassword);
    addQuery.bindValue(":animal_wanted", ui->ClientAnimalWanted->currentIndex());
    addQuery.bindValue(":agression", ui->ClientDealwithAgression->currentIndex());
    addQuery.bindValue(":hyperactivity", ui->ClientHyperactivity->currentIndex());
    addQuery.bindValue(":sleep", ui->ClientPreferredSleep->currentIndex());
    addQuery.bindValue(":animal_loudness", ui->ClientAnimalLoudness->currentIndex());
    addQuery.bindValue(":food_budget", ui->ClientFoodBudget->currentIndex());
    addQuery.bindValue(":time_avail", ui->ClientTimeAvail->currentIndex());
    addQuery.bindValue(":house_type", ui->ClientHouseType->currentIndex());
    addQuery.bindValue(":child_friendly", ui->ClientChildren->currentIndex());
    addQuery.bindValue(":equip_budget", ui->ClientEquipmentNeededBudget->currentIndex());
    addQuery.bindValue(":have_animals", ui->ClientOtherAnimal->currentIndex());
    addQuery.bindValue(":ex_stimuli", ui->ClientExternalStimuli->currentIndex());
    addQuery.bindValue(":pref_age", ui->ClientAge->currentIndex());
    addQuery.bindValue(":pref_gender", ui->ClientPreferredGender->currentIndex());
    addQuery.exec();

    //this->close();
    if (addQuery.exec())
    {
        QueryDatabase();
        qDebug() << "Client Updated";

        ui->stackedWidget->setCurrentIndex(1);
        ui->table_frame->hide();
        ui->table_frame_2->show();
        ui->table_frame_2->move(140,70);
        show_clients();
        AddClientToTable();
    }
    else
    {
        QMessageBox::information(this,"", addQuery.lastError().text());
    }

    /*ui->editClientName->setText("");
    ui->editClientUsername->setText("");
    ui->EditClientPassword->setText("");
    ui->editClientPN->setText("");
    ui->editClientAddress->setText("");
    ui->EditClientPostalCode->setText("");
    ui->editClientProvince->setText("");*/

}

void MainWindow::on_submit_3_clicked()
{
    //Following code updates the animal into the database
    QSqlQuery addQuery;

    int animalAge = ui->input_4->text().toInt();

    int a_id = ui->aIdLbl->text().toInt();

    addQuery.prepare("UPDATE PHYSICAL_ATTRIBUTES SET gender=:gender, age=:age, species=:species, breed=:breed, hair_type=:hair_type, hair_colour=:hair_colour, aggressiveness=:agg, hyperactivity=:hyp, sleep=:sleep, noise=:noise, appetite=:app, maintainance=:man, outside=:outside, space_required=:spa, child_friendly=:chi, animal_friendly=:ani, equipment=:equ, excitibility=:exc WHERE a_id=:a_id");
    addQuery.bindValue(":a_id", a_id);
    addQuery.bindValue(":gender", ui->input_3->text());
    addQuery.bindValue(":age", animalAge);
    addQuery.bindValue(":species", ui->input_5->text());
    addQuery.bindValue(":breed", ui->input_6->text());
    addQuery.bindValue(":hair_type", ui->input_7->text());
    addQuery.bindValue(":hair_colour", ui->input_8->text());
    addQuery.bindValue(":agg", ui->aggressivenessCombo_2->currentText());
    addQuery.bindValue(":hyp", ui->hyperactivity_combo_2->currentText());
    addQuery.bindValue(":sleep", ui->sleep_combo_2->currentText());
    addQuery.bindValue(":noise", ui->noise_combo_2->currentText());
    addQuery.bindValue(":app", ui->appetite_combo_2->currentText());
    addQuery.bindValue(":man", ui->maintainance_combo_2->currentText());
    addQuery.bindValue(":outside", ui->outside_combo_2->currentText());
    addQuery.bindValue(":spa", ui->space_combo_2->currentText());
    addQuery.bindValue(":chi", ui->child_combo_2->currentText());
    addQuery.bindValue(":ani", ui->animal_combo_2->currentText());
    addQuery.bindValue(":equ", ui->equipment_combo_2->currentText());
    addQuery.bindValue(":exc", ui->excitibility_combo_2->currentText());
    addQuery.exec();

    //this->close();
    if (addQuery.exec())
    {
        QueryDatabase();
        qDebug() << "Client Updated";
        ui->stackedWidget->setCurrentIndex(1);
        ui->table_frame->show();
        ui->table_frame_2->hide();
        ui->table_frame->move(140,70);
        show_animals();
        AddToTable();
    }
    else
    {
        QMessageBox::information(this,"", addQuery.lastError().text());
    }
}


void MainWindow::on_view_table_cellDoubleClicked(int row, int column)
{
    ui->stackedWidget->setCurrentIndex(3);
    EditAnimal(row);
}

void MainWindow::EditAnimal(int row){
    QString aId, age1, name,gender,species,breed,hairType,hairColour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space,child,animalFriendly,equipment,excitement;
    int age, a_id_int;

    QString animalName = ui->view_table->item(row, 0)->text();
    QSqlQuery query;
    query.prepare("SELECT NAME, gender, age, species, breed, hair_type, hair_colour, aggressiveness, hyperactivity, sleep, noise, appetite, maintainance, outside, space_required, child_friendly, animal_friendly, equipment, excitibility, ANIMALS.animal_id FROM ANIMALS INNER JOIN PHYSICAL_ATTRIBUTES ON ANIMALS.animal_id = PHYSICAL_ATTRIBUTES.a_id WHERE NAME=:aName;");
    query.bindValue(":aName", animalName);

    if(!query.exec())
        qWarning() << "Query Failed!";


    while(query.next()) {

        //use the data that gets fed into this string to create the animal objects

        name = query.value(0).toString();

        gender = query.value(1).toString();

        age = query.value(2).toInt();

        age1 = QString::number(age);

        species = query.value(3).toString();

        breed = query.value(4).toString();

        hairType = query.value(5).toString();

        hairColour = query.value(6).toString();

        aggressiveness = query.value(7).toString();

        hyperactivity = query.value(8).toString();

        sleep = query.value(9).toString();

        noise = query.value(10).toString();

        appetite = query.value(11).toString();

        maintainance = query.value(12).toString();

        outside = query.value(13).toString();

        space = query.value(14).toString();

        child = query.value(15).toString();

        animalFriendly = query.value(16).toString();

        equipment = query.value(17).toString();

        excitement = query.value(18).toString();

        a_id_int = query.value(19).toInt();

        aId = QString::number(a_id_int);

    }

    ui->input_2->setText(name);
    ui->input_3->setText(gender);
    ui->input_4->setText(age1);
    ui->input_5->setText(species);
    ui->input_6->setText(breed);
    ui->input_7->setText(hairType);
    ui->input_8->setText(hairColour);

    ui->aIdLbl->setText(aId);

    int currIndex = ui->aggressivenessCombo_2->findText(aggressiveness);
    ui->aggressivenessCombo_2->setCurrentIndex(currIndex);

    currIndex = ui->hyperactivity_combo_2->findText(hyperactivity);
    ui->hyperactivity_combo_2->setCurrentIndex(currIndex);

    currIndex = ui->sleep_combo_2->findText(sleep);
    ui->sleep_combo_2->setCurrentIndex(currIndex);

    currIndex = ui->noise_combo_2->findText(noise);
    ui->noise_combo_2->setCurrentIndex(currIndex);

    currIndex = ui->appetite_combo_2->findText(appetite);
    ui->appetite_combo_2->setCurrentIndex(currIndex);

    currIndex = ui->maintainance_combo_2->findText(maintainance);
    ui->maintainance_combo_2->setCurrentIndex(currIndex);

    currIndex = ui->outside_combo_2->findText(outside);
    ui->outside_combo_2->setCurrentIndex(currIndex);

    currIndex = ui->space_combo_2->findText(space);
    ui->space_combo_2->setCurrentIndex(currIndex);

    currIndex = ui->child_combo_2->findText(child);
    ui->child_combo_2->setCurrentIndex(currIndex);

    currIndex = ui->animal_combo_2->findText(animalFriendly);
    ui->animal_combo_2->setCurrentIndex(currIndex);

    currIndex = ui->equipment_combo_2->findText(equipment);
    ui->equipment_combo_2->setCurrentIndex(currIndex);

    currIndex = ui->excitibility_combo_2->findText(excitement);
    ui->excitibility_combo_2->setCurrentIndex(currIndex);
=======

>>>>>>> master
}


void MainWindow::on_ClientViewAnimalProfile_clicked(){

    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_view_client_clicked()
{
<<<<<<< HEAD
    delete ui;
    clientList.deleteList();
    list.deleteList();
}

void MainWindow::on_runACM_clicked()
{
    runACM();
}

void MainWindow::on_run_acm_clicked(){

    runACM();

}

void MainWindow::on_run_acm2_clicked(){

    runACM();

}

void MainWindow::runACM(){

    ui->stackedWidget->setCurrentIndex(4);

    for(int i=ui->acm_table->rowCount(); i>=0; i--)
    {
        ui->acm_table->removeRow(i);
    }

    optimalSet.clear();
    algorithm.compute(list, clientList, optimalSet);//run the algorithm

    for(int i = 0; i<(int)(optimalSet.size()); i++){
        qDebug() << i << ") " << optimalSet.at(i).getOverallScore() << " Animal: " << optimalSet.at(i).getAnimal()->getId() << " Client: " << optimalSet.at(i).getClient()->getDatabaseId();

        ui->acm_table->insertRow(i);
        ui->acm_table->setRowHeight(i,50);


        QString percent, animalName, clientName;
        string animal_Name, client_name;
        float percent1;

        animal_Name = optimalSet.at(i).getAnimal()->getName();
        animalName = QString::fromStdString(animal_Name);

        percent1 = optimalSet.at(i).getOverallScore();
        percent = QString::number(percent1);

        client_name = optimalSet.at(i).getClient()->getName();
        clientName = QString::fromStdString(client_name);

        ui->acm_table->setItem(i, 0, new QTableWidgetItem(percent));
        ui->acm_table->setItem(i, 1, new QTableWidgetItem(animalName));
        ui->acm_table->setItem(i, 2, new QTableWidgetItem(clientName));


=======

    qDebug() << "Now looking at client menu";
    ui->table_frame->hide();
    ui->table_frame_2->show();
    ui->table_frame_2->move(140,70);
    show_clients();
    AddClientToTable();


}
//When a staff member is in add form already and wants to view client
//it hides the form and shows table
void MainWindow::on_view_client_2_clicked(){
    ui->stackedWidget->setCurrentIndex(1);
    ui->table_frame->hide();
    ui->table_frame_2->show();
    ui->table_frame_2->move(140,70);
    show_clients();
    AddClientToTable();
}


void MainWindow::on_view_client_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->table_frame->hide();
    ui->table_frame_2->show();
    ui->table_frame_2->move(140,70);
    show_clients();
    AddClientToTable();
}

//When a staff member selects add client it'll hide the current frame
//and show the add form
void MainWindow::on_add_client_clicked(){
    ui->stackedWidget->setCurrentIndex(2);
    ui->stack_add->setCurrentIndex(1);
    show_clients();

}

void MainWindow::on_add_client_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->stack_add->setCurrentIndex(1);
    show_clients();
}

void MainWindow::on_add_client_2_clicked(){
    show_clients();
    ui->stack_add->setCurrentIndex(1);

}

//Function is called when the view animals button is clicked
void MainWindow::on_view_button_clicked()
{
    ui->table_frame->show();
    ui->table_frame_2->hide();
    ui->table_frame->move(140,70);
    show_animals();
    AddToTable(); //This function will have to add our animal objects to the viewable table
}

void MainWindow::on_view_button_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->table_frame->show();
    ui->table_frame_2->hide();
    ui->table_frame->move(140,70);
    show_animals();
    AddToTable();
}

//adds animals to the table when a client is logged in
void MainWindow::on_view_animals_clicked()
{
    AddToTableClient();
}

void MainWindow::on_view_button_2_clicked(){
    ui->stackedWidget->setCurrentIndex(1);
    ui->table_frame->show();
    ui->table_frame_2->hide();
    ui->table_frame->move(140,70);
    show_animals();
    AddToTable();
}

void MainWindow::on_add_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->stack_add->setCurrentIndex(0);

    show_animals();


}

void MainWindow::on_add_button_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->stack_add->setCurrentIndex(0);

    show_animals();
}

void MainWindow::on_add_button_2_clicked()
{
    show_animals();
    ui->stack_add->setCurrentIndex(0);
}

//This is the submit button when staff adds
void MainWindow::on_submit_clicked(){

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
        if(ui->input_label_05->text() == "Breed:"){
            AddAnimal();
        }else{
            AddClient();
        }

    }

}

void MainWindow::on_editProfile_clicked(){
    ui->stackedWidget->setCurrentIndex(5);
    setupEditClient(ui->username_input->text());

}


void MainWindow::setupEditClient(QString name){

    int numClients = clientList.getNumClients();
    for(int i = 0; i < numClients; i++){
        string clientName = clientList.getClientUsername(i);
        QString gender = QString::fromStdString(clientName);
        if(gender == name ){

            int *p;
            p = clientList.getClientPreferences(i);
            //once we find a match of username we fill in the edit profile input fields
            ui->editClientName->setText(QString::fromStdString(clientList.getClientName(i)));
            ui->editClientUsername->setText(QString::fromStdString(clientList.getClientUsername(i)));
            ui->editClientPN->setText(QString::fromStdString(clientList.getClientPhoneNumber(i)));
            ui->editClientAddress->setText(QString::fromStdString(clientList.getClientAddress(i)));
            ui->EditClientPassword->setText(QString::fromStdString(clientList.getClientPassword(i)));
            ui->EditClientPostalCode->setText(QString::fromStdString(clientList.getClientPostalCode(i)));
            ui->editClientProvince->setText(QString::fromStdString(clientList.getClientProvince(i)));
            ui->client_id_label->setText(QString::number(clientList.getClientDatabase_id(i)));

            ui->ClientAnimalWanted->setCurrentIndex(p[0]);
            ui->ClientDealwithAgression->setCurrentIndex(p[1]);
            ui->ClientHyperactivity->setCurrentIndex(p[2]);
            ui->ClientPreferredSleep->setCurrentIndex(p[3]);
            ui->ClientAnimalLoudness->setCurrentIndex(p[4]);
            ui->ClientFoodBudget->setCurrentIndex(p[5]);
            ui->ClientTimeAvail->setCurrentIndex(p[6]);
            ui->ClientHouseType->setCurrentIndex(p[7]);
            ui->ClientChildren->setCurrentIndex(p[8]);
            ui->ClientEquipmentNeededBudget->setCurrentIndex(p[9]);
            ui->ClientOtherAnimal->setCurrentIndex(p[10]);
            ui->ClientExternalStimuli->setCurrentIndex(p[11]);
            ui->ClientAge->setCurrentIndex(p[12]);
            ui->ClientPreferredGender->setCurrentIndex(p[13]);



        }
    }


}

void MainWindow::on_submit_2_clicked(){

    //Following code updates the client into the database
    QSqlQuery addQuery;
    QSqlQuery idQuery;
    QString clientName = ui->editClientName->text();
    QString clientUsername = ui->editClientUsername->text();
    QString clientPassword = ui->EditClientPassword->text();
    QString clientPhoneNumber = ui->editClientPN->text();
    QString clientAddress = ui->editClientAddress->text();
    QString clientPostalCode = ui->EditClientPostalCode->text();
    QString clientProvince = ui->editClientProvince->text();


    int clientId = ui->client_id_label->text().toInt();
    idQuery.exec();

    addQuery.prepare("UPDATE USERS SET name=:name, phone_number=:phone_number, address=:address, postal_code=:postal_code, province=:province WHERE user_id=:user_id");

    addQuery.bindValue(":name", clientName);
    addQuery.bindValue(":phone_number", clientPhoneNumber);
    addQuery.bindValue(":address", clientAddress);
    addQuery.bindValue(":postal_code", clientPostalCode);
    addQuery.bindValue(":province", clientProvince);
    addQuery.bindValue(":user_id", clientId);
    addQuery.exec();

    addQuery.prepare("UPDATE CLIENTS SET username=:username, password=:password,animal_wanted=:animal_wanted,agression=:agression,hyperactivity=:hyperactivity,sleep=:sleep,animal_loudness=:animal_loudness,food_budget=:food_budget,time_avail=:time_avail,house_type=:house_type,child_friendly=:child_friendly, equip_budget=:equip_budget, have_animals=:have_animals,ex_stimuli=:ex_stimuli,pref_age=:pref_age,pref_gender=:pref_gender WHERE u_id=:u_id");
    addQuery.bindValue(":u_id", clientId);
    addQuery.bindValue(":username", clientUsername);
    addQuery.bindValue(":password", clientPassword);
    addQuery.bindValue(":animal_wanted", ui->ClientAnimalWanted->currentIndex());
    addQuery.bindValue(":agression", ui->ClientDealwithAgression->currentIndex());
    addQuery.bindValue(":hyperactivity", ui->ClientHyperactivity->currentIndex());
    addQuery.bindValue(":sleep", ui->ClientPreferredSleep->currentIndex());
    addQuery.bindValue(":animal_loudness", ui->ClientAnimalLoudness->currentIndex());
    addQuery.bindValue(":food_budget", ui->ClientFoodBudget->currentIndex());
    addQuery.bindValue(":time_avail", ui->ClientTimeAvail->currentIndex());
    addQuery.bindValue(":house_type", ui->ClientHouseType->currentIndex());
    addQuery.bindValue(":child_friendly", ui->ClientChildren->currentIndex());
    addQuery.bindValue(":equip_budget", ui->ClientEquipmentNeededBudget->currentIndex());
    addQuery.bindValue(":have_animals", ui->ClientOtherAnimal->currentIndex());
    addQuery.bindValue(":ex_stimuli", ui->ClientExternalStimuli->currentIndex());
    addQuery.bindValue(":pref_age", ui->ClientAge->currentIndex());
    addQuery.bindValue(":pref_gender", ui->ClientPreferredGender->currentIndex());
    addQuery.exec();

    //this->close();
    if (addQuery.exec())
    {
        QueryDatabase();
        qDebug() << "Client Updated";

        ui->stackedWidget->setCurrentIndex(1);
        ui->table_frame->hide();
        ui->table_frame_2->show();
        ui->table_frame_2->move(140,70);
        show_clients();
        AddClientToTable();
    }
    else
    {
        QMessageBox::information(this,"", addQuery.lastError().text());
    }

    /*ui->editClientName->setText("");
    ui->editClientUsername->setText("");
    ui->EditClientPassword->setText("");
    ui->editClientPN->setText("");
    ui->editClientAddress->setText("");
    ui->EditClientPostalCode->setText("");
    ui->editClientProvince->setText("");*/

}

void MainWindow::on_submit_3_clicked()
{
    //Following code updates the animal into the database
    QSqlQuery addQuery;

    int animalAge = ui->input_4->text().toInt();

    int a_id = ui->aIdLbl->text().toInt();

    addQuery.prepare("UPDATE PHYSICAL_ATTRIBUTES SET gender=:gender, age=:age, species=:species, breed=:breed, hair_type=:hair_type, hair_colour=:hair_colour, aggressiveness=:agg, hyperactivity=:hyp, sleep=:sleep, noise=:noise, appetite=:app, maintainance=:man, outside=:outside, space_required=:spa, child_friendly=:chi, animal_friendly=:ani, equipment=:equ, excitibility=:exc WHERE a_id=:a_id");
    addQuery.bindValue(":a_id", a_id);
    addQuery.bindValue(":gender", ui->input_3->text());
    addQuery.bindValue(":age", animalAge);
    addQuery.bindValue(":species", ui->input_5->text());
    addQuery.bindValue(":breed", ui->input_6->text());
    addQuery.bindValue(":hair_type", ui->input_7->text());
    addQuery.bindValue(":hair_colour", ui->input_8->text());
    addQuery.bindValue(":agg", ui->aggressivenessCombo_2->currentText());
    addQuery.bindValue(":hyp", ui->hyperactivity_combo_2->currentText());
    addQuery.bindValue(":sleep", ui->sleep_combo_2->currentText());
    addQuery.bindValue(":noise", ui->noise_combo_2->currentText());
    addQuery.bindValue(":app", ui->appetite_combo_2->currentText());
    addQuery.bindValue(":man", ui->maintainance_combo_2->currentText());
    addQuery.bindValue(":outside", ui->outside_combo_2->currentText());
    addQuery.bindValue(":spa", ui->space_combo_2->currentText());
    addQuery.bindValue(":chi", ui->child_combo_2->currentText());
    addQuery.bindValue(":ani", ui->animal_combo_2->currentText());
    addQuery.bindValue(":equ", ui->equipment_combo_2->currentText());
    addQuery.bindValue(":exc", ui->excitibility_combo_2->currentText());
    addQuery.exec();

    //this->close();
    if (addQuery.exec())
    {
        QueryDatabase();
        qDebug() << "Client Updated";
        ui->stackedWidget->setCurrentIndex(1);
        ui->table_frame->show();
        ui->table_frame_2->hide();
        ui->table_frame->move(140,70);
        show_animals();
        AddToTable();
    }
    else
    {
        QMessageBox::information(this,"", addQuery.lastError().text());
>>>>>>> master
    }
    //display results


}

void MainWindow::on_back_button_clicked(){
    ui->stackedWidget->setCurrentIndex(4);
}

//ACM BUTTONS

void MainWindow::on_acmViewAnimals_clicked(){
    ui->stackedWidget->setCurrentIndex(1);
    ui->table_frame->show();
    ui->table_frame_2->hide();
    ui->table_frame->move(140,70);
    show_animals();
    AddToTable();
}

<<<<<<< HEAD
void MainWindow::on_acmViewClients_clicked(){
    ui->stackedWidget->setCurrentIndex(1);
    ui->table_frame->hide();
    ui->table_frame_2->show();
    ui->table_frame_2->move(140,70);
    show_clients();
    AddClientToTable();
}

void MainWindow::on_acmAddAnimal_clicked(){
    ui->stackedWidget->setCurrentIndex(2);
    ui->stack_add->setCurrentIndex(0);

    show_animals();
}

void MainWindow::on_acmAddClient_clicked(){
    ui->stackedWidget->setCurrentIndex(2);
    ui->stack_add->setCurrentIndex(1);
    show_clients();
}


void MainWindow::on_acm_table_cellDoubleClicked(int row, int column){
    ui->stackedWidget->setCurrentIndex(5);

    QString match = ui->acm_table->item(row, 0)->text() + "%";
    QString client = ui->acm_table->item(row, 2)->text();
    QString animal = ui->acm_table->item(row, 1)->text();

    ui->match_percentage->setText(match);
    ui->animal_name->setText(animal);
    ui->client_name->setText(client);

=======

void MainWindow::on_view_table_cellDoubleClicked(int row, int column)
{
    ui->stackedWidget->setCurrentIndex(3);
    EditAnimal(row);
}

void MainWindow::EditAnimal(int row){
    QString aId, age1, name,gender,species,breed,hairType,hairColour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space,child,animalFriendly,equipment,excitement;
    int age, a_id_int;

    QString animalName = ui->view_table->item(row, 0)->text();
    QSqlQuery query;
    query.prepare("SELECT NAME, gender, age, species, breed, hair_type, hair_colour, aggressiveness, hyperactivity, sleep, noise, appetite, maintainance, outside, space_required, child_friendly, animal_friendly, equipment, excitibility, ANIMALS.animal_id FROM ANIMALS INNER JOIN PHYSICAL_ATTRIBUTES ON ANIMALS.animal_id = PHYSICAL_ATTRIBUTES.a_id WHERE NAME=:aName;");
    query.bindValue(":aName", animalName);

    if(!query.exec())
        qWarning() << "Query Failed!";


    while(query.next()) {

        //use the data that gets fed into this string to create the animal objects

        name = query.value(0).toString();

        gender = query.value(1).toString();

        age = query.value(2).toInt();

        age1 = QString::number(age);

        species = query.value(3).toString();

        breed = query.value(4).toString();

        hairType = query.value(5).toString();

        hairColour = query.value(6).toString();

        aggressiveness = query.value(7).toString();

        hyperactivity = query.value(8).toString();

        sleep = query.value(9).toString();

        noise = query.value(10).toString();

        appetite = query.value(11).toString();

        maintainance = query.value(12).toString();

        outside = query.value(13).toString();

        space = query.value(14).toString();

        child = query.value(15).toString();

        animalFriendly = query.value(16).toString();

        equipment = query.value(17).toString();

        excitement = query.value(18).toString();

        a_id_int = query.value(19).toInt();

        aId = QString::number(a_id_int);

    }

    ui->input_2->setText(name);
    ui->input_3->setText(gender);
    ui->input_4->setText(age1);
    ui->input_5->setText(species);
    ui->input_6->setText(breed);
    ui->input_7->setText(hairType);
    ui->input_8->setText(hairColour);

    ui->aIdLbl->setText(aId);

    int currIndex = ui->aggressivenessCombo_2->findText(aggressiveness);
    ui->aggressivenessCombo_2->setCurrentIndex(currIndex);

    currIndex = ui->hyperactivity_combo_2->findText(hyperactivity);
    ui->hyperactivity_combo_2->setCurrentIndex(currIndex);

    currIndex = ui->sleep_combo_2->findText(sleep);
    ui->sleep_combo_2->setCurrentIndex(currIndex);

    currIndex = ui->noise_combo_2->findText(noise);
    ui->noise_combo_2->setCurrentIndex(currIndex);

    currIndex = ui->appetite_combo_2->findText(appetite);
    ui->appetite_combo_2->setCurrentIndex(currIndex);

    currIndex = ui->maintainance_combo_2->findText(maintainance);
    ui->maintainance_combo_2->setCurrentIndex(currIndex);

    currIndex = ui->outside_combo_2->findText(outside);
    ui->outside_combo_2->setCurrentIndex(currIndex);

    currIndex = ui->space_combo_2->findText(space);
    ui->space_combo_2->setCurrentIndex(currIndex);

    currIndex = ui->child_combo_2->findText(child);
    ui->child_combo_2->setCurrentIndex(currIndex);

    currIndex = ui->animal_combo_2->findText(animalFriendly);
    ui->animal_combo_2->setCurrentIndex(currIndex);

    currIndex = ui->equipment_combo_2->findText(equipment);
    ui->equipment_combo_2->setCurrentIndex(currIndex);

    currIndex = ui->excitibility_combo_2->findText(excitement);
    ui->excitibility_combo_2->setCurrentIndex(currIndex);
}


void MainWindow::on_ClientViewAnimalProfile_clicked(){

    ui->stackedWidget->setCurrentIndex(4);
}

MainWindow::~MainWindow()
{
    delete ui;
    clientList.deleteList();
    list.deleteList();
}

void MainWindow::on_runACM_clicked()
{
    optimalSet.clear();
    algorithm.compute(list, clientList, optimalSet);//run the algorithm

    //for(int i = 0; i<(int)(optimalSet.size()); i++){
    //    qDebug() << i << ") " << optimalSet.at(i).getOverallScore() << " Animal: " << optimalSet.at(i).getAnimal()->getId() << " Client: " << optimalSet.at(i).getClient()->getDatabaseId();
    //}
    //display results
>>>>>>> master
}




<<<<<<< HEAD
=======




>>>>>>> master
