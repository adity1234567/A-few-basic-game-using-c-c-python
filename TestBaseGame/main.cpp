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
string user;
int gold,silver,money,hp,moral,supplies;
int main()
{
   gold=0,silver=0,money=0,hp=0,moral=0,supplies=0;

   cout<<"-welcome to the Ermin Mines=\n -please select difficulty\n";
   cout<<"1.easy\n2.medium\n3.hard"<<endl;

   cin>>user;


   if(user=="1")
   {
       hp=10,moral=100,money=5;

   }
   if(user=="2")
   {
       hp=5,moral=50,money=2;
   }
   if(user=="3")
   {
       hp=3,moral=25,money=0;
   }

   while(user!="Q"||user!="q")
   {
       user="";
       menu();
   }
}
void menu()
{
   cout<<"make a selection\n1.mine\n2.main menu\n";
   cin>>user;

   if(user=="1")
   {
       mine();
   }
   if(user=="2")
   {
       main();
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
    random();
}
void random()
{
    int a;
   // cout<<a<<endl;
    for(int i=1;i<2;i++)
    {
        a=rand()%100;
        cout<<a<<endl;
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
