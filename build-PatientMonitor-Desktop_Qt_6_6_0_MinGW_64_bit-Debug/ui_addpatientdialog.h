/********************************************************************************
** Form generated from reading UI file 'addpatientdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPATIENTDIALOG_H
#define UI_ADDPATIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_addPatientDialog
{
public:
    QTextEdit *surnameTextEdit;
    QTextEdit *upperPressureTextEdit;
    QSpinBox *ageSpinBox;
    QSpinBox *pulseCB;
    QComboBox *bloodTypeCB;
    QComboBox *rhFactorCB;
    QTextEdit *lowerPressureTextEdit;
    QLabel *surnameLabel;
    QLabel *ageLabel;
    QLabel *bloodTypeLabel;
    QLabel *rhFactorLabel;
    QLabel *upperLabel;
    QLabel *lowerLabel;
    QLabel *pulseLabel;
    QPushButton *addButton;

    void setupUi(QDialog *addPatientDialog)
    {
        if (addPatientDialog->objectName().isEmpty())
            addPatientDialog->setObjectName("addPatientDialog");
        addPatientDialog->resize(399, 439);
        addPatientDialog->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: #8E9DCC\n"
"}"));
        surnameTextEdit = new QTextEdit(addPatientDialog);
        surnameTextEdit->setObjectName("surnameTextEdit");
        surnameTextEdit->setGeometry(QRect(215, 40, 171, 31));
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
        upperPressureTextEdit = new QTextEdit(addPatientDialog);
        upperPressureTextEdit->setObjectName("upperPressureTextEdit");
        upperPressureTextEdit->setGeometry(QRect(215, 200, 171, 30));
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
        ageSpinBox = new QSpinBox(addPatientDialog);
        ageSpinBox->setObjectName("ageSpinBox");
        ageSpinBox->setGeometry(QRect(215, 80, 171, 31));
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
        pulseCB = new QSpinBox(addPatientDialog);
        pulseCB->setObjectName("pulseCB");
        pulseCB->setGeometry(QRect(215, 289, 171, 31));
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
        bloodTypeCB = new QComboBox(addPatientDialog);
        bloodTypeCB->setObjectName("bloodTypeCB");
        bloodTypeCB->setGeometry(QRect(215, 120, 171, 25));
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
        rhFactorCB = new QComboBox(addPatientDialog);
        rhFactorCB->setObjectName("rhFactorCB");
        rhFactorCB->setGeometry(QRect(215, 160, 171, 25));
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
        lowerPressureTextEdit = new QTextEdit(addPatientDialog);
        lowerPressureTextEdit->setObjectName("lowerPressureTextEdit");
        lowerPressureTextEdit->setGeometry(QRect(215, 240, 171, 30));
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
        surnameLabel = new QLabel(addPatientDialog);
        surnameLabel->setObjectName("surnameLabel");
        surnameLabel->setGeometry(QRect(15, 40, 111, 30));
        surnameLabel->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-size: 20px;\n"
"font-family: \"Gogh\";\n"
"font-weight: 500;"));
        ageLabel = new QLabel(addPatientDialog);
        ageLabel->setObjectName("ageLabel");
        ageLabel->setGeometry(QRect(15, 80, 30, 30));
        ageLabel->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-size: 20px;\n"
"font-family: \"Gogh\";\n"
"font-weight: 500;"));
        bloodTypeLabel = new QLabel(addPatientDialog);
        bloodTypeLabel->setObjectName("bloodTypeLabel");
        bloodTypeLabel->setGeometry(QRect(15, 125, 131, 21));
        bloodTypeLabel->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-size: 20px;\n"
"font-family: \"Gogh\";\n"
"font-weight: 500;"));
        rhFactorLabel = new QLabel(addPatientDialog);
        rhFactorLabel->setObjectName("rhFactorLabel");
        rhFactorLabel->setGeometry(QRect(15, 160, 141, 21));
        rhFactorLabel->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-size: 20px;\n"
"font-family: \"Gogh\";\n"
"font-weight: 500;"));
        upperLabel = new QLabel(addPatientDialog);
        upperLabel->setObjectName("upperLabel");
        upperLabel->setGeometry(QRect(15, 190, 191, 40));
        upperLabel->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-size: 20px;\n"
"font-family: \"Gogh\";\n"
"font-weight: 500;"));
        lowerLabel = new QLabel(addPatientDialog);
        lowerLabel->setObjectName("lowerLabel");
        lowerLabel->setGeometry(QRect(15, 230, 181, 40));
        lowerLabel->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-size: 20px;\n"
"font-family: \"Gogh\";\n"
"font-weight: 500;"));
        pulseLabel = new QLabel(addPatientDialog);
        pulseLabel->setObjectName("pulseLabel");
        pulseLabel->setGeometry(QRect(15, 285, 70, 40));
        pulseLabel->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-size: 20px;\n"
"font-family: \"Gogh\";\n"
"font-weight: 500;"));
        addButton = new QPushButton(addPatientDialog);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(140, 350, 121, 41));
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

        retranslateUi(addPatientDialog);

        QMetaObject::connectSlotsByName(addPatientDialog);
    } // setupUi

    void retranslateUi(QDialog *addPatientDialog)
    {
        addPatientDialog->setWindowTitle(QCoreApplication::translate("addPatientDialog", "Dialog", nullptr));
        surnameLabel->setText(QCoreApplication::translate("addPatientDialog", "\320\237\321\200\321\226\320\267\320\262\320\270\321\211\320\265", nullptr));
        ageLabel->setText(QCoreApplication::translate("addPatientDialog", "\320\222\321\226\320\272:", nullptr));
        bloodTypeLabel->setText(QCoreApplication::translate("addPatientDialog", "\320\223\321\200\321\203\320\277\320\260 \320\272\321\200\320\276\320\262\321\226", nullptr));
        rhFactorLabel->setText(QCoreApplication::translate("addPatientDialog", "\320\240\320\265\320\267\321\203\321\201-\321\204\320\260\320\272\321\202\320\276\321\200", nullptr));
        upperLabel->setText(QCoreApplication::translate("addPatientDialog", "\320\224\321\226\320\260\321\201\321\202\320\276\320\273\321\226\321\207\320\275\320\270\320\271 \321\202\320\270\321\201\320\272", nullptr));
        lowerLabel->setText(QCoreApplication::translate("addPatientDialog", "\320\241\320\270\321\201\321\202\320\276\320\273\321\226\321\207\320\275\320\270\320\271 \321\202\320\270\321\201\320\272", nullptr));
        pulseLabel->setText(QCoreApplication::translate("addPatientDialog", "\320\237\321\203\320\273\321\214\321\201", nullptr));
        addButton->setText(QCoreApplication::translate("addPatientDialog", "\320\224\320\276\320\264\320\260\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addPatientDialog: public Ui_addPatientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPATIENTDIALOG_H
