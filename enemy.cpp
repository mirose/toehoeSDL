//=========SPRITES==========

const int ENEMY_NL = 0;
const int ENEMY_L = 1;
const int ENEMY_N = 2;

SDL_Rect clipsENEMY_NL[4];
SDL_Rect clipsENEMY_L [7];
SDL_Rect clipsENEMY_N [1];

class enemy
{
	public:
    
	//----------------------
	//----Constructors
	//----------------------
        
	enemy() ;
        
	//----------------------
	//----Facilitators
	//----------------------
	void setclips();

	//Takes key presses and adjusts the player's velocity
	void handle_input();

	//Moves the player
	void move();

	int getX_() const;
	int getY_() const;
	int getXVel_() const;
	int getYVel_() const;

	//Shows the player on the screen
	void show();
    
	private:

	// Movements
    int x_, y_;
    int xVel_, yVel_;

	// Graphics
	int frame;
	int status;
	int delay;

	SDL_Surface *genEnemy;
	SDL_Rect box;
	SDL_Rect* clip;

};

//----------CLASS IMPLEMENTATION-------------
//----------------------
//----Constructors
//----------------------
enemy::enemy()
{
	//game data
	x_ = SCREEN_WIDTH/2;
	y_ = 30;
	xVel_ = 0;
	yVel_ = 0;

	//animations
	frame = 0;
	delay = 0;
	status = ENEMY_N;
	genEnemy = enmyPNG;
}

void enemy::show()
{
	if(status == ENEMY_NL)
	{
		status = ENEMY_NL;
		delay++;
	}

	if (delay > 2)
	{
		frame++;
		delay = 0;
	}

	else if ((frame >= 4) && (status == ENEMY_NL))
	{
		frame = 0;
	}

	apply_surface(x_, y_, genEnemy, screen, &clipsENEMY_N[frame]);
}

void enemy::setclips()
{
	clipsENEMY_NL [0].x = 785;
	clipsENEMY_NL [0].y = 976;// 792+189
	clipsENEMY_NL [0].w = 40;
	clipsENEMY_NL [0].h = 40;

	clipsENEMY_NL [1].x = 785 + 40;
	clipsENEMY_NL [1].y = 976;
	clipsENEMY_NL [1].w = 40;
	clipsENEMY_NL [1].h = 40;

	clipsENEMY_NL [2].x = 785 + (40 * 2);
	clipsENEMY_NL [2].y = 976;
	clipsENEMY_NL [2].w = 40;
	clipsENEMY_NL [2].h = 40;

	clipsENEMY_NL [3].x = 785 + (40 * 3);
	clipsENEMY_NL [3].y = 976;
	clipsENEMY_NL [3].w = 40;
	clipsENEMY_NL [3].h = 40;

	clipsENEMY_N [0].x = 790;
	clipsENEMY_N [0].y = 792+189;
	clipsENEMY_N [0].w = 30;
	clipsENEMY_N [0].h = 30;
}

