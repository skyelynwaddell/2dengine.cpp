#pragma once

#ifndef IOBJECT_H
#define IOBJECT_H

#include <iostream>
using std::string;

/**
 * Interface Object Class
 * To be inherited from any object that needs a base create, update, and draw events
 * children: 
 *      - object.h
 */

#define GRID_SIZE 16*4
#define FRAMECOUNT 2 //size of spritesheet horizontally in sprite count
#define FRAMECOUNT_DEAD 1 //size of spritesheet horizontally in sprite count for the dead sprites

class IObject {
public:
    //virtual void Create()=0;
    virtual void Update(float dt)=0;
    virtual void Draw()=0;
    virtual void DrawGUI()=0;
    virtual void Clean()=0;

private:
protected:
    string m_id;
};

#endif // IOBJECT_H