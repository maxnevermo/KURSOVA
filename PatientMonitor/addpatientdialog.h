#ifndef ADDPATIENTDIALOG_H
#define ADDPATIENTDIALOG_H

#include <QDialog>
#include <QGraphicsDropShadowEffect>
#include <QRegularExpression>
#include <QMessageBox>

#include "patientinfo.h"


namespace Ui {
class addPatientDialog;
}

class addPatientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addPatientDialog(QWidget *parent = nullptr);
    void addDataError(const QString &errorInputMessage);
    ~addPatientDialog();

signals:
    void patientAdded(patientInfo &patient);

private slots:
    void on_addButton_clicked();
private:
    Ui::addPatientDialog *ui;
};

#endif // ADDPATIENTDIALOG_H
