//object.cpp

#include <object.h>

#undef Object

Object::Object(int x, int y, int w, int h, string sprite, SDL_Renderer* renderer):
    m_x(x), m_y(y), m_w(w), m_h(h), m_spriteFile(sprite), m_renderer(renderer), m_spd(5), m_xspd(0), m_yspd(0)
{
    setTexture(sprite,renderer);
    m_renderer = renderer;
}

void Object::setTexture(string filename, SDL_Renderer* renderer) {
    SDL_Surface* surf = IMG_Load(("assets/images/" + filename).c_str());
    if (surf == nullptr) {
        std::cout << "Error loading image: " << IMG_GetError() << std::endl;
        //return; // Exit the function if the image fails to load
    }
    m_tex = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf); // Free the surface after creating the texture
    if (m_tex == nullptr) {
        std::cout << "Error creating texture: " << SDL_GetError() << std::endl;
    }

    // After creating the texture, set the filtering
    SDL_SetTextureBlendMode(m_tex, SDL_BLENDMODE_BLEND);
    SDL_SetTextureScaleMode(m_tex, SDL_ScaleMode::SDL_ScaleModeNearest);
}

// draw sprite
void Object::draw_sprite(Object& obj, SDL_Renderer* renderer){
    SDL_Rect dest = obj.getDest();
    SDL_Rect src = obj.getSource();
    SDL_RenderCopyEx(renderer, obj.getTexture(), &src, &dest, 0, NULL, SDL_FLIP_NONE);
}

