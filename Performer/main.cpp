#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
int windowWidth=1000;
int windowHeight=1000;
int halfWinHeight=windowHeight/2;
int haldWinWidth=windowWidth/2;

using namespace sf;
using namespace std;
class platformClass{
  public:
      float xvel,yvel,xpos,ypos;

      platformClass(float xpos,float ypos){
          xpos=xpos;
          ypos=ypos;
      }

};
class playerClass{
     public:
         bool playerFaceRight;
         bool onGround,playerUp,playerDown;
         float xvel,yvel,xpos,ypos;
         playerClass(){//constructor

         playerFaceRight=true;
         xvel=0,yvel=0;
         xpos=0,ypos=0;
         onGround=false;
         playerUp=false;
         playerDown=false;
          //cout<<"jdakfjac8cfhd8chd8"<<endl;

         }
         void update(bool playerUp,bool playerDown,bool playerRight,bool playerLeft){
              if(playerRight)
              {
                  playerFaceRight=true;
                  xvel=0.5;
              }

              if(playerLeft)
              {
                   playerFaceRight=false;
                  xvel=-0.5;
              }
              if(playerUp)
              {
                  yvel=-1;
              }
              if(playerDown)
              {
                  yvel=1;
              }
              if(!(playerRight||playerLeft))
              {
                  xvel=0;
              }

              if(onGround==true)
              {
                  yvel=0;
              }
              if(!onGround==false && playerUp==true)
              {
                  yvel=-0.25;
              }
              if(!onGround==false && playerDown==true)
              {
                  yvel+=0.25;
              }
              xpos+=xvel;
              ypos+=yvel;

              collide();
         }

         void collide(){

            if(xpos>500||xpos<0)
            {
                xvel=0;
            }
            if(ypos>500||ypos<0)
            {
              //  xvel=0;
                  onGround=true;
            }
            if(onGround==true&&playerUp==true)
            {
                onGround=false;
            }
            if(onGround==true&&playerDown==true)
            {
                onGround=false;
            }
         }

};
int main()
{
    // Create the main window
    RenderWindow app(VideoMode(windowWidth,windowHeight), "Platformer");

    bool playerUp,playerDown,playerLeft,playerRight=false;

    playerClass playerObject;

    Font xyzFont;
    xyzFont.loadFromFile("data/fonts/consola.ttf");

    Text helloText("Hello....Adity!!!!!!!!!....",xyzFont,50);
    Texture myNameTexture;
    myNameTexture.loadFromFile("data/images/myName.png");
    Sprite myNameSprite( myNameTexture);
	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == Event::Closed)
                app.close();
        }

        if(Keyboard::isKeyPressed(Keyboard::Right)) playerRight=true;
        if(Keyboard::isKeyPressed(Keyboard::Left)) playerLeft=true;
        if(Keyboard::isKeyPressed(Keyboard::Up)) playerUp=true;
        if(Keyboard::isKeyPressed(Keyboard::Down)) playerDown=true;
        if(!(Keyboard::isKeyPressed(Keyboard::Down))) playerDown=false;
        if(!(Keyboard::isKeyPressed(Keyboard::Up))) playerUp=false;
        if(!(Keyboard::isKeyPressed(Keyboard::Right))) playerRight=false;
        if(!(Keyboard::isKeyPressed(Keyboard::Left))) playerLeft=false;
        playerObject.update(playerUp,playerDown,playerRight,playerLeft);
        // Clear screen
        app.clear();

        app.draw(myNameSprite);
       // app.draw(helloText);

         myNameSprite.move(Vector2f(playerObject.xvel,playerObject.yvel));
        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
