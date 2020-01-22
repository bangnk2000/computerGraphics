#include <graphics.h>
#include <math.h>

using namespace std;

typedef struct
{
    float x,y,z;
}diem3d;

typedef struct
{
    int x,y;
}diem2di;

typedef struct
{
    float x,y;
}diem2df;

typedef struct
{
    diem3d d1,d2;
}canh;

float R,PHI,TETA,D,tlx,tly;
int phepchieu;
diem2di o;
diem3d a[8];
canh c[12];

void chuyenhqs(diem3d m, diem3d &mv)
{
    mv.x=-m.x*sin(TETA)+m.y*cos(TETA);
    mv.y=-m.x*cos(TETA)*sin(PHI)-m.y*sin(TETA)*sin(PHI)+m.z*cos(PHI);
    mv.y=-m.x*cos(TETA)*sin(PHI)-m.y*sin(TETA)*sin(PHI)-m.z*sin(PHI)+R;
}

void chieu3d_2d(diem3d mv,  diem2df &mp)
{
    if(phepchieu == 1)
    {
        mp.x=D*mv.x/mv.z;
        mp.y=D*mv.y/mv.z;
    }else
    {
        mp.x=mv.x;
        mp.y=mv.y;
    }
}

void chuyenmh(diem2df mp, diem2di &mm)
{
    mm.x=(int)(tlx*mp.x+o.x+0.5);
    mm.y=(int)(tly*mp.y+o.y+0.5);
}

void chuyenden3d(diem3d m)
{
    diem3d mv; diem2df mp; diem2di mm;
    chuyenhqs(m, mv);
    chieu3d_2d(mv,mp);
    chuyenmh(mp,mm);
    moveto(mm.x,mm.y);
}

void veden3d(diem3d m)
{
    diem3d mv; diem2df mp; diem2di mm;
    chuyenhqs(m, mv);
    chieu3d_2d(mv,mp);
    chuyenmh(mp,mm);
    lineto(mm.x,mm.y);
}

void khoitao()
{
    R=5; PHI=30;TETA=30;D=3;tlx=150;tly=150;
    TETA=TETA*M_PI/180; PHI=PHI*M_PI/180;
    phepchieu=1;
    o.x=getmaxx()/2;
    o.y=getmaxx()/2;
}

void khoitaoLHP()
{
    a[0].x=1; a[0].y=0; a[0].z=1;
    a[1].x=0; a[1].y=0; a[1].z=1;
    a[2].x=0; a[2].y=1; a[2].z=1;
    a[3].x=1; a[3].y=1; a[3].z=1;
    a[4].x=1; a[4].y=1; a[4].z=0;
    a[5].x=1; a[5].y=0; a[5].z=0;
    a[6].x=0; a[6].y=0; a[6].z=0;
    a[7].x=0; a[7].y=1; a[7].z=0;

    c[0].d1=a[0]; c[0].d2=a[1];
    c[1].d1=a[1]; c[1].d2=a[2];
    c[2].d1=a[2]; c[2].d2=a[3];
    c[3].d1=a[3]; c[3].d2=a[0];
    c[4].d1=a[3]; c[4].d2=a[4];
    c[5].d1=a[2]; c[5].d2=a[7];
    c[6].d1=a[1]; c[6].d2=a[6];
    c[7].d1=a[0]; c[7].d2=a[5];
    c[8].d1=a[5]; c[8].d2=a[6];
    c[9].d1=a[5]; c[9].d2=a[4];
    c[10].d1=a[4]; c[10].d2=a[7];
    c[11].d1=a[7]; c[11].d2=a[6];
}

void veHLP()
{
    for(int i=0; i<12; i++)
    {
        chuyenden3d(c[i].d1);
        veden3d(c[i].d2);
    }
}


int main()
{
    int gd=0,gm;
    initgraph(&gd, &gm,"");
    khoitao();
    khoitaoLHP();
    veHLP();
    getch();
    closegraph();
    return 0;
}
