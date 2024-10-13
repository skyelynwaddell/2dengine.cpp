#pragma once

#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <SDL_render.h>
#include "iobject.h"
#include "transform.h"
#include "animation.h"

using std::string;

/**
 * Game Object Class
 * This class lets is the main game object that can draw sprites, text, and perform code on with a create, update, and draw, and draw gui events
 * children:
 *      - character.h
 */

//Properties(string textureID, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE)
struct Properties {
public:
    Properties(string textureID, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE){
        TextureID = textureID;
        X = x;
        Y = y;
        Width = width;
        Height = height;
        Flip = flip;
    }

    string TextureID;
    float X, Y;
    int Width, Height;
    SDL_RendererFlip Flip;
};

class Object : public IObject {
public:
    Object(Properties* props) : m_textureID(props->TextureID), m_width(props->Width), m_height(props->Height), m_flip(props->Flip) 
    {
        m_transform = new Transform(props->X, props->Y);
    }
    
    virtual void Create()=0;
    virtual void Update(float dt)=0;
    virtual void Draw()=0;
    virtual void DrawGUI()=0;
    virtual void Clean()=0;

    void DrawSetSprite(string textureID, int row, int frameCount, int animSpd){
        m_textureID = textureID;
        m_row = row;
        m_frameCount = frameCount;
        m_animSpd = animSpd;
        m_animation->SetProps(textureID,row,frameCount,animSpd);
    }

private:
protected:
    int m_width;
    int m_height;
    string m_textureID;
    Transform* m_transform;
    SDL_RendererFlip m_flip;

    Animation* m_animation; //Objects animation 
    int m_row; //The spritesheet row (index starts at 0)
    int m_frameCount; //Framecount horizontally of spritesheet
    int m_frame; //Current Frame
    int m_animSpd; //Animation Speed

};

#endif // OBJECT_H