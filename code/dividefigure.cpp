#include "dividefigure.h"

using namespace std;

/*
* There is the class TCFS	//Tangram Convex Figures Set(TCFS)
*/


TCFS::TCFS(int Tangram_Convex_Figures_Number)
{
    SetP(Tangram_Convex_Figures_Number);
}

void TCFS::SetP(int Tangram_Convex_Figures_Number)
{
    tangramNumber = Tangram_Convex_Figures_Number;

    //initialized the member variable maxCoordinate_X and maxCoordinate_Y
    maxCoordinate_X = 0;
    maxCoordinate_Y = 0;
    pointInput.clear();
    pointResult.clear();
    pointMapResult.clear();
}

void TCFS::Tangram_Convex_Figures_Vertex()
{
    pointInput.clear();		//clear the vector

    switch (tangramNumber)
    {
    case 1:		//This is the 1st Tangram Convex Figure
        pointInput.push_back({ 0,0 });
        pointInput.push_back({ 8,0 });
        pointInput.push_back({ 4,4 });
        break;

    case 2:		//This is the 2nd Tangram Convex Figure
        pointInput.push_back({ 0,0 });
        pointInput.push_back({ 4,0 });
        pointInput.push_back({ 4,4 });
        pointInput.push_back({ 0,4 });
        break;

    case 3:		//This is the 3rd Tangram Convex Figure
        pointInput.push_back({ 0,2 });
        pointInput.push_back({ 2,0 });
        pointInput.push_back({ 6,4 });
        pointInput.push_back({ 4,6 });
        break;

    case 4:		//This is the 4th Tangram Convex Figure
        pointInput.push_back({ 0,0 });
        pointInput.push_back({ 4,0 });
        pointInput.push_back({ 8,4 });
        pointInput.push_back({ 4,4 });
        break;

    case 5:		//This is the 5th Tangram Convex Figure
        pointInput.push_back({ 0,0 });
        pointInput.push_back({ 6,6 });
        pointInput.push_back({ 2,6 });
        pointInput.push_back({ 0,4 });
        break;

    case 6:		//This is the 6th Tangram Convex Figure
        pointInput.push_back({ 0,0 });
        pointInput.push_back({ 5,5 });
        pointInput.push_back({ 3,7 });
        pointInput.push_back({ 0,4 });
        break;

    case 7:		//This is the 7th Tangram Convex Figure
        pointInput.push_back({ 0,0 });
        pointInput.push_back({ 6,0 });
        pointInput.push_back({ 2,4 });
        pointInput.push_back({ 0,4 });
        break;

    case 8:		//This is the 8th Tangram Convex Figure
        pointInput.push_back({ 0,0 });
        pointInput.push_back({ 6,0 });
        pointInput.push_back({ 7,1 });
        pointInput.push_back({ 7,3 });
        pointInput.push_back({ 3,3 });
        break;

    case 9:		//This is the 9th Tangram Convex Figure
        pointInput.push_back({ 0,1 });
        pointInput.push_back({ 1,0 });
        pointInput.push_back({ 5,4 });
        pointInput.push_back({ 4,5 });
        pointInput.push_back({ 0,5 });
        break;

    case 10:	//This is the 10th Tangram Convex Figure
        pointInput.push_back({ 0,2 });
        pointInput.push_back({ 2,0 });
        pointInput.push_back({ 4,0 });
        pointInput.push_back({ 6,2 });
        pointInput.push_back({ 4,4 });
        pointInput.push_back({ 2,4 });
        break;

    case 11:	//This is the 11th Tangram Convex Figure
        pointInput.push_back({ 0,1 });
        pointInput.push_back({ 1,0 });
        pointInput.push_back({ 5,0 });
        pointInput.push_back({ 7,2 });
        pointInput.push_back({ 6,3 });
        pointInput.push_back({ 2,3 });
        break;

    case 12:	//This is the 12th Tangram Convex Figure
        pointInput.push_back({ 0,2 });
        pointInput.push_back({ 2,0 });
        pointInput.push_back({ 5,3 });
        pointInput.push_back({ 3,5 });
        pointInput.push_back({ 6,3 });
        pointInput.push_back({ 2,3 });
        break;

    case 13:	//This is the 13th Tangram Convex Figure
        pointInput.push_back({ 0,0 });
        pointInput.push_back({ 2,0 });
        pointInput.push_back({ 5,3 });
        pointInput.push_back({ 5,5 });
        pointInput.push_back({ 3,5 });
        pointInput.push_back({ 0,2 });
        break;
    }

}


