#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
using namespace std;
const int MAX_SIZE = 20;
template<typename T>
class stack{
private:
    T data[MAX_SIZE];
    int size;
public:
    stack();
    void push(T val);
    void pop();
    T top();
    bool empty();
};
#endif

template<typename T>
stack<T>::stack(){
    size = 0;
}

template<typename T>
void stack<T>::push(T val){
    if(size == MAX_SIZE){
        throw overflow_error("Called push on full stack.");
    }
    data[size] = val;
    size++;
}

template<typename T>
void stack<T>::pop(){
    if(empty()){
        throw out_of_range("Called pop on empty stack.");
    }
    size--;
}

template<typename T>
T stack<T>::top(){
    if(empty()){
        throw underflow_error("Called top on empty stack.");
    }
    return data[size-1];
}

template<typename T>
bool stack<T>::empty(){
    if(size == 0){
        return true;
    }
    return false;
}
