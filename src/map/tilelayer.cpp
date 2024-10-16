#include "tilelayer.h"
#include <vector2.h>
#include <camera.h>

TileLayer::TileLayer(SDL_Texture& spritesheet, std::string layer_name) : m_spritesheet(spritesheet), m_layername(layer_name)
{
}

void TileLayer::Draw(std::unique_ptr<tson::Map> &map)
{

    tson::Layer* tileLayer = map->getLayer(m_layername);
    if (tileLayer && tileLayer->getType() == tson::LayerType::TileLayer) {
        for (auto &[pos, tileObject] : tileLayer->getTileObjects()) {
            tson::Rect drawingRect = tileObject.getDrawingRect();
            tson::Vector2f position = tileObject.getPosition();

            Vector2 cam = Camera::GetInstance()->GetPosition();

            // Define the destination rectangle for rendering
            SDL_Rect destRect;
            destRect.x = static_cast<int>(position.x - cam.X);
            destRect.y = static_cast<int>(position.y - cam.Y);
            destRect.w = static_cast<int>(drawingRect.width);
            destRect.h = static_cast<int>(drawingRect.height);

            // Define the source rectangle for the tile on the tileset
            SDL_Rect srcRect;
            srcRect.x = static_cast<int>(drawingRect.x);
            srcRect.y = static_cast<int>(drawingRect.y);
            srcRect.w = static_cast<int>(drawingRect.width);
            srcRect.h = static_cast<int>(drawingRect.height);

            // Store the rectangles in the vectors
            SDL_RenderCopy(Engine::GetInstance()->GetRenderer(), &m_spritesheet, &srcRect, &destRect);

        }
    }
}

// void TileLayer::Draw()
// {
//     for (size_t i = 0; i < m_srcRects.size(); ++i) {
//         SDL_RenderCopy(Engine::GetInstance()->GetRenderer(), &m_spritesheet, &m_srcRects[i], &m_destRects[i]);
//     }
// }