/*
* This is calculate the max X coordinate and max Y coordinate
*/
void TCFS::Max_Coordinate_X_and_Y()
{
    for (unsigned int i = 0; i < pointInput.size(); i++)
    {
        if (pointInput[i].coordinate_X > maxCoordinate_X)
        {
            maxCoordinate_X = pointInput[i].coordinate_X;
        }
        if (pointInput[i].coordinate_Y > maxCoordinate_Y)
        {
            maxCoordinate_Y = pointInput[i].coordinate_Y;
        }
    }
}

/*
*  Description: Initialize user selection tangram convex figures
*/
bool Tangram_Convex_Figures_1(Point p)
{
    bool condition_1 = false;
    bool condition_2 = false;
    bool condition_3 = false;
    bool all_condition_true = false;

    if (p.coordinate_Y <= p.coordinate_X)
    {
        condition_1 = true;
    }
    if (p.coordinate_Y >= 0)
    {
        condition_2 = true;
    }
    if (p.coordinate_Y <= -p.coordinate_X + 8)
    {
        condition_3 = true;
    }


    all_condition_true = condition_1 && condition_2 && condition_3;

    if (all_condition_true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Tangram_Convex_Figures_2(Point p)
{
    bool condition_1 = false;
    bool condition_2 = false;
    bool condition_3 = false;
    bool condition_4 = false;
    bool all_condition_true = false;

    if (p.coordinate_Y >= 0)
    {
        condition_1 = true;
    }
    if (p.coordinate_Y <= 4)
    {
        condition_2 = true;
    }
    if (p.coordinate_X >= 0)
    {
        condition_3 = true;
    }
    if (p.coordinate_X <= 4)
    {
        condition_4 = true;
    }


    all_condition_true = condition_1 && condition_2 && condition_3 && condition_4;
    if (all_condition_true)
    {
        return true;
    }
    else
    {
        return false;
    }

}
bool Tangram_Convex_Figures_3(Point p)
{
    bool condition_1 = false;
    bool condition_2 = false;
    bool condition_3 = false;
    bool condition_4 = false;
    bool all_condition_true = false;

    if (p.coordinate_Y >= -p.coordinate_X + 2)
    {
        condition_1 = true;
    }
    if (p.coordinate_Y >= p.coordinate_X - 2)
    {
        condition_2 = true;
    }
    if (p.coordinate_Y <= -p.coordinate_X + 10)
    {
        condition_3 = true;
    }
    if (p.coordinate_Y <= p.coordinate_X + 2)
    {
        condition_4 = true;
    }


    all_condition_true = condition_1 && condition_2 && condition_3 && condition_4;
    if (all_condition_true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Tangram_Convex_Figures_4(Point p)
{
    bool condition_1 = false;
    bool condition_2 = false;
    bool condition_3 = false;
    bool condition_4 = false;
    bool all_condition_true = false;

    if (p.coordinate_Y <= p.coordinate_X)
    {
        condition_1 = true;
    }
    if (p.coordinate_Y >= 0)
    {
        condition_2 = true;
    }
    if (p.coordinate_Y >= p.coordinate_X - 4)
    {
        condition_3 = true;
    }
    if (p.coordinate_Y <= 4)
    {
        condition_4 = true;
    }


    all_condition_true = condition_1 && condition_2 && condition_3 && condition_4;
    if (all_condition_true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Tangram_Convex_Figures_5(Point p)
{
    bool condition_1 = false;
    bool condition_2 = false;
    bool condition_3 = false;
    bool condition_4 = false;
    bool all_condition_true = false;

    if (p.coordinate_Y >= p.coordinate_X)
    {
        condition_1 = true;
    }
    if (p.coordinate_Y <= 6)
    {
        condition_2 = true;
    }
    if (p.coordinate_Y <= p.coordinate_X + 4)
    {
        condition_3 = true;
    }
    if (p.coordinate_X >= 0)
    {
        condition_4 = true;
    }


    all_condition_true = condition_1 && condition_2 && condition_3 && condition_4;
    if (all_condition_true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Tangram_Convex_Figures_6(Point p)
{
    bool condition_1 = false;
    bool condition_2 = false;
    bool condition_3 = false;
    bool condition_4 = false;
    bool all_condition_true = false;

    if (p.coordinate_Y >= p.coordinate_X)
    {
        condition_1 = true;
    }
    if (p.coordinate_Y <= -p.coordinate_X + 10)
    {
        condition_2 = true;
    }
    if (p.coordinate_Y <= p.coordinate_X + 4)
    {
        condition_3 = true;
    }
    if (p.coordinate_X >= 0)
    {
        condition_4 = true;
    }


    all_condition_true = condition_1 && condition_2 && condition_3 && condition_4;
    if (all_condition_true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Tangram_Convex_Figures_7(Point p)
{
    bool condition_1 = false;
    bool condition_2 = false;
    bool condition_3 = false;
    bool condition_4 = false;
    bool all_condition_true = false;

    if (p.coordinate_Y >= 0)
    {
        condition_1 = true;
    }
    if (p.coordinate_Y <= -p.coordinate_X + 6)
    {
        condition_2 = true;
    }
    if (p.coordinate_Y <= 4)
    {
        condition_3 = true;
    }
    if (p.coordinate_X >= 0)
    {
        condition_4 = true;
    }


    all_condition_true = condition_1 && condition_2 && condition_3 && condition_4;
    if (all_condition_true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Tangram_Convex_Figures_8(Point p)
{
    bool condition_1 = false;
    bool condition_2 = false;
    bool condition_3 = false;
    bool condition_4 = false;
    bool condition_5 = false;
    bool all_condition_true = false;

    if (p.coordinate_Y >= 0)
    {
        condition_1 = true;
    }
    if (p.coordinate_Y >= p.coordinate_X - 6)
    {
        condition_2 = true;
    }
    if (p.coordinate_X <= 7)
    {
        condition_3 = true;
    }
    if (p.coordinate_Y <= 3)
    {
        condition_4 = true;
    }
    if (p.coordinate_Y <= p.coordinate_X)
    {
        condition_5 = true;
    }


    all_condition_true = condition_1 && condition_2 && condition_3 && condition_4 && condition_5;
    if (all_condition_true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Tangram_Convex_Figures_9(Point p)
{
    bool condition_1 = false;
    bool condition_2 = false;
    bool condition_3 = false;
    bool condition_4 = false;
    bool condition_5 = false;
    bool all_condition_true = false;

    if (p.coordinate_Y >= -p.coordinate_X + 1)
    {
        condition_1 = true;
    }
    if (p.coordinate_Y >= p.coordinate_X - 1)
    {
        condition_2 = true;
    }
    if (p.coordinate_Y <= -p.coordinate_X + 9)
    {
        condition_3 = true;
    }
    if (p.coordinate_Y <= 5)
    {
        condition_4 = true;
    }
    if (p.coordinate_X >= 0)
    {
        condition_5 = true;
    }


    all_condition_true = condition_1 && condition_2 && condition_3 && condition_4 && condition_5;
    if (all_condition_true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Tangram_Convex_Figures_10(Point p)
{
    bool condition_1 = false;
    bool condition_2 = false;
    bool condition_3 = false;
    bool condition_4 = false;
    bool condition_5 = false;
    bool condition_6 = false;
    bool all_condition_true = false;

    if (p.coordinate_Y >= -p.coordinate_X + 2)
    {
        condition_1 = true;
    }
    if (p.coordinate_Y >= 0)
    {
        condition_2 = true;
    }
    if (p.coordinate_Y >= p.coordinate_X - 4)
    {
        condition_3 = true;
    }
    if (p.coordinate_Y <= -p.coordinate_X + 8)
    {
        condition_4 = true;
    }
    if (p.coordinate_Y <= 4)
    {
        condition_5 = true;
    }
    if (p.coordinate_Y <= p.coordinate_X + 2)
    {
        condition_6 = true;
    }


    all_condition_true = condition_1 && condition_2 && condition_3 && condition_4 && condition_5 && condition_6;
    if (all_condition_true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Tangram_Convex_Figures_11(Point p)
{
    bool condition_1 = false;
    bool condition_2 = false;
    bool condition_3 = false;
    bool condition_4 = false;
    bool condition_5 = false;
    bool condition_6 = false;
    bool all_condition_true = false;

    if (p.coordinate_Y >= -p.coordinate_X + 1)
    {
        condition_1 = true;
    }
    if (p.coordinate_Y >= 0)
    {
        condition_2 = true;
    }
    if (p.coordinate_Y >= p.coordinate_X - 5)
    {
        condition_3 = true;
    }
    if (p.coordinate_Y <= -p.coordinate_X + 9)
    {
        condition_4 = true;
    }
    if (p.coordinate_Y <= 3)
    {
        condition_5 = true;
    }
    if (p.coordinate_Y <= p.coordinate_X + 1)
    {
        condition_6 = true;
    }


    all_condition_true = condition_1 && condition_2 && condition_3 && condition_4 && condition_5 && condition_6;
    if (all_condition_true)
    {
        return true;
    }
    else
    {
        return false;
    }

}
bool Tangram_Convex_Figures_12(Point p)
{
    bool condition_1 = false;
    bool condition_2 = false;
    bool condition_3 = false;
    bool condition_4 = false;
    bool condition_5 = false;
    bool condition_6 = false;
    bool all_condition_true = false;

    if (p.coordinate_Y >= -p.coordinate_X + 2)
    {
        condition_1 = true;
    }
    if (p.coordinate_Y >= p.coordinate_X - 2)
    {
        condition_2 = true;
    }
    if (p.coordinate_Y <= -p.coordinate_X + 8)
    {
        condition_3 = true;
    }
    if (p.coordinate_Y <= 5)
    {
        condition_4 = true;
    }
    if (p.coordinate_Y <= p.coordinate_X + 4)
    {
        condition_5 = true;
    }
    if (p.coordinate_X >= 0)
    {
        condition_6 = true;
    }


    all_condition_true = condition_1 && condition_2 && condition_3 && condition_4 && condition_5 && condition_6;
    if (all_condition_true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Tangram_Convex_Figures_13(Point p)
{
    bool condition_1 = false;
    bool condition_2 = false;
    bool condition_3 = false;
    bool condition_4 = false;
    bool condition_5 = false;
    bool condition_6 = false;
    bool all_condition_true = false;

    if (p.coordinate_Y >= 0)
    {
        condition_1 = true;
    }
    if (p.coordinate_Y >= p.coordinate_X - 2)
    {
        condition_2 = true;
    }
    if (p.coordinate_X <= 5)
    {
        condition_3 = true;
    }
    if (p.coordinate_Y <= 5)
    {
        condition_4 = true;
    }
    if (p.coordinate_Y <= p.coordinate_X + 2)
    {
        condition_5 = true;
    }
    if (p.coordinate_X >= 0)
    {
        condition_6 = true;
    }


    all_condition_true = condition_1 && condition_2 && condition_3 && condition_4 && condition_5 && condition_6;
    if (all_condition_true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void TCFS::Tangram_Convex_Figures_Inside_Vertex()
{
    Point possiblePoint;
    vector<Point> possiblePointList;

    bool (*pf)(Point p) = nullptr;	//this is a function pointer

    pointResult.clear();

    switch (tangramNumber)
    {
    case 1:pf = Tangram_Convex_Figures_1; break;
    case 2:pf = Tangram_Convex_Figures_2; break;
    case 3:pf = Tangram_Convex_Figures_3; break;
    case 4:pf = Tangram_Convex_Figures_4; break;
    case 5:pf = Tangram_Convex_Figures_5; break;
    case 6:pf = Tangram_Convex_Figures_6; break;
    case 7:pf = Tangram_Convex_Figures_7; break;
    case 8:pf = Tangram_Convex_Figures_8; break;
    case 9:pf = Tangram_Convex_Figures_9; break;
    case 10:pf = Tangram_Convex_Figures_10; break;
    case 11:pf = Tangram_Convex_Figures_11; break;
    case 12:pf = Tangram_Convex_Figures_12; break;
    case 13:pf = Tangram_Convex_Figures_13; break;
    }

    for (int i = 0; i < maxCoordinate_X + 1; i++)
    {
        for (int j = 0; j < maxCoordinate_Y + 1; j++)
        {
            possiblePoint = { i,j };
            if (pf(possiblePoint) == true)
            {
                pointResult.push_back(possiblePoint);
            }
        }
    }
}

void exist(vector<Point>& pointResult, Point* p, int tangramNumber)
{
    int vectorSize = pointResult.size();
    int x = (*p).coordinate_X;
    int y = (*p).coordinate_Y;
    int state = x + y;

    //up exist
    int up_x = x;
    int up_y = y + 1;
    for (int i = 0; i < vectorSize; i++)
    {
        if (pointResult[i].coordinate_X == up_x && pointResult[i].coordinate_Y == up_y)
        {
            (*p).up = &pointResult[i];
            break;
        }
    }

    //down exist
    int down_x = x;
    int down_y = y - 1;
    for (int i = 0; i < vectorSize; i++)
    {
        if (pointResult[i].coordinate_X == down_x && pointResult[i].coordinate_Y == down_y)
        {
            (*p).down = &pointResult[i];
            break;
        }
    }

    //left exist
    int left_x = x - 1;
    int left_y = y;
    for (int i = 0; i < vectorSize; i++)
    {
        if (pointResult[i].coordinate_X == left_x && pointResult[i].coordinate_Y == left_y)
        {
            (*p).left = &pointResult[i];
            break;
        }
    }

    //right exist
    int right_x = x + 1;
    int right_y = y;
    for (int i = 0; i < vectorSize; i++)
    {
        if (pointResult[i].coordinate_X == right_x && pointResult[i].coordinate_Y == right_y)
        {
            (*p).right = &pointResult[i];
            break;
        }
    }

    if (tangramNumber == 9 || tangramNumber == 11)
    {
        if (state % 2 != 0)
        {
            //up_left exist
            int up_left_x = x - 1;
            int up_left_y = y + 1;
            for (int i = 0; i < vectorSize; i++)
            {
                if (pointResult[i].coordinate_X == up_left_x && pointResult[i].coordinate_Y == up_left_y)
                {
                    (*p).up_left = &pointResult[i];
                    break;
                }
            }

            //up_right exist
            int up_right_x = x + 1;
            int up_right_y = y + 1;
            for (int i = 0; i < vectorSize; i++)
            {
                if (pointResult[i].coordinate_X == up_right_x && pointResult[i].coordinate_Y == up_right_y)
                {
                    (*p).up_right = &pointResult[i];
                    break;
                }
            }

            //down_left exist
            int down_left_x = x - 1;
            int down_left_y = y - 1;
            for (int i = 0; i < vectorSize; i++)
            {
                if (pointResult[i].coordinate_X == down_left_x && pointResult[i].coordinate_Y == down_left_y)
                {
                    (*p).down_left = &pointResult[i];
                    break;
                }
            }

            //down_right exist
            int down_right_x = x + 1;
            int down_right_y = y - 1;
            for (int i = 0; i < vectorSize; i++)
            {
                if (pointResult[i].coordinate_X == down_right_x && pointResult[i].coordinate_Y == down_right_y)
                {
                    (*p).down_right = &pointResult[i];
                    break;
                }
            }


        }
    }
    else
    {
        if (state % 2 == 0)
        {
            //up_left exist
            int up_left_x = x - 1;
            int up_left_y = y + 1;
            for (int i = 0; i < vectorSize; i++)
            {
                if (pointResult[i].coordinate_X == up_left_x && pointResult[i].coordinate_Y == up_left_y)
                {
                    (*p).up_left = &pointResult[i];
                    break;
                }
            }

            //up_right exist
            int up_right_x = x + 1;
            int up_right_y = y + 1;
            for (int i = 0; i < vectorSize; i++)
            {
                if (pointResult[i].coordinate_X == up_right_x && pointResult[i].coordinate_Y == up_right_y)
                {
                    (*p).up_right = &pointResult[i];
                    break;
                }
            }

            //down_left exist
            int down_left_x = x - 1;
            int down_left_y = y - 1;
            for (int i = 0; i < vectorSize; i++)
            {
                if (pointResult[i].coordinate_X == down_left_x && pointResult[i].coordinate_Y == down_left_y)
                {
                    (*p).down_left = &pointResult[i];
                    break;
                }
            }

            //down_right exist
            int down_right_x = x + 1;
            int down_right_y = y - 1;
            for (int i = 0; i < vectorSize; i++)
            {
                if (pointResult[i].coordinate_X == down_right_x && pointResult[i].coordinate_Y == down_right_y)
                {
                    (*p).down_right = &pointResult[i];
                    break;
                }
            }
        }
    }
}



void TCFS::ConnectOtherPoint()
{
    for (unsigned int i = 0; i < pointResult.size(); i++)
    {
        exist(pointResult, &pointResult[i], tangramNumber);
    }
}

vector<Point>& TCFS::doit()
{
    Tangram_Convex_Figures_Vertex();
    Max_Coordinate_X_and_Y();
    Tangram_Convex_Figures_Inside_Vertex();
    ConnectOtherPoint();

    return pointResult;
}


