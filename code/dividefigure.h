/*
* Description:	This header File is able to divide the 13 figures, in this
*				file we create some functions to solve the problem
*/
#ifndef DIVIDEFIGURE_H
#define DIVIDEFIGURE_H


#include<vector>
#include <iostream>

using namespace std;

/*
* Description:	This is a structure which called Point, every point may have neighbors,
*				so we have some Point* to store them
*/
struct Point
{
    int coordinate_X;
    int coordinate_Y;
    Point* up;
    Point* down;
    Point* left;
    Point* right;
    Point* up_left;
    Point* up_right;
    Point* down_left;
    Point* down_right;
    bool arrived;
};

class TCFS		//Tangram Convex Figures Set(TCFS)
{
private:

    int tangramNumber;

    int maxCoordinate_X;

    int maxCoordinate_Y;

    vector<Point> pointInput;		//This is the figures vertex coordinates

    vector<Point> pointResult;		//In this figer, how many point they have

    vector<Point> pointMapResult;	//we can connect these point, then it will be look like a map

    void Tangram_Convex_Figures_Vertex();

    void Max_Coordinate_X_and_Y();	//calculate max coordinate X and max coordinate Y in figure

    void Tangram_Convex_Figures_Inside_Vertex();

    void ConnectOtherPoint();	//connect the points

public:

    TCFS(int Tangram_Convex_Figures_Number);	//we are able to get user input, Tangram_Convex_Figures_Number
    void SetP(int Tangram_Convex_Figures_Number);
    vector<Point>& doit();

};
#endif // DIVIDEFIGURE_H
