//
// Created by Tomas Tzorta on 07/12/2023.
//

#ifndef CONFIG_H
#define CONFIG_H

#include <string>

std::string GetAssetDirectory()
{
#ifdef NDEBUG //Release build
    return "assets/";
#else //Debug build
    return "E:/Coding Projects/Labyrinth-Engine/Game/assets/";
#endif
}

#endif //CONFIG_H
