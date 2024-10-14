#pragma once

#ifndef CHARACTER_H
#define CHARACTER_H

#include "object.h"
#include "input.h"

/**
 * Character Class - This is the object all Players, NPC's and beings should use.
 * 
 */

//Character State Machine
enum STATE
{
    //States all characters have
    IDLE,
    WALK,

    //Player specific states
    BIKE,
};

//Character Object
class Character : public Object { //abstract
public:
    Character(Properties* props) : Object(props) { 
        m_moving = false;
        m_movedDistance = 0;
        m_spd = 2;
        m_dirx = 0;
        m_diry = 0;
        m_xspd = 0;
        m_yspd = 0;
    };

    //virtual void Create()=0;
    virtual void Update(float dt)=0;
    virtual void Draw()=0;
    virtual void DrawGUI()=0;
    virtual void Clean()=0;

    bool IsMoving() { return m_moving; }

    //Call this function to make the character move in a specified direction
    void Move(DIRECTION direction){
     
        if (m_moving == true) return; //dont allow the character to move twice without finishing the first move first

        //reset all movement variables, and set our direction and which ROW of the spritesheet should be rendered
        m_movedDistance = 0;
        m_moving = true;
        m_movementDirection = direction;
        m_row = direction;
        m_state = WALK;
    }

    //Listener to move the character when Move() is called
    void MoveInDirection(DIRECTION direction){
        
        //if were not moving, dont move... duh
        if (m_moving == false) return;

        //check if the character has moved the size of grid cell
        if (m_movedDistance < GRID_SIZE){
            switch(direction){
                //move character in correct direction
                case UP: m_transform->TranslateY(-m_spd); break;
                case DOWN: m_transform->TranslateY(m_spd); break;
                case LEFT: m_transform->TranslateX(-m_spd); break;
                case RIGHT: m_transform->TranslateX(m_spd); break;
            }

        //track how far we have moved
        m_movedDistance += m_spd;
        
        //We have reached our destination
        } else {

            //Check if character if still holding a move button and update our direction accordingly
            if (m_isPlayer){
                if (Input::GetInstance()->GetKeyDown(Input::GetInstance()->btn.up)) m_movementDirection = UP;
                if (Input::GetInstance()->GetKeyDown(Input::GetInstance()->btn.down)) m_movementDirection = DOWN;
                if (Input::GetInstance()->GetKeyDown(Input::GetInstance()->btn.left)) m_movementDirection = LEFT;
                if (Input::GetInstance()->GetKeyDown(Input::GetInstance()->btn.right)) m_movementDirection = RIGHT;

                m_row = m_movementDirection; //update the spritesheet to be the same as our movement direction (we use m_row on states the just use movement sprites, so this wont affect other states that have the row set directly)
            }

            //Reset our current moved distance of the walk
            m_movedDistance = 0;
        }

        //Make sure we aren't holding any more buttons, and have reached the target destination before stopping the character
        if 
        ((Input::GetInstance()->GetKeyDown(Input::GetInstance()->btn.up)) == false &&         
        (Input::GetInstance()->GetKeyDown(Input::GetInstance()->btn.down)) == false &&         
        (Input::GetInstance()->GetKeyDown(Input::GetInstance()->btn.left)) == false &&         
        (Input::GetInstance()->GetKeyDown(Input::GetInstance()->btn.right)) == false &&
        m_movedDistance == 0){

            //tell the character its okay to stop walking so they dont just walk on forever and ever and probably just end up hurting their legs or something drastic along the matters...
            m_moving = false;
            m_state = IDLE;
        }    
    }

protected:
    string m_name = "";
    bool m_isPlayer = false;
    int m_spd = 0;
    int m_dirx = 0;
    int m_diry = 0;
    int m_xspd = 0;
    int m_yspd = 0;

    bool m_moving = false;
    int m_movedDistance = 0;
    DIRECTION m_movementDirection = DOWN;
    STATE m_state = IDLE;
};

#endif // CHARACTER_H