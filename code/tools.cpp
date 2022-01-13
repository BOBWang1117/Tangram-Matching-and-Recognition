#include "tools.h"

tools::tools(vector<Point> input)
{
    this->input = input;
}

tools::~tools()
{
    input.clear();
}

void Judge_LT_1_Can_Put_In_It(Point p)
{
//    if (p.up_right->up_right != nullptr && p.down_right->down_right != nullptr)
//    {
//        cout << "Yes" << endl;
//        cout << "coordinate: " << p.coordinate_X << " ," << p.coordinate_Y << endl;
//    }
}

void tools::Find_LT_1_Position()
{
    Judge_LT_1_Can_Put_In_It(input[0]);
}

void tools::doit()
{
    Find_LT_1_Position();
}
