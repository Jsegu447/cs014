// algorithm help from algorithm.com
// working with annie wang
#include "PrintJob.h"

PrintJob::PrintJob ( int setP, int setJ, int numP ):priority(setP), jobNumber(setJ), numPages(numP){}
int PrintJob::getPriority ( ){
    return priority;
}

int PrintJob::getJobNumber ( ){
    return jobNumber;
}

int PrintJob::getPages ( ){
    return numPages;
}

void PrintJob::createHole(){
    priority = 0;
}
