#include "initializetangram.h"

IT::IT(int number)
{
    Initialize_Tangram();

    //initialized the member variable maxCoordinate_X and maxCoordinate_Y
    maxCoordinate_X = 0;
    maxCoordinate_Y = 0;
}

IT::~IT()
{
    pointInput_LT.clear();
    pointInput_MT.clear();
    pointInput_ST.clear();
    pointInput_SQ.clear();
    pointInput_PA.clear();
    pointResult_LT.clear();
    pointResult_MT.clear();
    pointResult_ST.clear();
    pointResult_SQ.clear();
    pointResult_PA.clear();
}
void IT::Initialize_Tangram()
{
    Initialize_Tangram_Figures_Vertex();
    Initialize_Tangram_LT();
    Initialize_Tangram_MT();
    Initialize_Tangram_ST();
    Initialize_Tangram_SQ();
    Initialize_Tangram_PA();
}

void IT::Initialize_Tangram_Figures_Vertex()
{
    pointInput_LT.push_back({ 0,0 });	//This is the Tangram (LT) Figure
    pointInput_LT.push_back({ 4,0 });
    pointInput_LT.push_back({ 2,2 });

    pointInput_MT.push_back({ 0,0 });	//This is the Tangram (MT) Figure
    pointInput_MT.push_back({ 2,0 });
    pointInput_MT.push_back({ 2,2 });

    pointInput_ST.push_back({ 0,0 });	//This is the Tangram (ST) Figure
    pointInput_ST.push_back({ 2,0 });
    pointInput_ST.push_back({ 1,1 });

    pointInput_SQ.push_back({ 0,1 });	//This is the Tangram (SQ) Figure
    pointInput_SQ.push_back({ 1,0 });
    pointInput_SQ.push_back({ 2,1 });
    pointInput_SQ.push_back({ 1,2 });

    pointInput_PA.push_back({ 0,0 });	//This is the Tangram (PA) Figure
    pointInput_PA.push_back({ 2,0 });
    pointInput_PA.push_back({ 3,1 });
    pointInput_PA.push_back({ 1,1 });
}

void ConnectOtherPoint(vector<Point>& pointResult, Point* p, int method)
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
        int right_x = x - 1;
        int right_y = y;
        for (int i = 0; i < vectorSize; i++)
        {
            if (pointResult[i].coordinate_X == right_x && pointResult[i].coordinate_Y == right_y)
            {
                (*p).right = &pointResult[i];
                break;
            }
        }

        if (method == 1)
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


        //cout << "This is point p" << endl;
        //cout << "p.up->coordinate_X:  " << p.up->coordinate_X << "p.up->coordinate_Y: " << p.up->coordinate_Y;
        //cout << "p.down->coordinate_X:  " << p.down->coordinate_X << "p.down->coordinate_Y: " << p.down->coordinate_Y;

}

bool Tangram_LT_Figures(Point p)
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
    if (p.coordinate_Y <= -p.coordinate_X + 4)
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

