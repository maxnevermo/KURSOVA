#include "healthypatients.h"
#include "ui_healthypatients.h"

healthyPatients::healthyPatients(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::healthyPatients)
{
    ui->setupUi(this);
    ui->healthyPatientsTable->setColumnCount(2);

    ui->healthyPatientsTable->setColumnWidth(0, 290);
    ui->healthyPatientsTable->setColumnWidth(1, 290);

    QGraphicsDropShadowEffect *shadowEffectHealthyPatientsTable = new QGraphicsDropShadowEffect();
    shadowEffectHealthyPatientsTable->setBlurRadius(20);
    shadowEffectHealthyPatientsTable->setXOffset(0);
    shadowEffectHealthyPatientsTable->setColor(QColor(0, 0, 0, 30));

    ui->healthyPatientsTable->setGraphicsEffect(shadowEffectHealthyPatientsTable);

    ui->healthyPatientsTable->setShowGrid(false);

    ui->healthyPatientsTable->horizontalHeader()->setVisible(false);
    ui->healthyPatientsTable->verticalHeader()->setVisible(false);

    ui->healthyPatientsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->healthyPatientsTable->setSelectionMode(QAbstractItemView::NoSelection);

    ui->healthyPatientsTable->setSelectionMode(QAbstractItemView::MultiSelection);

    setWindowTitle("Healthy patients");

    ui->healthyPatientsTable->setFocusPolicy(Qt::NoFocus);

    ui->healthyPatientsTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->healthyPatientsTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

healthyPatients::~healthyPatients()
{
    delete ui;
}

void healthyPatients::receivePatientList(const std::vector<patientInfo> &patients) {

    QTableWidgetItem* newPatientInfo = NULL;

        //вивід здорових пацієнтів
        for (int i = 0; i < (int)(patients.size()); i++) {
            ui->healthyPatientsTable->insertRow(i);
            newPatientInfo = new QTableWidgetItem(QString::fromStdString(patients[i].getSurname()));
            newPatientInfo->setTextAlignment(Qt::AlignCenter);
            ui->healthyPatientsTable->setItem(i, 0, newPatientInfo);

            newPatientInfo = new QTableWidgetItem("---ЗДОРОВИЙ!---");
            newPatientInfo->setTextAlignment(Qt::AlignCenter);
            ui->healthyPatientsTable->setItem(i, 1, newPatientInfo);
    }
}
