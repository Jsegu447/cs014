// worked with annie wang
#include "IntList.h"
#include <iostream>
using namespace std;

int main(){
    IntList list1;
    cout << list1 << endl;
    list1.push_front(1);
    cout << list1 << endl;
    list1.push_front(2);
    cout << list1 << endl;
    list1.push_front(3);
    cout << list1 << endl;
    list1.push_back(4);
    cout << list1 << endl;
    list1.push_back(5);
    cout << list1 << endl;
    list1.push_back(6);
    cout << list1 << endl;
    list1.printReverse();
    cout << endl;
    list1.pop_back();
    cout << list1 << endl;
    list1.pop_back();
    cout << list1 << endl;
    list1.pop_back();
    cout << list1 << endl;
    list1.pop_back();
    cout << list1 << endl;
    list1.pop_back();
    cout << list1 << endl;
    list1.pop_back();
    cout << list1 << endl;
    list1.pop_back();
    list1.push_front(1);
    list1.printReverse();
    cout << endl;
    
    

    





    
    
    
    
    
    
    
    
    
    
    return 0;
}
