#pragma once

#ifndef TILELAYER_H
#define TILELAYER_H

#include <tileson.hpp>
#include <SDL.h>
#include <engine.h>

class TileLayer {
public:
    TileLayer(SDL_Texture& spritesheet, std::string layer_name);
    void Draw(std::unique_ptr<tson::Map>& map);

private:
    std::vector<SDL_Rect> m_srcRects;    // Vector to hold source rectangles for tiles
    std::vector<SDL_Rect> m_destRects;   // Vector to hold destination rectangles for tiles
    SDL_Texture& m_spritesheet;          // Reference to the spritesheet texture
    std::unique_ptr<tson::Map> m_map;
    std::string m_layername;
protected:
};

#endif // TILELAYER_H