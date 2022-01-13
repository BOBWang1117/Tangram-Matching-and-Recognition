#include "tangram.h"
#include<algorithm>

using namespace std;

void printVector(vector<Point> needPrint)
{

    for (unsigned int j = 0; j < needPrint.size(); j++)
    {
        //if (needPrint[j].coordinate_X == 3 && needPrint[j].coordinate_Y == 1)
        {
            cout << "coordinate: " << needPrint[j].coordinate_X << " ," << needPrint[j].coordinate_Y << endl;
            if (needPrint[j].up != nullptr)
            {
                cout << "up: " << needPrint[j].up->coordinate_X << " ," << needPrint[j].up->coordinate_Y << endl;
            }
            if (needPrint[j].down != nullptr)
            {
                cout << "down: " << needPrint[j].down->coordinate_X << " ," << needPrint[j].down->coordinate_Y << endl;
            }
            if (needPrint[j].left != nullptr)
            {
                cout << "left: " << needPrint[j].left->coordinate_X << " ," << needPrint[j].left->coordinate_Y << endl;
            }
            if (needPrint[j].right != nullptr)
            {
                cout << "right: " << needPrint[j].right->coordinate_X << " ," << needPrint[j].right->coordinate_Y << endl;
            }
            if (needPrint[j].up_left != nullptr)
            {
                cout << "up_left: " << needPrint[j].up_left->coordinate_X << " ," << needPrint[j].up_left->coordinate_Y << endl;
            }
            if (needPrint[j].up_right != nullptr)
            {
                cout << "up_right: " << needPrint[j].up_right->coordinate_X << " ," << needPrint[j].up_right->coordinate_Y << endl;
            }
            if (needPrint[j].down_left != nullptr)
            {
                cout << "down_left: " << needPrint[j].down_left->coordinate_X << " ," << needPrint[j].down_left->coordinate_Y << endl;
            }
            if (needPrint[j].down_right != nullptr)
            {
                cout << "down_right: " << needPrint[j].down_right->coordinate_X << " ," << needPrint[j].down_right->coordinate_Y << endl;
            }
            cout << endl;
        }


    }
    cout << endl;



}

Tangram::Tangram(int tangramNumber, int searchNumber)
{
    this->tangramNumber = tangramNumber;
    this->searchNumber = searchNumber;
}

/*
* Description:	Initialization the TCFS class
*/

vector<Point>& Tangram::Initalize_Class_TCFS()
{
    static TCFS TCFS(tangramNumber);
    TCFS.SetP(tangramNumber);

    return TCFS.doit();
}

/*
* Description:	Initialization the Search class
*/

vector<Point> Tangram::Initalize_Class_Search()
{
    vector<Point> result;
    searchMethod Search(inputSearch, searchNumber);
    result = Search.doit();

    return result;
}
bool Matching(Point p, int graphID, int rotationID)
{
    /*
    * graphID:
    *		LT_1:			1
    *		LT_2:			2
    *		MT:				3
    *		ST_1:			4
    *		ST_2:			5
    *		SQ:				6
    *		PA:				7
    *		PA Mirroring:	8
    */

    /*
    * rotationID:
    *		Rotate right once:		1
    *		Rotate right twice:		2
    *		Rotate right 3 times:	3
    *		Rotate right 4 times:	4
    */

    //judge which triangle is judging
    int judgeType = -1;
    if (graphID == 1 || graphID == 2)	//LT
    {
        judgeType = 0;
    }
    if (graphID == 3)	//MT
    {
        judgeType = 1;
    }
    if (graphID == 4 || graphID == 5)	//ST
    {
        judgeType = 2;
    }
    if (graphID == 6)		//	SQ
    {
        judgeType = 3;
    }
    if (graphID == 7)	//(graphID == 7)  PA
    {
        judgeType = 4;
    }
    if (graphID == 8)	//(graphID == 8)  PA Mirroring
    {
        judgeType = 5;
    }


    if (judgeType == 0)
    {
        //Apply to LT
        bool havePoint_up_right = p.up_right;
        bool havePoint_down_right = p.down_right;
        bool havePoint_down_left = p.down_left;
        bool havePoint_up_left = p.up_left;

        bool havePoint_up_right_double = false;
        bool havePoint_down_right_double = false;
        bool havePoint_down_left_double = false;
        bool havePoint_up_left_double = false;

        if (havePoint_up_right == true)
        {
            havePoint_up_right_double = p.up_right->up_right;
        }
        if (havePoint_down_right == true)
        {
            havePoint_down_right_double = p.down_right->down_right;
        }
        if (havePoint_down_left == true)
        {
            havePoint_down_left_double = p.down_left->down_left;
        }
        if (havePoint_up_left == true)
        {
            havePoint_up_left_double = p.up_left->up_left;
        }


        //According to rotationID, return if find it
        if (rotationID == 1)
        {
            if (havePoint_up_right_double == true && havePoint_down_right_double == true)
            {
                return true;
            }
        }
        if (rotationID == 2)
        {
            if (havePoint_down_right_double == true && havePoint_down_left_double == true)
            {
                return true;
            }
        }
        if (rotationID == 3)
        {
            if (havePoint_down_left_double == true && havePoint_up_left_double == true)
            {
                return true;
            }
        }
        if (rotationID == 4)	//rotationID == 4
        {
            if (havePoint_up_left_double == true && havePoint_up_right_double == true)
            {
                return true;
            }
        }

        return false;

    }
    if (judgeType == 1)	//MT
    {
        //Apply to MT
        bool havePoint_up = p.up;
        bool havePoint_down = p.down;
        bool havePoint_left = p.left;
        bool havePoint_right = p.right;



        bool havePoint_up_double = false;
        bool havePoint_right_double = false;
        bool havePoint_down_double = false;
		bool havePoint_left_double = false;

        if (havePoint_up != 0)
        {
            havePoint_up_double = p.up->up;
        }
        if (havePoint_right != 0)
        {
            havePoint_right_double = p.right->right;
        }
        if (havePoint_down != 0)
        {
            havePoint_down_double = p.down->down;
        }
        if (havePoint_left != 0)
        {
            havePoint_left_double = p.left->left;
        }

        //According to rotationID, return if find it
        if (rotationID == 1)
        {
			if (havePoint_up_double == true && havePoint_right_double == true)
            {
                return true;
            }
        }
        if (rotationID == 2)
        {
			if (havePoint_right_double == true && havePoint_down_double == true)
            {
                return true;
            }
        }
        if (rotationID == 3)
        {
			if (havePoint_down_double == true && havePoint_left_double == true)
            {
                return true;
            }
        }
        if (rotationID == 4)	//rotationID == 4
        {
			if (havePoint_left_double == true && (havePoint_down_double == true || havePoint_up_double))
            {
                return true;
            }
        }

        return false;
    }
    if (judgeType == 2)	//judgeType = 2 : graphID = 4(ST_1) and graphID = 5(ST_2)
    {
        //Apply to ST
        bool havePoint_up_right = p.up_right;
        bool havePoint_down_right = p.down_right;
        bool havePoint_down_left = p.down_left;
        bool havePoint_up_left = p.up_left;

        //According to rotationID, return if find it
        if (rotationID == 1)
        {
            if (havePoint_up_right == true && havePoint_down_right == true)
            {
                return true;
            }
        }
        if (rotationID == 2)
        {
            if (havePoint_down_right == true && havePoint_down_left == true)
            {
                return true;
            }
        }
        if (rotationID == 3)
        {
            if (havePoint_down_left == true && havePoint_up_left == true)
            {
                return true;
            }
        }
        if (rotationID == 4)	//rotationID == 4
        {
            if (havePoint_up_left == true && havePoint_up_right == true)
            {
                return true;
            }
        }

        return false;


    }
    if (judgeType == 3)
    {
        //Apply to SQ
        bool havePoint_upRight = p.up_right;
        bool havePoint_downRight = p.down_right;
        bool havePoint_downLeft = p.down_left;
        bool havePoint_upLeft = p.up_left;

        bool havePoint_up = p.up;
        bool havePoint_down = p.down;
        bool havePoint_left = p.left;
        bool havePoint_right = p.right;

        bool havePoint_up_double = false;
        bool havePoint_down_double = false;
        bool havePoint_left_double = false;
        bool havePoint_right_double = false;

        if (havePoint_up == true)
        {
            havePoint_up_double = p.up->up;
        }
        if (havePoint_down == true)
        {
            havePoint_down_double = p.down->down;
        }
        if (havePoint_left == true)
        {
            havePoint_left_double = p.left->left;
        }
        if (havePoint_right == true)
        {
            havePoint_right_double = p.right->right;
        }

        //According to rotationID, return if find it
        if (rotationID == 1)
        {
            if (havePoint_upRight == true && havePoint_downRight == true && havePoint_right_double == true)
            {
                return true;
            }
        }
        if (rotationID == 2)
        {
            if (havePoint_downRight == true && havePoint_downLeft == true && havePoint_down_double == true)
            {
                return true;
            }
        }
        if (rotationID == 3)
        {
            if (havePoint_downLeft == true && havePoint_upLeft == true && havePoint_left_double == true)
            {
                return true;
            }
        }
        if (rotationID == 4)	//rotationID == 4
        {
            if (havePoint_upLeft == true && havePoint_upRight == true && havePoint_up_double == true)
            {
                return true;
            }
        }

        return false;

    }
    if (judgeType == 4)
    {
		//Apply to PA
        bool havePoint_upRight = p.up_right;
        bool havePoint_downRight = p.down_right;
        bool havePoint_downLeft = p.down_left;
        bool havePoint_upLeft = p.up_left;

        bool havePoint_up = p.up;
        bool havePoint_down = p.down;
        bool havePoint_left = p.left;
        bool havePoint_right = p.right;

        bool havePoint_up_double = false;
        bool havePoint_down_double = false;
        bool havePoint_left_double = false;
        bool havePoint_right_double = false;

        bool havePoint_upDouble_upLeft = false;
        bool havePoint_downDouble_downRight = false;
        bool havePoint_leftDouble_downLeft = false;
        bool havePoint_rightDouble_upRight = false;

        if (havePoint_up == true)
        {
            havePoint_up_double = p.up->up;
        }
        if (havePoint_down == true)
        {
            havePoint_down_double = p.down->down;
        }
        if (havePoint_left == true)
        {
            havePoint_left_double = p.left->left;
        }
        if (havePoint_right == true)
        {
            havePoint_right_double = p.right->right;
        }



        if (havePoint_up_double == true)
        {
            havePoint_upDouble_upLeft = p.up->up->up_left;
        }
        if (havePoint_down_double == true)
        {
            havePoint_downDouble_downRight = p.down->down->down_right;
        }
        if (havePoint_left_double == true)
        {
            havePoint_leftDouble_downLeft = p.left->left->down_left;
        }
        if (havePoint_right_double == true)
        {
            havePoint_rightDouble_upRight = p.right->right->up_right;
        }

        //According to rotationID, return if find it
        if (rotationID == 1)
        {
            if (havePoint_upRight == true && havePoint_right_double == true && havePoint_rightDouble_upRight == true)
            {
                return true;
            }
        }
        if (rotationID == 2)
        {
            if (havePoint_downRight == true && havePoint_down_double == true && havePoint_downDouble_downRight == true)
            {
                return true;
            }
        }
        if (rotationID == 3)
        {
            if (havePoint_downLeft == true && havePoint_left_double == true && havePoint_leftDouble_downLeft == true)
            {
                return true;
            }
        }
        if (rotationID == 4)	//rotationID == 4
        {
            if (havePoint_upLeft == true && havePoint_up_double == true && havePoint_upDouble_upLeft == true)
            {
                return true;
            }
        }

        return false;
    }
    if (judgeType == 5)
    {
        //Apply to PA
        bool havePoint_upRight = p.up_right;
        bool havePoint_downRight = p.down_right;
        bool havePoint_downLeft = p.down_left;
        bool havePoint_upLeft = p.up_left;

        bool havePoint_up = p.up;
        bool havePoint_down = p.down;
        bool havePoint_left = p.left;
        bool havePoint_right = p.right;

        bool havePoint_up_double = false;
        bool havePoint_down_double = false;
        bool havePoint_left_double = false;
        bool havePoint_right_double = false;

        bool havePoint_upDouble_upRight = false;
        bool havePoint_downDouble_downLeft = false;
        bool havePoint_leftDouble_upLeft = false;
        bool havePoint_rightDouble_downRight = false;

        if (havePoint_up == true)
        {
            havePoint_up_double = p.up->up;
        }
        if (havePoint_down == true)
        {
            havePoint_down_double = p.down->down;
        }
        if (havePoint_left == true)
        {
            havePoint_left_double = p.left->left;
        }
        if (havePoint_right == true)
        {
            havePoint_right_double = p.right->right;
        }



        if (havePoint_up_double == true)
        {
            havePoint_upDouble_upRight = p.up->up->up_right;
        }
        if (havePoint_down_double == true)
        {
            havePoint_downDouble_downLeft = p.down->down->down_left;
        }
        if (havePoint_left_double == true)
        {
            havePoint_leftDouble_upLeft = p.left->left->up_left;
        }
        if (havePoint_right_double == true)
        {
            havePoint_rightDouble_downRight = p.right->right->down_right;
        }

        //According to rotationID, return if find it
        if (rotationID == 1)
        {
			if (havePoint_right_double == true && havePoint_downRight == true && havePoint_rightDouble_downRight == true)
            {
                return true;
            }
        }
		if (rotationID == 2)
        {
			if (havePoint_down_double == true && havePoint_downLeft == true && havePoint_downDouble_downLeft == true)
            {
                return true;
            }
        }
        if (rotationID == 3)
        {
            if (havePoint_left_double == true && havePoint_upLeft == true && havePoint_leftDouble_upLeft == true)
            {
                return true;
            }
        }
        if (rotationID == 4)	//rotationID == 4
        {
            if (havePoint_up_double == true && havePoint_upRight == true && havePoint_upDouble_upRight == true)
            {
                return true;
            }
        }

        return false;
    }


    cout << "Matching() FALSE OVER" << endl;
    return false;
}

