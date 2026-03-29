#include "Driver.cpp"
#include "HashTable.cpp"
#include "LinkedList.cpp"
#include "DriverDatabase.h"


void DriverDatabase::addDriver(Driver inDriver){
    //Use Hashtable function to insert driver into hash
    activeDrivers.insert(inDriver);
}

void DriverDatabase::removeDriver(int licenseNum){
    activeDrivers.remove(licenseNum);
}

Driver DriverDatabase::findDriver(int searchID){
    //Prepare result for nullptr test, if its a valid search
    Driver* driverPntr  = activeDrivers.search(searchID);

    if(driverPntr == nullptr) {
        //return error 
        Driver nullDriver;
        return nullDriver;
    }

    return *driverPntr;
}

void DriverDatabase::moveToInactive(int id){
    //Get active driver, check existance
    Driver* tempDriver = activeDrivers.search(id);
    if(tempDriver == nullptr){
        return;
    }

    //Insert into inactive before deleting from active
    inactiveDrivers.insert(*tempDriver);
    activeDrivers.remove(id);
}

void DriverDatabase::getOldestLicenses(int n){
    licenseList.getXFromTail(n);
}

void DriverDatabase::getNewestLicenses(int n){
    //while next isnt nullptr and counter is less than n
    //licenseList
    licenseList.getXFromHead(n);
}