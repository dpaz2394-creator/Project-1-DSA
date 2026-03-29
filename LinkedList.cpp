#include "Driver.cpp"
#include "LinkedList.h"
#include <iostream>

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
    //newest driver located at head, oldest at tail
    LinkedListNode* temp = new LinkedListNode(driverData);

    //if empty, make it head
    if(head == nullptr){
        head = temp;
        tail = temp;
        return;
    }

    //check edges. head for if newer, and tail for if older
    if(head->driverData.olderIssThan(driverData) == true){
        //insert before head, done
        temp->next = head;
        head->prev = temp;
        head = temp;
        return;
    }

    if(tail->driverData.olderIssThan(driverData) == false){
        //insert after tail, done
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
        return;
    }

    //not an edge case, must navigate through all liscences.
    LinkedListNode* navigator = head->next;
    while(navigator != nullptr){
        //go until found a driver older than ours
        if(navigator->driverData.olderIssThan(driverData) == false){
            navigator = navigator->next;
            continue;
        }

        //here, navigator is the first older driver than ours
        temp->next = navigator;
        temp->prev = navigator->prev;
        navigator->prev->next = temp;
        navigator->prev = temp;
        break;
    }
    return;
    
}

void LinkedList::remove(Driver driverData){
    //check if list is empty
    if(head == nullptr){
        return;
    }

    //check edge cases. if head==tail, then head and tail
    if(head == tail){
        if(head->driverData == driverData){
            delete head;
            head == nullptr;
            tail == nullptr;
            return;
        }
        else{
            return;
        }
    }

    if(head->driverData == driverData){
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
        return;
    }
    if(tail->driverData == driverData){
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
        return;
    }


    //check entire list
    LinkedListNode* navigator = head->next;
    while(navigator != nullptr){
        if(navigator->driverData != driverData){
            navigator  = navigator->next;
            continue;
        }
        else{
            navigator->next->prev = navigator->prev;
            navigator->prev->next = navigator->next;
            delete navigator;
            return;
        }
    }
    return;
}

void LinkedList::getXFromHead(int n){
    //while next isnt nullptr and counter is less than n
    int counter = 0;
    LinkedListNode* navigator = head;
    cout << "Top " << n << " Newest Licenses:" << endl;
    
    while(counter<n && navigator!=nullptr){
        cout << "   " << counter+1 << ". " << navigator->driverData.getLicenseNum() << endl;
        counter++;
        navigator = navigator->next;
    }
}

void LinkedList::getXFromTail(int n){
    int counter = 0;
    LinkedListNode* navigator = tail;
    cout << "Top " << n << " Oldest Licenses:" << endl;
    
    while(counter<n && navigator!=nullptr){
        cout << "   " << counter+1 << ". " << navigator->driverData.getLicenseNum() << endl;
        counter++;
        navigator = navigator->prev;
    }
}