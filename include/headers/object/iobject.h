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

class IObject {
public:
    virtual void Create()=0;
    virtual void Update(float dt)=0;
    virtual void Draw()=0;
    virtual void DrawGUI()=0;
    virtual void Clean()=0;

private:
protected:
    string m_id;
};

#endif // IOBJECT_H