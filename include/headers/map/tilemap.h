#pragma once

#ifndef TILESET_H
#define TILESET_H

#include "SDL.h"
#include "tileson.hpp"
#include <iostream>

using std::string;

class TileMap {
public:
    TileMap(string source_folder, string json_filename, string spritesheet_filename);

    void DrawAbove();   //draws ABOVE player, characters, and objects
    void DrawBelow();   //draws BELOW player, characters, and objects
    void Clean();

private:
    SDL_Texture* m_spritesheet;
    tson::Tileson m_tson;
    std::unique_ptr<tson::Map> m_map;
                                    // Examples for syntax:
    string m_sourceFolder;          // maps/level1/
    string m_jsonFilename;          // level1
    string m_spritesheetFilename;   // basement_tutorial2_empty

    string m_jsonPath;
    string m_spritesheetPath;

protected:
};

#endif // TILESET_H