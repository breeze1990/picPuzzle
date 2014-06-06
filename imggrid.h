#ifndef IMGGRID_H
#define IMGGRID_H

#include <QImage>
#include <QLabel>
#include <QPixmap>
#include "myutils.h"
#include "mylabel.h"

class ImgGrid
{
public:
    ImgGrid(QImage img);
    void shuffle();
    int &blkx();
    int &blky();

    static const int nrow = 3;
    static const int ncol = 3;
    static const int ntotal = nrow*ncol-1;
    QPixmap imgs;
    MyLabel *disps[ntotal+1];
    //int posx[ntotal+1],posy[ntotal+1];


};

#endif // IMGGRID_H
