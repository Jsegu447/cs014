#include "Survivors.h"
#include <string>
using namespace std;
Survivors::Survivors(): head(nullptr), tail(nullptr){}
 
void Survivors::addSurvivor(string name){
    if( head == nullptr){
        head = new Person(name);
        tail = head;
        head->setNext(head);
        return;
    }
    Person* temp = new Person(name);
    tail->setNext(temp);
    temp->setNext(head);
    tail = temp;
    
}

bool Survivors::removeSurvivor(Person* &person, Person* &prevPerson){
    if(head == nullptr){
        return true;
    }
    if(person->nxtPerson == person){
        return true;
    }
    if(person == head){
        prevPerson->setNext(person->nxtPerson);
        delete person;
        head = prevPerson;
        person = prevPerson->nxtPerson;
        return false;
        }
    if(person == tail){
        prevPerson->setNext(person->nxtPerson);
        delete person;
        tail = prevPerson;
        person = prevPerson->nxtPerson;
        return false;
    }
    prevPerson->setNext(person->nxtPerson);
    delete person;
    person = prevPerson->nxtPerson;
    return false;
}

Person* Survivors::setCurr(int index){
    Person* temp = head;
    for(unsigned i = 1; i < index; i++){
        temp = temp->nxtPerson;
    }
    return temp;
}

Person* Survivors::setPrev(int index){
    Person* temp = head;
    if(index == 1){
        return tail;
    }
    for(unsigned i = 1; i < index-1; i++){
            temp = temp->nxtPerson;
        }
        return temp;
    }

