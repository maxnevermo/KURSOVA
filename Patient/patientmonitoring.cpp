#include "patientmonitoring.h"
#include "patientinfo.h"
#include "ui_patientmonitoring.h"
#include <QVBoxLayout>

std::vector<patientInfo> patients;

PatientMonitoring::PatientMonitoring(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PatientMonitoring)
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

    if (ui->patientTable->rowCount() == 0) {
        QPushButton* scanTableButton = new QPushButton("Scan", ui->patientTable);

        int buttonWidth = 250;
        int buttonHeight = 50;
        int x = (ui->patientTable->width() - buttonWidth) / 2;
        int y = (ui->patientTable->height() - buttonHeight) / 2;
        scanTableButton->setGeometry(x, y, buttonWidth, buttonHeight);

        QGraphicsDropShadowEffect *shadowEffectScanTable = new QGraphicsDropShadowEffect();
        shadowEffectScanTable->setBlurRadius(20);
        shadowEffectScanTable->setXOffset(0);
        shadowEffectScanTable->setColor(QColor(0, 0, 0, 30));

        scanTableButton->setGraphicsEffect(shadowEffectScanTable);

        scanTableButton->setStyleSheet("QPushButton {"
                                       "background-color: #C6CCE8;"
                                        "color: #000000;"
                                        "border-radius: 0.5em;"
                                        "font-family: 'Gogh';"
                                       "font-weight: 500;"
                                       "font-size: 30px"
                                       "}"
                                       "QPushButton:hover {"
                                       "background-color: #A9B9E3;"
                                       "font-family: 'Gogh';"
                                       "font-weight: 500;"
                                       "font-size: 30px"
                                       "}");

        connect(scanTableButton, &QPushButton::clicked, this, &PatientMonitoring::onScanTableButtonClick);
    }

}

void PatientMonitoring::onScanTableButtonClick() {
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), QDir::homePath(), tr("All Files (*.*)"));

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


}

PatientMonitoring::~PatientMonitoring()
{
    delete ui;
}


void PatientMonitoring::on_scanButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"), QDir::homePath(), tr("All Files (*.*)"));

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
}

