#include "Driver.cpp"
#include "LinkedList.h"

LinkedListNode::LinkedListNode(){
    next = nullptr;
    prev = nullptr;
}

LinkedListNode::LinkedListNode(Driver d){
    driverData = d;
    next = nullptr;
    prev = nullptr;
}

LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
}

void LinkedList::insert(Driver driverData){
    
}

void LinkedList::remove(Driver driverData){

}