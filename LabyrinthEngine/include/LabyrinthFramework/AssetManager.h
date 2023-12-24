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
        static AssetManager& GetInstance();
        Shared<sf::Texture> LoadTexture(const std::string& a_filename);
        Shared<sf::Font> LoadFont(const std::string& a_filename);
        void Clear();
        void SetAssetDirectory(const std::string& a_directory);
    protected:
        AssetManager();

    private:
        static Unique<AssetManager> assetManager;
        Dictionary<std::string, Shared<sf::Texture>> m_mLoadedTextures;
        Dictionary<std::string, Shared<sf::Font>> m_mLoadedFonts;
        std::string m_assetDirectory;
    };
}



#endif //ASSETMANAGER_H
