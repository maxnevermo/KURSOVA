/********************************************************************************
** Form generated from reading UI file 'agepatientdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGEPATIENTDIALOG_H
#define UI_AGEPATIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_agePatientDialog
{
public:
    QSpinBox *ageSpinBox;
    QLabel *ageLabel_2;
    QLabel *ageLabel;
    QPushButton *addButton;

    void setupUi(QDialog *agePatientDialog)
    {
        if (agePatientDialog->objectName().isEmpty())
            agePatientDialog->setObjectName("agePatientDialog");
        agePatientDialog->resize(317, 186);
        agePatientDialog->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: #8E9DCC\n"
"}"));
        ageSpinBox = new QSpinBox(agePatientDialog);
        ageSpinBox->setObjectName("ageSpinBox");
        ageSpinBox->setGeometry(QRect(135, 70, 170, 31));
        ageSpinBox->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"    background-color: #C6CCE8;\n"
"    color: #000000;\n"
"    border-radius: 0.5em;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"	font-size: 15px;\n"
"}\n"
"\n"
"QSpinBox:hover {\n"
"    background-color: #A9B9E3;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"}\n"
""));
        ageLabel_2 = new QLabel(agePatientDialog);
        ageLabel_2->setObjectName("ageLabel_2");
        ageLabel_2->setGeometry(QRect(70, 30, 190, 30));
        ageLabel_2->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-size: 20px;\n"
"font-family: \"Gogh\";\n"
"font-weight: 500;"));
        ageLabel = new QLabel(agePatientDialog);
        ageLabel->setObjectName("ageLabel");
        ageLabel->setGeometry(QRect(15, 70, 60, 30));
        ageLabel->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-size: 20px;\n"
"font-family: \"Gogh\";\n"
"font-weight: 500;"));
        addButton = new QPushButton(agePatientDialog);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(100, 130, 120, 40));
        addButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        retranslateUi(agePatientDialog);

        QMetaObject::connectSlotsByName(agePatientDialog);
    } // setupUi

    void retranslateUi(QDialog *agePatientDialog)
    {
        agePatientDialog->setWindowTitle(QCoreApplication::translate("agePatientDialog", "Dialog", nullptr));
        ageLabel_2->setText(QCoreApplication::translate("agePatientDialog", "Enter age to check:", nullptr));
        ageLabel->setText(QCoreApplication::translate("agePatientDialog", "Age", nullptr));
        addButton->setText(QCoreApplication::translate("agePatientDialog", "\320\224\320\276\320\264\320\260\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class agePatientDialog: public Ui_agePatientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGEPATIENTDIALOG_H
