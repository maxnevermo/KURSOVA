/********************************************************************************
** Form generated from reading UI file 'heartratesortdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEARTRATESORTDIALOG_H
#define UI_HEARTRATESORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_heartRateSortDialog
{
public:
    QPushButton *sortConfirm;
    QComboBox *orderChoice;

    void setupUi(QDialog *heartRateSortDialog)
    {
        if (heartRateSortDialog->objectName().isEmpty())
            heartRateSortDialog->setObjectName("heartRateSortDialog");
        heartRateSortDialog->resize(200, 118);
        heartRateSortDialog->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: #8E9DCC\n"
"}"));
        sortConfirm = new QPushButton(heartRateSortDialog);
        sortConfirm->setObjectName("sortConfirm");
        sortConfirm->setGeometry(QRect(55, 70, 90, 35));
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
        orderChoice = new QComboBox(heartRateSortDialog);
        orderChoice->addItem(QString());
        orderChoice->addItem(QString());
        orderChoice->setObjectName("orderChoice");
        orderChoice->setGeometry(QRect(35, 20, 140, 25));
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

        retranslateUi(heartRateSortDialog);

        QMetaObject::connectSlotsByName(heartRateSortDialog);
    } // setupUi

    void retranslateUi(QDialog *heartRateSortDialog)
    {
        heartRateSortDialog->setWindowTitle(QCoreApplication::translate("heartRateSortDialog", "Dialog", nullptr));
        sortConfirm->setText(QCoreApplication::translate("heartRateSortDialog", "Sort", nullptr));
        orderChoice->setItemText(0, QCoreApplication::translate("heartRateSortDialog", "By growth", nullptr));
        orderChoice->setItemText(1, QCoreApplication::translate("heartRateSortDialog", "By descending", nullptr));

    } // retranslateUi

};

namespace Ui {
    class heartRateSortDialog: public Ui_heartRateSortDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEARTRATESORTDIALOG_H
