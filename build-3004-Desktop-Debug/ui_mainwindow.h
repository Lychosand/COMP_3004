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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *centerFrame;
    QLabel *centerTitle;
    QTableWidget *animalTable;
    QPushButton *animalViewer;

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
        centralWidget->setStyleSheet(QStringLiteral(""));
        centerFrame = new QFrame(centralWidget);
        centerFrame->setObjectName(QStringLiteral("centerFrame"));
        centerFrame->setGeometry(QRect(90, 190, 921, 521));
        centerFrame->setStyleSheet(QLatin1String("#centerFrame {\n"
"background-color: rgba(241, 241, 241, 217);\n"
"border-radius: 50px;\n"
"}\n"
"\n"
"#centerTitle{\n"
"font: 75 28pt \"FreeSerif\";\n"
"}"));
        centerFrame->setFrameShape(QFrame::StyledPanel);
        centerFrame->setFrameShadow(QFrame::Raised);
        centerTitle = new QLabel(centerFrame);
        centerTitle->setObjectName(QStringLiteral("centerTitle"));
        centerTitle->setGeometry(QRect(300, -50, 441, 171));
        animalTable = new QTableWidget(centerFrame);
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
        animalViewer = new QPushButton(centerFrame);
        animalViewer->setObjectName(QStringLiteral("animalViewer"));
        animalViewer->setGeometry(QRect(350, 224, 251, 31));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        centerTitle->setText(QApplication::translate("MainWindow", "cuACS Animal Viewer", Q_NULLPTR));
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
