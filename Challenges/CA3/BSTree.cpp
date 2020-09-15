 // algorithm help from slides, journal dev
// worked with annie wang
// help from previous student github remove help
#include "BSTree.h"
#include "Node.h"
#include <iostream>
using namespace std;

BSTree::BSTree(){
    root = nullptr;
}

void BSTree::insert(const string &newString){
    Node* x = root;
    if(x == nullptr){
        root = new Node(newString, 1);
    }
    else if(search(newString, root)){
        Node* o = getNode(newString,root);
        o->counter++;
        return;
    }
    else{
        Node* insert = root;
        while(insert != nullptr){
            if(insert->data > newString){
                if(insert->left == nullptr){
                    insert->left = new Node(newString,1);
                    return;
                }
                else{
                    insert = insert->left;
                }
            }
            else if(insert->data < newString){
                if(insert->right == nullptr){
                    insert->right = new Node(newString,1);
                    return;
                }
                else{
                    insert = insert->right;
                    
                }
            }
        }
    }

}
                        
void BSTree::remove(const string &key){
    if(search(key,root)){
        Node* f = getNode(key, root);
        if(f->counter > 1){
            f->counter--;
        }
        else{
        remove(key, root);
        }
    }
    
}

Node* BSTree::remove(const string& key, Node* n){
    if( root == nullptr){
        return nullptr;
    }
    if(key < n->data){
        n->left = remove(key, n->left);
    }
    else if(key > n->data){
        n->right = remove(key, n->right);
    
    }
    else{
        if(n->counter > 1){
            Node* x = getNode(key, root);
            x->counter--;
            return n;
        }
        if(n->left == nullptr && n->right == nullptr && n == root){
                   delete n;
            root = nullptr;
               }
        else if(n->left == nullptr && n->right == nullptr){
            delete n;
            return nullptr;
        }
        else if(n->left == nullptr){
            Node* succ = min(n->right);
            n->data = succ->data;
            n->counter = succ->counter;
            succ->counter = 0;
            n->right = remove(succ->data,n->right);
            return n;
        }
        else if(n->right == nullptr){
            Node* succ = max(n->left);
            n->data = succ->data;
            n->counter = succ->counter;
            succ->counter = 0;
            n->left = remove(succ->data,n->left);
            return n;
            }
        else{
            Node* nxt = max(n->left);
            n->data = nxt->data;
            n->counter = nxt->counter;
            nxt->counter = 1;
            n->left = remove(nxt->data,n->left);
        }
    }
    return n;
}

Node* BSTree::getNode(const string &key, Node* n) const{
            if(n == nullptr){
                return nullptr;
            }
            if(key == n->data){
                return n;
            }
            else if(n->data > key){
                return getNode(key,n->left);
            }
            else if(n->data < key){
                return getNode(key, n->right);
            }
    return nullptr;
}


bool BSTree::search(const string &key, Node* n) const{
            if(n == nullptr){
                return false;
            }
            if(key == n->data){
                return true;
            }
            else if(n->data > key){
               return search(key,n->left);
                
            }
            else if(n->data < key){
               return search(key, n->right);
            }
    return false;
}
                        
bool BSTree::search(const string &key) const{
    return search( key, root);
}
      

string BSTree::largest() const{
      Node* node = root;
    if(node == nullptr){
        return "";
    }
    while(node->right != nullptr){
        node = node->right;
    }
    return node->data;
}

string BSTree::smallest() const{
     Node* node = root;
     if(node == nullptr){
         return "";
     }
     while(node->left != nullptr){
         node = node->left;
     }
     return node->data;
}

int BSTree::height(Node* v) const{
    if(v == nullptr){
        return -1;
    }
    int left;
    int right;
    left = height(v->left);
    right = height(v->right);
    if(left > right){
        return 1 + left;
    }
    else{
        return 1+ right;
    }
}

int BSTree::height(const string& n) const{
    Node* node = getNode(n, root);
    return height(node);
}






void BSTree::preOrder()const{
    preOrder(root);
}
void BSTree::postOrder()const{
    postOrder(root);
}

void BSTree::inOrder()const{
    inOrder(root);
}


void BSTree::preOrder(Node* node) const{
    if(node == nullptr){
        return;
    }
    cout << node->data << "("<< node->counter <<"), ";
    preOrder(node->left);
    preOrder(node->right);
}
void BSTree::postOrder(Node* node) const{
    if(node == nullptr){
           return;
       }
       postOrder(node->left);
       postOrder(node->right);
       cout << node->data << "(" << node->counter << "), ";
}

void BSTree::inOrder(Node* node) const{
    if(node == nullptr){
        return;
    }
    inOrder(node->left);
    cout << node->data << "(" << node->counter << "), ";
    inOrder(node->right);
}

Node* BSTree::min(Node* x){
    Node* temp = x;
    while(temp->left != nullptr){
        temp = temp->left;
    }
    return temp;
}

Node* BSTree::max(Node* y){
    Node* temp = y;
    while(temp->right != nullptr){
        temp = temp->right;
    }
    return temp;
}
