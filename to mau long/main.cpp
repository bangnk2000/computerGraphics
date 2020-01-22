#include <graphics.h>

using namespace std;

void to_mau(int x, int y, int mau)
{
    if(getpixel(x,y)==BLACK)
    {
        putpixel(x,y,mau);
        to_mau(x+1,y,mau);
        to_mau(x,y+1,mau);
        to_mau(x-1,y,mau);
        to_mau(x,y-1,mau);
    }

}

int main()
{
    initwindow(720,720);
    rectangle(50,50,300,250);
    to_mau(100,100,BLUE);
    getch();
}
