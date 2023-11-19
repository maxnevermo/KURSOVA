#include "patientinfo.h"

patientInfo::patientInfo()
{
    this->m_num = 0;
    this->m_surname = "Не визначено";
    this->m_age = 0;
    this->m_bloodType = "Не визначено";
    this->m_rhFactor = "Не визначено";
    this->m_upPressure = 0;
    this->m_lowPressure = 0;
    this->m_pulseValue = 0;
}

void patientInfo::errorMessage(QString currentError) {
    QMessageBox mb("PatientMonitor",
                   currentError,
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

patientInfo::patientInfo(std::string surname, int age, std::string bloodType, std::string rhFactor, int upPressure, int lowPressure, int pulse)
{
    m_surname = surname;
    m_age = age;
    m_bloodType = bloodType;
    m_rhFactor = rhFactor;
    m_upPressure = upPressure;
    m_lowPressure = lowPressure;
    m_pulseValue = pulse;
}
