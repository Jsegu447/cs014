#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;

class Node{
public:
    string data;
    int counter;
    Node* left;
    Node* right;
    Node(const string& stuff, const int& num);
    
};


#endif
