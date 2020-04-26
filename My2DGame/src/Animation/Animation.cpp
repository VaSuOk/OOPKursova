#include "Animation.h"
#include "TextureManager.h"

void Animation::Update()
{
    m_SpriteFrame = (SDL_GetTicks()/m_AnimSpeed)% m_FrameCount;
}

void Animation::Draw(float x, float y, int SpriteWidth, int SpriteHeight)
{
    TextureManager::GetInstance()->DrawFrame(m_TextureID, x, y, SpriteWidth, SpriteHeight, m_SpriteRow, m_SpriteFrame, m_Flip);
}

void Animation::SetProps(std::string textureID, int spriteRow, int FrameCount, int animSpeed, SDL_RendererFlip flip)
{
    m_TextureID = textureID;
    m_SpriteRow = spriteRow;
    m_FrameCount = FrameCount;
    m_AnimSpeed = animSpeed;
    m_Flip = flip;
}
