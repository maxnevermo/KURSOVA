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

void PatientMonitor::onScanTableButtonClick() {
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
    pressureQuickSort(patients, 0, patients.size() - 1);

    ui->patientTable->clear();

    QTableWidgetItem* newPatientInfo = NULL;

    for (int i =0; i < (int)(patients.size()); i++) {
        newPatientInfo = new QTableWidgetItem(QString::number(i+1));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 0, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(patients[i].getSurname().c_str());
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 1, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::number(patients[i].getAge()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 2, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::fromStdString(patients[i].getBloodType()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 3, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::fromStdString(patients[i].getRhFactor()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 4, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::number(patients[i].getUpPressure()) + "/" + QString::number(patients[i].getLowPressure()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 5, newPatientInfo);

        newPatientInfo = new QTableWidgetItem(QString::number(patients[i].getPulseValue()));
        newPatientInfo->setTextAlignment(Qt::AlignCenter);
        ui->patientTable->setItem(i, 6, newPatientInfo);
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

void PatientMonitor::on_rhGroupHrSort_clicked()
{
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

void PatientMonitor::onAgeSet(int age) {
    for (int i = 0; i < (int)(patients.size()); i++) {
    }
}

void PatientMonitor::on_agePulseCheckButton_clicked()
{
    agePatientDialog* agePatientDialogWindow = new agePatientDialog();
    agePatientDialogWindow->show();
    QObject::connect(agePatientDialogWindow, &agePatientDialog::sentAge, this, &PatientMonitor::onAgeSet);
}

