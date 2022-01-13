#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include <QDebug>

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //set main scene
    //set fixed size
    this->setFixedSize(800,600);

    //set icon
    setWindowIcon(QIcon("/resource/tangram.jpg"));

    setWindowTitle("A Pattern Matching and Recognition System");

    connect(ui->actionQuit,&QAction::triggered,[=](){
        this->close();
    });

    ui->startButton->move(this->width() * 0.5 - ui->startButton->width() * 0.5, this->height() * 0.3);

    search = new Search;
    connect(ui->startButton,&QPushButton::clicked, [=](){
        this->hide();
        search->show();
    });
}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("./resource/bg1.jpeg");
    painter.drawPixmap(0,0,this->width(),this->height(), pix);

    //draw sloggan
    pix.load("./resource/title.png");
    pix = pix.scaled(pix.width()*0.5, pix.height()*0.5);
    painter.drawPixmap(136,30,pix);
}

MainScene::~MainScene()
{
    delete ui;
}
