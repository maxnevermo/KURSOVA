#include "donorstable.h"
#include "ui_donorstable.h"

std::vector<patientInfo> universalDonors;
std::vector<patientInfo> universalRecipients;

std::vector<patientInfo> gotPatients;

std::vector<patientInfo> Idonors;
std::vector<patientInfo> IIdonors;
std::vector<patientInfo> IIIdonors;
std::vector<patientInfo> IVdonors;

std::vector<patientInfo> Irecipients;
std::vector<patientInfo> IIrecipients;
std::vector<patientInfo> IIIrecipients;
std::vector<patientInfo> IVrecipients;


donorsTable::donorsTable(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::donorsTable)
{
    ui->setupUi(this);
    setWindowTitle("Donors");

    ui->donRepTable->setShowGrid(false);
    ui->donRepTable->verticalHeader()->setVisible(false);
    ui->donRepTable->horizontalHeader()->setVisible(false);

    ui->donRepTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->donRepTable->setSelectionMode(QAbstractItemView::NoSelection);

    ui->donRepTable->setSelectionMode(QAbstractItemView::MultiSelection);
    connect(ui->donRepTable, &QTableWidget::itemClicked, this, &donorsTable::onItemClicked);

    ui->donRepTable->setFocusPolicy(Qt::NoFocus);

    ui->donRepTable->setColumnCount(2);

    QGraphicsDropShadowEffect *shadowEffectUniButton = new QGraphicsDropShadowEffect();
    shadowEffectUniButton->setBlurRadius(20);
    shadowEffectUniButton->setXOffset(0);
    shadowEffectUniButton->setColor(QColor(0, 0, 0, 30));

    QGraphicsDropShadowEffect *shadowEffectGeneralButton = new QGraphicsDropShadowEffect();
    shadowEffectGeneralButton->setBlurRadius(20);
    shadowEffectGeneralButton->setXOffset(0);
    shadowEffectGeneralButton->setColor(QColor(0, 0, 0, 30));

    QGraphicsDropShadowEffect *shadowEffectTableSheet = new QGraphicsDropShadowEffect();
    shadowEffectTableSheet->setBlurRadius(20);
    shadowEffectTableSheet->setXOffset(0);
    shadowEffectTableSheet->setColor(QColor(0, 0, 0, 30));

    ui->universalButton->setGraphicsEffect(shadowEffectUniButton);
    ui->generalButton->setGraphicsEffect(shadowEffectGeneralButton);
    ui->donRepTable->setGraphicsEffect(shadowEffectTableSheet);
}

donorsTable::~donorsTable()
{
    delete ui;
}

void donorsTable::receivePatientList(const std::vector<patientInfo> &patients) {
    gotPatients = patients;
}


void donorsTable::on_universalButton_clicked()
{
    move(690, 314);

    universalDonors.clear();
    universalRecipients.clear();

    for(int i = 0; i < (int)(gotPatients.size()); i++) {
        if(gotPatients[i].getBloodType() == "I"){
            universalDonors.push_back(gotPatients[i]);
        } else if (gotPatients[i].getBloodType() == "IV") {
            universalRecipients.push_back(gotPatients[i]);
        } else {
            continue;
        }
    }

    for(int i = ui->donRepTable->rowCount()-1; i >= 0; i--) {
        ui->donRepTable->removeRow(i);
    }

    if((int)(universalDonors.size())>(int)(universalRecipients.size())) {
        ui->donRepTable->setRowCount((int)(universalDonors.size()));
    } else {
        ui->donRepTable->setRowCount((int)(universalRecipients.size()));
    }

    QTableWidgetItem* patientInfo = nullptr;
    for(int i = 0; i < (int)(universalDonors.size()); i++) {
        patientInfo = new QTableWidgetItem(QString::fromStdString(universalDonors[i].getSurname()));
        ui->donRepTable->setItem(i, 0, patientInfo);
    }

    for(int i = 0; i < (int)(universalRecipients.size()); i++) {
        patientInfo = new QTableWidgetItem(QString::fromStdString(universalRecipients[i].getSurname()));
        ui->donRepTable->setItem(i, 1, patientInfo);
    }

    ui->donRepTable->setColumnWidth(0, 230);
    ui->donRepTable->setColumnWidth(1, 230);

    resize(540, 420);
    ui->donRepTable->resize(460, 230);
}

