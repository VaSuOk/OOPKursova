#include "Player.h"
#include "TextureManager.h"
#include<SDL2/SDL.h>
#include "Input.h"

Player::Player(Properties* props): Character(props)
{
    m_RigetBody = new RigetBody();
    m_Animation = new Animation();
    m_Animation->SetProps(m_TextureID, 1, 5, 80);
}

void Player::Draw()
{
    m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);
}


void Player::Update(float dt)
{
    m_Animation->SetProps("tree", 1, 2, 80);
    m_RigetBody->UnSetForce();

    if(Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A)){
        SDL_Log("Key A pushed!!");
        m_RigetBody->ApplyForce(5*BACKWARD);
        m_Animation->SetProps("player", 1, 5, 80, SDL_FLIP_HORIZONTAL);
    }
    if(Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D)){
        SDL_Log("Key D pushed!!");
        m_RigetBody->ApplyForce(5*FORWARD);
        m_Animation->SetProps("player", 1, 5, 80);
    }

    m_RigetBody->Update(dt);
    m_Transform->TranslateX(m_RigetBody->GetPosition().X);
   // m_Transform->TranslateY(m_RigetBody->GetPosition().Y);

    m_Animation->Update();

}

void Player::Clean()
{
    TextureManager::GetInstance()->Clean();
}
