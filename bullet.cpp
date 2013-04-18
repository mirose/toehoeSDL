const int playerbullet = 0;

SDL_Rect clipPlayerbullet[1];

class bullet
{
	public:

	//----------------------
	//----Constructors
	//----------------------
    
	bullet();
    bullet(int x, int y, int w, int h);
	
	//----------------------
	//----Facilitators
	//----------------------

	//void setyVel_bullet(int yVel_bull);
	void setclips();
	void setonScreen(bool stat);
	void handle_input(int player_x, int player_y);
	void move();
	void setXY(int x, int y);
	void setWH(int w, int h);

	//----------------------
	//----Inspectors
	//----------------------
	
	void getbullets(SDL_Surface *surface);
	bool getonScreen() const;
	int gety_bullet() const;

	void show();

	private:

	int xVel_bullet, yVel_bullet;

	bool onScreen;
	SDL_Rect proj;
	SDL_Surface *bullets;
};

bullet::bullet()
{
	xVel_bullet = 0;
	yVel_bullet = 0;
	bullets = character;
}

bullet::bullet(int x, int y, int w, int h)
{
	proj.x = x;
	proj.y = y;
	proj.w = w;
	proj.h = h;
	xVel_bullet = 0;
	yVel_bullet = 0;
	bullets = character;
}

//----------------------
//----Inspectors
//----------------------

bool bullet::getonScreen() const
{
	return onScreen;
}

int bullet::gety_bullet() const
{
	return proj.y;
}

void bullet::show()
{
	if (getonScreen() == true)
	{
		apply_surface(proj.x, proj.y, bullets, screen, &clipPlayerbullet[0]);
	}
}

//----------------------
//----Facilitator
//----------------------

//void bullet::setyVel_bullet(int yVel_bull)
//{
//	yVel_bullet = yVel_bull;
//}

void bullet::setonScreen(bool stat)
{
	onScreen = stat;
}

void bullet::setXY(int x, int y)
{
	proj.x = x;
	proj.y = y;
}

void bullet::setWH(int w, int h)
{
	proj.w = w;
	proj.h = h;
}

void bullet::setclips()
{
	//clip from sprite sheet
	clipPlayerbullet [0].x = 128;
	clipPlayerbullet [0].y = 0;
	clipPlayerbullet [0].w = 15;
	clipPlayerbullet [0].h = 15;
}

void bullet::handle_input(int player_x, int player_y)
{
	Uint8 *keystates = SDL_GetKeyState (NULL);

    //If z pressed down
    if ((keystates [SDLK_z]) && (event.type == SDL_KEYDOWN))
	{
		setonScreen(true);
		setXY(player_x, player_y);
		yVel_bullet = 15;
	}
}


void bullet::move()
{
    //Move the bullet up
    proj.y -= yVel_bullet;

    //If the bullet went too far up or down
    if ((proj.y < -15) || (proj.y + proj.h > SCREEN_HEIGHT + 15) )
    {
        //remove bullet
        setonScreen(false);
    }
}
