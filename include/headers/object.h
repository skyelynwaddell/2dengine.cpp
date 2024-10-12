//object.h

#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using std::string;

class Object {
private:
    SDL_Rect m_dest;
    SDL_Rect m_src;
    SDL_Texture* m_tex;
    int m_x;
    int m_y;
    int m_w;
    int m_h;
    int m_dirx;
    int m_diry;
    int m_spd;
    int m_xspd;
    int m_yspd;
    string m_spriteFile;

public:
    Object(int x, int y, int w, int h, string sprite, SDL_Renderer* renderer);
    SDL_Rect getDest() const { return m_dest; }
    SDL_Rect getSource() const { return m_src; }
    SDL_Texture* getTexture() const { return m_tex; }
    void setDest(int x, int y, int w, int h);
    void setSource(int x, int y, int w, int h);
    void setTexture(string filename, SDL_Renderer* renderer);
    void draw_sprite(Object& obj, SDL_Renderer* renderer);

    int getX(){ return m_x; }
    void setX(int x) { m_x = x; }

    int getY(){ return m_y; }
    void setY(int y) { m_y = y; }

    int getDirX(){ return m_dirx; }
    void setDirX(int dirx) { m_dirx = dirx; }

    int getDirY(){ return m_diry; }
    void setDirY(int diry) { m_diry = diry; }

    int getSpd(){ return m_spd; }
    void setSpd(int spd) { m_spd = spd; }

    int getXSpd(){ return m_xspd; }
    void setXSpd(int xspd) { m_xspd = xspd; }

    int getYSpd(){ return m_yspd; }
    void setYSpd(int yspd) { m_yspd = yspd; }

protected:
    SDL_Renderer* m_renderer;

};

#endif //OBJECT_H