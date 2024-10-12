#include "player.h"
#include "object.h"

Player::Player(SDL_Renderer *renderer, string sprite, int x, int y, int w, int h, int health)
: Object(x,y,w,h,sprite,renderer)
{
    setDest(x,y,64,64);
    setSource(0,0,100,100);
    setTexture(sprite, renderer);
    m_health = 100;
    Create();
}

void Player::Create(){
    SDL_Log("Create event");

    setX(0);
    setY(0);
}

void Player::Input(const SDL_Event& event){

    const Uint8* key = SDL_GetKeyboardState(NULL);
    int key_up = key[SDL_SCANCODE_UP] ? 1 : 0;
    int key_down = key[SDL_SCANCODE_DOWN] ? 1 : 0;
    int key_left = key[SDL_SCANCODE_LEFT] ? 1 : 0;
    int key_right = key[SDL_SCANCODE_RIGHT] ? 1 : 0;

    int _dirx = key_right - key_left;
    int _diry = key_down - key_up;

    setDirX(_dirx);
    setDirY(_diry);

    int _x = getX();
    int _y = getY();

    switch(event.type){
        case SDL_KEYDOWN:
        //std::cout << ("Key Down");
        break;

        case SDL_KEYUP:
        //std::cout << ("Key Up");

        break;

        case SDL_MOUSEMOTION:
        //std::cout << "Mouse moved \n";
        SDL_GetMouseState(&_x,&_y);

        default:
        break;
    }

    setX(_x);
    setY(_y);

}

void Player::Update(float delta_time){

    //SDL_Log("Update Event");
    setXSpd((getDirX() * getSpd()));
    setYSpd((getDirY() * getSpd()));

    setX(getX() + getXSpd() * delta_time); 
    setY(getY() + getYSpd() * delta_time); 

    std::cout << "X: " << getX() << "\n";
    std::cout << "Y: " << getY() << "\n";

    setDest(getX(),getY(),64,64);
    setSource(0,0,100,100);
}

void Player::Draw(){
    draw_sprite(*this,m_renderer);
    //SDL_Log("Draw Event");
}

