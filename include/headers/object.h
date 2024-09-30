//object.h

#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class Object {
private:
    SDL_Rect m_dest;
    SDL_Rect m_src;
    SDL_Texture* m_tex;
    int m_x;
    int m_y;
    int m_w;
    int m_h;
public:
    Object() {}
    SDL_Rect getDest() const { return m_dest; }
    SDL_Rect getSource() const { return m_src; }
    SDL_Texture* getTexture() const { return m_tex; }
    void setDest(int x, int y, int w, int h);
    void setSource(int x, int y, int w, int h);
    void setTexture(std::string filename, SDL_Renderer* renderer);
};

#endif //OBJECT_H