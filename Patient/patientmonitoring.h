#ifndef PATIENTMONITORING_H
#define PATIENTMONITORING_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PatientMonitoring; }
QT_END_NAMESPACE

class PatientMonitoring : public QMainWindow
{
    Q_OBJECT

public:
    PatientMonitoring(QWidget *parent = nullptr);
    ~PatientMonitoring();

private:
    Ui::PatientMonitoring *ui;
};
#endif // PATIENTMONITORING_H