/*
* Description:	This is Judging function, it will calculate the Tangram can put into the figures
*/
int Judging(vector<Point>searchResult, Point p, int graphID, int roationID)
{
    /*
        * graphID:
        *		LT_1:			1
        *		LT_2:			2
        *		MT:				3
        *		ST_1:			4
        *		ST_2:			5
        *		SQ:				6
        *		PA:				7
        *		PA Mirroring:	8
        */

        /*
        * rotationID:
        *		Rotate right once:		1
        *		Rotate right twice:		2
        *		Rotate right 3 times:	3
        *		Rotate right 4 times:	4
        */

    int judgeType = -1;
    if (graphID == 1 || graphID == 2)	//LT
    {
        judgeType = 0;
    }
    if (graphID == 3)	//MT
    {
        judgeType = 1;
    }
    if (graphID == 4 || graphID == 5)	//ST
    {
        judgeType = 2;
    }
    if (graphID == 6)		//SQ
    {
        judgeType = 3;
    }
    if (graphID == 7)		//PA
    {
        judgeType = 4;
    }
    if (graphID == 8)		//PA Mirroring
    {
        judgeType = 5;
    }

    if (judgeType == 0)
    {
        //There have 9 point need to solve
        if (roationID == 1)
        {
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex_right;				//(x + 1, y)
            Point rightAngleVertex_upRight;				//(x + 1, y + 1)
            Point rightAngleVertex_downRight;			//(x + 1, y - 1)
            Point rightAngleVertex_upRight_right;		//(x + 2, y + 1)
            Point rightAngleVertex_downRight_right;		//(x + 2, y - 1)

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight = searchResult[i];
                    continue;
                }
                if (coordinate_X + 2 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight_right = searchResult[i];
                    continue;
                }
                if (coordinate_X + 2 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight_right = searchResult[i];
                    continue;
                }
            }


            bool situation_1 = false;
            bool situation_2 = false;
            bool situation_3 = false;
            bool situation_4 = false;
            bool situation_5 = false;


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2 && situation_3 && situation_4 && situation_5)
                {
                    return true;
                }


                if (rightAngleVertex_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].left;
                    bool Road_2 = searchResult[i].right;
                    if (Road_1 && Road_2)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_upRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].down_left;
                    bool Road_2 = searchResult[i].down;
                    bool Road_3 = searchResult[i].down_right;
                    bool Road_4 = searchResult[i].right;
                    bool Road_5 = searchResult[i].up_right;
                    if (Road_1 && Road_2 && Road_3 && Road_4 && Road_5)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_downRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up_left;
                    bool Road_2 = searchResult[i].up;
                    bool Road_3 = searchResult[i].up_right;
                    bool Road_4 = searchResult[i].right;
                    bool Road_5 = searchResult[i].down_right;
                    if (Road_1 && Road_2 && Road_3 && Road_4 && Road_5)
                    {
                        situation_3 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_upRight_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    bool Road_2 = searchResult[i].down;
                    if (Road_1 && Road_2)
                    {
                        situation_4 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_downRight_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    bool Road_2 = searchResult[i].down;
                    if (Road_1 && Road_2)
                    {
                        situation_5 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            if (situation_1 && situation_2 && situation_3 && situation_4 && situation_5)
            {
                return true;
            }

        }
        if (roationID == 2)
        {
            bool situation_1 = false;
            bool situation_2 = false;
            bool situation_3 = false;
            bool situation_4 = false;
            bool situation_5 = false;

            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex_down;				//(  x  , y - 1)
            Point rightAngleVertex_downLeft;			//(x - 1, y - 1)
            Point rightAngleVertex_downRight;			//(x + 1, y - 1)
            Point rightAngleVertex_downLeft_down;		//(x - 1, y - 2)
            Point rightAngleVertex_downRight_down;		//(x + 1, y - 2)

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y - 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft_down = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y - 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight_down = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2 && situation_3 && situation_4 && situation_5)
                {
                    return true;
                }


                if (rightAngleVertex_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    bool Road_2 = searchResult[i].down;
                    if (Road_1 && Road_2)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_downLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up_right;
                    bool Road_2 = searchResult[i].right;
                    bool Road_3 = searchResult[i].down_right;
                    bool Road_4 = searchResult[i].down;
                    bool Road_5 = searchResult[i].down_left;
                    if (Road_1 && Road_2 && Road_3 && Road_4 && Road_5)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_downRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up_left;
                    bool Road_2 = searchResult[i].left;
                    bool Road_3 = searchResult[i].down_left;
                    bool Road_4 = searchResult[i].down;
                    bool Road_5 = searchResult[i].down_right;
                    if (Road_1 && Road_2 && Road_3 && Road_4 && Road_5)
                    {
                        situation_3 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_downLeft_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].left;
                    bool Road_2 = searchResult[i].right;
                    if (Road_1 && Road_2)
                    {
                        situation_4 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_downRight_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].left;
                    bool Road_2 = searchResult[i].right;
                    if (Road_1 && Road_2)
                    {
                        situation_5 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            if (situation_1 && situation_2 && situation_3 && situation_4 && situation_5)
            {
                return true;
            }

        }
        if (roationID == 3)
        {
            bool situation_1 = false;
            bool situation_2 = false;
            bool situation_3 = false;
            bool situation_4 = false;
            bool situation_5 = false;

            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex_left;				//(x - 1, y)
            Point rightAngleVertex_upLeft;				//(x - 1, y + 1)
            Point rightAngleVertex_downLeft;			//(x - 1, y - 1)
            Point rightAngleVertex_upLeft_left;			//(x - 2, y + 1)
            Point rightAngleVertex_downLeft_left;		//(x - 2, y - 1)

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X - 2 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft_left = searchResult[i];
                    continue;
                }
                if (coordinate_X - 2 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft_left = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2 && situation_3 && situation_4 && situation_5)
                {
                    return true;
                }

                if (rightAngleVertex_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].left;
                    bool Road_2 = searchResult[i].right;
                    if (Road_1 && Road_2)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_upLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up_left;
                    bool Road_2 = searchResult[i].left;
                    bool Road_3 = searchResult[i].down_left;
                    bool Road_4 = searchResult[i].down;
                    bool Road_5 = searchResult[i].down_right;
                    if (Road_1 && Road_2 && Road_3 && Road_4 && Road_5)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_downLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up_right;
                    bool Road_2 = searchResult[i].up;
                    bool Road_3 = searchResult[i].up_left;
                    bool Road_4 = searchResult[i].left;
                    bool Road_5 = searchResult[i].down_left;
                    if (Road_1 && Road_2 && Road_3 && Road_4 && Road_5)
                    {
                        situation_3 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_upLeft_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    bool Road_2 = searchResult[i].down;
                    if (Road_1 && Road_2)
                    {
                        situation_4 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_downLeft_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    bool Road_2 = searchResult[i].down;
                    if (Road_1 && Road_2)
                    {
                        situation_5 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            if (situation_1 && situation_2 && situation_3 && situation_4 && situation_5)
            {
                return true;
            }
        }
        if (roationID == 4)	//rotation 4
        {
            bool situation_1 = false;
            bool situation_2 = false;
            bool situation_3 = false;
            bool situation_4 = false;
            bool situation_5 = false;

            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex_up;				//(  x  , y + 1)
            Point rightAngleVertex_upLeft;			//(x - 1, y + 1)
            Point rightAngleVertex_upRight;			//(x + 1, y + 1)
            Point rightAngleVertex_upLeft_up;		//(x - 1, y + 2)
            Point rightAngleVertex_upRight_up;		//(x + 1, y + 2)



            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y + 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft_up = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y + 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight_up = searchResult[i];
                    continue;
                }

            }


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2 && situation_3 && situation_4 && situation_5)
                {
                    return true;
                }

                if (rightAngleVertex_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    bool Road_2 = searchResult[i].down;
                    if (Road_1 && Road_2)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_upLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up_left;
                    bool Road_2 = searchResult[i].up;
                    bool Road_3 = searchResult[i].up_right;
                    bool Road_4 = searchResult[i].right;
                    bool Road_5 = searchResult[i].down_right;
                    if (Road_1 && Road_2 && Road_3 && Road_4 && Road_5)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_upRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up_right;
                    bool Road_2 = searchResult[i].up;
                    bool Road_3 = searchResult[i].up_left;
                    bool Road_4 = searchResult[i].left;
                    bool Road_5 = searchResult[i].down_left;
                    if (Road_1 && Road_2 && Road_3 && Road_4 && Road_5)
                    {
                        situation_3 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_upLeft_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].left;
                    bool Road_2 = searchResult[i].right;
                    if (Road_1 && Road_2)
                    {
                        situation_4 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_upRight_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].left;
                    bool Road_2 = searchResult[i].right;
                    if (Road_1 && Road_2)
                    {
                        situation_5 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            if (situation_1 && situation_2 && situation_3 && situation_4 && situation_5)
            {
                return true;
            }

        }
    }
    if (judgeType == 1)
    {
		if (roationID == 1)
        {
            bool situation_1 = false;
            bool situation_2 = false;
            bool situation_3 = false;

            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex_up;			//(  x  , y + 1)
            Point rightAngleVertex_upRight;		//(x + 1, y + 1)
            Point rightAngleVertex_right;		//(x + 1, y)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2 && situation_3)
                {
                    return true;
                }


                if (rightAngleVertex_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    bool Road_2 = searchResult[i].down;
                    if (Road_1 && Road_2)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                if (rightAngleVertex_upRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up_left;
                    bool Road_2 = searchResult[i].left;
                    bool Road_3 = searchResult[i].down_left;
                    bool Road_4 = searchResult[i].down;
                    bool Road_5 = searchResult[i].down_right;
                    if (Road_1 && Road_2 && Road_3 && Road_4 && Road_5)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                if (rightAngleVertex_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].left;
                    bool Road_2 = searchResult[i].right;
                    if (Road_1 && Road_2)
                    {
                        situation_3 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }

            }
            if (situation_1 && situation_2 && situation_3)
            {
                return true;
            }
        }
        if (roationID == 2)
        {
            bool situation_1 = false;
            bool situation_2 = false;
            bool situation_3 = false;

            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex_right;		//(x + 1, y)
            Point rightAngleVertex_down;		//(  x  , y - 1)
            Point rightAngleVertex_downRight;	//(x + 1, y - 1)

			for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight = searchResult[i];
                    continue;
                }
            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2 && situation_3)
                {
                    return true;
                }


                if (rightAngleVertex_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    bool Road_2 = searchResult[i].down;
                    if (Road_1 && Road_2)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                if (rightAngleVertex_downRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up_right;
                    bool Road_2 = searchResult[i].up;
                    bool Road_3 = searchResult[i].up_left;
                    bool Road_4 = searchResult[i].left;
                    bool Road_5 = searchResult[i].down_left;
                    if (Road_1 && Road_2 && Road_3 && Road_4 && Road_5)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                if (rightAngleVertex_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].left;
                    bool Road_2 = searchResult[i].right;
                    if (Road_1 && Road_2)
                    {
                        situation_3 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }

            }
            if (situation_1 && situation_2 && situation_3)
            {
                return true;
            }
        }
        if (roationID == 3)
        {
            bool situation_1 = false;
            bool situation_2 = false;
            bool situation_3 = false;


            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;


            Point rightAngleVertex_left;		//(x - 1, y)
            Point rightAngleVertex_down;		//(  x  , y - 1)
            Point rightAngleVertex_downLeft;	//(x - 1, y - 1)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft = searchResult[i];
                    continue;
                }
            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2 && situation_3)
                {
                    return true;
                }


                if (rightAngleVertex_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].left;
                    bool Road_2 = searchResult[i].right;
                    if (Road_1 && Road_2)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                if (rightAngleVertex_downLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up_left;
                    bool Road_2 = searchResult[i].up;
                    bool Road_3 = searchResult[i].up_right;
                    bool Road_4 = searchResult[i].right;
                    bool Road_5 = searchResult[i].down_right;
                    if (Road_1 && Road_2 && Road_3 && Road_4 && Road_5)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                if (rightAngleVertex_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    bool Road_2 = searchResult[i].down;
                    if (Road_1 && Road_2)
                    {
                        situation_3 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }

            }
            if (situation_1 && situation_2 && situation_3)
            {
                return true;
            }
        }
        if (roationID == 4)	//roationID == 4
        {
            bool situation_1 = false;
            bool situation_2 = false;
            bool situation_3 = false;

            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;


            Point rightAngleVertex_left;		//(x - 1, y)
            Point rightAngleVertex_up;			//(  x  , y + 1)
            Point rightAngleVertex_upLeft;		//(x - 1, y + 1)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft = searchResult[i];
                    continue;
                }
            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2 && situation_3)
                {
                    return true;
                }


                if (rightAngleVertex_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].left;
                    bool Road_2 = searchResult[i].right;
                    if (Road_1 && Road_2)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_upLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up_right;
                    bool Road_2 = searchResult[i].right;
                    bool Road_3 = searchResult[i].down_right;
                    bool Road_4 = searchResult[i].down;
                    bool Road_5 = searchResult[i].down_left;
                    if (Road_1 && Road_2 && Road_3 && Road_4 && Road_5)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    bool Road_2 = searchResult[i].down;
                    if (Road_1 && Road_2)
                    {
                        situation_3 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }

            }
            if (situation_1 && situation_2 && situation_3)
            {
                return true;
            }
        }
    }
    if (judgeType == 2)	//judgeType == 2 : ST_1 and ST_2
    {
        if (roationID == 1)
        {
            bool situation_1 = false;
            bool situation_2 = false;

            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;				//(  x  , y)
            Point rightAngleVertex_right;		//(x + 1, y)

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2)
                {
                    return true;
                }


                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up_right;
                    bool Road_2 = searchResult[i].down_right;
                    if (Road_1 && Road_2)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    bool Road_2 = searchResult[i].left;
                    bool Road_3 = searchResult[i].down;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }

            }
            if (situation_1 && situation_2)
            {
                return true;
            }
        }
        if (roationID == 2)
        {
            bool situation_1 = false;
            bool situation_2 = false;

            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;				//(  x  , y)
            Point rightAngleVertex_down;		//(  x  , y - 1)

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2)
                {
                    return true;
                }


                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].down_left;
                    bool Road_2 = searchResult[i].down_right;
                    if (Road_1 && Road_2)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    bool Road_2 = searchResult[i].left;
                    bool Road_3 = searchResult[i].right;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }

            }
            if (situation_1 && situation_2)
            {
                return true;
            }
        }
        if (roationID == 3)
        {
            bool situation_1 = false;
            bool situation_2 = false;

            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;			//(  x  , y)
            Point rightAngleVertex_left;	//(x - 1, y)

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2)
                {
                    return true;
                }


                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up_left;
                    bool Road_2 = searchResult[i].down_left;
                    if (Road_1 && Road_2)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    bool Road_2 = searchResult[i].right;
                    bool Road_3 = searchResult[i].down;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }

            }
            if (situation_1 && situation_2)
            {
                return true;
            }
        }
        if (roationID == 4)
        {
            bool situation_1 = false;
            bool situation_2 = false;

            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;			//(  x  , y)
            Point rightAngleVertex_up;		//(  x  , y + 1)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2)
                {
                    return true;
                }


                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up_left;
                    bool Road_2 = searchResult[i].up_right;
                    if (Road_1 && Road_2)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].left;
                    bool Road_2 = searchResult[i].right;
                    bool Road_3 = searchResult[i].down;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }

            }
            if (situation_1 && situation_2)
            {
                return true;
            }
        }
    }
    if (judgeType == 3)
    {
        if (roationID == 1)
        {
            bool situation_1 = false;
            bool situation_2 = false;
            bool situation_3 = false;

            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;				//(  x  , y)
            Point rightAngleVertex_right;		//(x + 1, y)
            Point rightAngleVertex_right_right;	//(x + 2, y)

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right = searchResult[i];
                    continue;
                }
                if (coordinate_X + 2 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right_right = searchResult[i];
                    continue;
                }
            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2 && situation_3)
                {
                    return true;
                }


                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up_right;
                    bool Road_2 = searchResult[i].right;
                    bool Road_3 = searchResult[i].down_right;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    bool Road_2 = searchResult[i].down;
                    if (Road_1 && Road_2)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_right_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_right_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up_left;
                    bool Road_2 = searchResult[i].left;
                    bool Road_3 = searchResult[i].down_left;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_3 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }

            }
            if (situation_1 && situation_2 && situation_3)
            {
                return true;
            }

        }
        if (roationID == 2)
        {
            bool situation_1 = false;
            bool situation_2 = false;
            bool situation_3 = false;

            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;				//(  x  , y)
            Point rightAngleVertex_down;		//(  x  , y - 1)
            Point rightAngleVertex_down_down;	//(  x  , y - 2)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }

                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down = searchResult[i];
                    continue;
                }

                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y - 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down_down = searchResult[i];
                    continue;
                }
            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2 && situation_3)
                {
                    return true;
                }


                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].down_left;
                    bool Road_2 = searchResult[i].down;
                    bool Road_3 = searchResult[i].down_right;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].left;
                    bool Road_2 = searchResult[i].right;
                    if (Road_1 && Road_2)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_down_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_down_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up_left;
                    bool Road_2 = searchResult[i].up;
                    bool Road_3 = searchResult[i].up_right;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_3 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }

            }
            if (situation_1 && situation_2 && situation_3)
            {
                return true;
            }
        }
        if (roationID == 3)
        {
            bool situation_1 = false;
            bool situation_2 = false;
            bool situation_3 = false;

            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;				//(  x  , y)
            Point rightAngleVertex_left;		//(x - 1, y)
            Point rightAngleVertex_left_left;	//(x - 2, y)



            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left = searchResult[i];
                    continue;
                }
                if (coordinate_X - 2 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left_left = searchResult[i];
                    continue;
                }
            }


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2 && situation_3)
                {
                    return true;
                }


                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up_left;
                    bool Road_2 = searchResult[i].left;
                    bool Road_3 = searchResult[i].down_left;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    bool Road_2 = searchResult[i].down;
                    if (Road_1 && Road_2)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_left_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_left_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up_right;
                    bool Road_2 = searchResult[i].right;
                    bool Road_3 = searchResult[i].down_right;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_3 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }

            }
            if (situation_1 && situation_2 && situation_3)
            {
                return true;
            }
        }
        if (roationID == 4)
        {
            bool situation_1 = false;
            bool situation_2 = false;
            bool situation_3 = false;

            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;			//(  x  , y)
            Point rightAngleVertex_up;		//(  x  , y + 1)
            Point rightAngleVertex_up_up;	//(  x  , y + 2)



            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }

                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y + 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up_up = searchResult[i];
                    continue;
                }
            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2 && situation_3)
                {
                    return true;
                }


                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up_left;
                    bool Road_2 = searchResult[i].up;
                    bool Road_3 = searchResult[i].up_right;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].left;
                    bool Road_2 = searchResult[i].right;
                    if (Road_1 && Road_2)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_up_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_up_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].down_left;
                    bool Road_2 = searchResult[i].down;
                    bool Road_3 = searchResult[i].down_right;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_3 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }

            }
            if (situation_1 && situation_2 && situation_3)
            {
                return true;
            }
        }
    }
    if (judgeType == 4)		//PA
    {
        if (roationID == 1)
        {
            bool situation_1 = false;
            bool situation_2 = false;
            bool situation_3 = false;
            bool situation_4 = false;

            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;						//(  x  , y)
            Point rightAngleVertex_upRight;				//(x + 1,y + 1)
            Point rightAngleVertex_right_right;			//(x + 2,y)
            Point rightAngleVertex_upRight_right;		//(x + 2,y + 1)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight = searchResult[i];
                    continue;
                }
                if (coordinate_X + 2 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right_right = searchResult[i];
                    continue;
                }
                if (coordinate_X + 2 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight_right = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2 && situation_3 && situation_4)
                {
                    return true;
                }


                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up_right;
                    bool Road_2 = searchResult[i].right;
                    if (Road_1 && Road_2)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_upRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].down;
                    bool Road_2 = searchResult[i].down_right;
                    bool Road_3 = searchResult[i].right;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_right_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_right_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].left;
                    bool Road_2 = searchResult[i].up;
                    bool Road_3 = searchResult[i].up_right;
                    bool Road_4 = searchResult[i].up_left;
                    if (Road_1 && Road_2 && Road_3 && Road_4)
                    {
                        situation_3 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_upRight_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].right;
                    if (Road_1)
                    {
                        situation_4 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }

            }
            if (situation_1 && situation_2 && situation_3 && situation_4)
            {
                return true;
            }
        }
        if (roationID == 2)
        {
            bool situation_1 = false;
            bool situation_2 = false;
            bool situation_3 = false;
            bool situation_4 = false;

            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;


            Point rightAngleVertex;						//(  x  , y)
            Point rightAngleVertex_downRight;			//(x + 1,y - 1)
            Point rightAngleVertex_down_down;			//(  x  ,y - 2)
            Point rightAngleVertex_downRight_down;		//(x + 1,y - 2)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y - 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down_down = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y - 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight_down = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2 && situation_3 && situation_4)
                {
                    return true;
                }


                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].down_right;
                    bool Road_2 = searchResult[i].down;
                    if (Road_1 && Road_2)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_downRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].left;
                    bool Road_2 = searchResult[i].down_left;
                    bool Road_3 = searchResult[i].down;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_down_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_down_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    bool Road_2 = searchResult[i].right;
                    bool Road_3 = searchResult[i].down_right;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_3 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_downRight_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].down;
                    if (Road_1)
                    {
                        situation_4 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }

            }
            if (situation_1 && situation_2 && situation_3 && situation_4)
            {
                return true;
            }
        }
        if (roationID == 3)
        {
            bool situation_1 = false;
            bool situation_2 = false;
            bool situation_3 = false;
            bool situation_4 = false;

            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;						//(  x  ,y)
            Point rightAngleVertex_downLeft;			//(x - 1,y - 1)
            Point rightAngleVertex_left_left;			//(x - 2,y)
            Point rightAngleVertex_downLeft_left;		//(x - 2,y - 1)

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X - 2 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left_left = searchResult[i];
                    continue;
                }
                if (coordinate_X - 2 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft_left = searchResult[i];
                    continue;
                }
            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2 && situation_3 && situation_4)
                {
                    return true;
                }


                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].left;
                    bool Road_2 = searchResult[i].down_left;
                    if (Road_1 && Road_2)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_downLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    bool Road_2 = searchResult[i].up_left;
                    bool Road_3 = searchResult[i].left;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_left_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_left_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].down_left;
                    bool Road_2 = searchResult[i].down;
                    bool Road_3 = searchResult[i].right;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_3 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_downLeft_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].left;
                    if (Road_1)
                    {
                        situation_4 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }

            }
            if (situation_1 && situation_2 && situation_3 && situation_4)
            {
                return true;
            }
        }
        if (roationID == 4)
        {
            bool situation_1 = false;
            bool situation_2 = false;
            bool situation_3 = false;
            bool situation_4 = false;

            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;				//(  x  ,y)
            Point rightAngleVertex_upLeft;		//(x - 1,y + 1)
            Point rightAngleVertex_up_up;		//(  x  ,y + 2)
            Point rightAngleVertex_upLeft_up;	//(x - 1,y + 2)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y + 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up_up = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y + 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft_up = searchResult[i];
                    continue;
                }
            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2 && situation_3 && situation_4)
                {
                    return true;
                }


                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    bool Road_2 = searchResult[i].up_left;
                    if (Road_1 && Road_2)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_upLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    bool Road_2 = searchResult[i].up_right;
                    bool Road_3 = searchResult[i].right;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_up_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_up_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up_left;
                    bool Road_2 = searchResult[i].left;
                    bool Road_3 = searchResult[i].down;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_3 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_upLeft_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    if (Road_1)
                    {
                        situation_4 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }

            }
            if (situation_1 && situation_2 && situation_3 && situation_4)
            {
                return true;
            }
        }

    }
    if (judgeType == 5)		//PA Mirroring
    {
		if (roationID == 1)
        {
            bool situation_1 = false;
            bool situation_2 = false;
            bool situation_3 = false;
            bool situation_4 = false;

            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;						//(  x  ,  y )
            Point rightAngleVertex_downRight;			//(x + 1,y - 1)
            Point rightAngleVertex_right_right;			//(x + 2,y)
            Point rightAngleVertex_downRight_right;		//(x + 2,y - 1)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight = searchResult[i];
                    continue;
                }
                if (coordinate_X + 2 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right_right = searchResult[i];
                    continue;
                }
                if (coordinate_X + 2 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight_right = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2 && situation_3 && situation_4)
                {
                    return true;
                }


                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].down_right;
                    bool Road_2 = searchResult[i].right;
                    if (Road_1 && Road_2)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_downRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    bool Road_2 = searchResult[i].up_right;
                    bool Road_3 = searchResult[i].right;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
						return false;
                    }
                }
                else if (rightAngleVertex_right_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_right_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].left;
                    bool Road_2 = searchResult[i].down;
                    bool Road_3 = searchResult[i].down_left;
                    bool Road_4 = searchResult[i].down_right;
                    if (Road_1 && Road_2 && Road_3 && Road_4)
                    {
                        situation_3 = true;
                        continue;
                    }
                    else
                    {
						return false;
                    }
                }
                else if (rightAngleVertex_downRight_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].right;
                    if (Road_1)
                    {
                        situation_4 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }

            }
            if (situation_1 && situation_2 && situation_3 && situation_4)
            {
                return true;
            }
        }
        if (roationID == 2)
        {
            bool situation_1 = false;
            bool situation_2 = false;
            bool situation_3 = false;
            bool situation_4 = false;

            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;


            Point rightAngleVertex;						//(  x  , y)
            Point rightAngleVertex_downLeft;			//(x - 1,y - 1)
            Point rightAngleVertex_down_down;			//(  x  ,y - 2)
            Point rightAngleVertex_downLeft_down;		//(x - 1,y - 2)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y - 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down_down = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y - 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft_down = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2 && situation_3 && situation_4)
                {
                    return true;
                }


                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].down_left;
                    bool Road_2 = searchResult[i].down;
                    if (Road_1 && Road_2)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_downLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].right;
                    bool Road_2 = searchResult[i].down_right;
                    bool Road_3 = searchResult[i].down;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
						return false;
                    }
                }
                else if (rightAngleVertex_down_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_down_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    bool Road_2 = searchResult[i].left;
                    bool Road_3 = searchResult[i].down_left;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_3 = true;
                        continue;
                    }
                    else
                    {
						return false;
                    }
                }
                else if (rightAngleVertex_downLeft_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].down;
                    if (Road_1)
                    {
                        situation_4 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }

            }
            if (situation_1 && situation_2 && situation_3 && situation_4)
            {
                return true;
            }
        }
        if (roationID == 3)
        {
            bool situation_1 = false;
            bool situation_2 = false;
            bool situation_3 = false;
            bool situation_4 = false;

            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;						//(  x  ,y)
            Point rightAngleVertex_upLeft;				//(x - 1,y + 1)
            Point rightAngleVertex_left_left;			//(x - 2,y)
            Point rightAngleVertex_upLeft_left;			//(x - 2,y + 1)

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X - 2 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left_left = searchResult[i];
                    continue;
                }
                if (coordinate_X - 2 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft_left = searchResult[i];
                    continue;
                }
            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2 && situation_3 && situation_4)
                {
                    return true;
                }


                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].left;
                    bool Road_2 = searchResult[i].up_left;
                    if (Road_1 && Road_2)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
						return false;
                    }
                }
                else if (rightAngleVertex_upLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].down;
                    bool Road_2 = searchResult[i].left;
                    bool Road_3 = searchResult[i].down_left;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
						return false;
                    }
                }
                else if (rightAngleVertex_left_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_left_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    bool Road_2 = searchResult[i].up_left;
                    bool Road_3 = searchResult[i].right;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_3 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_upLeft_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].left;
                    if (Road_1)
                    {
                        situation_4 = true;
                        continue;
                    }
                    else
                    {
						return false;
                    }
                }

            }
            if (situation_1 && situation_2 && situation_3 && situation_4)
            {
                return true;
            }
        }
        if (roationID == 4)
        {
            bool situation_1 = false;
            bool situation_2 = false;
            bool situation_3 = false;
            bool situation_4 = false;

            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;				//(  x  ,y)
            Point rightAngleVertex_upRight;		//(x + 1,y + 1)
            Point rightAngleVertex_up_up;		//(  x  ,y + 2)
            Point rightAngleVertex_upRight_up;	//(x + 1,y + 2)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y + 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up_up = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y + 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight_up = searchResult[i];
                    continue;
                }
            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (situation_1 && situation_2 && situation_3 && situation_4)
                {
                    return true;
                }

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    bool Road_2 = searchResult[i].up_right;
                    if (Road_1 && Road_2)
                    {
                        situation_1 = true;
                        continue;
                    }
                    else
                    {
						return false;
                    }
                }
                else if (rightAngleVertex_upRight.coordinate_X == searchResult[i].coordinate_X 
                    && rightAngleVertex_upRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].right;
                    bool Road_2 = searchResult[i].up_left;
                    bool Road_3 = searchResult[i].left;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_2 = true;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (rightAngleVertex_up_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_up_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up_right;
                    bool Road_2 = searchResult[i].right;
                    bool Road_3 = searchResult[i].down;
                    if (Road_1 && Road_2 && Road_3)
                    {
                        situation_3 = true;
                        continue;
                    }
                    else
                    {
						return false;
                    }
                }
                else if (rightAngleVertex_upRight_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    bool Road_1 = searchResult[i].up;
                    if (Road_1)
                    {
                        situation_4 = true;
                        continue;
                    }
                    else
                    {
						return false;
                    }
                }

            }

			if (situation_1 && situation_2 && situation_3 && situation_4)
            {
                return true;
            }
        }

    }

    return false;

}

