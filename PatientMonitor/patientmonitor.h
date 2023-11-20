#ifndef PATIENTMONITOR_H
#define PATIENTMONITOR_H

#include <QMainWindow>
#include <QGraphicsDropShadowEffect>
#include <QFileDialog>
#include <QPixmap>
#include <fstream>
#include <locale>
#include <codecvt>

#include "addpatientdialog.h"
#include "patientinfo.h"


QT_BEGIN_NAMESPACE
namespace Ui { class PatientMonitor; }
QT_END_NAMESPACE

class PatientMonitor : public QMainWindow
{
    Q_OBJECT

public:
    PatientMonitor(QWidget *parent = nullptr);
    ~PatientMonitor();

    void onScanTableButtonClick();
    void checkIfEmpty();

    void pressureQuickSort(std::vector<patientInfo> &patients, int low, int high);
    void heartRateQuickSort(std::vector<patientInfo> &patients, int low, int high);

    int pressurePartition(std::vector<patientInfo> &patients, int low, int high);
    int heartRatepressurepartition(std::vector<patientInfo> &patients, int low, int high);

public slots:
    void onPatientAdded(const patientInfo &patient);

private slots:
    void on_scanButton_clicked();
    void on_addButton_clicked();
    void on_bloodPressureSort_clicked();

    void on_bloodTypeGroupButton_clicked();

    void on_rhGroupHrSort_clicked();

    void on_agePulseCheckButton_clicked();

private:
    Ui::PatientMonitor *ui;
};
#endif // PATIENTMONITORING_H
