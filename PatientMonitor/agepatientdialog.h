#ifndef AGEPATIENTDIALOG_H
#define AGEPATIENTDIALOG_H

#include <QDialog>

namespace Ui {
class agePatientDialog;
}

class agePatientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit agePatientDialog(QWidget *parent = nullptr);
    ~agePatientDialog();

signals:
    void sentAge(int &patientAge);

private:
    Ui::agePatientDialog *ui;
};

#endif // AGEPATIENTDIALOG_H