/*
* Description:	This is DeleteRoad function, after it can put into it then the road(Point to Point connect),
*				will be delete
*/
vector<Point> DeleteRoad(vector<Point>searchResult, Point p, int graphID, int roationID)
{
    /*
        * graphID:
        *		LT_1:			1
        *		LT_2:			2
        *		MT:				3
        *		ST_1:			4
        *		ST_2:			5
        *		SQ:				6
        *		PA:				7
        *		PA Mirroring:	8
        */

        /*
        * rotationID:
        *		Rotate right once:		1
        *		Rotate right twice:		2
        *		Rotate right 3 times:	3
        *		Rotate right 4 times:	4
        */

    int judgeType = -1;
    if (graphID == 1 || graphID == 2)	//LT
    {
        judgeType = 0;
    }
    if (graphID == 3)	//MT
    {
        judgeType = 1;
    }
    if (graphID == 4 || graphID == 5)	//ST(graphID = 4 and graphID = 5)
    {
        judgeType = 2;
    }
    if (graphID == 6)
    {
        judgeType = 3;
    }
    if (graphID == 7)
    {
        judgeType = 4;

    }
    if (graphID == 8)
    {
        judgeType = 5;

    }

    vector<Point> deleteRoadResultERROR;

    if (judgeType == 0)
    {
        if (roationID == 1)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;						//(  x  , y)
            Point rightAngleVertex_right;				//(x + 1, y)
            Point rightAngleVertex_upRight;				//(x + 1, y + 1)
            Point rightAngleVertex_downRight;			//(x + 1, y - 1)
            Point rightAngleVertex_right_right;			//(x + 2, y)
            Point rightAngleVertex_upRight_right;		//(x + 2, y + 1)
            Point rightAngleVertex_downRight_right;		//(x + 2, y - 1)
            Point rightAngleVertex_upRight_upRight;		//(x + 2, y + 2)
            Point rightAngleVertex_downRight_downRight;	//(x + 2, y - 2)

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight = searchResult[i];
                    continue;
                }
                if (coordinate_X + 2 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right_right = searchResult[i];
                    continue;
                }
                if (coordinate_X + 2 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight_right = searchResult[i];
                    continue;
                }
                if (coordinate_X + 2 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight_right = searchResult[i];
                    continue;
                }
                if (coordinate_X + 2 == searchResult[i].coordinate_X && coordinate_Y + 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight_upRight = searchResult[i];
                    continue;
                }
                if (coordinate_X + 2 == searchResult[i].coordinate_X && coordinate_Y - 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight_downRight = searchResult[i];
                    continue;
                }

            }


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right.up = nullptr;
                    rightAngleVertex_right.down = nullptr;
                    rightAngleVertex_right.left = nullptr;
                    rightAngleVertex_right.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_right);
                    continue;
                }
                else if (rightAngleVertex_upRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight.down = nullptr;
                    rightAngleVertex_upRight.down_right = nullptr;
                    rightAngleVertex_upRight.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_upRight);
                    continue;
                }
                else if (rightAngleVertex_downRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight.up = nullptr;
                    rightAngleVertex_downRight.up_right = nullptr;
                    rightAngleVertex_downRight.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_downRight);
                    continue;
                }
                else if (rightAngleVertex_right_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_right_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right_right.up_left = nullptr;
                    rightAngleVertex_right_right.left = nullptr;
                    rightAngleVertex_right_right.down_left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_right_right);
                    continue;
                }
                else if (rightAngleVertex_upRight_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight_right.left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_upRight_right);
                    continue;
                }
                else if (rightAngleVertex_downRight_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight_right.left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_downRight_right);
                    continue;
                }
                else if (rightAngleVertex_upRight_upRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight_upRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_upRight_upRight);
                    continue;
                }
                else if (rightAngleVertex_downRight_downRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight_downRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_downRight_downRight);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);
                }
            }

            return deleteRoadResult;

        }
        if (roationID == 2)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;						//(  x  , y)
            Point rightAngleVertex_down;				//(  x  , y - 1)
            Point rightAngleVertex_downLeft;			//(x - 1, y - 1)
            Point rightAngleVertex_downRight;			//(x + 1, y - 1)
            Point rightAngleVertex_down_down;			//(  x  , y - 2)
            Point rightAngleVertex_downLeft_down;		//(x - 1, y - 2)
            Point rightAngleVertex_downRight_down;		//(x + 1, y - 2)
            Point rightAngleVertex_downLeft_downLeft;	//(x - 2, y - 2)
            Point rightAngleVertex_downRight_downRight;	//(x + 2, y - 2)

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y - 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down_down = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y - 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft_down = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y - 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight_down = searchResult[i];
                    continue;
                }
                if (coordinate_X - 2 == searchResult[i].coordinate_X && coordinate_Y - 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft_downLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X + 2 == searchResult[i].coordinate_X && coordinate_Y - 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight_downRight = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex.down = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down.up = nullptr;
                    rightAngleVertex_down.down = nullptr;
                    rightAngleVertex_down.left = nullptr;
                    rightAngleVertex_down.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_down);
                    continue;
                }
                else if (rightAngleVertex_downLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft.down = nullptr;
                    rightAngleVertex_downLeft.down_right = nullptr;
                    rightAngleVertex_downLeft.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_downLeft);
                    continue;
                }
                else if (rightAngleVertex_downRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight.left = nullptr;
                    rightAngleVertex_downRight.down_left = nullptr;
                    rightAngleVertex_downRight.down = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_downRight);
                    continue;
                }
                else if (rightAngleVertex_down_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_down_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down_down.up_left = nullptr;
                    rightAngleVertex_down_down.up_right = nullptr;
                    rightAngleVertex_down_down.up = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_down_down);
                    continue;
                }
                else if (rightAngleVertex_downLeft_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft_down.up = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_downLeft_down);
                    continue;
                }
                else if (rightAngleVertex_downRight_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight_down.up = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_downRight_down);
                    continue;
                }
                else if (rightAngleVertex_downLeft_downLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft_downLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_downLeft_downLeft);
                    continue;
                }
                else if (rightAngleVertex_downRight_downRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight_downRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_downRight_downRight);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);
                }
            }
            return deleteRoadResult;
        }
        if (roationID == 3)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;						//(  x  , y)
            Point rightAngleVertex_left;				//(x - 1, y)
            Point rightAngleVertex_upLeft;				//(x - 1, y + 1)
            Point rightAngleVertex_downLeft;			//(x - 1, y - 1)
            Point rightAngleVertex_left_left;			//(x - 2, y)
            Point rightAngleVertex_upLeft_left;			//(x - 2, y + 1)
            Point rightAngleVertex_downLeft_left;		//(x - 2, y - 1)
            Point rightAngleVertex_upLeft_upLeft;		//(x - 2, y + 2)
            Point rightAngleVertex_downLeft_downLeft;	//(x - 2, y - 2)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X - 2 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left_left = searchResult[i];
                    continue;
                }
                if (coordinate_X - 2 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft_left = searchResult[i];
                    continue;
                }
                if (coordinate_X - 2 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft_left = searchResult[i];
                    continue;
                }
                if (coordinate_X - 2 == searchResult[i].coordinate_X && coordinate_Y + 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft_upLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X - 2 == searchResult[i].coordinate_X && coordinate_Y - 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft_downLeft = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex.left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left.up = nullptr;
                    rightAngleVertex_left.down = nullptr;
                    rightAngleVertex_left.left = nullptr;
                    rightAngleVertex_left.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_left);
                    continue;
                }
                else if (rightAngleVertex_upLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft.down = nullptr;
                    rightAngleVertex_upLeft.down_left = nullptr;
                    rightAngleVertex_upLeft.left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_upLeft);
                    continue;
                }
                else if (rightAngleVertex_downLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft.up = nullptr;
                    rightAngleVertex_downLeft.up_left = nullptr;
                    rightAngleVertex_downLeft.left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_downLeft);
                    continue;
                }
                else if (rightAngleVertex_left_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_left_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left_left.up_right = nullptr;
                    rightAngleVertex_left_left.down_right = nullptr;
                    rightAngleVertex_left_left.up = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_left_left);
                    continue;
                }
                else if (rightAngleVertex_upLeft_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft_left.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_upLeft_left);
                    continue;
                }
                else if (rightAngleVertex_downLeft_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft_left.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_downLeft_left);
                    continue;
                }
                else if (rightAngleVertex_upLeft_upLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft_upLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_upLeft_upLeft);
                    continue;
                }
                else if (rightAngleVertex_downLeft_downLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft_downLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_downLeft_downLeft);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);
                }
            }

            return deleteRoadResult;
        }
        if (roationID == 4)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;					//(  x  , y)
            Point rightAngleVertex_up;				//(  x  , y + 1)
            Point rightAngleVertex_upLeft;			//(x - 1, y + 1)
            Point rightAngleVertex_upRight;			//(x + 1, y + 1)
            Point rightAngleVertex_up_up;			//(  x  , y + 2)
            Point rightAngleVertex_upLeft_up;		//(x - 1, y + 2)
            Point rightAngleVertex_upRight_up;		//(x + 1, y + 2)
            Point rightAngleVertex_upLeft_upLeft;	//(x - 2, y + 2)
            Point rightAngleVertex_upRight_upRight;	//(x + 2, y + 2)



            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y + 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up_up = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y + 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft_up = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y + 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight_up = searchResult[i];
                    continue;
                }
                if (coordinate_X - 2 == searchResult[i].coordinate_X && coordinate_Y + 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft_upLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X + 2 == searchResult[i].coordinate_X && coordinate_Y + 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight_upRight = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex.up = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up.up = nullptr;
                    rightAngleVertex_up.down = nullptr;
                    rightAngleVertex_up.left = nullptr;
                    rightAngleVertex_up.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_up);
                    continue;
                }
                else if (rightAngleVertex_upLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft.up = nullptr;
                    rightAngleVertex_upLeft.up_right = nullptr;
                    rightAngleVertex_upLeft.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_upLeft);
                    continue;
                }
                else if (rightAngleVertex_upRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight.up = nullptr;
                    rightAngleVertex_upRight.up_left = nullptr;
                    rightAngleVertex_upRight.left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_upRight);
                    continue;
                }
                else if (rightAngleVertex_up_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_up_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up_up.down_left = nullptr;
                    rightAngleVertex_up_up.down_right = nullptr;
                    rightAngleVertex_up_up.down = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_up_up);
                    continue;
                }
                else if (rightAngleVertex_upLeft_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft_up.down = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_upLeft_up);
                    continue;
                }
                else if (rightAngleVertex_upRight_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight_up.down = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_upRight_up);
                    continue;
                }
                else if (rightAngleVertex_upLeft_upLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft_upLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_upLeft_upLeft);
                    continue;
                }
                else if (rightAngleVertex_upRight_upRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight_upRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_upRight_upRight);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);
                }
            }

            return deleteRoadResult;
        }
    }
    if (judgeType == 1)
    {
        if (roationID == 1)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;				//(  x  , y)
            Point rightAngleVertex_up;			//(  x  , y + 1)
            Point rightAngleVertex_upRight;		//(x + 1, y + 1)
            Point rightAngleVertex_right;		//(x + 1, y)
            Point rightAngleVertex_up_up;		//(  x  , y + 2)
            Point rightAngleVertex_right_right;	//(x + 2, y)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y + 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up_up = searchResult[i];
                    continue;
                }
                if (coordinate_X + 2 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right_right = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex.up_right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_up);
                    continue;
                }
                else if (rightAngleVertex_upRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight.left = nullptr;
                    rightAngleVertex_upRight.down = nullptr;
                    rightAngleVertex_upRight.down_left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_upRight);
                    continue;
                }
                else if (rightAngleVertex_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right.up = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_right);
                    continue;
                }
                else if (rightAngleVertex_up_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_up_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_up_up);
                    continue;
                }
                else if (rightAngleVertex_right_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_right_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_right_right);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);
                }
            }

            return deleteRoadResult;

        }
        if (roationID == 2)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;				//(  x  , y)
            Point rightAngleVertex_right;		//(x + 1, y)
            Point rightAngleVertex_down;		//(  x  , y - 1)
            Point rightAngleVertex_downRight;	//(x + 1, y - 1)
            Point rightAngleVertex_right_right;	//(x + 2, y)
            Point rightAngleVertex_down_down;	//(  x  , y - 2)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight = searchResult[i];
                    continue;
                }
                if (coordinate_X + 2 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right_right = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y - 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down_down = searchResult[i];
                    continue;
                }

            }


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex.down_right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right.down = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_right);
                    continue;
                }
                else if (rightAngleVertex_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_down);
                    continue;
                }
                else if (rightAngleVertex_downRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight.up = nullptr;
                    rightAngleVertex_downRight.left = nullptr;
                    rightAngleVertex_downRight.up_left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_downRight);
                    continue;
                }
                else if (rightAngleVertex_right_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_right_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_right_right);
                    continue;
                }
                else if (rightAngleVertex_down_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_down_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_down_down);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);
                }
            }

            return deleteRoadResult;
        }
        if (roationID == 3)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;				//(  x  , y)
            Point rightAngleVertex_left;		//(x - 1, y)
            Point rightAngleVertex_down;		//(  x  , y - 1)
            Point rightAngleVertex_downLeft;	//(x - 1, y - 1)
            Point rightAngleVertex_left_left;	//(x - 2, y)
            Point rightAngleVertex_down_down;	//(  x  , y - 2)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X - 2 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left_left = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y - 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down_down = searchResult[i];
                    continue;
                }

            }


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex.down_left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left.down = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_left);
                    continue;
                }
                else if (rightAngleVertex_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down.left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_down);
                    continue;
                }
                else if (rightAngleVertex_downLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft.up = nullptr;
                    rightAngleVertex_downLeft.right = nullptr;
                    rightAngleVertex_downLeft.up_right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_downLeft);
                    continue;
                }
                else if (rightAngleVertex_left_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_left_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_left_left);
                    continue;
                }
                else if (rightAngleVertex_down_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_down_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_down_down);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);
                }
            }

            return deleteRoadResult;
        }
        if (roationID == 4)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;				//(  x  , y)
            Point rightAngleVertex_left;		//(x - 1, y)
            Point rightAngleVertex_up;			//(  x  , y + 1)
            Point rightAngleVertex_upLeft;		//(x - 1, y + 1)
            Point rightAngleVertex_left_left;	//(x - 2, y)
            Point rightAngleVertex_up_up;		//(  x  , y + 2)

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X - 2 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left_left = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y + 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up_up = searchResult[i];
                    continue;
                }

            }


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex.up_left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left.up = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_left);
                    continue;
                }
                else if (rightAngleVertex_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up.left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_up);
                    continue;
                }
                else if (rightAngleVertex_upLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft.down = nullptr;
                    rightAngleVertex_upLeft.right = nullptr;
                    rightAngleVertex_upLeft.down_right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_upLeft);
                    continue;
                }
                else if (rightAngleVertex_left_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_left_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_left_left);
                    continue;
                }
                else if (rightAngleVertex_up_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_up_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_up_up);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);
                }
            }

            return deleteRoadResult;
        }
    }
    if (judgeType == 2)	//judgeType == 2 : ST(graphID = 4 and graphID = 5)
    {
        if (roationID == 1)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;				//(  x  , y)
            Point rightAngleVertex_right;		//(x + 1, y)
            Point rightAngleVertex_upRight;		//(x + 1, y + 1)
            Point rightAngleVertex_downRight;	//(x - 1, y - 1)

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight = searchResult[i];
                    continue;
                }

            }


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right.left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_right);
                    continue;
                }
                else if (rightAngleVertex_upRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_upRight);
                    continue;
                }
                else if (rightAngleVertex_downRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_downRight);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);

                }
            }

            return deleteRoadResult;
        }
        if (roationID == 2)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;				//(  x  , y)
            Point rightAngleVertex_down;		//(  x  , y - 1)
            Point rightAngleVertex_downLeft;	//(x - 1, y - 1)
            Point rightAngleVertex_downRight;	//(x + 1, y - 1)

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex.down = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down.up = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_down);
                    continue;
                }
                else if (rightAngleVertex_downLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_downLeft);
                    continue;
                }
                else if (rightAngleVertex_downRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_downRight);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);

                }
            }
            return deleteRoadResult;
        }
        if (roationID == 3)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;			//(  x  , y)
            Point rightAngleVertex_left;	//(x - 1, y)
            Point rightAngleVertex_upLeft;	//(x - 1, y + 1)
            Point rightAngleVertex_downLeft;//(x - 1, y - 1)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex.left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_left);
                    continue;
                }
                else if (rightAngleVertex_upLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_upLeft);
                    continue;
                }
                else if (rightAngleVertex_downLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_downLeft);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);

                }
            }

            return deleteRoadResult;
        }
        if (roationID == 4)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;			//(  x  , y)
            Point rightAngleVertex_up;		//(  x  , y + 1)
            Point rightAngleVertex_upLeft;	//(x - 1, y + 1)
            Point rightAngleVertex_upRight;	//(x + 1, y + 1)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight = searchResult[i];
                    continue;
                }

            }


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex.up = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up.down = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_up);
                    continue;
                }
                else if (rightAngleVertex_upLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_upLeft);
                    continue;
                }
                else if (rightAngleVertex_upRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_upRight);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);

                }
            }

            return deleteRoadResult;
        }
    }
    if (judgeType == 3)	//SQ
    {
        if (roationID == 1)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;				//(  x  , y)
            Point rightAngleVertex_upRight;		//(x + 1, y + 1)
            Point rightAngleVertex_right;		//(x + 1, y)
            Point rightAngleVertex_downRight;	//(x + 1, y - 1)
            Point rightAngleVertex_right_right;	//(x + 2, y)

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight = searchResult[i];
                    continue;
                }
                if (coordinate_X + 2 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right_right = searchResult[i];
                    continue;
                }
            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_upRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight.down = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_upRight);
                    continue;
                }
                else if (rightAngleVertex_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right.up = nullptr;
                    rightAngleVertex_right.down = nullptr;
                    rightAngleVertex_right.left = nullptr;
                    rightAngleVertex_right.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_right);
                    continue;
                }
                else if (rightAngleVertex_downRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight.up = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_downRight);
                    continue;
                }
                else if (rightAngleVertex_right_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_right_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right_right.left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_right_right);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);
                }
            }

            return deleteRoadResult;

        }
        if (roationID == 2)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;				//(  x  , y)
            Point rightAngleVertex_downLeft;	//(x - 1, y - 1)
            Point rightAngleVertex_down;		//(  x  , y - 1)
            Point rightAngleVertex_downRight;	//(x + 1, y - 1)
            Point rightAngleVertex_down_down;	//(  x  , y - 2)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y - 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down_down = searchResult[i];
                    continue;
                }
            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex.down = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_downLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_downLeft);
                    continue;
                }
                else if (rightAngleVertex_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down.up = nullptr;
                    rightAngleVertex_down.down = nullptr;
                    rightAngleVertex_down.left = nullptr;
                    rightAngleVertex_down.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_down);
                    continue;
                }
                else if (rightAngleVertex_downRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight.left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_downRight);
                    continue;
                }
                else if (rightAngleVertex_down_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_down_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down_down.up = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_down_down);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);
                }
            }

            return deleteRoadResult;
        }
        if (roationID == 3)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;				//(  x  , y)
            Point rightAngleVertex_upLeft;		//(x - 1, y + 1)
            Point rightAngleVertex_left;		//(x - 1, y)
            Point rightAngleVertex_downLeft;	//(x - 1, y - 1)
            Point rightAngleVertex_left_left;	//(x - 2, y)



            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X - 2 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left_left = searchResult[i];
                    continue;
                }
            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex.left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_upLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft.down = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_upLeft);
                    continue;
                }
                else if (rightAngleVertex_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left.up = nullptr;
                    rightAngleVertex_left.down = nullptr;
                    rightAngleVertex_left.left = nullptr;
                    rightAngleVertex_left.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_left);
                    continue;
                }
                else if (rightAngleVertex_downLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft.up = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_downLeft);
                    continue;
                }
                else if (rightAngleVertex_left_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_left_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left_left.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_left_left);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);
                }
            }

            return deleteRoadResult;
        }
        if (roationID == 4)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;			//(  x  , y)
            Point rightAngleVertex_upLeft;	//(x - 1, y + 1)
            Point rightAngleVertex_up;		//(  x  , y + 1)
            Point rightAngleVertex_upRight;	//(x + 1, y + 1)
            Point rightAngleVertex_up_up;	//(  x  , y + 2)



            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y + 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up_up = searchResult[i];
                    continue;
                }
            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex.up = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_upLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_upLeft);
                    continue;
                }
                else if (rightAngleVertex_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up.up = nullptr;
                    rightAngleVertex_up.down = nullptr;
                    rightAngleVertex_up.left = nullptr;
                    rightAngleVertex_up.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_up);
                    continue;
                }
                else if (rightAngleVertex_upRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight.left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_upRight);
                    continue;
                }
                else if (rightAngleVertex_up_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_up_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up_up.down = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_up_up);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);
                }
            }

            return deleteRoadResult;
        }
    }
    if (judgeType == 4)		//PA
    {
        if (roationID == 1)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;						//(  x  , y)
            Point rightAngleVertex_upRight;				//(x + 1,y + 1)
            Point rightAngleVertex_right;				//(x + 1,y)
            Point rightAngleVertex_right_right;			//(x + 2,y)
            Point rightAngleVertex_upRight_right;		//(x + 2,y + 1)
            Point rightAngleVertex_upRight_right_right;	//(x + 3,y + 1)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right = searchResult[i];
                    continue;
                }
                if (coordinate_X + 2 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right_right = searchResult[i];
                    continue;
                }
                if (coordinate_X + 2 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight_right = searchResult[i];
                    continue;
                }
                if (coordinate_X + 3 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight_right_right = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_upRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight.down = nullptr;
                    rightAngleVertex_upRight.down_right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_upRight);
                    continue;
                }
                else if (rightAngleVertex_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right.up = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_right);
                    continue;
                }
                else if (rightAngleVertex_right_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_right_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right_right.up = nullptr;
                    rightAngleVertex_right_right.up_left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_right_right);
                    continue;
                }
                else if (rightAngleVertex_upRight_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight_right.down = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_upRight_right);
                    continue;
                }
                else if (rightAngleVertex_upRight_right_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight_right_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight_right_right.down = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_upRight_right_right);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);
                }
            }

            return deleteRoadResult;
        }
        if (roationID == 2)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;


            Point rightAngleVertex;						//(  x  , y)
            Point rightAngleVertex_down;				//(  x  ,y - 1)
            Point rightAngleVertex_downRight;			//(x + 1,y - 1)
            Point rightAngleVertex_down_down;			//(  x  ,y - 2)
            Point rightAngleVertex_downRight_down;		//(x + 1,y - 2)
            Point rightAngleVertex_downRight_down_down;	//(x + 1,y - 3)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y - 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down_down = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y - 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight_down = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y - 3 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight_down_down = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_down);
                    continue;
                }
                else if (rightAngleVertex_downRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight.left = nullptr;
                    rightAngleVertex_downRight.down_left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_downRight);
                    continue;
                }
                else if (rightAngleVertex_down_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_down_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down_down.up_right = nullptr;
                    rightAngleVertex_down_down.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_down_down);
                    continue;
                }
                else if (rightAngleVertex_downRight_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight_down.left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_downRight_down);
                    continue;
                }
                else if (rightAngleVertex_downRight_down_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight_down_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_downRight_down_down);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);
                }
            }

            return deleteRoadResult;
        }
        if (roationID == 3)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;						//(  x  ,y)
            Point rightAngleVertex_left;				//(x - 1,y)
            Point rightAngleVertex_downLeft;			//(x - 1,y - 1)
            Point rightAngleVertex_left_left;			//(x - 2,y)
            Point rightAngleVertex_downLeft_left;		//(x - 2,y - 1)
            Point rightAngleVertex_downLeft_left_left;	//(x - 3,y - 1)

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X - 2 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left_left = searchResult[i];
                    continue;
                }
                if (coordinate_X - 2 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft_left = searchResult[i];
                    continue;
                }
                if (coordinate_X - 3 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft_left_left = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left.down = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_left);
                    continue;
                }
                else if (rightAngleVertex_downLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft.up = nullptr;
                    rightAngleVertex_downLeft.up_left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_downLeft);
                    continue;
                }
                else if (rightAngleVertex_left_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_left_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left_left.down = nullptr;
                    rightAngleVertex_left_left.down_right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_left_left);
                    continue;
                }
                else if (rightAngleVertex_downLeft_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft_left.up = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_downLeft_left);
                    continue;
                }
                else if (rightAngleVertex_downLeft_left_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft_left_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_downLeft_left_left);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);
                }
            }

            return deleteRoadResult;
        }
        if (roationID == 4)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;				//(  x  ,y)
            Point rightAngleVertex_up;			//(  x  ,y + 1)
            Point rightAngleVertex_upLeft;		//(x - 1,y + 1)
            Point rightAngleVertex_up_up;		//(  x  ,y + 2)
            Point rightAngleVertex_upLeft_up;	//(x - 1,y + 2)
            Point rightAngleVertex_upLeft_up_up;//(x - 1,y + 3)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y + 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up_up = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y + 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft_up = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y + 3 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft_up_up = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up.left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_up);
                    continue;
                }
                else if (rightAngleVertex_upLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft.right = nullptr;
                    rightAngleVertex_upLeft.up_right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_upLeft);
                    continue;
                }
                else if (rightAngleVertex_up_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_up_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up_up.left = nullptr;
                    rightAngleVertex_up_up.down_left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_up_up);
                    continue;
                }
                else if (rightAngleVertex_upLeft_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft_up.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_upLeft_up);
                    continue;
                }
                else if (rightAngleVertex_upLeft_up_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft_up_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_upLeft_up_up);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);
                }
            }

            return deleteRoadResult;
        }
    }
    if (judgeType == 5)		//PA Mirroring
    {
        if (roationID == 1)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;							//(  x  , y)
            Point rightAngleVertex_downRight;				//(x + 1,y - 1)
            Point rightAngleVertex_right;					//(x + 1,y)
            Point rightAngleVertex_right_right;				//(x + 2,y)
            Point rightAngleVertex_downRight_right;			//(x + 2,y - 1)
            Point rightAngleVertex_downRight_right_right;	//(x + 3,y - 1)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right = searchResult[i];
                    continue;
                }
                if (coordinate_X + 2 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right_right = searchResult[i];
                    continue;
                }
                if (coordinate_X + 2 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight_right = searchResult[i];
                    continue;
                }
                if (coordinate_X + 3 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight_right_right = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_downRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight.up = nullptr;
                    rightAngleVertex_downRight.up_right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_downRight);
                    continue;
                }
                else if (rightAngleVertex_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right.down = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_right);
                    continue;
                }
                else if (rightAngleVertex_right_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_right_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_right_right.down = nullptr;
                    rightAngleVertex_right_right.down_left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_right_right);
                    continue;
                }
                else if (rightAngleVertex_downRight_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downRight_right.up = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_downRight_right);
                    continue;
                }
                else if (rightAngleVertex_downRight_right_right.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downRight_right_right.coordinate_Y == searchResult[i].coordinate_Y)
                {
					rightAngleVertex_downRight_right_right.up = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_downRight_right_right);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);
                }
            }

            return deleteRoadResult;
        }
        if (roationID == 2)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;


            Point rightAngleVertex;						//(  x  , y)
            Point rightAngleVertex_down;				//(  x  ,y - 1)
            Point rightAngleVertex_downLeft;			//(x - 1,y - 1)
            Point rightAngleVertex_down_down;			//(  x  ,y - 2)
            Point rightAngleVertex_downLeft_down;		//(x - 1,y - 2)
            Point rightAngleVertex_downLeft_down_down;	//(x - 1,y - 3)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y - 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y - 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down_down = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y - 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft_down = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y - 3 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft_down_down = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down.left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_down);
                    continue;
                }
                else if (rightAngleVertex_downLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft.right = nullptr;
                    rightAngleVertex_downLeft.down_right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_downLeft);
                    continue;
                }
                else if (rightAngleVertex_down_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_down_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_down_down.up_left = nullptr;
                    rightAngleVertex_down_down.left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_down_down);
                    continue;
                }
                else if (rightAngleVertex_downLeft_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_downLeft_down.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_downLeft_down);
                    continue;
                }
                else if (rightAngleVertex_downLeft_down_down.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_downLeft_down_down.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_downLeft_down_down);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);
                }
            }

            return deleteRoadResult;
        }
        if (roationID == 3)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;						//(  x  ,y)
            Point rightAngleVertex_left;				//(x - 1,y)
            Point rightAngleVertex_upLeft;				//(x - 1,y + 1)
            Point rightAngleVertex_left_left;			//(x - 2,y)
            Point rightAngleVertex_upLeft_left;			//(x - 2,y + 1)
            Point rightAngleVertex_upLeft_left_left;	//(x - 3,y + 1)

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left = searchResult[i];
                    continue;
                }
                if (coordinate_X - 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft = searchResult[i];
                    continue;
                }
                if (coordinate_X - 2 == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left_left = searchResult[i];
                    continue;
                }
                if (coordinate_X - 2 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft_left = searchResult[i];
                    continue;
                }
                if (coordinate_X - 3 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft_left_left = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left.up = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_left);
                    continue;
                }
                else if (rightAngleVertex_upLeft.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft.down = nullptr;
                    rightAngleVertex_upLeft.down_left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_upLeft);
                    continue;
                }
                else if (rightAngleVertex_left_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_left_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_left_left.up = nullptr;
                    rightAngleVertex_left_left.up_right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_left_left);
                    continue;
                }
                else if (rightAngleVertex_upLeft_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upLeft_left.down = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_upLeft_left);
                    continue;
                }
                else if (rightAngleVertex_upLeft_left_left.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upLeft_left_left.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_upLeft_left_left);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);
                }
            }

            return deleteRoadResult;
        }
        if (roationID == 4)
        {
            vector<Point> deleteRoadResult;
            int coordinate_X = p.coordinate_X;
            int coordinate_Y = p.coordinate_Y;

            Point rightAngleVertex;					//(  x  ,y)
            Point rightAngleVertex_up;				//(  x  ,y + 1)
            Point rightAngleVertex_upRight;			//(x + 1,y + 1)
            Point rightAngleVertex_up_up;			//(  x  ,y + 2)
            Point rightAngleVertex_upRight_up;		//(x + 1,y + 2)
            Point rightAngleVertex_upRight_up_up;	//(x + 1,y + 3)


            for (unsigned int i = 0; i < searchResult.size(); i++)
            {
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y + 1 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight = searchResult[i];
                    continue;
                }
                if (coordinate_X == searchResult[i].coordinate_X && coordinate_Y + 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up_up = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y + 2 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight_up = searchResult[i];
                    continue;
                }
                if (coordinate_X + 1 == searchResult[i].coordinate_X && coordinate_Y + 3 == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight_up_up = searchResult[i];
                    continue;
                }

            }

            for (unsigned int i = 0; i < searchResult.size(); i++)
            {

                if (rightAngleVertex.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex);
                    continue;
                }
                else if (rightAngleVertex_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up.right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_up);
                    continue;
                }
                else if (rightAngleVertex_upRight.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight.left = nullptr;
                    rightAngleVertex_upRight.up_left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_upRight);
                    continue;
                }
                else if (rightAngleVertex_up_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_up_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_up_up.right = nullptr;
                    rightAngleVertex_up_up.down_right = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_up_up);
                    continue;
                }
                else if (rightAngleVertex_upRight_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    rightAngleVertex_upRight_up.left = nullptr;
                    deleteRoadResult.push_back(rightAngleVertex_upRight_up);
                    continue;
                }
                else if (rightAngleVertex_upRight_up_up.coordinate_X == searchResult[i].coordinate_X && rightAngleVertex_upRight_up_up.coordinate_Y == searchResult[i].coordinate_Y)
                {
                    deleteRoadResult.push_back(rightAngleVertex_upRight_up_up);
                    continue;
                }
                else
                {
                    deleteRoadResult.push_back(searchResult[i]);
                }
            }

            return deleteRoadResult;
        }
    }

    return deleteRoadResultERROR;
}


