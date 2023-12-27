//
// Created by Tomas Tzorta on 07/12/2023.
//

#include "EntryPoint.h"
#include "LabyrinthFramework/Application.h"

#undef main
int main()
{
    SDL_SetMainReady();
    labyrinth_engine::Application* application = GetApplication();
    application->Run();
    delete application;
    return 0;
}