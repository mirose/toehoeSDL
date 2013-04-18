//------CLASS DECLARATION-------
const int NEUTRAL_L = 0;
const int NEUTRAL_R = 1;
const int LEFT = 2;
const int RIGHT = 3;

SDL_Rect clipsNeutral_L[4];
SDL_Rect clipsNeutral_R[4];
SDL_Rect clipsLeft [7];
SDL_Rect clipsRight [7];

class player
{
    public:
    
        //----------------------
        //----Constructors
        //----------------------
        
        player() ;
        player(int type);
        
        //----------------------
        //----Facilitators
        //----------------------
        
        void setLife(int life);
		void setType(int type);
		void setBomb(int bomb);
		void setPlevel(int plevel);
		void setScore(int score);
		void setclips();
		void setShoot_(bool shoot_);

		//Takes key presses and adjusts the player's velocity
		void handle_input();
		void firebullet();

		//Moves the player
		void move();

        //----------------------
        //----Inspectors
        //----------------------
           
        int getLife() const;
        int getType() const;
        int getBomb() const;
        int getPlevel() const;
        int getScore() const;
		int getX_() const;
		int getY_() const;
		int getXVel_() const;
		int getYVel_() const;
		bool getShoot_() const;

        //Shows the player on the screen
        void show();
    
    private:

        // Movements
        int x_, y_;
        int xVel_, yVel_;

		// Stats
        int life_;
        int type_;
        int bomb_;
        int plevel_;
        int score_;
		bool shoot_;
		int shots;

        // Graphics
		int frame;
		int status;
		int delay;

        SDL_Surface *mainSprite;
		SDL_Rect box;
		SDL_Rect* clip;

		/*bullet *tali;*/
};
//----------CLASS IMPLEMENTATION-------------
//----------------------
//----Constructors
//----------------------
    player::player()
    {
		//game data
        x_ = SCREEN_WIDTH/2;
        y_ = SCREEN_HEIGHT/2;
        xVel_ = 0;
        yVel_ = 0;
        life_ = 2;
        type_ = 0;
        bomb_ = 2;
        plevel_ = 0;
        score_ = 0;
		shots = 0;
		shoot_ = false;
		//shoot_[0] = 0;
		//shoot_[1] = 0;
		//shoot_[2] = 0;
		//shoot_[3] = 0;
		//shoot_[4] = 0;
		//shoot_[5] = 0;
		//shoot_[6] = 0;
		//shoot_[7] = 0;
		//shoot_[8] = 0;
		//shoot_[9] = 0;

		//animations
		frame = 0;
		delay = 0;
		status = NEUTRAL_L;
        mainSprite = character;
    }
        
        player::player(int type)
    {
		//game data
        x_ = SCREEN_WIDTH/2;
        y_ = SCREEN_HEIGHT/2;
        xVel_ = 0;
        yVel_ = 0;
        life_ = 2;
        type_ = type;
        bomb_ = 2;
        plevel_ = 0;
        score_ = 0;
		shots = 0;
		shoot_ = false;
		//shoot_[0] = 0;
		//shoot_[1] = 0;
		//shoot_[2] = 0;
		//shoot_[3] = 0;
		//shoot_[4] = 0;
		//shoot_[5] = 0;
		//shoot_[6] = 0;
		//shoot_[7] = 0;
		//shoot_[8] = 0;
		//shoot_[9] = 0;

		//animations
		frame = 0;
		delay = 0;
		status = NEUTRAL_L;
        mainSprite = character;
    }

//----------------------
//----Inspectors
//----------------------
int player::getLife() const
{
	return life_;
}

int player::getType() const
{
	return type_;
}

int player::getBomb() const
{
	return bomb_;
}

int player::getPlevel() const
{
	return plevel_;
}

int player::getScore() const
{
	return score_;
}

int player::getX_() const
{
	return x_;
}

int player::getY_() const
{
	return y_;
}

int player::getXVel_() const
{
	return xVel_;
}

int player::getYVel_() const
{
	return xVel_;
}

bool player::getShoot_() const
{
	return shoot_;
}

