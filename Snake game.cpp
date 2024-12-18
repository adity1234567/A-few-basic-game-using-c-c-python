#include<bits/stdc++.h>
#include<conio.h>
#include <windows.h>
using namespace std;

bool gameOver;
const int width=20;
const int height=20;
int x,y,fruitX,fruitY,score;
int tailX[100],tailY[100],nTail;
///for snake direction
enum eDirection{ STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
void setUp()
{
    gameOver=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    fruitX=rand()%width;
    fruitY=rand()%height;
    score=0;
}
void Draw()
{
    system("cls");
    for(int i=0;i<width+1;i++)
    {
        cout<<"#";
    }
    cout<<endl;
     for(int i=0;i<height;i++)
     {
         for(int j=0;j<width;j++)
         {
             if(j==0)
             {
                 cout<<"#";
             }

             if(i==y && j==x)
             {
                 cout<<"0";
             }
             else if(i==fruitY&&j==fruitX)
             {
                 cout<<"F";
             }
             else
             {
                 bool print=false;
                 for(int k=0;k<nTail;k++)
                 {

                     if(tailX[k]==j&&tailY[k]==i)
                     {
                         cout<<"o";
                         print=true;
                     }

                 }
                   if(print==false)
                     {
                          cout<<" ";
                     }

             }


             if(j==width-1)
             {
                 cout<<"#";
             }
         }
         cout<<endl;
     }
     for(int i=0;i<width+1;i++)
     {
        cout<<"#";
     }
     cout<<endl;
     cout<<"score: "<<score<<endl;
}
void input()
{
    if(_kbhit())//is keyboard typed??
    {
       switch(_getch())
       {
        case 'f':
            dir=LEFT;
            break;
        case 'j':
            dir=RIGHT;
            break;
        case 'y':
            dir=UP;
            break;
        case 'b':
            dir=DOWN;
            break;
        case 'x':
            gameOver=true;
            break;
       }
    }

}
void logic()
{
    int prevX=tailX[0];
    int prevY=tailY[0];
    tailX[0]=x;
    tailY[0]=y;
    int prev2X,prev2Y;

    for(int i=1;i<nTail;i++)
    {
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;

    }
    switch(dir)
    {
       case LEFT:
          x--;
          break;
       case RIGHT:
          x++;
          break;
        case UP:
          y--;
          break;
        case DOWN:
          y++;
          break;
        default:
            break;
    }
     if(x>width||x<0||y>height||y<0)
    {
        gameOver=true;
    }
    if(x==fruitX&&y==fruitY)
    {
        score+=10;
        fruitX=rand()%width;
        fruitY=rand()%height;
        nTail++;
    }
}
int main()
{
 setUp();
 while(!gameOver)
 {
     Draw();
     input();
     logic();
     Sleep(100);
 }
}
