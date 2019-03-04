/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *login_frame;
    QLabel *login_title;
    QPushButton *login_button;
    QLineEdit *password_input;
    QLineEdit *username_input;
    QLabel *password_label;
    QLabel *username_label;
    QFrame *client_frame;
    QLabel *Logo;
    QPushButton *view_animals;
    QFrame *table_frame_3;
    QTableWidget *view_table_2;
    QFrame *staff_frame_2;
    QLabel *staff_title_2;
    QPushButton *view_button_2;
    QLabel *input_label_01;
    QLabel *input_label_02;
    QLabel *input_label_03;
    QLabel *input_label_04;
    QLabel *input_label_05;
    QLabel *input_label_06;
    QLabel *input_label_07;
    QLineEdit *input_01;
    QLineEdit *input_02;
    QLineEdit *input_03;
    QLineEdit *input_04;
    QLineEdit *input_05;
    QLineEdit *input_06;
    QLineEdit *input_07;
    QPushButton *add_button_2;
    QPushButton *view_client_2;
    QPushButton *add_client_2;
    QPushButton *submit;
    QFrame *addAnimalFrame;
    QComboBox *aggressivenessCombo;
    QLabel *sleep;
    QLabel *hyperactivity;
    QLabel *noise;
    QLabel *aggressiveness;
    QComboBox *hyperactivity_combo;
    QComboBox *sleep_combo;
    QComboBox *noise_combo;
    QComboBox *space_combo;
    QLabel *hyperactivity_2;
    QLabel *aggressiveness_2;
    QComboBox *appetite_combo;
    QComboBox *outside_combo;
    QLabel *noise_2;
    QLabel *sleep_2;
    QComboBox *maintainance_combo;
    QComboBox *animal_combo;
    QLabel *noise_3;
    QComboBox *child_combo;
    QLabel *aggressiveness_3;
    QComboBox *excitibility_combo;
    QLabel *sleep_3;
    QLabel *hyperactivity_3;
    QComboBox *equipment_combo;
    QFrame *staff_frame;
    QLabel *staff_title;
    QPushButton *view_button;
    QPushButton *add_button;
    QFrame *table_frame;
    QTableWidget *view_table;
    QPushButton *view_client;
    QPushButton *add_client;
    QFrame *table_frame_2;
    QTableWidget *view_table_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1080, 810);
        MainWindow->setMinimumSize(QSize(1080, 810));
        MainWindow->setMaximumSize(QSize(1080, 810));
        MainWindow->setStyleSheet(QLatin1String("#centralWidget {\n"
"background-image: url(:/Images/Images/background.jpg);\n"
"background-position: center-right;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        centralWidget->setStyleSheet(QLatin1String("#staff_frame {\n"
"background-color: rgba(241, 241, 241, 217);\n"
"border-radius: 50px;\n"
"}\n"
"\n"
"#login_frame {\n"
"background-color: rgba(241, 241, 241, 217);\n"
"border-radius: 50px;\n"
"}\n"
"\n"
"#login_title{\n"
"font: 75 28pt \"FreeSerif\";\n"
"}\n"
"\n"
"#staff_title{\n"
"font: 75 28pt \"FreeSerif\";\n"
"}\n"
""));
        login_frame = new QFrame(centralWidget);
        login_frame->setObjectName(QStringLiteral("login_frame"));
        login_frame->setGeometry(QRect(920, -310, 600, 400));
        login_frame->setAutoFillBackground(false);
        login_frame->setStyleSheet(QStringLiteral(""));
        login_frame->setFrameShape(QFrame::StyledPanel);
        login_frame->setFrameShadow(QFrame::Raised);
        login_title = new QLabel(login_frame);
        login_title->setObjectName(QStringLiteral("login_title"));
        login_title->setGeometry(QRect(225, 20, 150, 70));
        login_title->setLayoutDirection(Qt::LeftToRight);
        login_title->setAlignment(Qt::AlignCenter);
        login_button = new QPushButton(login_frame);
        login_button->setObjectName(QStringLiteral("login_button"));
        login_button->setGeometry(QRect(215, 270, 165, 31));
        password_input = new QLineEdit(login_frame);
        password_input->setObjectName(QStringLiteral("password_input"));
        password_input->setGeometry(QRect(225, 210, 150, 25));
        password_input->setStyleSheet(QStringLiteral(""));
        username_input = new QLineEdit(login_frame);
        username_input->setObjectName(QStringLiteral("username_input"));
        username_input->setGeometry(QRect(225, 125, 150, 25));
        password_label = new QLabel(login_frame);
        password_label->setObjectName(QStringLiteral("password_label"));
        password_label->setGeometry(QRect(145, 210, 80, 30));
        username_label = new QLabel(login_frame);
        username_label->setObjectName(QStringLiteral("username_label"));
        username_label->setGeometry(QRect(145, 120, 80, 30));
        client_frame = new QFrame(centralWidget);
        client_frame->setObjectName(QStringLiteral("client_frame"));
        client_frame->setGeometry(QRect(40, 100, 980, 600));
        client_frame->setStyleSheet(QLatin1String("background-color: rgb(32,34,37);\n"
"border-radius: 60px;\n"
""));
        client_frame->setFrameShape(QFrame::StyledPanel);
        client_frame->setFrameShadow(QFrame::Raised);
        Logo = new QLabel(client_frame);
        Logo->setObjectName(QStringLiteral("Logo"));
        Logo->setGeometry(QRect(10, 60, 100, 163));
        Logo->setPixmap(QPixmap(QString::fromUtf8("Images/duck.jpg")));
        view_animals = new QPushButton(client_frame);
        view_animals->setObjectName(QStringLiteral("view_animals"));
        view_animals->setGeometry(QRect(10, 250, 110, 110));
        view_animals->setStyleSheet(QLatin1String("background-color: rbg(54,57,65);\n"
"border-radius: 20px;\n"
"border: 1px solid white;\n"
"color: rgb(255,255,255);"));
        table_frame_3 = new QFrame(client_frame);
        table_frame_3->setObjectName(QStringLiteral("table_frame_3"));
        table_frame_3->setGeometry(QRect(140, 50, 770, 490));
        table_frame_3->setFrameShape(QFrame::StyledPanel);
        table_frame_3->setFrameShadow(QFrame::Raised);
        view_table_2 = new QTableWidget(table_frame_3);
        if (view_table_2->columnCount() < 19)
            view_table_2->setColumnCount(19);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        view_table_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        view_table_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        view_table_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        view_table_2->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        view_table_2->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        view_table_2->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        view_table_2->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        view_table_2->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        view_table_2->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        view_table_2->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        view_table_2->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        view_table_2->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        view_table_2->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        view_table_2->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        view_table_2->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        view_table_2->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        view_table_2->setHorizontalHeaderItem(16, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        view_table_2->setHorizontalHeaderItem(17, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        view_table_2->setHorizontalHeaderItem(18, __qtablewidgetitem18);
        view_table_2->setObjectName(QStringLiteral("view_table_2"));
        view_table_2->setGeometry(QRect(0, 0, 770, 490));
        view_table_2->setStyleSheet(QLatin1String("background-color: rgb(255,255,255);\n"
"border-radius: 0px;\n"
"color: rgb(0, 0, 0);"));
        view_table_2->horizontalHeader()->setDefaultSectionSize(120);
        staff_frame_2 = new QFrame(centralWidget);
        staff_frame_2->setObjectName(QStringLiteral("staff_frame_2"));
        staff_frame_2->setGeometry(QRect(-30, -520, 920, 600));
        staff_frame_2->setStyleSheet(QLatin1String("color: rgb(255,255,255);\n"
"background-color: rgb(32,34,37);\n"
""));
        staff_frame_2->setFrameShape(QFrame::StyledPanel);
        staff_frame_2->setFrameShadow(QFrame::Raised);
        staff_title_2 = new QLabel(staff_frame_2);
        staff_title_2->setObjectName(QStringLiteral("staff_title_2"));
        staff_title_2->setGeometry(QRect(330, -50, 441, 171));
        view_button_2 = new QPushButton(staff_frame_2);
        view_button_2->setObjectName(QStringLiteral("view_button_2"));
        view_button_2->setGeometry(QRect(10, 60, 110, 110));
        view_button_2->setCursor(QCursor(Qt::PointingHandCursor));
        view_button_2->setStyleSheet(QLatin1String("background-color: rbg(54,57,65);\n"
"border-radius: 20px;\n"
"border: 1px solid white;\n"
"color: rgb(255,255,255);"));
        input_label_01 = new QLabel(staff_frame_2);
        input_label_01->setObjectName(QStringLiteral("input_label_01"));
        input_label_01->setGeometry(QRect(200, 70, 64, 17));
        input_label_02 = new QLabel(staff_frame_2);
        input_label_02->setObjectName(QStringLiteral("input_label_02"));
        input_label_02->setGeometry(QRect(200, 110, 101, 17));
        input_label_03 = new QLabel(staff_frame_2);
        input_label_03->setObjectName(QStringLiteral("input_label_03"));
        input_label_03->setGeometry(QRect(510, 110, 91, 17));
        input_label_04 = new QLabel(staff_frame_2);
        input_label_04->setObjectName(QStringLiteral("input_label_04"));
        input_label_04->setGeometry(QRect(200, 160, 101, 17));
        input_label_05 = new QLabel(staff_frame_2);
        input_label_05->setObjectName(QStringLiteral("input_label_05"));
        input_label_05->setGeometry(QRect(510, 160, 91, 17));
        input_label_06 = new QLabel(staff_frame_2);
        input_label_06->setObjectName(QStringLiteral("input_label_06"));
        input_label_06->setGeometry(QRect(200, 210, 101, 17));
        input_label_07 = new QLabel(staff_frame_2);
        input_label_07->setObjectName(QStringLiteral("input_label_07"));
        input_label_07->setGeometry(QRect(510, 210, 91, 17));
        input_01 = new QLineEdit(staff_frame_2);
        input_01->setObjectName(QStringLiteral("input_01"));
        input_01->setGeometry(QRect(310, 70, 481, 21));
        input_02 = new QLineEdit(staff_frame_2);
        input_02->setObjectName(QStringLiteral("input_02"));
        input_02->setGeometry(QRect(310, 110, 191, 21));
        input_03 = new QLineEdit(staff_frame_2);
        input_03->setObjectName(QStringLiteral("input_03"));
        input_03->setGeometry(QRect(600, 110, 191, 21));
        input_04 = new QLineEdit(staff_frame_2);
        input_04->setObjectName(QStringLiteral("input_04"));
        input_04->setGeometry(QRect(310, 160, 191, 21));
        input_05 = new QLineEdit(staff_frame_2);
        input_05->setObjectName(QStringLiteral("input_05"));
        input_05->setGeometry(QRect(600, 160, 191, 21));
        input_06 = new QLineEdit(staff_frame_2);
        input_06->setObjectName(QStringLiteral("input_06"));
        input_06->setGeometry(QRect(310, 210, 191, 21));
        input_07 = new QLineEdit(staff_frame_2);
        input_07->setObjectName(QStringLiteral("input_07"));
        input_07->setGeometry(QRect(600, 210, 191, 21));
        add_button_2 = new QPushButton(staff_frame_2);
        add_button_2->setObjectName(QStringLiteral("add_button_2"));
        add_button_2->setGeometry(QRect(10, 300, 110, 110));
        add_button_2->setStyleSheet(QLatin1String("background-color: rbg(54,57,65);\n"
"border-radius: 20px;\n"
"border: 1px solid white;\n"
"color: rgb(255,255,255);"));
        view_client_2 = new QPushButton(staff_frame_2);
        view_client_2->setObjectName(QStringLiteral("view_client_2"));
        view_client_2->setGeometry(QRect(10, 180, 110, 110));
        view_client_2->setStyleSheet(QLatin1String("background-color: rbg(54,57,65);\n"
"border-radius: 20px;\n"
"border: 1px solid white;\n"
"color: rgb(255,255,255);"));
        add_client_2 = new QPushButton(staff_frame_2);
        add_client_2->setObjectName(QStringLiteral("add_client_2"));
        add_client_2->setGeometry(QRect(10, 420, 110, 110));
        add_client_2->setStyleSheet(QLatin1String("background-color: rbg(54,57,65);\n"
"border-radius: 20px;\n"
"border: 1px solid white;\n"
"color: rgb(255,255,255);"));
        submit = new QPushButton(staff_frame_2);
        submit->setObjectName(QStringLiteral("submit"));
        submit->setGeometry(QRect(800, 100, 110, 110));
        submit->setStyleSheet(QLatin1String("background-color: rbg(54,57,65);\n"
"border-radius: 20px;\n"
"border: 1px solid white;\n"
"color: rgb(255,255,255);"));
        addAnimalFrame = new QFrame(staff_frame_2);
        addAnimalFrame->setObjectName(QStringLiteral("addAnimalFrame"));
        addAnimalFrame->setGeometry(QRect(190, 252, 641, 300));
        addAnimalFrame->setFrameShape(QFrame::StyledPanel);
        addAnimalFrame->setFrameShadow(QFrame::Raised);
        aggressivenessCombo = new QComboBox(addAnimalFrame);
        aggressivenessCombo->setObjectName(QStringLiteral("aggressivenessCombo"));
        aggressivenessCombo->setGeometry(QRect(120, 0, 201, 32));
        sleep = new QLabel(addAnimalFrame);
        sleep->setObjectName(QStringLiteral("sleep"));
        sleep->setGeometry(QRect(10, 75, 101, 20));
        hyperactivity = new QLabel(addAnimalFrame);
        hyperactivity->setObjectName(QStringLiteral("hyperactivity"));
        hyperactivity->setGeometry(QRect(10, 40, 101, 20));
        noise = new QLabel(addAnimalFrame);
        noise->setObjectName(QStringLiteral("noise"));
        noise->setGeometry(QRect(10, 110, 121, 20));
        aggressiveness = new QLabel(addAnimalFrame);
        aggressiveness->setObjectName(QStringLiteral("aggressiveness"));
        aggressiveness->setGeometry(QRect(10, 5, 101, 20));
        hyperactivity_combo = new QComboBox(addAnimalFrame);
        hyperactivity_combo->setObjectName(QStringLiteral("hyperactivity_combo"));
        hyperactivity_combo->setGeometry(QRect(120, 35, 201, 32));
        sleep_combo = new QComboBox(addAnimalFrame);
        sleep_combo->setObjectName(QStringLiteral("sleep_combo"));
        sleep_combo->setGeometry(QRect(120, 70, 201, 32));
        noise_combo = new QComboBox(addAnimalFrame);
        noise_combo->setObjectName(QStringLiteral("noise_combo"));
        noise_combo->setGeometry(QRect(120, 105, 201, 32));
        noise_combo->setInsertPolicy(QComboBox::InsertAtBottom);
        space_combo = new QComboBox(addAnimalFrame);
        space_combo->setObjectName(QStringLiteral("space_combo"));
        space_combo->setGeometry(QRect(210, 240, 201, 32));
        space_combo->setInsertPolicy(QComboBox::InsertAtBottom);
        hyperactivity_2 = new QLabel(addAnimalFrame);
        hyperactivity_2->setObjectName(QStringLiteral("hyperactivity_2"));
        hyperactivity_2->setGeometry(QRect(10, 175, 151, 20));
        aggressiveness_2 = new QLabel(addAnimalFrame);
        aggressiveness_2->setObjectName(QStringLiteral("aggressiveness_2"));
        aggressiveness_2->setGeometry(QRect(10, 140, 101, 20));
        appetite_combo = new QComboBox(addAnimalFrame);
        appetite_combo->setObjectName(QStringLiteral("appetite_combo"));
        appetite_combo->setGeometry(QRect(120, 135, 201, 32));
        outside_combo = new QComboBox(addAnimalFrame);
        outside_combo->setObjectName(QStringLiteral("outside_combo"));
        outside_combo->setGeometry(QRect(210, 205, 201, 32));
        noise_2 = new QLabel(addAnimalFrame);
        noise_2->setObjectName(QStringLiteral("noise_2"));
        noise_2->setGeometry(QRect(10, 245, 201, 20));
        sleep_2 = new QLabel(addAnimalFrame);
        sleep_2->setObjectName(QStringLiteral("sleep_2"));
        sleep_2->setGeometry(QRect(10, 210, 171, 20));
        maintainance_combo = new QComboBox(addAnimalFrame);
        maintainance_combo->setObjectName(QStringLiteral("maintainance_combo"));
        maintainance_combo->setGeometry(QRect(210, 170, 201, 32));
        animal_combo = new QComboBox(addAnimalFrame);
        animal_combo->setObjectName(QStringLiteral("animal_combo"));
        animal_combo->setGeometry(QRect(440, 35, 201, 32));
        noise_3 = new QLabel(addAnimalFrame);
        noise_3->setObjectName(QStringLiteral("noise_3"));
        noise_3->setGeometry(QRect(330, 110, 121, 20));
        child_combo = new QComboBox(addAnimalFrame);
        child_combo->setObjectName(QStringLiteral("child_combo"));
        child_combo->setGeometry(QRect(440, 0, 201, 32));
        aggressiveness_3 = new QLabel(addAnimalFrame);
        aggressiveness_3->setObjectName(QStringLiteral("aggressiveness_3"));
        aggressiveness_3->setGeometry(QRect(330, 5, 101, 20));
        excitibility_combo = new QComboBox(addAnimalFrame);
        excitibility_combo->setObjectName(QStringLiteral("excitibility_combo"));
        excitibility_combo->setGeometry(QRect(440, 105, 201, 32));
        excitibility_combo->setInsertPolicy(QComboBox::InsertAtBottom);
        sleep_3 = new QLabel(addAnimalFrame);
        sleep_3->setObjectName(QStringLiteral("sleep_3"));
        sleep_3->setGeometry(QRect(330, 75, 111, 20));
        hyperactivity_3 = new QLabel(addAnimalFrame);
        hyperactivity_3->setObjectName(QStringLiteral("hyperactivity_3"));
        hyperactivity_3->setGeometry(QRect(330, 40, 101, 20));
        equipment_combo = new QComboBox(addAnimalFrame);
        equipment_combo->setObjectName(QStringLiteral("equipment_combo"));
        equipment_combo->setGeometry(QRect(440, 70, 201, 32));
        staff_frame = new QFrame(centralWidget);
        staff_frame->setObjectName(QStringLiteral("staff_frame"));
        staff_frame->setGeometry(QRect(30, 700, 920, 600));
        staff_frame->setStyleSheet(QLatin1String("color: rgb(255,255,255);\n"
"background-color: rgb(32,34,37);"));
        staff_frame->setFrameShape(QFrame::StyledPanel);
        staff_frame->setFrameShadow(QFrame::Raised);
        staff_title = new QLabel(staff_frame);
        staff_title->setObjectName(QStringLiteral("staff_title"));
        staff_title->setGeometry(QRect(330, 0, 441, 171));
        view_button = new QPushButton(staff_frame);
        view_button->setObjectName(QStringLiteral("view_button"));
        view_button->setGeometry(QRect(10, 60, 110, 110));
        view_button->setCursor(QCursor(Qt::PointingHandCursor));
        view_button->setStyleSheet(QLatin1String("background-color: rbg(54,57,65);\n"
"border-radius: 20px;\n"
"border: 1px solid white;\n"
"color: rgb(255,255,255);"));
        add_button = new QPushButton(staff_frame);
        add_button->setObjectName(QStringLiteral("add_button"));
        add_button->setGeometry(QRect(10, 300, 110, 110));
        add_button->setStyleSheet(QLatin1String("background-color: rbg(54,57,65);\n"
"border-radius: 20px;\n"
"border: 1px solid white;\n"
"color: rgb(255,255,255);"));
        table_frame = new QFrame(staff_frame);
        table_frame->setObjectName(QStringLiteral("table_frame"));
        table_frame->setGeometry(QRect(140, 330, 770, 490));
        table_frame->setFrameShape(QFrame::StyledPanel);
        table_frame->setFrameShadow(QFrame::Raised);
        view_table = new QTableWidget(table_frame);
        if (view_table->columnCount() < 19)
            view_table->setColumnCount(19);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        view_table->setHorizontalHeaderItem(0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        view_table->setHorizontalHeaderItem(1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        view_table->setHorizontalHeaderItem(2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        view_table->setHorizontalHeaderItem(3, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        view_table->setHorizontalHeaderItem(4, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        view_table->setHorizontalHeaderItem(5, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        view_table->setHorizontalHeaderItem(6, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        view_table->setHorizontalHeaderItem(7, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        view_table->setHorizontalHeaderItem(8, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        view_table->setHorizontalHeaderItem(9, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        view_table->setHorizontalHeaderItem(10, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        view_table->setHorizontalHeaderItem(11, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        view_table->setHorizontalHeaderItem(12, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        view_table->setHorizontalHeaderItem(13, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        view_table->setHorizontalHeaderItem(14, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        view_table->setHorizontalHeaderItem(15, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        view_table->setHorizontalHeaderItem(16, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        view_table->setHorizontalHeaderItem(17, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        view_table->setHorizontalHeaderItem(18, __qtablewidgetitem37);
        view_table->setObjectName(QStringLiteral("view_table"));
        view_table->setGeometry(QRect(0, 0, 770, 490));
        view_table->setStyleSheet(QLatin1String("background-color: rgb(255,255,255);\n"
"border-radius: 0px;\n"
"color: rgb(0, 0, 0);"));
        view_table->horizontalHeader()->setDefaultSectionSize(120);
        view_client = new QPushButton(staff_frame);
        view_client->setObjectName(QStringLiteral("view_client"));
        view_client->setGeometry(QRect(10, 180, 110, 110));
        view_client->setStyleSheet(QLatin1String("background-color: rbg(54,57,65);\n"
"border-radius: 20px;\n"
"border: 1px solid white;\n"
"color: rgb(255,255,255);"));
        add_client = new QPushButton(staff_frame);
        add_client->setObjectName(QStringLiteral("add_client"));
        add_client->setGeometry(QRect(10, 420, 110, 110));
        add_client->setStyleSheet(QLatin1String("background-color: rbg(54,57,65);\n"
"border-radius: 20px;\n"
"border: 1px solid white;\n"
"color: rgb(255,255,255);"));
        table_frame_2 = new QFrame(staff_frame);
        table_frame_2->setObjectName(QStringLiteral("table_frame_2"));
        table_frame_2->setGeometry(QRect(290, 130, 770, 490));
        table_frame_2->setFrameShape(QFrame::StyledPanel);
        table_frame_2->setFrameShadow(QFrame::Raised);
        view_table_3 = new QTableWidget(table_frame_2);
        if (view_table_3->columnCount() < 7)
            view_table_3->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        view_table_3->setHorizontalHeaderItem(0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        view_table_3->setHorizontalHeaderItem(1, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        view_table_3->setHorizontalHeaderItem(2, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        view_table_3->setHorizontalHeaderItem(3, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        view_table_3->setHorizontalHeaderItem(4, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        view_table_3->setHorizontalHeaderItem(5, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        view_table_3->setHorizontalHeaderItem(6, __qtablewidgetitem44);
        view_table_3->setObjectName(QStringLiteral("view_table_3"));
        view_table_3->setGeometry(QRect(0, 0, 770, 490));
        view_table_3->setStyleSheet(QLatin1String("background-color: rgb(255,255,255);\n"
"border-radius: 0px;\n"
"color: rgb(0, 0, 0);"));
        view_table_3->horizontalHeader()->setDefaultSectionSize(110);
        MainWindow->setCentralWidget(centralWidget);
        QWidget::setTabOrder(username_input, password_input);
        QWidget::setTabOrder(password_input, login_button);
        QWidget::setTabOrder(login_button, view_button);
        QWidget::setTabOrder(view_button, view_table);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        login_title->setText(QApplication::translate("MainWindow", "cuACS", Q_NULLPTR));
        login_button->setText(QApplication::translate("MainWindow", "Login", Q_NULLPTR));
        password_label->setText(QApplication::translate("MainWindow", "Password:", Q_NULLPTR));
        username_label->setText(QApplication::translate("MainWindow", "Username:", Q_NULLPTR));
        Logo->setText(QString());
        view_animals->setText(QApplication::translate("MainWindow", "View Animals", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = view_table_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = view_table_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Gender", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = view_table_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Age", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = view_table_2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Species", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = view_table_2->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Breed", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = view_table_2->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Hair Type", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = view_table_2->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Hair Colour", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = view_table_2->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Aggressiveness", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = view_table_2->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Hyperactivity", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = view_table_2->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Sleep Schedule", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = view_table_2->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Noise Production", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = view_table_2->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Appetite", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = view_table_2->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Maintainence Req.", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = view_table_2->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "Outdoor Needs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = view_table_2->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "Space Required", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = view_table_2->horizontalHeaderItem(15);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "Equipment Needed", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = view_table_2->horizontalHeaderItem(16);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "Child Friendly", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = view_table_2->horizontalHeaderItem(17);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "Animal Friendly", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = view_table_2->horizontalHeaderItem(18);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "Excitability", Q_NULLPTR));
        staff_title_2->setText(QApplication::translate("MainWindow", "Add Form", Q_NULLPTR));
        view_button_2->setText(QApplication::translate("MainWindow", "View Animals", Q_NULLPTR));
        input_label_01->setText(QApplication::translate("MainWindow", "Name:", Q_NULLPTR));
        input_label_02->setText(QApplication::translate("MainWindow", "Gender:", Q_NULLPTR));
        input_label_03->setText(QApplication::translate("MainWindow", "Age:", Q_NULLPTR));
        input_label_04->setText(QApplication::translate("MainWindow", "Species:", Q_NULLPTR));
        input_label_05->setText(QApplication::translate("MainWindow", "Breed:", Q_NULLPTR));
        input_label_06->setText(QApplication::translate("MainWindow", "Hair Type:", Q_NULLPTR));
        input_label_07->setText(QApplication::translate("MainWindow", "Hair Colour:", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        input_01->setAccessibleName(QApplication::translate("MainWindow", "nameInput", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        add_button_2->setText(QApplication::translate("MainWindow", "Add Animal", Q_NULLPTR));
        view_client_2->setText(QApplication::translate("MainWindow", "View Clients", Q_NULLPTR));
        add_client_2->setText(QApplication::translate("MainWindow", "Add Client", Q_NULLPTR));
        submit->setText(QApplication::translate("MainWindow", "Submit", Q_NULLPTR));
        aggressivenessCombo->clear();
        aggressivenessCombo->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "Submissive", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Slighty Submissive", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Slighty Aggressive", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Aggressive", Q_NULLPTR)
        );
        sleep->setText(QApplication::translate("MainWindow", "Sleep Schedule:", Q_NULLPTR));
        hyperactivity->setText(QApplication::translate("MainWindow", "Hyperactivity:", Q_NULLPTR));
        noise->setText(QApplication::translate("MainWindow", "Noise Production:", Q_NULLPTR));
        aggressiveness->setText(QApplication::translate("MainWindow", "Aggressiveness:", Q_NULLPTR));
        hyperactivity_combo->clear();
        hyperactivity_combo->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "Calm", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Slighty Calm", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Slighty Hyper", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Hyper", Q_NULLPTR)
        );
        sleep_combo->clear();
        sleep_combo->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "Nocturnal", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Flexible", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Normal", Q_NULLPTR)
        );
        noise_combo->clear();
        noise_combo->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2", Q_NULLPTR)
         << QApplication::translate("MainWindow", "3", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4", Q_NULLPTR)
         << QApplication::translate("MainWindow", "5", Q_NULLPTR)
         << QApplication::translate("MainWindow", "6", Q_NULLPTR)
         << QApplication::translate("MainWindow", "7", Q_NULLPTR)
         << QApplication::translate("MainWindow", "8", Q_NULLPTR)
         << QApplication::translate("MainWindow", "9", Q_NULLPTR)
         << QApplication::translate("MainWindow", "10", Q_NULLPTR)
        );
        space_combo->clear();
        space_combo->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "Minimal", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Moderate", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Above Average", Q_NULLPTR)
        );
        hyperactivity_2->setText(QApplication::translate("MainWindow", "Maintainance Required:", Q_NULLPTR));
        aggressiveness_2->setText(QApplication::translate("MainWindow", "Appetite:", Q_NULLPTR));
        appetite_combo->clear();
        appetite_combo->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "Minimal", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Average", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Above Average", Q_NULLPTR)
        );
        outside_combo->clear();
        outside_combo->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "Rarely", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Sometimes", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Daily", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Multiple Times Daily", Q_NULLPTR)
        );
        noise_2->setText(QApplication::translate("MainWindow", "Space Required for happy living:", Q_NULLPTR));
        sleep_2->setText(QApplication::translate("MainWindow", "Does it need to go outside:", Q_NULLPTR));
        maintainance_combo->clear();
        maintainance_combo->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "Minimal", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Below Average", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Above Average", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Special Care Needed", Q_NULLPTR)
        );
        animal_combo->clear();
        animal_combo->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "Not Animal Friendly", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Neutral", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Animal Friendly", Q_NULLPTR)
        );
        noise_3->setText(QApplication::translate("MainWindow", "Excitibility:", Q_NULLPTR));
        child_combo->clear();
        child_combo->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "No Children", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Neutral", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Child Friendly", Q_NULLPTR)
        );
        aggressiveness_3->setText(QApplication::translate("MainWindow", "Child Friendly:", Q_NULLPTR));
        excitibility_combo->clear();
        excitibility_combo->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "Easily Excited", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Moderate", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Not Easily Excited", Q_NULLPTR)
        );
        sleep_3->setText(QApplication::translate("MainWindow", "Equipment Needs:", Q_NULLPTR));
        hyperactivity_3->setText(QApplication::translate("MainWindow", "Animal Friendly:", Q_NULLPTR));
        equipment_combo->clear();
        equipment_combo->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "Minimal", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Some Equipment", Q_NULLPTR)
         << QApplication::translate("MainWindow", "More Than Average Equipment", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Above Average", Q_NULLPTR)
        );
        staff_title->setText(QApplication::translate("MainWindow", "Staff Admin Form", Q_NULLPTR));
        view_button->setText(QApplication::translate("MainWindow", "View Animals", Q_NULLPTR));
        add_button->setText(QApplication::translate("MainWindow", "Add Animal", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = view_table->horizontalHeaderItem(0);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = view_table->horizontalHeaderItem(1);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "Gender", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = view_table->horizontalHeaderItem(2);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "Age", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = view_table->horizontalHeaderItem(3);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "Species", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = view_table->horizontalHeaderItem(4);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "Breed", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = view_table->horizontalHeaderItem(5);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "Hair Type", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = view_table->horizontalHeaderItem(6);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "Hair Colour", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = view_table->horizontalHeaderItem(7);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "Aggressiveness", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem27 = view_table->horizontalHeaderItem(8);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "Hyperactivity", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem28 = view_table->horizontalHeaderItem(9);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "Sleep Schedule", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem29 = view_table->horizontalHeaderItem(10);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "Noise Production", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem30 = view_table->horizontalHeaderItem(11);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "Appetite", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem31 = view_table->horizontalHeaderItem(12);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "Maintainence Req.", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem32 = view_table->horizontalHeaderItem(13);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "Outdoor Needs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem33 = view_table->horizontalHeaderItem(14);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "Space Required", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem34 = view_table->horizontalHeaderItem(15);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "Equipment Needed", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem35 = view_table->horizontalHeaderItem(16);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWindow", "Child Friendly", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem36 = view_table->horizontalHeaderItem(17);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWindow", "Animal Friendly", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem37 = view_table->horizontalHeaderItem(18);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWindow", "Excitability", Q_NULLPTR));
        view_client->setText(QApplication::translate("MainWindow", "View Clients", Q_NULLPTR));
        add_client->setText(QApplication::translate("MainWindow", "Add Client", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem38 = view_table_3->horizontalHeaderItem(0);
        ___qtablewidgetitem38->setText(QApplication::translate("MainWindow", "Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem39 = view_table_3->horizontalHeaderItem(1);
        ___qtablewidgetitem39->setText(QApplication::translate("MainWindow", "Username", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem40 = view_table_3->horizontalHeaderItem(2);
        ___qtablewidgetitem40->setText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem41 = view_table_3->horizontalHeaderItem(3);
        ___qtablewidgetitem41->setText(QApplication::translate("MainWindow", "Phone Number", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem42 = view_table_3->horizontalHeaderItem(4);
        ___qtablewidgetitem42->setText(QApplication::translate("MainWindow", "Address", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem43 = view_table_3->horizontalHeaderItem(5);
        ___qtablewidgetitem43->setText(QApplication::translate("MainWindow", "Postal Code", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem44 = view_table_3->horizontalHeaderItem(6);
        ___qtablewidgetitem44->setText(QApplication::translate("MainWindow", "Province", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