void player::show()
{
	//if (player::getShoot_() == true)
	//{
	//	player::firebullet();
	//}

	if (xVel_ < 0)
	{
		status = LEFT;

		delay++;
	}

	else if (xVel_ > 0)
	{
		status = RIGHT;
		delay++;
	}

	else
	{
		if ((status == LEFT) || (status == NEUTRAL_L))
		{
			status = NEUTRAL_L;
			delay++;
		}

		else if ((status == RIGHT) || (status ==NEUTRAL_R))
		{
			status = NEUTRAL_R;
			delay++;
		}
	}

	if (delay > 2)
	{
		frame++;
		delay = 0;
	}

	// //Loop the animation 
	if ((frame >= 7) && (status == LEFT))
	{
		frame = 3;
	}

	else if ((frame >= 7) && (status == RIGHT))
	{
		frame = 3 ;
	}

	else if ((frame >= 4) && (status == NEUTRAL_L))
	{
		frame = 0;
	}

	else if ((frame >= 4) && (status == NEUTRAL_R))
	{
		frame = 0;
	}

	if (status == RIGHT)
	{
		apply_surface(x_, y_, mainSprite, screen, &clipsRight[frame]);
	}
	
	else if (status == LEFT)
	{
		apply_surface(x_, y_, mainSprite, screen, &clipsLeft[frame]);
	}

	else if (status == NEUTRAL_R)
	{
		apply_surface (x_, y_, mainSprite, screen, &clipsNeutral_R[frame]);
	}

	else
	{
		apply_surface(x_, y_, mainSprite, screen, &clipsNeutral_L[frame]);
	}
}

//----------------------
//----Facilitator
//----------------------
        
void player::setLife (int life)
{
	life_ = life;
}
void player::setType (int type)
{
	type_ = type;
}

void player::setBomb (int bomb)
{
	bomb_ = bomb;
}

void player::setPlevel(int plevel)
{
	plevel_ = plevel;
}

void player::setScore(int score)
{
	score_ = score;
}

void player::setShoot_(bool shoot)
{
	shoot_ = shoot;
}

void player::handle_input()
{
	bool fire = false;
	Uint8 *keystates = SDL_GetKeyState (NULL);

    //If a key was pressed
    if (event.type == SDL_KEYDOWN)
    {
        //Adjust the velocity
		switch (event.key.keysym.sym)
        {
            case SDLK_UP: 
				yVel_ -= PLAYER_HEIGHT/6; 
				break;
            case SDLK_DOWN: 
				yVel_ += PLAYER_HEIGHT/6; 
				break;
            case SDLK_LEFT: 
				xVel_ -= PLAYER_WIDTH/4; 
				break;
            case SDLK_RIGHT: 
				xVel_ += PLAYER_WIDTH/4; 
				break;
			//case SDLK_z:
			//	fire = true;
			//	player::setShoot_(fire);
			//	//shots++;
			//	break;
        }
    }
    //If a key was released
    else if (event.type == SDL_KEYUP)
    {
        //Adjust the velocity
        switch (event.key.keysym.sym)
        {
            case SDLK_UP: 
				yVel_ += PLAYER_HEIGHT/6; 
				break;
            case SDLK_DOWN: 
				yVel_ -= PLAYER_HEIGHT/6; 
				break;
            case SDLK_LEFT: 
				xVel_ += PLAYER_WIDTH/4; 
				break;
            case SDLK_RIGHT:
				xVel_ -= PLAYER_WIDTH/4; 
				break;
			//case SDLK_z:
			//	fire = false;
			//	player::setShoot_(fire);
			//	break;
        }
    }
}

//void player::firebullet()
//{
//	////creates a talisman bullet
//	bullet talisman ((player::getX_() + PLAYER_WIDTH/4), (player::getY_() + PLAYER_HEIGHT/2), 15, 15);
//	tali = &talisman;
//	tali->setclips();
//	//talisman.setcounter(shots);
//	tali->setstatus(shoot_);
//
//	if (talisman.getstatus() == true)
//	{
//
//	 //while the bullet is with in screen do these
//		do 
//		{
//			tali->setstatus(true);
//			tali->move();
//			tali->show();
//		}
//		while (talisman.gety_bullet() +15 < SCREEN_HEIGHT);
//	}
//}

void player::move()
{
    //Move the player left or right
    x_ += xVel_;

    //If the player went too far to the left or right
    if ((x_ < -15) || (x_ + PLAYER_WIDTH > SCREEN_WIDTH + 15))
    {
        //move back
        x_ -= xVel_;
    }

    //Move the player up or down
    y_ += yVel_;

    //If the player went too far up or down
    if ((y_ < -15) || (y_ + PLAYER_HEIGHT > SCREEN_HEIGHT + 15) )
    {
        //move back
        y_ -= yVel_;
    }
}

