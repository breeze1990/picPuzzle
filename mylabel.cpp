#include "mylabel.h"
#include <iostream>

MyLabel::MyLabel()
{

}

void MyLabel::mousePressEvent(QMouseEvent *ev){
    this->QLabel::mousePressEvent(ev);
    //std::cout<<"c";
    emit lclicked(idx,px,py);
}
