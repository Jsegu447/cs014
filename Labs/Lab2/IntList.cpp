#include "IntList.h"
#include <iostream>
using namespace std;
IntList::IntList(){
    dHead = new IntNode(0);
    dTail = new IntNode(0);
    dTail->prev = dHead;
    dHead->next = dTail;
}

IntList::~IntList(){
    IntNode* curr;
    curr = dHead->next;
    IntNode* temp;
    while (curr!= dTail){
        dHead->next = curr->next;
        temp = curr->next;
        temp->prev = dHead;
        delete curr;
        curr = temp;
    }
}

void IntList::push_front(int value){
    IntNode* temp = new IntNode(value);
    if(dTail->prev == dHead){
        dTail->prev = temp;
    }
    temp->next = dHead->next;
    dHead->next = temp;
    temp->prev = dHead;
    temp->next->prev = temp;
}
void IntList::pop_front(){
    if(empty() == true){
        return;
    }
    IntNode* temp = dHead->next->next;
    delete dHead->next;
    dHead->next = temp;
    temp->prev = dHead;
}
void IntList::push_back(int value){
    IntNode* temp = new IntNode(value);
    dTail->prev->next = temp;
    temp->prev = dTail->prev;
    temp->next = dTail;
    dTail->prev = temp;
    
}
void IntList::pop_back(){
    if(empty() == true){
        return;
    }
    IntNode* temp =  dTail->prev->prev;
    dTail->prev->prev->next = dTail;
    delete dTail->prev;
    dTail->prev = temp;
    
}
bool IntList::empty() const{
    if(dHead->next == dTail){
        return true;
    }
    return false;
}

ostream & operator<<(ostream &out, const IntList &rhs){
    IntNode* currNode = rhs.dHead->next;
    while (currNode != rhs.dTail) {
        if (currNode == rhs.dTail->prev){
            out << currNode->data;
            currNode = currNode->next;
            return out;
        }
        out << currNode->data << " ";
        currNode = currNode->next;
    }
    return out;
}

void IntList::printReverse() const{
    IntNode* currNode = dTail->prev;
    while(currNode != dHead){
    if (currNode == dHead->next){
        cout << currNode->data;
        currNode = currNode->prev;
        return;
            }
        cout << currNode->data << " ";
        currNode = currNode->prev;
    }
}

    

