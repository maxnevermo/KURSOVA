/********************************************************************************
** Form generated from reading UI file 'donorstable.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DONORSTABLE_H
#define UI_DONORSTABLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_donorsTable
{
public:
    QAction *actionExit;
    QAction *actionWrite;
    QWidget *centralwidget;
    QTableWidget *donRepTable;
    QPushButton *universalButton;
    QPushButton *generalButton;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *donorsTable)
    {
        if (donorsTable->objectName().isEmpty())
            donorsTable->setObjectName("donorsTable");
        donorsTable->resize(540, 394);
        donorsTable->setStyleSheet(QString::fromUtf8("QWidget {\n"
"background-color: rgb(142, 157, 204);\n"
"}"));
        actionExit = new QAction(donorsTable);
        actionExit->setObjectName("actionExit");
        actionWrite = new QAction(donorsTable);
        actionWrite->setObjectName("actionWrite");
        centralwidget = new QWidget(donorsTable);
        centralwidget->setObjectName("centralwidget");
        donRepTable = new QTableWidget(centralwidget);
        donRepTable->setObjectName("donRepTable");
        donRepTable->setGeometry(QRect(40, 120, 460, 230));
        donRepTable->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #D9DBF1;\n"
"    color: #000000;\n"
"    border-radius: 20px;\n"
"    font-family: 'Gogh';\n"
"    font-weight: 500;\n"
"    font-size: 15px;\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"    border-right: 0.5px solid #E5E5E5;\n"
"    background-color: #A9B9E3;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #A9B9E3;\n"
"    border: none;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    border-right: 1px solid #8E9DCC;\n"
"}"));
        universalButton = new QPushButton(centralwidget);
        universalButton->setObjectName("universalButton");
        universalButton->setGeometry(QRect(10, 10, 220, 30));
        universalButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #C6CCE8;\n"
"    color: #000000;\n"
"    border-radius: 0.5em;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"	font-size: 15px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #A9B9E3;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"}"));
        generalButton = new QPushButton(centralwidget);
        generalButton->setObjectName("generalButton");
        generalButton->setGeometry(QRect(260, 10, 270, 30));
        generalButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #C6CCE8;\n"
"    color: #000000;\n"
"    border-radius: 0.5em;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"	font-size: 15px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #A9B9E3;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 50, 340, 60));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../images/DonorsRec.png")));
        donorsTable->setCentralWidget(centralwidget);
        menubar = new QMenuBar(donorsTable);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 540, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        donorsTable->setMenuBar(menubar);
        statusbar = new QStatusBar(donorsTable);
        statusbar->setObjectName("statusbar");
        donorsTable->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionWrite);
        menuFile->addAction(actionExit);

        retranslateUi(donorsTable);

        QMetaObject::connectSlotsByName(donorsTable);
    } // setupUi

    void retranslateUi(QMainWindow *donorsTable)
    {
        donorsTable->setWindowTitle(QCoreApplication::translate("donorsTable", "MainWindow", nullptr));
        actionExit->setText(QCoreApplication::translate("donorsTable", "Exit", nullptr));
        actionWrite->setText(QCoreApplication::translate("donorsTable", "Write", nullptr));
        universalButton->setText(QCoreApplication::translate("donorsTable", "Universal donors | recipients", nullptr));
        generalButton->setText(QCoreApplication::translate("donorsTable", "General table of donors | recipients", nullptr));
        label->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("donorsTable", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class donorsTable: public Ui_donorsTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DONORSTABLE_H
