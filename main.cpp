#include "setupSDL.cpp"
#include "bullets.cpp"
#include "player.cpp"
#include "timer.cpp"
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

	int i = 0;
	player raymoo;
	Timer fps;
	raymoo.setclips();
	setclips();
	bullet talisman;
	bullet *tali;
	tali = new bullet [100];
	//bullet talisman ((raymoo.getX_() + PLAYER_WIDTH/4), (raymoo.getY_() + PLAYER_HEIGHT/2), 15, 15);

	tali[0].setWH (15,15);
	tali[1].setWH (15,15);
	tali[2].setWH (15,15);
	tali[3].setWH (15,15);
	tali[4].setWH (15,15);
	tali[5].setWH (15,15);
	tali[6].setWH (15,15);
	tali[7].setWH (15,15);
	tali[8].setWH (15,15);
    tali[9].setWH (15,15);

	tali[0].setclips();
	tali[1].setclips();
	tali[2].setclips();
	tali[3].setclips();
	tali[4].setclips();
	tali[5].setclips();
	tali[6].setclips();
	tali[7].setclips();
	tali[8].setclips();
	tali[9].setclips();

	//While the user hasn't quit
    while (quit == false)
    {
		//Start the frame timer
        fps.start();

		//While there's events to handle
        while (SDL_PollEvent(&event))
        {
			//Handles event for player raymoo
			raymoo.handle_input();
			tali[i].setXY((raymoo.getX_() + PLAYER_WIDTH/4), (raymoo.getY_() + PLAYER_HEIGHT/2));
			tali[i].handle_input();

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
		tali[0].move();
		tali[1].move();
		tali[2].move();
		tali[3].move();
		tali[4].move();
		tali[5].move();
		tali[6].move();
		tali[7].move();
		tali[8].move();
		tali[9].move();

		//Fill the screen white
		SDL_FillRect (screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
		
		apply_surface(SCREEN_WIDTH/4, SCREEN_HEIGHT/4, stage, screen, &clipstree[0]);
		
		//show raymoo
		raymoo.show();
		
		//show talismans
		tali[0].show();
		tali[1].show();
		tali[2].show();
		tali[3].show();
		tali[4].show();
		tali[5].show();
		tali[6].show();
		tali[7].show();
		tali[8].show();
		tali[9].show();

		//counter to step through array

		if (i >= 10)
		{
			i = 0;
		}

		else
		{
			i++;
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
