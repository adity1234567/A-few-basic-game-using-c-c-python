#include <iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
#include <cstdlib>
//#include<unistd.h>
#include<windows.h>
using namespace std;

void mine();
void random();
void die();
void gameOver();
void menu();
void town();
string user;
int gold,silver,money,hp,moral,supplies;
int main()
{
   gold=0,silver=0,money=0,hp=0,moral=0,supplies=0;

   system("cls");
   cout<<"-welcome to the Ermin Mines=\n -please select difficulty\n";
   cout<<"1.easy\n2.medium\n3.hard"<<endl;

   cin>>user;


   if(user=="1")
   {
       hp=10,moral=100,money=5,supplies=50;

   }
   if(user=="2")
   {
       hp=5,moral=50,money=2,supplies=25;
   }
   if(user=="3")
   {
       hp=3,moral=25,money=0,supplies=15;
   }

   while(user!="Q"||user!="q")
   {
       user="";
       menu();
   }
   return 0;
}
void menu()
{
    system("cls");
   cout<<"make a selection\n1.mine\n2.main menu\n3.town\n";
   cin>>user;

   if(user=="1")
   {
       mine();
   }
   if(user=="2")
   {
       main();
   }
   if(user=="3")
   {
       town();
   }
}
void town()
{
    system("cls");
    cout<<"you've made it to town"<<endl;cout<<endl;
    cout<<"Do you sell something press-1\nTo buy supplies press-2\nDo you want to return to the game press-3"<<endl;
    cout<<"Sell gold or silver? press 1 for gold and 2 for silver"<<endl;
    cout<<"You've--\n"<<gold<<" gold,and\n"<<silver<<" silver and\n"<<money<<" money and\n"<<supplies<<"supplies"<<endl;
    cin>>user;
    if(user=="1")
    {
        cin>>user;
        if(user=="1"&&gold>0)
        {
            cout<<"you've sold one gold"<<endl;
            gold--;
            money+=5;
        }
        if(user=="2"&&silver>0)
        {
            cout<<"you've sold one silver"<<endl;
            silver--;
            money+=3;
        }
    }
    if(user=="2"&&money>1)
    {
      supplies+=5;
      money--;
    }
    if(user=="3")
    {
        menu();
    }
}
void mine()
{
    system("cls");
    cout<<"Mining."<<endl;
    Sleep(1000);
    system("cls");
    cout<<"Mining.."<<endl;
    Sleep(1000);
    system("cls");
    cout<<"Mining..."<<endl;
    Sleep(1000);
    supplies--;
    random();
}
void random()
{
    int a;
   // cout<<a<<endl;
    for(int i=1;i<2;i++)
    {
        a=rand()%100;
        //cout<<a<<endl;
        if(a>0&&a<20)
        {
            cout<<"you've found gold!"<<endl;
            gold++;
        }
        if(a>19&&a<50)
        {
            cout<<"you've found silver!"<<endl;
            silver++;
        }
        if(a>50&&a<101)
        {
           cout<<"you've found nothing!"<<endl;
            //gold++;
        }
        if(a>79&&a<100)
        {
           // cout<<"you've died"<<endl;
           die();
        }

    }
    Sleep(1000);
}

void die()
{
    system("cls");
    cout<<"you've died"<<endl;
    gameOver();
}
void gameOver()
{
    system("cls");
    cout<<"-Game over"<<endl;
    Sleep(1000);
    system("cls");
    cout<<"-Game over"<<endl;
    Sleep(1000);
     system("cls");
    cout<<"-Game over"<<endl;
    Sleep(1000);
     system("cls");
    cout<<"-Game over"<<endl;
    Sleep(1000);
    main();
}
