#include "patientinfo.h"

patientInfo::patientInfo()
{
    this->m_num = 0;
    this->m_surname = "Undefined";
    this->m_age = 0;
    this->m_bloodType = 0;
    this->m_rhFactor = '/';
    this->m_upPressure = 0;
    this->m_lowPressure = 0;
    this->m_pulseValue = 0;

    QMessageBox mb("PatientMonitor",
                   "Error.\n\nInput data are incorrect\n(Probably, you didn't fill some fields)\nPlease, try again",
                   QMessageBox::NoIcon,
                   QMessageBox::Yes | QMessageBox::Default,
                   QMessageBox::NoButton,
                   QMessageBox::NoButton);
    QPixmap exportSuccess("C:\\Users\\maxnevermo\\Downloads\\gui-check-no-svgrepo-com.svg");
    mb.setIconPixmap(exportSuccess);
    mb.setStyleSheet("QMessageBox {"
                     "background-color: #C6CCE8;"
                     "color: #000000;"
                     "font-family: 'Gogh';"
                     "font-weight: 400;"
                     "font-size: 20px"
                     "}");
    mb.exec();
}
