#include<iostream>
#include "Engine.h"

#include "Timer.h"
using namespace std;

const int WIDTH = 800, HEIGHT = 600;


int main(int argc, char* argv[])
{
    Engine::GetInstance()->Init();

    while(Engine::GetInstance()->IsRunning()){
        Engine::GetInstance()->Events();
        Engine::GetInstance()->Update();
        Engine::GetInstance()->Render();
        Timer::GetInstance()->Tick();

    }
    Engine::GetInstance()->Clean();

    return 0;
}
