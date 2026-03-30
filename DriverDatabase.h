#ifndef DRIVERDATABASE_H
#define DRIVERDATABASE_H

#include "Driver.h"
#include "HashTable.h"
#include "LinkedList.h"

class DriverDatabase{
    private:
    HashTable activeDrivers;
    HashTable inactiveDrivers;
    LinkedList licenseList;

    public:
    DriverDatabase();
    void addDriver(Driver inDriver);

    void removeDriver(int licenseNum);

    Driver findDriver(int searchID);

    void moveToInactive(int id);

    void getOldestLicenses(int n);

    void getNewestLicenses(int n);
};

#endif
