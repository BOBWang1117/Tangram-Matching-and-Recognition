#ifndef PAINTERTANGRAM_H
#define PAINTERTANGRAM_H

#include <QMainWindow>
#include <QWidget>
class PainterTangram : public QMainWindow
{
    Q_OBJECT
public:
    explicit PainterTangram(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // PAINTERTANGRAM_H
