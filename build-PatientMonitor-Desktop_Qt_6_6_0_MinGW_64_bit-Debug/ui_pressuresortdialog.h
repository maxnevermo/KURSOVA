/********************************************************************************
** Form generated from reading UI file 'pressuresortdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRESSURESORTDIALOG_H
#define UI_PRESSURESORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_pressureSortDialog
{
public:
    QComboBox *pressureChoice;
    QComboBox *orderChoice;
    QPushButton *sortConfirm;

    void setupUi(QDialog *pressureSortDialog)
    {
        if (pressureSortDialog->objectName().isEmpty())
            pressureSortDialog->setObjectName("pressureSortDialog");
        pressureSortDialog->resize(200, 180);
        pressureSortDialog->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: #8E9DCC\n"
"}"));
        pressureChoice = new QComboBox(pressureSortDialog);
        pressureChoice->addItem(QString());
        pressureChoice->addItem(QString());
        pressureChoice->setObjectName("pressureChoice");
        pressureChoice->setGeometry(QRect(30, 20, 140, 25));
        pressureChoice->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        orderChoice = new QComboBox(pressureSortDialog);
        orderChoice->addItem(QString());
        orderChoice->addItem(QString());
        orderChoice->setObjectName("orderChoice");
        orderChoice->setGeometry(QRect(30, 70, 140, 25));
        orderChoice->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        sortConfirm = new QPushButton(pressureSortDialog);
        sortConfirm->setObjectName("sortConfirm");
        sortConfirm->setGeometry(QRect(55, 120, 90, 35));
        sortConfirm->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        retranslateUi(pressureSortDialog);

        QMetaObject::connectSlotsByName(pressureSortDialog);
    } // setupUi

    void retranslateUi(QDialog *pressureSortDialog)
    {
        pressureSortDialog->setWindowTitle(QCoreApplication::translate("pressureSortDialog", "Dialog", nullptr));
        pressureChoice->setItemText(0, QCoreApplication::translate("pressureSortDialog", "By upper", nullptr));
        pressureChoice->setItemText(1, QCoreApplication::translate("pressureSortDialog", "By lower", nullptr));

        orderChoice->setItemText(0, QCoreApplication::translate("pressureSortDialog", "By growth", nullptr));
        orderChoice->setItemText(1, QCoreApplication::translate("pressureSortDialog", "By descending", nullptr));

        sortConfirm->setText(QCoreApplication::translate("pressureSortDialog", "Sort", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pressureSortDialog: public Ui_pressureSortDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRESSURESORTDIALOG_H
