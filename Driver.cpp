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

int Driver::getLicenseNum(){
    return licenseNum;
}

Date Driver::getDob(){
    return dob;
}

string Driver::getName(){
    return name;
}

bool Driver::operator==(Driver& rhs){
    //only check name, dob, licenseNum for equality
    if(name == rhs.getName()){
        if(dob.year==rhs.getDob().year && dob.month==rhs.getDob().month && dob.day==rhs.getDob().day){
            if(licenseNum == rhs.getLicenseNum()){
                return true;
            }
        }
    }
    return false;
}

bool Driver::operator!=(Driver& rhs){
    return !(this->operator==(rhs));
}

Date Driver::getIssuanceDate(){
    return issuanceDate;
}

bool Driver::olderIssThan(Driver& rhs){
    //if lhs has older or same issuance date then rhs, then true. else, false

    if(issuanceDate.year < rhs.getIssuanceDate().year){
        return true;
    }
    else if(issuanceDate.year > rhs.getIssuanceDate().year){
        return false;
    }
    
    //if its the same year, compare month

    if(issuanceDate.month < rhs.getIssuanceDate().month){
        return true;
    }
    else if(issuanceDate.month > rhs.getIssuanceDate().month){
        return false;
    }

    //if its the same month, compare day

    if(issuanceDate.day <= rhs.getIssuanceDate().day){
        return true;
    }
    else{
        return false;
    }
    
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


