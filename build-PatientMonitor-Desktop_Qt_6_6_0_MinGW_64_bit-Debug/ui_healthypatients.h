/********************************************************************************
** Form generated from reading UI file 'healthypatients.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEALTHYPATIENTS_H
#define UI_HEALTHYPATIENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_healthyPatients
{
public:
    QWidget *centralwidget;
    QTableWidget *healthyPatientsTable;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *healthyPatients)
    {
        if (healthyPatients->objectName().isEmpty())
            healthyPatients->setObjectName("healthyPatients");
        healthyPatients->resize(590, 370);
        healthyPatients->setStyleSheet(QString::fromUtf8("QWidget {\n"
"background-color: rgb(142, 157, 204);\n"
"}"));
        centralwidget = new QWidget(healthyPatients);
        centralwidget->setObjectName("centralwidget");
        healthyPatientsTable = new QTableWidget(centralwidget);
        healthyPatientsTable->setObjectName("healthyPatientsTable");
        healthyPatientsTable->setGeometry(QRect(5, 10, 580, 300));
        healthyPatientsTable->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
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
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #A9B9E3;\n"
"    border: none;\n"
"}\n"
"\n"
"QTableWidget::item:hover:selected {\n"
"    background-color: #A9B9E3;\n"
"    border-right: 0.5px solid #E5E5E5;\n"
"}"));
        healthyPatients->setCentralWidget(centralwidget);
        menubar = new QMenuBar(healthyPatients);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 590, 21));
        healthyPatients->setMenuBar(menubar);
        statusbar = new QStatusBar(healthyPatients);
        statusbar->setObjectName("statusbar");
        healthyPatients->setStatusBar(statusbar);

        retranslateUi(healthyPatients);

        QMetaObject::connectSlotsByName(healthyPatients);
    } // setupUi

    void retranslateUi(QMainWindow *healthyPatients)
    {
        healthyPatients->setWindowTitle(QCoreApplication::translate("healthyPatients", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class healthyPatients: public Ui_healthyPatients {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEALTHYPATIENTS_H
