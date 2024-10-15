#include "tilemap.h"
#include "engine.h"
#include "tilelayer.h"
#include "objectlayer.h"

TileLayer* tiles_above = nullptr;
TileLayer* tiles_below = nullptr;

TileMap::TileMap(string source_folder, string json_filename, string spritesheet_filename)
{
    //set member variables
    m_sourceFolder = source_folder;
    m_jsonFilename = json_filename;
    m_spritesheetFilename = spritesheet_filename;

    //JSON File Path
    m_jsonPath = m_sourceFolder+m_jsonFilename+".json";

    //Spritesheet File Path
    m_spritesheetPath = m_sourceFolder+m_spritesheetFilename+".png";

    //Get tileset from map file
    m_map = m_tson.parse(fs::path(m_jsonPath));
	tson::Tileset* tileset = m_map->getTileset(m_spritesheetFilename);

	// Load the tileset image into an SDL texture
	if (tileset) {
		m_spritesheet = IMG_LoadTexture(Engine::GetInstance()->GetRenderer(), m_spritesheetPath.c_str());
		
        if (!m_spritesheet) {
            std::cout << "Failed to load tileset texture: " << IMG_GetError() << std::endl;
		}
	}

    //Instantiate the tile layers for each layer in Tiled
    tiles_above = new TileLayer(m_map,"tiles_above",*m_spritesheet);
    tiles_below = new TileLayer(m_map,"tiles_below",*m_spritesheet);

    //Load objects from object layers
    ObjectLayer::GetInstance()->LoadDoors(m_map);

}

void TileMap::DrawAbove()
{
    if(m_map->getStatus() != tson::ParseStatus::OK) return;
    tiles_above->Draw();
}

void TileMap::DrawBelow()
{
    if(m_map->getStatus() != tson::ParseStatus::OK) return;
    tiles_below->Draw();
}

void TileMap::Clean()
{
    if (m_spritesheet) {
        SDL_DestroyTexture(m_spritesheet);
        m_spritesheet = nullptr;
    }
}
