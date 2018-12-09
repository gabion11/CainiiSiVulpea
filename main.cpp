#include <iostream>
#include <graphics.h>
#include <winbgim.h>

using namespace std;
int MatriceTabla[8][8];
void DisplayCharacters(int stanga, int sus, int latura)
{
    for (int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(MatriceTabla[i][j] == 1)
            {
                 readimagefile("Fox1.gif",stanga + latura*j,sus + latura*i,(stanga + latura) + latura*j, (sus + latura) + latura*i);
            }

            else
            {
                if(MatriceTabla[i][j] == 2)
                {
                    readimagefile("Dog4.gif",stanga + latura*j,sus + latura*i,(stanga + latura) + latura*j, (sus + latura) + latura*i);
                }
            }
        }
    }

}

void meniu()
{
    char sir[30];
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

int numar, width, height, latura, sus, stanga;

void DesenCaine(int x, int y, int z, int w)
{
    setcolor(LIGHTRED);
    setfillstyle(SOLID_FILL, LIGHTRED);
    fillellipse(x, y, z, w);
}

void TablaDeJoc()
{
    int i, j, x, a, b, c, d;
    numar = 8;
    width = 560;
    height = 560;
    latura = width/numar; //70
    sus = (getmaxy()-width) / 2; //19
    stanga = (getmaxx()-height) / 2; //119
    setbkcolor(RED);
    clearviewport();
    setcolor(0);
    for(i=1; i<=numar; i++)
    {
        x++;
        for(j=1; j<=numar; j++)
        {
            if(x%2==0)
            {
                setcolor(0);
                setfillstyle(SOLID_FILL, 0);
            }
            else
            {
                setcolor(15);
                setfillstyle(SOLID_FILL, 15);
            }
            bar(stanga + latura*(i-1), sus + latura*(j-1), stanga + latura*(i-1) + latura, sus + latura*(j-1) + latura);

            x++;
        }
    }
    //DesenCaine(151, 547, 18, 18);
    //DesenCaine(295, 547, 18, 18);
    //DesenCaine(435, 547, 18, 18);
    //DesenCaine(576, 547, 18, 18);
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    bar(341, 30, 386, 75);
    MatriceTabla[0][3]=1;
    MatriceTabla[7][0]=2;
    MatriceTabla[7][2]=2;
    MatriceTabla[7][4]=2;
    MatriceTabla[7][6]=2;
    MatriceTabla[6][2]=3;
    DisplayCharacters(stanga, sus, latura);

}

int main()
{
    initwindow(800,600);
    meniu();
    //TablaDeJoc();
    int linia, coloana, x, y;
    int x1, y1, x2, y2;
    int xmijloc, ymijloc;
    int m=0;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
            if(x>220 && x<600 && y>245 && y<275)  // Daca se da click pe Jucator vs Jucator
            {
                TablaDeJoc();
            }
        }
    }
    while(m==0);

    getch();
    closegraph();
    return 0;
}
