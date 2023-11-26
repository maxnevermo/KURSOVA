#include "patientmonitor.h"
#include "patientinfo.h"
#include "ui_patientmonitor.h"

std::vector<patientInfo> patients;
std::vector<patientInfo> hyperTTachyC;
std::vector<patientInfo> healthyPatients;
std::vector<patientInfo> backUpVector;

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

    ui->patientTable->setSelectionMode(QAbstractItemView::MultiSelection);
    connect(ui->patientTable, &QTableWidget::itemClicked, this, &PatientMonitor::onItemClicked);

    ui->patientTable->setFocusPolicy(Qt::NoFocus);


    ui->menuFile->setStyleSheet("QMenu {background-color: #C6CCE8; color: #000000; border-radius: 0.5em; font-family: 'Gogh'; font-weight: 500; font-size: 15px }"
                                "QMenu:hover { background-color: #A9B9E3; font-family: 'Gogh'; font-weight: 500; } ");

    ui->menubar->setStyleSheet("QMenuBar { color: #000000; border-radius: 0.5em; font-family: 'Gogh'; font-weight: 500; font-size: 15px }");


    QGraphicsDropShadowEffect *shadowEffectScanTable = new QGraphicsDropShadowEffect();
    shadowEffectScanTable->setBlurRadius(20);
    shadowEffectScanTable->setXOffset(0);
    shadowEffectScanTable->setColor(QColor(0, 0, 0, 30));

    ui->scanTableButton->setGraphicsEffect(shadowEffectScanTable);
    ui->scanTableButton->setVisible(false);
    connect(ui->scanTableButton, &QPushButton::clicked, this, &PatientMonitor::onScanTableButtonClick);


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



std::vector<std::string> splitByString(const std::string& input, const std::string& delimiter) {
    std::vector<std::string> elements;
    size_t startPos = 0;
    size_t foundPos;

    while ((foundPos = input.find(delimiter, startPos)) != std::string::npos) {
        elements.push_back(input.substr(startPos, foundPos - startPos));
        startPos = foundPos + delimiter.length();
    }

    elements.push_back(input.substr(startPos));
    return elements;
}



