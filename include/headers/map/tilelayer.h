#pragma once

#ifndef TILELAYER_H
#define TILELAYER_H

#include <tileson.hpp>
#include <SDL.h>
#include <engine.h>

class TileLayer {
public:
    TileLayer(std::unique_ptr<tson::Map>& map, std::string layer_name, SDL_Texture& spritesheet);
    void Draw();

private:
    std::vector<SDL_Rect> m_srcRects;    // Vector to hold source rectangles for tiles
    std::vector<SDL_Rect> m_destRects;   // Vector to hold destination rectangles for tiles
    SDL_Texture& m_spritesheet;          // Reference to the spritesheet texture
protected:
};

#endif // TILELAYER_H