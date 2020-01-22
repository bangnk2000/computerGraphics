#include <graphics.h>

using namespace std;

void goc2(int a, int b, int r)
{
    int p = 1-r;
    int x=0,y=r;
    while(x<y)
    {
        if(p<0)
        {
            p=p+2*x+3;
        }
        else
        {
            p=p+2*(x-y)+5;
            y--;
        }
        x++;
        putpixel(-x+a, y+b, 15);
        putpixel(-y+a, x+b, 15);
        putpixel(y+a, x+b, 15);
        putpixel(x+a, y+b, 15);
        putpixel(-x+a, -y+b, 15);
        putpixel(-y+a, -x+b, 15);
        putpixel(x+a, -y+b, 15);
        putpixel(y+a,- x+b, 15);
    }
}

int main()
{
    initwindow(640,600);
    goc2(250,250,250);
    getch();
    return 0;
}
