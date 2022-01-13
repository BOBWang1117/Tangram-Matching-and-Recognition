#ifndef INITIALIZETANGRAM_H
#define INITIALIZETANGRAM_H

#include "divideFigure.h"

struct Triangle
{
    Point verticalAngleVertexCoordinate_X;
    Point smallCoordinate_X;
    Point bigCoordinate_X;
    vector<Point> otherPoint;

};

struct Square
{
    Point smallCoordinate_X;
    Point middleCoordinate_X_up;
    Point middleCoordinate_X_down;
    Point bigCoordinate_X;
    vector<Point> otherPoint;
};

struct Parallelogram
{
    Point smallCoordinate_X_up;
    Point bigCoordinate_X_up;
    Point smallCoordinate_X_down;
    Point bigCoordinate_X_down;
    vector<Point> otherPoint;
};

class IT //Initialize Tangram
{
private:
    int maxCoordinate_X;

    int maxCoordinate_Y;

    vector<Point> pointInput_LT;

    vector<Point> pointInput_MT;

    vector<Point> pointInput_ST;

    vector<Point> pointInput_SQ;

    vector<Point> pointInput_PA;

    vector<Point> pointResult_LT;

    vector<Point> pointResult_MT;

    vector<Point> pointResult_ST;

    vector<Point> pointResult_SQ;

    vector<Point> pointResult_PA;

    void Initialize_Tangram_Figures_Vertex();

    void Max_Coordinate_X_and_Y(vector<Point> pointInput);

    void Initialize_Tangram();

    void Initialize_Tangram_LT();

    void Initialize_Tangram_MT();

    void Initialize_Tangram_ST();

    void Initialize_Tangram_SQ();

    void Initialize_Tangram_PA();

public:
    IT(int number);

    Triangle LT_1;

    Triangle LT_2;

    Triangle MT;

    Triangle ST_1;

    Triangle ST_2;

    Square SQ;

    Parallelogram PA;

    ~IT();
};


#endif
