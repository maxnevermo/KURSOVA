#ifndef PATIENTINFO_H
#define PATIENTINFO_H
#include <iostream>
#include <string>
#include <QMessageBox>

class patientInfo
{
public:
    patientInfo();
    patientInfo(std::string surname, int age, std::string bloodType, std::string rhFactor, int upPressure, int lowPressure, int pulse);

    void setNum(int num) { m_num = num; }
    void setSurname(const std::string& surname) { m_surname = surname; }
    void setAge(int age) { m_age = age; }
    void setBloodType(std::string bloodType) { m_bloodType = bloodType; }
    void setRhFactor(std::string rhFactor) { m_rhFactor = rhFactor; }
    void setUpPressure(int upPressure) { m_upPressure = upPressure; }
    void setLowPressure(int lowPressure) { m_lowPressure = lowPressure; }
    void setPulseValue(int pulseValue) { m_pulseValue = pulseValue; }

    int getNum() const { return m_num; }
    std::string getSurname() const { return m_surname; }
    int getAge() const { return m_age; }
    std::string getBloodType() const { return m_bloodType; }
    std::string getRhFactor() const { return m_rhFactor; }
    int getUpPressure() const { return m_upPressure; }
    int getLowPressure() const { return m_lowPressure; }
    int getPulseValue() const { return m_pulseValue; }

private:
    int m_num;
    std::string m_surname;
    int m_age;
    std::string m_bloodType;
    std::string m_rhFactor;
    int m_upPressure;
    int m_lowPressure;
    int m_pulseValue;

};

#endif // PATIENTINFO_H
