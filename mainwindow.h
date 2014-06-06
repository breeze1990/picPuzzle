#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include "mylabel.h"
#include "imggrid.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void createLayout();
    ~MainWindow();

    QVBoxLayout *mainLayout;
    QGridLayout *imLayout;

    QLabel *dispWindow;
    QPixmap *img;
    QImage *imsrc,*imrect;
    ImgGrid *imfrac;
private:

public slots:
    void updateGrid(int idx, int px, int py);
};

#endif // MAINWINDOW_H
