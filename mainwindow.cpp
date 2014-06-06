#include "mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    this->setGeometry(300,50,200,200);
    mainLayout = new QVBoxLayout();
    imLayout = new QGridLayout();

    dispWindow = new QLabel("asdfs");

    imsrc = new QImage("C:\\Users\\invisibili\\Pictures\\me.jpg","jpg");
    imrect = new QImage(imsrc->scaled(600,600));


    imfrac = new ImgGrid(*imrect);

    int i;
    for(i=0;i<imfrac->ntotal;i++)
        connect(imfrac->disps[i],SIGNAL(lclicked(int,int,int)),this,SLOT(updateGrid(int,int,int)));
    createLayout();

}

void MainWindow::updateGrid(int idx,int px,int py){
    if (abs(imfrac->blkx()-px)+abs(imfrac->blky()-py)!=1) return;
    //neighbor to the blank, switch the image block
    int tx,ty;
    tx = imfrac->disps[idx]->px;
    ty = imfrac->disps[idx]->py;
    imfrac->disps[idx]->px = imfrac->blkx();
    imfrac->disps[idx]->py = imfrac->blky();
    imfrac->blkx() = tx;
    imfrac->blky() = ty;


    mainLayout->removeItem(imLayout);
    delete imLayout;
    imLayout = new QGridLayout();
    createLayout();
}

void MainWindow::createLayout(){
    int i,tx,ty;

    for(i=0;i<imfrac->ntotal;i++){
        tx=imfrac->disps[i]->px;
        ty=imfrac->disps[i]->py;
        imLayout->addWidget(imfrac->disps[i],ty,tx);
    }
    mainLayout->addLayout(imLayout);
    this->setLayout(mainLayout);

}
MainWindow::~MainWindow()
{

}