vector<vector<Point>> result;
vector<vector<info>> informationResult;
vector<info> information;

bool cmppoint(pair<int, int> i, pair<int, int> j) { return (i.first < j.first || (i.first == j.first && i.second < j.second)); }
vector<pair<int, int>> PointVector(int coordinate_X, int coordinate_Y, int graphID, int rotationID);

//Description: Remove duplicate graphics
bool JugdgeInformation(vector<info> informationBefore, vector<info> informationNow)
{
    for (int ib = 0; ib < informationBefore.size(); ib++)
    {
        auto& before = informationBefore[ib];

        vector<pair<int, int>> vbefore;

        bool fNoSame = true;
        for (auto& Now : informationNow)
        {
            if (Now.graphID == before.graphID)
            {
                if (!vbefore.size())
                {
                    vbefore = PointVector(before.coordinate_X, before.coordinate_Y, before.graphID, before.rotationID);
                    std::sort(vbefore.begin(), vbefore.end(), cmppoint);
                }
                vector<pair<int, int>> vNow = PointVector(Now.coordinate_X, Now.coordinate_Y, Now.graphID, Now.rotationID);
                std::sort(vNow.begin(), vNow.end(), cmppoint);
                if (vbefore.size() == vNow.size())
                {
                    for (int in = 0; in < vbefore.size(); in++)
                    {
                        if (vbefore[in].first != vNow[in].first
                            || vbefore[in].second != vNow[in].second)
                        {
                            return true;
                        }
                    }
                }
                else 
                    continue;

                fNoSame = false;
                break;
            }
        }

        if (fNoSame)
        {
			return true;
        }
    }
    return false;
}

