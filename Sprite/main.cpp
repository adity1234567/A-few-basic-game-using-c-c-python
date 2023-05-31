#include <SFML/Graphics.hpp>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
using namespace sf;

int winWidth=1000;
int winHeight=700;

int main()
{
    float x=0,y=0,xPos=0,yPos=0;
    int w=50,h=50;
    int zoomScale=7;
    // Create the main window
    RenderWindow app(VideoMode(winWidth,winHeight), "Sprite");

    Texture texture;
    texture.loadFromFile("data/images/spritesheet1.png");
    Sprite spriteSheet(texture);
    spriteSheet.scale(zoomScale,zoomScale);

    Clock gameClock;

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

        float fps=gameClock.restart().asMilliseconds();

        if(Keyboard::isKeyPressed(Keyboard::Z))
        {
            zoomScale++;
            spriteSheet.scale(zoomScale,zoomScale);
        }
        if(Keyboard::isKeyPressed(Keyboard::X))
        {
            zoomScale--;
            spriteSheet.scale(zoomScale,zoomScale);
        }
     if(Keyboard::isKeyPressed(Keyboard::LShift))
      {
        if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            y=0.25;
        }
        if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            y=0.55;
        }
        if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            x=-0.25;
        }
        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            x=0.25;
        }
      }
      else{
        if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            y=-1;
        }
        if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            y=1;
        }
        if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            x=-1;
        }
        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            x=1;
        }
      }
        if(!(Keyboard::isKeyPressed(Keyboard::Up))&&!(Keyboard::isKeyPressed(Keyboard::Down)))
        {
           y=0;
        }
        if(!(Keyboard::isKeyPressed(Keyboard::Right))&&!(Keyboard::isKeyPressed(Keyboard::Left)))
        {
            x=0;
        }
        if(Keyboard::isKeyPressed(Keyboard::Space))
        {
           // x++;
           ofstream file;
           file.open("data/output/text.txt");
           file<<xPos/-7<<" , "<<yPos/-7<<endl;
           file.close();
        }

        xPos=spriteSheet.getPosition().x;
        yPos=spriteSheet.getPosition().y;

        app.clear();
        app.draw(spriteSheet);
        spriteSheet.move(x*fps,y*fps);
        app.display();
    }

    return EXIT_SUCCESS;
}
