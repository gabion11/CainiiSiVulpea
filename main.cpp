#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <stdlib.h>
using namespace std;
int numar,width,height,latura,sus,stanga;
double TablaDeJoc[1000][1000];
void DisplayCharacters()
{
    for (int i=1; i<=8; i++)

        for(int j=1; j<=8; j++)

            if(TablaDeJoc[i][j] == 2)

                 readimagefile("Fox1.gif",stanga + latura*(j-1),sus + latura*(i-1),(stanga + latura) + latura*(j-1), (sus + latura) + latura*(i-1));

             else

                if(TablaDeJoc[i][j] == 1)

                    readimagefile("Dog4.gif",stanga + latura*(j-1),sus + latura*(i-1),(stanga + latura) + latura*(j-1), (sus + latura) + latura*(i-1));




}


void AfisareMutari(int linia,int coloana) //sagetutele
{
int x1, y1, x2, y2;
int xmijloc, ymijloc;
int x,y;


setcolor(RED);
setfillstyle(SOLID_FILL,RED);




x1=stanga+latura*(coloana-1);
y1=sus+latura*(linia-1);
x2=x1+latura;
y2=y1+latura;
xmijloc=(x1+x2)/2;
ymijloc=(y1+y2)/2;
setlinestyle(SOLID_LINE,2,8);
if(TablaDeJoc[linia][coloana]==1)
if(linia!=1)
       if(coloana==1)
         {

        if(TablaDeJoc[linia-1][coloana+1]!=1&&TablaDeJoc[linia-1][coloana+1]!=2) line(xmijloc,ymijloc,xmijloc+50,ymijloc-50);}
        else if(coloana==8)
           {

            if(TablaDeJoc[linia-1][coloana-1]!=1&&TablaDeJoc[linia-1][coloana-1]!=2)
                line(xmijloc,ymijloc,xmijloc-50,ymijloc-50);}
            else
            {    if(TablaDeJoc[linia-1][coloana-1]!=1&&TablaDeJoc[linia-1][coloana-1]!=2)
                  line(xmijloc,ymijloc,xmijloc-50,ymijloc-50);
                 if(TablaDeJoc[linia-1][coloana+1]!=1&&TablaDeJoc[linia-1][coloana+1]!=2)
                  line(xmijloc,ymijloc,xmijloc+50,ymijloc-50);
            }


if(TablaDeJoc[linia][coloana]==2)
{
    int a,b;
     a=linia;b=coloana;
    if(a-1>=1&&b-1>=1&&TablaDeJoc[a-1][b-1]==0)line(xmijloc,ymijloc,xmijloc-50,ymijloc-50);
    if(a-1>=1&&b+1<=8&&TablaDeJoc[a-1][b+1]==0)line(xmijloc,ymijloc,xmijloc+50,ymijloc-50);
    if(a+1<=8&&b-1>=1&&TablaDeJoc[a+1][b-1]==0)line(xmijloc,ymijloc,xmijloc-50,ymijloc+50);
    if(a+1<=8&&b+1<=8&&TablaDeJoc[a+1][b+1]==0)line(xmijloc,ymijloc,xmijloc+50,ymijloc+50);

}
DisplayCharacters();
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


void Tabla()
{
int i,j,x,a,b,c,d;
numar=8;
width=560;
height=560;
latura=width/numar;
sus=(getmaxy()-width)/2;
stanga=(getmaxx()-height)/2;
setbkcolor(RED);
clearviewport();
setcolor(0);

for(i=1; i<=numar; i++)
{
    x++;for(j=1; j<=numar; j++)

    {
    if (x%2==0)
    {
            setcolor(0);setfillstyle(SOLID_FILL,0);
    }
    else
    {
            setcolor(15);setfillstyle(SOLID_FILL,15);
    }
    bar(stanga+latura*(i-1),sus+latura*(j-1),stanga+latura*(i-1)+latura,sus+latura*(j-1)+latura);
    x++;

    }
}
TablaDeJoc[8][1]=1;
TablaDeJoc[8][3]=1;
TablaDeJoc[8][5]=1;
TablaDeJoc[8][7]=1;
TablaDeJoc[1][4]=2;
DisplayCharacters();

}

void PunerePiese()
{
int i,j;
int x1, y1, x2, y2;
int xmijloc, ymijloc;
int linia,coloana,x=0,y;

numar=8;
width=560;
height=560;
latura=width/numar;
sus=(getmaxy()-width)/2;
stanga=(getmaxx()-height)/2;

for(i=1; i<=numar; i++)
{
    x++;for(j=1; j<=numar; j++)

{
    if (x%2==0)
    {
        setcolor(0);setfillstyle(SOLID_FILL,0);
    }
    else
    {
        setcolor(15);setfillstyle(SOLID_FILL,15);
    }
    bar(stanga+latura*(i-1),sus+latura*(j-1),stanga+latura*(i-1)+latura,sus+latura*(j-1)+latura);
    x++;
}
}
DisplayCharacters();
}
bool CainiAuCastigat()
{
    int a,b,i,j;

    for(i=1;i<=8;i++)
        for(j=1;j<=8;j++)
        if(TablaDeJoc[i][j]==2){a=i;b=j;}

     int nr=0;

    if(a-1>=1&&b-1>=1&&TablaDeJoc[a-1][b-1]==0)nr++;
    if(a-1>=1&&b+1<=8&&TablaDeJoc[a-1][b+1]==0)nr++;
    if(a+1<=8&&b-1>=1&&TablaDeJoc[a+1][b-1]==0)nr++;
    if(a+1<=8&&b+1<=8&&TablaDeJoc[a+1][b+1]==0)nr++;

   if(nr==0)
           return true;
       else return false;

}
bool VulpeaACastigat()
{
     int a,b,i,j;

    for(i=1;i<=8;i++)
        for(j=1;j<=8;j++)
        if(TablaDeJoc[i][j]==2){a=i;b=j;}
    if(a==8) return true;
    else if(TablaDeJoc[1][2]==1&&TablaDeJoc[1][4]==1&&TablaDeJoc[1][6]==1&&TablaDeJoc[1][8]==1)
            return true;
    else return false;
}
void JucatorVsJucator()
{
int x1, y1, x2, y2;
int xmijloc, ymijloc;
int linia,coloana,x,y,linia1,coloana1;
int nr=0,ok,gata=1;
Tabla();
    while(gata)
    {

        while(nr%2==0)
       {

       if(ismouseclick(WM_LBUTTONDOWN))
            {ok=1;
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            linia=(y-sus)/latura+1;
            coloana=(x-stanga)/latura+1;

            if(TablaDeJoc[linia][coloana]==1)
                 {

                  AfisareMutari(linia,coloana);
                  while(ok==1)



                    if(ismouseclick(WM_LBUTTONDOWN))
                   {
                      clearmouseclick(WM_LBUTTONDOWN);
                      x=mousex();
                      y=mousey();
                      linia1=(y-sus)/latura+1;
                      coloana1=(x-stanga)/latura+1;

                      if(((coloana1==coloana+1&&linia1==linia-1)||(coloana1==coloana-1&&linia1==linia-1))&&TablaDeJoc[linia1][coloana1]==0)
                        {
                         TablaDeJoc[linia][coloana]=0;
                         TablaDeJoc[linia1][coloana1]=1;
                         nr++;

                        }
                        ok=0;


                   }
            PunerePiese();
            }
            }

       }

if(CainiAuCastigat()){gata=0;cout<<"caini au castigat:";}
     else
        if(VulpeaACastigat()){gata=0;cout<<"Vulpea a castigat";}
           else
           {
            ok=1;
            while(nr%2==1)

            if(ismouseclick(WM_LBUTTONDOWN))
            {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            linia=(y-sus)/latura+1;
            coloana=(x-stanga)/latura+1;
            if(TablaDeJoc[linia][coloana]==2)
             {
                 AfisareMutari(linia,coloana);

              while(ok==1)
               if(ismouseclick(WM_LBUTTONDOWN))
                   {
                      clearmouseclick(WM_LBUTTONDOWN);
                      x=mousex();
                      y=mousey();
                      linia1=(y-sus)/latura+1;
                      coloana1=(x-stanga)/latura+1;
                    if(((coloana1==coloana+1&&linia1==linia+1)||(coloana1==coloana+1&&linia1==linia-1)||(coloana1==coloana-1&&linia1==linia+1)||(coloana1==coloana-1&&linia1==linia-1))&&TablaDeJoc[linia1][coloana1]==0)
                      {
                          TablaDeJoc[linia][coloana]=0;
                          TablaDeJoc[linia1][coloana1]=2;
                          nr++;
                          ok=0;
                      }

                   }
            PunerePiese();
              }

              }
              if(VulpeaACastigat()){gata=0;cout<<"Vulpea a castigat";}
    }}
}


int main()
{
initwindow(800,600);
meniu();
int a,b;
int m=0;
do
{
    if(ismouseclick(WM_LBUTTONDOWN))
{
clearmouseclick(WM_LBUTTONDOWN);
a=mousex();
b=mousey();
if(a>220&&a<600&&b>245&&b<275)
    JucatorVsJucator();
    else
    {

    }
}}
while(m==0);

  getch();
  closegraph();
  return 0;
}
