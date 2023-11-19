#include "patientmonitor.h"
#include "patientinfo.h"
#include "ui_patientmonitor.h"

std::vector<patientInfo> patients;

PatientMonitor::PatientMonitor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PatientMonitor)
{
    ui->setupUi(this);

    QGraphicsDropShadowEffect *shadowEffectScan = new QGraphicsDropShadowEffect();
    shadowEffectScan->setBlurRadius(20);
    shadowEffectScan->setXOffset(0);
    shadowEffectScan->setColor(QColor(0, 0, 0, 30));

    QGraphicsDropShadowEffect *shadowEffectAdd = new QGraphicsDropShadowEffect();
    shadowEffectAdd->setBlurRadius(20);
    shadowEffectAdd->setXOffset(0);
    shadowEffectAdd->setColor(QColor(0, 0, 0, 30));

    QGraphicsDropShadowEffect *shadowEffectWrite = new QGraphicsDropShadowEffect();
    shadowEffectWrite->setBlurRadius(20);
    shadowEffectWrite->setXOffset(0);
    shadowEffectWrite->setColor(QColor(0, 0, 0, 30));

    QGraphicsDropShadowEffect *shadowEffectPressureSort = new QGraphicsDropShadowEffect();
    shadowEffectPressureSort->setBlurRadius(20);
    shadowEffectPressureSort->setXOffset(0);
    shadowEffectPressureSort->setColor(QColor(0, 0, 0, 30));

    QGraphicsDropShadowEffect *shadowEffectTypeGroup = new QGraphicsDropShadowEffect();
    shadowEffectTypeGroup->setBlurRadius(20);
    shadowEffectTypeGroup->setXOffset(0);
    shadowEffectTypeGroup->setColor(QColor(0, 0, 0, 30));

    QGraphicsDropShadowEffect *shadowEffectPulseSort = new QGraphicsDropShadowEffect();
    shadowEffectPulseSort->setBlurRadius(20);
    shadowEffectPulseSort->setXOffset(0);
    shadowEffectPulseSort->setColor(QColor(0, 0, 0, 30));

    QGraphicsDropShadowEffect *shadowEffectUniDonors = new QGraphicsDropShadowEffect();
    shadowEffectUniDonors->setBlurRadius(20);
    shadowEffectUniDonors->setXOffset(0);
    shadowEffectUniDonors->setColor(QColor(0, 0, 0, 30));

    QGraphicsDropShadowEffect *shadowEffectAgePulseChecker = new QGraphicsDropShadowEffect();
    shadowEffectAgePulseChecker->setBlurRadius(20);
    shadowEffectAgePulseChecker->setXOffset(0);
    shadowEffectAgePulseChecker->setColor(QColor(0, 0, 0, 30));

    QGraphicsDropShadowEffect *shadowEffectHealthyChecker = new QGraphicsDropShadowEffect();
    shadowEffectHealthyChecker->setBlurRadius(20);
    shadowEffectHealthyChecker->setXOffset(0);
    shadowEffectHealthyChecker->setColor(QColor(0, 0, 0, 30));

    ui->scanButton->setGraphicsEffect(shadowEffectScan);
    ui->addButton->setGraphicsEffect(shadowEffectAdd);
    ui->writeButton->setGraphicsEffect(shadowEffectWrite);
    ui->bloodPressureSort->setGraphicsEffect(shadowEffectPressureSort);
    ui->bloodTypeGroupButton->setGraphicsEffect(shadowEffectTypeGroup);
    ui->pulseSortButton->setGraphicsEffect(shadowEffectPulseSort);
    ui->donorCheckButton->setGraphicsEffect(shadowEffectUniDonors);
    ui->agePulseCheckButton->setGraphicsEffect(shadowEffectAgePulseChecker);
    ui->normPressureCheckButton->setGraphicsEffect(shadowEffectHealthyChecker);

    ui->patientTable->setColumnCount(7);
    ui->patientTable->setColumnWidth(0, 47);
    ui->patientTable->setColumnWidth(1, 122);
    ui->patientTable->setColumnWidth(2, 65);
    ui->patientTable->setColumnWidth(3, 126);
    ui->patientTable->setColumnWidth(4, 120);
    ui->patientTable->setColumnWidth(5, 143);
    ui->patientTable->setColumnWidth(6, 88);

    ui->patientTable->setShowGrid(false);

    ui->patientTable->horizontalHeader()->setVisible(false);
    ui->patientTable->verticalHeader()->setVisible(false);

    ui->patientTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->patientTable->setSelectionMode(QAbstractItemView::NoSelection);


    QGraphicsDropShadowEffect *shadowEffectScanTable = new QGraphicsDropShadowEffect();
    shadowEffectScanTable->setBlurRadius(20);
    shadowEffectScanTable->setXOffset(0);
    shadowEffectScanTable->setColor(QColor(0, 0, 0, 30));

    ui->scanTableButton->setGraphicsEffect(shadowEffectScanTable);

    connect(ui->scanTableButton, &QPushButton::clicked, this, &PatientMonitor::onScanTableButtonClick);
    ui->scanTableButton->setVisible(false);

    try {
        if (ui->patientTable->rowCount() == 0)
            throw 1;
    }
    catch (int) {
        ui->scanTableButton->setVisible(true);
    }
}