int now = 0;

bool FilterL(vector<pair<int, int>> vC,vector<pair<int, int>> vDst)
{
	std::sort(vC.begin(), vC.end(), cmppoint);
	std::sort(vDst.begin(), vDst.end(), cmppoint);

	if (vC.size() != vDst.size())
	{
		return true;
	}
	for (int i = 0; i < vDst.size(); i++)
	{
		if (vC[i].first != vDst[i].first
			|| vC[i].second != vDst[i].second)
		{
			return true;
		}
	}

    return false;
}

/*
* Description:	This is backtrack function, it will backrack until it find all the correct solutions
*/
void backtrack(int graphIDArray[], int retationID, vector<Point> currentPoint)
{
    int graphID = graphIDArray[now];
    vector<Point> temp;
    if (now > 0)
    {
		//int CurID = graphIDArray[now-1];
		//if (CurID == 1) //condition satified
  //      {
		//	info cur = information.back();
		//	vector<pair<int, int>> vF = PointVector(cur.coordinate_X, cur.coordinate_Y, cur.graphID, cur.rotationID);
  //          std::sort(vF.begin(), vF.end(), cmppoint);

  //          if (vF[1].first != 6 || vF[1].second != 2
  //              || vF[0].first != 4 || vF[0].second != 0
  //              )
  //          {
  //              return;
  //          }
  //      }
  //      else if (CurID == 2)
  //      {
		//	info cur = information.back();
		//	vector<pair<int, int>> vS = PointVector(cur.coordinate_X, cur.coordinate_Y, cur.graphID, cur.rotationID);
  //          std::sort(vS.begin(), vS.end(), cmppoint);

  //          if (vS[0].first != 4 || vS[0].second != 0
  //              || vS[1].first != 4 || vS[1].second != 4
  //              || vS[2].first != 6 || vS[2].second != 2
  //              )
  //          {
  //              return;
  //          }
  //      }
  //      else if (CurID == 3)
  //      {
		//	info cur = information.back();
  //          vector<pair<int, int>> vC = PointVector(cur.coordinate_X, cur.coordinate_Y, cur.graphID, cur.rotationID);
  //          std::sort(vC.begin(), vC.end(), cmppoint);

  //          if (vC[0].first != 2 || vC[0].second != 0
  //              || vC[1].first != 4 || vC[1].second != 0
  //              || vC[2].first != 4 || vC[2].second != 2
  //              )
  //          {
  //              return;
  //          }
  //      }
        /* else if (CurID == 4)
        {
			info cur = information.back();
            vector<pair<int, int>> vC = PointVector(cur.coordinate_X, cur.coordinate_Y, cur.graphID, cur.rotationID);
            std::sort(vC.begin(), vC.end(), cmppoint);

            if (vC[0].first != 2 || vC[0].second != 2
                || vC[1].first != 3 || vC[1].second != 1
                || vC[2].first != 3 || vC[2].second != 3
                )
            {
                return;
            }
        }
         else if (CurID == 5)
        {
			info cur = information.back();
            vector<pair<int, int>> vC = PointVector(cur.coordinate_X, cur.coordinate_Y, cur.graphID, cur.rotationID);
            std::sort(vC.begin(), vC.end(), cmppoint);

            if (vC[0].first != 0 || vC[0].second != 0
                || vC[1].first != 1 || vC[1].second != 1
                || vC[2].first != 2 || vC[2].second != 0
                )
            {
                return;
            }
        }
        else if (CurID == 6)
        {
			info cur = information.back();
            vector<pair<int, int>> vC = PointVector(cur.coordinate_X, cur.coordinate_Y, cur.graphID, cur.rotationID);
            std::sort(vC.begin(), vC.end(), cmppoint);

            if (vC[0].first != 1 || vC[0].second != 1
                || vC[1].first != 2 || vC[1].second != 0
                || vC[2].first != 2 || vC[2].second != 2
                || vC[3].first != 3 || vC[3].second != 1
                )
            {
                return;
            }
        }
        else if (CurID == 7 || CurID == 8)
        {
			info cur = information.back();
            vector<pair<int, int>> vC = PointVector(cur.coordinate_X, cur.coordinate_Y, cur.graphID, cur.rotationID);
            std::sort(vC.begin(), vC.end(), cmppoint);

            if (vC[0].first != 3 || vC[0].second != 1
                || vC[1].first != 3 || vC[1].second != 3
                || vC[2].first != 4 || vC[2].second != 2
                || vC[3].first != 4 || vC[3].second != 4
                )
            {
                return;
            }
        }*/
    }
  //  if (now > 0)
  //  {
		//info cur = information[now - 1];
		//vector<pair<int, int>> vCur = PointVector(cur.coordinate_X, cur.coordinate_Y, cur.graphID, cur.rotationID);
		//if ((now == 1 && FilterL(vCur, vector<pair<int, int>>{ {0, 0}, { 0,4 }, { 2,2 } }))
		//	|| (now == 2 && FilterL(vCur, vector<pair<int, int>>{ {3, 3}, { 3,7 }, { 5,5 } }))
		//	|| (now == 3 && FilterL(vCur, vector<pair<int, int>>{ {3, 5}, { 1,5 }, { 3,7 }}))
		//	|| (now == 4 && FilterL(vCur, vector<pair<int, int>>{ {3, 5}, { 2,4 }, { 1,5 }}))
		//	|| (now == 5 && FilterL(vCur, vector<pair<int, int>>{ {2, 2}, { 1,3 }, { 2,4 }}))
		//	|| (now == 6 && FilterL(vCur, vector<pair<int, int>>{ { 1,3 }, { 2,4 }, {0, 4}, { 1, 5 }}))
		//	|| (now == 7 && FilterL(vCur, vector<pair<int, int>>{ {2, 2}, { 2,4 }, { 3,3 }, { 3,5 } }))
  //          )
		//{
		//	//return;
		//}
  //  }
	

    if (now >= 7) //condition satified
    {
        bool fFind = false;
        for (int i = 0; i < informationResult.size(); i++)
        {
            if (!JugdgeInformation(informationResult[i], information))
            {
                fFind = true;
                break;
            }
        }
        if (!fFind)
        {
            informationResult.push_back(information);
            result.push_back(currentPoint);
        }

        return;
    }


    for (unsigned int i = 0; i < currentPoint.size(); i++) {
        Point p = currentPoint[i];
        for (int rotationID = 1; rotationID <= 4; rotationID++) {
            if (Matching(p, graphID, rotationID))	//condition satified
            {
                /*int ret = Judging(currentPoint, p, graphID, rotationID);
                if ((6 ==now& ret==2)|| (6 != now & ret == true))
				{
					if (ret == 2 && informationResult.size() == 17)
					{
						ret = ret;
					}*/
               if(Judging(currentPoint, p, graphID, rotationID))
                {
                    temp = currentPoint;
                    currentPoint = DeleteRoad(currentPoint, p, graphID, rotationID);
                    information.push_back({ p.coordinate_X, p.coordinate_Y, graphID, rotationID });
                    //graphID++;
                    now++;
                    backtrack(graphIDArray, rotationID, currentPoint);
                    information.pop_back();
                    currentPoint = temp;
                    //graphID--;
                    now--;
                }
            }
        }
    }
}

