#include "Engine.h"
#include "TextureManager.h"
#include "Input.h"
#include "Player.h"
#include "Timer.h"

Engine* Engine::s_Instance = nullptr;
Player* player = nullptr;

bool Engine::Init(){

    if(SDL_Init(SDL_INIT_VIDEO)!=0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG)!=0){
        SDL_Log("Failed to initialize SDL : %s", SDL_GetError());
        return false;
    }
    m_Window = SDL_CreateWindow("MyFirstGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if(m_Window == nullptr){
        SDL_Log("Fail to crearte Window: %s", SDL_GetError());
        return false;
    }
    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(m_Renderer == nullptr){
        SDL_Log("Fail to crearte Renderer: %s", SDL_GetError());
        return false;
    }

    //Test Treeee
    TextureManager::GetInstance()->Load("player", "assets/images/player.png");
    TextureManager::GetInstance()->Load("tree", "assets/images/tree.png");
    player = new Player(new Properties("player", 100, 200, 109, 150));
    player = new Player(new Properties("tree", 100, 200, 109, 150));
    Transform tf;
    tf.Log();
    return m_IsRunning = true;
}
void Engine::Update(){
    float dt = Timer::GetInstance()->GetDeltaTime();
    player->Update(dt);
}

void Engine::Render(){
    SDL_SetRenderDrawColor(m_Renderer, 124, 210, 254, 255);
    SDL_RenderClear(m_Renderer);

    //Test Treee
    player->Draw();

    SDL_RenderPresent(m_Renderer);
}

void Engine::Events(){
    Input::GetInstance()->Listen();
}

bool Engine::Clean(){
    TextureManager::GetInstance()->Clean();
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    IMG_Quit();
    SDL_Quit();
}

void Engine::Quit(){
    m_IsRunning = false;
}