void PatientMonitor::on_scanButton_clicked()
{

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Text File"), QDir::homePath(), tr("Text Files (*.txt)"));

    std::ifstream inputData(fileName.toStdString());

    if (!inputData || inputData.peek() == EOF) {
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
    std::string delim = " | ";
    std::string Pdelim = "/";
    std::vector<std::string> dividedPatientInfo;
    std::vector<std::string> dividedPressure;

    while (std::getline(inputData, myline)) {
        dividedPatientInfo = splitByString(myline, delim);
        dividedPressure = splitByString(dividedPatientInfo.at(4), Pdelim);
        patientInfo newPatient (dividedPatientInfo.at(0), stoi(dividedPatientInfo.at(1)),dividedPatientInfo.at(2),dividedPatientInfo.at(3),stoi(dividedPressure.at(0)),
                               stoi(dividedPressure.at(1)), stoi(dividedPatientInfo.at(5)));
        onPatientAdded(newPatient);
    }

    inputData.close();

    if (backUpVector.empty()) {
        backUpVector = patients;
    }
}

void PatientMonitor::onScanTableButtonClick() {
    on_scanButton_clicked();
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

void PatientMonitor::pressureQuickSort(std::vector<patientInfo> &patients, int low, int high) {
    if (low < high) {
        int pivotIndex = pressurePartition(patients, low, high);
        pressureQuickSort(patients, low, pivotIndex - 1);
        pressureQuickSort(patients, pivotIndex + 1, high);
    }
}

int PatientMonitor::pressurePartition(std::vector<patientInfo> &patients, int low, int high) {
    patientInfo pivot = patients[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (patients[j].getUpPressure() < pivot.getUpPressure()) {
            i++;
            std::swap(patients[i], patients[j]);
        }
    }

    std::swap(patients[i + 1], patients[high]);
    return i + 1;
}

void PatientMonitor::heartRateQuickSort(std::vector<patientInfo> &patients, int low, int high) {
    if (low < high) {
        int pivotIndex = heartRatepressurepartition(patients, low, high);
        heartRateQuickSort(patients, low, pivotIndex - 1);
        heartRateQuickSort(patients, pivotIndex + 1, high);
    }
}

int PatientMonitor::heartRatepressurepartition(std::vector<patientInfo> &patients, int low, int high) {
    patientInfo pivot = patients[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (patients[j].getPulseValue() < pivot.getPulseValue()) {
            i++;
            std::swap(patients[i], patients[j]);
        }
    }

    std::swap(patients[i + 1], patients[high]);
    return i + 1;
}

void PatientMonitor::on_bloodPressureSort_clicked()
{
    if (patients.size() == 0) {
        operatingError();
    } else {
    std::vector<patientInfo> patientsToOperate = patients;

    pressureQuickSort(patientsToOperate, 0, patientsToOperate.size() - 1);

    ui->patientTable->clear();

    QTableWidgetItem* newPatientInfo = NULL;

    for (int i =0; i < (int)(patients.size()); i++) {
        newPatientInfo = new QTableWidgetItem(QString::number(i+1));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 0, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(patientsToOperate[i].getSurname().c_str());
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 1, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::number(patientsToOperate[i].getAge()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 2, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::fromStdString(patientsToOperate[i].getBloodType()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 3, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::fromStdString(patientsToOperate[i].getRhFactor()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 4, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::number(patientsToOperate[i].getUpPressure()) + "/" + QString::number(patientsToOperate[i].getLowPressure()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 5, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::number(patientsToOperate[i].getPulseValue()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 6, newPatientInfo);
    }
    }
}

void PatientMonitor::checkIfEmpty() {
    if(ui->patientTable->rowCount() > 0) {
        ui->scanTableButton->setVisible(false);
    } else {
        ui->scanTableButton->setVisible(true);
    }
}

void PatientMonitor::on_bloodTypeGroupButton_clicked()
{
    if (patients.size() == 0) {
        operatingError();
    } else {
    std::vector<patientInfo> firstTB;
    std::vector<patientInfo> secondTB;
    std::vector<patientInfo> thirdTB;
    std::vector<patientInfo> fourthTB;

    std::vector<patientInfo> rhP;
    std::vector<patientInfo> rhM;

    std::string currentBT;
    std::string currentRH;

    for (int i = 0; i < (int)(patients.size()); i++) {
        currentRH = patients[i].getRhFactor();
        if(currentRH == "+")
            rhP.push_back(patients[i]);
        if(currentRH == "-")
            rhM.push_back(patients[i]);
    }

    std::vector<patientInfo> groupedPatients;
    groupedPatients.insert(groupedPatients.end(), rhP.begin(), rhP.end());
    groupedPatients.insert(groupedPatients.end(), rhM.begin(), rhM.end());

    rhP.clear();
    rhM.clear();


    for (int i = 0; i < (int)(groupedPatients.size()); i++) {
        currentBT = groupedPatients[i].getBloodType();
        if(currentBT == "I")
            firstTB.push_back(groupedPatients[i]);
        if(currentBT == "II")
            secondTB.push_back(groupedPatients[i]);
        if(currentBT == "III")
            thirdTB.push_back(groupedPatients[i]);
        if(currentBT == "IV")
            fourthTB.push_back(groupedPatients[i]);
    }

    std::vector<patientInfo> mergedVector;
    mergedVector.insert(mergedVector.end(), firstTB.begin(), firstTB.end());
    mergedVector.insert(mergedVector.end(), secondTB.begin(), secondTB.end());
    mergedVector.insert(mergedVector.end(), thirdTB.begin(), thirdTB.end());
    mergedVector.insert(mergedVector.end(), fourthTB.begin(), fourthTB.end());

    firstTB.clear();
    secondTB.clear();
    thirdTB.clear();
    fourthTB.clear();

    QTableWidgetItem* newPatientInfo = NULL;

    ui->patientTable->clear();

    for (int i = 0; i < (int)(mergedVector.size()); i++) {
        newPatientInfo = new QTableWidgetItem(QString::number(i+1));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 0, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(mergedVector[i].getSurname().c_str());
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 1, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::number(mergedVector[i].getAge()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 2, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::fromStdString(mergedVector[i].getBloodType()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 3, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::fromStdString(mergedVector[i].getRhFactor()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 4, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::number(mergedVector[i].getUpPressure()) + "/" + QString::number(groupedPatients[i].getLowPressure()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 5, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::number(mergedVector[i].getPulseValue()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 6, newPatientInfo);
    }
    }
}

void PatientMonitor::on_rhGroupHrSort_clicked()
{
    if (patients.size() == 0) {
        operatingError();
    } else {
    std::vector<patientInfo> rhP;
    std::vector<patientInfo> rhM;

    std::string currentRH;

    for (int i = 0; i < (int)(patients.size()); i++) {
        currentRH = patients[i].getRhFactor();
        if(currentRH == "+")
            rhP.push_back(patients[i]);
        if(currentRH == "-")
            rhM.push_back(patients[i]);
    }

    heartRateQuickSort(rhP, 0, rhP.size() - 1);
    heartRateQuickSort(rhM, 0, rhM.size() - 1);


    std::vector<patientInfo> groupedPatients;
    groupedPatients.insert(groupedPatients.end(), rhP.begin(), rhP.end());
    groupedPatients.insert(groupedPatients.end(), rhM.begin(), rhM.end());

    rhP.clear();
    rhM.clear();

    QTableWidgetItem* newPatientInfo = NULL;

    ui->patientTable->clear();

    for (int i = 0; i < (int)(groupedPatients.size()); i++) {
        newPatientInfo = new QTableWidgetItem(QString::number(i+1));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 0, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(groupedPatients[i].getSurname().c_str());
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 1, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::number(groupedPatients[i].getAge()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 2, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::fromStdString(groupedPatients[i].getBloodType()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 3, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::fromStdString(groupedPatients[i].getRhFactor()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 4, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::number(groupedPatients[i].getUpPressure()) + "/" + QString::number(groupedPatients[i].getLowPressure()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 5, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::number(groupedPatients[i].getPulseValue()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 6, newPatientInfo);
    }
    }
}

void PatientMonitor::on_agePulseCheckButton_clicked()
{
    if(patients.size() == 0) {
         operatingError();
    } else {

    AgeInputDialog ageInputDialogWindow(this);
    connect(&ageInputDialogWindow, &AgeInputDialog::ageSet, this, &PatientMonitor::handleAgeSet);
    ageInputDialogWindow.exec();
    }
}

void PatientMonitor::handleAgeSet(const int &age) {
    int flagChecker = 0;
    hyperTTachyC.clear();

    for (int i = 0; i < (int)(patients.size()); i++) {
        if (patients[i].getAge() == age) {
            flagChecker++;
        }
    }

    if (flagChecker == 0) {
        QMessageBox mb("Pressure and pulse check",
                       "No patients of this age",
                       QMessageBox::NoIcon,
                       QMessageBox::Ok | QMessageBox::Default,
                       QMessageBox::NoButton,
                       QMessageBox::NoButton);
        QPixmap exportSuccess("C:\\Users\\maxnevermo\\Downloads\\gui-check-no-svgrepo-com.svg");
        mb.setIconPixmap(exportSuccess);
        mb.setStyleSheet("QMessageBox {"
                         "background-color: #C6CCE8;"
                         "color: #000000;"
                         "font-family: 'Gogh';"
                         "font-weight: 400;"
                         "font-size: 20px"
                         "}");
        mb.exec();
    } else {
        for (int i = (int)(patients.size()); i >= 0; i--) {
            ui->patientTable->removeRow(i);
        }

        for (int i = 0; i < (int)(patients.size()); i++) {
            if (patients[i].getAge() == age) {
                if (age >= 0 && age <= 7) {
                if (patients[i].getPulseValue() >= 115) {
                    hyperTTachyC.push_back(patients[i]);
                }
                } else if (age >= 8 && age <= 18) {
                if (patients[i].getPulseValue() >= 85) {
                    hyperTTachyC.push_back(patients[i]);
                }
                } else if (age >= 19 && age <= 50) {
                if (patients[i].getPulseValue() >= 85) {
                    hyperTTachyC.push_back(patients[i]);
                }
            } else {
                if (patients[i].getPulseValue() >= 80) {
                    hyperTTachyC.push_back(patients[i]);
                }
            }
        }
    }

    QTableWidgetItem* newPatientInfo = NULL;

    for (int i = 0; i < (int)(hyperTTachyC.size()); i++) {
        ui->patientTable->insertRow(i);

        newPatientInfo = new QTableWidgetItem(QString::number(i+1));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 0, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(hyperTTachyC[i].getSurname().c_str());
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 1, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::number(hyperTTachyC[i].getAge()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 2, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::fromStdString(hyperTTachyC[i].getBloodType()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 3, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::fromStdString(hyperTTachyC[i].getRhFactor()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 4, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::number(hyperTTachyC[i].getUpPressure()) + "/" + QString::number(hyperTTachyC[i].getLowPressure()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 5, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::number(hyperTTachyC[i].getPulseValue()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 6, newPatientInfo);
    }
    }
}

void PatientMonitor::on_actionCancel_action_triggered()
{
    if (patients.size() == 0) {
        operatingError();
    } else {
    for (int i = (int)(patients.size())-1; i >= 0; i--) {
        ui->patientTable->removeRow(i);
    }

    QTableWidgetItem* newPatientInfo = NULL;

    for (int i = 0; i < (int)(backUpVector.size()); i++) {
    ui->patientTable->insertRow(i);

    newPatientInfo = new QTableWidgetItem(QString::number(i+1));
    newPatientInfo->setTextAlignment(Qt::AlignCenter);
    ui->patientTable->setItem(i, 0, newPatientInfo);

    newPatientInfo = new QTableWidgetItem(backUpVector[i].getSurname().c_str());
    newPatientInfo->setTextAlignment(Qt::AlignCenter);
    ui->patientTable->setItem(i, 1, newPatientInfo);

    newPatientInfo = new QTableWidgetItem(QString::number(backUpVector[i].getAge()));
    newPatientInfo->setTextAlignment(Qt::AlignCenter);
    ui->patientTable->setItem(i, 2, newPatientInfo);

    newPatientInfo = new QTableWidgetItem(QString::fromStdString(backUpVector[i].getBloodType()));
    newPatientInfo->setTextAlignment(Qt::AlignCenter);
    ui->patientTable->setItem(i, 3, newPatientInfo);

    newPatientInfo = new QTableWidgetItem(QString::fromStdString(backUpVector[i].getRhFactor()));
    newPatientInfo->setTextAlignment(Qt::AlignCenter);
    ui->patientTable->setItem(i, 4, newPatientInfo);

    newPatientInfo = new QTableWidgetItem(QString::number(backUpVector[i].getUpPressure()) + "/" + QString::number(backUpVector[i].getLowPressure()));
    newPatientInfo->setTextAlignment(Qt::AlignCenter);
    ui->patientTable->setItem(i, 5, newPatientInfo);

    newPatientInfo = new QTableWidgetItem(QString::number(backUpVector[i].getPulseValue()));
    newPatientInfo->setTextAlignment(Qt::AlignCenter);
    ui->patientTable->setItem(i, 6, newPatientInfo);
    }

    patients = backUpVector;
    }
}


void PatientMonitor::on_actionExit_triggered()
{
    close();
}


void PatientMonitor::on_writeButton_clicked()
{
    if (patients.size() == 0) {
        operatingError();
    } else {
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save Patient Data"), "", tr("Text Files (*.txt);;All Files (*)"));

    if (!filePath.isEmpty()) {
    std::ofstream patientOutputFile(filePath.toStdString());

    if (patientOutputFile.is_open()) {
        QString header = QString("%1 | %2 | %3 | %4 | %5 | %6 | %7\n")
                             .arg("ID", -15)
                             .arg("Name", -15)
                             .arg("Age", -15)
                             .arg("Ward", -15)
                             .arg("Blood Type", -15)
                             .arg("Blood Pressure", -15)
                             .arg("Heart Rate", -15);
        QString dividing = QString("-").repeated(125) + "\n";
        patientOutputFile << header.toStdString();
        patientOutputFile << dividing.toStdString();

        for (int i = 0; i < ui->patientTable->rowCount(); i++) {
            QString patientToOutput = "";

            for (int j = 0; j < ui->patientTable->columnCount(); j++) {
                QTableWidgetItem* theItem = ui->patientTable->item(i, j);
                QString theText = theItem->text();
                patientToOutput += QString("%1 | ").arg(theText, -15);
            }

            patientToOutput += "\n";
            patientOutputFile << patientToOutput.toStdString();
        }

        patientOutputFile.close();
    } else {
        std::cerr << "Error opening file\n";
    }
    }
    }
}




void PatientMonitor::onItemClicked(QTableWidgetItem *item) {
    if (item != nullptr) {
    int row = item->row();

    ui->patientTable->clearSelection();

    for (int col = 0; col < ui->patientTable->columnCount(); ++col) {
        ui->patientTable->item(row, col)->setSelected(true);
    }
    }
}


void PatientMonitor::on_normPressureCheckButton_clicked()
{
    if(patients.size() == 0) {
        operatingError();
    } else {

    healthyPatients.clear();
        for (int i = (int)(patients.size()); i >= 0; i--) {
            ui->patientTable->removeRow(i);
        }

        int age = 0;

        for (int i = 0; i < (int)(patients.size()); i++) {
            age = patients[i].getAge();
            if (age >= 0 && age <= 5) {
                if ((patients[i].getUpPressure() >= 80 && patients[i].getUpPressure() <= 110 ) &&
                    (patients[i].getLowPressure() >= 55 && patients[i].getLowPressure() <= 80 )) {
                    healthyPatients.push_back(patients[i]);
                }
            } else if (age >= 6 && age <= 13) {
                if ((patients[i].getUpPressure() >= 90 && patients[i].getUpPressure() <= 115 ) &&
                    (patients[i].getLowPressure() >= 60 && patients[i].getLowPressure() <= 80 )) {
                    healthyPatients.push_back(patients[i]);
                }
            }
            else if (age >= 14 && age <= 49) {
                if ((patients[i].getUpPressure() >= 110 && patients[i].getUpPressure() <= 140 ) &&
                    (patients[i].getLowPressure() >= 77 && patients[i].getLowPressure() <= 85 )) {
                    healthyPatients.push_back(patients[i]);
                }
            } else {
                if ((patients[i].getUpPressure() >= 115 && patients[i].getUpPressure() <= 150 ) &&
                    (patients[i].getLowPressure() >= 80 && patients[i].getLowPressure() <= 90 )) {
                    healthyPatients.push_back(patients[i]);
                }
            }
        }
    }

    QTableWidgetItem* newPatientInfo = NULL;

    for (int i = 0; i < (int)(healthyPatients.size()); i++) {
        ui->patientTable->insertRow(i);

        newPatientInfo = new QTableWidgetItem(QString::number(i+1));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 0, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(healthyPatients[i].getSurname().c_str());
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 1, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::number(healthyPatients[i].getAge()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 2, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::fromStdString(healthyPatients[i].getBloodType()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 3, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::fromStdString(healthyPatients[i].getRhFactor()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 4, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::number(healthyPatients[i].getUpPressure()) + "/" + QString::number(healthyPatients[i].getLowPressure()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 5, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::number(healthyPatients[i].getPulseValue()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 6, newPatientInfo);
    }
}

void PatientMonitor::on_donorCheckButton_clicked()
{
    if (patients.size() == 0) {
        operatingError();
    } else {
            donorsTable* donorsTableWindow = new donorsTable(this);
            connect(this, &PatientMonitor::sentPatients, donorsTableWindow, &donorsTable::receivePatientList);
            emit sentPatients(patients);
            donorsTableWindow->show();
    }
}

void PatientMonitor::operatingError() {
    QMessageBox mb("PatientMonitor",
                   "Patient list is empty",
                   QMessageBox::NoIcon,
                   QMessageBox::Yes | QMessageBox::Default,
                   QMessageBox::NoButton,
                   QMessageBox::NoButton);
    QPixmap exportSuccess("C:\\Users\\maxnevermo\\Downloads\\gui-check-no-svgrepo-com.svg");
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

void PatientMonitor::on_actionPrint_triggered()
{
    QPrinter printer(QPrinter::PrinterResolution);

    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec() == QDialog::Accepted) {
            QPainter painter(&printer);

            painter.setRenderHint(QPainter::Antialiasing, true);
            painter.setRenderHint(QPainter::TextAntialiasing, true);

            QFont font = painter.font();
            font.setPointSize(12);
            painter.setFont(font);

            double scaleFactor = 4;
            painter.scale(scaleFactor, scaleFactor);

            ui->patientTable->render(&painter);
    }
}


