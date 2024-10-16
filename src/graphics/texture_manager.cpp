#include "texture_manager.h" 
#include <SDL_image.h>
#include "engine.h"
#include <camera.h>

TextureManager* TextureManager::s_instance = nullptr;

void TextureManager::LoadSpritesheets(){
	GetInstance()->Load("skye","assets/sprites/player/skye.png");
	GetInstance()->Load("skye_dead","assets/sprites/player/skye_dead.png");
}

//LOAD
bool TextureManager::Load(string id, string filename){

	//Load image from filename string & create a surface
	SDL_Surface* surface = IMG_Load((filename).c_str());
	if (surface == nullptr){
		std::cout << "Texture Manager failed to load image: " << filename << std::endl;
		return false;
	}

	//Create texture from surface
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), surface);
	if (texture == nullptr){
		std::cout << "Texture Manager failed to create texture from surface: " << SDL_GetError() << std::endl;
		return false;
	}

	//Load texture into texture map
	m_textureMap[id] = texture;

	return true;
}

//DRAW
void TextureManager::Draw(string id, int x, int y, int width, int height, SDL_RendererFlip flip){
	
	//Render the whole contents of the image
	SDL_Rect srcRect = {0,0,width,height};

	//Set the position of the image on the screen
	SDL_Rect destRect = {x,y,width*4,height*4};

	//Draw the image to the renderer
	int img_angle = 0;
	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(),m_textureMap[id],&srcRect,&destRect,img_angle,nullptr,flip);
}

//DRAW FRAME
void TextureManager::DrawFrame(string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip)
{
	int _x = Camera::TranslateX(x);
	int _y = Camera::TranslateY(y);
	int _width = Camera::TranslateZoom(width);
	int _height = Camera::TranslateZoom(height);

	//Render the whole contents of the image
	SDL_Rect srcRect = {width*frame,height*row,width,height};

	//Set the position of the image on the screen
	SDL_Rect destRect = {_x,_y,_width,_height};

	//Draw the image to the renderer
	int img_angle = 0;
	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(),m_textureMap[id],&srcRect,&destRect,img_angle,nullptr,flip);
}

//Draw Tile
void TextureManager::DrawTile(string tilesetID, int tileSize, int x, int y, int row, int frame, SDL_RendererFlip flip)
{
	//Render the whole contents of the tile
	SDL_Rect srcRect = {tileSize*frame,tileSize*(row-1),tileSize,tileSize};

	//Set the position of the tile on the screen
	SDL_Rect destRect = {x,y,tileSize,tileSize};

	//Draw the tile to the renderer
	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(),m_textureMap[tilesetID],&srcRect,&destRect,0,0,flip);
}

//DROP
void TextureManager::Drop(string id){
	
	//Destroy the texture
	SDL_DestroyTexture(m_textureMap[id]);

	//Remove texture from the map
	m_textureMap.erase(id);
}

//CLEAN
void TextureManager::Clean(){
	//Maps cant be accessed with for loop so we need to get iterator for it

	//Define an iterator with the same type as the map
	std::map<string, SDL_Texture*>::iterator it; 

	//For loop with the iterator
	for (it = m_textureMap.begin(); it != m_textureMap.end(); it++){

		//Clear each element in the map from memory
		SDL_DestroyTexture(it->second);
	}

	//Clear the map itself from memory
	m_textureMap.clear();

	SDL_Log("Texture map cleaned success!");
}

