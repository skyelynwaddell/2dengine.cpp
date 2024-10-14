#pragma once

#ifndef LAYER_H
#define LAYER_H
/**
 * Layer Parent class
 */

class Layer { //abstract
public:
    virtual void Draw()=0;
    virtual void Update()=0;
private:
protected:
};

#endif // LAYER_H