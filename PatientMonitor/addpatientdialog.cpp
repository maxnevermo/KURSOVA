#include "addpatientdialog.h"
#include "ui_addpatientdialog.h"

addPatientDialog::addPatientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPatientDialog)
{
    ui->setupUi(this);
    setWindowTitle("Add new patient");
    QStringList bloodTypeList = {"Undefined", "1", "2", "3", "4"};
    ui->bloodTypeCB->addItems(bloodTypeList);

    QStringList rhFactorList = {"Undefined", "+", "-"};
    ui->rhFactorCB->addItems(rhFactorList);
}

addPatientDialog::~addPatientDialog()
{
    delete ui;
}

void addPatientDialog::on_addButton_clicked()
{
    std::string gotName = ui->surnameTextEdit->toPlainText().toStdString();
    int gotAge = ui->ageSpinBox->value();
    int gotBloodType = ui->bloodTypeCB->currentText().toInt();
    std::string gotRhFactor = ui->rhFactorCB->currentText().toStdString();
    char rhFactorChar = gotRhFactor.at(0);
    int gotUpperPressure = ui->upperPressureTextEdit->toPlainText().toInt();
    int gotLowerPressure = ui->lowerPressureTextEdit->toPlainText().toInt();
    int gotPulse = ui->pulseCB->value();

    patientInfo* newPatient = new patientInfo(gotName, gotAge, gotBloodType, rhFactorChar, gotUpperPressure, gotLowerPressure, gotPulse);
    emit patientAdded(*newPatient);
}
