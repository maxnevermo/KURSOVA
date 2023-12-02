/********************************************************************************
** Form generated from reading UI file 'patientmonitor.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTMONITOR_H
#define UI_PATIENTMONITOR_H

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

class Ui_PatientMonitor
{
public:
    QAction *actionCancel_action;
    QAction *actionExit;
    QAction *actionPrint;
    QWidget *centralwidget;
    QLabel *state;
    QPushButton *pulseSortButton;
    QLabel *logo;
    QLabel *rectangle;
    QTableWidget *patientTable;
    QPushButton *writeButton;
    QPushButton *bloodPressureSort;
    QPushButton *donorCheckButton;
    QPushButton *addButton;
    QPushButton *scanButton;
    QPushButton *agePulseCheckButton;
    QPushButton *normPressureCheckButton;
    QPushButton *bloodTypeGroupButton;
    QPushButton *scanTableButton;
    QPushButton *rhGroupHrSort;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PatientMonitor)
    {
        if (PatientMonitor->objectName().isEmpty())
            PatientMonitor->setObjectName("PatientMonitor");
        PatientMonitor->resize(990, 650);
        PatientMonitor->setStyleSheet(QString::fromUtf8("QWidget {\n"
"background-color: rgb(142, 157, 204);\n"
"}"));
        actionCancel_action = new QAction(PatientMonitor);
        actionCancel_action->setObjectName("actionCancel_action");
        actionExit = new QAction(PatientMonitor);
        actionExit->setObjectName("actionExit");
        actionPrint = new QAction(PatientMonitor);
        actionPrint->setObjectName("actionPrint");
        centralwidget = new QWidget(PatientMonitor);
        centralwidget->setObjectName("centralwidget");
        state = new QLabel(centralwidget);
        state->setObjectName("state");
        state->setGeometry(QRect(260, 10, 731, 61));
        state->setPixmap(QPixmap(QString::fromUtf8("C:/Users/maxnevermo/Desktop/course/git/KURSOVA/PatientMonitor/images/nav.png")));
        pulseSortButton = new QPushButton(centralwidget);
        pulseSortButton->setObjectName("pulseSortButton");
        pulseSortButton->setGeometry(QRect(20, 290, 230, 41));
        pulseSortButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #C6CCE8;\n"
"    color: #000000;\n"
"	border-radius: 0.5em;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"	font-size: 20px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A9B9E3;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"}\n"
""));
        logo = new QLabel(centralwidget);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(30, 530, 71, 51));
        logo->setStyleSheet(QString::fromUtf8("background-color: #D9DBF1;"));
        logo->setPixmap(QPixmap(QString::fromUtf8("C:/Users/maxnevermo/Desktop/course/git/KURSOVA/PatientMonitor/images/logo.png")));
        rectangle = new QLabel(centralwidget);
        rectangle->setObjectName("rectangle");
        rectangle->setGeometry(QRect(0, 0, 271, 601));
        rectangle->setPixmap(QPixmap(QString::fromUtf8("C:/Users/maxnevermo/Desktop/course/git/KURSOVA/PatientMonitor/images/menu.png")));
        patientTable = new QTableWidget(centralwidget);
        patientTable->setObjectName("patientTable");
        patientTable->setGeometry(QRect(270, 70, 711, 521));
        patientTable->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
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
        writeButton = new QPushButton(centralwidget);
        writeButton->setObjectName("writeButton");
        writeButton->setGeometry(QRect(180, 110, 70, 31));
        writeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #C6CCE8;\n"
"    color: #000000;\n"
"    border-radius: 0.5em;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"	font-size: 15px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A9B9E3;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"}\n"
""));
        bloodPressureSort = new QPushButton(centralwidget);
        bloodPressureSort->setObjectName("bloodPressureSort");
        bloodPressureSort->setGeometry(QRect(20, 170, 230, 41));
        bloodPressureSort->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #C6CCE8;\n"
"    color: #000000;\n"
"	border-radius: 0.5em;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"	font-size: 20px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A9B9E3;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"}\n"
""));
        donorCheckButton = new QPushButton(centralwidget);
        donorCheckButton->setObjectName("donorCheckButton");
        donorCheckButton->setGeometry(QRect(20, 350, 230, 41));
        donorCheckButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #C6CCE8;\n"
"    color: #000000;\n"
"	border-radius: 0.5em;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"	font-size: 20px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A9B9E3;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"}\n"
""));
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(100, 110, 70, 31));
        addButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #C6CCE8;\n"
"    color: #000000;\n"
"    border-radius: 0.5em;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"	font-size: 15px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A9B9E3;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"}\n"
""));
        scanButton = new QPushButton(centralwidget);
        scanButton->setObjectName("scanButton");
        scanButton->setGeometry(QRect(20, 110, 70, 31));
        scanButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #C6CCE8;\n"
"    color: #000000;\n"
"    border-radius: 0.5em;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"	font-size: 15px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A9B9E3;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"}\n"
""));
        agePulseCheckButton = new QPushButton(centralwidget);
        agePulseCheckButton->setObjectName("agePulseCheckButton");
        agePulseCheckButton->setGeometry(QRect(20, 410, 230, 40));
        agePulseCheckButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #C6CCE8;\n"
"    color: #000000;\n"
"	border-radius: 0.5em;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"	font-size: 20px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A9B9E3;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"}\n"
""));
        normPressureCheckButton = new QPushButton(centralwidget);
        normPressureCheckButton->setObjectName("normPressureCheckButton");
        normPressureCheckButton->setGeometry(QRect(20, 470, 230, 40));
        normPressureCheckButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #C6CCE8;\n"
"    color: #000000;\n"
"	border-radius: 0.5em;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"	font-size: 20px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A9B9E3;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"}"));
        bloodTypeGroupButton = new QPushButton(centralwidget);
        bloodTypeGroupButton->setObjectName("bloodTypeGroupButton");
        bloodTypeGroupButton->setGeometry(QRect(20, 230, 230, 41));
        bloodTypeGroupButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #C6CCE8;\n"
"    color: #000000;\n"
"	border-radius: 0.5em;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"	font-size: 20px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A9B9E3;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"}\n"
""));
        scanTableButton = new QPushButton(centralwidget);
        scanTableButton->setObjectName("scanTableButton");
        scanTableButton->setGeometry(QRect(520, 280, 250, 50));
        scanTableButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #C6CCE8;\n"
"color: #000000;\n"
"border-radius: 0.5em;\n"
"font-family: 'Gogh';\n"
"font-weight: 500;\n"
"font-size: 30px\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: #A9B9E3;\n"
"font-family: 'Gogh';\n"
"font-weight: 500;\n"
"font-size: 30px\n"
"}"));
        rhGroupHrSort = new QPushButton(centralwidget);
        rhGroupHrSort->setObjectName("rhGroupHrSort");
        rhGroupHrSort->setGeometry(QRect(20, 290, 230, 41));
        rhGroupHrSort->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #C6CCE8;\n"
"    color: #000000;\n"
"	border-radius: 0.5em;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"	font-size: 20px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A9B9E3;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"}\n"
""));
        PatientMonitor->setCentralWidget(centralwidget);
        state->raise();
        pulseSortButton->raise();
        rectangle->raise();
        patientTable->raise();
        writeButton->raise();
        bloodPressureSort->raise();
        donorCheckButton->raise();
        addButton->raise();
        scanButton->raise();
        agePulseCheckButton->raise();
        normPressureCheckButton->raise();
        bloodTypeGroupButton->raise();
        logo->raise();
        scanTableButton->raise();
        rhGroupHrSort->raise();
        menubar = new QMenuBar(PatientMonitor);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 990, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        PatientMonitor->setMenuBar(menubar);
        statusbar = new QStatusBar(PatientMonitor);
        statusbar->setObjectName("statusbar");
        PatientMonitor->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionCancel_action);
        menuFile->addAction(actionExit);

        retranslateUi(PatientMonitor);

        QMetaObject::connectSlotsByName(PatientMonitor);
    } // setupUi

    void retranslateUi(QMainWindow *PatientMonitor)
    {
        PatientMonitor->setWindowTitle(QCoreApplication::translate("PatientMonitor", "PatientMonitor", nullptr));
        actionCancel_action->setText(QCoreApplication::translate("PatientMonitor", "Cancel actions", nullptr));
        actionExit->setText(QCoreApplication::translate("PatientMonitor", "Exit", nullptr));
        actionPrint->setText(QCoreApplication::translate("PatientMonitor", "Print", nullptr));
        state->setText(QString());
        pulseSortButton->setText(QCoreApplication::translate("PatientMonitor", "Rh group | Pulse sort", nullptr));
        logo->setText(QString());
        rectangle->setText(QString());
        writeButton->setText(QCoreApplication::translate("PatientMonitor", "Write", nullptr));
        bloodPressureSort->setText(QCoreApplication::translate("PatientMonitor", "Sort by pressure", nullptr));
        donorCheckButton->setText(QCoreApplication::translate("PatientMonitor", "Check donors", nullptr));
        addButton->setText(QCoreApplication::translate("PatientMonitor", "Add", nullptr));
        scanButton->setText(QCoreApplication::translate("PatientMonitor", "Scan", nullptr));
        agePulseCheckButton->setText(QCoreApplication::translate("PatientMonitor", "Age checker", nullptr));
        normPressureCheckButton->setText(QCoreApplication::translate("PatientMonitor", "Check healthy person", nullptr));
        bloodTypeGroupButton->setText(QCoreApplication::translate("PatientMonitor", "Group by BT | RH", nullptr));
        scanTableButton->setText(QCoreApplication::translate("PatientMonitor", "Scan", nullptr));
        rhGroupHrSort->setText(QCoreApplication::translate("PatientMonitor", "Group RH | Sort HR", nullptr));
        menuFile->setTitle(QCoreApplication::translate("PatientMonitor", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientMonitor: public Ui_PatientMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTMONITOR_H
