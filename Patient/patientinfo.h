#ifndef PATIENTINFO_H
#define PATIENTINFO_H
#include <iostream>
#include <string>


class patientInfo
{
public:
    patientInfo();
    void setNum(int num) { m_num = num; }
    void setSurname(const std::string& surname) { m_surname = surname; }
    void setAge(int age) { m_age = age; }
    void setBloodType(int bloodType) { m_bloodType = bloodType; }
    void setRhFactor(char rhFactor) { m_rhFactor = rhFactor; }
    void setUpPressure(int upPressure) { m_upPressure = upPressure; }
    void setLowPressure(int lowPressure) { m_lowPressure = lowPressure; }
    void setPulseValue(int pulseValue) { m_pulseValue = pulseValue; }

    int getNum() {return this->m_num;}
    std::string getSurname() {return this->m_surname;}
    int getAge() {return this->m_age;}
    int getBloodType() {return this->m_bloodType;}
    char getRhFactor() {return this->m_rhFactor;}
    int getUpPressure() {return this->m_upPressure;}
    int getLowPressure() {return this->m_lowPressure;}
    int getPulseValue() {return this->m_pulseValue;}

private:
    int m_num;
    std::string m_surname;
    int m_age;
    int m_bloodType;
    char m_rhFactor;
    int m_upPressure;
    int m_lowPressure;
    int m_pulseValue;

};

#endif // PATIENTINFO_H
