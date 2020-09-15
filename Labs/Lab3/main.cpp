#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;


string int2str(int n) {
   ostringstream ssout;
   ssout << n;
   return ssout.str();
}

int genRandInt(int low, int high) {
    return low + rand() % (high - low + 1);
}




template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index){
    if ( index > vals.size()-1 || index < 0){
    throw out_of_range("Invalid index");
    }
       unsigned minDex = index;
       T item = vals.at(index);
        for(unsigned i = index; i < vals.size(); i++){
            if( item >= vals.at(i)){
                item = vals.at(i);
                minDex = i;
            }
        }
        return minDex;
}

template<typename T>
void selection_sort(vector<T>& vals){
    for(unsigned i = 0; i < vals.size(); i ++){
        unsigned minDex = min_index(vals, i);
        T temp = vals.at(i);
        vals.at(i) = vals.at(minDex);
        vals.at(minDex) = temp;
    }
}


vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++){
            vals.push_back(c);
            c++;
        }
        return vals;
    }

template<typename T>
T getElement(vector<T> vals, int index){
    unsigned num = index;
    if ( num > vals.size()-1 || num < 0){
    throw out_of_range("Invalid index");
    }
    return vals.at(index);
}

//pendu test

bool testPassed() {
   srand(time(0));
   ostringstream ssout;
   string actual, expected;
   int randValue;
   vector<int> values;
   vector<int> expectedValues;
   int numValues;
   
   selection_sort(values);
   //ssout << values;
   for (unsigned i = 0; i < values.size(); ++i) {
       ssout << values.at(i);
       if(i != values.size()-1)
           ssout<< " ";
   }
   actual = ssout.str();
   if (actual != expected) {
      cout << "selection_sort did not work when called on an empty vector of integers." << endl;
      cout << "Expected: " << expected << endl;
      cout << "Actual: " << actual << endl;
      return false;
   }
   
   randValue = genRandInt(-20, -10);
   values.push_back(randValue);
   expectedValues.push_back(randValue);
   selection_sort(values);
   expected = int2str(randValue);
   ssout.str("");
   //ssout << values;
   for (unsigned i = 0; i < values.size(); ++i) {
       ssout << values.at(i);
       if(i != values.size()-1)
           ssout<< " ";
   }
   actual = ssout.str();
   if (actual != expected) {
      cout << "selection_sort did not work when called on a vector with a single integer." << endl;
      cout << "Expected: " << expected << endl;
      cout << "Actual: " << actual << endl;
      return false;
   }

   randValue = genRandInt(-9, -1);
   values.push_back(randValue);
   expectedValues.push_back(randValue);
   selection_sort(values);
   expected = int2str(expectedValues.at(0)) + " " + int2str(expectedValues.at(1));
   ssout.str("");
   //ssout << values;
   for (unsigned i = 0; i < values.size(); ++i) {
       ssout << values.at(i);
       if(i != values.size()-1)
           ssout<< " ";
   }
   actual = ssout.str();
   if (actual != expected) {
      cout << "selection_sort did not work when called on a vector with 2 integers." << endl;
      cout << "Expected: " << expected << endl;
      cout << "Actual: " << actual << endl;
      return false;
   }
   
   numValues = genRandInt(10, 20);
   
   for (int n = 0; n < numValues; ++n) {
      randValue = genRandInt(-10, 20);
      values.push_back(randValue);
      expectedValues.push_back(randValue);
   }
   selection_sort(values);
   sort(expectedValues.begin(), expectedValues.end());
   expected = int2str(expectedValues.at(0));
   for (unsigned i = 1; i < expectedValues.size(); ++i) {
      expected = expected + " " + int2str(expectedValues.at(i));
   }
   ssout.str("");
   //ssout << values;
   for (unsigned i = 0; i < values.size(); ++i) {
       ssout << values.at(i);
       if(i != values.size()-1)
           ssout<< " ";
   }
   actual = ssout.str();
   if (actual != expected) {
      cout << "selection_sort did not work when called on a vector with more than 2 integers." << endl;
      cout << "Expected: " << expected << endl;
      cout << "Actual: " << actual << endl;
      return false;
   }
   
   return true;
}











int main(){
  //part a
   
    vector<int> nums;
    int user = 0;
    cout << "insert nums (-1 to stop)" << endl;
    cin >> user;
    while(user != -1){
        nums.push_back(user);
        cout << "insert num" << endl;
        cin >> user;
    }
     selection_sort(nums);
    cout << endl;
    for ( unsigned i = 0; i < nums.size(); i++){
        cout << nums.at(i) << endl;
    }
 
    vector<char> chars;
    char stuff;
    cout << "insert char ( z to stop )" << endl;
    cin >> stuff;
    while(stuff != 'z'){
        chars.push_back(stuff);
        cout << "insert char" << endl;
        cin >> stuff;
    }
    selection_sort(chars);
    cout << endl;
    for ( unsigned i = 0; i < chars.size(); i++){
        cout << chars.at(i) << endl;
    }
   
   
    
    vector<string> strings;
       string thangs;
       cout << "insert string ( \"stop\" to stop )" << endl;
       cin >> thangs;
       while(thangs != "stop"){
           strings.push_back(thangs);
           cout << "insert string" << endl;
           cin >> thangs;
       }
    cout << endl;
       selection_sort(strings);
       for ( unsigned i = 0; i < strings.size(); i++){
           cout << strings.at(i) << endl;
       }
   
    bool test = testPassed();
       if(test){
           cout << "no error" << endl;
       }
    
    
    
       cout << "Done part 1" << endl;
    
    //part b

   
    srand(time(0));
        vector<char> vals = createVector();
        char curChar;
        int index;
        int numOfRuns = 10;
        while(--numOfRuns >= 0){
            try{
            cout << "Enter a number: " << endl;
            cin >> index;
            curChar = getElement(vals,index);
            cout << "Element located at " << index << ": is " << curChar << endl;
            }
       catch(out_of_range& excpt){
           cout << "out of range exception occured" << endl;
       }
        
    }
    
    
    
    
  
    return 0;
}

