#include "patientinfo.h"

//функція для розбиття зчитаної з файлу стрічки для подальшого заповнення таблиці

std::vector<std::string> splitByString(const std::string& input, const std::string& delimiter) {
    std::vector<std::string> elements;
    size_t startPos = 0;
    size_t foundPos;

    while ((foundPos = input.find(delimiter, startPos)) != std::string::npos) {
        elements.push_back(input.substr(startPos, foundPos - startPos));
        startPos = foundPos + delimiter.length();
    }

    elements.push_back(input.substr(startPos));
    return elements;
}

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


std::istream& operator>>(std::istream& is, patientInfo& patient)
{

    std::string myline;
    std::string delim = " | ";
    std::string Pdelim = "/";
    std::vector<std::string> dividedPatientInfo;
    std::vector<std::string> dividedPressure;

    if (std::getline(is, myline)) {
        dividedPatientInfo = splitByString(myline, delim);
        dividedPressure = splitByString(dividedPatientInfo.at(4), Pdelim);

        patient = patientInfo(dividedPatientInfo.at(0), stoi(dividedPatientInfo.at(1)), dividedPatientInfo.at(2), dividedPatientInfo.at(3),
                              stoi(dividedPressure.at(0)), stoi(dividedPressure.at(1)), stoi(dividedPatientInfo.at(5)));
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, const patientInfo& patient)
{
    os << QString("%1 | %2 | %3 | %4 | %5 | %6/%7 | %8")
              .arg(QString::fromStdString(patient.m_surname), -15)
              .arg(patient.m_age, -15)
              .arg(QString::fromStdString(patient.m_bloodType), -15)
              .arg(QString::fromStdString(patient.m_rhFactor), -15)
              .arg(patient.m_upPressure)
              .arg(patient.m_lowPressure)
              .arg(QString::number(patient.m_pulseValue), -15)  // Ensure the Heart Rate is correctly formatted
              .toStdString();
    return os;
}


