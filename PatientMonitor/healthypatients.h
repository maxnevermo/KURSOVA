#ifndef HEALTHYPATIENTS_H
#define HEALTHYPATIENTS_H

#include <QMainWindow>
#include <QGraphicsDropShadowEffect>

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

private:
    Ui::healthyPatients *ui;
};

#endif // HEALTHYPATIENTS_H
