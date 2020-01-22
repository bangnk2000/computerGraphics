#include <graphics.h>

using namespace std;

void macode(int xmin,int ymin,int xmax,int ymax,int x, int y, int b[], int &b10)
{
    for(int i=0; i<4; i++)
    b[i]=0;
    if(x<xmin) b[0]=1;
    if(x>xmax) b[1]=1;
    if(y<ymin) b[2]=1;
    if(y>ymax) b[3]=1;
    b10 = 8*b[3]+4*b[2]+2*b[1]+b[0];
}
void cohen(int xmin,int ymin,int xmax,int ymax,int xa, int ya, int xb, int yb)
{
    bool kt=false;
    int a[4],b[4];
    int A10,B10;
    while(!kt)
    {
        macode(xmin,ymin,xmax,ymax,xa,ya,a,A10);
        macode(xmin,ymin,xmax,ymax,xb,yb,b,B10);
        if(A10==0&&B10==0)
        {
            line(xa,ya,xb,yb);
            kt=true;
        }else if((A10&B10)!=0)
        {
            kt=true;
        }else
        {
            if(A10==0)
            {
                swap(xa,xb);
                swap(ya,yb);
                macode(xmin,ymin,xmax,ymax,xa,ya,a,A10);
            }
            float m=(float)(yb-ya)/(xb-xa);
            if(a[0]==1)
            {
                ya=ya+m*(xmin-xa);
                xa=xmin;
            }
            if(a[1]==1)
            {
                ya=ya+m*(xmax-xa);
                xa=xmax;
            }
            if(a[2]==1)
            {
                xa=xa+(1/m)*(ymin-ya);
                ya=ymin;
            }
            if(a[3]==1)
            {
                xa=xa+(1/m)*(ymax-ya);
                ya=ymax;
            }
        }
    }
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
    cohen(100,100,300,250,100,50,400,300);
    getch();
}
