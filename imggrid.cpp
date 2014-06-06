#include "imggrid.h"

ImgGrid::ImgGrid(QImage img)
{
    int i,j,rsp,csp,cnt;
    MyLabel *tmp;

    rsp = img.height()/nrow;
    csp = img.width()/ncol;

    cnt = 0;
    for(i=0;i<nrow;i++)
        for(j=0;j<ncol;j++){
            imgs = QPixmap::fromImage(img.copy(j*csp,i*rsp,csp,rsp));
            disps[cnt]= new MyLabel();
            disps[cnt]->setPixmap(imgs);
            disps[cnt]->px=j;
            disps[cnt]->py=i;
            disps[cnt]->idx=cnt;
            //posx[cnt]=j;
            //posy[cnt]=i;
            cnt++;
        }

    int deleted=MyUtils::randInt(0,ntotal);

    tmp = disps[deleted];
    disps[deleted]=disps[ntotal];
    disps[ntotal] = tmp;
    disps[ntotal]->idx = ntotal;
    disps[deleted]->idx = deleted;

    shuffle();
    //posx[deleted]=posx[ntotal];
    //posy[deleted]=posy[ntotal];
    //posx[ntotal]=tx;
    //posy[ntotal]=ty;
}

void ImgGrid::shuffle()
{
    int i;
    for(i=0;i<10;i++){
        int t1,t2,tx,ty;
        t1 = MyUtils::randInt(0,ntotal-1);
        t2 = MyUtils::randInt(0,ntotal-1);
        tx = disps[t1]->px;
        ty = disps[t1]->py;
        disps[t1]->px = disps[t2]->px;
        disps[t1]->py = disps[t2]->py;
        disps[t2]->px = tx;
        disps[t2]->py = ty;
    }
}

int& ImgGrid::blkx(){
    return disps[ntotal]->px;
}
int& ImgGrid::blky(){
    return disps[ntotal]->py;
}

