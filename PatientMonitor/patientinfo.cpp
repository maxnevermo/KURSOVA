#include "patientinfo.h"
bool isNumeric(const std::string& str) {
    for (char ch : str) {
        if (!std::isdigit(ch)) {
            return false;
        }
    }
    return !str.empty();
}

bool isAlphabetic(const std::string& str) {
    for (char ch : str) {
        if (!std::isalpha(ch)) {
            return false;
        }
    }
    return !str.empty();
}

void scanningError(const QString errorMessage) {
    QMessageBox mb("Add new patient",
                   errorMessage,
                   QMessageBox::NoIcon,
                   QMessageBox::Ok | QMessageBox::Default,
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

patientInfo& patientInfo::operator=(const patientInfo& other)
{
    if (this != &other)
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

    return *this;
}

std::istream& operator>>(std::istream& is, patientInfo& patient) {
    std::string myline;
    std::string delim = " | ";
    std::string Pdelim = "/";
    std::vector<std::string> dividedPatientInfo;
    std::vector<std::string> dividedPressure;

    try {
        if (std::getline(is, myline)) {
            dividedPatientInfo = splitByString(myline, delim);

            if (dividedPatientInfo.size() != 7) {
                throw QString("Incorrect data format");
            }

            dividedPressure = splitByString(dividedPatientInfo.at(5), Pdelim);

            if (!isNumeric(dividedPatientInfo.at(0))) {
                throw QString("Number can not be a string");
            }

            if (!isAlphabetic(dividedPatientInfo.at(1))) {
                throw QString("Surname can not be a number");
            }

            if (!isNumeric(dividedPatientInfo.at(2))) {
                throw QString("Age can not be a string");
            }

            if (dividedPatientInfo.at(3) != "I" && dividedPatientInfo.at(3) != "II" &&
                dividedPatientInfo.at(3) != "III" && dividedPatientInfo.at(3) != "IV") {
                throw QString("Blood type must be 'I', 'II', 'III', or 'IV'");
            }

            if (dividedPatientInfo.at(4) != "+" && dividedPatientInfo.at(4) != "-") {
                throw QString("Rh factor must be '+' or '-'");
            }

            if (dividedPressure.size() != 2) {
                throw QString("Incorrect format for blood pressure values");
            }

            if (!isNumeric(dividedPressure.at(0)) || !isNumeric(dividedPressure.at(1))) {
                throw QString("Blood pressure values must be numeric");
            }

            if (!isNumeric(dividedPatientInfo.at(6))) {
                throw QString("Heart rate must be numeric");
            }

            patient = patientInfo(stoi(dividedPatientInfo.at(0)), dividedPatientInfo.at(1), stoi(dividedPatientInfo.at(2)),
                                  dividedPatientInfo.at(3), dividedPatientInfo.at(4),
                                  stoi(dividedPressure.at(0)), stoi(dividedPressure.at(1)), stoi(dividedPatientInfo.at(6)));
        }
    } catch (const QString& errorMessage) {
        scanningError(errorMessage);
        is.setstate(std::ios::failbit);
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, const patientInfo& patient)
{
    os << patient.m_num << " | "
       << patient.m_surname << " | "
       << patient.m_age << " | "
       << patient.m_bloodType << " | "
       << patient.m_rhFactor << " | "
       << patient.m_upPressure << "/" << patient.m_lowPressure << " | "
       << patient.m_pulseValue;


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
