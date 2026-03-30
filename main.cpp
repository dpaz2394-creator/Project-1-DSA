#include "DriverDatabase.h"
#include <iostream>
using namespace std;

int main(){
    srand(time(0));

    DriverDatabase DriverDatabase;

    int choice;
    int nChoice;
    int inLicenseNum;
    string inName;
    int inAge;
    string inCounty;
    string inJobType;
    int inDay, inMonth, inYear;
    int inHouseNum, inZip;
    string inStreet;
    string inCity;
    string inState;
    int numTickets;

    Date inDob;
    Address inAdress;
    Driver foundDriver;

    do{
        cout << "Welcome to the driver database!\n" <<
        "1. Add Driver\n"
        "2. Display Driver\n"
        "3. Remove Driver\n"
        "4. Retrieve N newest licenses\n"
        "5. Retrieve N oldest licenses\n"
        "6. Exit program\n"
        "Enter your choice: \n";

        cin >> choice;

        switch(choice){

            //Inserting a driver
            case 1:
            {
                cout << "Enter driver name:" << endl;
                cin.ignore();
                getline(cin, inName);

                cout << "Enter age:" << endl;
                cin >> inAge;

                cout << "Enter the date of birth (day month year):" << endl;
                cin >> inDay >> inMonth >> inYear;
                inDob = Date{inDay, inMonth, inYear};

                cout << "Enter job type:" << endl;
                cin.ignore();
                getline(cin, inJobType);

                cout << "Enter house number:" << endl;
                cin >> inHouseNum;

                cout << "Enter street name:" << endl;
                cin.ignore();
                getline(cin, inStreet);

                cout << "Enter ZIP code:" << endl;
                cin >> inZip;

                cout << "Enter city:" << endl;
                cin.ignore();
                getline(cin, inCity);

                cout << "Enter state:" << endl;
                getline(cin, inState);

                cout << "Enter county:" << endl;
                getline(cin, inCounty);

                inAdress = Address{inHouseNum, inStreet, inZip, inCity, inState};

                Driver newDriver(inName, inAge, inDob, inJobType, inAdress, inCounty);
                DriverDatabase.addDriver(newDriver);

                cout << "Driver added successfully." << endl;
                cout << "Assigned license number: " << newDriver.getLicenseNum() << endl;


                break;
            }

            //Displaying a driver
            case 2:
            {
                cout << "Enter license number to search: ";
                cin >> inLicenseNum;

                foundDriver = DriverDatabase.findDriver(inLicenseNum);

                if(foundDriver.getLicenseNum() == 0){
                    cout << "Driver not found." << endl;
                }
                else {
                    cout << "Driver found:" << endl;
                    cout << "Name: " << foundDriver.getName() << endl;
                    cout << "License Number: " << foundDriver.getLicenseNum() << endl;
                    cout << "Age: " << foundDriver.getAge() << endl;
                    cout << "Experience Category: " << foundDriver.getExperienceCategory() << endl;
                }

                break;
            }

            //Removing a driver
            case 3:
            {
                cout << "Enter license number to remove: ";
                cin >> inLicenseNum;

                DriverDatabase.removeDriver(inLicenseNum);
                cout << "If the driver existed, they have been removed." << endl;
                
                break;
            }

            //Retrieving N newest licenses
            case 4:
            {
                cout << "What is N?" << endl;

                cin >> nChoice;

                DriverDatabase.getNewestLicenses(nChoice);

                break;
            }

            //Retrieving N oldest licenses
            case 5:
            {
                cout << "What is N?" << endl;

                cin >> nChoice;

                DriverDatabase.getOldestLicenses(nChoice);

                break;
            }

            //case 6 ends the loop
            case 6:
            {
                break;
            }

            default:
            {
                cout << "Invalid selection." << endl;
                break;
            }
        }

    }while(choice != 6);

    cout << "Exiting program." << endl;

    return 0;
}