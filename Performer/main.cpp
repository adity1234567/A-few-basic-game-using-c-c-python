#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
int windowWidth=400;
int windowHeight=300;

using namespace sf;
using namespace std;

class playerClass{
     public:
         playerClass(){//constructor

          cout<<"jdakfjac8cfhd8chd8"<<endl;

         }

};
int main()
{
    // Create the main window
    RenderWindow app(VideoMode(windowWidth,windowHeight), "Platformer");

    bool up,down,left,right=false;

    playerClass playerObject;
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

        // Clear screen
        app.clear();



        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
