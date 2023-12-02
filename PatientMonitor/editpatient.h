#ifndef EDITPATIENT_H
#define EDITPATIENT_H

//діалогове вікно для зміни даних
//про пацієнта

#include <QDialog>
#include "patientinfo.h"
namespace Ui {
class EditPatient;
}

class EditPatient : public QDialog
{
    Q_OBJECT

public:
    explicit EditPatient(QWidget *parent = nullptr, patientInfo *patient = nullptr);
    ~EditPatient();
    patientInfo* getEditedPatient() const {return editedPatient;}
    void editDataError(const QString &errorInputMessage);

signals:
    void accepted();

private slots:
    void on_changeButton_clicked();

private:
    Ui::EditPatient *ui;
    patientInfo *editedPatient;
};

#endif
