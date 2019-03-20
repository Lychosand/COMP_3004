/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
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
    QFrame *staff_frame;
    QLabel *staff_title;
    QTableWidget *animal_table;
    QPushButton *view_button;
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
    QPushButton *add_button;
    QComboBox *staff_combo;
    QFrame *login_frame;
    QLabel *login_title;
    QPushButton *login_button;
    QLineEdit *password_input;
    QLineEdit *username_input;
    QLabel *password_label;
    QLabel *username_label;

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
        staff_frame = new QFrame(centralWidget);
        staff_frame->setObjectName(QStringLiteral("staff_frame"));
        staff_frame->setGeometry(QRect(90, 160, 921, 521));
        staff_frame->setStyleSheet(QLatin1String("\n"
"\n"
"#centerTitle{\n"
"font: 75 28pt \"FreeSerif\";\n"
"}"));
        staff_frame->setFrameShape(QFrame::StyledPanel);
        staff_frame->setFrameShadow(QFrame::Raised);
        staff_title = new QLabel(staff_frame);
        staff_title->setObjectName(QStringLiteral("staff_title"));
        staff_title->setGeometry(QRect(330, -50, 441, 171));
        animal_table = new QTableWidget(staff_frame);
        if (animal_table->columnCount() < 7)
            animal_table->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        animal_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        animal_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        animal_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        animal_table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        animal_table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        animal_table->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        animal_table->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        animal_table->setObjectName(QStringLiteral("animal_table"));
        animal_table->setGeometry(QRect(120, 280, 701, 231));
        view_button = new QPushButton(staff_frame);
        view_button->setObjectName(QStringLiteral("view_button"));
        view_button->setGeometry(QRect(70, 150, 111, 21));
        input_label_01 = new QLabel(staff_frame);
        input_label_01->setObjectName(QStringLiteral("input_label_01"));
        input_label_01->setGeometry(QRect(200, 70, 64, 17));
        input_label_02 = new QLabel(staff_frame);
        input_label_02->setObjectName(QStringLiteral("input_label_02"));
        input_label_02->setGeometry(QRect(200, 110, 101, 17));
        input_label_03 = new QLabel(staff_frame);
        input_label_03->setObjectName(QStringLiteral("input_label_03"));
        input_label_03->setGeometry(QRect(510, 110, 91, 17));
        input_label_04 = new QLabel(staff_frame);
        input_label_04->setObjectName(QStringLiteral("input_label_04"));
        input_label_04->setGeometry(QRect(200, 160, 101, 17));
        input_label_05 = new QLabel(staff_frame);
        input_label_05->setObjectName(QStringLiteral("input_label_05"));
        input_label_05->setGeometry(QRect(510, 160, 91, 17));
        input_label_06 = new QLabel(staff_frame);
        input_label_06->setObjectName(QStringLiteral("input_label_06"));
        input_label_06->setGeometry(QRect(200, 210, 101, 17));
        input_label_07 = new QLabel(staff_frame);
        input_label_07->setObjectName(QStringLiteral("input_label_07"));
        input_label_07->setGeometry(QRect(510, 210, 91, 17));
        input_01 = new QLineEdit(staff_frame);
        input_01->setObjectName(QStringLiteral("input_01"));
        input_01->setGeometry(QRect(310, 70, 331, 21));
        input_02 = new QLineEdit(staff_frame);
        input_02->setObjectName(QStringLiteral("input_02"));
        input_02->setGeometry(QRect(310, 110, 191, 21));
        input_03 = new QLineEdit(staff_frame);
        input_03->setObjectName(QStringLiteral("input_03"));
        input_03->setGeometry(QRect(600, 110, 191, 21));
        input_04 = new QLineEdit(staff_frame);
        input_04->setObjectName(QStringLiteral("input_04"));
        input_04->setGeometry(QRect(310, 160, 191, 21));
        input_05 = new QLineEdit(staff_frame);
        input_05->setObjectName(QStringLiteral("input_05"));
        input_05->setGeometry(QRect(600, 160, 191, 21));
        input_06 = new QLineEdit(staff_frame);
        input_06->setObjectName(QStringLiteral("input_06"));
        input_06->setGeometry(QRect(310, 210, 191, 21));
        input_07 = new QLineEdit(staff_frame);
        input_07->setObjectName(QStringLiteral("input_07"));
        input_07->setGeometry(QRect(600, 210, 191, 21));
        add_button = new QPushButton(staff_frame);
        add_button->setObjectName(QStringLiteral("add_button"));
        add_button->setGeometry(QRect(70, 110, 111, 21));
        staff_combo = new QComboBox(staff_frame);
        staff_combo->setObjectName(QStringLiteral("staff_combo"));
        staff_combo->setGeometry(QRect(70, 70, 111, 25));
        login_frame = new QFrame(centralWidget);
        login_frame->setObjectName(QStringLiteral("login_frame"));
        login_frame->setGeometry(QRect(820, -460, 921, 521));
        login_frame->setAutoFillBackground(false);
        login_frame->setStyleSheet(QStringLiteral(""));
        login_frame->setFrameShape(QFrame::StyledPanel);
        login_frame->setFrameShadow(QFrame::Raised);
        login_title = new QLabel(login_frame);
        login_title->setObjectName(QStringLiteral("login_title"));
        login_title->setGeometry(QRect(310, -50, 441, 171));
        login_button = new QPushButton(login_frame);
        login_button->setObjectName(QStringLiteral("login_button"));
        login_button->setGeometry(QRect(320, 280, 251, 31));
        password_input = new QLineEdit(login_frame);
        password_input->setObjectName(QStringLiteral("password_input"));
        password_input->setGeometry(QRect(360, 220, 171, 25));
        password_input->setStyleSheet(QStringLiteral(""));
        username_input = new QLineEdit(login_frame);
        username_input->setObjectName(QStringLiteral("username_input"));
        username_input->setGeometry(QRect(360, 140, 171, 25));
        password_label = new QLabel(login_frame);
        password_label->setObjectName(QStringLiteral("password_label"));
        password_label->setGeometry(QRect(410, 190, 111, 31));
        username_label = new QLabel(login_frame);
        username_label->setObjectName(QStringLiteral("username_label"));
        username_label->setGeometry(QRect(410, 100, 191, 41));
        MainWindow->setCentralWidget(centralWidget);
        QWidget::setTabOrder(username_input, password_input);
        QWidget::setTabOrder(password_input, login_button);
        QWidget::setTabOrder(login_button, view_button);
        QWidget::setTabOrder(view_button, animal_table);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        staff_title->setText(QApplication::translate("MainWindow", "Staff Admin Form", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = animal_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = animal_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Gender", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = animal_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Age", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = animal_table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Species", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = animal_table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Breed", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = animal_table->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Hair Type", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = animal_table->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Hair Colour", Q_NULLPTR));
        view_button->setText(QApplication::translate("MainWindow", "View Animals", Q_NULLPTR));
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
        add_button->setText(QApplication::translate("MainWindow", "Add Animal", Q_NULLPTR));
        staff_combo->clear();
        staff_combo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Animals", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Clients", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        staff_combo->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        login_title->setText(QApplication::translate("MainWindow", "The cuACS System", Q_NULLPTR));
        login_button->setText(QApplication::translate("MainWindow", "Login", Q_NULLPTR));
        password_label->setText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
        username_label->setText(QApplication::translate("MainWindow", "Username", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
