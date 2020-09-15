#ifndef SURVIVORS_H
#define SURVIVORS_H
#include <string>
using namespace std;
class Survivors;
struct Person{
    string name;
    Person* nxtPerson;
    Person() : name(""), nxtPerson(nullptr){}
    Person(string name) : name(name), nxtPerson(nullptr){}
    void setNext(Person* next){ nxtPerson = next; }
};


class Survivors{
private:
    Person* head;
    Person* tail;
public:
    void addSurvivor(string name);
    bool removeSurvivor(Person* &person, Person* &prevPerson);
    Person* setCurr(int);
    Person* setPrev(int);
    Survivors();
};
#endif
