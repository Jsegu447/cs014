// Worked with Annie wang
// reverse algorigthm from algorithm.com
#include "WordLadder.h"
#include <fstream>
#include <iostream>
#include <stack>
#include <queue>
#include <list>
using namespace std;

WordLadder::WordLadder(const string& file){
    ifstream inFS;
    string word;
    inFS.open(file);
        if (!inFS.is_open()){
            cout << ("Error opening file.") << endl;
            return;
        }
        while (inFS >> word){
            if(word.length() == 5){
                dict.push_back(word);
            }
            else{
                cout << "Dictionary only stores words with length of 5" << endl;
                return;
            }
        }
        inFS.close();
    }

void WordLadder::stackRev(stack<string>& st, ofstream& file) {
    if(st.empty()){
        return;
    }
    stack<string>temp;
          while(st.size()>0){
              temp.push(st.top());
              st.pop();
          }

         

          while(temp.size()>0){

              string word = temp.top();
              temp.pop();
              file << word << " ";
          }
}

bool WordLadder::wordDiff(const string& start, const string& dict){
    int diff = 0;
    for(unsigned i = 0; i < start.size(); i++){
        if(start.at(i) != dict.at(i)){
            diff++;
        }
    }
    if(diff <= 1){
        return true;
    }
    return false;
}

void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile){
    string last;
    ofstream outFS;
    outFS.open(outputFile);
    if(!outFS.is_open()){
        return;
    }
    
    for(list<string>::iterator i = dict.begin(); i != dict.end(); i++){
        last = *i;
        if(start == last){
            break;
        }
    }
    if(last != start){
        outFS << "No Word Ladder Found" << endl;
        return;
    }
    for(list<string>::iterator i = dict.begin(); i != dict.end(); i++){
        last = *i;
        if(end == last){
            break;
        }
    }
    
    if(last != end){
        outFS << "No Word Ladder Found" << endl;
        return;
    }
    if(start == end){
        outFS << start << endl;
        return;
    }
    stack<string> wordLad;
    queue<stack<string>> ladStack;
    wordLad.push(start);
    ladStack.push(wordLad);
    while(!ladStack.empty()){
        string word1 = ladStack.front().top();
        for(list<string>::iterator i = dict.begin(); i != dict.end(); ++i){
            string word = *i;
            if(wordDiff(word1, word)){
                stack<string> newStack = ladStack.front();
                newStack.push(*i);
             
                if(word == end){
                    stack<string> temp = newStack;
                    stackRev(temp, outFS);
//                    while(!newStack.empty()){
//                        outFS << newStack.top() << " ";
//                        newStack.pop();
//                    }
                    outFS << endl;
                    return;
                }
                ladStack.push(newStack);
                i = dict.erase(i);
                i = dict.begin();
            }
        }
         ladStack.pop();
    }
    outFS << "No Word Ladder Found." << endl;
}


