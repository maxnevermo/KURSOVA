#ifndef ADDPATIENTDIALOG_H
#define ADDPATIENTDIALOG_H

#include <QDialog>
#include "patientinfo.h"

namespace Ui {
class addPatientDialog;
}

class addPatientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addPatientDialog(QWidget *parent = nullptr);
    ~addPatientDialog();

signals:
    void patientAdded(const patientInfo &patient);

private slots:
    void on_addButton_clicked();
private:
    Ui::addPatientDialog *ui;
};

#endif // ADDPATIENTDIALOG_H
