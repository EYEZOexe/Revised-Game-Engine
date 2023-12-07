//
// Created by NAT20 on 06/12/2023.
//

#include <Framework/Application.h>

int main ()
{
    const auto application = std::make_unique<Framework::Application>();
    application->Run();
}