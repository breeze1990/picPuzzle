#include "mainwindow.h"
#include <QApplication>
#include <QTime>
#include <qglobal.h>

int main(int argc, char *argv[])
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    QApplication a(argc, argv);
    MainWindow *w;
    w=new MainWindow();


    w->show();
    return a.exec();
}
