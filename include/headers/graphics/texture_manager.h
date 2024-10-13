#pragma once

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <iostream>
#include <SDL_render.h>
#include <map>
using std::string;

class TextureManager {
public:
    inline static TextureManager* GetInstance() { return s_instance = (s_instance != nullptr) ? s_instance : new TextureManager(); }
    bool Load(string id, string filename);
    void Drop(string id);
    void Clean();

    void Draw(string id, int x, int y, int width, int height, SDL_RendererFlip flip=SDL_FLIP_NONE);
    void DrawFrame(string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip=SDL_FLIP_NONE);

private:
    TextureManager(){};
    static TextureManager* s_instance;
    std::map<string, SDL_Texture*> m_textureMap;
protected:
};

#endif // TEXTUREMANAGER_H