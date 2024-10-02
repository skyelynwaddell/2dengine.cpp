//game.cpp

#include <game.h>

#undef game

enum Level {
    LOW,
    MEDIUM,
    HIGH
};

// game constructor
Game::Game()
    : window(nullptr), renderer(nullptr), gameloop(true), fullscreen(false),
      frameCount(0), currentFPS(0), lastFrame(0) {}

// game loop cleanup
Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}


// init event
void Game::init()
{
    enum Level myLevelVariable = LOW;
    enum Level myLevelVariable1 = MEDIUM;
    enum Level myLevelVariable2 = HIGH;

    std::cout << myLevelVariable << std::endl;
    std::cout << myLevelVariable1 << std::endl;
    std::cout << myLevelVariable2 << std::endl;

    // Validate SDL initialization was successful
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) 
    { std::cout << "Error at SDL_Init()" << std::endl; }

    // Validate Window & Renderer were created
    if (SDL_CreateWindowAndRenderer(WIDTH,HEIGHT,0,&window,&renderer) < 0)
    { std::cout << "Error at SDL_CreateWindowAndRenderer()" << std::endl; }

    // Init SDL Window Properties
    SDL_SetWindowTitle(window, "2d engine");
    SDL_ShowCursor(1);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");

    TTF_Init();

    player.setDest(10,10,100,100);
    player.setSource(0,0,64,64);
    player.setTexture("player.png", renderer);
}

// update event
void Game::update(){

    updateFPS();

    // fullscreen toggler functionality
    if (fullscreen) SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    else SDL_SetWindowFullscreen(window, 0);
}

// input event
void Game::input(){
    SDL_Event e;

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

    draw_sprite(player);
    draw_text("Hello World :)", 20, 30, 0, 255, 0, 24);

    SDL_RenderPresent(renderer);
}

// draw sprite
void Game::draw_sprite(Object obj){
    SDL_Rect dest = obj.getDest();
    SDL_Rect src = obj.getSource();
    SDL_RenderCopyEx(renderer, obj.getTexture(), &src, &dest, 0, NULL, SDL_FLIP_NONE);
}

//draw text
void Game::draw_text(const char* msg, int x, int y, int r, int g, int b, int size){
    SDL_Surface* surf;
    SDL_Texture* tex;
    TTF_Font *font = TTF_OpenFont("../assets/fonts/pico-8.ttf", size);
    SDL_Color color;
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = 255;

    SDL_Rect rect;
    surf = TTF_RenderText_Solid(font,msg,color);
    tex = SDL_CreateTextureFromSurface(renderer,surf);
    rect.x = x;
    rect.y = y;
    rect.w = surf->w;
    rect.h = surf->h;

    SDL_FreeSurface(surf);
    SDL_RenderCopy(renderer,tex,NULL,&rect);
    SDL_DestroyTexture(tex);
}

//update fps
void Game::updateFPS() {
    frameCount++;
    int timerFPS = SDL_GetTicks() - lastFrame;
    if (timerFPS < (1000 / FPS)) SDL_Delay((1000 / FPS) - timerFPS);
}

//run , calls all the methods 
void Game::run() {
    static int lastTime = 0;
    
    // Main Game Loop
    while (gameloop) {
        lastFrame = SDL_GetTicks();

        if (lastFrame >= (lastTime + 1000)) { 
            lastTime = lastFrame; 
            currentFPS = frameCount;    
            frameCount = 0;
        }

        std::cout << currentFPS << std::endl;

        input();
        update();
        draw();
    }
}