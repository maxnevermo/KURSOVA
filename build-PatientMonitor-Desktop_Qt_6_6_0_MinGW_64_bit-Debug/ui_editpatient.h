/********************************************************************************
** Form generated from reading UI file 'editpatient.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPATIENT_H
#define UI_EDITPATIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_EditPatient
{
public:
    QComboBox *bloodTypeCB;
    QTextEdit *surnameTextEdit;
    QTextEdit *lowerPressureTextEdit;
    QLabel *ageLabel;
    QLabel *rhFactorLabel;
    QPushButton *changeButton;
    QTextEdit *upperPressureTextEdit;
    QLabel *surnameLabel;
    QLabel *pulseLabel;
    QComboBox *rhFactorCB;
    QLabel *upperLabel;
    QSpinBox *pulseCB;
    QLabel *bloodTypeLabel;
    QLabel *lowerLabel;
    QSpinBox *ageSpinBox;

    void setupUi(QDialog *EditPatient)
    {
        if (EditPatient->objectName().isEmpty())
            EditPatient->setObjectName("EditPatient");
        EditPatient->resize(394, 374);
        EditPatient->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: #8E9DCC\n"
"}"));
        bloodTypeCB = new QComboBox(EditPatient);
        bloodTypeCB->addItem(QString());
        bloodTypeCB->addItem(QString());
        bloodTypeCB->addItem(QString());
        bloodTypeCB->addItem(QString());
        bloodTypeCB->addItem(QString());
        bloodTypeCB->setObjectName("bloodTypeCB");
        bloodTypeCB->setGeometry(QRect(210, 90, 171, 25));
        bloodTypeCB->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #C6CCE8;\n"
"    color: #000000;\n"
"    border-radius: 0.5em;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"	font-size: 15px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    background-color: #A9B9E3;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"}\n"
""));
        surnameTextEdit = new QTextEdit(EditPatient);
        surnameTextEdit->setObjectName("surnameTextEdit");
        surnameTextEdit->setGeometry(QRect(210, 10, 171, 31));
        surnameTextEdit->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: #C6CCE8;\n"
"    color: #000000;\n"
"    border-radius: 0.5em;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"	font-size: 15px;\n"
"}\n"
"\n"
"QTextEdit:hover {\n"
"    background-color: #A9B9E3;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"}\n"
""));
        lowerPressureTextEdit = new QTextEdit(EditPatient);
        lowerPressureTextEdit->setObjectName("lowerPressureTextEdit");
        lowerPressureTextEdit->setGeometry(QRect(210, 210, 171, 30));
        lowerPressureTextEdit->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: #C6CCE8;\n"
"    color: #000000;\n"
"    border-radius: 0.5em;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"	font-size: 15px;\n"
"}\n"
"\n"
"QTextEdit:hover {\n"
"    background-color: #A9B9E3;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"}\n"
""));
        ageLabel = new QLabel(EditPatient);
        ageLabel->setObjectName("ageLabel");
        ageLabel->setGeometry(QRect(10, 50, 51, 30));
        ageLabel->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-size: 20px;\n"
"font-family: \"Gogh\";\n"
"font-weight: 500;"));
        rhFactorLabel = new QLabel(EditPatient);
        rhFactorLabel->setObjectName("rhFactorLabel");
        rhFactorLabel->setGeometry(QRect(10, 130, 91, 21));
        rhFactorLabel->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-size: 20px;\n"
"font-family: \"Gogh\";\n"
"font-weight: 500;"));
        changeButton = new QPushButton(EditPatient);
        changeButton->setObjectName("changeButton");
        changeButton->setGeometry(QRect(160, 310, 70, 40));
        changeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        upperPressureTextEdit = new QTextEdit(EditPatient);
        upperPressureTextEdit->setObjectName("upperPressureTextEdit");
        upperPressureTextEdit->setGeometry(QRect(210, 170, 171, 30));
        upperPressureTextEdit->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: #C6CCE8;\n"
"    color: #000000;\n"
"    border-radius: 0.5em;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"	font-size: 15px;\n"
"}\n"
"\n"
"QTextEdit:hover {\n"
"    background-color: #A9B9E3;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"}\n"
""));
        surnameLabel = new QLabel(EditPatient);
        surnameLabel->setObjectName("surnameLabel");
        surnameLabel->setGeometry(QRect(10, 10, 111, 30));
        surnameLabel->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-size: 20px;\n"
"font-family: \"Gogh\";\n"
"font-weight: 500;"));
        pulseLabel = new QLabel(EditPatient);
        pulseLabel->setObjectName("pulseLabel");
        pulseLabel->setGeometry(QRect(10, 255, 101, 40));
        pulseLabel->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-size: 20px;\n"
"font-family: \"Gogh\";\n"
"font-weight: 500;"));
        rhFactorCB = new QComboBox(EditPatient);
        rhFactorCB->addItem(QString());
        rhFactorCB->addItem(QString());
        rhFactorCB->addItem(QString());
        rhFactorCB->setObjectName("rhFactorCB");
        rhFactorCB->setGeometry(QRect(210, 130, 171, 25));
        rhFactorCB->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #C6CCE8;\n"
"    color: #000000;\n"
"    border-radius: 0.5em;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"	font-size: 15px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    background-color: #A9B9E3;\n"
"	font-family: 'Gogh';\n"
"	font-weight: 500;\n"
"}\n"
""));
        upperLabel = new QLabel(EditPatient);
        upperLabel->setObjectName("upperLabel");
        upperLabel->setGeometry(QRect(10, 160, 181, 40));
        upperLabel->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-size: 20px;\n"
"font-family: \"Gogh\";\n"
"font-weight: 500;"));
        pulseCB = new QSpinBox(EditPatient);
        pulseCB->setObjectName("pulseCB");
        pulseCB->setGeometry(QRect(210, 259, 171, 31));
        pulseCB->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
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
        bloodTypeLabel = new QLabel(EditPatient);
        bloodTypeLabel->setObjectName("bloodTypeLabel");
        bloodTypeLabel->setGeometry(QRect(10, 95, 111, 21));
        bloodTypeLabel->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-size: 20px;\n"
"font-family: \"Gogh\";\n"
"font-weight: 500;"));
        lowerLabel = new QLabel(EditPatient);
        lowerLabel->setObjectName("lowerLabel");
        lowerLabel->setGeometry(QRect(10, 200, 171, 40));
        lowerLabel->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-size: 20px;\n"
"font-family: \"Gogh\";\n"
"font-weight: 500;"));
        ageSpinBox = new QSpinBox(EditPatient);
        ageSpinBox->setObjectName("ageSpinBox");
        ageSpinBox->setGeometry(QRect(210, 50, 171, 31));
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

        retranslateUi(EditPatient);

        QMetaObject::connectSlotsByName(EditPatient);
    } // setupUi

    void retranslateUi(QDialog *EditPatient)
    {
        EditPatient->setWindowTitle(QCoreApplication::translate("EditPatient", "Dialog", nullptr));
        bloodTypeCB->setItemText(0, QCoreApplication::translate("EditPatient", "Undefined", nullptr));
        bloodTypeCB->setItemText(1, QCoreApplication::translate("EditPatient", "I", nullptr));
        bloodTypeCB->setItemText(2, QCoreApplication::translate("EditPatient", "II", nullptr));
        bloodTypeCB->setItemText(3, QCoreApplication::translate("EditPatient", "III", nullptr));
        bloodTypeCB->setItemText(4, QCoreApplication::translate("EditPatient", "IV", nullptr));

        ageLabel->setText(QCoreApplication::translate("EditPatient", "Age", nullptr));
        rhFactorLabel->setText(QCoreApplication::translate("EditPatient", "Rh factor", nullptr));
        changeButton->setText(QCoreApplication::translate("EditPatient", "Change", nullptr));
        surnameLabel->setText(QCoreApplication::translate("EditPatient", "Surname", nullptr));
        pulseLabel->setText(QCoreApplication::translate("EditPatient", "Heart rate", nullptr));
        rhFactorCB->setItemText(0, QCoreApplication::translate("EditPatient", "Undefined", nullptr));
        rhFactorCB->setItemText(1, QCoreApplication::translate("EditPatient", "+", nullptr));
        rhFactorCB->setItemText(2, QCoreApplication::translate("EditPatient", "-", nullptr));

        upperLabel->setText(QCoreApplication::translate("EditPatient", "Diastolic pressure", nullptr));
        bloodTypeLabel->setText(QCoreApplication::translate("EditPatient", "Blood type", nullptr));
        lowerLabel->setText(QCoreApplication::translate("EditPatient", "Systolic pressure", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditPatient: public Ui_EditPatient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPATIENT_H
