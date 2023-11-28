#include "patientmonitor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PatientMonitor w;

    QIcon icon("I:\\uni\\thirdsem\\course\\images\\logo.png");
    w.setWindowIcon(icon);

    w.show();
    return a.exec();
}
