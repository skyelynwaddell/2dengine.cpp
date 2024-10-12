//game.h

#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "player.h"
#include "object.h"
#include "delta.h"

class Game {
public:
    Game();
    ~Game();

    void init();
    void update();
    void input();
    void draw();
    void draw_gui();
    void draw_sprite(Object& obj, SDL_Renderer* renderer);
    void draw_text(const char* msg, int x, int y, int r, int g, int b);
    void run();

    TTF_Font* font;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    bool gameloop;
    bool fullscreen;

    int frameCount;
    int currentFPS;
    int lastFrame;
    
    static const int WIDTH = 1280;
    static const int HEIGHT = 720;
    static const int FPS = 60;

    Player* player;
};

#endif // GAME_H