//game.cpp
#include "game.h"
#include <iostream>
#include <windows.h>
#include <math.h>
#include <stdio.h>
#include "delta.h"


#undef game

struct app {
    Player* player;

};

enum Level {
    LOW,
    MEDIUM,
    HIGH
};

// game constructor
Game::Game()
    : window(nullptr), renderer(nullptr), gameloop(true), fullscreen(false),
      frameCount(0), currentFPS(0), lastFrame(0), player(nullptr) {}

// game loop cleanup
Game::~Game()
{
    delete player;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}


// init event
void Game::init()
{
    TTF_Init();
    TTF_Init();

    //preload files here
    font = TTF_OpenFont("assets/fonts/pico-8.ttf",16);

    // Validate SDL initialization was successful
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) 
    { std::cout << "Error at SDL_Init()" << std::endl; }

    // Validate Window & Renderer were created
    if (SDL_CreateWindowAndRenderer(WIDTH,HEIGHT,SDL_RENDERER_ACCELERATED,&window,&renderer) < 0)
    { std::cout << "Error at SDL_CreateWindowAndRenderer()" << std::endl; }

    // Init SDL Window Properties
    SDL_SetWindowTitle(window, "cofebean engine");
    SDL_ShowCursor(1); //display cursor
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");

    player = new Player(renderer,"player.png",0,0,16,16,100);
}

// update event
void Game::update(){

    float delta_time = Delta::GetInstance()->GetDeltaTime();

    player->Update(delta_time);

    // fullscreen toggler functionality
    if (fullscreen) SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    else SDL_SetWindowFullscreen(window, 0);
}

// input event
void Game::input(){
    SDL_Event e;
    
    player->Input(e);

    // close game window when event is set to quit
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) gameloop = false;
    }

    // key states to control window
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_ESCAPE]) gameloop = false;
    if (keystates[SDL_SCANCODE_F11]) fullscreen = !fullscreen;
}

// draw event
void Game::draw() {

    //fill background with a blue color
    SDL_SetRenderDrawColor(renderer, 40, 43, 200, 255);
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = WIDTH;
    rect.h = HEIGHT;
    SDL_RenderFillRect(renderer, &rect);

    //draw_sprite(*player, renderer);
    

    player->Draw();

}

//draw gui event
void Game::draw_gui(){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    draw_text("Points: 300", 20, 30, 0, 255, 0);

    SDL_RenderPresent(renderer);
}

//draw text
void Game::draw_text(const char* msg, int x, int y, int r, int g, int b) {
    SDL_Surface* surf;
    SDL_Texture* tex;

    SDL_Color color;
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = 255;

    surf = TTF_RenderText_Solid(font, msg, color);
    if (!surf) {
        std::cerr << "TTF_RenderText_Solid Error: " << TTF_GetError() << std::endl;
        return;  // Handle error appropriately
    }

    tex = SDL_CreateTextureFromSurface(renderer, surf);
    if (!tex) {
        std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(surf);
        return;  // Handle error appropriately
    }

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = surf->w;
    rect.h = surf->h;

    SDL_FreeSurface(surf);
    SDL_RenderCopy(renderer, tex, NULL, &rect);
    SDL_DestroyTexture(tex);
}

// Main game loop
void Game::run() {


    gameloop = true;
    while (gameloop) {
        
        // Main Game Loop
        input();
        update();
        draw();
        draw_gui();
        Delta::GetInstance()->Tick();
    }
}

