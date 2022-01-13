#include "mainscene.h"
#include <QApplication>
#include <qdir.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDir::setCurrent(a.applicationDirPath());
    MainScene w;
    w.show();

    return a.exec();
}
