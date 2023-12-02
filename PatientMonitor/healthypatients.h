#ifndef HEALTHYPATIENTS_H
#define HEALTHYPATIENTS_H

//вікно для відображення здорових пацієнтів

#include <QMainWindow>
#include <QGraphicsDropShadowEffect>
#include <fstream>
#include <QFileDialog>

#include "patientinfo.h"


namespace Ui {
class healthyPatients;
}

class healthyPatients : public QMainWindow
{
    Q_OBJECT

public slots:
    void receivePatientList(const std::vector<patientInfo> &patients);
public:
    explicit healthyPatients(QWidget *parent = nullptr);
    ~healthyPatients();

private slots:
    void on_actionWrite_to_file_triggered();

private:
    Ui::healthyPatients *ui;
};

#endif // HEALTHYPATIENTS_H
