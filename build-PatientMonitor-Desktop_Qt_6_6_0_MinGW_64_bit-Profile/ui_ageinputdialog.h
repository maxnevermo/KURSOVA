/********************************************************************************
** Form generated from reading UI file 'ageinputdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGEINPUTDIALOG_H
#define UI_AGEINPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AgeInputDialog
{
public:
    QLabel *ageLabel;
    QLabel *enterAgeLabel;
    QSpinBox *ageSpinBox;
    QPushButton *checkButton;

    void setupUi(QDialog *AgeInputDialog)
    {
        if (AgeInputDialog->objectName().isEmpty())
            AgeInputDialog->setObjectName("AgeInputDialog");
        AgeInputDialog->resize(260, 220);
        AgeInputDialog->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: #8E9DCC\n"
"}"));
        ageLabel = new QLabel(AgeInputDialog);
        ageLabel->setObjectName("ageLabel");
        ageLabel->setGeometry(QRect(40, 70, 50, 30));
        ageLabel->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-size: 20px;\n"
"font-family: \"Gogh\";\n"
"font-weight: 500;"));
        enterAgeLabel = new QLabel(AgeInputDialog);
        enterAgeLabel->setObjectName("enterAgeLabel");
        enterAgeLabel->setGeometry(QRect(40, 20, 190, 30));
        enterAgeLabel->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"font-size: 20px;\n"
"font-family: \"Gogh\";\n"
"font-weight: 500;"));
        ageSpinBox = new QSpinBox(AgeInputDialog);
        ageSpinBox->setObjectName("ageSpinBox");
        ageSpinBox->setGeometry(QRect(150, 70, 70, 30));
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
        checkButton = new QPushButton(AgeInputDialog);
        checkButton->setObjectName("checkButton");
        checkButton->setGeometry(QRect(95, 130, 70, 30));
        checkButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        retranslateUi(AgeInputDialog);

        QMetaObject::connectSlotsByName(AgeInputDialog);
    } // setupUi

    void retranslateUi(QDialog *AgeInputDialog)
    {
        AgeInputDialog->setWindowTitle(QCoreApplication::translate("AgeInputDialog", "Dialog", nullptr));
        ageLabel->setText(QCoreApplication::translate("AgeInputDialog", "Age", nullptr));
        enterAgeLabel->setText(QCoreApplication::translate("AgeInputDialog", "Enter patients' age", nullptr));
        checkButton->setText(QCoreApplication::translate("AgeInputDialog", "Check", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AgeInputDialog: public Ui_AgeInputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGEINPUTDIALOG_H
