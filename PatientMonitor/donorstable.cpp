#include "donorstable.h"
#include "ui_donorstable.h"


//вектори для зберігання донорів та реципієнтів
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

    ui->donRepTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->donRepTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

donorsTable::~donorsTable()
{
    delete ui;
}

void donorsTable::receivePatientList(const std::vector<patientInfo> &patients) {
    //зчитування переданих з головного вікна пацієнтів
    gotPatients = patients;
}


void donorsTable::on_universalButton_clicked()
{
    move(690, 314);

    ui->universalButton->move(10, 10);
    ui->generalButton->move(260, 10);
    ui->label->move(100, 50);

    ui->donRepTable->setColumnCount(2);

    ui->donRepTable->setColumnWidth(0, 230);
    ui->donRepTable->setColumnWidth(1, 230);

    resize(540, 420);
    ui->donRepTable->resize(460, 230);

    universalDonors.clear();
    universalRecipients.clear();

    //відбір універсальних донорів та універсальних реципієнтів
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

    //виведення інформації у таблицю
    QTableWidgetItem* patientInfo = nullptr;
    for(int i = 0; i < (int)(universalDonors.size()); i++) {
        patientInfo = new QTableWidgetItem(QString::fromStdString(universalDonors[i].getSurname()));
        ui->donRepTable->setItem(i, 0, patientInfo);
    }

    for(int i = 0; i < (int)(universalRecipients.size()); i++) {
        patientInfo = new QTableWidgetItem(QString::fromStdString(universalRecipients[i].getSurname()));
        ui->donRepTable->setItem(i, 1, patientInfo);
    }
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
    move(480, 30);

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

    //відбір на донорів і реципієнтів згідно з групами крові пацієнтів
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

    //визначення оптимальної кількості рядків для таблиці
    int countOfRecipientsIandIII = Irecipients.size() + IIIrecipients.size();
    int countOfRecipientsIIandIV = IIrecipients.size() + IVrecipients.size();

    int countOfDonorsIandIII = Idonors.size() + IIIdonors.size();
    int countOfDonorsIIandIV =  IIdonors.size() + IVdonors.size();

    ui->donRepTable->setRowCount(std::max({countOfRecipientsIandIII, countOfRecipientsIIandIV}) + std::max({countOfDonorsIandIII, countOfDonorsIIandIV}));

    ui->donRepTable->setColumnCount(4);
    ui->donRepTable->setColumnWidth(0, 220);
    ui->donRepTable->setColumnWidth(1, 220);
    ui->donRepTable->setColumnWidth(2, 220);
    ui->donRepTable->setColumnWidth(3, 223);

    for(int i = 0; i < ui->donRepTable->rowCount()-1; i++) {
        ui->donRepTable->setRowHeight(i, 15);
    }
    resize(962, 1000);
    ui->donRepTable->resize(882, 820);

    ui->universalButton->move(221, 10);
    ui->generalButton->move(471, 10);
    ui->label->move(311, 50);

    QStringList headers = {"I blood type", "II blood type", "III blood type", "IV blood type"};

    //вивід донорів та реципієнтів на екран
    QTableWidgetItem* tableInfo = new QTableWidgetItem(headers.at(0));
    ui->donRepTable->setSpan(0, 0, 1, 2);
    tableInfo->setTextAlignment(Qt::AlignCenter);
    ui->donRepTable->setItem(0,0, tableInfo);

    int counterI = 0;
    int counterII = 0;

    while(counterI < (int)(Idonors.size())) {
        tableInfo = new QTableWidgetItem(QString::fromStdString(Idonors[counterI].getSurname()));
        tableInfo->setTextAlignment(Qt::AlignCenter);
        ui->donRepTable->setItem(counterI+2,0, tableInfo);
        counterI++;
    }

    counterI = 0;

    while(counterI < (int)(Irecipients.size())) {
        tableInfo = new QTableWidgetItem(QString::fromStdString(Irecipients[counterI].getSurname()));
        tableInfo->setTextAlignment(Qt::AlignCenter);
        ui->donRepTable->setItem(counterI+2,1, tableInfo);
        counterI++;
    }

    tableInfo = new QTableWidgetItem(headers.at(1));
    tableInfo->setTextAlignment(Qt::AlignCenter);
    ui->donRepTable->setSpan(counterI+2, 0, 1, 2);
    ui->donRepTable->setItem(counterI+2,0, tableInfo);

    int posToAlign = counterI+2;

    while(counterII < (int)(IIdonors.size())) {
        tableInfo = new QTableWidgetItem(QString::fromStdString(IIdonors[counterII].getSurname()));
        tableInfo->setTextAlignment(Qt::AlignCenter);
        ui->donRepTable->setItem(counterI+4+counterII,0, tableInfo);
        counterII++;
    }

    counterII = 0;

    while(counterII < (int)(IIrecipients.size())) {
        tableInfo = new QTableWidgetItem(QString::fromStdString(IIrecipients[counterII].getSurname()));
        tableInfo->setTextAlignment(Qt::AlignCenter);
        ui->donRepTable->setItem(counterI+4+counterII,1, tableInfo);
        counterII++;
    }



    tableInfo = new QTableWidgetItem(headers.at(2));
    tableInfo->setTextAlignment(Qt::AlignCenter);
    ui->donRepTable->setSpan(0, 2, 1, 2);
    ui->donRepTable->setItem(0,2, tableInfo);

    counterI = 0;

    while(counterI < (int)(IIIdonors.size())) {
        tableInfo = new QTableWidgetItem(QString::fromStdString(IIIdonors[counterI].getSurname()));
        tableInfo->setTextAlignment(Qt::AlignCenter);
        ui->donRepTable->setItem(counterI+2,2, tableInfo);
        counterI++;
    }

    counterI = 0;

    while(counterI < (int)(IIIrecipients.size())) {
        tableInfo = new QTableWidgetItem(QString::fromStdString(IIIrecipients[counterI].getSurname()));
        tableInfo->setTextAlignment(Qt::AlignCenter);
        ui->donRepTable->setItem(counterI+2,3, tableInfo);
        counterI++;
    }

    counterII = 0;

    tableInfo = new QTableWidgetItem(headers.at(3));
    tableInfo->setTextAlignment(Qt::AlignCenter);
    ui->donRepTable->setSpan(posToAlign, 2, 1, 2);
    ui->donRepTable->setItem(posToAlign,2, tableInfo);

    while(counterII < (int)(IVdonors.size())) {
        tableInfo = new QTableWidgetItem(QString::fromStdString(IVdonors[counterII].getSurname()));
        tableInfo->setTextAlignment(Qt::AlignCenter);
        ui->donRepTable->setItem(posToAlign+2+counterII,2, tableInfo);
        counterII++;
    }

    counterII = 0;

    while(counterII < (int)(IVrecipients.size())) {
        tableInfo = new QTableWidgetItem(QString::fromStdString(IVrecipients[counterII].getSurname()));
        tableInfo->setTextAlignment(Qt::AlignCenter);
        ui->donRepTable->setItem(posToAlign+2+counterII,3, tableInfo);
        counterII++;
    }
}

void donorsTable::on_actionExit_triggered()
{
    close();
}

//функція для запису донорів та реципієнтів у файл
void donorsTable::on_actionWrite_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Text File"), QDir::homePath(), tr("Text Files (*.txt)"));

    std::ofstream patientOutputFile(fileName.toStdString());
    QFile file(fileName);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out.setFieldWidth(0);

        for (int row = 0; row < ui->donRepTable->rowCount(); ++row) {
            for (int col = 0; col < ui->donRepTable->columnCount(); ++col) {
                QTableWidgetItem *item = ui->donRepTable->item(row, col);
                if (item) {
                    if (item->text() == "I blood type" || item->text() == "II blood type"
                        || item->text() == "III blood type" || item->text() == "IV blood type") {
                        out << qSetFieldWidth(40) << item->text();
                    } else {
                        out << qSetFieldWidth(20) << item->text() << "\t";
                    }
                } else {
                    out << qSetFieldWidth(20) << " " << "\t";
                }
            }
            out.setFieldWidth(0);
            out << "\n";
        }
        file.close();
    }
}
