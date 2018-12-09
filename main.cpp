#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <stdlib.h>
using namespace std;
int numar,width,height,latura,sus,stanga;
double TablaDeJoc[1000][1000],TablaPoziti[20][20];
void PunerePiese();
void DesenCaine(int x,int y,int z,int w);
void AfisareMutari()

{
int x1, y1, x2, y2;
int xmijloc, ymijloc;
int linia,coloana,x,y;

int ok;setcolor(RED); setfillstyle(SOLID_FILL,RED);
ok=0;
while(ok==0)
{


if(ismouseclick(WM_LBUTTONDOWN))
{
clearmouseclick(WM_LBUTTONDOWN);
x=mousex();
y=mousey();


linia=(y-sus)/latura+1;
coloana=(x-stanga)/latura+1;

PunerePiese();
x1=stanga+latura*(coloana-1); y1=sus+latura*(linia-1);
x2=x1+latura; y2=y1+latura;
xmijloc=(x1+x2)/2; ymijloc=(y1+y2)/2;
setlinestyle(SOLID_LINE,2,8);
if(TablaDeJoc[linia][coloana]==1)
    if(linia!=1)
{       if(coloana==1)
             line(xmijloc,ymijloc,xmijloc+50,ymijloc-50);
        else if(coloana==8)
                line(xmijloc,ymijloc,xmijloc-50,ymijloc-50);
            else
                {
                  line(xmijloc,ymijloc,xmijloc-50,ymijloc-50);
                  line(xmijloc,ymijloc,xmijloc+50,ymijloc-50);
            }

}
if(TablaDeJoc[linia][coloana]==2)
{
    if(linia==1)
        if(coloana==8)
             line(xmijloc,ymijloc,xmijloc-50,ymijloc+50);
          else if(coloana==1)
                 line(xmijloc,ymijloc,xmijloc+50,ymijloc+50);
                 else
                 {line(xmijloc,ymijloc,xmijloc-50,ymijloc+50);
                  line(xmijloc,ymijloc,xmijloc+50,ymijloc+50);
                 }
   else if(linia==8)
            if(coloana==8)
               line(xmijloc,ymijloc,xmijloc-50,ymijloc-50);
              else if(coloana==1)
                    line(xmijloc,ymijloc,xmijloc+50,ymijloc-50);
                     else
                        {line(xmijloc,ymijloc,xmijloc+50,ymijloc-50);
                         line(xmijloc,ymijloc,xmijloc-50,ymijloc-50);
                        }
                 else {  line(xmijloc,ymijloc,xmijloc+50,ymijloc-50);
                         line(xmijloc,ymijloc,xmijloc-50,ymijloc-50);
                         line(xmijloc,ymijloc,xmijloc+50,ymijloc+50);
                         line(xmijloc,ymijloc,xmijloc-50,ymijloc+50);}
}
}

}
}

void meniu()
{char sir[30];
bar(290,80,510,155);
strcpy(sir,"MENIU");
setcolor(RED);
settextstyle(8,HORIZ_DIR,18);
outtextxy(300,85,sir);
settextstyle(9,HORIZ_DIR,13);
strcpy(sir,"CALCULATOR VS JUCATOR");
outtextxy(200,185,sir);
strcpy(sir,"JUCATOR VS JUCATOR");
outtextxy(230,255,sir);
strcpy(sir,"CUM TE JOCI?");
outtextxy(300,325,sir);
strcpy(sir,"SETARI");
outtextxy(350,395,sir);

}

void DesenCaine(int x,int y,int z,int w)
{
   setcolor(LIGHTRED); setfillstyle(SOLID_FILL,LIGHTRED);
fillellipse(x,y,z,w);
}
void Tabla()
{
int i,j,x,a,b,c,d;
numar=8;
width=560;
height=560;
latura=width/numar;
sus=(getmaxy()-width)/2;
stanga=(getmaxx()-height)/2;
setbkcolor(BLUE); clearviewport(); setcolor(0);
for(i=1;i<=8;i++)
    for(j=1;j<=8;j++) if(i==1||j==8||j==1||i==8) TablaPoziti[i][j]=-1;




for(i=1; i<=numar; i++)
{x++;for(j=1; j<=numar; j++)

{if (x%2==0){setcolor(0);setfillstyle(SOLID_FILL,0);}
else {setcolor(15);setfillstyle(SOLID_FILL,15);}
    bar(stanga+latura*(i-1),sus+latura*(j-1),stanga+latura*(i-1)+latura,sus+latura*(j-1)+latura);x++;

}}
TablaDeJoc[8][1]=1;
TablaDeJoc[8][3]=1;
TablaDeJoc[8][5]=1;
TablaDeJoc[8][7]=1;


TablaDeJoc[1][4]=2;
PunerePiese();
AfisareMutari();
}

void PunerePiese()
{
int i,j;
int x1, y1, x2, y2;
int xmijloc, ymijloc;
int linia,coloana,x,y;

numar=8;
width=560;
height=560;
latura=width/numar;
sus=(getmaxy()-width)/2;
stanga=(getmaxx()-height)/2;

for(i=1; i<=numar; i++)
{x++;for(j=1; j<=numar; j++)

{if (x%2==0){setcolor(0);setfillstyle(SOLID_FILL,0);}
else {setcolor(15);setfillstyle(SOLID_FILL,15);}
    bar(stanga+latura*(i-1),sus+latura*(j-1),stanga+latura*(i-1)+latura,sus+latura*(j-1)+latura);x++;
}}

for(linia=1; linia<=8; linia++)
     for(coloana=1;coloana <=8; coloana++)
        if( TablaDeJoc[linia][coloana]==1)
         {x1=stanga+latura*(coloana-1); y1=sus+latura*(linia-1);
          x2=x1+latura; y2=y1+latura;
          xmijloc=(x1+x2)/2; ymijloc=(y1+y2)/2;
          DesenCaine(xmijloc,ymijloc,18,18); }
          else if(TablaDeJoc[linia][coloana]==2)
          {
              x1=stanga+latura*(coloana-1); y1=sus+latura*(linia-1);
              x2=x1+latura; y2=y1+latura;
              xmijloc=(x1+x2)/2; ymijloc=(y1+y2)/2;
              setcolor(RED); setfillstyle(SOLID_FILL,RED);
              bar(xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
          }
}

int main()
{initwindow(800,600);
meniu();
int a,b;
int m=0;
do
{if(ismouseclick(WM_LBUTTONDOWN))
{
clearmouseclick(WM_LBUTTONDOWN);
a=mousex();
b=mousey();
if(a>220&&a<600&&b>245&&b<275)
    Tabla();
    else
    {

    }
}}
while(m==0);

  getch();
  closegraph();
  return 0;
}
