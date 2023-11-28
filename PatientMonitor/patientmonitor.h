#ifndef PATIENTMONITOR_H
#define PATIENTMONITOR_H

#include <QMainWindow>
#include <QGraphicsDropShadowEffect>
#include <QFileDialog>
#include <QPixmap>
#include <QTableWidgetItem>
#include <fstream>
#include <codecvt>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>

#include "addpatientdialog.h"
#include "patientinfo.h"
#include "ageinputdialog.h"
#include "donorstable.h"


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

    void onItemClicked(QTableWidgetItem *item);

    void operatingError();

public slots:
    void onPatientAdded(const patientInfo &patient);
    void handleAgeSet(const int &age);

private slots:
    void on_scanButton_clicked();
    void on_addButton_clicked();
    void on_bloodPressureSort_clicked();

    void on_bloodTypeGroupButton_clicked();

    void on_rhGroupHrSort_clicked();

    void on_agePulseCheckButton_clicked();

    void on_actionCancel_action_triggered();

    void on_actionExit_triggered();

    void on_writeButton_clicked();

    void on_normPressureCheckButton_clicked();

    void on_donorCheckButton_clicked();

    void on_actionPrint_triggered();

signals:
    void sentPatients(const std::vector<patientInfo> &patients);

private:
    Ui::PatientMonitor *ui;
};
#endif // PATIENTMONITORING_H
