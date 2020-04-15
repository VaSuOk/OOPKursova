#include<iostream>
#include<SDL2/SDL.h>
#include <Game.h>
using namespace std;

const int WIDTH = 800, HEIGHT = 600;
Game *game = nullptr;

int main(int argc, char* argv[])
{
    game = new Game();

    game->Init("BirchEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, false);
    while(game->Running()){
        game->HandlEvents();
        game->Update();
        game->Render();
    }
    game->Clean();
    return 0;
}
