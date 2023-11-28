#include "patientmonitor.h"
#include "patientinfo.h"
#include "ui_patientmonitor.h"

int patientNum = 0;

std::vector<patientInfo> patients;
std::vector<patientInfo> hyperTTachyC;
std::vector<patientInfo> healthyPatientsList;
std::vector<patientInfo> backUpVector;
std::vector<patientInfo> vectorToPrint;

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
    ui->patientTable->setColumnWidth(0, 50);
    ui->patientTable->setColumnWidth(1, 120);
    ui->patientTable->setColumnWidth(2, 65);
    ui->patientTable->setColumnWidth(3, 125);
    ui->patientTable->setColumnWidth(4, 120);
    ui->patientTable->setColumnWidth(5, 140);
    ui->patientTable->setColumnWidth(6, 85);

    ui->patientTable->setShowGrid(false);

    ui->patientTable->horizontalHeader()->setVisible(false);
    ui->patientTable->verticalHeader()->setVisible(false);

    ui->patientTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->patientTable, &QTableWidget::itemClicked, this, &PatientMonitor::onItemClicked);

    ui->patientTable->setFocusPolicy(Qt::NoFocus);
    ui->patientTable->setSelectionMode(QAbstractItemView::MultiSelection);

    ui->menuFile->setStyleSheet("QMenu {background-color: #C6CCE8; color: #000000; border-radius: 0.5em; font-family: 'Gogh'; font-weight: 500; font-size: 15px }"
                                "QMenu:hover { background-color: #A9B9E3; font-family: 'Gogh'; font-weight: 500; } ");

    ui->menubar->setStyleSheet("QMenuBar { color: #000000; border-radius: 0.5em; font-family: 'Gogh'; font-weight: 500; font-size: 15px }");

    ui->patientTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->patientTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    QGraphicsDropShadowEffect *shadowEffectScanTable = new QGraphicsDropShadowEffect();
    shadowEffectScanTable->setBlurRadius(20);
    shadowEffectScanTable->setXOffset(0);
    shadowEffectScanTable->setColor(QColor(0, 0, 0, 30));

    ui->scanTableButton->setGraphicsEffect(shadowEffectScanTable);
    ui->scanTableButton->setVisible(false);
    connect(ui->scanTableButton, &QPushButton::clicked, this, &PatientMonitor::onScanTableButtonClick);

    contextMenu = new QMenu(this);
    deleteAction = new QAction("Delete patient", this);
    editAction = new QAction("Edit patient", this);

    contextMenu->addAction(deleteAction);
    contextMenu->addAction(editAction);

    connect(deleteAction, &QAction::triggered, this, &PatientMonitor::onDeletePatient);
    connect(editAction, &QAction::triggered, this, &PatientMonitor::onEditPatient);
    connect(ui->patientTable, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));
    ui->patientTable->setContextMenuPolicy(Qt::CustomContextMenu);


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


