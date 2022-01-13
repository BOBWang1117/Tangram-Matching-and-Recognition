/*
* Description:	This header File is able to Match, select and delete some roads(Point to Point)
*/
#ifndef TANGRAM_H
#define TANGRAM_H

#include "searchmethod.h"

//Test time library
#include <ctime>//can delete
#include <ratio>//can delete
#include <chrono>//can delete

/*
* Description:	This is a structure which called TangramGraph, every Tangram Graph
*				has its graphID, so we can store the graphID and their vertex to
*				indicates their position in the coordinate system
*/
struct TangramGraph
{
    int graphID;
    vector<pair<int, int>> point;	//pair<int,int> : (int coordinate_X, int coordinate_Y)
};

/*
* Description:	This is a structure which called info, every Tangram Graph
*				can use graphID, rotationID, and their Vertex coordinates to
*				indicates their position in the coordinate system
*/
struct info
{
    int coordinate_X;
    int coordinate_Y;
    int graphID;
    int rotationID;
};

class Tangram
{
private:
    int tangramNumber;

    int searchNumber;

    vector<Point> inputSearch;		//	This is a Point Vector in this vector, we have the data which is
                                    //	used cualculating by artificial intelligence algorithm
    vector<Point> searchResult;

    vector<Point>& Initalize_Class_TCFS();

    vector<Point> Initalize_Class_Search();

    void doit();

public:

    Tangram(int tangramNumber, int searchNumber);

    vector<vector<TangramGraph>> finalFunction();

};

#endif
