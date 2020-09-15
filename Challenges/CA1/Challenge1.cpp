#include <iostream>
#include <vector>
#include <fstream>
#include "Survivors.h"
using namespace std;
bool loadPpl(vector <string>&, string );
int main(int argc, char* argv[]){
    vector <string> ppl;
    Survivors group1;
    Person* prev;
    Person* curr;
    string file = argv[1];
    bool oneLeft = false;
    int start = 0;
    int skip = 0;
    loadPpl(ppl, file);
    for (unsigned i = 0; i < ppl.size(); i++){
        group1.addSurvivor(ppl.at(i));
    }
    cout << "Starting Person num: " << endl;
    cin >> start;
    while(start < 1 || start > ppl.size() ){
        cin.clear();
        cin.ignore();
        cout << "Not valid; Starting Person num: " << endl;
        cin >> start;
    }
    cout << "How many to skip: " << endl;
    cin >> skip;
    while(skip < 2 || skip > ppl.size()){
        cin.clear();
        cin.ignore();
        cout << "Not valid; How many to skip: " << endl;
        cin >> skip;
    }
    skip -= 1;
    prev = group1.setPrev(start);
    curr = group1.setCurr(start);
    while (oneLeft == false) {
        for (unsigned i = 0; i < skip; i++) {
            prev = curr;
            curr = curr->nxtPerson;
        }
        oneLeft = group1.removeSurvivor(curr, prev);
    }
    cout << curr->name << " has survived." << endl;

    return 0;
}

bool loadPpl(vector <string>& ppls, string fileName){
    ifstream inFS;
    inFS.open(fileName);
    string name;
    
    if(!inFS.is_open()){
        return false;
    }
    
    while(getline(inFS, name)){
        ppls.push_back(name);
    }
    return true;
}
