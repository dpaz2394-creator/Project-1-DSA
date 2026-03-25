#ifndef DRIVER_H
#define DRIVER_H
#include <string>
using namespace std;

struct Date{
    int day;
    int month;
    int year;
};

struct Address{
    int houseNum;
    string street;
    int zip;
    string city;
    string state;
};

struct Ticket{
    string location;
    Date issueDate;
};

class Driver{
    private:
        //auto made
        int licenseNum;
        int yrsOfExp;
        int ticketCount;

        //manual set
        string name;
        int age;
        Date dob;
        Address resAddress;
        string county;
        
        Date issuanceDate;
        string medicalConditions;
        string jobType;

        //seperate
        Ticket* tickets;
        string frequentLocation;
        
    public:

        Driver(string name, int age, Date dob, string jobType, Address redAddress, string county);
        // setIssuance and setLicenseNum only if it's an already existing liscence
        void setIssuanceDate(Date issuanceDate);
        void setLicenseNum(int licenseNum);
        void setJobType(string jobType);
        void setMedicalConditions(string medicalConditions);

        int getAge();

        string getExperienceCategory();

};

#endif