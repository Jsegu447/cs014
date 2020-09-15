#include <iostream>
#include "WordLadder.h"
using namespace std;
int main(int argc, char* argv[]){
    string fileName = argv[1];
    WordLadder w1(fileName);
    w1.outputLadder("Same", "Came", "no");
}
