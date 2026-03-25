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

        int licenseNum;
        string name;
        int age;
        Date dob;
        string jobType;
        Address resAddress;
        Date issuanceDate;
        string county;
        Ticket* tickets;
        int ticketCount;
        string frequentLocation;
        string medicalConditions;
        int yrsOfExp;

    public:

        Driver(string name, int age, Date dob);

        void addTicket(Ticket newTicket);

        int getAge();

        string getExperienceCategory();

};

#endif