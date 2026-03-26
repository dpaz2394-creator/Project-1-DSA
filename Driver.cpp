#include "Driver.h"
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
Ticket* tickets;
int ticketCount;
string frequentLocation;
*/

Driver::Driver(){
    this->name = " ";
    this->age = 0;
    this->dob = Date{0,0,0};
    this->resAddress = Address{};
    issuanceDate = Date{0, 0, 0};
    yrsOfExp = 0;
    licenseNum = 0;
    medicalConditions = " ";
    jobType = " ";

}

Driver::Driver(string name, int age, Date dob, string jobType, Address redAddress, string county) {
    this->name = name;
    this->age = age;
    this->dob = dob;
    this->resAddress = resAddress;
    this->county = county;
    issuanceDate = Date{25, 03, 2026};
    yrsOfExp = 2026-issuanceDate.year;
    licenseNum = rand() % 1000000000;
    // 9 digit random number
    medicalConditions = "Fit";
    jobType = "Student";
}

void Driver::setIssuanceDate(Date issuanceDate) {
    this->issuanceDate = issuanceDate;
}

void Driver::setLicenseNum(int licenseNum) {
    this->licenseNum = licenseNum;
}

void Driver::setJobType(string jobType) {
    this->jobType = jobType;
    /*
    Should be one of the following:
    Student, Government employee, Self-employed, Business owner, Private sector employee
    */
}

void Driver::setMedicalConditions(string medicalConditions) {
    this->medicalConditions = medicalConditions;
    /*
    Should be one of the following:
    Fit, Vision impaired, Upper extremity impairment, Locomotor disability
    */
}

int Driver::getAge(){
    return age;
}

string Driver::getExperienceCategory(){
    if(yrsOfExp <= 5){
        return "New driver";
    }
    else if(yrsOfExp <= 15){
        return "Moderately experienced driver";
    }
    else {
        return "Highly experienced driver";
    }
}