/*
* Description:	This is PointVector function, it will output a simple result, in order that we can
*				draw graph the in UI
*/
vector<pair<int, int>> PointVector(int coordinate_X, int coordinate_Y, int graphID, int rotationID)
{
    int judgeType = -1;
    if (graphID == 1 || graphID == 2)	//LT
    {
        judgeType = 0;
    }
    if (graphID == 3)	//MT
    {
        judgeType = 1;
    }
    if (graphID == 4 || graphID == 5)	//ST(graphID = 4 and graphID = 5)
    {
        judgeType = 2;
    }
    if (graphID == 6)
    {
        judgeType = 3;
    }
    if (graphID == 7)
    {
        judgeType = 4;
    }
    if (graphID == 8)
    {
        judgeType = 5;
    }

    vector<pair<int, int>> point;
    point.push_back({ coordinate_X, coordinate_Y });
    if (judgeType == 0)
    {
        if (rotationID == 1)
        {
            point.push_back({ coordinate_X + 2, coordinate_Y + 2 });
            point.push_back({ coordinate_X + 2, coordinate_Y - 2 });
        }
        if (rotationID == 2)
        {
            point.push_back({ coordinate_X - 2, coordinate_Y - 2 });
            point.push_back({ coordinate_X + 2, coordinate_Y - 2 });
        }
        if (rotationID == 3)
        {
            point.push_back({ coordinate_X - 2, coordinate_Y + 2 });
            point.push_back({ coordinate_X - 2, coordinate_Y - 2 });
        }
        if (rotationID == 4)
        {
            point.push_back({ coordinate_X + 2, coordinate_Y + 2 });
            point.push_back({ coordinate_X - 2, coordinate_Y + 2 });
        }

    }
    if (judgeType == 1)
    {
        if (rotationID == 1)
        {
            point.push_back({ coordinate_X + 2, coordinate_Y });
            point.push_back({ coordinate_X, coordinate_Y + 2 });
        }
        if (rotationID == 2)
        {
            point.push_back({ coordinate_X + 2, coordinate_Y });
            point.push_back({ coordinate_X, coordinate_Y - 2 });
        }
        if (rotationID == 3)
        {
            point.push_back({ coordinate_X - 2, coordinate_Y });
            point.push_back({ coordinate_X, coordinate_Y - 2 });
        }
        if (rotationID == 4)
        {
            point.push_back({ coordinate_X - 2, coordinate_Y });
            point.push_back({ coordinate_X, coordinate_Y + 2 });
        }

    }
    if (judgeType == 2)
    {
        if (rotationID == 1)
        {
            point.push_back({ coordinate_X + 1, coordinate_Y + 1 });
            point.push_back({ coordinate_X + 1, coordinate_Y - 1 });
        }
        if (rotationID == 2)
        {
            point.push_back({ coordinate_X + 1, coordinate_Y - 1 });
            point.push_back({ coordinate_X - 1, coordinate_Y - 1 });
        }
        if (rotationID == 3)
        {
            point.push_back({ coordinate_X - 1, coordinate_Y + 1 });
            point.push_back({ coordinate_X - 1, coordinate_Y - 1 });
        }
        if (rotationID == 4)
        {
            point.push_back({ coordinate_X + 1, coordinate_Y + 1 });
            point.push_back({ coordinate_X - 1, coordinate_Y + 1 });
        }

    }
    if (judgeType == 3)
    {
        if (rotationID == 1)
        {
            point.push_back({ coordinate_X + 1, coordinate_Y + 1 });
            point.push_back({ coordinate_X + 2, coordinate_Y });
            point.push_back({ coordinate_X + 1, coordinate_Y - 1 });
        }
        if (rotationID == 2)
        {
            point.push_back({ coordinate_X + 1, coordinate_Y - 1 });
            point.push_back({ coordinate_X , coordinate_Y - 2 });
            point.push_back({ coordinate_X - 1, coordinate_Y - 1 });
        }
        if (rotationID == 3)
        {
            point.push_back({ coordinate_X - 1, coordinate_Y - 1 });
            point.push_back({ coordinate_X - 2, coordinate_Y });
            point.push_back({ coordinate_X - 1, coordinate_Y + 1 });
        }
        if (rotationID == 4)
        {
            point.push_back({ coordinate_X + 1, coordinate_Y + 1 });
            point.push_back({ coordinate_X , coordinate_Y + 2 });
            point.push_back({ coordinate_X - 1, coordinate_Y + 1 });
        }

    }
    if (judgeType == 4)
    {
        if (rotationID == 1)
        {
            point.push_back({ coordinate_X + 1, coordinate_Y + 1 });
            point.push_back({ coordinate_X + 3, coordinate_Y + 1 });
            point.push_back({ coordinate_X + 2, coordinate_Y });
        }
        if (rotationID == 2)
        {
            point.push_back({ coordinate_X + 1, coordinate_Y - 1 });
            point.push_back({ coordinate_X + 1, coordinate_Y - 3 });
            point.push_back({ coordinate_X , coordinate_Y - 2 });
        }
        if (rotationID == 3)
        {
            point.push_back({ coordinate_X - 1, coordinate_Y - 1 });
            point.push_back({ coordinate_X - 3, coordinate_Y - 1 });
            point.push_back({ coordinate_X - 2, coordinate_Y });
        }
        if (rotationID == 4)
        {
            point.push_back({ coordinate_X - 1, coordinate_Y + 1 });
            point.push_back({ coordinate_X - 1, coordinate_Y + 3 });
            point.push_back({ coordinate_X , coordinate_Y + 2 });
        }

    }
    if (judgeType == 5)
    {
        if (rotationID == 1)
        {
            point.push_back({ coordinate_X + 2, coordinate_Y });
            point.push_back({ coordinate_X + 3, coordinate_Y - 1 });
            point.push_back({ coordinate_X + 1, coordinate_Y - 1 });
        }
        if (rotationID == 2)
        {
            point.push_back({ coordinate_X , coordinate_Y - 2 });
            point.push_back({ coordinate_X - 1, coordinate_Y - 3 });
            point.push_back({ coordinate_X - 1, coordinate_Y - 1 });
        }
        if (rotationID == 3)
        {
            point.push_back({ coordinate_X - 2, coordinate_Y });
            point.push_back({ coordinate_X - 3, coordinate_Y + 1 });
            point.push_back({ coordinate_X - 1, coordinate_Y + 1 });
        }
        if (rotationID == 4)
        {
            point.push_back({ coordinate_X , coordinate_Y + 2 });
            point.push_back({ coordinate_X + 1, coordinate_Y + 3 });
            point.push_back({ coordinate_X + 1 , coordinate_Y + 1 });
        }

    }
    return point;
}
/*
* Description:	This is PointVector function, it will output a simple result, in order that we can
*				draw graph the in UI
*/
vector<TangramGraph> FinalDeal(vector<info> inform)
{
    vector<TangramGraph> TG_V;
    vector<pair<int, int>> point;
    int GraphID = -1;
    for (unsigned int i = 0; i < inform.size(); i++)
    {
        GraphID = inform[i].graphID;
        point = PointVector(inform[i].coordinate_X, inform[i].coordinate_Y, GraphID, inform[i].rotationID);
        TG_V.push_back({ GraphID ,point });
    }

    return TG_V;
}

