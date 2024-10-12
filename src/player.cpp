#include "player.h"
#include "object.h"

Player::Player(int x, int y, int w, int h, string sprite, SDL_Renderer *renderer, int health)
: Object(x,y,w,h,sprite,renderer)
{
    setDest(x,y,100,100);
    setSource(0,0,64,64);
    setTexture(sprite, renderer);
    m_health = 100;
    Create();
}

void Player::Create(){
    SDL_Log("Create event");

    setX(0);
    setY(0);
}

void Player::Input(SDL_Event event){

    const Uint8* key = SDL_GetKeyboardState(NULL);
    int key_up = key[SDL_SCANCODE_UP] ? 1 : 0;
    int key_down = key[SDL_SCANCODE_DOWN] ? 1 : 0;
    int key_left = key[SDL_SCANCODE_LEFT] ? 1 : 0;
    int key_right = key[SDL_SCANCODE_RIGHT] ? 1 : 0;

    int _dirx = key_right - key_left;
    int _diry = key_down - key_up;

    setDirX(_dirx);
    setDirY(_diry);

    switch(event.type){
        case SDL_KEYDOWN:
        //std::cout << ("Key Down");
        break;

        case SDL_KEYUP:
        //std::cout << ("Key Up");
        break;
    }
}

void Player::Update(){

    //SDL_Log("Update Event");
    setXSpd(getDirX() * getSpd());
    setYSpd(getDirY() * getSpd());

    setX(getX() + getXSpd());
    setY(getY() + getYSpd());

    std::cout << getX() << std::endl;
    std::cout << getY() << std::endl;

    setDest(getX(),getY(),100,100);
    setSource(0,0,64,64);
}

void Player::Draw(){
    draw_sprite(*this,m_renderer);
    //SDL_Log("Draw Event");
}
