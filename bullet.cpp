//------Global Members-------
const int playerbullet = 0;

SDL_Rect clipPlayerbullet[1];


//----------CLASS Declaration-------------
class bullet
{
	public:

		//----------------------
		//----Constructors
		//----------------------
    
		bullet();
		bullet(int x, int y, int w, int h);
	
		//----------------------
		//----Mutators
		//----------------------

		void setXY(int x, int y);
		void setWH(int w, int h);
		void setYVel(int yVel);
		void setXVel(int xVel);
		void setClips();
		void setOnScreen(bool state);

		//----------------------
		//----Inspectors
		//----------------------
	
		int getX() const;
		int getY() const;
		int getW() const;
		int getH() const;
		int getXVel() const;
		int getYVel() const;
		void getBullet(SDL_Surface *surface);
		bool getOnScreen() const;

		//----------------------
		//----Facilitators
		//----------------------

		void move();
		void show();
		void handle_input(int x, int y);


	//----------------------
	//----Private Members
	//----------------------

	private:

		// Movements
		int x_, y_, w_, h_;
		int xVel_, yVel_;

		// Graphics
		bool onScreen;
		SDL_Rect proj;
		SDL_Surface *bulletSprite;
};




//----------------------
//----Constructors
//----------------------

	bullet::bullet()
	{
		xVel_ = 0;
		yVel_ = 0;
		onScreen = false;
		bulletSprite = character;
	}

	bullet::bullet(int x, int y, int w, int h)
	{
		proj.x = x;
		proj.y = y;
		proj.w = w;
		proj.h = h;
		xVel_ = 0;
		yVel_ = 0;
		onScreen = false;
		bulletSprite = character;
	}


//----------------------
//----Mutators
//----------------------

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


	void bullet::setClips()
	{
		clipPlayerbullet [0].x = 128;
		clipPlayerbullet [0].y = 0;
		clipPlayerbullet [0].w = 15;
		clipPlayerbullet [0].h = 15;
	}

	void bullet::setXVel(int xVel)
	{
		xVel_ = xVel;
	}

	void bullet::setYVel(int yVel)
	{
		yVel_ = yVel;
	}

	void bullet::setOnScreen(bool state)
	{
		onScreen = state;
	}
//----------------------
//----Inspectors
//----------------------

	int bullet::getX() const
	{
		return x_;
	}
	int bullet::getY() const
	{
		return y_;
	}
	int bullet::getW() const
	{
		return w_;
	}
	int bullet::getH() const
	{
		return h_;
	}

	int bullet::getXVel() const
	{
		return xVel_;
	}

	int bullet::getYVel() const
	{
		return yVel_;
	}

	bool bullet::getOnScreen() const
	{
		return onScreen;
	}

//----------------------
//----Facilitator
//----------------------

	void bullet::move()
	{
		//Move the dot up or down
		proj.y -= yVel_;

		//If the bullet went too far up or down
		//if ((proj.y < -15) || (proj.y + proj.h > SCREEN_HEIGHT + 15) )
		//{
		//	//remove bullet
		//	setOnScreen(false);
		//};
	}

	void bullet::show()
	{
		if (getOnScreen() == true)
		{
			//cout << "This is " << getOnScreen() << endl;
			apply_surface(proj.x, proj.y, bulletSprite, screen, &clipPlayerbullet[0]);
		}
	}
	
	void bullet::handle_input(int x, int y)
	{
		Uint8 *keystates = SDL_GetKeyState (NULL);

		//If a key was pressed
		if (event.type == SDL_KEYDOWN)
		{
			//Adjust the velocity
			if (event.key.keysym.sym == SDLK_z)
			{
				cout << "z was pressed" << endl;
				setOnScreen(true);
				setXY(x, y);
				yVel_= 15;
			}
		}
	}
