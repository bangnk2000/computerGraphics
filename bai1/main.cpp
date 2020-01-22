#include <iostream>
#include <graphics.h>

using namespace std;

void TH3(int x1, int y1, int x2, int y2)
{
    //b1:
    if(x1>x2)
    {
        int tg=x1;
        x1=x2;
        x2=tg;
        tg=y1;
        y1=y2;
        y2=tg;
    }
    //b2
    int Dy=(y2-y1);
    int Dx=(x2-x1);
    int const1= 2*Dy;
    int const2= 2*(Dy-Dx);
    //b3
    int x=x1, y=y1;
    int p=2*Dy-Dx;
    do
    {
        putpixel(x,y,15);
        if(p<0)
        {
            p+=const1;
        }
        else
        {
            p+=const2;
            x++;
        }
        y++;
    }
    while(x<x2);
}

void TH4(int x1, int y1, int x2, int y2)
{
    //b1:
    if(x1>x2)
    {
        swap(x1,x2);
        swap(y1,y2);
    }
    //b2
    int Dy=(y1-y2);
    int Dx=(x2-x1);
    int const1= 2*Dy;
    int const2= 2*(Dy-Dx);
    //b3
    int x=x1, y=y1;
    int p=2*Dy-Dx;
    do
    {
        putpixel(x,y,15);
        if(p<0)
        {
            p+=const1;
        }
        else
        {
            p+=const2;
            x--;
        }
        y++;
    }
    while(x<x2);
}

/*void bresenham(int x1, int x2, int y1, int y2)
{
    if(x1>x2)
    {
        int tg=x1;
        x1=x2;
        x2=tg;
    }
    int Dy=(y2-y1);
    int Dx=(x2-x1);
    int p=2*Dy-Dx;
    int const1= 2*Dy;
    int const2= 2*(Dy-Dx);
    int x=x1,y=y1;
    putpixel(x,y,15);
    while(x<x2)
    {
        if(p<0)
        {
            p+=const1;
        }
        else
        {
            p+=const2;
            y++;
        }
        x++;
        putpixel(x,y,15);
    }
}*/

int main()
{
    initwindow(640,480);
    TH3(50,50,300,300);
    TH4(50,100,300,50);
    getch();
    closegraph();
    return 0;
}
