#include "setupSDL.cpp"
#include "player.cpp"
#include "timer.cpp"
#include "bulletsv2.cpp"
#include "enemy.cpp"
#include <sstream>

using namespace std;

const int STAGE = 0;
SDL_Rect clipstree[1];

void setclips()
{
	clipstree [0].x = 290;
	clipstree [0].y = 340;
	clipstree [0].h = 110;
	clipstree [0].w = 110;
}

int main (int argc, char* args[])
{
    //Quit flag
    bool quit = false;

    //Initialize
    if (init() == false)
    {
        return 1;
    }

	//Load the files
	if (load_files() == false)
	{
		return 1;
	}

	int n = 0;
	player raymoo;
	enemy fairy;
	Timer fps;
	raymoo.setclips();
	fairy.setclips();
	setclips();
	bullet talisman;
	bullet *tali;
	tali = new bullet [50];

	for (int i = 0; i < 50; i++)
	{
		tali[i].setWH (15,15);
		tali[i].setclips();
	}


	//While the user hasn't quit
    while (quit == false)
    {
		//Start the frame timer
        fps.start();

		//While there's events to handle
        while (SDL_PollEvent(&event))
        {
			//Handles event for player raymoozzzzzzzzzzzzzzzzzz
			raymoo.handle_input();
			tali[n].handle_input((raymoo.getX_() + PLAYER_WIDTH/4), (raymoo.getY_() + PLAYER_HEIGHT/2));

            //If the user has Xed out the window
            if (event.type == SDL_QUIT)
            {
                //Quit the program
                quit = true;
            }
        }

		//move raymoo
		raymoo.move();

		//move talismans
		for (int i = 0; i < 50; i++)
			tali[i].move();


		//Fill the screen white
		SDL_FillRect (screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
		
		apply_surface(SCREEN_WIDTH/4, SCREEN_HEIGHT/4, stage, screen, &clipstree[0]);
		
		//show raymoo
		raymoo.show();

		fairy.show();
		
		//show talismans
		for (int i = 0; i < 50; i++)
			tali[i].show();


		//counter to step through array

		if (n == 49)
		{
			n = 0;
		}

		else
		{
			n++;
		}

        //Update the screen
        if (SDL_Flip(screen) == -1)
        {
            return 1;
        }

		//Cap the frame rate
        if(fps.get_ticks() < 1000 / FRAMES_PER_SECOND)
        {
            SDL_Delay((1000 / FRAMES_PER_SECOND) - fps.get_ticks());
        }
    }

    //Clean up
    clean_up();

    return 0;
}
