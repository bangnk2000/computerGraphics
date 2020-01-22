#include <graphics.h>

using namespace std;

void bresenham(int xmin,int ymin,int xmax,int ymax,int xa, int ya, int xb, int yb)
{
    int dx=xb-xa;
    int dy=yb-ya;
    int p[4],q[4],t1=1,t2=0;
    p[0]=-dx; q[0]=xa-xmin;
    p[1]=dx; q[1]=xmax-xa;
    p[2]=-dy; q[2]=ya-ymin;
    p[3]=dy; q[3]=ymax-ya;
    for(int i=0; i<4; i++)
    {
        if(p[i]>0)
        {
            t1=min(q[i]/p[i],t1);
        }
        else
        {
            t2=max(q[i]/p[i],t2);
        }
    }
    if(t1>=t2)
    {
        xa=xa+t1*dx;
        ya=ya+t1*dy;
        xb=xa+t2*dx;
        yb=ya+t2*dy;
    }
    line(xa,ya,xb,yb);

}

int main()
{
    initwindow(640,480);
    rectangle(100,100,300,250);
    setcolor(4);
    line(100,50,400,300);
    getch();
    setcolor(0);
    line(100,50,400,300);
    setcolor(YELLOW);
    bresenham(100,100,300,250,100,50,400,300);
    getch();
}

