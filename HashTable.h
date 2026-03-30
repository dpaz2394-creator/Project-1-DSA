#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Driver.h"

struct HashNode{
    Driver* driver;
    HashNode* next;
};

class HashTable{
    private:
    HashNode** table;
    int tableSize;
    int Hash(int licenseNum);

    public:
    HashTable();
    HashTable(int size);
    ~HashTable();

    void insert(Driver inDriver);
    Driver* search(int licenseNum);
    bool remove(int licenseNum);
};


#endif
