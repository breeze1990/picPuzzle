#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    MyLabel();
    void mousePressEvent(QMouseEvent *ev);
    int idx,px,py;

signals:
    void lclicked(int,int,int);
};

#endif // MYLABEL_H