void player::setclips()
{
	clipsNeutral_L [0].x = 0;
	clipsNeutral_L [0].y = 0;
	clipsNeutral_L [0].w = PLAYER_WIDTH;
	clipsNeutral_L [0].h = PLAYER_HEIGHT;

	clipsNeutral_L [1].x = PLAYER_WIDTH;
	clipsNeutral_L [1].y = 0;
	clipsNeutral_L [1].w = PLAYER_WIDTH;
	clipsNeutral_L [1].h = PLAYER_HEIGHT;

	clipsNeutral_L [2].x = PLAYER_WIDTH * 2;
	clipsNeutral_L [2].y = 0;
	clipsNeutral_L [2].w = PLAYER_WIDTH;
	clipsNeutral_L [2].h = PLAYER_HEIGHT;

	clipsNeutral_L [3].x = PLAYER_WIDTH * 3;
	clipsNeutral_L [3].y = 0;
	clipsNeutral_L [3].w = PLAYER_WIDTH;
	clipsNeutral_L [3].h = PLAYER_HEIGHT;

	clipsNeutral_R [0].x = 741;
	clipsNeutral_R [0].y = 256;
	clipsNeutral_R [0].w = PLAYER_WIDTH;
	clipsNeutral_R [0].h = PLAYER_HEIGHT;

	clipsNeutral_R [1].x = 741 - PLAYER_WIDTH;
	clipsNeutral_R [1].y = 256;
	clipsNeutral_R [1].w = PLAYER_WIDTH;
	clipsNeutral_R [1].h = PLAYER_HEIGHT;

	clipsNeutral_R [2].x = 741 - PLAYER_WIDTH * 2;
	clipsNeutral_R [2].y = 256;
	clipsNeutral_R [2].w = PLAYER_WIDTH;
	clipsNeutral_R [2].h = PLAYER_HEIGHT;

	clipsNeutral_R [3].x = 741 - PLAYER_WIDTH * 3;
	clipsNeutral_R [3].y = 256;
	clipsNeutral_R [3].w = PLAYER_WIDTH;
	clipsNeutral_R [3].h = PLAYER_HEIGHT;

	clipsLeft [0].x = 0;
	clipsLeft [0].y = PLAYER_HEIGHT;
	clipsLeft [0].w = PLAYER_WIDTH;
	clipsLeft [0].h = PLAYER_HEIGHT;

	clipsLeft [1].x = PLAYER_WIDTH;
	clipsLeft [1].y = PLAYER_HEIGHT;
	clipsLeft [1].w = PLAYER_WIDTH;
	clipsLeft [1].h = PLAYER_HEIGHT;

	clipsLeft [2].x = PLAYER_WIDTH * 2;
	clipsLeft [2].y = PLAYER_HEIGHT;
	clipsLeft [2].w = PLAYER_WIDTH;
	clipsLeft [2].h = PLAYER_HEIGHT;

	clipsLeft [3].x = PLAYER_WIDTH * 3;
	clipsLeft [3].y = PLAYER_HEIGHT;
	clipsLeft [3].w = PLAYER_WIDTH;
	clipsLeft [3].h = PLAYER_HEIGHT;

	clipsLeft [4].x = PLAYER_WIDTH * 4;
	clipsLeft [4].y = PLAYER_HEIGHT;
	clipsLeft [4].w = PLAYER_WIDTH;
	clipsLeft [4].h = PLAYER_HEIGHT;

	clipsLeft [5].x = PLAYER_WIDTH * 5;
	clipsLeft [5].y = PLAYER_HEIGHT;
	clipsLeft [5].w = PLAYER_WIDTH;
	clipsLeft [5].h = PLAYER_HEIGHT;

	clipsLeft [6].x = PLAYER_WIDTH * 6;
	clipsLeft [6].y = PLAYER_HEIGHT;
	clipsLeft [6].w = PLAYER_WIDTH;
	clipsLeft [6].h = PLAYER_HEIGHT;

	clipsRight [0].x = 741;
	clipsRight [0].y = 304;
	clipsRight [0].w = PLAYER_WIDTH;
	clipsRight [0].h = PLAYER_HEIGHT;

	clipsRight [1].x = 741 - PLAYER_WIDTH;
	clipsRight [1].y = 304;
	clipsRight [1].w = PLAYER_WIDTH;
	clipsRight [1].h = PLAYER_HEIGHT;

	clipsRight [2].x = 741 - PLAYER_WIDTH * 2;
	clipsRight [2].y = 304;
	clipsRight [2].w = PLAYER_WIDTH;
	clipsRight [2].h = PLAYER_HEIGHT;

	clipsRight [3].x = 741 - PLAYER_WIDTH * 3;
	clipsRight [3].y = 304;
	clipsRight [3].w = PLAYER_WIDTH;
	clipsRight [3].h = PLAYER_HEIGHT;

	clipsRight [4].x = 741 - PLAYER_WIDTH * 4;
	clipsRight [4].y = 304;
	clipsRight [4].w = PLAYER_WIDTH;
	clipsRight [4].h = PLAYER_HEIGHT;

	clipsRight [5].x = 741 - PLAYER_WIDTH * 5;
	clipsRight [5].y = 304;
	clipsRight [5].w = PLAYER_WIDTH;
	clipsRight [5].h = PLAYER_HEIGHT;

	clipsRight [6].x = 741 - PLAYER_WIDTH * 6;
	clipsRight [6].y = 304;
	clipsRight [6].w = PLAYER_WIDTH;
	clipsRight [6].h = PLAYER_HEIGHT;
}
