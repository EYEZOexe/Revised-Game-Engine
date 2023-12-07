//
// Created by NAT20 on 07/12/2023.
//

#ifndef CONFIG_H
#define CONFIG_H

#include <string>

std::string GetAssetDirectory()
{
#ifdef RELEASEMODE //Release build
    return "assets/";
#else //Debug build
    return "E:/Coding Projects/UdemyYears/Game/assets/";
#endif
}

#endif //CONFIG_H
