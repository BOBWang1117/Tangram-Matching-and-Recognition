#ifndef TOOLS_H
#define TOOLS_H
#include "dividefigure.h"

class tools
{
private:
    vector<Point> input;

    void Find_LT_1_Position();

public:
    tools(vector<Point> input);

    ~tools();

    void doit();

};

#endif // TOOLS_H
