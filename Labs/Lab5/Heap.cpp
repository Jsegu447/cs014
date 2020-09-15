// algorithm help from algorithm.com
// working with annie wang
// used lependu slides
#include "PrintJob.h"
#include "Heap.h"
#include <iostream>
using namespace std;

Heap::Heap(): numItems(0){
}

void Heap::enqueue(PrintJob* newJob){
    if(numItems + 1 <= MAX_HEAP_SIZE ){
        if(numItems == 0){
            arr[0] = newJob;
            numItems++;
        }
        else{
            int x = numItems;
            while(x > 0 && arr[(x-1)/2]->getPriority() < newJob->getPriority()){
                arr[x] = arr[(x-1)/2];
                x = (x-1)/2;
            }
            arr[x] = newJob;
            ++numItems;
            }
    }
}
void Heap::dequeue(){
    if(numItems == 0){
        return;
    }
    arr[0]->createHole();
    trickleDown(0);
    numItems--;
}

PrintJob* Heap::highest(){
    if (numItems == 0) {
        return nullptr;
    }
    return arr[0];
}
void Heap::print(){
    if( numItems > 0){
    cout << "Priority: " << arr[0]->getPriority() << ", Job Number: " << arr[0]->getJobNumber() << ", Number of Pages: " << arr[0]->getPages() << endl;
    }
    return;
}

void Heap::trickleDown(int k){
    int large;
    int l = 2 * k + 1;
    int r = 2 * k + 2;
    if(l < numItems && arr[l]->getPriority() > arr[k]->getPriority()){
        large = l;
    }
    else{
        large = k;
    }
    if(r < numItems && arr[r]->getPriority() > arr[large]->getPriority()){
          large = r;
      }
    if (large != k){
        swap(arr[k], arr[large]);
        trickleDown(large);
    }
}




