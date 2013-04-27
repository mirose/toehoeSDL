//Hitbox
class hitbox
{
    private:
    //The collision box of the square
    SDL_Rect box;
    
    public:
    //Initializes the variables
    hitbox();
    
    //Takes key presses and adjusts the square's velocity
    void handle_input();
    
    //Shows the square on the screen
    void show();
};

hitbox::hitbox()
{
    //Initialize the offsets
    box.x = 0;
    box.y = 0;
    
    //Set the square's dimensions
    box.w = SQUARE_WIDTH;
    box.h = SQUARE_HEIGHT;
    
}

void hitbox::show()
{
    //Show the square
    apply_surface( box.x, box.y, square, screen );
}

bool hitbox::check_collision( SDL_Rect A, SDL_Rect B )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;
        
    //Calculate the sides of rect B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }
    
    if( topA >= bottomB )
    {
        return false;
    }
    
    if( rightA <= leftB )
    {
        return false;
    }
    
    if( leftA >= rightB )
    {
        return false;
    }
    
    //If none of the sides from A are outside B
    return true;
}
