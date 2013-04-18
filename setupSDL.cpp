#include <string>
#include <sstream>
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
const int SCREEN_BPP = 32;

SDL_Surface *proj = NULL;
SDL_Surface *character = NULL;
SDL_Surface *stage = NULL;
SDL_Surface *screen = NULL;

SDL_Event event;

SDL_Surface *load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormatAlpha( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );

        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }

    //Return the optimized surface
    return optimizedImage;
}

void apply_surface (int x, int y, SDL_Surface*source, SDL_Surface* destination, SDL_Rect* clip = NULL)
{
    //Temporary rectangle to hold offsets
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    //Blit Surface
    SDL_BlitSurface (source, clip, destination, &offset);
}

bool init()
{
    if (SDL_Init (SDL_INIT_EVERYTHING) == -1)
    {
        return false;
    }

    screen = SDL_SetVideoMode (SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    
    //Check for error in setting up screen
    if (screen == NULL)
    {
        return false;
    }

    if (TTF_Init() == -1)
    {
        return false;
    }

    SDL_WM_SetCaption ("[FEZ] TOEHOE", NULL);
    
    return true;
}

bool load_files()
{
    //Load the dot image
    character = load_image( "characters.png" );
  proj = load_image ("projectile.png");
	stage = load_image ("stages.png");

    //If there was a problem in loading the dot
    if( character, proj, stage == NULL )
    {
        return false;
    }

    //If everything loaded fine
    return true;
}

void clean_up()
{
    SDL_FreeSurface(character);
    SDL_FreeSurface(proj);
    SDL_FreeSurface(stage);

    SDL_Quit();
}