void IT::Initialize_Tangram_LT()
{
    Point possiblePoint;
    Max_Coordinate_X_and_Y(pointInput_LT);
    for (int i = 0; i < maxCoordinate_X + 1; i++)
    {
        for (int j = 0; j < maxCoordinate_Y + 1; j++)
        {
            possiblePoint = { i,j };
            if (Tangram_LT_Figures(possiblePoint) == true)
            {
                pointResult_LT.push_back(possiblePoint);
            }
        }
    }

    /*
    for (unsigned int i = 0; i < pointResult_LT.size(); i++)
    {
        cout << "coordinate: " << pointResult_LT[i].coordinate_X << " ," << pointResult_LT[i].coordinate_Y << endl;
    }
    */

    for (unsigned int i = 0; i < pointResult_LT.size(); i++)
    {
        if (pointResult_LT[i].coordinate_X == 0 && pointResult_LT[i].coordinate_Y == 0)
        {
            LT_1.smallCoordinate_X.coordinate_X = 0; LT_1.smallCoordinate_X.coordinate_Y = 0;
            LT_2.smallCoordinate_X.coordinate_X = 0; LT_2.smallCoordinate_X.coordinate_Y = 0;
            ConnectOtherPoint(pointResult_LT, &LT_1.smallCoordinate_X, 0);
            ConnectOtherPoint(pointResult_LT, &LT_2.smallCoordinate_X, 0);
            continue;
        }
        if (pointResult_LT[i].coordinate_X == 4 && pointResult_LT[i].coordinate_Y == 0)
        {
            LT_1.bigCoordinate_X.coordinate_X = 4; LT_1.bigCoordinate_X.coordinate_Y = 0;
            LT_2.bigCoordinate_X.coordinate_X = 4; LT_2.bigCoordinate_X.coordinate_Y = 0;
            ConnectOtherPoint(pointResult_LT, &LT_1.bigCoordinate_X, 0);
            ConnectOtherPoint(pointResult_LT, &LT_2.bigCoordinate_X, 0);
            continue;
        }
        if (pointResult_LT[i].coordinate_X == 2 && pointResult_LT[i].coordinate_Y == 2)
        {
            LT_1.verticalAngleVertexCoordinate_X.coordinate_X = 2; LT_1.verticalAngleVertexCoordinate_X.coordinate_Y = 2;
            LT_2.verticalAngleVertexCoordinate_X.coordinate_X = 2; LT_2.verticalAngleVertexCoordinate_X.coordinate_Y = 2;
            ConnectOtherPoint(pointResult_LT, &LT_1.verticalAngleVertexCoordinate_X, 0);
            ConnectOtherPoint(pointResult_LT, &LT_2.verticalAngleVertexCoordinate_X, 0);
            continue;
        }


        ConnectOtherPoint(pointResult_LT, &pointResult_LT[i], 0);
        LT_1.otherPoint.push_back(pointResult_LT[i]);
        LT_2.otherPoint.push_back(pointResult_LT[i]);
    }

}

bool Tangram_MT_Figures(Point p)
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
    if (p.coordinate_X <= 2)
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

void IT::Initialize_Tangram_MT()
{
    Point possiblePoint;
    Max_Coordinate_X_and_Y(pointInput_MT);
    for (int i = 0; i < maxCoordinate_X + 1; i++)
    {
        for (int j = 0; j < maxCoordinate_Y + 1; j++)
        {
            possiblePoint = { i,j };
            if (Tangram_MT_Figures(possiblePoint) == true)
            {
                pointResult_MT.push_back(possiblePoint);
            }
        }
    }

    for (unsigned int i = 0; i < pointResult_MT.size(); i++)
    {
        if (pointResult_MT[i].coordinate_X == 0 && pointResult_MT[i].coordinate_Y == 0)
        {
            MT.smallCoordinate_X.coordinate_X = 0; MT.smallCoordinate_X.coordinate_Y = 0;
            ConnectOtherPoint(pointResult_MT, &MT.smallCoordinate_X, 0);
            continue;
        }
        if (pointResult_MT[i].coordinate_X == 2 && pointResult_MT[i].coordinate_Y == 0)
        {
            MT.verticalAngleVertexCoordinate_X.coordinate_X = 2; MT.verticalAngleVertexCoordinate_X.coordinate_Y = 0;
            ConnectOtherPoint(pointResult_MT, &MT.verticalAngleVertexCoordinate_X, 0);
            continue;
        }
        if (pointResult_MT[i].coordinate_X == 2 && pointResult_MT[i].coordinate_Y == 2)
        {
            MT.bigCoordinate_X.coordinate_X = 2; MT.bigCoordinate_X.coordinate_Y = 2;
            ConnectOtherPoint(pointResult_MT, &MT.bigCoordinate_X, 0);
            continue;
        }

        ConnectOtherPoint(pointResult_MT, &pointResult_MT[i], 0);
        MT.otherPoint.push_back(pointResult_MT[i]);
    }
}

bool Tangram_ST_Figures(Point p)
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
    if (p.coordinate_Y <= -p.coordinate_X + 2)
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

