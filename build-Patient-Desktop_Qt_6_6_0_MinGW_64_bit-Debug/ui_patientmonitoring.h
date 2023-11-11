/********************************************************************************
** Form generated from reading UI file 'patientmonitoring.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTMONITORING_H
#define UI_PATIENTMONITORING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientMonitoring
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PatientMonitoring)
    {
        if (PatientMonitoring->objectName().isEmpty())
            PatientMonitoring->setObjectName("PatientMonitoring");
        PatientMonitoring->resize(800, 600);
        centralwidget = new QWidget(PatientMonitoring);
        centralwidget->setObjectName("centralwidget");
        PatientMonitoring->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PatientMonitoring);
        menubar->setObjectName("menubar");
        PatientMonitoring->setMenuBar(menubar);
        statusbar = new QStatusBar(PatientMonitoring);
        statusbar->setObjectName("statusbar");
        PatientMonitoring->setStatusBar(statusbar);

        retranslateUi(PatientMonitoring);

        QMetaObject::connectSlotsByName(PatientMonitoring);
    } // setupUi

    void retranslateUi(QMainWindow *PatientMonitoring)
    {
        PatientMonitoring->setWindowTitle(QCoreApplication::translate("PatientMonitoring", "PatientMonitoring", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientMonitoring: public Ui_PatientMonitoring {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTMONITORING_H
