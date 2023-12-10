//
// Created by NAT20 on 07/12/2023.
//

#include "EntryPoint.h"
#include "Framework/Application.h"

int main()
{
    labyrinth_engine::Application* application = GetApplication();
    application->Run();
    delete application;
}