void IT::Initialize_Tangram_ST()
{
    Point possiblePoint;
    Max_Coordinate_X_and_Y(pointInput_ST);
    for (int i = 0; i < maxCoordinate_X + 1; i++)
    {
        for (int j = 0; j < maxCoordinate_Y + 1; j++)
        {
            possiblePoint = { i,j };
            if (Tangram_ST_Figures(possiblePoint) == true)
            {
                pointResult_ST.push_back(possiblePoint);
            }
        }
    }

    for (unsigned int i = 0; i < pointResult_ST.size(); i++)
    {
        if (pointResult_ST[i].coordinate_X == 0 && pointResult_ST[i].coordinate_Y == 0)
        {
            ST_1.smallCoordinate_X.coordinate_X = 0; ST_1.smallCoordinate_X.coordinate_Y = 0;
            ST_2.smallCoordinate_X.coordinate_X = 0; ST_2.smallCoordinate_X.coordinate_Y = 0;
            ConnectOtherPoint(pointResult_ST, &ST_1.smallCoordinate_X, 0);
            ConnectOtherPoint(pointResult_ST, &ST_2.smallCoordinate_X, 0);
            continue;
        }
        if (pointResult_ST[i].coordinate_X == 1 && pointResult_ST[i].coordinate_Y == 1)
        {
            ST_1.verticalAngleVertexCoordinate_X.coordinate_X = 1; ST_1.verticalAngleVertexCoordinate_X.coordinate_Y = 1;
            ST_2.verticalAngleVertexCoordinate_X.coordinate_X = 1; ST_2.verticalAngleVertexCoordinate_X.coordinate_Y = 1;
            ConnectOtherPoint(pointResult_ST, &ST_1.verticalAngleVertexCoordinate_X, 0);
            ConnectOtherPoint(pointResult_ST, &ST_2.verticalAngleVertexCoordinate_X, 0);
            continue;
        }
        if (pointResult_ST[i].coordinate_X == 2 && pointResult_ST[i].coordinate_Y == 0)
        {
            ST_1.bigCoordinate_X.coordinate_X = 2; ST_1.bigCoordinate_X.coordinate_Y = 0;
            ST_2.bigCoordinate_X.coordinate_X = 2; ST_2.bigCoordinate_X.coordinate_Y = 0;
            ConnectOtherPoint(pointResult_ST, &ST_1.bigCoordinate_X, 0);
            ConnectOtherPoint(pointResult_ST, &ST_2.bigCoordinate_X, 0);
            continue;
        }

        ConnectOtherPoint(pointResult_ST, &pointResult_ST[i], 0);
        ST_1.otherPoint.push_back(pointResult_ST[i]);
        ST_2.otherPoint.push_back(pointResult_ST[i]);
    }
}