void Tangram::doit()
{
	informationResult.clear();
	result.clear();
	information.clear();

    inputSearch = Initalize_Class_TCFS();
    searchResult = Initalize_Class_Search();

    int searchNumber_1_Array[7] = { 1,2,3,4,5,6,7 };	//using for DFS
    int searchNumber_2_Array[7] = { 1,2,3,4,5,6,7 };	//using for BFD
    int searchNumber_3_Array[7] = { 1,2,3,6,7,4,5 };	//using for greedy
    int searchNumber_4_Array[7] = { 1,2,3,7,6,4,5 };	//using for A*


    if (searchNumber == 1)
    {
		backtrack(searchNumber_1_Array, 1, searchResult);
        for (int id = 0; id < 8; id++)
        {
            if (7 == searchNumber_1_Array[id])
            {
                searchNumber_1_Array[id] = 8;
                break;
            }
        }

		backtrack(searchNumber_1_Array, 1, searchResult);
    }
    else if (searchNumber == 2)
    {
		backtrack(searchNumber_2_Array, 1, searchResult);
		for (int id = 0; id < 8; id++)
		{
			if (7 == searchNumber_2_Array[id])
			{
                searchNumber_2_Array[id] = 8;
				break;
			}
		}
		backtrack(searchNumber_2_Array, 1, searchResult);
    }
    else if (searchNumber == 3)
    {
        backtrack(searchNumber_3_Array, 1, searchResult);
		for (int id = 0; id < 8; id++)
		{
			if (7 == searchNumber_3_Array[id])
			{
				searchNumber_3_Array[id] = 8;
				break;
			}
		}
		backtrack(searchNumber_3_Array, 1, searchResult);
    }
    else if (searchNumber == 4)
    {
        backtrack(searchNumber_4_Array, 1, searchResult);
		for (int id = 0; id < 8; id++)
		{
			if (7 == searchNumber_4_Array[id])
			{
				searchNumber_4_Array[id] = 8;
				break;
			}
		}
		backtrack(searchNumber_4_Array, 1, searchResult);
    }
    else
    {
        cout << "Please input an number 1 or 2 or 3 or 4" << endl;
    }

    for (int i = 0; i < result.size(); i++)
    {
        //cout << "Situdtion :" << i << endl;
        if (i != 0)
        {
            break;
        }
        //printVector(result[i]);
    }

}

vector<vector<TangramGraph>> Tangram::finalFunction()
{
    doit();
    vector<vector<TangramGraph>> finalResult;
    for (unsigned int i = 0; i < informationResult.size(); i++)
    {
        vector<TangramGraph> TG_V;
        TG_V = FinalDeal(informationResult[i]);
        finalResult.push_back(TG_V);
    }

    TCFS TCFS(tangramNumber);

    return finalResult;
}
