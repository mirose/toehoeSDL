#include "iostream"
#include "setupSDL.cpp"
#include "player.cpp"
#include "timer.cpp"
#include "bullet.cpp"
#include <vector>
//#include "bulletQ.cpp"

using namespace std;

const int STAGE = 0;

//Temporary Background Object
SDL_Rect clipstree[1];

void setTreeClips()
{
	clipstree [0].x = 290;
	clipstree [0].y = 340;
	clipstree [0].h = 110;
	clipstree [0].w = 110;
}

int main( int argc, char* args[] )
{

    //Quit flag
    bool quit = false;

    //Initialize SDL settings
    if( init() == false )
    {
        return 1;
    }

	//Load images
    if( load_files() == false )
    {
        return 1;
    }

	//Create player and set clip
	player raymoo;
	raymoo.setClips();
	setTreeClips();

	//Set Talisman Bullet
	bullet talisman;
	bullet *taliSet;
	taliSet = new bullet [50];
	int n = 0;
	for (int i = 0; i < 50; i++)
	{
		taliSet[i].setWH(15,15);
		taliSet[i].setClips();
	}

	//Keep track of frame count
	int frame = 0;
	Timer fps;
	Timer update;

    //While the user hasn't quit
    while( quit == false )
    {
		//Start the frame timer
		fps.start();


        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
			//Handles event for player raymoo
			raymoo.handle_input();
			taliSet[n].handle_input((raymoo.getX() + PLAYER_WIDTH/4), (raymoo.getY() + PLAYER_HEIGHT/2));

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }

		//Move raymoo
		raymoo.move();

		//Move projectiles
		for (int i = 0; i < 50; i++)
		{
			taliSet[i].move();
		}



        //Fill the screen white
        SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );

		//Load Background Object (tree)
		apply_surface(SCREEN_WIDTH/4, SCREEN_HEIGHT/4, stage, screen, &clipstree[0]);

		//Show raymoo on screen
		raymoo.show();

		//Show bullets on screen
		for (int i = 0; i < 50; i++)
		{
			taliSet[i].show();
		}

		if (n >= 49)
			n = 0;
		else
			n++;

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        //Cap the frame rate
        if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }

    }


    //Clean up
    clean_up();

    return 0;
}
