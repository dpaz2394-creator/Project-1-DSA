#include "HashTable.h"

HashTable::HashTable() : HashTable(101) {
}

HashTable::HashTable(int size){
    tableSize = size;
    table = new HashNode*[tableSize];

    for (int i = 0; i < tableSize; i++){
        table[i] = nullptr;
    }
}

HashTable::~HashTable(){
    for (int i = 0; i < tableSize; i++){
        HashNode* current = table[i];

        while (current != nullptr){
            HashNode* temp = current;
            current  = current->next;
            delete temp->driver;
            delete temp;
            temp = nullptr;
        }
    }

    delete[] table;
}

//Modulo hash for hashing
int HashTable::Hash(int licenseNum){
    return licenseNum % tableSize;
}


void HashTable::insert(Driver inDriver){
    //Finds which bucket the driver should be in
    int index = Hash(inDriver.getLicenseNum());

    //Creates a new node for the linked list in that bucket
    HashNode* newNode = new HashNode;

    //Copies driver information onto the new bucket
    newNode->driver = new Driver(inDriver);

    //Inserts the driver at the front of the linked list in that bucket
    newNode->next = table[index];
    table[index] = newNode;
}

//Returns the pointer of the driver corresponding to licenseNum
Driver* HashTable::search(int licenseNum){
    //Finds the bucket corresponding to licenseNum
    int index = Hash(licenseNum);

    //Starts at the first node in that bucket
    HashNode* current = table[index];

    //Traverse the linked list until driver is found
    while(current != nullptr){
        if (current->driver->getLicenseNum() == licenseNum){
            //Retrun pointer to matching driver
            return current->driver;
        }

        current = current->next;
    }

    //returns null pointer if driver is not found
    return nullptr;
}

bool HashTable::remove(int licenseNum){
    //Finds the correct bucket
    int index = Hash(licenseNum);

    HashNode* current = table[index];
    HashNode* previous = nullptr;

    //Searches through the linked list in the bucket
    while(current != nullptr){
        if (current->driver->getLicenseNum() == licenseNum){
            //deletes the first node
            if (previous == nullptr){
                table[index] = current->next;
            }
            else{
                //skips over the current node
                previous->next = current->next;
            }

            //Free the memory used by Driver and the hash node
            delete current->driver;
            delete current;

            return true;
        }

        //moves the pointers forward in the list
        previous = current;
        current = current->next;
    }

    //Returns false if licenseNum was not found
    return false;
}
