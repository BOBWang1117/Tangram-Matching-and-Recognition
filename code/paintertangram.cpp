#include "paintertangram.h"
#include <QPainter>

PainterTangram::PainterTangram(QWidget *parent) : QMainWindow(parent)
{

}

void PainterTangram::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.translate(5,5);
    painter.setPen(QColor(255,0,0));
    painter.drawLine(0,0,190,0);
    painter.drawLine(0,0,10,10);

    painter.drawLine(10,10,20,20);
    painter.drawLine(10,10,0,0);

    painter.drawLine(20,20,30,30);
    painter.drawLine(20,20,10,10);
    painter.drawLine(20,20,30,10);
}

