#include "player.h"
#include "texture_manager.h"
#include "SDL.h"
#include "character.h"
#include <input.h>

#define FRAMECOUNT 4 //size of spritesheet horizontally in sprite count

//Player Constructor || Player::Player(Properties* props) : Character(props)
Player::Player(Properties* props) : Character(props)
{
    Create();
    m_animation = new Animation();
    m_animation->SetProps(m_textureID,m_row,FRAMECOUNT,m_animSpd);

}

//Player Create Event
void Player::Create()
{
    m_name = "Player";
    m_row = DOWN;
    m_animSpd = 300;
    m_spd = 2;
    m_dirx = 0;
    m_diry = 0;
    m_xspd = 0;
    m_yspd = 0;
}

//Player Update Event
void Player::Update(float dt)
{
    Input();
    m_animation->Update();

    switch(state){
        case IDLE:
        break;

        case WALK:
        break;
    }

    m_xspd = m_dirx * m_spd * dt;
    m_yspd = m_diry * m_spd * dt;
    m_transform->TranslateX(m_xspd);
    m_transform->TranslateY(m_yspd);
}

//Player Draw Event
void Player::Draw()
{
    m_animation->Draw(m_transform->X, m_transform->Y, m_width, m_height);
}

//Player Draw GUI Event
void Player::DrawGUI()
{
    
}

//Player Input Events
void Player::Input()
{
	int key_up = (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_UP)) ? 1 : 0;
	int key_down = (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_DOWN)) ? 1 : 0;
	int key_left = (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_LEFT)) ? 1 : 0;
	int key_right = (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_RIGHT)) ? 1 : 0;

    m_dirx = key_right - key_left;
    m_diry = key_down - key_up;

    SDL_Log(m_dirx + "");
    SDL_Log(m_diry + "");

    int frame = m_dirx == 0 && m_diry == 0 ? 1 : FRAMECOUNT;

    if (key_up == 1) {
        m_row = UP;
        DrawSetSprite("player",m_row,frame,m_animSpd);
    }

    else if (key_down == 1) {
        m_row = DOWN;
        DrawSetSprite("player",m_row,frame,m_animSpd);
    } 

    else if (key_left == 1) {
        m_row = LEFT;
        DrawSetSprite("player",m_row,frame,m_animSpd);
    }

    else if (key_right == 1) { 
        m_row = RIGHT;
        DrawSetSprite("player",m_row,frame,m_animSpd);
    } 
    else {
        DrawSetSprite("player",m_row,1,m_animSpd);
    }


    

}

//Player Clean-Up Event
void Player::Clean()
{
    TextureManager::GetInstance()->Clean();
}
