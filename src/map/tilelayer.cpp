#include "tilelayer.h"

TileLayer::TileLayer(std::unique_ptr<tson::Map>& map, std::string layer_name, SDL_Texture& spritesheet) : m_spritesheet(spritesheet)
{
    tson::Layer* tileLayer = map->getLayer(layer_name);
    if (tileLayer && tileLayer->getType() == tson::LayerType::TileLayer) {
        for (auto &[pos, tileObject] : tileLayer->getTileObjects()) {
            tson::Rect drawingRect = tileObject.getDrawingRect();
            tson::Vector2f position = tileObject.getPosition();

            // Define the destination rectangle for rendering
            SDL_Rect destRect;
            destRect.x = static_cast<int>(position.x);
            destRect.y = static_cast<int>(position.y);
            destRect.w = static_cast<int>(drawingRect.width);
            destRect.h = static_cast<int>(drawingRect.height);

            // Define the source rectangle for the tile on the tileset
            SDL_Rect srcRect;
            srcRect.x = static_cast<int>(drawingRect.x);
            srcRect.y = static_cast<int>(drawingRect.y);
            srcRect.w = static_cast<int>(drawingRect.width);
            srcRect.h = static_cast<int>(drawingRect.height);

            // Store the rectangles in the vectors
            m_destRects.push_back(destRect);
            m_srcRects.push_back(srcRect);
        }
    }
}

void TileLayer::Draw()
{
    for (size_t i = 0; i < m_srcRects.size(); ++i) {
        SDL_RenderCopy(Engine::GetInstance()->GetRenderer(), &m_spritesheet, &m_srcRects[i], &m_destRects[i]);
    }
}
