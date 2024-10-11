#include "player.h"
#include "object.h"

using std::string;

Player::Player(int x, int y, int w, int h, std::string sprite, SDL_Renderer *renderer, int health)
: Object(x,y,w,h,sprite,renderer)
{
    m_health = 100;
    Create();
}

void Player::Create(){
    SDL_Log("Create event");
}
void Player::Update(){
    SDL_Log("Update Event");
}
void Player::Draw(){
    SDL_Log("Draw Event");
}
