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
    QTableWidget *animalTable;
    QPushButton *animalViewer;
    QLabel *nameLabel;
    QLabel *genderLabel;
    QLabel *ageLabel;
    QLabel *speciesLabel;
    QLabel *breedLabel;
    QLabel *hairTypeLabel;
    QLabel *hairColourLabel;
    QLineEdit *nameInput;
    QLineEdit *genderInput;
    QLineEdit *ageInput;
    QLineEdit *speciesInput;
    QLineEdit *breedInput;
    QLineEdit *hairTypeInput;
    QLineEdit *hairColourInput;
    QPushButton *addButton;
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
        staff_frame->setGeometry(QRect(0, 530, 921, 521));
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
        animalTable = new QTableWidget(staff_frame);
        if (animalTable->columnCount() < 7)
            animalTable->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        animalTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        animalTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        animalTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        animalTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        animalTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        animalTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        animalTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        animalTable->setObjectName(QStringLiteral("animalTable"));
        animalTable->setGeometry(QRect(70, 270, 801, 231));
        animalViewer = new QPushButton(staff_frame);
        animalViewer->setObjectName(QStringLiteral("animalViewer"));
        animalViewer->setGeometry(QRect(350, 224, 251, 31));
        nameLabel = new QLabel(staff_frame);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(90, 60, 64, 17));
        genderLabel = new QLabel(staff_frame);
        genderLabel->setObjectName(QStringLiteral("genderLabel"));
        genderLabel->setGeometry(QRect(90, 80, 64, 17));
        ageLabel = new QLabel(staff_frame);
        ageLabel->setObjectName(QStringLiteral("ageLabel"));
        ageLabel->setGeometry(QRect(340, 80, 64, 17));
        speciesLabel = new QLabel(staff_frame);
        speciesLabel->setObjectName(QStringLiteral("speciesLabel"));
        speciesLabel->setGeometry(QRect(90, 100, 64, 17));
        breedLabel = new QLabel(staff_frame);
        breedLabel->setObjectName(QStringLiteral("breedLabel"));
        breedLabel->setGeometry(QRect(90, 120, 64, 17));
        hairTypeLabel = new QLabel(staff_frame);
        hairTypeLabel->setObjectName(QStringLiteral("hairTypeLabel"));
        hairTypeLabel->setGeometry(QRect(90, 140, 71, 17));
        hairColourLabel = new QLabel(staff_frame);
        hairColourLabel->setObjectName(QStringLiteral("hairColourLabel"));
        hairColourLabel->setGeometry(QRect(90, 160, 81, 17));
        nameInput = new QLineEdit(staff_frame);
        nameInput->setObjectName(QStringLiteral("nameInput"));
        nameInput->setGeometry(QRect(170, 60, 331, 21));
        genderInput = new QLineEdit(staff_frame);
        genderInput->setObjectName(QStringLiteral("genderInput"));
        genderInput->setGeometry(QRect(170, 80, 161, 21));
        ageInput = new QLineEdit(staff_frame);
        ageInput->setObjectName(QStringLiteral("ageInput"));
        ageInput->setGeometry(QRect(380, 80, 121, 21));
        speciesInput = new QLineEdit(staff_frame);
        speciesInput->setObjectName(QStringLiteral("speciesInput"));
        speciesInput->setGeometry(QRect(170, 100, 191, 21));
        breedInput = new QLineEdit(staff_frame);
        breedInput->setObjectName(QStringLiteral("breedInput"));
        breedInput->setGeometry(QRect(170, 120, 191, 21));
        hairTypeInput = new QLineEdit(staff_frame);
        hairTypeInput->setObjectName(QStringLiteral("hairTypeInput"));
        hairTypeInput->setGeometry(QRect(170, 140, 191, 21));
        hairColourInput = new QLineEdit(staff_frame);
        hairColourInput->setObjectName(QStringLiteral("hairColourInput"));
        hairColourInput->setGeometry(QRect(170, 160, 191, 21));
        addButton = new QPushButton(staff_frame);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(420, 160, 83, 25));
        login_frame = new QFrame(centralWidget);
        login_frame->setObjectName(QStringLiteral("login_frame"));
        login_frame->setGeometry(QRect(0, 0, 921, 521));
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
        QWidget::setTabOrder(login_button, animalViewer);
        QWidget::setTabOrder(animalViewer, animalTable);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        staff_title->setText(QApplication::translate("MainWindow", "Staff Admin Form", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = animalTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = animalTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Gender", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = animalTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Age", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = animalTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Species", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = animalTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Breed", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = animalTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Hair Type", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = animalTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Hair Colour", Q_NULLPTR));
        animalViewer->setText(QApplication::translate("MainWindow", "View Current Animals", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("MainWindow", "Name:", Q_NULLPTR));
        genderLabel->setText(QApplication::translate("MainWindow", "Gender:", Q_NULLPTR));
        ageLabel->setText(QApplication::translate("MainWindow", "Age:", Q_NULLPTR));
        speciesLabel->setText(QApplication::translate("MainWindow", "Species:", Q_NULLPTR));
        breedLabel->setText(QApplication::translate("MainWindow", "Breed:", Q_NULLPTR));
        hairTypeLabel->setText(QApplication::translate("MainWindow", "Hair Type:", Q_NULLPTR));
        hairColourLabel->setText(QApplication::translate("MainWindow", "Hair Colour:", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        nameInput->setAccessibleName(QApplication::translate("MainWindow", "nameInput", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        addButton->setText(QApplication::translate("MainWindow", "Add Animal", Q_NULLPTR));
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
