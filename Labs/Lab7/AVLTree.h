#ifndef AVL_H
#define AVL_H
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>
class AVLTree {
public:
void insert(const string &);
int balanceFactor(Node*);
void printBalanceFactors();
void visualizeTree(const string &);
AVLTree();
private:
    Node* root;
    Node* findUnbalancedNode(Node*);
    void rotate(Node*&);
    Node* rotateLeft(Node*&);
    Node* rotateRight(Node*&);
    void printBalanceFactors(Node *);
    void visualizeTree(ofstream &, Node *);
    int height(Node* v) const;
};
#endif
