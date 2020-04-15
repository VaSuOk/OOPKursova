#ifndef ENGINE_H
#define ENGINE_H
#include<SDL2/SDL.h>
#include<iostream>

#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640

class Engine
{
public:
        static Engine* GetInstance();

        bool Init();
        bool Clean();
        void Quit();

        void Update();
        void Render();
        void Events();

        inline bool IsRunning(){return m_IsRunning;}
        inline SDL_Renderer *Get_Renderer(){return m_Renderer;}

    private:
        Engine(){}
        bool m_IsRunning;
        SDL_Window *m_Window;
        SDL_Renderer *m_Renderer;
        static Engine* s_Instance;
};

#endif // ENGINE_H
