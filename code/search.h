#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include <QPainter>
#include <QScrollArea>
#include "mainfunction.h"
//#include <QLayout>

using namespace std;

namespace Ui {
class Search;
}

class Search : public QWidget
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = nullptr);
    ~Search();

    int getMethod();
    int getFigure();
    void paintEvent(QPaintEvent *);
    //bool eventFilter(QObject *obj, QEvent *event);
    void magicTime();
    void paintTangram(vector<Point> result);
    void paintTriangle(QPainter *painter, int ax, int ay, int bx, int by, int cx, int cy, int gid);
    int i = 0;
    int step = 0;
    int showText = 0;
    //void paintTangram(QPaintEvent *);

private:
    Ui::Search *ui;
    //QScrollArea *s;
    //QWidget *w ;
    //PainterTangram *drawWidget;
    //QHBoxLayout *topLayout;// = new QHBoxLayout;
    //QLabel *    label;
};

#endif // SEARCH_H
