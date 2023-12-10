//
// Created by Tomas Tzorta on 07/12/2023.
//

#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <SFML/Graphics.hpp>
#include "Core.h"

namespace labyrinth_engine
{
    class AssetManager
    {
    public:
        static AssetManager& Get();
        Sptr<sf::Texture> LoadTexture(const std::string& a_filename);
        void Clear();
        void SetAssetDirectory(const std::string& a_directory);
    protected:
        AssetManager();

    private:
        static Uptr<AssetManager> assetManager;
        UMap<std::string, Sptr<sf::Texture>> m_mLoadedTextures;
        std::string m_assetDirectory;
    };
}



#endif //ASSETMANAGER_H