void PatientMonitor::onDeletePatient() {
    QList<QTableWidgetItem *> selectedItems = ui->patientTable->selectedItems();

    if (!selectedItems.isEmpty()) {
        int row = selectedItems.first()->row();
        patients.erase(patients.begin() + row);

        for(int i = ui->patientTable->rowCount()-1; i >= 0; i--) {
            ui->patientTable->removeRow(i);
        }

        QTableWidgetItem* newPatientInfo = NULL;
        for (int i = 0; i < (int)(patients.size()); i++) {
            ui->patientTable->insertRow(i);
            patients[i].setNum(i+1);
            newPatientInfo = new QTableWidgetItem(QString::number(patients[i].getNum()));
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
    checkIfEmpty();
}

void PatientMonitor::onEditPatient() {
    QList<QTableWidgetItem *> selectedItems = ui->patientTable->selectedItems();

    if (!selectedItems.isEmpty()) {
        int row = selectedItems.first()->row();
        patientInfo selectedPatient = patients.at(row);

        EditPatient editPatientDialog(this, &selectedPatient);
        connect(&editPatientDialog, &QDialog::accepted, this, [=, &editPatientDialog]() {
            onPatientChanged(editPatientDialog.getEditedPatient());
        });
        editPatientDialog.exec();
    }
}

void PatientMonitor::onPatientChanged(patientInfo* editedPatient) {

    QTableWidgetItem* newPatientInfo = NULL;

    QList<QTableWidgetItem *> selectedItems = ui->patientTable->selectedItems();

    if (!selectedItems.isEmpty()) {
        int row = selectedItems.first()->row();
        patients.at(row) = *editedPatient;
    }

    for (int i =0; i < (int)(patients.size()); i++) {
        newPatientInfo = new QTableWidgetItem(QString::number(patients[i].getNum()));
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

void PatientMonitor::showContextMenu(const QPoint& pos) {
    QTableWidgetItem* item = ui->patientTable->itemAt(pos);

    if (item) {
        QPoint globalPos = ui->patientTable->mapToGlobal(pos);
        contextMenu->exec(globalPos);
    }
}


//функція для зчитування з таблиці пацієнтів з файлу (ліве бокове меню програми)
void PatientMonitor::on_scanButton_clicked()
{
    //відкриваєтсья діалогове вікно, щоб обрати файли
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Text File"), QDir::homePath(), tr("Text Files (*.txt)"));

    std::ifstream inputData(fileName.toStdString());

    //якщо файл не вдається відкрити або шлях передано неправильно
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
    } else {
        for (int i = ui->patientTable->rowCount() - 1; i >= 0; i--) {
            ui->patientTable->removeRow(i);
        }
        patients.clear();

        patientNum = 0;
        //запис пацієнтів
        patientInfo patient;
        while (inputData >> patient) {
            onPatientAdded(patient);
        }
        inputData.close();

        backUpVector = patients;
        vectorToPrint = patients;
        patientNum = patients.size();
    }
}

//функція для зчитування таблиці пацієнтів з файлу (кнопка всередині таблиці, якщо таблиця пуста)
void PatientMonitor::onScanTableButtonClick() {
    on_scanButton_clicked();
}

//функція виклику діалогового вікна для додавання нового пацієнта
void PatientMonitor::on_addButton_clicked()
{
    addPatientDialog addPatientDialog(this);
    connect(&addPatientDialog, &addPatientDialog::patientAdded, this, &PatientMonitor::onPatientAdded);
    addPatientDialog.exec();
}



//функція обробки введених даних про нового пацієнта і додавання його у таблицю
void PatientMonitor::onPatientAdded(patientInfo &patient)
{
    patientNum += 1;
    patient.setNum(patientNum);
    patients.push_back(patient);
    int rows = ui->patientTable->rowCount();

    ui->patientTable->insertRow(rows);

    QTableWidgetItem* newPatientInfo = new QTableWidgetItem(QString::number(patient.getNum()));
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
// функція швидкого сортування для класу patientInfo за артеріальним тиском
void PatientMonitor::pressureQuickSort(std::vector<patientInfo> &patients, int low, int high) {
    if (low < high) {
        int pivotIndex = pressurePartition(patients, low, high);
        pressureQuickSort(patients, low, pivotIndex - 1);
        pressureQuickSort(patients, pivotIndex + 1, high);
    }
}
//функція ділення масиву на частини для швидкого сортування за артеріальним тиском
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
//функція швидкого сортування для класу patientInfo за пульсом
void PatientMonitor::heartRateQuickSort(std::vector<patientInfo> &patients, int low, int high) {
    if (low < high) {
        int pivotIndex = heartRatepressurepartition(patients, low, high);
        heartRateQuickSort(patients, low, pivotIndex - 1);
        heartRateQuickSort(patients, pivotIndex + 1, high);
    }
}
//функція ділення масиву на частини для швидкого сортування за пульсом
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
//функція, що сортує пацієнтів за артеріальним тиском та виводить
// відсортований список пацієнтів у таблицю
void PatientMonitor::on_bloodPressureSort_clicked()
{
    if (patients.size() == 0) {
        operatingError();
    } else {
    std::vector<patientInfo> patientsToOperate = patients;

    pressureQuickSort(patientsToOperate, 0, patientsToOperate.size() - 1);
    vectorToPrint = patientsToOperate;

    for(int i = 0; i < vectorToPrint.size(); i++) {
        vectorToPrint[i].setNum(i+1);
        patientsToOperate[i].setNum(i+1);
    }

    ui->patientTable->clear();

    QTableWidgetItem* newPatientInfo = NULL;

    for (int i =0; i < (int)(patients.size()); i++) {
        newPatientInfo = new QTableWidgetItem(QString::number(patientsToOperate[i].getNum()));
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

//функція для перевірки, чи таблиця пуста:
//якщо так, вивести кнопку сканування у таблицю
void PatientMonitor::checkIfEmpty() {
    if(ui->patientTable->rowCount() > 0) {
        ui->scanTableButton->setVisible(false);
    } else {
        ui->scanTableButton->setVisible(true);
    }
}
//функція для групування пацієнтів за групою крові та резус-фактором
void PatientMonitor::on_bloodTypeGroupButton_clicked()
{
    //перевірка, чи таблиця не пуста
    if (patients.size() == 0) {
        operatingError();
    } else {
    //створення структур даних для зберігання груп пацієнтів
    std::vector<patientInfo> firstTB;
    std::vector<patientInfo> secondTB;
    std::vector<patientInfo> thirdTB;
    std::vector<patientInfo> fourthTB;

    std::vector<patientInfo> rhP;
    std::vector<patientInfo> rhM;

    std::string currentBT;
    std::string currentRH;

    //відбір пацієнтів за резус-фактором
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
    //відбір пацієнтів за групою крові
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

    vectorToPrint = mergedVector;

    for(int i = 0; i < vectorToPrint.size(); i++) {
        vectorToPrint[i].setNum(i+1);
        mergedVector[i].setNum(i+1);
    }

    QTableWidgetItem* newPatientInfo = NULL;

    ui->patientTable->clear();

    //вивід на екран
    for (int i = 0; i < (int)(mergedVector.size()); i++) {
        newPatientInfo = new QTableWidgetItem(QString::number(mergedVector[i].getNum()));
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

//функція для групування пацієнтів за резус-фактором
//та сортування за показниками пульсу
void PatientMonitor::on_rhGroupHrSort_clicked()
{
    if (patients.size() == 0) {
        operatingError();
    } else {
    std::vector<patientInfo> rhP;
    std::vector<patientInfo> rhM;

    std::string currentRH;

    //відбір за резус-фактором
    for (int i = 0; i < (int)(patients.size()); i++) {
        currentRH = patients[i].getRhFactor();
        if(currentRH == "+")
            rhP.push_back(patients[i]);
        if(currentRH == "-")
            rhM.push_back(patients[i]);
    }

    //сортування кожної групи за показниками пульсу
    heartRateQuickSort(rhP, 0, rhP.size() - 1);
    heartRateQuickSort(rhM, 0, rhM.size() - 1);


    std::vector<patientInfo> groupedPatients;
    groupedPatients.insert(groupedPatients.end(), rhP.begin(), rhP.end());
    groupedPatients.insert(groupedPatients.end(), rhM.begin(), rhM.end());

    rhP.clear();
    rhM.clear();

    vectorToPrint = groupedPatients;

    for(int i = 0; i < vectorToPrint.size(); i++) {
        vectorToPrint[i].setNum(i+1);
        groupedPatients[i].setNum(i+1);
    }

    QTableWidgetItem* newPatientInfo = NULL;

    ui->patientTable->clear();

    //вивід на екран
    for (int i = 0; i < (int)(groupedPatients.size()); i++) {
        newPatientInfo = new QTableWidgetItem(QString::number(groupedPatients[i].getNum()));
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

//функція, що викликає діалогове вікно для подальшої
//перевірки, чи показники пульсу та артеріального тиску завищені
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

//функція, що обробляє введений користувачем вік для перевірки
void PatientMonitor::handleAgeSet(const int &age) {
    int flagChecker = 0;

    //перевірка, чи є пацієнти вказаного віку
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
        hyperTTachyC.clear();
        //очищення таблиці
        for (int i = (int)(patients.size()); i >= 0; i--) {
            ui->patientTable->removeRow(i);
        }

        //перевірка показників пульсу та артеріального тиску за вказаним віком
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

        for (int i = 0; i < (int)(hyperTTachyC.size());i++) {
        if (age >= 0 && age <= 5) {
            if ((hyperTTachyC[i].getUpPressure() >= 80 && hyperTTachyC[i].getUpPressure() <= 110 ) &&
                (hyperTTachyC[i].getLowPressure() >= 55 && hyperTTachyC[i].getLowPressure() <= 80 )) {
                hyperTTachyC.erase(hyperTTachyC.begin() + i);
            }
        } else if (age >= 6 && age <= 13) {
            if ((hyperTTachyC[i].getUpPressure() >= 90 && hyperTTachyC[i].getUpPressure() <= 115 ) &&
                (hyperTTachyC[i].getLowPressure() >= 60 && hyperTTachyC[i].getLowPressure() <= 80 )) {
                hyperTTachyC.erase(hyperTTachyC.begin() + i);
            }
        }
        else if (age >= 14 && age <= 49) {
            if ((hyperTTachyC[i].getUpPressure() >= 110 && hyperTTachyC[i].getUpPressure() <= 140 ) &&
                (hyperTTachyC[i].getLowPressure() >= 77 && hyperTTachyC[i].getLowPressure() <= 85 )) {
                hyperTTachyC.erase(hyperTTachyC.begin() + i);
            }
        } else {
            if ((hyperTTachyC[i].getUpPressure() >= 115 && hyperTTachyC[i].getUpPressure() <= 150 ) &&
                (hyperTTachyC[i].getLowPressure() >= 80 && hyperTTachyC[i].getLowPressure() <= 90 )) {
                hyperTTachyC.erase(hyperTTachyC.begin() + i);
            }
        }
    }

    vectorToPrint = hyperTTachyC;
    patients = hyperTTachyC;

    for(int i = 0; i < vectorToPrint.size(); i++) {
        vectorToPrint[i].setNum(i+1);
        hyperTTachyC[i].setNum(i+1);
    }

    QTableWidgetItem* newPatientInfo = NULL;

    //вивід таблиці на екран
    for (int i = 0; i < (int)(hyperTTachyC.size()); i++) {
        ui->patientTable->insertRow(i);

        newPatientInfo = new QTableWidgetItem(QString::number(hyperTTachyC[i].getNum()));
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

//функція відміни здійснених операцій над таблицею
void PatientMonitor::on_actionCancel_action_triggered()
{
    if (backUpVector.size() == 0) {
        operatingError();
    } else {
        for (int i = ui->patientTable->rowCount(); i >= 0; i--) {
        ui->patientTable->removeRow(i);
    }

    QTableWidgetItem* newPatientInfo = NULL;


    for (int i = 0; i < (int)(backUpVector.size()); i++) {
    ui->patientTable->insertRow(i);

        newPatientInfo = new QTableWidgetItem(QString::number(backUpVector[i].getNum()));
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

    //відновлення початкової зчитаної таблиці
    patients = backUpVector;
    vectorToPrint = patients;
    }

    checkIfEmpty();
}

//функція для закриття програми
void PatientMonitor::on_actionExit_triggered()
{
    close();
}


//функція для запису таблиці у файл
void PatientMonitor::on_writeButton_clicked()
{
    if (patients.size() == 0) {
    operatingError();
    } else {
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save Patient Data"), "", tr("Text Files (*.txt);;All Files (*)"));

    if (!filePath.isEmpty()) {
    std::ofstream patientOutputFile(filePath.toStdString());

    // Check if the file can be opened
    if (patientOutputFile.is_open()) {
            for (const auto& patient : vectorToPrint) {
                patientOutputFile << patient << "\n";
            }

            patientOutputFile.close();
    } else {
            QMessageBox mb("PatientMonitor",
                           "Error opening file",
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
            mb.exec();;
    }
    }
    }
}

//функція для виділення усього рядка
void PatientMonitor::onItemClicked(QTableWidgetItem *item) {
    if (item != nullptr) {
    int row = item->row();

    ui->patientTable->clearSelection();

    for (int col = 0; col < ui->patientTable->columnCount(); ++col) {
        ui->patientTable->item(row, col)->setSelected(true);
    }
    }
}

//функція для перевірки, чи здорові пацієнти (за показниками артеріального тиску)
void PatientMonitor::on_normPressureCheckButton_clicked()
{
    //перевірка, чи таблиця не пуста
    if(patients.size() == 0) {
        operatingError();
    } else {

    //оскільки не пуста, очищуємо її від початкових значень
    healthyPatientsList.clear();

        int age = 0;
        //перевірка тиску кожного пацієнта за його віком
        for (int i = 0; i < (int)(patients.size()); i++) {
            age = patients[i].getAge();
            if (age >= 0 && age <= 5) {
                if ((patients[i].getUpPressure() >= 80 && patients[i].getUpPressure() <= 110 ) &&
                    (patients[i].getLowPressure() >= 55 && patients[i].getLowPressure() <= 80 )) {
                    healthyPatientsList.push_back(patients[i]);
                }
            } else if (age >= 6 && age <= 13) {
                if ((patients[i].getUpPressure() >= 90 && patients[i].getUpPressure() <= 115 ) &&
                    (patients[i].getLowPressure() >= 60 && patients[i].getLowPressure() <= 80 )) {
                    healthyPatientsList.push_back(patients[i]);
                }
            }
            else if (age >= 14 && age <= 49) {
                if ((patients[i].getUpPressure() >= 110 && patients[i].getUpPressure() <= 140 ) &&
                    (patients[i].getLowPressure() >= 77 && patients[i].getLowPressure() <= 85 )) {
                    healthyPatientsList.push_back(patients[i]);
                }
            } else {
                if ((patients[i].getUpPressure() >= 115 && patients[i].getUpPressure() <= 150 ) &&
                    (patients[i].getLowPressure() >= 80 && patients[i].getLowPressure() <= 90 )) {
                    healthyPatientsList.push_back(patients[i]);
                }
            }
        }

        if(healthyPatientsList.empty()) {
            operatingError();
        } else {

        for (int i = 0; i < healthyPatientsList.size() - 1; i++) {
            for (int j = 0; j < healthyPatientsList.size() - i - 1; j++) {
                if (healthyPatientsList[j].getSurname() > healthyPatientsList[j + 1].getSurname()) {
                    std::swap(healthyPatientsList[j], healthyPatientsList[j + 1]);
                }
            }
        }

    healthyPatients* healthyPatientsWindow = new healthyPatients(this);
    connect(this, &PatientMonitor::sentPatients, healthyPatientsWindow, healthyPatients::receivePatientList);
    emit sentPatients(healthyPatientsList);
    healthyPatientsWindow->show();
    }
    }
}

//функція для виклику вікна для перегляду донорів
void PatientMonitor::on_donorCheckButton_clicked()
{
    if (patients.size() == 0) {
        operatingError();
    } else {
            donorsTable* donorsTableWindow = new donorsTable(this);
            connect(this, &PatientMonitor::sentPatients, donorsTableWindow, &donorsTable::receivePatientList);
            emit sentPatients(vectorToPrint);
            donorsTableWindow->show();
    }
}

//функція для опису помилки користувачеві
//[за пустої таблиці жодна з функцій, які маніплюють таблицею виконуватися не може]
void PatientMonitor::operatingError() {
    QMessageBox mb("PatientMonitor",
                   "Patient list is empty",
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
}

//функція для виводу таблиці на друк
void PatientMonitor::on_actionPrint_triggered()
{
    if (patients.size() == 0) {
            operatingError();
    } else {
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
}


