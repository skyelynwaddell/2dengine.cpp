#include "player.h"
#include "texture_manager.h"
#include "SDL.h"
#include "character.h"
#include <input.h>
#include <camera.h>

//Player Constructor || Player::Player(Properties* props) : Character(props)
Player::Player(Properties* props) : Character(props)
{
    m_isPlayer = true;
    m_name = "Player";
}

//Player Update Event
void Player::Update(float dt)
{
    m_animation->Update();

    int key_up = (Input::GetInstance()->GetKeyDown(Input::GetInstance()->btn.up)) ? 1 : 0;
	int key_down = (Input::GetInstance()->GetKeyDown(Input::GetInstance()->btn.down)) ? 1 : 0;
	int key_left = (Input::GetInstance()->GetKeyDown(Input::GetInstance()->btn.left)) ? 1 : 0;
	int key_right = (Input::GetInstance()->GetKeyDown(Input::GetInstance()->btn.right)) ? 1 : 0;

    int frame = IsMoving() ? FRAMECOUNT : 1; //set our framecount to the spritesheet width, or to idle depdning if there is any input in the dirx/diry

    if (key_up)         { Move(UP);    }
    else if (key_down)  { Move(DOWN);  } 
    else if (key_left)  { Move(LEFT);  }
    else if (key_right) { Move(RIGHT); }        

    switch(m_state){
        case IDLE:
            DrawSetSprite(m_spriteSheet,m_row,frame,m_animSpd);
        break;

        case WALK:
            DrawSetSprite(m_spriteSheet,m_row,frame,m_animSpd);
            MoveInDirection(m_movementDirection);
        break;
    }

    m_origin->X = m_transform->X + m_width / 2;
    m_origin->Y = m_transform->Y + m_height / 2;
}

//Player Draw Event
void Player::Draw()
{
    Vector2 cam = Camera::GetInstance()->GetPosition();
    m_animation->Draw(m_transform->X - cam.X, m_transform->Y - cam.Y, m_width, m_height);
}

//Player Clean-Up Event
void Player::Clean()
{
    TextureManager::GetInstance()->Clean();
}
