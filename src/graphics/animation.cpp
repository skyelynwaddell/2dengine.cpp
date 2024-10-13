#include "animation.h"
#include <SDL.h>
#include <SDL_timer.h>
#include "texture_manager.h"

//Animation Update
void Animation::Update()
{
    m_spriteFrame = (SDL_GetTicks() / m_animSpd) % m_frameCount;
}

//Animation Draw
void Animation::Draw(float x, float y, int spriteWidth, int spriteHeight)
{
    TextureManager::GetInstance()->DrawFrame(m_textureID, x, y, spriteWidth, spriteWidth, m_spriteRow, m_spriteFrame, m_flip);
}

//Animation Set Props
void Animation::SetProps(string textureID, int spriteRow, int frameCount, int animSpd, SDL_RendererFlip flip)
{
    m_textureID = textureID;
    m_spriteRow = spriteRow;
    m_frameCount = frameCount;
    m_animSpd = animSpd;
    m_flip = flip;
}