PatientMonitor::~PatientMonitor()
{
    delete ui;
}


void PatientMonitor::onScanTableButtonClick() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("All Files (*.*)"));

    std::ifstream inputData(fileName.toStdString());

    try {
        if(!inputData || inputData.peek() == EOF)
            throw 1;
    }
    catch (int) {
        QMessageBox mb("PatientMonitor",
                       "Error\n\nFile cannot be opened or it is empty\nPlease, try again",
                       QMessageBox::NoIcon,
                       QMessageBox::Ok | QMessageBox::Default,
                       QMessageBox::NoButton,
                       QMessageBox::NoButton);
        QPixmap exportSuccess("C:\\Users\\maxnevermo\\Downloads\\sad-but-relieved-face_1f625.png");
        mb.setIconPixmap(exportSuccess);
        mb.setStyleSheet("QMessageBox {"
                         "background-color: #C6CCE8;"
                         "color: #000000;"
                         "font-family: 'Gogh';"
                         "font-weight: 400;"
                         "font-size: 20px"
                         "}");
        mb.exec();
    }

    std::string myline;
    while (inputData) {
        std::getline (inputData, myline);
        qDebug() << myline << ": " << inputData.tellg() << '\n';
    }

    inputData.close();
}



void PatientMonitor::on_scanButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Text File"), QDir::homePath(), tr("Text Files (*.txt)"));

    std::ifstream inputData(fileName.toStdString());

    if(!inputData || inputData.peek() == EOF){
        QMessageBox mb("PatientMonitor",
                       "Error\n\nFile cannot be opened or it is empty\nPlease, try again",
                       QMessageBox::NoIcon,
                       QMessageBox::Ok | QMessageBox::Default,
                       QMessageBox::NoButton,
                       QMessageBox::NoButton);
        QPixmap exportSuccess("C:\\Users\\maxnevermo\\Downloads\\sad-but-relieved-face_1f625.png");
        mb.setIconPixmap(exportSuccess);

        mb.setStyleSheet("QMessageBox {"
                         "background-color: #C6CCE8;"
                         "color: #000000;"
                         "font-family: 'Gogh';"
                         "font-weight: 400;"
                         "font-size: 20px"
                         "}");
        mb.exec();
    }

    std::string myline;
    while (inputData) {
        std::getline (inputData, myline);
        qDebug() << myline << ": " << inputData.tellg() << '\n';
    }

        inputData.close();
}


void PatientMonitor::on_addButton_clicked()
{
    addPatientDialog addPatientDialog(this);
    connect(&addPatientDialog, &addPatientDialog::patientAdded, this, &PatientMonitor::onPatientAdded);
    addPatientDialog.exec();
}

void PatientMonitor::onPatientAdded(const patientInfo &patient)
{
    patients.push_back(patient);
    int rows = ui->patientTable->rowCount();
    int createNewRow = rows + 1;

    ui->patientTable->insertRow(rows);

    QTableWidgetItem* newPatientInfo = new QTableWidgetItem(QString::number(createNewRow));
    newPatientInfo->setTextAlignment(Qt::AlignCenter);
    ui->patientTable->setItem(rows, 0, newPatientInfo);

    newPatientInfo = new QTableWidgetItem(patient.getSurname().c_str());
    newPatientInfo->setTextAlignment(Qt::AlignCenter);
    ui->patientTable->setItem(rows, 1, newPatientInfo);

    newPatientInfo = new QTableWidgetItem(QString::number(patient.getAge()));
    newPatientInfo->setTextAlignment(Qt::AlignCenter);
    ui->patientTable->setItem(rows, 2, newPatientInfo);

    newPatientInfo = new QTableWidgetItem(QString::fromStdString(patient.getBloodType()));
    newPatientInfo->setTextAlignment(Qt::AlignCenter);
    ui->patientTable->setItem(rows, 3, newPatientInfo);

    newPatientInfo = new QTableWidgetItem(QString::fromStdString(patient.getRhFactor()));
    newPatientInfo->setTextAlignment(Qt::AlignCenter);
    ui->patientTable->setItem(rows, 4, newPatientInfo);

    newPatientInfo = new QTableWidgetItem(QString::number(patient.getUpPressure()) + "/" + QString::number(patient.getLowPressure()));
    newPatientInfo->setTextAlignment(Qt::AlignCenter);
    ui->patientTable->setItem(rows, 5, newPatientInfo);

    newPatientInfo = new QTableWidgetItem(QString::number(patient.getPulseValue()));
    newPatientInfo->setTextAlignment(Qt::AlignCenter);
    ui->patientTable->setItem(rows, 6, newPatientInfo);

    checkIfEmpty();
}




void PatientMonitor::checkIfEmpty() {
    if(ui->patientTable->rowCount() > 0) {
        ui->scanTableButton->setVisible(false);
    } else {
        ui->scanTableButton->setVisible(true);
    }
}