bool Tangram_SQ_Figures(Point p)
{
    bool condition_1 = false;
    bool condition_2 = false;
    bool condition_3 = false;
    bool condition_4 = false;
    bool all_condition_true = false;

    if (p.coordinate_Y <= p.coordinate_X + 1)
    {
        condition_1 = true;
    }
    if (p.coordinate_Y >= -p.coordinate_X + 1)
    {
        condition_2 = true;
    }
    if (p.coordinate_Y >= p.coordinate_X - 1)
    {
        condition_3 = true;
    }
    if (p.coordinate_Y <= -p.coordinate_X + 3)
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

void IT::Initialize_Tangram_SQ()
{
    Point possiblePoint;
    Max_Coordinate_X_and_Y(pointInput_SQ);
    for (int i = 0; i < maxCoordinate_X + 1; i++)
    {
        for (int j = 0; j < maxCoordinate_Y + 1; j++)
        {
            possiblePoint = { i,j };
            if (Tangram_SQ_Figures(possiblePoint) == true)
            {
                pointResult_SQ.push_back(possiblePoint);
            }
        }
    }

    for (unsigned int i = 0; i < pointResult_SQ.size(); i++)
    {
        if (pointResult_SQ[i].coordinate_X == 0 && pointResult_SQ[i].coordinate_Y == 1)
        {
            SQ.smallCoordinate_X.coordinate_X = 0; SQ.smallCoordinate_X.coordinate_Y = 1;
            ConnectOtherPoint(pointResult_SQ, &SQ.smallCoordinate_X, 1);
            continue;
        }
        if (pointResult_SQ[i].coordinate_X == 1 && pointResult_SQ[i].coordinate_Y == 0)
        {
            SQ.middleCoordinate_X_down.coordinate_X = 1; SQ.middleCoordinate_X_down.coordinate_Y = 0;
            ConnectOtherPoint(pointResult_SQ, &SQ.middleCoordinate_X_down, 1);
            continue;
        }
        if (pointResult_SQ[i].coordinate_X == 2 && pointResult_SQ[i].coordinate_Y == 1)
        {
            SQ.bigCoordinate_X.coordinate_X = 2; SQ.bigCoordinate_X.coordinate_Y = 1;
            ConnectOtherPoint(pointResult_SQ, &SQ.bigCoordinate_X, 1);
            continue;
        }
        if (pointResult_SQ[i].coordinate_X == 1 && pointResult_SQ[i].coordinate_Y == 2)
        {
            SQ.middleCoordinate_X_up.coordinate_X = 1; SQ.middleCoordinate_X_up.coordinate_Y = 2;
            ConnectOtherPoint(pointResult_SQ, &SQ.middleCoordinate_X_up, 1);
            continue;
        }

        ConnectOtherPoint(pointResult_SQ, &pointResult_SQ[i], 1);
        SQ.otherPoint.push_back(pointResult_SQ[i]);
    }
}

bool Tangram_PA_Figures(Point p)
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
    if (p.coordinate_Y >= p.coordinate_X - 2)
    {
        condition_3 = true;
    }
    if (p.coordinate_Y <= 1)
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

void IT::Initialize_Tangram_PA()
{
    Point possiblePoint;
    Max_Coordinate_X_and_Y(pointInput_PA);
    for (int i = 0; i < maxCoordinate_X + 1; i++)
    {
        for (int j = 0; j < maxCoordinate_Y + 1; j++)
        {
            possiblePoint = { i,j };
            if (Tangram_PA_Figures(possiblePoint) == true)
            {
                pointResult_PA.push_back(possiblePoint);
            }
        }
    }

    for (unsigned int i = 0; i < pointResult_PA.size(); i++)
    {
        if (pointResult_PA[i].coordinate_X == 0 && pointResult_PA[i].coordinate_Y == 0)
        {
            PA.smallCoordinate_X_down.coordinate_X = 0; PA.smallCoordinate_X_down.coordinate_Y = 0;
            ConnectOtherPoint(pointResult_PA, &PA.smallCoordinate_X_down, 0);
            continue;
        }
        if (pointResult_PA[i].coordinate_X == 2 && pointResult_PA[i].coordinate_Y == 0)
        {
            PA.bigCoordinate_X_down.coordinate_X = 2; PA.bigCoordinate_X_down.coordinate_Y = 0;
            ConnectOtherPoint(pointResult_PA, &PA.bigCoordinate_X_down, 0);
            continue;
        }
        if (pointResult_PA[i].coordinate_X == 3 && pointResult_PA[i].coordinate_Y == 1)
        {
            PA.bigCoordinate_X_up.coordinate_X = 3; PA.bigCoordinate_X_up.coordinate_Y = 1;
            ConnectOtherPoint(pointResult_PA, &PA.bigCoordinate_X_up, 0);
            continue;
        }
        if (pointResult_PA[i].coordinate_X == 1 && pointResult_PA[i].coordinate_Y == 1)
        {
            PA.smallCoordinate_X_up.coordinate_X = 1; PA.smallCoordinate_X_up.coordinate_Y = 1;
            ConnectOtherPoint(pointResult_PA, &PA.smallCoordinate_X_up, 0);
            continue;
        }

        ConnectOtherPoint(pointResult_PA, &pointResult_PA[i], 0);
        PA.otherPoint.push_back(pointResult_PA[i]);
    }
}

void IT::Max_Coordinate_X_and_Y(vector<Point> pointInput)
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
