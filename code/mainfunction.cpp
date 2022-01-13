#include "mainfunction.h"

using namespace std;

vector<vector<TangramGraph>> process(int tangramNumber, int searchNumber)
{
    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();//calculate begaing time

    vector<vector<TangramGraph>> finalResult;	//store the final result
    Tangram* Tan = new Tangram(tangramNumber, searchNumber);	//
    finalResult = Tan->finalFunction();
    delete Tan;		//free the memory
    cout << endl;
    cout << "FinalResult1: " << finalResult.size() << endl;	//calculate how many solutions we have

    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();//calculate finish time
    chrono::duration<double, std::milli> first_time_span = t2 - t1;//Calculate the time difference
    std::cout << "Tangram: Time is " << first_time_span.count() << " ms" << std::endl;//print the different time


    return finalResult;
}
