#ifndef PATIENTMONITOR_H
#define PATIENTMONITOR_H

//головне вікно програми

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
#include "healthypatients.h"
#include "editpatient.h"
#include "pressuresortdialog.h"
#include "heartratesortdialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class PatientMonitor; }
QT_END_NAMESPACE

class PatientMonitor : public QMainWindow
{
    Q_OBJECT

public:

    std::vector<patientInfo> patients;
    std::vector<patientInfo> hyperTTachyC;
    std::vector<patientInfo> healthyPatientsList;
    std::vector<patientInfo> backUpVector;
    std::vector<patientInfo> vectorToPrint;

    PatientMonitor(QWidget *parent = nullptr);
    ~PatientMonitor();

    void onScanTableButtonClick();
    void checkIfEmpty();

    void pressureQuickSortUpper(std::vector<patientInfo> &patients, int low, int high, QString choiceForOrder);
    void pressureQuickSortLower(std::vector<patientInfo> &patients, int low, int high, QString choiceForOrder);
    void heartRateQuickSort(std::vector<patientInfo> &patients, int low, int high, QString choiceForOrder);

    int pressurePartitionUpper(std::vector<patientInfo> &patients, int low, int high, QString choice);
    int pressurePartitionLower(std::vector<patientInfo> &patients, int low, int high, QString choice);
    int heartRatepressurepartition(std::vector<patientInfo> &patients, int low, int high, QString choice);

    void onItemClicked(QTableWidgetItem *item);

    void operatingError();

public slots:
    void onPatientAdded(patientInfo &patient);
    void handleAgeSet(const int &age);
    void onPatientChanged(patientInfo* editedPatient);

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

    void showContextMenu(const QPoint& pos);
    void onDeletePatient();
    void onEditPatient();

    void handleSortButtonClicked(const QString& comboBox1Text, const QString& comboBox2Text);
    void handleSortButtonHR(const QString& comboBox1Text);


signals:
    void sentPatients(const std::vector<patientInfo> &patients);

private:
    QMenu *contextMenu;
    QAction *deleteAction;
    QAction *editAction;
    Ui::PatientMonitor *ui;
};
#endif // PATIENTMONITORING_H
