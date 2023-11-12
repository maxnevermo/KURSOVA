#ifndef PATIENTMONITOR_H
#define PATIENTMONITOR_H

#include <QMainWindow>
#include <QGraphicsDropShadowEffect>
#include <QFileDialog>
#include <QPixmap>
#include <fstream>

#include "addpatientdialog.h"


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

public slots:
    void onPatientAdded(const patientInfo &patient);

private slots:
    void on_scanButton_clicked();

    void on_addButton_clicked();
private:
    Ui::PatientMonitor *ui;
};
#endif // PATIENTMONITORING_H
