#include "patientmonitoring.h"
#include "ui_patientmonitoring.h"

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

