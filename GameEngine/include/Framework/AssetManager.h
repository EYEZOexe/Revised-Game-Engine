//
// Created by NAT20 on 07/12/2023.
//

#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include "SFML/Graphics.hpp"
#include "Framework/Core.h"

namespace Framework
{
    class AssetManager
    {
    public:
        static AssetManager& Get();
        Sptr<sf::Texture> LoadTexture(const std::string& filename);
    protected:
        AssetManager();

    private:
        static Uptr<AssetManager> assetManager;
        UMap<std::string, Sptr<sf::Texture>> m_mLoadedTextures;
    };
}



#endif //ASSETMANAGER_H
