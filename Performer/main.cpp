#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
int windowWidth=400;
int windowHeight=300;

using namespace sf;
using namespace std;

class playerClass{
     public:
         bool playerFaceRight;
         float xvel,yvel,xpos,ypos;
         playerClass(){//constructor

         playerFaceRight=true;
         xvel=0,yvel=0;
         xpos=0,ypos=0;
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

              xpos+=xvel;
              ypos+=yvel;

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
        app.draw(helloText);

         myNameSprite.move(Vector2f(playerObject.xvel,playerObject.yvel));
        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
