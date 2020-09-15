// worked with annie wang
// used prof ali slides
// went on geeksforgeeks.com for algorithm help

#include <iostream>
#include <fstream>
#include <ostream>
#include <stack>
#include <sstream>
#include <string>
#include "arithmeticExpression.h"
using namespace std;
    /* Initializes an empty tree and sets the infixExpression
    to the value of parameter passed in. */
arithmeticExpression::arithmeticExpression(const string & stuff){
   infixExpression = stuff;
    root = nullptr;
}


    /* Converts the infixExpression to its equivalent postfix string
       and then generates the tree and assigns the root node to the
       root data field. The key for the first node is 'a', 'b' for the second node and so on. */

    /* Calls the recursive infix function. */
void arithmeticExpression::infix(){
    infix(root);
    
}

    /* Calls the recursive prefix function. */
void arithmeticExpression::prefix(){
    prefix(root);
}

    /* Calls the recursive postfix function. */
void arithmeticExpression::postfix(){
    postfix(root);
}

 int arithmeticExpression::priority(char op){
        int priority = 0;
        if(op == '('){
            priority =  3;
        }
        else if(op == '*' || op == '/'){
            priority = 2;
        }
        else if(op == '+' || op == '-'){
            priority = 1;
        }
        return priority;
    }

    string arithmeticExpression::infix_to_postfix(){
        stack<char> s;
        ostringstream oss;
        char c;
        for(unsigned i = 0; i< infixExpression.size();++i){
            c = infixExpression.at(i);
            if(c == ' '){
                continue;
            }
            if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
                if( c == '('){
                    s.push(c);
                }
                else if(c == ')'){
                    while(s.top() != '('){
                        oss << s.top();
                        s.pop();
                    }
                    s.pop();
                }
                else{
                    while(!s.empty() && priority(c) <= priority(s.top())){
                        if(s.top() == '('){
                            break;
                        }
                        oss << s.top();
                        s.pop();
                    }
                    s.push(c);
                }
            }
            else{ //c is an operand
                oss << c;
            }
        }
        while(!s.empty()){
            oss << s.top();
            s.pop();
        }
        return oss.str();
    }

    void arithmeticExpression::visualizeTree(const string &outputFilename){
        ofstream outFS(outputFilename.c_str());
        if(!outFS.is_open()){
            cout<<"Error opening "<< outputFilename<<endl;
            return;
        }
        outFS<<"digraph G {"<<endl;
        visualizeTree(outFS,root);
        outFS<<"}";
        outFS.close();
        string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
        string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
        system(command.c_str());
    }
void arithmeticExpression::infix(TreeNode* node){
    if(node->left != nullptr && node->right != nullptr){
        cout << "(";
        infix(node->left);
        cout << node->data;
        infix(node->right);
        cout << ")";
    }
    else{
        cout << node->data;
    }
}

    /* Helper function that outputs the prefix notation of the arithmetic expression tree
       by performing the preorder traversal of the tree. */
void arithmeticExpression::prefix(TreeNode * node){
    if(node == nullptr){
        return;
    }
    cout << node->data;
    prefix(node->left);
    prefix(node->right);
}

    /* Helper function that outputs the postfix notation of the arithmetic expression tree
       by performing the postorder traversal of the tree. */
void arithmeticExpression::postfix(TreeNode * node){
    if(node == nullptr){
        return;
    }
    postfix(node->left);
    postfix(node->right);
    cout << node->data;
}

void arithmeticExpression::buildTree(){
stack <TreeNode* > treeNodeStack;
    string boof = infix_to_postfix();
    for(unsigned i = 0; i < boof.size(); i++){
        if(boof.at(i) == '+' || boof.at(i) == '-' || boof.at(i) == '*' || boof.at(i) == '/' ){
            TreeNode* a;
            TreeNode* b;
           a = treeNodeStack.top();
            treeNodeStack.pop();
            b = treeNodeStack.top();
            treeNodeStack.pop();
            treeNodeStack.push(new TreeNode(boof.at(i), 97+i));
            treeNodeStack.top()->left = b;
            treeNodeStack.top()->right = a;
        }
        else{
            treeNodeStack.push(new TreeNode(boof.at(i), 97+i));
        }
    }
    root = treeNodeStack.top();
}

void arithmeticExpression::visualizeTree(ofstream & out, TreeNode * node){
   if (node != nullptr) {
       out << node->key << "[ label = " << "\"" << node->data << "\"" << " ]" <<endl;
       if (node->left != nullptr) {
           out << node->key <<  "->" << node->left->key <<endl;
           visualizeTree(out, node->left);
       }
       
       if (node->right != nullptr) {
           out << node->key << " -> " << node->right->key << endl;
           visualizeTree(out, node->right);
       }
       
       out << endl;
       }
}
