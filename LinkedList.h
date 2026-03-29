#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Driver.h"

struct LinkedListNode{
    Driver driverData;
    LinkedListNode* next;
    LinkedListNode* prev;

    LinkedListNode();
    LinkedListNode(Driver d);
};

class LinkedList{
    private:
    LinkedListNode* head;
    LinkedListNode* tail;

    public:

    LinkedList();

    void insert(Driver driverData);
    void remove(Driver driverData);

    void getXFromHead(int n);
    void getXFromTail(int n);

};

#endif