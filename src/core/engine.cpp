#include "engine.h"
#include <iostream> 

#include "texture_manager.h"
#include <transform.h>
#include "player.h"
#include "input.h"
#include "timer.h"

Engine* Engine::s_instance = nullptr; //reserve some memory for the object
Input* Input::s_instance = nullptr; //reserve some memory for the object
Player* player = nullptr;

//CREATE
bool Engine::Create(){

	//Start up SDL and SDL_Image
	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_PNG) != 0) {
		SDL_Log("Failed to start SDL: %s", SDL_GetError());
		return m_isRunning = false;
	}

	//Create engine window
	m_window = SDL_CreateWindow("SkyeSrc Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (m_window == nullptr){
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return m_isRunning = false;
	}

	//create engine renderer
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == nullptr){
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		return m_isRunning = false;
	}

	//Initialize Game Objects and such here

	//Load Spritesheets
	TextureManager::GetInstance()->Load("player","player/player.png");

	player = new Player(new Properties("player", 100, 200, 16, 16));

	return m_isRunning = true;
}

//CLEAN
bool Engine::Clean(){
	
	TextureManager::GetInstance()->Clean();
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	IMG_Quit();
	SDL_Quit();

	return true;
}

//UPDATE
void Engine::Update(){
	float dt = Timer::GetInstance()->GetDeltaTime();

	player->Update(dt);
}

//DRAW
void Engine::Draw(){
	SDL_SetRenderDrawColor(m_renderer,124,0,124,255);
	SDL_RenderClear(m_renderer);

	player->Draw();
	//TextureManager::GetInstance()->Draw("player",20,20,16,16);

	SDL_RenderPresent(m_renderer);
}

//DRAW GUI
void Engine::DrawGUI()
{
}

//INPUT
void Engine::Input(){
	Input::GetInstance()->Listen();
}

//QUIT
void Engine::Quit(){
	m_isRunning = false;
}
