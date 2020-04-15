#include<iostream>
#include<SDL2/SDL.h>
#include <Game.h>
using namespace std;

const int WIDTH = 800, HEIGHT = 600;

int main(int argc, char* argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) cout<<"ne Pashe"<<SDL_GetError()<<endl;
    SDL_Window *window = SDL_CreateWindow("MyGame",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH ,HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

    if(NULL == window){
        cout<<"Not Created"<<SDL_GetError()<<endl;
        return EXIT_FAILURE;
    }

    SDL_Event windowEvent;
    while(true){
        if(SDL_PollEvent( &windowEvent)){
            if(SDL_QUIT == windowEvent.type){
                break;
            }

        }
    }



    SDL_DestroyWindow( window );
    SDL_Quit();

    return EXIT_SUCCESS;
}
