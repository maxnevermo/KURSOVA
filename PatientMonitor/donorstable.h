#ifndef DONORSTABLE_H
#define DONORSTABLE_H

//вікно для відображення таблиці донорів та реципієнтів

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QGraphicsDropShadowEffect>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QBrush>
#include <algorithm>
#include <QFile>
#include <fstream>
#include <QFileDialog>
#include <QTextStream>

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

    void on_actionExit_triggered();

    void on_actionWrite_triggered();

private:
    Ui::donorsTable *ui;
};

#endif // DONORSTABLE_H
