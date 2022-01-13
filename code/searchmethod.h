/*
* Description:	This header File is able to use artificial intelligence algorithms,
*				In this file, we have some search methods:
                uninformed Search: DFS search and BFS search
                Informed Search: Greedy Search and A* search
*/
#ifndef SEARCHMETHOD_H
#define SEARCHMETHOD_H
#include "dividefigure.h"
#include <stack>
#include <queue>

class searchMethod
{
private:
    int searchNumber;

    vector<Point> searchResult;

    vector<Point> inputSearchResult;

    void Matching_Search_Method();		//According to the number entered by the user, select the algorithm to use

    void DFS();

    void BFS();

    void Greedy_Search();

    void A_Star();

    void Change_Arrive_To_False();	//Assign all the arrive information stored in Point to false

public:
    searchMethod(vector<Point> inputSearchResult, int searchNumber);

    vector<Point> doit();

};


#endif // SEARCHMETHOD_H
