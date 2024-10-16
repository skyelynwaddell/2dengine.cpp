#include "engine.h"
#include <iostream> 

#include "texture_manager.h"
#include <transform.h>
#include "player.h"
#include "input.h"
#include "timer.h"
#include "console.h"
#include <SDL.h>
#include <iostream>
#include "tilemap.h"
#include "objectlayer.h"
#include "camera.h"

Engine* Engine::s_instance = nullptr; //reserve some memory for the object
Input* Input::s_instance = nullptr; //reserve some memory for the object
Player* player = nullptr;
Console* console = nullptr;
TileMap* tilemap = nullptr;
ObjectLayer* ObjectLayer::s_instance = nullptr;

//CREATE
bool Engine::Create(){
	std::cout << "### skyesrc 2024 ###\n" << std::endl;

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

	//Initialize Game Objects
	tilemap = new TileMap("maps/level1/","level1","basement_tutorial2_empty");
	console = new Console();
	TextureManager::LoadSpritesheets();
	player = new Player(new Properties("skye", 0, 0, 16, 16));

	Camera::GetInstance()->SetTarget(player->GetOrigin());


	return m_isRunning = true;
}

//CLEAN
bool Engine::Clean(){
	
	tilemap->Clean();
	console->Clean();
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
	Camera::GetInstance()->Update(dt);
}

//DRAW
void Engine::Draw(){
	SDL_RenderClear(m_renderer);

	//SDL_SetRenderDrawColor(m_renderer,124,0,124,255);
	//TextureManager::GetInstance()->Draw("player",20,20,16,16);

	tilemap->DrawBelow();
	player->Draw();
	tilemap->DrawAbove();
}

//DRAW GUI
void Engine::DrawGUI()
{
	console->Draw();
	SDL_RenderPresent(m_renderer);
}

//INPUT
void Engine::Input(){
	Input::GetInstance()->Listen();
	console->Input();
}

//QUIT
void Engine::Quit(){
	m_isRunning = false;
}