void donorsTable::onItemClicked(QTableWidgetItem *item) {
    if (item != nullptr) {
        int row = item->row();

        if (row >= 0 && row < ui->donRepTable->rowCount()) {
            ui->donRepTable->clearSelection();

            for (int col = 0; col < ui->donRepTable->columnCount(); ++col) {
                QTableWidgetItem* tableItem = ui->donRepTable->item(row, col);
                if (tableItem) {
                    tableItem->setSelected(true);
                }
            }
        }
    }
}


void donorsTable::on_generalButton_clicked()
{
    move(690, 100);

    Idonors.clear();
    IIdonors.clear();
    IIIdonors.clear();
    IVdonors.clear();

    Irecipients.clear();
    IIrecipients.clear();
    IIIrecipients.clear();
    IVrecipients.clear();

    for(int i = ui->donRepTable->rowCount()-1; i >= 0; i--) {
        ui->donRepTable->removeRow(i);
    }

    for(int i = 0; i < (int)(gotPatients.size()); i++) {
        if (gotPatients[i].getBloodType() == "I") {
            Idonors.push_back(gotPatients[i]);
            IIdonors.push_back(gotPatients[i]);
            IIIdonors.push_back(gotPatients[i]);
            IVdonors.push_back(gotPatients[i]);

            Irecipients.push_back(gotPatients[i]);
        } else if(gotPatients[i].getBloodType() == "II") {
            IIdonors.push_back(gotPatients[i]);
            IVdonors.push_back(gotPatients[i]);

            Irecipients.push_back(gotPatients[i]);
            IIrecipients.push_back(gotPatients[i]);
        } else if(gotPatients[i].getBloodType() == "III") {
            IIIdonors.push_back(gotPatients[i]);
            IVdonors.push_back(gotPatients[i]);

            Irecipients.push_back(gotPatients[i]);
            IIIrecipients.push_back(gotPatients[i]);
        } else {
            IVdonors.push_back(gotPatients[i]);

            Irecipients.push_back(gotPatients[i]);
            IIrecipients.push_back(gotPatients[i]);
            IIIrecipients.push_back(gotPatients[i]);
            IVrecipients.push_back(gotPatients[i]);
        }
    }

    int countOfRecipients = Irecipients.size() + IIrecipients.size() + IIIrecipients.size() + IVrecipients.size();
    int countOfDonors = Idonors.size() + IIdonors.size() + IIIdonors.size() + IVdonors.size();

    if (countOfDonors > countOfRecipients) {
        ui->donRepTable->setRowCount(countOfDonors);
    } else {
        ui->donRepTable->setRowCount(countOfRecipients);
    }

    ui->donRepTable->setColumnWidth(0, 220);
    ui->donRepTable->setColumnWidth(1, 220);

    for(int i = 0; i < ui->donRepTable->rowCount()-1; i++) {
        ui->donRepTable->setRowHeight(i, 20);
    }
    resize(540, 20*(ui->donRepTable->rowCount()+8) + 155);
    ui->donRepTable->resize(460, 20*(ui->donRepTable->rowCount()+8));

    QStringList headers = {"I blood type", "II blood type", "III blood type", "IV blood type"};

    QTableWidgetItem* tableInfo = new QTableWidgetItem(headers.at(0));
    tableInfo->setTextAlignment(Qt::AlignCenter);
    ui->donRepTable->setItem(0,0, tableInfo);

    int counter = 0;

    for (counter = 0; counter < (int)(Idonors.size()); counter ++) {
        tableInfo = new QTableWidgetItem(QString::fromStdString(Idonors[counter].getSurname()));
        tableInfo->setTextAlignment(Qt::AlignCenter);
        ui->donRepTable->setItem(counter+2,0, tableInfo);
    }

    for (counter = 0; counter < (int)(Irecipients.size()); counter ++) {
        tableInfo = new QTableWidgetItem(QString::fromStdString(Irecipients[counter].getSurname()));
        tableInfo->setTextAlignment(Qt::AlignCenter);
        ui->donRepTable->setItem(counter+2,1, tableInfo);
    }

    tableInfo = new QTableWidgetItem(headers.at(1));
    tableInfo->setTextAlignment(Qt::AlignCenter);
    ui->donRepTable->setItem(counter+3,0, tableInfo);
}

