//=========SPRITES==========

const int ENEMY_NL = 0;
const int ENEMY_L = 1;

SDL_Rect clipsENEMY_NL[4];
SDL_Rect clipsENEMY_L [7];

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

	//Moves the enemy
	void move();

	int getX_() const;
	int getY_() const;
	int getXVel_() const;
	int getYVel_() const;

	//Shows the enemy on the screen
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
	y_ = SCREEN_HEIGHT/2;
	xVel_ = 0;
	yVel_ = 0;

	//animations
	frame = 0;
	delay = 0;
	status = ENEMY_NL;
	genEnemy = enemy;
}

void enemy::show()
{
	apply_surface(x_, y_, genEnemy, screen, &clipsENEMY_NL[frame]);
}

void enemy::setclips()
{
	clipsENEMY_NL [0].x = 406;
	clipsENEMY_NL [0].y = 0;
	clipsENEMY_NL [0].w = 28;
	clipsENEMY_NL [0].h = 28;

	clipsENEMY_NL [1].x = 406 + 28;
	clipsENEMY_NL [1].y = 0;
	clipsENEMY_NL [1].w = 28;
	clipsENEMY_NL [1].h = 28;

	clipsENEMY_NL [2].x = 406 + 28 * 2;
	clipsENEMY_NL [2].y = 0;
	clipsENEMY_NL [2].w = 28;
	clipsENEMY_NL [2].h = 28;

	clipsENEMY_NL [3].x = 406 + 28 * 3;
	clipsENEMY_NL [3].y = 0;
	clipsENEMY_NL [3].w = 28;
	clipsENEMY_NL [3].h = 28;
}
