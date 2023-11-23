#include "agepatientdialog.h"
#include "ui_agepatientdialog.h"

agePatientDialog::agePatientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agePatientDialog)
{
    ui->setupUi(this);
}

agePatientDialog::~agePatientDialog()
{
    delete ui;
}
