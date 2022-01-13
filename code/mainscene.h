#ifndef MAINSCENE_H
#define MAINSCENE_H
//#include "searchscene.h"
#include "search.h"
#include <QMainWindow>
#include "mainfunction.h"

namespace Ui {
class MainScene;
}

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = nullptr);
    ~MainScene();

    //bg pic
    void paintEvent(QPaintEvent *);

    //SearchScene * searchScene = NULL;
    Search * search = NULL;

private:
    Ui::MainScene *ui;
};

#endif // MAINSCENE_H
