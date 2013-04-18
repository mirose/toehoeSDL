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
	void setstatus(bool stat);
	void handle_input();
	void move();
	void setXY(int x, int y);
	void setWH(int w, int h);
	void setcounter(int j);

	//----------------------
	//----Inspectors
	//----------------------
	
	void getbullets(SDL_Surface *surface);
	bool getstatus() const;
	int gety_bullet() const;
	int getcounter() const;

	void show();

	private:

	int xVel_bullet, yVel_bullet;
	int counter;

	bool status;
	SDL_Rect proj;
	SDL_Surface *bullets;
};

bullet::bullet()
{
	xVel_bullet = 0;
	yVel_bullet = 0;
	counter = 0;
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
	counter = 0;
	bullets = character;
}

//----------------------
//----Inspectors
//----------------------

bool bullet::getstatus() const
{
	return status;
}

int bullet::gety_bullet() const
{
	return proj.y;
}

int bullet::getcounter() const
{
	return counter;
}

void bullet::show()
{
	if (bullet::getstatus() == true)
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

void bullet::setstatus(bool stat)
{
	status = stat;
	//status[0] = stat[0];
	//status[1] = stat[1];
	//status[2] = stat[2];
	//status[3] = stat[3];
	//status[4] = stat[4];
	//status[5] = stat[5];
	//status[6] = stat[6];
	//status[7] = stat[7];
	//status[8] = stat[8];
	//status[9] = stat[9];
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

void bullet::setcounter(int j)
{
	counter = j;
}

void bullet::setclips()
{
	clipPlayerbullet [0].x = 128;
	clipPlayerbullet [0].y = 0;
	clipPlayerbullet [0].w = 15;
	clipPlayerbullet [0].h = 15;
}

void bullet::handle_input()
{
			status = true;
			yVel_bullet = 15;
	//Uint8 *keystates = SDL_GetKeyState (NULL);

 //   //If a key was pressed
 //   if (event.type == SDL_KEYDOWN)
 //   {
 //       //Adjust the velocity
	//	if (event.key.keysym.sym == SDLK_z)
 //       {
	//		status = true;
	//		yVel_bullet = 15;
	//	}
	//}
}

void bullet::move()
{
    //Move the bullet up
    proj.y -= yVel_bullet;

    //If the bullet went too far up or down
    if ((proj.y < -15) || (proj.y + proj.h > SCREEN_HEIGHT + 15) )
    {
        //remove bullet
        status = false;
    }
}

