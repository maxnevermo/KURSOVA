#include "patientinfo.h"

std::vector<std::string> splitByString(const std::string& input, const std::string& delimiter) {
    std::vector<std::string> elements;
    size_t startPos = 0;
    size_t foundPos;

    while ((foundPos = input.find(delimiter, startPos)) != std::string::npos) {
        std::string element = input.substr(startPos, foundPos - startPos);

        // Remove leading and trailing whitespaces
        element.erase(element.begin(), std::find_if(element.begin(), element.end(), [](unsigned char ch) {
                          return !std::isspace(ch);
                      }));
        element.erase(std::find_if(element.rbegin(), element.rend(), [](unsigned char ch) {
                          return !std::isspace(ch);
                      }).base(), element.end());

        elements.push_back(element);
        startPos = foundPos + delimiter.length();

        // Skip additional spaces
        while (startPos < input.length() && input[startPos] == ' ') {
            startPos++;
        }
    }

    // Handle the last element
    std::string lastElement = input.substr(startPos);
    // Remove leading and trailing whitespaces
    lastElement.erase(lastElement.begin(), std::find_if(lastElement.begin(), lastElement.end(), [](unsigned char ch) {
                          return !std::isspace(ch);
                      }));
    lastElement.erase(std::find_if(lastElement.rbegin(), lastElement.rend(), [](unsigned char ch) {
                          return !std::isspace(ch);
                      }).base(), lastElement.end());

    elements.push_back(lastElement);

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

patientInfo::patientInfo(int num, std::string surname, int age, std::string bloodType, std::string rhFactor, int upPressure, int lowPressure, int pulse)
{
    m_num = num;
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
        dividedPressure = splitByString(dividedPatientInfo.at(5), Pdelim);

        patient = patientInfo(stoi(dividedPatientInfo.at(0)), dividedPatientInfo.at(1), stoi(dividedPatientInfo.at(2)), dividedPatientInfo.at(3), dividedPatientInfo.at(4),
                              stoi(dividedPressure.at(0)), stoi(dividedPressure.at(1)), stoi(dividedPatientInfo.at(6)));
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, const patientInfo& patient)
{
    os << std::setw(4) << patient.m_num << " | "
       << std::setw(15) << patient.m_surname << " | "
       << std::setw(5) << patient.m_age << " | "
       << std::setw(7) << patient.m_bloodType << " | "
       << std::setw(5) << patient.m_rhFactor << " | "
       << std::setw(13) << patient.m_upPressure << "/" << patient.m_lowPressure << " | "
       << std::setw(4) << patient.m_pulseValue << " |";


    return os;
}

patientInfo::patientInfo(const patientInfo& other)
{
    m_num = other.m_num;
    m_surname = other.m_surname;
    m_age = other.m_age;
    m_bloodType = other.m_bloodType;
    m_rhFactor = other.m_rhFactor;
    m_upPressure = other.m_upPressure;
    m_lowPressure = other.m_lowPressure;
    m_pulseValue = other.m_pulseValue;
}
