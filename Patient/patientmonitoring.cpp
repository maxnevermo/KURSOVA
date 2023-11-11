#include "patientmonitoring.h"
#include "patientinfo.h"
#include "ui_patientmonitoring.h"

std::vector<patientInfo> patients;

PatientMonitoring::PatientMonitoring(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PatientMonitoring)
{
    ui->setupUi(this);
}

PatientMonitoring::~PatientMonitoring()
{
    delete ui;
}

