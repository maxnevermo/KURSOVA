#ifndef DONORSTABLE_H
#define DONORSTABLE_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QGraphicsDropShadowEffect>

#include "patientinfo.h"

namespace Ui {
class donorsTable;
}

class donorsTable : public QMainWindow
{
    Q_OBJECT

public:
    explicit donorsTable(QWidget *parent = nullptr);
    ~donorsTable();

    void onItemClicked(QTableWidgetItem *item);

public slots:
    void receivePatientList(const std::vector<patientInfo> &patients);

private slots:
    void on_universalButton_clicked();

    void on_generalButton_clicked();

private:
    Ui::donorsTable *ui;
};

#endif // DONORSTABLE_H
