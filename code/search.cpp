#include "search.h"
#include "ui_search.h"
#include <QDebug>
#include <QPainter>
#include <iostream>
#include <QFont>

using namespace std;
static vector<vector<TangramGraph>> result;
static bool change = false;

int Search::getFigure()
{
    int figureIndex = (ui->comboBox->currentIndex()) + 1;
    return figureIndex;
}

int Search::getMethod()
{
    int indexMethod = ui->comboBox_2->currentIndex();
    indexMethod++;

    return indexMethod;
}

void Search::paintTriangle(QPainter *painter, int ax, int ay, int bx, int by, int cx, int cy, int gid)
{
    static QPointF points[3] = {
          QPointF(ax,ay),
          QPointF(bx,by),
          QPointF(cx,cy)
      };
    painter->drawConvexPolygon(points, 3);
}

Search::Search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Search)
{
    vector<vector<TangramGraph>> temp;
    ui->setupUi(this);
    this->setFixedSize(800,600);
    setWindowIcon(QIcon("../../resource/tangram.jpg"));
    this->setWindowTitle("Tangram Search Algorithms");

    connect(ui->search, &QPushButton::clicked, [=]{
    //update();
    cout << "You choose figure " << getFigure()
             << ", " << getMethod() << " algorithm." << endl;
    i=0;
    step = 7;
    result.clear();
    cout << "size of result1: " << result.size() << endl;
    int fid = getFigure();
    int method = getMethod();
    result = process(fid,method);
    showText = 1;
    cout << "size of result2: " << result.size() << endl;
    update();
    //ui->search->hide();
    });

    connect(ui->nextSolution, &QPushButton::clicked, [=]{
        i++;
        step = 7;
        if(i>=result.size()){
            i=0;//result.size()-1;
        }
    update();
    });

    connect(ui->previousSolution, &QPushButton::clicked, [=]{
        i--;
        step = 7;
        if(i>=result.size()){
            i=0;
        }
    update();
    });

    connect(ui->step, &QPushButton::clicked, [=]{
        step++;
        if(step > 7){
            step = 1;
        }
        update();
    });
}

void Search::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    QPolygon LT1,LT2,MT, ST1,ST2,SQ,SA;

    pix.load("./resource/bg2.jpeg");
    painter.drawPixmap(0,0,this->width(),this->height(), pix);
    painter.translate(500,370);

    if(showText)
    {
        QFont font;
        font.setFamily("setFamily");
        font.setBold(true);

        string str = "Times New Roman";
        float size = 15;

        font.setPointSizeF(size);
        string text = "Number of goal states: " + to_string(i+1) + "/" + to_string(result.size());
        QString qtext = QString::fromStdString(text);

        painter.setFont(font);
        painter.drawText(QRect(-280,100,300, 80),qtext);
    }

    QBrush red(Qt::red);
    QBrush magenta(Qt::magenta);
    QBrush green(Qt::green);
    QBrush blue(Qt::blue);
    QBrush cyan(Qt::cyan);
    QBrush gray(Qt::gray);
    QBrush yellow(Qt::yellow);
    if(i < result.size()){
        int num = 0;
        for(int j=0;j<result[i].size();j++)
        {
            if(num == step){
                break;
            }

            int ax=-40*(result[i][j].point[0].first);
            int ay=-40*(result[i][j].point[0].second);
            int bx=-40*(result[i][j].point[1].first);
            int by=-40*(result[i][j].point[1].second);
            int cx=-40*(result[i][j].point[2].first);
            int cy=-40*(result[i][j].point[2].second);

            if(result[i][j].graphID==1){
                LT1.setPoints(3,ax,ay,bx,by,cx,cy);
                painter.setBrush(red);
                painter.drawPolygon(LT1);
                num++;
                continue;
            }
            else if(result[i][j].graphID==2){
                LT2.setPoints(3,ax,ay,bx,by,cx,cy);
                painter.setBrush(magenta);
                painter.drawPolygon(LT2);
                num++;
                continue;
            }
            else if(result[i][j].graphID==3){
                MT.setPoints(3,ax,ay,bx,by,cx,cy);
                painter.setBrush(green);
                painter.drawPolygon(MT);
                num++;
                continue;
            }
            else if(result[i][j].graphID==4){
                ST1.setPoints(3,ax,ay,bx,by,cx,cy);
                painter.setBrush(blue);
                painter.drawPolygon(ST1);
                num++;
                continue;
            }
            else if(result[i][j].graphID==5){
                ST2.setPoints(3,ax,ay,bx,by,cx,cy);
                painter.setBrush(cyan);
                painter.drawPolygon(ST2);
                num++;
                continue;
            }
            int dx=-40*(result[i][j].point[3].first);
            int dy=-40*(result[i][j].point[3].second);
            //cout << dx << "," << dy << endl;
            if(result[i][j].graphID==6){
                SQ.setPoints(4,ax,ay,bx,by,cx,cy,dx,dy);
                painter.setBrush(gray);
                painter.drawPolygon(SQ);
                num++;
                continue;
            }
            else if(result[i][j].graphID==7 || result[i][j].graphID == 8){
                SA.setPoints(4,ax,ay,bx,by,cx,cy,dx,dy);
                painter.setBrush(yellow);
                painter.drawPolygon(SA);
                num++;
            }
        }
    }

}

Search::~Search()
{
    delete ui;
}
