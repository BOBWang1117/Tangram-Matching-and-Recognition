#include "searchmethod.h"

searchMethod::searchMethod(vector<Point> inputSearchResult, int searchNumber)
{
    this->searchNumber = searchNumber;
    this->inputSearchResult = inputSearchResult;
}

/*
* Description:	This is a selecting method, it will followed by user
*/

void searchMethod::Matching_Search_Method()
{
    switch (searchNumber)
    {
    case 1:		DFS(); break;
    case 2:		BFS(); break;
    case 3:		Greedy_Search(); break;
    case 4:		A_Star(); break;
    }
}

/*
* Description:	This is DFS Search, we can get a vector<Point> to achieve efficient search
*/

void searchMethod::DFS()
{
    Point p;
    stack<Point> sequence;
    sequence.push(inputSearchResult[0]);
    inputSearchResult[0].arrived = true;
    searchResult.push_back(inputSearchResult[0]);

    while (!sequence.empty())
    {
        p = sequence.top();
        p.arrived = true;
        if (p.up_right != nullptr && p.up_right->arrived == false)
        {
            p.up_right->arrived = true;
            sequence.push(*p.up_right);
            searchResult.push_back(*p.up_right);
        }
        else if (p.right != nullptr && p.right->arrived == false)
        {
            p.right->arrived = true;
            sequence.push(*p.right);
            searchResult.push_back(*p.right);
        }
        else if (p.down_right != nullptr && p.down_right->arrived == false)
        {
            p.down_right->arrived = true;
            sequence.push(*p.down_right);
            searchResult.push_back(*p.down_right);
        }
        else if (p.up != nullptr && p.up->arrived == false)
        {
            p.up->arrived = true;
            sequence.push(*p.up);
            searchResult.push_back(*p.up);
        }
        else
        {
            sequence.pop();
        }

    }
}

/*
* Description:	This is BFS Search, we can get a vector<Point> to achieve efficient search
*/

void searchMethod::BFS()
{
    Point p;
    queue<Point> sequence;
    sequence.push(inputSearchResult[0]);
    inputSearchResult[0].arrived = true;

    while (!sequence.empty())
    {
        p = sequence.front();
        p.arrived = true;

        if (p.up != nullptr && p.up->arrived == false)
        {
            p.up->arrived = true;
            sequence.push(*p.up);
        }
        if (p.up_right != nullptr && p.up_right->arrived == false)
        {
            p.up_right->arrived = true;
            sequence.push(*p.up_right);
        }
        if (p.right != nullptr && p.right->arrived == false)
        {
            p.right->arrived = true;
            sequence.push(*p.right);
        }
        if (p.down_right != nullptr && p.down_right->arrived == false)
        {
            p.down_right->arrived = true;
            sequence.push(*p.down_right);
        }

        searchResult.push_back(p);
        sequence.pop();
    }

}

/*
* Description:	This is Greedy Search, we can get a vector<Point> to achieve efficient search
*/

void searchMethod::Greedy_Search()
{
    Point p;
    stack<Point> greedySearchMethod;//greedySearchMethod
    greedySearchMethod.push(inputSearchResult[0]);
    inputSearchResult[0].arrived = true;
    searchResult.push_back(inputSearchResult[0]);

    while (!greedySearchMethod.empty())
    {
        p = greedySearchMethod.top();
        p.arrived = true;
        if (p.up_right != nullptr && p.up_right->arrived == false)
        {
            p.up_right->arrived = true;
            greedySearchMethod.push(*p.up_right);
            searchResult.push_back(*p.up_right);
        }
        else if (p.right != nullptr && p.right->arrived == false)
        {
            p.right->arrived = true;
            greedySearchMethod.push(*p.right);
            searchResult.push_back(*p.right);
        }
        else if (p.down_right != nullptr && p.down_right->arrived == false)
        {
            p.down_right->arrived = true;
            greedySearchMethod.push(*p.down_right);
            searchResult.push_back(*p.down_right);
        }
        else if (p.up != nullptr && p.up->arrived == false)
        {
            p.up->arrived = true;
            greedySearchMethod.push(*p.up);
            searchResult.push_back(*p.up);
        }
        else
        {
            greedySearchMethod.pop();
        }

    }
}

/*
* Description:	This is A* Search, we can get a vector<Point> to achieve efficient search
*/
void searchMethod:: A_Star()
{
    Point p;
    stack<Point> A_StarVariable;
    A_StarVariable.push(inputSearchResult[0]);
    inputSearchResult[0].arrived = true;
    searchResult.push_back(inputSearchResult[0]);

    while (!A_StarVariable.empty())
    {
        p = A_StarVariable.top();
        p.arrived = true;
        if (p.up_right != nullptr && p.up_right->arrived == false)
        {
            p.up_right->arrived = true;
            searchResult.push_back(*p.up_right);
            A_StarVariable.push(*p.up_right);
        }
        else if (p.right != nullptr && p.right->arrived == false)
        {
            p.right->arrived = true;
            searchResult.push_back(*p.right);
            A_StarVariable.push(*p.right);
        }
        else if (p.down_right != nullptr && p.down_right->arrived == false)
        {
            p.down_right->arrived = true;
            searchResult.push_back(*p.down_right);
            A_StarVariable.push(*p.down_right);
        }
        else if (p.up != nullptr && p.up->arrived == false)
        {
            p.up->arrived = true;
            searchResult.push_back(*p.up);
            A_StarVariable.push(*p.up);
        }
        else
        {
            A_StarVariable.pop();
        }

    }
}

void searchMethod::Change_Arrive_To_False()
{
    for (unsigned int i = 0; i < searchResult.size(); i++)
    {
        searchResult[i].arrived = false;
        //cout << "coordinate: " << searchResult[i].coordinate_X << " ," << searchResult[i].coordinate_Y << endl;//can delete
    }
}

vector<Point> searchMethod::doit()
{
    Matching_Search_Method();
    Change_Arrive_To_False();
    return searchResult;
}
