#include "patientmonitoring.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PatientMonitoring w;
    w.show();
    return a.exec();
}
