#ifndef PATIENTMONITORING_H
#define PATIENTMONITORING_H

#include <QMainWindow>
#include <QGraphicsDropShadowEffect>
#include <QFileDialog>
#include <QPixmap>
#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui { class PatientMonitoring; }
QT_END_NAMESPACE

class PatientMonitoring : public QMainWindow
{
    Q_OBJECT

public:
    PatientMonitoring(QWidget *parent = nullptr);
    ~PatientMonitoring();

    void onScanTableButtonClick();

private slots:
    void on_scanButton_clicked();

private:
    Ui::PatientMonitoring *ui;
};
#endif // PATIENTMONITORING_H
